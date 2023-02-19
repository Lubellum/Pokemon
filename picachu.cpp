﻿#include "pikachu.h"

// ------------------------------------------------------------------------- //
//  コンストラクタ.
// ------------------------------------------------------------------------- //
CPicachu::CPicachu()
    : mLevel(1), mHitPoint(35), mAttackPoint(55), mDefensePoint(40)
{
    std::cout << "ピカチュウ誕生\n";

    std::cout << mLevel << "レベル\n";
    std::cout << mHitPoint << "HP\n";
    std::cout << mAttackPoint << "攻撃\n";
    std::cout << mDefensePoint << "防御\n";
}

// ------------------------------------------------------------------------- //
//  デストラクタ.
// ------------------------------------------------------------------------- //
CPicachu::~CPicachu()
{
}

// ------------------------------------------------------------------------- //
//  攻撃.
// ------------------------------------------------------------------------- //
int CPicachu::Attack()
{
    std::cout << "ピカチュウ" << "の" << "攻撃！\n";
    std::cout << "10万ボルト！" << "\n";
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  ダメージ.
// ------------------------------------------------------------------------- //
void CPicachu::Damage(int aDamagePoint)
{
    mHitPoint -= aDamagePoint;

    std::cout << "ピカチュウ" << "は" << "攻撃を受けた。\n";
    std::cout << aDamagePoint << " ダメージ！" << "\n";
    std::cout << mHitPoint << "HP\n";
    std::cout << mHitPoint << "HP\n";
    if (mHitPoint <= 0)
    {
        std::cout << "ピカチュウ" << "は" << "倒れた。\n";
    }
}