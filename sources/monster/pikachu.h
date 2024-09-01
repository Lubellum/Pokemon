#ifndef PIKACHU_H_INCLUDED

#define PIKACHU_H_INCLUDED

#include "monster.h"

// ========================================================================= //
//  【モンスター】ピカチュウ
// ========================================================================= //

// 継承の際は基底クラスの定義がないとダメなので、前方宣言では中身が見えずコンパイルエラーになる
//class CMonster;
class CPikachu : public CMonster
{
public:

    CPikachu();
    virtual ~CPikachu();
};

#endif // !PIKACHU_H_INCLUDED