#pragma once

#include"DiceEffectBase.h"

class NormalAttackDice :public DiceEffectBase
{
public:

	void func(Charactor& _user)override;
};

class CriticalAttackDice :public DiceEffectBase
{
public:
	
	void func(Charactor& _user)override;

protected:

	void(*addEffect[6])(void);

};

class StanAttackDice :public DiceEffectBase
{

};