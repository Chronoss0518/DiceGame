#ifndef _FutureObject
#define _FutureObject

class Charactor;

class FutureObject
{
public:

	void Init(char* _text, int _damage)
	{
		text = _text;
		damage = _damage;
		flg = 0;
	}

private:



	std::string text;
	int damage;
	char flg;

};

#endif