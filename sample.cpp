/*
#include <iostream>

// ========================================================================= //
//  �y�����X�^�[�z�s�J�`���E.
// ========================================================================= //
class CPicachu
{
public:

    CPicachu();
    virtual ~CPicachu(); // �f�X�g���N�^�ɂ� virtual ��t����.

    int Attack();
    void Damage(int aDamagePoint);


private:

    int mLevel;         // ���x��.
    int mHitPoint;      // HP.
    int mAttackPoint;   // �U��.
    int mDefensePoint;  // �h��.
};

// ------------------------------------------------------------------------- //
//  �R���X�g���N�^.
// ------------------------------------------------------------------------- //
CPicachu::CPicachu()
    : mLevel(1), mHitPoint(35), mAttackPoint(55), mDefensePoint(40)
{
    std::cout << "�s�J�`���E�a��\n";

    std::cout << mLevel << "���x��\n";
    std::cout << mHitPoint << "HP\n";
    std::cout << mAttackPoint << "�U��\n";
    std::cout << mDefensePoint << "�h��\n";
}

// ------------------------------------------------------------------------- //
//  �f�X�g���N�^.
// ------------------------------------------------------------------------- //
CPicachu::~CPicachu()
{
}

// ------------------------------------------------------------------------- //
//  �U��.
// ------------------------------------------------------------------------- //
int CPicachu::Attack()
{
    std::cout << "10���{���g�I\n";
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  �_���[�W.
// ------------------------------------------------------------------------- //
void CPicachu::Damage(int aDamagePoint)
{
    mHitPoint -= aDamagePoint;
    std::cout << "�s�J�`���E�̓_���[�W���󂯂��I\n";
    std::cout << mHitPoint << "HP\n";
}

// ========================================================================= //
//  �y�����X�^�[�z�~���E�c�[.
// ========================================================================= //
class CMewtwo
{
public:

    CMewtwo();
    virtual ~CMewtwo(); // �f�X�g���N�^�ɂ� virtual ��t����.

    int Attack();
    void Damage(int aDamagePoint);

private:

    int mLevel;         // ���x��.
    int mHitPoint;      // HP.
    int mAttackPoint;   // �U��.
    int mDefensePoint;  // �h��.
};

static int a;

// ------------------------------------------------------------------------- //
//  �R���X�g���N�^.
// ------------------------------------------------------------------------- //
CMewtwo::CMewtwo()
    : mLevel(1), mHitPoint(65), mAttackPoint(105), mDefensePoint(40)
{
    std::cout << "�~���E�c�[�a��\n";

    std::cout << mLevel << "���x��\n";
    std::cout << mHitPoint << "HP\n";
    std::cout << mAttackPoint << "�U��\n";
    std::cout << mDefensePoint << "�h��\n";
}

// ------------------------------------------------------------------------- //
//  �f�X�g���N�^.
// ------------------------------------------------------------------------- //
CMewtwo::~CMewtwo()
{
}

// ------------------------------------------------------------------------- //
//  �U��.
// ------------------------------------------------------------------------- //
int CMewtwo::Attack()
{
    std::cout << "�T�C�R�L�l�V�X�I\n";
    return mAttackPoint;
}

// ------------------------------------------------------------------------- //
//  �_���[�W.
// ------------------------------------------------------------------------- //
void CMewtwo::Damage(int aDamagePoint)
{
    mHitPoint -= aDamagePoint;
    std::cout << "�~���E�c�[�̓_���[�W���󂯂��I\n";
    std::cout << mHitPoint << "HP\n";
}

// ------------------------------------------------------------------------- //
//  ���C��.
// ------------------------------------------------------------------------- //
int main()
{
    CPicachu picachu;
    CMewtwo mewtwo;

    int picachuDamagePoint = picachu.Attack();
    mewtwo.Damage(picachuDamagePoint);

    int mewtwoDamagePoint = mewtwo.Attack();
    picachu.Damage(mewtwoDamagePoint);
}
*/