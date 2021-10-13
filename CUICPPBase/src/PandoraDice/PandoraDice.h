#pragma once

#include"../Dice/Dice.h"

class PandoraDice : public Dice
{
public:

	ChStd::Bool IsThrow();

	void DiceEffect()override;

	inline void RecetCount() { pandoraCount = 0; }



private:

	unsigned char pandoraCount = 0;

};