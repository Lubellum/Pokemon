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
        int aDefensePoint // –hŒä.
    );
    virtual ~CMonster();

    int Attack();
    int Guard();
    void Damage(int aDamagePoint);

private:

    int mLevel;        // ƒŒƒxƒ‹.
    int mHitPoint;     // HP.
    int mAttackPoint;  // UŒ‚.
    int mDefensePoint; // –hŒä.
};