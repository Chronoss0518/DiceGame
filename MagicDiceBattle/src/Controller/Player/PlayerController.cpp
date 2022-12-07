#include<Windows.h>
#include<ChBaseLibrary.h>

#include"PlayerController.h"

void PlayerController::Update()
{
	/*
	* 
	if (ChSystem::SysManager().IsPushKey(VK_UP)) SetTrueUpFlg();
	if (ChSystem::SysManager().IsPushKey(VK_DOWN))SetTrueDownFlg();
	if (ChSystem::SysManager().IsPushKey(VK_RETURN))SetTrueDecisionFlg();
	if (ChSystem::SysManager().IsPushKey(VK_RETURN))SetTrueThrowDiceFlg();
	if (ChSystem::SysManager().IsPushKey('Z'))SetTrueCancelFlg();
	* 
	*/


	char tmp = std::getchar();

	if (tmp == 0xd)SetTrueDecisionFlg();
	if (tmp == 0xd)SetTrueThrowDiceFlg();
	if (tmp == 0x7a)SetTrueCancelFlg();
	if (tmp == 0xe0)
	{
		tmp = std::getchar();

		if (tmp == 0x50)SetTrueDownFlg();
		if (tmp == 0x48) SetTrueUpFlg();
	}

}