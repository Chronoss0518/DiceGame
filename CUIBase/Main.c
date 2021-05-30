#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct CharactorData
{
	char* name;
	int hp;
	int stan;
	int nodamage;
	int ice;
} CharaData;

int a = 0, b = 0;
int c = 0, d = 0, f = 0, ep = 0, dou = 0, psn = 0, esn = 0, pss = 0, ess = 0, ppn = 0, epn = 0, etd = 0, turn = 0;
int ph = 30, eh = 30;
char ps = 0, es = 0;

CharaData charas;

//s=スタン、n=ノーダメージ、dou=倍ダメージ,
//pst1,est1=n;pst2,est2=s
//c=クリティカル,m=マジック,g=ガード,h=ヒーリング,
void Helps();
void StartDice();
void Game();
void FirstPlayer();
void FirstEnemy();
void DicePlayer();
void DiceEnemy();
void Result();

void CriticalDice(char* _name,int* _hp, int* _stn, int* _nod,int* _thisHp,int* _thisNod);
void MagicDice(char* _name,int* _hp, int* _stn, int* _nod,int* _thisHp,int* _thisNod);
void GuardDice(char* _name,int* _hp, int* _stn, int* _nod,int* _thisHp,int* _thisNod);
void HearingDice(char* _name,int* _hp, int* _stn, int* _nod,int* _thisHp,int* _thisNod);
void Pandora

