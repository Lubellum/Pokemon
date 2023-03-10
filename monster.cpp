#include "monster.h"

// ------------------------------------------------------------------------- //
//  コンストラクタ.
// ------------------------------------------------------------------------- //
CMonster::CMonster()
    : mLevel(), mHitPoint(), mAttackPoint(), mDefencePoint()
{
}

CMonster::CMonster(
    int aLevel,       // レベル.
    int aHitPoint,    // HP.
    int aAttackPoint, // 攻撃.
    int aDefensePoint // 防御.
)
    : mLevel(aLevel), mHitPoint(aHitPoint), mAttackPoint(aAttackPoint), mDefencePoint(aDefensePoint)
{
    std::cout << "誕生!\n";

    std::cout << "レベル\t= " << mLevel        << "\n";
    std::cout << "HP    \t= " << mHitPoint     << "\n";
    std::cout << "攻撃  \t= " << mAttackPoint  << "\n";
    std::cout << "防御  \t= " << mDefencePoint << "\n";
}

// ------------------------------------------------------------------------- //
//  デストラクタ.
// ------------------------------------------------------------------------- //
CMonster::~CMonster()
{
}

// ------------------------------------------------------------------------- //
//  攻撃.
// ------------------------------------------------------------------------- //
int CMonster::Attack()
{
    std::cout << "" << "の" << "攻撃！\n";
    std::cout << "" << "\n";
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  攻撃.
// ------------------------------------------------------------------------- //
int CMonster::Guard()
{
    std::cout << "" << "の" << "防御！\n";
    mAttackPoint = mAttackPoint / 2;
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  ダメージ.
// ------------------------------------------------------------------------- //
void CMonster::Damage(int aDamagePoint)
{
    mHitPoint -= aDamagePoint;

    std::cout << "" << "は" << "攻撃を受けた。\n";
    std::cout << aDamagePoint << " ダメージ！" << "\n";
    std::cout << "残りHP = " << mHitPoint << "\n";
    if (mHitPoint <= 0)
    {
        std::cout << "" << "は" << "倒れた。\n";
    }
}