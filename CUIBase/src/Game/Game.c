#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#include "Game.h"

char Guard(struct CharaData *_chara)
{
    if((_chara->statusflg & guard) == 0)return 0;
    printf("%s�͍U�����K�[�h����\n",_chara->name);
    return 1;
}

void CriticalDamage(struct CharaData* _chara, unsigned char _damage,char _skipFlg)
{
    if(Guard(_chara) == 1)return;

    printf("�N���e�B�J���q�b�g!!\n");
    printf("%s��%d�̃_���[�W!!\n",_chara->name,_damage);
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
    printf("�~�X!%s��0�_���[�W\n",_chara->name);
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