#include<Windows.h>
#include<ChBaseLibrary.h>

#include"PlayerController.h"

void PlayerController::Update()
{
	if (ChSystem::SysManager().IsPushKey(VK_UP)) SetTrueUpFlg();
	if (ChSystem::SysManager().IsPushKey(VK_DOWN))SetTrueDownFlg();
	if (ChSystem::SysManager().IsPushKey(VK_RETURN))SetTrueDecisionFlg();
	if (ChSystem::SysManager().IsPushKey(VK_RETURN))SetTrueThrowDiceFlg();
	if (ChSystem::SysManager().IsPushKey('Z'))SetTrueCancelFlg();
}