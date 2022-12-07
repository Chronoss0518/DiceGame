
#include<ChBaseLibrary.h>

#include"../Charactor/Charactor.h"
#include"../DiceScript/DiceScript.h"
#include"Dice.h"

void Dice::AddDiceScript(ChPtr::Shared<DiceScript>& _sDice)
{
	_sDice->Init();
	dices.push_back(_sDice);
}

void Dice::LoadDice(const std::string& _outFile)
{

}

void Dice::DiceEffect()
{
	dices[count]->Func(*user);
}