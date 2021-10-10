
#include<ChBaseLibrary.h>

#include"../Charactor/Charactor.h"
#include"../FieldObjectBase/FieldObjectBase.h"
#include "Game.h"


void MainGame::Init()
{
	turns[0] = StartDice;
	turns[1] = TurnStunby;
	turns[2] = ThrowDice;
	turns[3] = SelectTarget;
	turns[4] = SelectDice;
	turns[5] = DiceEffect;
	turns[6] = TurnEnd;
}

void MainGame::Frame()
{
	StartDice();

	while (!gameEndFlg)
	{

		for (turnCount = 0; turnCount < sizeof(turns); turnCount++)
		{
			(this->*turns[turnCount])();
		}
	}
}

void MainGame::Release()
{

}

void MainGame::AddFieldObject(const std::string& _str)
{
	fieldObjects.push_back(FieldObjectBase::Create(_str));
}

void MainGame::StartDice()
{

}

void MainGame::TurnStart()
{


	for (auto&& obj = fieldObjects.begin(); obj == fieldObjects.end(); obj++)
	{
		(*obj)->TurnStart();
	}
	charactors[turnPlayer]->TurnStart();
}

void MainGame::TurnStunby()
{

	for (auto&& obj = fieldObjects.begin(); obj == fieldObjects.end(); obj++)
	{
		(*obj)->TurnStart();

	}

	charactors[turnPlayer]->TurnStunby();
}

void MainGame::SelectTarget()
{

	for (auto&& obj = fieldObjects.begin(); obj == fieldObjects.end(); obj++)
	{
		(*obj)->SelectTarget();

	}

	charactors[turnPlayer]->SelectTarget();

}

void MainGame::SelectDice()
{

	for (auto&& obj = fieldObjects.begin(); obj == fieldObjects.end(); obj++)
	{
		(*obj)->SelectDice();

	}

	charactors[turnPlayer]->SelectDice();

}

void MainGame::ThrowDice()
{

	for (auto&& obj = fieldObjects.begin(); obj == fieldObjects.end(); obj++)
	{
		(*obj)->ThrowDice();

	}

	charactors[turnPlayer]->ThrowDice();
}

void MainGame::DiceEffect()
{
	for (auto&& obj = fieldObjects.begin(); obj == fieldObjects.end(); obj++)
	{
		(*obj)->DiceEffect();

	}

	charactors[turnPlayer]->DiceEffect();
}

void MainGame::TurnEnd()
{

	charactors[turnPlayer]->TurnEnd();

	for (auto&& obj = fieldObjects.begin(); obj == fieldObjects.end(); obj)
	{
		(*obj)->TurnEnd();
		(*obj)->CountDown();

		if (!(*obj)->IsDeath())
		{
			obj++;
			continue;
		}

		fieldObjects.erase(obj);

	}

	unsigned long deathCount = 0;

	do
	{
		deathCount++;
		if (charactors.size() - 1 < deathCount)
		{
			gameEndFlg = true;
			break;
		}
		turnPlayer++;
		turnPlayer %= charactors.size();


	} while (!charactors[turnPlayer]->IsDeath());

}