int main(void)
{
	srand(time(0));
	rand();

	Helps();

	StartDice();

	Game();

	Result();

	
	return 0;
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

		printf("あなたの目は%dです。\n", a);
		printf("相手の目は%dです。\n", b);

		if (a > b)
		{
			printf("あなたが先行です。\n");
		}
		if (a < b)
		{ //if(a>b)
			printf("あなたは後攻です。\n");
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
	printf("戦闘終了です!\nあなたの");
	if (ph > 0)
	{
		printf("勝ちです!!");
	}
	else
	{
		printf("負けです!");
	}
}

void Game()
{

	while (ph > 0 && eh > 0)
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

	if (eh > 0 && ph > 0)
	{

		dou--;
		psn = 0;
		printf("\n△あなたのLP:%d\n◯相手のLP:%d\n", ph, eh);
		printf("next\n");
		getchar();

		printf("△＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n");
		if (pss != 1)
		{
			if (f == 1)
			{
				printf("ファイアーボールの流れ弾が当たった!!\n");
				ph = ph - 2;
				if (dou > 0)
				{
					ph = ph - 2;
				} //if(dou>0)
				f = 0;
			} //if(f==1)
			printf("\n△あなたのターンです\n");
			printf("c;クリティカルダイス\n");
			printf("m;マジックダイス\n");
			printf("h;ヒーリングダイス\n");
			printf("g;ガードダイス\n");
			printf("\n使うダイスを宣言して、ダイスを振ってください:");
			scanf("%c", &ps);
			if (ps == 'c')
			{
				printf("あなたはクリティカルダイスを振りました。\n");
				c = rand() % 6 + 1;
				if (c == 1)
				{
					printf("クリティカルヒット!!\n");
					printf("相手に7のダメージ!!\n");
					if (esn != 1)
					{
						eh = eh - 7;
						if (dou > 0)
						{
							eh = eh - 7;
						} //if(dou>0)
					}	  //if(esn!=1)
					ppn++;
				}
				if (c == 2)
				{ //if(c==
					printf("ミス!相手に0ダメージ\n");
					ppn++;
				}
				if (c == 3)
				{ //if(c==2)
					printf("クリティカルヒット!!\n");
					printf("相手に5のダメージ!!次の相手のターンをスキップする。\n");
					if (esn != 1)
					{
						eh = eh - 5;
						if (dou > 0)
						{
							eh = eh - 5;
						} //if(dou>0)
						ess = 1;
					} //if(esn!=1)
					ppn++;
				}
				if (c == 4)
				{ //if(c==3)
					printf("相手に2のダメージ\n");
					if (esn != 1)
					{
						eh = eh - 2;
						if (dou > 0)
						{
							eh = eh - 2;
						} //if(dou>0)
					}	  //if(esn!=1)
					ppn++;
				}
				if (c == 5)
				{ //if(c==4)
					ppn = 0;
					printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
					scanf("\n");
					d = rand() % 6 + 1;
					if (d == 1)
					{
						printf("ギガドレイン始動!!\n相手のLPから10ポイント吸い取る!!\n");
						if (esn != 1)
						{
							ph = ph + 10;
							eh = eh - 10;
						} //if(esn!=1)
					}
					if (d == 2)
					{ //if(c==1)
						printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、相手に15のダメージ!!\n");
						ph = 1;
						if (esn != 1)
						{
							ph = 1;
							eh = eh - 15;
							if (dou > 0)
							{
								eh = eh - 15;
							} //if(dou>0)
						}	  //if(esn!=1)
					}
					if (d == 3)
					{ //if(d==2)
						printf("相手と自分のLPを入れ替える!\n");
						ph = ph + eh;
						eh = ph - eh;
						ph = ph - eh;
					}
					if (d == 4)
					{ //if(d==3)
						printf("ゼウスを召喚した!!\n相手に13のダメージ!!\n");
						if (esn != 1)
						{
							eh = eh - 13;
							if (dou > 0)
							{
								eh = eh - 13;
							} //if(dou>0)
						}	  //if(esn!=1)
					}
					if (d == 5)
					{ //if(d==4)
						printf("ヒーリング・ノヴァ始動\n自分のLPを10回復!!\n");
						ph = ph + 10;
					}
					if (d == 6)
					{ //if(d==5)
						printf("次の自分のターン終了時まで、発生する全てのダメージは2倍になる\n");
						while (dou < 3)
						{
							dou++;
						} //while(dou<3)
					}	  //if(d==6)
				}
				if (c == 6)
				{ //if(c==5)
					printf("クリティカルヒット!!\n");
					printf("相手に5のダメージ!!次の相手のターンをスキップする。\n");
					if (esn != 1)
					{
						eh = eh - 5;
						if (dou > 0)
						{
							eh = eh - 5;
						} //if(dou>0)
						ess = 1;
					} //if(esn!=1)
					ppn++;
				} //if(c==6)
			}
			if (ps == 'm')
			{ //if(ps=='c')
				printf("あなたはマジックダイスを振りました。\n");
				c = rand() % 6 + 1;
				if (c == 1)
				{
					printf("炎魔法、ファイアーボール発動!!\n");
					printf("相手に2のダメージ!!,次にダイスを振るプレイヤーに2のダメージを与える。\n");
					if (esn != 1)
					{
						eh = eh - 2;
						if (dou > 0)
						{
							eh = eh - 2;
						} //if(dou>0)
					}	  //if(esn!=1)
					f = 1;
					ppn++;
				}
				if (c == 2)
				{ //if(c==1)
					printf("雷魔法、サンダーボルト発動!!\n");
					printf("お互いに4のダメージ!!\n");
					ph = ph - 4;
					if (dou > 0)
					{
						ph = ph - 4;
					} //if(dou>0)
					if (esn != 1)
					{
						eh = eh - 4;
						if (dou > 0)
						{
							eh = eh - 4;
						} //if(dou>0)
					}	  //if(esn!=1)
					ppn++;
				}
				if (c == 3)
				{ //if(c==2)
					printf("ミス!、相手に0のダメージ\n");
					ppn++;
				}
				if (c == 4)
				{ //if(c==3)
					ppn = 0;
					printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
					scanf("\n");
					d = rand() % 6 + 1;
					if (d == 1)
					{
						printf("ギガドレイン始動!!\n相手のLPから10ポイント吸い取る!!\n");
						if (esn != 1)
						{
							ph = ph + 10;
							eh = eh - 10;
						} //if(esn!=1)
					}
					if (d == 2)
					{ //if(d==1)
						printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、相手に15のダメージ!!\n");
						ph = 1;
						if (esn != 1)
						{
							eh = eh - 15;
							if (dou > 0)
							{
								eh = eh - 15;
							} //if(dou>0)
						}	  //if(esn!=1)
					}
					if (d == 3)
					{ //if(d==2)
						printf("相手と自分のLPを入れ替える!\n");
						ph = ph + eh;
						eh = ph - eh;
						ph = ph - eh;
					}
					if (d == 4)
					{ //if(d==3)
						printf("ゼウスを召喚した!!\n相手に13のダメージ!!\n");
						if (esn != 1)
						{
							eh = eh - 13;
							if (dou > 0)
							{
								eh = eh - 13;
							} //if(dou>0)
						}	  //if(esn!=1)
					}
					if (d == 5)
					{ //if(d==4)
						printf("ヒーリング・ノヴァ始動\n自分のLPを10回復!!\n");
						ph = ph + 10;
					}
					if (d == 6)
					{ //if(d==5)
						printf("次の自分のターン終了時まで、発生する全てのダメージは2倍になる\n");
						while (dou < 3)
						{
							dou++;
						} //while(dou<3)
					}	  //if(d==6)
				}
				if (c == 5)
				{
					printf("氷魔法、サークルフロスト発動!!\n");
					printf("相手に3のダメージ!!次の相手のターンをスキップする。\n");
					if (esn != 1)
					{
						eh = eh - 3;
						if (dou > 0)
						{
							eh = eh - 3;
						} //if(dou>0)
						ess = 1;
					} //if(esn!=1)
					ppn++;
				}
				if (c == 6)
				{ //if(c==5)
					printf("宇宙魔法、メテオ発動!!\n");
					printf("自身のLPを1にして、相手に10のダメージ!!\n");
					ph = 1;
					if (esn != 1)
					{
						eh = eh - 10;
						if (dou > 0)
						{
							eh = eh - 10;
						} //if(dou>0)
					}	  //if(esn!=1)
					ppn++;
				} //if(c==6)
			}
			if (ps == 'g')
			{ //if(ps=='m')
				printf("あなたはガードダイスを振りました。\n");
				c = rand() % 6 + 1;
				if (c == 1)
				{
					printf("クリティカルヒット!!\n");
					printf("相手に4のダメージ!!、次の自分のターンまで受けるダメージは0になる。\n");
					psn = 1;
					if (esn != 1)
					{
						eh = eh - 4;
						if (dou > 0)
						{
							eh = eh - 4;
						} //if(dou>0)
					}	  //if(esn!=1)
					ppn++;
				}
				if (c == 2)
				{ //if(c==1)
					printf("守りを固めた!!\n(次の自分のターンまで自身が受けるダメージは0になる)\n");
					psn = 1;
					ppn++;
				}
				if (c == 3)
				{ //if(c==2)
					ppn = 0;
					printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
					scanf("\n");
					d = rand() % 6 + 1;
					if (d == 1)
					{
						printf("ギガドレイン始動!!\n相手のLPから10ポイント吸い取る!!\n");
						if (esn != 1)
						{
							ph = ph + 10;
							eh = eh - 10;
						} //if(esn!=1)
					}
					if (d == 2)
					{ //if(d==1)
						printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、相手に15のダメージ!!\n");
						ph = 1;
						if (esn != 1)
						{
							eh = eh - 15;
							if (dou > 0)
							{
								eh = eh - 15;
							} //if(dou>0)
						}	  //if(esn!=1)
					}
					if (d == 3)
					{ //if(d==2)
						printf("相手と自分のLPを入れ替える!\n");
						ph = ph + eh;
						eh = ph - eh;
						ph = ph - eh;
					}
					if (d == 4)
					{ //if(d==3)
						printf("ゼウスを召喚した!!\n相手に13のダメージ!!\n");
						if (esn != 1)
						{
							eh = eh - 13;
							if (dou > 0)
							{
								eh = eh - 13;
							} //if(dou>0)
						}	  //if(esn!=1)
					}
					if (d == 5)
					{ //if(d==4)
						printf("ヒーリング・ノヴァ始動\n自分のLPを10回復!!\n");
						ph = ph + 10;
					}
					if (d == 6)
					{ //if(d==5)
						printf("次の自分のターン終了時まで、発生する全てのダメージは2倍になる\n");
						while (dou < 3)
						{
							dou++;
						} //while(dou<3)
					}	  //if(d==6)
				}
				if (c == 4)
				{ //if(c==3)
					printf("ミス!、何も起こらなかった。\n");
					ppn++;
				}
				if (c == 5)
				{ //if(c==4)
					printf("相手に1のダメージ!\n");
					if (esn != 1)
					{
						eh = eh - 1;
						if (dou > 0)
						{
							eh = eh - 1;
						} //if(dou>0)
					}	  //if(esn!=1)
					ppn++;
				}
				if (c == 6)
				{ //if(c==5)
					printf("守りを固めた!!\n(次の自分のターンまで、自身が受けるダメージは0になる)\n");
					psn = 1;
					ppn++;
				} //if(c==6)
			}
			if (ps == 'h')
			{ //if(ps=='g')
				printf("あなたはヒーリングダイスを振りました。\n");
				c = rand() % 6 + 1;
				if (c == 1)
				{
					printf("ドレイン発動!!\n相手のLPから4ポイント吸い取る\n");
					if (esn != 1)
					{
						eh = eh - 4;
						ph = ph + 4;
					} //if(esn!=1)
					ppn++;
				}
				if (c == 2)
				{ //if(c==1)
					ppn = 0;
					printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
					scanf("\n");
					d = rand() % 6 + 1;
					if (d == 1)
					{
						printf("ギガドレイン始動!!\n相手のLPから10ポイント吸い取る!!\n");
						if (esn != 1)
						{
							ph = ph + 10;
							eh = eh - 10;
						} //if(esn!=1)
					}
					if (d == 2)
					{ //if(d==1)
						printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、相手に15のダメージ!!\n");
						ph = 1;
						if (esn != 1)
						{
							ph = 1;
							eh = eh - 15;
							if (dou > 0)
							{
								eh = eh - 15;
							} //if(dou>0)
						}	  //if(esn!=1)
					}
					if (d == 3)
					{ //if(d==2)
						printf("相手と自分のLPを入れ替える!\n");
						ph = ph + eh;
						eh = ph - eh;
						ph = ph - eh;
					}
					if (d == 4)
					{ //if(d==3)
						printf("ゼウスを召喚した!!\n相手に13のダメージ!!\n");
						if (esn != 1)
						{
							eh = eh - 13;
							if (dou > 0)
							{
								eh = eh - 13;
							} //if(dou>0)
						}	  //if(esn!=1)
					}
					if (d == 5)
					{ //if(d==4)
						printf("ヒーリング・ノヴァ始動\n自分のLPを10回復!!\n");
						ph = ph + 10;
					}
					if (d == 6)
					{ //if(d==5)
						printf("次の自分のターン終了時まで、発生する全てのダメージは2倍になる\n");
						while (dou < 3)
						{
							dou++;
						} //if(dou>3)
					}	  //if(d==6)
				}
				if (c == 3)
				{ //if(c==2)
					printf("相手に2のダメージ!!\n");
					if (esn != 1)
					{
						eh = eh - 2;
						if (dou > 0)
						{
							eh = eh - 2;
						} //if(dou>0)
					}	  //if(esn!=1)
					ppn++;
				}
				if (c == 4)
				{ //if(c==3)
					printf("自身のLPを3回復!!\n");
					ph = ph + 3;
					ppn++;
				}
				if (c == 5)
				{ //if(c==4)
					printf("守りを固めた!!/n");
					printf("(次の自分のターンまで自身が受けるダメージは0となる)\n");
					psn = 1;
					ppn++;
				}
				if (c == 6)
				{ //if(c==5)
					printf("ミス!,何も起こらなかった\n");
					ppn++;
				} //if(c==6)
			}
			if (ps != 'c' && ps != 'm' && ps != 'g' && ps != 'h')
			{ //if(ps=='h')
				printf("コマンドを押していないため、このターンは行動できません\n");
			} //if(ps!==''&&pw!='m'&&ps!='g'&&ps!='h')
			if (ppn == 6)
			{
				ppn = 0;
				printf("パンドラのダイス強制始動!!\nダイスを一回振れ!!\n");
				scanf("\n");
				d = rand() % 6 + 1;
				if (d == 1)
				{
					printf("ギガドレイン始動!!\n相手のLPから10ポイント吸い取る!!\n");
					if (esn != 1)
					{
						ph = ph + 10;
						eh = eh - 10;
					} //if(esn!=1)
				}
				if (d == 2)
				{ //if(d==1)
					printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、相手に15のダメージ!!\n");
					ph = 1;
					if (esn != 1)
					{
						ph = 1;
						eh = eh - 15;
						if (dou > 0)
						{
							eh = eh - 15;
						} //if(dou>0)
					}	  //if(esn!=1)
				}
				if (d == 3)
				{ //if(d==2)
					printf("相手と自分のLPを入れ替える!\n");
					ph = ph + eh;
					eh = ph - eh;
					ph = ph - eh;
				}
				if (d == 4)
				{ //if(d==3)
					printf("ゼウスを召喚した!!\n相手に13のダメージ!!\n");
					if (esn != 1)
					{
						eh = eh - 13;
						if (dou > 0)
						{
							eh = eh - 13;
						} //if(dou>0)
					}	  //if(esn!=1)
				}
				if (d == 5)
				{ //if(d==4)
					printf("ヒーリング・ノヴァ始動\n自分のLPを10回復!!\n");
					ph = ph + 10;
				}
				if (d == 6)
				{ //if(d==5)
					printf("次の自分のターン終了時まで、発生する全てのダメージは2倍になる\n");
					while (dou < 3)
					{
						dou++;
					} //while(dou<3)
				}	  //if(d==6)
			}		  //if(ppn==6)
		}
		if (pss == 1)
		{ //if(pss!=1)
			printf("\nあなたはこのターン行動できません\n");
			pss = 0;
		} //if(pss==1)
		printf("next\n");
		getchar();
	} //if(ph>0)
}

void DiceEnemy()
{

	if (eh > 0 && ph > 0)
	{
		dou--;
		esn = 0;

		printf("\n△あなたのLP:%d\n◯相手のLP:%d\n", ph, eh);
		printf("next\n");
		getchar();
		printf("◯＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n");
		if (ess != 1)
		{
			if (f == 1)
			{
				printf("ファイアーボールの流れ弾が当たった!!\n");
				eh = eh - 2;
				if (dou > 0)
				{
					eh = eh - 2;
				} //if(dou>0)
				f = 0;
			} //if(==1)
			printf("\n◯相手のターンです\n");
			getchar();
			etd = 1;
			if (epn != 6)
			{
				if (10 > eh && eh > 0 && etd == 1)
				{
					etd = 0;
					ep = rand() % 2 + 1;
					if (ep == 1)
					{
						printf("相手はガードダイスを振りました\n");
						c = rand() % 6 + 1;
						if (c == 1)
						{
							printf("クリティカルヒット!!\n");
							printf("あなたに4のダメージ!!、次の相手のターンまで相手が受けるダメージは0になる。\n");
							esn = 1;
							if (psn != 1)
							{
								ph = ph - 4;
								if (dou > 0)
								{
									ph = ph - 4;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 2)
						{ //if(c==1)
							printf("守りを固めた!!\n(次の相手のターンまで相手が受けるダメージは0になる)\n");
							esn = 1;
							epn++;
						}
						if (c == 3)
						{ //if(c==2)
							epn = 0;
							printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
							d = rand() % 6 + 1;
							if (d == 1)
							{
								printf("ギガドレイン始動!!\nあなたのLPから10ポイント吸い取る!!\n");
								if (psn != 1)
								{
									eh = eh + 10;
									ph = ph - 10;
								} //if(ps1!='n')
							}
							if (d == 2)
							{ //if(c==1)
								printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、あなたに15のダメージ!!\n");
								eh = 1;
								if (psn != 1)
								{
									ph = ph - 15;
									if (dou > 0)
									{
										ph = ph - 15;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 3)
							{ //if(c==2)
								printf("相手と自分のLPを入れ替える!\n");
								ph = ph + eh;
								eh = ph - eh;
								ph = ph - eh;
							}
							if (d == 4)
							{ //if(c==3)
								printf("ゼウスを召喚した!!\nあなたに13のダメージ!!\n");
								if (psn != 1)
								{
									ph = ph - 13;
									if (dou > 0)
									{
										ph = ph - 13;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 5)
							{ //if(c==4)
								printf("ヒーリング・ノヴァ始動\n相手はLPを10回復!!\n");
								eh = eh + 10;
							}
							if (d == 6)
							{ //if(c==5)
								printf("次の相手のターン終了時まで、発生する全てのダメージは2倍になる\n");
								while (dou < 3)
								{
									dou++;
								} //while(dou<3)
							}	  //if(c==6)
						}
						if (c == 4)
						{ //if(c==3)
							printf("ミス!、何も起こらなかった。\n");
							epn++;
						}
						if (c == 5)
						{ //if(c==4)
							printf("あなたに1のダメージ!\n");
							if (psn != 1)
							{
								ph = ph - 1;
								if (dou > 0)
								{
									ph = ph - 1;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 6)
						{ //if(c==5)
							printf("守りを固めた!!\n(次の自分のターンまで、自身が受けるダメージは0になる)\n");
							esn = 1;
							epn++;
						} //if(c==6)
					}
					if (ep == 2)
					{ //if(ep==1)
						printf("相手はヒーリングダイスを振りました\n");
						c = rand() % 6 + 1;
						if (c == 1)
						{
							printf("ドレイン発動!!\nあなたのLPから4ポイント吸い取る\n");
							if (psn != 1)
							{
								ph = ph - 4;
								eh = eh + 4;
							} //if(psn!=1)
							epn++;
						}
						if (c == 2)
						{ //if(c==1)
							epn = 0;
							printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
							d = rand() % 6 + 1;
							if (d == 1)
							{
								printf("ギガドレイン始動!!\nあなたのLPから10ポイント吸い取る!!\n");
								if (psn != 1)
								{
									eh = eh + 10;
									ph = ph - 10;
								} //if(psn!=1)
							}
							if (d == 2)
							{ //if(c==1)
								printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、あなたに15のダメージ!!\n");
								eh = 1;
								if (psn != 1)
								{
									ph = ph - 15;
									if (dou > 0)
									{
										ph = ph - 15;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 3)
							{ //if(c==2)
								printf("相手と自分のLPを入れ替える!\n");
								ph = ph + eh;
								eh = ph - eh;
								ph = ph - eh;
							}
							if (d == 4)
							{ //if(c==3)
								printf("ゼウスを召喚した!!\nあなたに13のダメージ!!\n");
								if (psn != 1)
								{
									ph = ph - 13;
									if (dou > 0)
									{
										ph = ph - 13;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 5)
							{ //if(c==4)
								printf("ヒーリング・ノヴァ始動\nあいてはLPを10回復!!\n");
								eh = eh + 10;
							}
							if (d == 6)
							{ //if(c==5)
								printf("次の相手のターン終了時まで、発生する全てのダメージは2倍になる\n");
								while (dou < 3)
								{
									dou++;
								} //while(dou<3)
							}	  //if(c==6)
						}
						if (c == 3)
						{ //if(c==2)
							printf("あなたに2のダメージ!!\n");
							if (psn != 1)
							{
								ph = eh - 2;
								if (dou > 0)
								{
									ph = ph - 2;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 4)
						{ //if(c==3)
							printf("あいてはLPを3回復!!\n");
							eh = eh + 3;
							epn++;
						}
						if (c == 5)
						{ //if(c==4)
							printf("守りを固めた!!/n");
							printf("(次の相手のターンまで相手が受けるダメージは0となる)\n");
							esn = 1;
							epn++;
						}
						if (c == 6)
						{ //if(c==5)
							printf("ミス!,何も起こらなかった\n");
							epn++;
						} //if(c==6)
					}	  //if(ep==2)
				}
				if (20 > eh && eh >= 10 && etd == 1)
				{ //if(10>eh&&eh>0&&etd==1)
					etd = 0;
					ep = rand() % 4 + 1;
					if (ep == 1)
					{
						printf("相手はクリティカルダイスを振りました。\n");
						c = rand() % 6 + 1;
						if (c == 1)
						{
							printf("クリティカルヒット!!\n");
							printf("あなたに7のダメージ!!\n");
							if (psn != 1)
							{
								ph = ph - 7;
								if (dou > 0)
								{
									ph = ph - 7;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 2)
						{ //if(c==1)
							printf("ミス!あなたに0ダメージ\n");
							epn++;
						}
						if (c == 3)
						{ //if(c==2)
							printf("クリティカルヒット!!\n");
							printf("あなたに5のダメージ!!次のあなたのターンをスキップする。\n");
							if (psn != 1)
							{
								ph = ph - 5;
								if (dou > 0)
								{
									ph = ph - 5;
								} //if(dou>0)
								pss = 1;
							} //if(psn!=1)
							epn++;
						}
						if (c == 4)
						{ //if(c==3)
							printf("あなたに2のダメージ\n");
							if (psn != 1)
							{
								ph = ph - 2;
								if (dou > 0)
								{
									ph = ph - 2;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 5)
						{ //if(c==4)
							epn = 0;
							printf("パンドラのダイス始動!!\nダイスを一回振れ!!");
							d = rand() % 6 + 1;
							if (d == 1)
							{
								printf("ギガドレイン始動!!\nあなたのLPから10ポイント吸い取る!!\n");
								if (psn != 1)
								{
									eh = eh + 10;
									ph = ph - 10;
								} //if(psn!=1)
							}
							if (d == 2)
							{ //if(c==1)
								printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、相手に15のダメージ!!\n");
								eh = 1;
								if (psn != 1)
								{
									ph = ph - 15;
									if (dou > 0)
									{
										ph = ph - 15;
									} //ih(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 3)
							{ //if(c==2)
								printf("相手と自分のLPを入れ替える!\n");
								ph = ph + eh;
								eh = ph - eh;
								ph = ph - eh;
							}
							if (d == 4)
							{ //if(c==3)
								printf("ゼウスを召喚した!!\nあなたに13のダメージ!!\n");
								if (psn != 1)
								{
									ph = ph - 13;
									if (dou > 0)
									{
										ph = ph - 13;
									} ///if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 5)
							{ //if(c==4)
								printf("ヒーリング・ノヴァ始動\n相手はLPを10回復!!\n");
								eh = eh + 10;
							}
							if (d == 6)
							{ //if(c==5)
								printf("次の相手のターン終了時まで、発生する全てのダメージは2倍になる\n");
								while (dou < 3)
								{
									dou++;
								} //while(dou<3)
							}	  //if(c==6)
						}
						if (c == 6)
						{ //if(c==5)
							printf("クリティカルヒット!!\n");
							printf("あなたに5のダメージ!!次のあなたのターンをスキップする。\n");
							if (psn != 1)
							{
								ph = ph - 5;
								if (dou > 0)
								{
									ph = ph - 5;
								} //if(dou>0)
								pss = 1;
							} //if(pstn!=1)
							epn++;
						} //if(c==6)
					}
					if (ep == 2)
					{ //if(ep==1)
						printf("相手はマジックダイスを振りました。\n");
						c = rand() % 6 + 1;
						if (c == 1)
						{
							printf("炎魔法、ファイアーボール発動!!\n");
							printf("あなたに2のダメージ!!,次にダイスを振るプレイヤーに2のダメージを与える。!");
							if (psn != 1)
							{
								ph = ph - 2;
								if (dou > 0)
								{
									ph = ph - 2;
								} //if(dou>0)
							}	  //if(psn!=1)
							f = 1;
							epn++;
						}
						if (c == 2)
						{ //if(c==1)
							printf("雷魔法、サンダーボルト発動!!\n");
							printf("お互いに4のダメージ!!\n");
							eh = eh - 4;
							if (dou > 0)
							{
								eh = eh - 4;
							} //if(dou>0)
							if (psn != 1)
							{
								ph = ph - 4;
								if (dou > 0)
								{
									ph = ph - 4;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 3)
						{ //if(c==2)
							printf("ミス!、あなたに0のダメージ\n");
							epn++;
						}
						if (c == 4)
						{ //if(c==3)
							epn = 0;
							printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
							d = rand() % 6 + 1;
							if (d == 1)
							{
								printf("ギガドレイン始動!!\nあなたのLPから10ポイント吸い取る!!\n");
								if (psn != 1)
								{
									eh = eh + 10;
									ph = ph - 10;
								} //if(psn!=1)
							}
							if (d == 2)
							{ //if(c==1)
								printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、相手に15のダメージ!!\n");
								eh = 1;
								if (psn != 1)
								{
									ph = ph - 15;
									if (dou > 0)
									{
										ph = ph - 15;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 3)
							{ //if(c==2)
								printf("相手と自分のLPを入れ替える!\n");
								ph = ph + eh;
								eh = ph - eh;
								ph = ph - eh;
							}
							if (d == 4)
							{ //if(c==3)
								printf("ゼウスを召喚した!!\nあなたに13のダメージ!!\n");
								if (psn != 1)
								{
									ph = ph - 13;
									if (dou > 0)
									{
										ph = ph - 13;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 5)
							{ //if(c==4)
								printf("ヒーリング・ノヴァ始動\n相手はLPを10回復!!\n");
								eh = eh + 10;
							}
							if (d == 6)
							{ //if(c==5)
								printf("次の相手のターン終了時まで、発生する全てのダメージは2倍になる\n");
								while (dou < 3)
								{
									dou++;
								} //while(dou<3)
							}	  //if(c==6)
						}
						if (c == 5)
						{
							printf("氷魔法、サークルフロスト発動!!\n");
							printf("あなたに3のダメージ!!次のあなたのターンをスキップする。\n");
							if (psn != 1)
							{
								ph = ph - 3;
								if (dou > 0)
								{
									ph = ph - 3;
								} //if(dou>0)
								pss = 1;
							} //if(psn!=1)
							epn++;
						}
						if (c == 6)
						{ //if(c==5)
							printf("宇宙魔法、メテオ発動!!\n");
							printf("自身のLPを1にして、あなたにに10のダメージ!!\n");
							eh = 1;
							if (psn != 1)
							{
								ph = ph - 10;
								if (dou > 0)
								{
									ph = ph - 10;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						} //if(c==6)
					}
					if (ep == 3)
					{ //if(ep==2)
						printf("相手はガードダイスを振りました\n");
						c = rand() % 6 + 1;
						if (c == 1)
						{
							printf("クリティカルヒット!!\n");
							printf("あなたに4のダメージ!!、次の相手のターンまで相手が受けるダメージは0になる。\n");
							esn = 1;
							if (psn != 1)
							{
								ph = ph - 4;
								if (dou > 0)
								{
									ph = ph - 4;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 2)
						{ //if(c==1)
							printf("守りを固めた!!\n(次の相手のターンまで相手が受けるダメージは0になる)\n");
							esn = 1;
							epn++;
						}
						if (c == 3)
						{ //if(c==2)
							epn = 0;
							printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
							d = rand() % 6 + 1;
							if (d == 1)
							{
								printf("ギガドレイン始動!!\nあなたのLPから10ポイント吸い取る!!\n");
								if (psn != 1)
								{
									eh = eh + 10;
									ph = ph - 10;
								} //if(psn!=1)
							}
							if (d == 2)
							{ //if(c==1)
								printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、あなたに15のダメージ!!\n");
								eh = 1;
								if (psn != 1)
								{
									ph = ph - 15;
									if (dou > 0)
									{
										ph = ph - 15;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 3)
							{ //if(c==2)
								printf("相手と自分のLPを入れ替える!\n");
								ph = ph + eh;
								eh = ph - eh;
								ph = ph - eh;
							}
							if (d == 4)
							{ //if(c==3)
								printf("ゼウスを召喚した!!\nあなたに13のダメージ!!\n");
								if (psn != 1)
								{
									ph = ph - 13;
									if (dou > 0)
									{
										ph = ph - 13;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 5)
							{ //if(c==4)
								printf("ヒーリング・ノヴァ始動\n相手はLPを10回復!!\n");
								eh = eh + 10;
							}
							if (d == 6)
							{ //if(c==5)
								printf("次の相手のターン終了時まで、発生する全てのダメージは2倍になる\n");
								while (dou < 3)
								{
									dou++;
								} //while(dou<3)
							}	  //if(c==6)
						}
						if (c == 4)
						{ //if(c==3)
							printf("ミス!、何も起こらなかった。\n");
							epn++;
						}
						if (c == 5)
						{ //if(c==4)
							printf("あなたに1のダメージ!\n");
							if (psn != 1)
							{
								ph = ph - 1;
								if (dou > 0)
								{
									ph = ph - 1;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 6)
						{ //if(c==5)
							printf("守りを固めた!!\n(次の相手のターンまで、相手が受けるダメージは0になる)\n");
							esn = 1;
							epn++;
						} //if(c==6)
					}
					if (ep == 4)
					{ //if(ep==3)
						printf("相手はヒーリングダイスを振りました\n");
						c = rand() % 6 + 1;
						if (c == 1)
						{
							printf("ドレイン発動!!\nあなたのLPから4ポイント吸い取る\n");
							if (psn != 1)
							{
								ph = ph - 4;
								eh = eh + 4;
							} //if(psn!=1)
							epn++;
						}
						if (c == 2)
						{ //if(c==1)
							epn = 0;
							printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
							d = rand() % 6 + 1;
							if (d == 1)
							{
								printf("ギガドレイン始動!!\nあなたのLPから10ポイント吸い取る!!\n");
								if (psn != 1)
								{
									eh = eh + 10;
									ph = ph - 10;
								} //if(psn!=1)
							}
							if (d == 2)
							{ //if(c==1)
								printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、あなたに15のダメージ!!\n");
								eh = 1;
								if (psn != 1)
								{
									ph = ph - 15;
									if (dou > 0)
									{
										ph = ph - 15;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 3)
							{ //if(c==2)
								printf("相手と自分のLPを入れ替える!\n");
								ph = ph + eh;
								eh = ph - eh;
								ph = ph - eh;
							}
							if (d == 4)
							{ //if(c==3)
								printf("ゼウスを召喚した!!\nあなたに13のダメージ!!\n");
								if (psn != 1)
								{
									ph = ph - 13;
									if (dou > 0)
									{
										ph = ph - 13;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 5)
							{ //if(c==4)
								printf("ヒーリング・ノヴァ始動\n自分のLPを10回復!!\n");
								ph = ph + 10;
							}
							if (d == 6)
							{ //if(c==5)
								printf("次の相手のターン終了時まで、発生する全てのダメージは2倍になる\n");
								while (dou < 3)
								{
									dou++;
								} //while(dou<3)
							}	  //if(c==6)
						}
						if (c == 3)
						{ //if(c==2)
							printf("あなたに2のダメージ!!\n");
							if (psn != 1)
							{
								ph = ph - 2;
								if (dou > 0)
								{
									ph = ph - 2;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 4)
						{ //if(c==3)
							printf("あいてはLPを3回復!!\n");
							eh = eh + 3;
							epn++;
						}
						if (c == 5)
						{ //if(c==4)
							printf("守りを固めた!!/n");
							printf("(次の自分のターンまで自身が受けるダメージは0となる)\n");
							esn = 1;
							epn++;
						}
						if (c == 6)
						{ //if(c==5)
							printf("ミス!,何も起こらなかった\n");
							epn++;
						} //if(c==6)
					}	  //if(ep==4)
				}
				if (eh >= 20 && etd == 1)
				{ //if(20>eh&&eh=>10&&etd==1)
					etd = 0;
					ep = rand() % 2 + 1;
					if (ep == 1)
					{
						printf("相手はクリティカルダイスを振りました。\n");
						c = rand() % 6 + 1;
						if (c == 1)
						{
							printf("クリティカルヒット!!\n");
							printf("あなたに7のダメージ!!\n");
							if (psn != 1)
							{
								ph = ph - 7;
								if (dou > 0)
								{
									ph = ph - 7;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 2)
						{ //if(c==1)
							printf("ミス!あなたに0ダメージ\n");
							epn++;
						}
						if (c == 3)
						{ //if(c==3)
							printf("クリティカルヒット!!\n");
							printf("あなたに5のダメージ!!次のあなたのターンをスキップする。\n");
							if (psn != 1)
							{
								ph = ph - 5;
								if (dou > 0)
								{
									ph = ph - 5;
								} //if(dou>0)
								pss = 1;
							} //if(psn!=1)
							epn++;
						}
						if (c == 4)
						{ //if(c==3)
							printf("あなたに2のダメージ\n");
							if (psn != 1)
							{
								ph = ph - 2;
								if (dou > 0)
								{
									ph = ph - 2;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 5)
						{ //if(c==4)
							epn = 0;
							printf("パンドラのダイス始動!!\nダイスを一回振れ!!");
							d = rand() % 6 + 1;
							if (d == 1)
							{
								printf("ギガドレイン始動!!\nあなたのLPから10ポイント吸い取る!!\n");
								if (psn != 1)
								{
									eh = eh + 10;
									ph = ph - 10;
								} //if(psn!=1)
							}
							if (d == 2)
							{ //if(c==1)
								printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、あなたに15のダメージ!!\n");
								eh = 1;
								if (psn != 1)
								{
									ph = ph - 15;
									if (dou > 0)
									{
										ph = ph - 15;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 3)
							{ //if(c==2)
								printf("相手と自分のLPを入れ替える!\n");
								ph = ph + eh;
								eh = ph - eh;
								ph = ph - eh;
							}
							if (d == 4)
							{ //if(c==3)
								printf("ゼウスを召喚した!!\nあなたに13のダメージ!!\n");
								if (psn != 1)
								{
									ph = ph - 13;
									if (dou > 0)
									{
										ph = ph - 13;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 5)
							{ //if(c==4)
								printf("ヒーリング・ノヴァ始動\n相手はLPを10回復!!\n");
								eh = eh + 10;
							}
							if (d == 6)
							{ //if(c==5)
								printf("次の相手のターン終了時まで、発生する全てのダメージは2倍になる\n");
							} //if(c==6)
						}
						if (c == 6)
						{ //if(c==5)
							printf("クリティカルヒット!!\n");
							printf("あなたに5のダメージ!!次のあなたのターンをスキップする。\n");
							if (psn != 1)
							{
								ph = ph - 5;
								if (dou > 0)
								{
									ph = ph - 5;
								} //if(dou>0)
								pss = 1;
							} //if(psn!=1)
							epn++;
						} //if(c==6)
					}
					if (ep == 2)
					{ //if(ep==1)
						printf("相手はマジックダイスを振りました。\n");
						c = rand() % 6 + 1;
						if (c == 1)
						{
							printf("炎魔法、ファイアーボール発動!!\n");
							printf("あなたに2のダメージ!!,次にダイスを振るプレイヤーに2のダメージを与える。!");
							if (psn != 1)
							{
								ph = ph - 2;
								if (dou > 0)
								{
									ph = ph - 2;
								} //if(dou>0)
							}	  //if(psn!=1)
							f = 1;
							epn++;
						}
						if (c == 2)
						{ //if(c==1)
							printf("雷魔法、サンダーボルト発動!!\n");
							printf("お互いに4のダメージ!!\n");
							eh = eh - 4;
							if (dou > 0)
							{
								eh = eh - 4;
							} //if(dou>0)
							if (psn != 1)
							{
								ph = ph - 4;
								if (dou > 0)
								{
									ph = ph - 4;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						}
						if (c == 3)
						{ //if(c==2)
							printf("ミス!、あなたに0のダメージ\n");
							epn++;
						}
						if (c == 4)
						{ //if(c==3)
							epn = 0;
							printf("パンドラのダイス始動!!\nダイスを一回振れ!!\n");
							d = rand() % 6 + 1;
							if (d == 1)
							{
								printf("ギガドレイン始動!!\nあなたのLPから10ポイント吸い取る!!\n");
								if (psn != 1)
								{
									eh = eh + 10;
									ph = ph - 10;
								} //if(psn!=1)
							}
							if (d == 2)
							{ //if(c==1)
								printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、あなたに15のダメージ!!\n");
								eh = 1;
								if (psn != 1)
								{
									ph = ph - 15;
									if (dou > 0)
									{
										ph = ph - 15;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 3)
							{ //if(c==2)
								printf("相手と自分のLPを入れ替える!\n");
								ph = ph + eh;
								eh = ph - eh;
								ph = ph - eh;
							}
							if (d == 4)
							{ //if(c==3)
								printf("ゼウスを召喚した!!\nあなたに13のダメージ!!\n");
								if (psn != 1)
								{
									ph = ph - 13;
									if (dou > 0)
									{
										ph = ph - 13;
									} //if(dou>0)
								}	  //if(psn!=1)
							}
							if (d == 5)
							{ //if(c==4)
								printf("ヒーリング・ノヴァ始動\n相手はLPを10回復!!\n");
								eh = eh + 10;
							}
							if (d == 6)
							{ //if(c==5)
								printf("次の自分のターン終了時まで、発生する全てのダメージは2倍になる\n");
								while (dou < 3)
								{
									dou++;
								} //while(dou<3)
							}	  //if(c==6)
						}
						if (c == 5)
						{
							printf("氷魔法、サークルフロスト発動!!\n");
							printf("あなたに3のダメージ!!次のあなたのターンをスキップする。\n");
							if (psn != 1)
							{
								ph = ph - 3;
								if (dou > 0)
								{
									ph = ph - 3;
								} //if(dou>0)
								pss = 1;
							} //if(psn!=1)
							epn++;
						}
						if (c == 6)
						{ //if(c==5)
							printf("宇宙魔法、メテオ発動!!\n");
							printf("自身のLPを1にして、あなたにに10のダメージ!!\n");
							eh = 1;
							if (psn != 1)
							{
								ph = ph - 10;
								if (dou > 0)
								{
									ph = ph - 10;
								} //if(dou>0)
							}	  //if(psn!=1)
							epn++;
						} //if(c==6)
					}	  //if(ep==2)
				}		  //if(eh>=20)
			}
			if (epn == 6)
			{ //if(epn!=6)
				epn = 0;
				printf("パンドラのダイス強制始動!!\nダイスを一回振れ!!");
				d = rand() % 6 + 1;
				if (d == 1)
				{
					printf("ギガドレイン始動!!\nあなたのLPから10ポイント吸い取る!!\n");
					if (psn != 1)
					{
						eh = eh + 10;
						ph = ph - 10;
					} //if(psn!=1)
				}
				if (d == 2)
				{ //if(c==1)
					printf("宇宙魔法、ブラックホール始動!!\n自分のLP1にして、あなたに15のダメージ!!\n");
					eh = 1;
					if (psn != 1)
					{
						ph = ph - 15;
						if (dou > 0)
						{
							ph = ph - 15;
						} //if(dou>0)
					}	  //if(psn!=1)
				}
				if (d == 3)
				{ //if(c==2)
					printf("相手と自分のLPを入れ替える!\n");
					ph = ph + eh;
					eh = ph - eh;
					ph = ph - eh;
				}
				if (d == 4)
				{ //if(c==3)
					printf("ゼウスを召喚した!!\nあなたに13のダメージ!!\n");
					if (psn != 1)
					{
						ph = ph - 13;
						if (dou > 0)
						{
							ph = ph - 13;
						} //if(dou>0)
					}	  //if(psn!=1)
				}
				if (d == 5)
				{ //if(c==4)
					printf("ヒーリング・ノヴァ始動\n相手はLPを10回復!!\n");
					eh = eh + 20;
				}
				if (d == 6)
				{ //if(c==5)
					printf("次の相手のターン終了時まで、発生する全てのダメージは2倍になる\n");
					while (dou < 3)
					{
						dou++;
					} //while(dou<3)
				}	  //if(c==6)
			}		  //if(epn==6)
		}
		if (ess == 1)
		{ //if(ess!=1)
			printf("\n相手はこのターン行動できなかった。\n");
			ess = 0;
		} //if(ess==1)
		printf("next\n");
		getchar();
	} //if(eh>0&&ph>0)
}
