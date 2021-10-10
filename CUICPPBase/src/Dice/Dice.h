#pragma once

class Charactor;
class DiceScript;

class Dice
{
public:

    inline void Init(Charactor* _user) { user = _user; }

    inline void SetDiceCount(const unsigned char _count) { count = _count <= 5 ? _count : 0; }

    void AddCreateDice(
        const std::vector<unsigned char>& _script, 
        const std::string& _text,
        const short _damage = 0,
        const short _heal = 0,
        const std::vector<std::string>& _CFONames = std::vector<std::string>(),
        const std::vector<std::string>& _CCENames = std::vector<std::string>());

    void LoadDice(const std::string& _outFile);

    void DiceEffect();

private:

    ChPtr::Shared<DiceScript>dices[6];

    unsigned char count = 0;

    Charactor* user = nullptr;
    std::string name = nullptr;
};
