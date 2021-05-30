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

enum CharaType
{
	Player,
	Enemy
};

int a = 0, b = 0;
int c = 0, d = 0, f = 0, ep = 0, dou = 0;
int ph = 30, eh = 30;
char ps = 0, es = 0;

CharaData charas[2];

//s=スタン、n=ノーダメージ、dou=倍ダメージ,
//pst1,est1=n;pst2,est2=s
//c=クリティカル,m=マジック,g=ガード,h=ヒーリング,

void InitCharaData(CharaData *_data, char *_name);
void Helps();
void StartDice();
void Game();
void FirstPlayer();
void FirstEnemy();
void DicePlayer();
void DiceEnemy();
void Result();

void CriticalDice(CharaData *_target, CharaData *_this);
void MagicDice(CharaData *_target, CharaData *_this);
void GuardDice(CharaData *_target, CharaData *_this);
void HearingDice(CharaData *_target, CharaData *_this);
void PandoraDice(CharaData *_target, CharaData *_this);

int main(void)
{
	srand(time(0));
	rand();

	InitCharaData(&charas[Player], "あなた");
	InitCharaData(&charas[Enemy], "エネミー");

	Helps();

	StartDice();

	Game();

	Result();

	return 0;
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
	printf("enter keyを押してダイスを振ってください\n");

	while (a == b)
	{

		scanf("\n");
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
			printf("あいこです、もう一度振ってください。\n");
		} //if(a==b)

		printf("next\n");
		getchar();
	}
}

void Result()
{
	printf("戦闘終了です!\n%sの", charas[Player].name);
	if (charas[Player].hp > 0)
	{
		printf("勝ちです!!");
	}
	else
	{
		printf("負けです!");
	}
	printf("GameEnd\n");
	getchar();
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

		dou--;
		charas[Player].nodamage = 0;
		printf("\n△%sのLP:%d\n◯%sのLP:%d\n", charas[Player].name, charas[Player].hp, charas[Enemy].name, charas[Enemy].hp);
		printf("next\n");
		getchar();

		printf("△＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n");
		if (charas[Player].stan == 1)
		{ //if(pss!=1)
			printf("\n%sはこのターン行動できません\n", charas[Player].name);
			charas[Player].stan = 0;
		} //if(pss==1)
		else
		{

			if (f == 1)
			{
				printf("%sはファイアーボールの流れ弾が当たった!!\n", charas[Player].name);
				charas[Player].hp -= 2;
				if (dou > 0)
				{
					charas[Player].hp -= 2;
				} //if(dou>0)
				f = 0;
			} //if(f==1)
			printf("\n△%sのターンです\n", charas[Player].name);
			printf("c;クリティカルダイス\n");
			printf("m;マジックダイス\n");
			printf("h;ヒーリングダイス\n");
			printf("g;ガードダイス\n");
			printf("\n使うダイスを宣言して、ダイスを振ってください:");
			scanf("%c", &ps);

			if (charas[Player].pandoraDiceCount >= 6)
			{
				PandoraDice(&charas[Enemy], &charas[Player]);
			} //if(ppn==6)
			else
			{

				charas[Player].pandoraDiceCount++;
				if (ps == 'c')
				{
					CriticalDice(&charas[Enemy], &charas[Player]);
				}
				if (ps == 'm')
				{ //if(ps=='c')
					MagicDice(&charas[Enemy], &charas[Player]);
				}
				if (ps == 'g')
				{ //if(ps=='m')
					GuardDice(&charas[Enemy], &charas[Player]);
				}
				if (ps == 'h')
				{ //if(ps=='g')
					HearingDice(&charas[Enemy], &charas[Player]);
				}
				if (ps != 'c' && ps != 'm' && ps != 'g' && ps != 'h')
				{ //if(ps=='h')
					printf("コマンドを押していないため、このターンは行動できません\n");
				} //if(ps!==''&&pw!='m'&&ps!='g'&&ps!='h')
			}
		}
	}
	printf("next\n");
	getchar();
}

void DiceEnemy()
{

	if (charas[Player].hp > 0 && charas[Enemy].hp > 0)
	{
		dou--;
		charas[Enemy].nodamage = 0;

		printf("\n△%sのLP:%d\n◯%sのLP:%d\n", charas[Player].name, charas[Player].hp, charas[Enemy].name, charas[Enemy].hp);
		printf("next\n");
		getchar();
		printf("◯＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n");

		if (f == 1)
		{
			printf("%sはファイアーボールの流れ弾が当たった!!\n", charas[Enemy].name);
			charas[Enemy].hp -= 2;
			if (dou > 0)
			{
				charas[Enemy].hp -= 2;
			} //if(dou>0)
			f = 0;
		} //if(==1)
		printf("\n◯%sのターンです\n", charas[Enemy].name);
		printf("next\n");
		getchar();
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
				if (10 > eh && eh > 0)
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
				else if (20 > eh && eh >= 10)
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
				if (eh >= 20)
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
		printf("next\n");
		getchar();
	} //if(eh>0&&ph>0)
}

