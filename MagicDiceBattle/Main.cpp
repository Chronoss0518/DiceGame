#include<Windows.h>
#include<ChBaseLibrary.h>
#include<ChWindowsLibrary.h>
#include<ChDirect3D11Library.h>
#include"src/Game/Game.h"

int WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
{
	{
		auto system = ChSystem::SysManager().Init<ChSystem::Windows>();
		system->Init("Magic Dice Battle", "ChGame", 1280, 720, hInstance, nShowCmd);
		
		ChD3D11::D3D11API().Init(system->GethWnd(), false, system->GetWindWidth(), system->GetWindHeight());
		ChD3D11::Shader11().Init(ChD3D11::D3D11API(), system->GetWindWidth(), system->GetWindHeight());

		ChSystem::SysManager().SetFPS(60);
	}

	srand(timeGetTime());

	ChCpp::FrameList().SetFrame<MainGame>("Game");

	while (ChSystem::SysManager().IsUpdate())
	{
		ChCpp::FrameList().Update();
	}

}

