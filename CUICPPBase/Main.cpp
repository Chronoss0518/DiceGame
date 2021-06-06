#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct CharactorData
{
	char *name;
	int hp;
	int stan;
	int nodamage;
	int ice;
	int pandoraDiceCount;
} CharaData;

typedef struct FutureAttackObject
{
	char *text;
	int damage;
	char flg;
} FAObject;

enum CharaType
{
	Player,
	Enemy
};

enum GuardTest
{
	Guard_False,
	Guard_True
};

int a = 0, b = 0;
int c = 0, d = 0, ep = 0, dou = 0;
char ps = 0, es = 0;

FAObject fireBall;
CharaData charas[2];

//s=スタン、n=ノーダメージ、dou=倍ダメージ,
//pst1,est1=n;pst2,est2=s
//c=クリティカル,m=マジック,g=ガード,h=ヒーリング,

//Init//
void InitFAttackObject(FAObject *_obj, char *_text, int _damage);
void InitCharaData(CharaData *_data, char *_name);

//GameMain//
void Helps();
void StartDice();
void Game();
void FirstPlayer();
void FirstEnemy();
void DicePlayer();
void DiceEnemy();
void ChangeTurn(CharaData *_turnCharas);
void Result();
void PushKeyAction();

void CriticalDice(CharaData *_target, CharaData *_this);
void MagicDice(CharaData *_target, CharaData *_this);
void GuardDice(CharaData *_target, CharaData *_this);
void HearingDice(CharaData *_target, CharaData *_this);
void PandoraDice(CharaData *_target, CharaData *_this);

//Effect//
void NormalAttack(CharaData *_target, int _damage);											//通常攻撃//
void StanAttack(CharaData *_target, int _damage);											//スタン攻撃//
void IceAttack(CharaData *_target, int _damage);											//アイス攻撃//
void BothPlayerAttack(CharaData *_target, CharaData *_this, int _damage);					//両プレイヤーに攻撃//
void AbsorptionAttack(CharaData *_target, CharaData *_this, int _damage);					//吸収攻撃//
void SacrificeAttack(CharaData *_target, int _targetDamage, CharaData *_this, int _thisHP); //自身のHPを指定数にして攻撃//
void FutureAttack(CharaData *_target, FAObject *_obj, int _damage);							//一部攻撃を未来へ飛ばす攻撃//
void DoubleTest(CharaData *_target, int _damage);											//倍ダメージテスト//
void HealingPoint(CharaData *_target, int _healingPoint);									//回復//
void ChangeHP(CharaData *_target, CharaData *_this);										//HPを入れ替える//
void SetGuard(CharaData *_target);															//ガードさせる//
char GuardTest(CharaData *_target);															//ガードテスト//



int main(void)
{
	srand(time(0));
	rand();

	InitFAttackObject(&fireBall, "ファイアーボールの流れ弾が当たった!!", 2);

	InitCharaData(&charas[Player], "あなた");
	InitCharaData(&charas[Enemy], "エネミー");

	Helps();

	StartDice();

	Game();

	Result();

	return 0;
}

void InitFAttackObject(FAObject *_obj, char *_text, int _damage)
{
	_obj->text = _text;
	_obj->damage = _damage;
	_obj->flg = 0;
}

void InitCharaData(CharaData *_data, char *_name)
{
	_data->name = _name;
	_data->hp = 30;
	_data->ice = 0;
	_data->nodamage = 0;
	_data->stan = 0;
	_data->pandoraDiceCount = 0;
}

