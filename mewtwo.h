#ifndef MEWTWO_H_INCLUDED

#define MEWTWO_H_INCLUDED

#include "monster.h"

// =============================================================================== //
//  【モンスター】ミュウツー.
// =============================================================================== //
class CMewtwo : public CMonster
{
public:

    CMewtwo();
    virtual ~CMewtwo(); // デストラクタには virtual を付ける.
};

#endif // !MEWTWO_H_INCLUDED