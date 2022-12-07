#include<Windows.h>
#include<ChBaseLibrary.h>

#include"ControllerBase.h"
#include"../Charactor/Charactor.h"
#include"../Game/Game.h"


Charactor& ControllerBase::GetUser()
{
	return *user;
}

void ControllerBase::SetTrueUpFlg()
{
	flgs.SetBitTrue(ChStd::EnumCast(ButtonFlgNames::Up));
}

void ControllerBase::SetTrueDownFlg()
{
	flgs.SetBitTrue(ChStd::EnumCast(ButtonFlgNames::Down));
}

void ControllerBase::SetTrueDecisionFlg()
{
	flgs.SetBitTrue(ChStd::EnumCast(ButtonFlgNames::Decision));
}

void ControllerBase::SetTrueThrowDiceFlg()
{
	flgs.SetBitTrue(ChStd::EnumCast(ButtonFlgNames::ThrowDice));
}

void ControllerBase::SetTrueCancelFlg()
{
	flgs.SetBitTrue(ChStd::EnumCast(ButtonFlgNames::Cancel));
}

ChStd::Bool ControllerBase::Up()
{
	ChStd::Bool out = flgs.GetBitFlg(ChStd::EnumCast(ButtonFlgNames::Up));
	flgs.SetBitFalse(ChStd::EnumCast(ButtonFlgNames::Up));
	return out;
}

ChStd::Bool ControllerBase::Down()
{
	ChStd::Bool out = flgs.GetBitFlg(ChStd::EnumCast(ButtonFlgNames::Down));
	flgs.SetBitFalse(ChStd::EnumCast(ButtonFlgNames::Down));
	return out;
}

ChStd::Bool ControllerBase::Decision()
{
	ChStd::Bool out = flgs.GetBitFlg(ChStd::EnumCast(ButtonFlgNames::Decision));
	flgs.SetBitFalse(ChStd::EnumCast(ButtonFlgNames::Decision));
	return out;
}

ChStd::Bool ControllerBase::ThrowDice()
{
	ChStd::Bool out = flgs.GetBitFlg(ChStd::EnumCast(ButtonFlgNames::ThrowDice));
	flgs.SetBitFalse(ChStd::EnumCast(ButtonFlgNames::ThrowDice));
	return out;
}

ChStd::Bool ControllerBase::Cancel()
{
	ChStd::Bool out = flgs.GetBitFlg(ChStd::EnumCast(ButtonFlgNames::Cancel));
	flgs.SetBitFalse(ChStd::EnumCast(ButtonFlgNames::Cancel));
	return out;
}