void Helps()
{

	printf("スキルダイスを用いて、相手のLPを0にしてください\n");
	printf("スキルダイスは以下のスペルを押してからenter keyを押すと、\nそれぞれのダイスを振ることができます。\n");
	printf("\nc:クリティカルダイス(クリティカルヒットを狙うためのダイスです。\n");
	printf("外れる可能性はありますが、当たれば強力な一撃に特殊能力が付与されます。)\n");
	printf("\nm:マジックダイス(魔法を扱うダイスです。魔法は基本的に外れることはありませんが、\n");
	printf("魔法の中では、自らにダメージを当てるものがあります。)\n");
	printf("\ng:ガードダイス(主に守りを強化することを目的としたダイスです\n");
	printf("ガードを行うことで受けるダメージを0にできます。)\n");
	printf("\nh:ヒーリングダイス(多人数戦で使用される回復用ダイスです。\n");
	printf("本戦では相手を回復させてしまう恐れがあるため、注意が必要です。)\n");
	printf("\n上記のもの以外にも特別なダイスが存在します\n");
	printf("\n選択肢のないダイスで、パンドラのダイスと言います。\n");
	printf("このダイスは特定条件に達した場合に振ることができます。\n");
	printf("強力な効果のものしかないため、一気に決める場合にはこれが出ることを望むと良いでしょう。\n");
	printf("このダイスを振る条件は、通常のスキルダイスによってこのダイスを振る指示を受けた場合か、\n");
	printf("このダイスを振らずに6回通常ダイスのみを振った場合にこのダイスを振ることができます。\n");
	printf("\n以上が簡単なルール説明となります。\n");
}

void StartDice()
{

	printf("先行後攻を決めるダイスです\n");
	printf("いずれかのkeyを押してダイスを振ってください\n");

	while (a == b)
	{

		PushKeyAction();

		a = rand() % 20 + 1;
		b = rand() % 20 + 1;

		printf("%sの目は%dです。\n", charas[Player].name, a);
		printf("%sの目は%dです。\n", charas[Enemy].name, b);

		if (a > b)
		{
			printf("%sが先行です。\n", charas[Player].name);
		}
		if (a < b)
		{ //if(a>b)
			printf("%sは後攻です。\n", charas[Player].name);
		}
		if (a == b)
		{ //if(a<b)
			printf("先行後攻を決めるダイスです\n");
			printf("いずれかのkeyを押してダイスを振ってください\n");

			printf("あいこです、もう一度振ってください。\n");
		} //if(a==b)
	}
}

void Result()
{

	printf("next\n");
	getchar();
	printf("戦闘終了です!\n%sの", charas[Player].name);
	if (charas[Player].hp > 0)
	{
		printf("勝ちです!!\n");
	}
	else
	{
		printf("負けです\n");
	}
	printf("GameEnd\n");
	getchar();
}

void PushKeyAction()
{

	printf("next>>\n");
	getchar();

#ifdef __WIN32__
	system("cls\n");
#elif __WIN64__
	system("cls\n");
#else
	system("clear\n");
#endif
}

void Game()
{

	while (charas[Player].hp > 0 && charas[Enemy].hp > 0)
	{
		FirstPlayer();
		FirstEnemy();
	} //while(ph>0&&eh>0)
}

void FirstPlayer()
{

	if (a > b)
	{
		DicePlayer();
		DiceEnemy();
	}
}

void FirstEnemy()
{

	if (b > a)
	{ //if(a>b)
		DiceEnemy();
		DicePlayer();

	} //if(b>a)
}

void DicePlayer()
{

	if (charas[Player].hp > 0 && charas[Enemy].hp > 0)
	{

		ChangeTurn(&charas[Player]);
		if (charas[Player].stan == 1)
		{ //if(pss!=1)
			printf("\n%sはこのターン行動できません\n", charas[Player].name);
			charas[Player].stan = 0;
		} //if(pss==1)
		else
		{

			if (charas[Player].pandoraDiceCount >= 6)
			{
				PandoraDice(&charas[Enemy], &charas[Player]);
			} //if(ppn==6)
			else
			{

				printf("\n△%sのターンです\n", charas[Player].name);
				printf("c;クリティカルダイス\n");
				printf("m;マジックダイス\n");
				printf("h;ヒーリングダイス\n");
				printf("g;ガードダイス\n");
				printf("\n使うダイスを宣言して、ダイスを振ってください:");
				scanf("%c", &ps);
				getchar();
				printf("\n");

				charas[Player].pandoraDiceCount++;
				if (ps == 'c')
				{
					CriticalDice(&charas[Enemy], &charas[Player]);
				}
				else if (ps == 'm')
				{ //if(ps=='c')
					MagicDice(&charas[Enemy], &charas[Player]);
				}
				else if (ps == 'g')
				{ //if(ps=='m')
					GuardDice(&charas[Enemy], &charas[Player]);
				}
				else if (ps == 'h')
				{ //if(ps=='g')
					HearingDice(&charas[Enemy], &charas[Player]);
				}
				else
				{ //if(ps=='h')
					printf("コマンドを押していないため、このターンは行動できません\n");
				} //if(ps!==''&&pw!='m'&&ps!='g'&&ps!='h')
			}
		}
	}
}

