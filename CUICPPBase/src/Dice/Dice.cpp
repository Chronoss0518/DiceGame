
#include<ChBaseLibrary.h>

#include"../Charactor/Charactor.h"
#include"../DiceScript/DiceScript.h"
#include"Dice.h"

void AddCreateDice(
    const std::vector<unsigned char>& _script,
    const std::string& _text,
    const short _damage,
    const short _heal,
    const std::vector<std::string>& _CFONames,
    const std::vector<std::string>& _CCENames)
{
    auto dScript = ChPtr::Make_S<DiceScript>();

    
    for (auto&& scr : _script)
    {
        dScript->AddScript(scr);
    }

    dScript->SetEffectText(_text);
    dScript->SetDamage(_damage);
    dScript->SetHealPoint(_heal);

    for (auto&& cfo : _CFONames)
    {
        dScript->AddCreateFieldObjectName(cfo);
    }

    for (auto&& cce : _CCENames)
    {
        dScript->AddCreateCharactorEffectName(cce);
    }

}

void LoadDice(const std::string& _outFile)
{

}

void Dice::DiceEffect()
{
	dices[count]->Func(*user);
}