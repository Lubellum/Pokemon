#include <iostream>

// ========================================================================= //
//  �y�����X�^�[�z�s�J�`���E
// ========================================================================= //
class CPicachu
{
public:

    CPicachu();
    virtual ~CPicachu();

    int Attack();
    void Damage(int aDamagePoint);


private:

    int mLevel;         // ���x��.
    int mHitPoint;      // HP.
    int mAttackPoint;   // �U��.
    int mDefensePoint;  // �h��.
};