void CriticalDice(CharaData *_target, CharaData *_this)
{
	_this->pandoraDiceCount++;
	printf("%sはクリティカルダイスを振りました。\n", _this->name);
	c = rand() % 6 + 1;
	if (c == 1)
	{
		printf("クリティカルヒット!!\n");
		printf("%sに7のダメージ!!\n", _target->name);
		if (_target->nodamage != 1)
		{
			_target->hp -= 7;
			if (dou > 0)
			{
				_target->hp -= 7;
			} //if(dou>0)
		}	  //if(esn!=1)
	}
	if (c == 2)
	{ //if(c==
		printf("ミス!%sに0ダメージ\n", _target->name);
	}
	if (c == 3)
	{ //if(c==2)
		printf("クリティカルヒット!!\n");
		printf("%sに5のダメージ!!次の%sのターンをスキップする。\n", _target->name, _target->name);
		if (_target->nodamage != 1)
		{
			_target->hp -= 5;
			if (dou > 0)
			{
				_target->hp -= 5;
			} //if(dou>0)
			_target->stan = 1;
		} //if(esn!=1)
	}
	if (c == 4)
	{ //if(c==3)
		printf("%sに2のダメージ\n", _target->name);
		if (_target->nodamage != 1)
		{
			_target->hp -= 2;
			if (dou > 0)
			{
				_target->hp -= 2;
			} //if(dou>0)
		}	  //if(esn!=1)
	}
	if (c == 5)
	{ //if(c==4)
		PandoraDice(_target, _this);
	}
	if (c == 6)
	{ //if(c==5)
		printf("クリティカルヒット!!\n");
		printf("%sに5のダメージ!!次の%sのターンをスキップする。\n", _target->name);
		if (_target->nodamage != 1)
		{
			_target->hp -= 5;
			if (dou > 0)
			{
				_target->hp -= 5;
			} //if(dou>0)
			_target->stan = 1;
		} //if(esn!=1)
	}	  //if(c==6)
}

void MagicDice(CharaData *_target, CharaData *_this)
{
	printf("%sはマジックダイスを振りました。\n", _this->name);
	c = rand() % 6 + 1;
	if (c == 1)
	{
		printf("炎魔法、ファイアーボール発動!!\n");
		printf("%sに2のダメージ!!,次にダイスを振るプレイヤーに2のダメージを与える。\n", _target->name);
		if (_target->nodamage != 1)
		{
			_target->hp -= 2;
			if (dou > 0)
			{
				_target->hp -= 2;
			} //if(dou>0)
		}	  //if(esn!=1)
		f = 1;
	}
	if (c == 2)
	{ //if(c==1)
		printf("雷魔法、サンダーボルト発動!!\n");
		printf("お互いに4のダメージ!!\n");
		_this->hp -= 4;
		if (dou > 0)
		{
			_this->hp -= 4;
		} //if(dou>0)
		if (_target->nodamage != 1)
		{
			_target->hp -= 4;
			if (dou > 0)
			{
				_target->hp -= 4;
			} //if(dou>0)
		}	  //if(esn!=1)
	}
	if (c == 3)
	{ //if(c==2)
		printf("ミス!、%sに0のダメージ\n", _target->name);
	}
	if (c == 4)
	{ //if(c==3)
		PandoraDice(_target, _this);
	}
	if (c == 5)
	{
		printf("氷魔法、サークルフロスト発動!!\n");
		printf("%sに3のダメージ!!次の%sのターンをスキップする。\n", _target->name, _target->name);
		if (_target->nodamage != 1)
		{
			_target->hp -= 3;
			if (dou > 0)
			{
				_target->hp -= 3;
			} //if(dou>0)
			_target->stan = 1;
		} //if(esn!=1)
	}
	if (c == 6)
	{ //if(c==5)
		printf("宇宙魔法、メテオ発動!!\n");
		printf("%sのLPを1にして、%sに10のダメージ!!\n", _this->name, _target->name);
		_this->hp = 1;
		if (_target->nodamage != 1)
		{
			_target->hp -= 10;
			if (dou > 0)
			{
				_target->hp -= 10;
			} //if(dou>0)
		}	  //if(esn!=1)
	}		  //if(c==6)
}

