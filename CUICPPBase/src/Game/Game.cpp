
#include<ChBaseLibrary.h>

#include"../Charactor/Charactor.h"
#include"../FieldObjectBase/FieldObjectBase.h"
#include"../Controller/Player/PlayerController.h"
#include"../Controller/CPU/CPUController.h"
#include "Game.h"


void MainGame::Init()
{
	turns[0] = &MainGame::TurnStart;
	turns[1] = &MainGame::TurnStunby;
	turns[2] = &MainGame::ThrowDice;
	turns[3] = &MainGame::SelectTarget;
	turns[4] = &MainGame::SelectDice;
	turns[5] = &MainGame::DiceEffect;
	turns[6] = &MainGame::TurnEnd;

	{

		auto obj = ChPtr::Make_S<Charactor>();
		obj->Init("player", 30);
		obj->SetParticipationGame(this);
		obj->SetController<PlayerController>();

		charactors.push_back(obj);
		obj->TestData_Dice();

	}

	{

		auto obj = ChPtr::Make_S<Charactor>();
		obj->Init("enemy", 30);
		obj->SetParticipationGame(this);
		obj->SetController<LVNormalCPUController>();
		
		charactors.push_back(obj);
		obj->TestData_Dice();

	}

	printf("ゲーム開始!!\n");

	StartDice();
}

void MainGame::Frame()
{
	charactors[turnPlayer]->SetActionSkipFalse();
	(this->*turns[turnCount])();
}

void MainGame::Release()
{

}

void MainGame::AddFieldObject(const FieldObjectNames _name, const unsigned long _turnCount)
{
	auto&& obj = FieldObjectBase::Create(_name);

	if (obj == nullptr)return;

	obj->InitBase(this);

	obj->Init();

	obj->SetTurn(_turnCount);

	fieldObjects.push_back(obj);
}

void MainGame::StartDice()
{
	unsigned char maxPoint = -1;
	unsigned char charactorNo = -1;

	for (unsigned char i = 0; i < charactors.size(); i++)
	{

		printf("%sさん、ダイスを振ってください\n", charactors[i]->GetName().c_str());
		unsigned char tmpPoint = rand() % 20;
		printf("出た目は%dです。\n", tmpPoint);

		if (tmpPoint == maxPoint)
		{
			printf("%sさんと%sさんの数値が同じです。\n全員振りなおします。\n",
				charactors[i]->GetName().c_str(),
				charactors[charactorNo]->GetName().c_str());

			maxPoint = -1;
			charactorNo = -1;
			i = 0;
			continue;
		}

		if (charactorNo < charactors.size() && (maxPoint > tmpPoint && maxPoint < 20))continue;
		
		maxPoint = tmpPoint;
		charactorNo = i;

		printf("%sさんが最高得点を出しました。",charactors[i]->GetName().c_str());

	}

	turnPlayer = charactorNo;

	printf("%sさんがStartPlayerになりました。", charactors[turnPlayer]->GetName().c_str());


}

void MainGame::TurnStart()
{
	for (auto&& obj = fieldObjects.begin(); obj != fieldObjects.end(); obj++)
	{
		(*obj)->TurnStart();
	}
	charactors[turnPlayer]->TurnStart();
}

void MainGame::TurnStunby()
{
	for (auto&& obj = fieldObjects.begin(); obj != fieldObjects.end(); obj++)
	{
		(*obj)->TurnStart();

	}

	charactors[turnPlayer]->TurnStunby();
}

void MainGame::SelectTarget()
{
	for (auto&& obj = fieldObjects.begin(); obj != fieldObjects.end(); obj++)
	{
		(*obj)->SelectTarget();

	}

	charactors[turnPlayer]->SelectTarget();

}

void MainGame::SelectDice()
{
	for (auto&& obj = fieldObjects.begin(); obj != fieldObjects.end(); obj++)
	{
		(*obj)->SelectDice();

	}

	charactors[turnPlayer]->SelectDice();

}

void MainGame::ThrowDice()
{

	for (auto&& obj = fieldObjects.begin(); obj != fieldObjects.end(); obj++)
	{
		(*obj)->ThrowDice();

	}

	charactors[turnPlayer]->ThrowDice();
}

void MainGame::DiceEffect()
{
	for (auto&& obj = fieldObjects.begin(); obj != fieldObjects.end(); obj++)
	{
		(*obj)->DiceEffect();

	}

	charactors[turnPlayer]->DiceEffect();
}

void MainGame::TurnEnd()
{

	charactors[turnPlayer]->TurnEnd();

	for (auto&& obj = fieldObjects.begin(); obj != fieldObjects.end(); obj)
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
