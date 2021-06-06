#ifndef _Charactor
#define _Charactor

#include<string>
#include<vector>
#include<memory>

class Dice;

namespace CharactorStatus
{
    enum 
    {
        stan = 0x1,
        ice = 0x2
    };
}

class Charactor
{
public:
    inline void SetHP(const int _lp){lp = _lp;}
    inline void SetName(const std::string& _name){name = _name;}

    inline std::string GetName(){return name;}

    bool IsGuard();

    void ThrowDice();
    void SelectDice();
    void TurnStart();

private:

	std::string name;
    bool guardFlg = false;
	int lp = 0;
    char status = 0;
	unsigned char pandoraDiceCount = 0;

    std::vector<std::shared_ptr<Dice>>haveDice;

};

#endif