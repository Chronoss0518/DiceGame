#pragma once

#include<string>

class Charactor;
class DiceEffectBase;

class Dice
{
public:

    void Init(Charactor* _charas) { thisHave = _charas; }

private:

    ChPtr::Shared<DiceEffectBase>dices[6];

    Charactor* thisHave = nullptr;
    std::string name = nullptr;
};
