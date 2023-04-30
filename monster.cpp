#include "monster.h"

// ------------------------------------------------------------------------- //
//  コンストラクタ.
// ------------------------------------------------------------------------- //
CMonster::CMonster()
    : mName(), mLevel(), mHitPoint(), mAttackPoint(), mDefencePoint(), mGuardFlag()
{
}

CMonster::CMonster(
    std::string aName, // 名前.
    int aLevel,        // レベル.
    int aHitPoint,     // HP.
    int aAttackPoint,  // 攻撃.
    int aDefensePoint  // 防御.
)
    : mName(aName), mLevel(aLevel), mHitPoint(aHitPoint), mAttackPoint(aAttackPoint), mDefencePoint(aDefensePoint), mGuardFlag()
{
    std::cout << mName << "誕生!\n";

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
//  生存状態.
// ------------------------------------------------------------------------- //
bool CMonster::faint_flag()
{
    if (mHitPoint <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ------------------------------------------------------------------------- //
//  攻撃.
// ------------------------------------------------------------------------- //
int CMonster::Attack()
{
    std::cout << mName << "の" << "攻撃！\n";
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  防御.
// ------------------------------------------------------------------------- //
bool CMonster::Guard()
{
    std::cout << mName << "の" << "防御！\n";
    mGuardFlag = true;
    return mGuardFlag;
}

// ------------------------------------------------------------------------- //
//  ダメージ.
// ------------------------------------------------------------------------- //
void CMonster::Damage(int aDamagePoint)
{
    std::cout << mName << "は" << "攻撃を受けた。\n";
    if (mGuardFlag)
    {
        aDamagePoint -= aDamagePoint / 2;
    }
    std::cout << aDamagePoint << " ダメージ！" << "\n";
    mHitPoint -= aDamagePoint;
    std::cout << "残りHP = " << mHitPoint << "\n\n\n";
    if (mHitPoint <= 0)
    {
        std::cout << mName << "は" << "倒れた。\n";
    }
}