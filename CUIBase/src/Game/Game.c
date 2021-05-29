#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#include "Game.h"

char Guard(struct CharaData *_chara)
{
    if((_chara->statusflg & guard) == 0)return 0;
    printf("%sは攻撃をガードした\n",_chara->name);
    return 1;
}

void CriticalDamage(struct CharaData* _chara, unsigned char _damage,char _skipFlg)
{
    if(Guard(_chara) == 1)return;

    printf("クリティカルヒット!!\n");
    printf("%sに%dのダメージ!!\n",_chara->name,_damage);
    if (_chara->statusflg & guard)
    {
        _chara->lp = _chara->lp - _damage;
        if (doubleFlg > 0)
        {
        _chara->lp = _chara->lp - _damage;
        } //if(dou>0)
    }//if(esn!=1)

    _chara->pandoraDiceCount++;
}

void AttackMiss(struct CharaData* _chara)
{
    printf("ミス!%sに0ダメージ\n",_chara->name);
}

void Critical1(struct CharaData *_chara)
{   
    CrotocalDamage(_chara,7,0);
}

void Critical2(struct CharaData *_chara)
{   
    AttackMiss(_chara);
}

void diceInit(void)
{
    Critical[0] = &Critical1;
}