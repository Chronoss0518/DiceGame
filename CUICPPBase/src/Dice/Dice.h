#pragma once

class Charactor;
class DiceScript;

class Dice
{
public:

    inline void Init(Charactor* _user) { user = _user; }

    inline void SetDiceCount(const unsigned char _count) { count = _count <= 5 ? _count : 0; }

    inline void SetName(const std::string& _name) { name = _name; }

    inline std::string GetName() { return name; }

    void AddDiceScript(ChPtr::Shared<DiceScript>& _sDice);

    void LoadDice(const std::string& _outFile);

    virtual void DiceEffect();

protected:

    std::vector<ChPtr::Shared<DiceScript>>dices;

    unsigned char count = 0;

    Charactor* user = nullptr;
    std::string name = nullptr;
};
