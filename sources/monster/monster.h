#ifndef MONSTER_H_INCLUDED

#define MONSTER_H_INCLUDED

#include <iostream>

// ========================================================================= //
//  �y�����X�^�[�z���N���X
// ========================================================================= //

class CMonster
{
public:

    virtual bool FaintFlag();
    virtual int Attack();
    virtual bool Guard();
    virtual void Damage(int aDamagePoint);


protected:

    CMonster
    (
        std::string aName, // ���O
        int aLevel,        // ���x��.
        int aHitPoint,     // HP.
        int aAttackPoint,  // �U��.
        int aDefencePoint  // �h��.
    );
    // �������z�֐� = �p����ŕK����`����
    virtual ~CMonster() = 0;


private:

    CMonster();

    std::string mName; // ���O
    int mLevel;        // ���x��.
    int mHitPoint;     // HP.
    int mAttackPoint;  // �U��.
    int mDefencePoint; // �h��.
    bool mGuardFlag;
};

#endif // !MONSTER_H_INCLUDED