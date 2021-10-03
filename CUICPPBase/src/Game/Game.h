#ifndef _Game
#define _Game

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
    
    void FirstPlayer();
    void FirstEnemy();
    
    void DicePlayer();
    void DiceEnemy();

    void Result();
    void PushKeyAction();

    unsigned long turnPlayer = 0;
    
};

#endif