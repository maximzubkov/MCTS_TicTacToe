#include <iostream>
using namespace std;
#include "Field.h"
#include "Bot.h"
#include "MNTS.h"



int main ()
{
    int size;
    std::cout << "Enter the field size";
    std::cin >> size;
    std::vector<std::vector<int>> v(size, std::vector<int>(size, 0));
    for (const auto& lines: v){
        for (const auto& elem: lines){
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
    Field field(v, size);
    std::cout<<field;
    // f.make_move(1, 1, 1);
    // std::cout<<f;
    // User u(2);
    // u.make_move(f);
    // std::cout << f;
    // Bot b(1);
    // b.make_move(f);
    // std::cout << f;
    // TTTGame::Field field;
    // TTTGame::Init (field);

    // Player * player1 = new Bot ();
    // player1->SetFigure ( TTT_CROSS );
    // Player * player2 = new MonteCarloBot ();
    // player2->SetFigure ( TTT_CIRCLE );

    // Player * current = player1;

    // cout << "Monte-Carlo bot setting up..." << endl;
    // for (int i = 0; i < 10; i++ )
    // {
    //     while ( TTTGame::IsPlayable ( field ) )
    //     {
    //         current->MakeMove ( field );

    //         if ( current == player1 )
    //             current = player2;
    //         else
    //             current = player1;
    //     }

    //     player1->Reset ();
    //     player2->Reset ();
    //     TTTGame::Init ( field );
    // }

    // system ( "cls" );
    User player1 = User(TTT_CROSS);
    MNTS player2 = MNTS(TTT_CIRCLE, size);
    int current = 1;
    while (field.is_playable())
    {
        std::cout << field;
        std::cout << current;
        if(current == 1){
            cout << "Player " << player1.get_figure() << " turn: ";
            player1.make_move(field);
        } 
        if (current == 2) {
            cout << "Player " << player2.get_figure() << " turn: ";
            player2.search(field);
        }
        if (current == 1){
            current = 2;
        } else {
            current = 1;
        }
    }

    std::cout << field;
    cout << "Winner is Player " << field.check_win() << endl;
    return 0;
}