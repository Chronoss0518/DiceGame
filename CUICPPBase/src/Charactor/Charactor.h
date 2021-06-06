#ifndef _Charactor
#define _Charactor

#include<string>

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


    bool IsGuard();

private:

	std::string name;
    bool guardFlg = false;
	int lp = 0;
    char status = 0;
	unsigned char pandoraDiceCount = 0;
};

#endif