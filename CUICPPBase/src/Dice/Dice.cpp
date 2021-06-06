
#include<ChBaseLibrary.h>

#include"../FutureObject/FutureObject.h"
#include"../Charactor/Charactor.h"
#include"Dice.h"


//通常攻撃//
void Dice::NormalAttack(Charactor *_target, int _damage)
{
	if (_target->IsGuard())
		return;

	printf(_damage <= 4 ? "%sに%dのダメージ\n" : "%sに%dのダメージ!!\n", _target->name, _damage);
	_target->hp -= _damage;
	DoubleTest(_target, _damage);
}

//スタン攻撃//
void Dice::StanAttack(Charactor*_target, int _damage)
{
	if (_target->IsGuard())
		return;

	NormalAttack(_target, _damage);
	_target->stan = 1;
	printf("次の%sのターンをスキップする。\n", _target->name);
}

//アイス攻撃//
void Dice::IceAttack(Charactor*_target, int _damage)
{

	if (_target->IsGuard())
		return;

	NormalAttack(_target, _damage);
	_target->ice = 1;
	printf("次の%sのターンをスキップする。\n", _target->name);
}

//両プレイヤーに攻撃//
void Dice::BothPlayerAttack(Charactor*_target, int _damage)
{
	printf("%sと%sにダメージを与える\n", thisHave->name.c_str(), _target->name.c_str());

	NormalAttack(thisHave, _damage);

	NormalAttack(_target, _damage);
}

//吸収攻撃//
void Dice::AbsorptionAttack(Charactor*_target, int _damage)
{
	if (GuardTest(_target) == Guard_True)
		return;

	printf((_damage <= 4 ? "%sのLPから%dポイント吸い取る\n" : "%sのLPから%dポイント吸い取る!!\n"), _target->name, _damage);
	_this->hp += _damage;
	_target->hp -= _damage;
}

//自身のHPを指定数にして攻撃//
void Dice::SacrificeAttack(Charactor*_target, int _targetDamage, int _thisHP)
{
	printf("%sのLPを%dにして攻撃", _this->name, _thisHP);

	_this->hp = _thisHP;

	if (GuardTest(_target) == Guard_True)
		return;

	NormalAttack(_target, _targetDamage);
}

//一部攻撃を未来へ飛ばす攻撃//
void Dice::FutureAttack(Charactor*_target, FAObject *_obj, int _damage)
{
	if (GuardTest(_target) == Guard_False)
	{
		NormalAttack(_target, _damage);
	}

	printf("次にダイスを振るプレイヤーに%dのダメージ\n", _obj->damage);
	_obj->flg = 1;
}

//倍ダメージテスト//
void Dice::DoubleTest(Charactor*_target, int _damage)
{
	if (dou <= 0)
		return;

	_target->hp -= _damage;
}

//回復//
void Dice::HealingPoint(Charactor*_target, int _healingPoint)
{
	printf((_healingPoint <= 4 ? "%sのLPを%d回復\n" : "%sのLPを%d回復!!\n"), _target->name, _healingPoint);
	_target->hp += _healingPoint;
}

//HPを入れ替える//
void Dice::ChangeHP(Charactor*_target, Charactor*_this)
{
	printf("%sと%sのLPを入れ替える!\n", _target->name, _this->name);
	_this->hp += _target->hp;
	_target->hp = _this->hp - _target->hp;
	_this->hp -= _target->hp;
}

//ガードさせる//
void Dice::SetGuard(Charactor*_target)
{
	printf("%sは守りを固めた!!\n"
		   "(次の%sのターンまで%sが受けるダメージは0となる)\n",
		   _target->name, _target->name, _target->name);
	_target->nodamage = 1;
}
