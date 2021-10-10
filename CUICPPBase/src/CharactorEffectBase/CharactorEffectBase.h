#pragma once

class Charactor;

class CharactorEffectBase
{
public:

	static ChPtr::Shared<CharactorEffectBase> Create(const std::string& _str);

	void InitBase(Charactor* _thisHaver) { haver = _thisHaver; }

	virtual void Init(){}

	Charactor& GetCharactor() { return *haver; }

	virtual short PointMath(const short _point) { return _point; }

	ChStd::Bool IsDeath() { return deathFlg; }

	void CountDown() { turnCount = turnCount > 0 ? turnCount - 1 : 0; }

	virtual void TurnStart() {}

	virtual void TurnStunby() {}

	virtual void SelectTarget() {}

	virtual void SelectDice() {}

	virtual void ThrowDice() {}

	virtual void DiceEffect(){}

	virtual void TurnEnd() {}

protected:

	void SetDeathFlgTrue() { deathFlg = true; }

private:

	static std::map<std::string, std::function<ChPtr::Shared<CharactorEffectBase>(void)>>createrMap;

	Charactor* haver = nullptr;

	unsigned long turnCount = 0;

	ChStd::Bool deathFlg = false;

};

class C_AttackDouble :public CharactorEffectBase
{
	void Init()override;

	short PointMath(const short _point)override;
};

class C_GuardEffect:public CharactorEffectBase
{
	void Init()override;

	short PointMath(const short _point)override;
};

class C_StanEffect : public CharactorEffectBase
{
	void Init()override;

	void TurnStunby()override;
};