#include <iostream>
#include "../scene/battle.h"

tAction InputAction()
{
    // trueになった時(条件に合致したとき)にブロックの中を処理する
    while (true)
    {
        std::cout << "数字を入力してください\n";
        std::string command;
        std::cin >> command;

        // ふるいにかけてる
        if (command.length() != 1)
        {
            std::cout << "入力可能な文字数は1文字です\n";
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

// コマンドをランダムに決定
tAction RandomAction()
{
    std::random_device seed;
    std::mt19937 mt(seed());
    return static_cast<tAction>(mt() % 2);
}

// 1P用の入力関数
//0 -> attack, 1 -> guard
tAction SelectAction1()
{
    std::cout << "1Pの入力" << "\n";
    return InputAction();
}

// 2P用の入力関数
tAction SelectAction2()
{
    return RandomAction();
}