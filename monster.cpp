#include "monster.h"

// ------------------------------------------------------------------------- //
//  �R���X�g���N�^.
// ------------------------------------------------------------------------- //
CMonster::CMonster()
    : mLevel(), mHitPoint(), mAttackPoint(), mDefencePoint()
{
}

CMonster::CMonster(
    int aLevel,       // ���x��.
    int aHitPoint,    // HP.
    int aAttackPoint, // �U��.
    int aDefensePoint // �h��.
)
    : mLevel(aLevel), mHitPoint(aHitPoint), mAttackPoint(aAttackPoint), mDefencePoint(aDefensePoint)
{
    std::cout << "�a��!\n";

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
//  �U��.
// ------------------------------------------------------------------------- //
int CMonster::Attack()
{
    std::cout << "" << "��" << "�U���I\n";
    std::cout << "" << "\n";
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  �U��.
// ------------------------------------------------------------------------- //
int CMonster::Guard()
{
    std::cout << "" << "��" << "�h��I\n";
    mAttackPoint = mAttackPoint / 2;
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  �_���[�W.
// ------------------------------------------------------------------------- //
void CMonster::Damage(int aDamagePoint)
{
    mHitPoint -= aDamagePoint;

    std::cout << "" << "��" << "�U�����󂯂��B\n";
    std::cout << aDamagePoint << " �_���[�W�I" << "\n";
    std::cout << "�c��HP = " << mHitPoint << "\n";
    if (mHitPoint <= 0)
    {
        std::cout << "" << "��" << "�|�ꂽ�B\n";
    }
}