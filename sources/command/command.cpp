#include <iostream>
#include "../scene/battle.h"

tAction InputAction()
{
    // true�ɂȂ�����(�����ɍ��v�����Ƃ�)�Ƀu���b�N�̒�����������
    while (true)
    {
        std::cout << "��������͂��Ă�������\n";
        std::string command;
        std::cin >> command;

        // �ӂ邢�ɂ����Ă�
        if (command.length() != 1)
        {
            std::cout << "���͉\�ȕ�������1�����ł�\n";
        }
        else if (isdigit(command.at(0)) == false)
        {
        }
        else
        {
            int number = std::stoi(command);
            return static_cast<tAction>(number);
        }
    }
}

// �R�}���h�������_���Ɍ���
tAction RandomAction()
{
    std::random_device seed;
    std::mt19937 mt(seed());
    return static_cast<tAction>(mt() % 2);
}

// 1P�p�̓��͊֐�
//0 -> attack, 1 -> guard
tAction SelectAction1()
{
    std::cout << "1P�̓���" << "\n";
    return InputAction();
}

// 2P�p�̓��͊֐�
tAction SelectAction2()
{
    return RandomAction();
}