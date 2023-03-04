#include <iostream>

// ========================================================================= //
//  �y�����X�^�[�z���N���X
// ========================================================================= //
class CMonster
{
public:

    CMonster();
    CMonster
    (
        int aLevel,       // ���x��.
        int aHitPoint,    // HP.
        int aAttackPoint, // �U��.
        int aDefensePoint // �h��.
    );
    virtual ~CMonster();

    int Attack();
    int Guard();
    void Damage(int aDamagePoint);

private:

    int mLevel;        // ���x��.
    int mHitPoint;     // HP.
    int mAttackPoint;  // �U��.
    int mDefensePoint; // �h��.
};