#ifndef _Charactor
#define _Charactor

#include<string>
#include<vector>
#include<memory>

class MainGame;
class Dice;
class CharactorEffectBase;

enum class SkipFlgName :unsigned char
{
	TurnStart = 1,
	TurnStunby = 2,
	SelectTarget = 4,
	SelectDice = 8,
	ThrowDice = 16,
	DiceEffect = 32,
	TurnEnd = 64
};

class Charactor
{
public:

	void Init(const char* _name, const int _lp = 30);

	inline void AddCharactorEffect(ChPtr::Shared<CharactorEffectBase>& _effect) { effect.push_back(_effect); }

	inline void SetParticipationGame(MainGame* _game) { participationGame = _game; }

	inline void SetName(const std::string& _name) { name = _name; }

	inline std::string GetName() { return name; }

	inline unsigned char GetTargetCharactorNo() { return targetCharactor; }

	MainGame& GetParticipationGame();

	ChPtr::Shared<Charactor> GetAttackCharactor() { return attackTarget.lock(); }

	ChStd::Bool IsDeath() { return (lp <= 0); }

	inline void SetLP(const int _lp) { lp = _lp; }

	short Damage(const short _damage);

	short CriticalDamage(const short _damage);

	short Heal(const short _heal);

	void ChangeLPToAttackTarget();

	void TurnStart();

	//inline void TurnStartSkip() { skipFlg.SetBitTrue(ChStd::EnumCast(SkipFlgName::TurnStart)); }

	void TurnStunby();

	//inline void TurnStartSkip() { skipFlg.SetBitTrue(ChStd::EnumCast(SkipFlgName::TurnStunby)); }

	void SelectTarget();

	inline void TurnStartSkip() { skipFlg.SetBitTrue(ChStd::EnumCast(SkipFlgName::SelectTarget)); }

	void SelectDice();

	inline void TurnStartSkip() { skipFlg.SetBitTrue(ChStd::EnumCast(SkipFlgName::SelectDice)); }

	void ThrowDice();

	inline void TurnStartSkip() { skipFlg.SetBitTrue(ChStd::EnumCast(SkipFlgName::ThrowDice)); }

	void DiceEffect();

	inline void TurnStartSkip() { skipFlg.SetBitTrue(ChStd::EnumCast(SkipFlgName::DiceEffect)); }

	void TurnEnd();

	//inline void TurnStartSkip() { skipFlg.SetBitTrue(ChStd::EnumCast(SkipFlgName::TurnEnd)); }

private:

	std::string name;
	short lp = 0;
	unsigned char pandoraDiceCount = 0;

	unsigned char targetCharactor = 0;
	unsigned char targetDice = 0;

	ChCpp::BitBool skipFlg = ChCpp::BitBool(1);

	std::vector<ChPtr::Shared<Dice>>haveDice;
	ChPtr::Shared<Dice> pandraDice = nullptr;

	std::vector<ChPtr::Shared<CharactorEffectBase>>effect;

	ChPtr::Weak<Charactor>attackTarget;

	MainGame* participationGame = nullptr;
};

#endif