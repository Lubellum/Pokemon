﻿#include "pikachu.h"

// ------------------------------------------------------------------------- //
//  コンストラクタ.
// ------------------------------------------------------------------------- //
CPikachu::CPikachu()
    //: mLevel(1), mHitPoint(35), mAttackPoint(55), mDefensePoint(40)
{
    std::cout << "ピカチュウ誕生\n";

    std::cout << "レベル\t= " << mLevel        << "\n";
    std::cout << "HP    \t= " << mHitPoint     << "\n";
    std::cout << "攻撃  \t= " << mAttackPoint  << "\n";
    std::cout << "防御  \t= " << mDefensePoint << "\n";
}

// ------------------------------------------------------------------------- //
//  デストラクタ.
// ------------------------------------------------------------------------- //
CPikachu::~CPikachu()
{
}

//// ------------------------------------------------------------------------- //
////  攻撃.
//// ------------------------------------------------------------------------- //
////int CMonster::Attack()
//int CPikachu::Attack()
//{
//    std::cout << "ピカチュウ" << "の" << "攻撃！\n";
//    std::cout << "10万ボルト！" << "\n";
//    return mAttackPoint;
//}
//
//// ------------------------------------------------------------------------- //
////  ダメージ.
//// ------------------------------------------------------------------------- //
//void CMonster::Damage(int aDamagePoint)
//{
//    mHitPoint -= aDamagePoint;
//
//    std::cout << "ピカチュウ" << "は" << "攻撃を受けた。\n";
//    std::cout << aDamagePoint << " ダメージ！" << "\n";
//    std::cout << "残りHP = " << mHitPoint << "\n";
//    if (mHitPoint <= 0)
//    {
//        std::cout << "ピカチュウ" << "は" << "倒れた。\n";
//    }
//}