#ifndef MEWTWO_H_INCLUDED

#define MEWTWO_H_INCLUDED

#include "monster.h"

// =============================================================================== //
//  【モンスター】ミュウツー.
// =============================================================================== //
class CMewtwo : public CMonster
{
public:

    CMewtwo();
    virtual ~CMewtwo(); // デストラクタには virtual を付ける.

    int Attack();
    void Damage(int aDamagePoint);

private:

    int mLevel;         // レベル.
    int mHitPoint;      // HP.
    int mAttackPoint;   // 攻撃.
    int mDefensePoint;  // 防御.
};

#endif // !MEWTWO_H_INCLUDED