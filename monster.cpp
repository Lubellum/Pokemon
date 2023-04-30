#include "monster.h"

// ------------------------------------------------------------------------- //
//  �R���X�g���N�^.
// ------------------------------------------------------------------------- //
CMonster::CMonster()
    : mName(), mLevel(), mHitPoint(), mAttackPoint(), mDefencePoint(), mGuardFlag()
{
}

CMonster::CMonster(
    std::string aName, // ���O.
    int aLevel,        // ���x��.
    int aHitPoint,     // HP.
    int aAttackPoint,  // �U��.
    int aDefensePoint  // �h��.
)
    : mName(aName), mLevel(aLevel), mHitPoint(aHitPoint), mAttackPoint(aAttackPoint), mDefencePoint(aDefensePoint), mGuardFlag()
{
    std::cout << mName << "�a��!\n";

    std::cout << "���x��\t= " << mLevel        << "\n";
    std::cout << "HP    \t= " << mHitPoint     << "\n";
    std::cout << "�U��  \t= " << mAttackPoint  << "\n";
    std::cout << "�h��  \t= " << mDefencePoint << "\n";
}

// ------------------------------------------------------------------------- //
//  �f�X�g���N�^.
// ------------------------------------------------------------------------- //
CMonster::~CMonster()
{
}

// ------------------------------------------------------------------------- //
//  �������.
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
//  �U��.
// ------------------------------------------------------------------------- //
int CMonster::Attack()
{
    std::cout << mName << "��" << "�U���I\n";
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  �h��.
// ------------------------------------------------------------------------- //
bool CMonster::Guard()
{
    std::cout << mName << "��" << "�h��I\n";
    mGuardFlag = true;
    return mGuardFlag;
}

// ------------------------------------------------------------------------- //
//  �_���[�W.
// ------------------------------------------------------------------------- //
void CMonster::Damage(int aDamagePoint)
{
    std::cout << mName << "��" << "�U�����󂯂��B\n";
    if (mGuardFlag)
    {
        aDamagePoint -= aDamagePoint / 2;
    }
    std::cout << aDamagePoint << " �_���[�W�I" << "\n";
    mHitPoint -= aDamagePoint;
    std::cout << "�c��HP = " << mHitPoint << "\n\n\n";
    if (mHitPoint <= 0)
    {
        std::cout << mName << "��" << "�|�ꂽ�B\n";
    }
}