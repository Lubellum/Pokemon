//#include <iostream>
//
//void sample()
//{
//    std::cout << team1position << "\n";
//    std::cout << team2position << "\n";
//
//    const tAction command1 = SelectAction1();
//    const tAction command2 = SelectAction2();
//
//    Execution(team1Monster[team1position], team2Monster[team2position], command1, command2);
//
//    // 気絶していれば次のポケモンを繰り出す
//    if (IsRoundFinish(team1Monster[team1position], team2Monster[team2position]))
//    {
//        if (team1Monster[team1position]->FaintFlag())
//        {
//            team1position = SelectMonster(team1Monster);
//        }
//
//        if (team2Monster[team2position]->FaintFlag())
//        {
//            team2position = SelectMonster(team2Monster);
//        }
//    }
//}