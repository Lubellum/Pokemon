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

    // �������z�֐� = �p����ŕK����`����B =0�@������
    virtual ~CMonster() = 0;

protected:

    CMonster( std::string aName, int aLevel, int aHitPoint, 
              int aAttackPoint, int aDefencePoint );


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