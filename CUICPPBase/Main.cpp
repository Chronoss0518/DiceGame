#include<Windows.h>
#include<ChBaseLibrary.h>
#include<ChWindowsLibrary.h>
#include"src/Game/Game.h"


int main(void)
{
	srand(timeGetTime());

	ChCpp::FrameList().SetFrame<MainGame>("Game");

	ChCpp::FrameList().Update();
}
