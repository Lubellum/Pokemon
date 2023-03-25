#ifndef MONSTER_H_INCLUDED

#define MONSTER_H_INCLUDED

#include <iostream>
#include <string>

// ========================================================================= //
//  【モンスター】基底クラス
// ========================================================================= //

class CMonster
{
public:

    CMonster();
    CMonster
    (
        std::string aName, // 名前
        int aLevel,        // レベル.
        int aHitPoint,     // HP.
        int aAttackPoint,  // 攻撃.
        int aDefencePoint  // 防御.
    );
    virtual ~CMonster();

    int Attack();
    bool Guard();
    void Damage(int aDamagePoint);

private:

    std::string mName; // 名前
    int mLevel;        // レベル.
    int mHitPoint;     // HP.
    int mAttackPoint;  // 攻撃.
    int mDefencePoint; // 防御.
    bool mGuardFlag;
};

#endif // !MONSTER_H_INCLUDED