#include<Windows.h>
#include<ChBaseLibrary.h>

#include"../../Charactor/Charactor.h"
#include"../../Game/Game.h"
#include"CPUController.h"


void CPUController::Init(Charactor* _user)
{
	ControllerBase::Init(_user);

	selectFunction[0] = &CPUController::SelectTargetFunction;
	selectFunction[1] = &CPUController::SelectDiceFunction;
}

ChStd::Bool CPUController::PushButtonUpdate()
{
	pushButtonCounter++;
	return (pushButtonCounter % pushButtonMaxCount <= 0 ? true : false);
}

void CPUController::SelectTargetFunction()
{
	auto turn = GetUser().GetParticipationGame().GetTurnCount();
	if (turn == TurnNames::SelectTarget)return;

	SelectTarget();

	updateFlg = true;
}

void CPUController::SelectDiceFunction()
{
	auto turn = GetUser().GetParticipationGame().GetTurnCount();
	if (turn == TurnNames::SelectDice)return;

	SelectDice();

	updateFlg = true;
}

void CPUController::DefaultAction()
{
	if (updateFlg)return;
	SetTrueDecisionFlg();
}

void CPUController::Update()
{
	if (PushButtonUpdate())return;

	updateFlg = false;
	SelectTarget();
	SelectDice();
	DefaultAction();
}

void LVNormalCPUController::SelectTarget()
{

}

void LVNormalCPUController::SelectDice()
{

}