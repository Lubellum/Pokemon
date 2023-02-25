// 継承元でもコンストラクタ・デストラクタは無いといけない

#include <iostream>

// ========================================================================= //
//  【モンスター】基底クラス
// ========================================================================= //
class CMonster
{
public:

    CMonster();
    virtual ~CMonster();

    int Attack();
    void Damage(int aDamagePoint);


private:

    int mLevel;         // レベル.
    int mHitPoint;      // HP.
    int mAttackPoint;   // 攻撃.
    int mDefensePoint;  // 防御.
};