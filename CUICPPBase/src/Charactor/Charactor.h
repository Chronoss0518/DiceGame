#ifndef _Charactor
#define _Charactor

#include<string>
#include<vector>
#include<memory>

class Dice;


enum class CharactorStatus :unsigned char
{
	stan = 0x1,
	ice = 0x2
};

class Charactor :public ChCpp::BaseObject
{
public:

	void Init(const char* _name, const int _lp = 30);

	inline void SetHP(const int _lp) { lp = _lp; }

	inline void SetName(const std::string& _name) { name = _name; }

	inline std::string GetName() { return name; }

	ChStd::Bool IsGuard();

	inline void UpGardFlg() { guardFlg = true; }

	void Damage(const int _damage);

	void ThrowDice();

	void SelectDice();

	void TurnStart();

private:

	std::string name;
	ChStd::Bool guardFlg = false;
	int lp = 0;
	unsigned char status = 0;
	unsigned char pandoraDiceCount = 0;

	std::vector<std::shared_ptr<Dice>>haveDice;

};

#endif