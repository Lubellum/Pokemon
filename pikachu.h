#include <iostream>

// ========================================================================= //
//  【モンスター】ピカチュウ
// ========================================================================= //
class CPicachu
{
public:

    CPicachu();
    virtual ~CPicachu();

    int Attack();
    void Damage(int aDamagePoint);


private:

    int mLevel;         // レベル.
    int mHitPoint;      // HP.
    int mAttackPoint;   // 攻撃.
    int mDefensePoint;  // 防御.
};