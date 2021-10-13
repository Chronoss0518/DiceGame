#include<ChBaseLibrary.h>

#include"../Game/Game.h"
#include"../Charactor/Charactor.h"
#include"../Dice/Dice.h"
#include"PandoraDice.h"


ChStd::Bool PandoraDice::IsThrow()
{
	auto game = user->GetParticipationGame();

	pandoraCount++;
	return 0 == (pandoraCount % game.GetPandoraCount());
}

void PandoraDice::DiceEffect()
{
	Dice::DiceEffect();

	pandoraCount = 0;

}