void DiceEnemy()
{

	if (charas[Player].hp > 0 && charas[Enemy].hp > 0)
	{
		ChangeTurn(&charas[Enemy]);
		if (charas[Enemy].stan == 1)
		{ //if(ess!=1)
			printf("\n%sはこのターン行動できません\n", charas[Enemy].name);
			charas[Enemy].stan = 0;
		} //if(ess==1)
		else
		{
			if (charas[Enemy].pandoraDiceCount >= 6)
			{ //if(epn!=6)
				PandoraDice(&charas[Player], &charas[Enemy]);
			}
			else
			{
				charas[Enemy].pandoraDiceCount++;
				if (10 > charas[Enemy].hp && charas[Enemy].hp > 0)
				{
					ep = rand() % 2 + 1;
					if (ep == 1)
					{
						GuardDice(&charas[Player], &charas[Enemy]);
					}
					if (ep == 2)
					{ //if(ep==1)
						HearingDice(&charas[Player], &charas[Enemy]);
					} //if(ep==2)
				}
				else if (20 > charas[Enemy].hp && charas[Enemy].hp >= 10)
				{ //if(10>eh&&eh>0&&etd==1)
					ep = rand() % 4 + 1;
					if (ep == 1)
					{
						CriticalDice(&charas[Player], &charas[Enemy]);
					}
					if (ep == 2)
					{ //if(ep==1)
						MagicDice(&charas[Player], &charas[Enemy]);
					}
					if (ep == 3)
					{ //if(ep==2)
						GuardDice(&charas[Player], &charas[Enemy]);
					}
					if (ep == 4)
					{ //if(ep==3)
						HearingDice(&charas[Player], &charas[Enemy]);
					} //if(ep==4)
				}
				else if (charas[Enemy].hp >= 20)
				{ //if(20>eh&&eh=>10&&etd==1)
					ep = rand() % 2 + 1;
					if (ep == 1)
					{
						CriticalDice(&charas[Player], &charas[Enemy]);
					}
					if (ep == 2)
					{ //if(ep==1)
						MagicDice(&charas[Player], &charas[Enemy]);
					} //if(ep==2)
				}	  //if(eh>=20)
			}
			//if(epn==6)
		}
	} //if(eh>0&&ph>0)
}

void ChangeTurn(CharaData *_turnCharas)
{
	dou--;
	_turnCharas->nodamage = 0;

	PushKeyAction();
	printf("%sのLP:%d\n", charas[Player].name, charas[Player].hp);
	printf("%sのパンドラダイスカウント:%d\n", charas[Player].name, charas[Player].pandoraDiceCount);
	printf("\n%sのLP:%d\n",  charas[Enemy].name, charas[Enemy].hp);
	printf("%sのパンドラダイスカウント:%d\n", charas[Enemy].name, charas[Enemy].pandoraDiceCount);

	if (fireBall.flg == 1)
	{
		printf("%sは\n", _turnCharas->name);
		printf(fireBall.text);
		printf("\n");
		fireBall.flg = 0;
		NormalAttack(_turnCharas, 2);
	} //if(==1)

	printf("\n%sのターンです\n", _turnCharas->name);

	printf("next>>\n");
	getchar();
}

