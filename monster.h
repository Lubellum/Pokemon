#ifndef MONSTER_H_INCLUDED

#define MONSTER_H_INCLUDED

#include <iostream>

// ========================================================================= //
//  yƒ‚ƒ“ƒXƒ^[zŠî’êƒNƒ‰ƒX
// ========================================================================= //

class CMonster
{
public:

    CMonster();
    CMonster
    (
        int aLevel,       // ƒŒƒxƒ‹.
        int aHitPoint,    // HP.
        int aAttackPoint, // UŒ‚.
        int aDefencePoint // –hŒä.
    );
    virtual ~CMonster();

    int Attack();
    int Guard(int aAttackPoint);
    void Damage(int aDamagePoint);

private:

    int mLevel;        // ƒŒƒxƒ‹.
    int mHitPoint;     // HP.
    int mAttackPoint;  // UŒ‚.
    int mDefencePoint; // –hŒä.
};

#endif // !MONSTER_H_INCLUDED