void GuardDice(CharaData *_target, CharaData *_this)
{
	printf("%sはガードダイスを振りました。\n", _this->name);
	c = rand() % 6 + 1;
	if (c == 1)
	{
		printf("クリティカルヒット!!\n");
		printf("%sに4のダメージ!!、次の%sのターンまで受けるダメージは0になる。\n", _target->name, _this->name);
		_this->nodamage = 1;
		if (_target->nodamage != 1)
		{
			_target->hp -= 4;
			if (dou > 0)
			{
				_target->hp -= 4;
			} //if(dou>0)
		}	  //if(esn!=1)
	}
	if (c == 2)
	{ //if(c==1)
		printf("%sは守りを固めた!!\n(次の%sのターンまで%sが受けるダメージは0になる)\n", _this->name, _this->name, _this->name);
		_this->nodamage = 1;
	}
	if (c == 3)
	{ //if(c==2)
		PandoraDice(_target, _this);
	}
	if (c == 4)
	{ //if(c==3)
		printf("ミス!、何も起こらなかった。\n");
	}
	if (c == 5)
	{ //if(c==4)
		printf("%sに1のダメージ!\n", _target->name);
		if (_target->nodamage != 1)
		{
			_target->hp -= 1;
			if (dou > 0)
			{
				_target->hp -= 1;
			} //if(dou>0)
		}	  //if(esn!=1)
	}
	if (c == 6)
	{ //if(c==5)
		printf("%sは守りを固めた!!\n(次の%sのターンまで%sが受けるダメージは0になる)\n", _this->name, _this->name, _this->name);
		_this->nodamage = 1;
	} //if(c==6)
}

void HearingDice(CharaData *_target, CharaData *_this)
{
	printf("%sはヒーリングダイスを振りました。\n", _this->name);
	c = rand() % 6 + 1;
	if (c == 1)
	{
		printf("ドレイン発動!!\n%sのLPから4ポイント吸い取る\n", _target->name);
		if (_target->nodamage != 1)
		{
			_target->hp -= 4;
			_this->hp += 4;
		} //if(esn!=1)
	}
	if (c == 2)
	{ //if(c==1)
		PandoraDice(_target, _this);
	}
	if (c == 3)
	{ //if(c==2)
		printf("%sに2のダメージ!!\n", _target);
		if (_target->nodamage != 1)
		{
			_target->hp -= 2;
			if (dou > 0)
			{
				_target->hp -= 2;
			} //if(dou>0)
		}	  //if(esn!=1)
	}
	if (c == 4)
	{ //if(c==3)
		printf("%sのLPを3回復!!\n", _this->name);
		_this->hp += 3;
	}
	if (c == 5)
	{ //if(c==4)
		printf("%sは守りを固めた!!/n"
			   "(次の%sのターンまで%sが受けるダメージは0となる)\n",
			   _this->name, _this->name, _this->name);
		_this->nodamage = 1;
	}
	if (c == 6)
	{ //if(c==5)
		printf("ミス!,何も起こらなかった\n");
	} //if(c==6)
}

void PandoraDice(CharaData *_target, CharaData *_this)
{
	_this->pandoraDiceCount = 0;
	printf("%sのパンドラのダイス始動!!\nダイスを一回振れ!!\n", _this->name);
	scanf("\n");
	d = rand() % 6 + 1;
	if (d == 1)
	{
		printf("ギガドレイン始動!!\n%sのLPから10ポイント吸い取る!!\n", _target->name);

		if (_target->nodamage != 1)
		{
			_this->hp += 10;
			_target->hp -= 10;
		} //if(esn!=1)
	}
	if (d == 2)
	{ //if(d==1)
		printf("宇宙魔法、ブラックホール始動!!\n%sのLP1にして、%sに15のダメージ!!\n", _this->name, _target->name);

		_this->hp = 1;

		if (_target->nodamage != 1)
		{
			_target->hp -= -15;
			if (dou > 0)
			{
				_target->hp -= -15;
			} //if(dou>0)
		}	  //if(esn!=1)
	}
	if (d == 3)
	{ //if(d==2)
		printf("%sと%sのLPを入れ替える!\n", _target->name, _this->name);
		_this->hp += _target->hp;
		_target->hp = _this->hp - _target->hp;
		_this->hp -= _target->hp;
	}
	if (d == 4)
	{ //if(d==3)
		printf("%sはゼウスを召喚した!!\n%sに13のダメージ!!\n", _this->name, _target->name);

		if (_target->nodamage != 1)
		{
			_target->hp -= 13;
			if (dou > 0)
			{
				_target->hp -= 13;
			} //if(dou>0)
		}	  //if(esn!=1)
	}
	if (d == 5)
	{ //if(d==4)
		printf("ヒーリング・ノヴァ始動\n%sのLPを10回復!!\n", _this->name);
		_this->hp += 10;
	}
	if (d == 6)
	{ //if(d==5)
		printf("次の%sのターン終了時まで、発生する全てのダメージは2倍になる\n", _this->name);
		while (dou < 3)
		{
			dou++;
		} //while(dou<3)
	}	  //if(d==6)
}