void CriticalDice(CharaData *_target, CharaData *_this)
{
	printf("%sはクリティカルダイスを振りました。\n", _this->name);

	printf("next>>\n");
	getchar();

	c = rand() % 6 + 1;
	if (c == 1)
	{
		printf("クリティカルヒット!!\n");
		NormalAttack(_target, 7);
	}
	if (c == 2)
	{
		printf("ミス!%sに0ダメージ\n", _target->name);
	}
	if (c == 3)
	{ 
		printf("クリティカルヒット!!\n");
		StanAttack(_target, 5);
	}
	if (c == 4)
	{ 
		NormalAttack(_target, 2);
	}
	if (c == 5)
	{
		PandoraDice(_target, _this);
	}
	if (c == 6)
	{
		printf("クリティカルヒット!!\n");
		StanAttack(_target, 5);
	}
}

void MagicDice(CharaData *_target, CharaData *_this)
{
	printf("%sはマジックダイスを振りました。\n", _this->name);

	printf("next>>\n");
	getchar();
	c = rand() % 6 + 1;
	if (c == 1)
	{
		printf("炎魔法、ファイアーボール発動!!\n");
		FutureAttack(_target, &fireBall, 2);
	}
	if (c == 2)
	{
		printf("雷魔法、サンダーボルト発動!!\n");
		BothPlayerAttack(_target, _this, 4);
	}
	if (c == 3)
	{
		printf("ミス!、%sに0のダメージ\n", _target->name);
	}
	if (c == 4)
	{
		PandoraDice(_target, _this);
	}
	if (c == 5)
	{
		printf("氷魔法、サークルフロスト発動!!\n");
		StanAttack(_target, 3);
	}
	if (c == 6)
	{
		printf("%sは宇宙魔法、メテオ発動!!\n", _target->name);
		SacrificeAttack(_target,10,_this,1);
	}
}

void GuardDice(CharaData *_target, CharaData *_this)
{
	printf("%sはガードダイスを振りました。\n", _this->name);

	printf("next>>\n");
	getchar();
	c = rand() % 6 + 1;
	if (c == 1)
	{
		printf("クリティカルヒット!!\n");
		NormalAttack(_target, 6);
		SetGuard(_this);
	}
	if (c == 2)
	{
		SetGuard(_this);
	}
	if (c == 3)
	{
		PandoraDice(_target, _this);
	}
	if (c == 4)
	{
		printf("ミス!、何も起こらなかった。\n");
	}
	if (c == 5)
	{
		NormalAttack(_target, 1);
	}
	if (c == 6)
	{
		SetGuard(_this);
	}
}

void HearingDice(CharaData *_target, CharaData *_this)
{
	printf("%sはヒーリングダイスを振りました。\n", _this->name);

	printf("next>>\n");
	getchar();

	c = rand() % 6 + 1;
	if (c == 1)
	{
		printf("%sはドレイン発動!!\n", _this->name);
		AbsorptionAttack(_target, _this, 5);
	}
	if (c == 2)
	{
		PandoraDice(_target, _this);
	}
	if (c == 3)
	{
		NormalAttack(_target, 3);
	}
	if (c == 4)
	{
		HealingPoint(_this, 6);
	}
	if (c == 5)
	{
		SetGuard(_this);
	}
	if (c == 6)
	{
		printf("ミス!,何も起こらなかった\n");
	}
}

void PandoraDice(CharaData *_target, CharaData *_this)
{
	_this->pandoraDiceCount = 0;
	printf("%sのパンドラのダイス始動!!\nダイスを一回振れ!!\n", _this->name);

	printf("next>>\n");
	getchar();

	d = rand() % 6 + 1;
	if (d == 1)
	{
		printf("%sはギガドレイン始動!!\n", _target->name);
		AbsorptionAttack(_target, _this, 10);
	}
	if (d == 2)
	{
		printf("%sは宇宙魔法、ブラックホール始動!!\n", _this->name);
		SacrificeAttack(_target, 15, _this, 1);
	}
	if (d == 3)
	{
		ChangeHP(_target, _this);
	}
	if (d == 4)
	{
		printf("%sはゼウスを召喚した!!\n", _this->name);
		NormalAttack(_target, 13);
	}
	if (d == 5)
	{
		printf("ヒーリング・ノヴァ始動\n");
		HealingPoint(_this, 10);
	}
	if (d == 6)
	{
		printf("次の%sのターン終了時まで、発生する全てのダメージは2倍になる\n", _this->name);
		dou = 3;
	}
}

