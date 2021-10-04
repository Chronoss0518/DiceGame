
#include"DiceEffectBase.h"

//�ʏ�U��//
void DiceEffectBase::NormalAttack(Charactor* _target, int _damage)
{
	if (_target->IsGuard())
		return;

	printf(_damage <= 4 ? "%s��%d�̃_���[�W\n" : "%s��%d�̃_���[�W!!\n", _target->GetName(), _damage);
	_target->hp -= _damage;
	DoubleTest(_target, _damage);
}

//�X�^���U��//
void DiceEffectBase::StanAttack(Charactor* _target, int _damage)
{
	if (_target->IsGuard())
		return;

	NormalAttack(_target, _damage);
	_target->stan = 1;
	printf("����%s�̃^�[�����X�L�b�v����B\n", _target->name);
}

//�A�C�X�U��//
void DiceEffectBase::IceAttack(Charactor* _target, int _damage)
{

	if (_target->IsGuard())
		return;

	NormalAttack(_target, _damage);
	_target->ice = 1;
	printf("����%s�̃^�[�����X�L�b�v����B\n", _target->name);
}

//���v���C���[�ɍU��//
void DiceEffectBase::BothPlayerAttack(Charactor* _target, int _damage)
{
	printf("%s��%s�Ƀ_���[�W��^����\n", thisHave->name.c_str(), _target->name.c_str());

	NormalAttack(thisHave, _damage);

	NormalAttack(_target, _damage);
}

//�z���U��//
void DiceEffectBase::AbsorptionAttack(Charactor* _target, int _damage)
{
	if (GuardTest(_target) == Guard_True)
		return;

	printf((_damage <= 4 ? "%s��LP����%d�|�C���g�z�����\n" : "%s��LP����%d�|�C���g�z�����!!\n"), _target->name, _damage);
	_this->hp += _damage;
	_target->hp -= _damage;
}

//���g��HP���w�萔�ɂ��čU��//
void DiceEffectBase::SacrificeAttack(Charactor* _target, int _targetDamage, int _thisHP)
{
	printf("%s��LP��%d�ɂ��čU��", _this->name, _thisHP);

	_this->hp = _thisHP;

	if (GuardTest(_target) == Guard_True)
		return;

	NormalAttack(_target, _targetDamage);
}

//�ꕔ�U���𖢗��֔�΂��U��//
void DiceEffectBase::FutureAttack(Charactor* _target, FAObject* _obj, int _damage)
{
	if (GuardTest(_target) == Guard_False)
	{
		NormalAttack(_target, _damage);
	}

	printf("���Ƀ_�C�X��U��v���C���[��%d�̃_���[�W\n", _obj->damage);
	_obj->flg = 1;
}

//�{�_���[�W�e�X�g//
void DiceEffectBase::DoubleTest(Charactor* _target, int _damage)
{
	if (dou <= 0)
		return;

	_target->hp -= _damage;
}

//��//
void DiceEffectBase::HealingPoint(Charactor* _target, int _healingPoint)
{
	printf((_healingPoint <= 4 ? "%s��LP��%d��\n" : "%s��LP��%d��!!\n"), _target->name, _healingPoint);
	_target->hp += _healingPoint;
}

//HP�����ւ���//
void DiceEffectBase::ChangeHP(Charactor* _target, Charactor* _this)
{
	printf("%s��%s��LP�����ւ���!\n", _target->name, _this->name);
	_this->hp += _target->hp;
	_target->hp = _this->hp - _target->hp;
	_this->hp -= _target->hp;
}

//�K�[�h������//
void DiceEffectBase::SetGuard(Charactor* _target)
{
	printf("%s�͎����ł߂�!!\n"
		"(����%s�̃^�[���܂�%s���󂯂�_���[�W��0�ƂȂ�)\n",
		_target->name, _target->name, _target->name);
	_target->nodamage = 1;
}
