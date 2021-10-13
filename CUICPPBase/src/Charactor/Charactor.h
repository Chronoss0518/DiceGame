#ifndef _Charactor
#define _Charactor

class MainGame;
class Dice;
class PandoraDice;
class CharactorEffectBase;

#include"../CharactorEffectBase/CharactorEffectNames_Enum.h"
#include"../Controller/ControllerBase.h"

class Charactor
{
private:

	void TestData_Dice();

public:

	void Init(const char* _name, const int _lp = 30);

	void AddCharactorEffect(const CharactorEffectNames _name, const unsigned long _turnCount);

	inline void SetParticipationGame(MainGame* _game) { participationGame = _game; }

	inline void SetName(const std::string& _name) { name = _name; }

	inline void SetLP(const int _lp) { lp = _lp; }

	inline void SetActionSkipTrue() { skipFlg = true; }

	inline void SetActionSkipFalse() { skipFlg = false; }

	void SetDiceCount(const unsigned char _count);

	template<class Con>
	inline void SetController()
	{
		controller = ChPtr::Make_S<std::enable_if<std::is_base_of<ControllerBase, Con>, Con>>();
		controller->Init(this);
	}

	inline std::string GetName() { return name; }

	inline unsigned char GetTargetCharactorNo() { return targetCharactor; }

	MainGame& GetParticipationGame();

	inline ChPtr::Shared<Charactor> GetAttackCharactor() { return attackTarget.lock(); }

	inline std::vector<ChPtr::Shared<Dice>> GetDiceList() { return haveDice; };

	inline ChStd::Bool IsDeath() { return (lp <= 0); }

	short Damage(const short _damage);

	short CriticalDamage(const short _damage);

	short Heal(const short _heal);

	void ChangeLPToAttackTarget();

	void ThrowPandoraDice();

	void TurnStart();

	void TurnStunby();

	void SelectTarget();

	void SelectDice();

	void ThrowDice();

	void DiceEffect();

	void TurnEnd();

private:

	std::string name = "";
	short lp = 0;
	unsigned char targetCharactor = 0;

	//プレイヤーの行動を強制的にスキップさせるフラグ
	ChStd::Bool skipFlg = false;

	std::vector<ChPtr::Shared<Dice>>haveDice;
	ChPtr::Shared<PandoraDice> pandoraDice = nullptr;
	ChPtr::Weak<Dice>throwDice;

	std::vector<ChPtr::Shared<CharactorEffectBase>>effect;

	ChPtr::Shared<ControllerBase>controller = nullptr;

	ChPtr::Weak<Charactor>attackTarget;

	MainGame* participationGame = nullptr;
};

#endif