//通常攻撃//
void NormalAttack(CharaData *_target, int _damage)
{
	if (GuardTest(_target) == Guard_True)
		return;

	printf(_damage <= 4 ? "%sに%dのダメージ\n" : "%sに%dのダメージ!!\n", _target->name, _damage);
	_target->hp -= _damage;
	DoubleTest(_target, _damage);
}

//スタン攻撃//
void StanAttack(CharaData *_target, int _damage)
{
	if (GuardTest(_target) == Guard_True)
		return;

	NormalAttack(_target, _damage);
	_target->stan = 1;
	printf("次の%sのターンをスキップする。\n", _target->name);
}

//アイス攻撃//
void IceAttack(CharaData *_target, int _damage)
{

	if (GuardTest(_target) == Guard_True)
		return;

	NormalAttack(_target, _damage);
	_target->ice = 1;
	printf("次の%sのターンをスキップする。\n", _target->name);
}

//両プレイヤーに攻撃//
void BothPlayerAttack(CharaData *_target, CharaData *_this, int _damage)
{
	printf("%sと%sにダメージを与える\n", _this->name, _target->name);

	NormalAttack(_this, _damage);

	NormalAttack(_target, _damage);
}

//吸収攻撃//
void AbsorptionAttack(CharaData *_target, CharaData *_this, int _damage)
{
	if (GuardTest(_target) == Guard_True)
		return;

	printf((_damage <= 4 ? "%sのLPから%dポイント吸い取る\n" : "%sのLPから%dポイント吸い取る!!\n"), _target->name, _damage);
	_this->hp += _damage;
	_target->hp -= _damage;
}

//自身のHPを指定数にして攻撃//
void SacrificeAttack(CharaData *_target, int _targetDamage, CharaData *_this, int _thisHP)
{
	printf("%sのLPを%dにして攻撃", _this->name, _thisHP);

	_this->hp = _thisHP;

	if (GuardTest(_target) == Guard_True)
		return;

	NormalAttack(_target, _targetDamage);
}

//一部攻撃を未来へ飛ばす攻撃//
void FutureAttack(CharaData *_target, FAObject *_obj, int _damage)
{
	if (GuardTest(_target) == Guard_False)
	{
		NormalAttack(_target, _damage);
	}

	printf("次にダイスを振るプレイヤーに%dのダメージ\n", _obj->damage);
	_obj->flg = 1;
}

//ガードテスト//
char GuardTest(CharaData *_target)
{
	if (_target->nodamage < 1)
		return Guard_False;

	printf("%sは攻撃を防いだ\n", _target->name);
	return Guard_True;
}

//倍ダメージテスト//
void DoubleTest(CharaData *_target, int _damage)
{
	if (dou <= 0)
		return;

	_target->hp -= _damage;
}

//回復//
void HealingPoint(CharaData *_target, int _healingPoint)
{
	printf((_healingPoint <= 4 ? "%sのLPを%d回復\n" : "%sのLPを%d回復!!\n"), _target->name, _healingPoint);
	_target->hp += _healingPoint;
}

//HPを入れ替える//
void ChangeHP(CharaData *_target, CharaData *_this)
{
	printf("%sと%sのLPを入れ替える!\n", _target->name, _this->name);
	_this->hp += _target->hp;
	_target->hp = _this->hp - _target->hp;
	_this->hp -= _target->hp;
}

//ガードさせる//
void SetGuard(CharaData *_target)
{
	printf("%sは守りを固めた!!\n"
		   "(次の%sのターンまで%sが受けるダメージは0となる)\n",
		   _target->name, _target->name, _target->name);
	_target->nodamage = 1;
}
