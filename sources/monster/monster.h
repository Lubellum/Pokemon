#ifndef MONSTER_H_INCLUDED

#define MONSTER_H_INCLUDED

#include <iostream>

// ========================================================================= //
//  【モンスター】基底クラス
// ========================================================================= //

class CMonster
{
public:

    virtual bool FaintFlag();
    virtual int Attack();
    virtual bool Guard();
    virtual void Damage(int aDamagePoint);

    // 純粋仮想関数 = 継承先で必ず定義する。 =0　をつける
    virtual ~CMonster() = 0;

protected:

    CMonster( std::string aName, int aLevel, int aHitPoint, 
              int aAttackPoint, int aDefencePoint );


private:

    CMonster();

    std::string mName; // 名前
    int mLevel;        // レベル.
    int mHitPoint;     // HP.
    int mAttackPoint;  // 攻撃.
    int mDefencePoint; // 防御.
    bool mGuardFlag;
};

#endif // !MONSTER_H_INCLUDED