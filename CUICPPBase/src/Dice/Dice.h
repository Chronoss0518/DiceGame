#ifndef _Dice
#define _Dice

#include<string>

class Charactor;
class FutureObject;

using DiceFunctions = void(*)(void);

class Dice
{
public:

    void SetCharactor(Charactor* _charas){thisHave = _charas;}

private:

    void NormalAttack(Charactor *_target, int _damage);                                         //通常攻撃//
    void StanAttack(Charactor *_target, int _damage);                                           //スタン攻撃//
    void IceAttack(Charactor *_target, int _damage);                                            //アイス攻撃//
    void BothPlayerAttack(Charactor *_target, int _damage);                                     //両プレイヤーに攻撃//
    void AbsorptionAttack(Charactor *_target, int _damage);                                     //吸収攻撃//
    void SacrificeAttack(Charactor *_target, int _targetDamage, int _thisHP);                   //自身のHPを指定数にして攻撃//
    void FutureAttack(Charactor *_target, FutureObject *_obj, int _damage);                     //一部攻撃を未来へ飛ばす攻撃//
    void DoubleTest(Charactor *_target, int _damage);                                           //倍ダメージテスト//
    void HealingPoint(Charactor *_target, int _healingPoint);                                   //回復//
    void ChangeHP(Charactor *_target);                                                          //HPを入れ替える//
    void SetGuard(Charactor *_target);                                                          //ガードさせる//

    Charactor* thisHave = nullptr;
    std::string name;
};

#endif