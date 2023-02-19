﻿#include "mewtwo.h"

// ------------------------------------------------------------------------- //
//  コンストラクタ.
// ------------------------------------------------------------------------- //
CMewtwo::CMewtwo()
    : mLevel(1), mHitPoint(65), mAttackPoint(105), mDefensePoint(40)
{
    std::cout << "ミュウツー誕生\n";

    std::cout << mLevel << "レベル\n";
    std::cout << mHitPoint << "HP\n";
    std::cout << mAttackPoint << "攻撃\n";
    std::cout << mDefensePoint << "防御\n";
}

// ------------------------------------------------------------------------- //
//  デストラクタ.
// ------------------------------------------------------------------------- //
CMewtwo::~CMewtwo()
{
}

// ------------------------------------------------------------------------- //
//  攻撃.
// ------------------------------------------------------------------------- //
int CMewtwo::Attack()
{
    std::cout << "ミュウツー" << "の" << "攻撃！\n";
    std::cout << "サイコキネシス！" << "\n";
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  ダメージ.
// ------------------------------------------------------------------------- //
void CMewtwo::Damage(int aDamagePoint)
{
    mHitPoint -= aDamagePoint;

    std::cout << "ミュウツー" << "は" << "攻撃を受けた。\n";
    std::cout << aDamagePoint << " ダメージ！" << "\n";
    std::cout << mHitPoint << "HP\n";
    if (mHitPoint <= 0)
    {
        std::cout << "ミュウツー" << "は" << "倒れた\n";
    }
}