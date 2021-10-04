#pragma once

class Charactor;

class MainGame:public ChCpp::BaseFrame
{
public:

    void Init()override;

    void Frame()override;

    void Release()override;


private:

    void Helps();
    
    void StartDice();

    void Game();

    void TurnStart();

    void TurnStunby();

    void ThrowDice();

    void SelectTarget();

    void SelectDice();

    void TurnEnd();

    void FirstPlayer();
    void FirstEnemy();
    
    void DicePlayer();
    void DiceEnemy();

    void Result();
    void PushKeyAction();

    unsigned long turnPlayer = 0;
    std::vector<ChPtr::Shared< Charactor>>charactors;
    
};
