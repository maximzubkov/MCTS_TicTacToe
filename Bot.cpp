#include "Bot.h"
#include <vector>

void User::make_move (Field & f){
    std::cout << "YOUR TURN (x y): ";

    int x = -1, y = -1;
    int bad_input_flag = 0;
    while (true){
        std::cin >> x >> y;
        if (f.make_move(this->get_figure(), x, y )){
            break;
        } else {
            std::cout << "INVALID INPUT!!";
        }
    }
}

// TODO расширить поле
bool Bot::interrupt_enemy (Field &f) 
{
    int enemy = (this->get_figure() == TTT_CIRCLE) ? TTT_CROSS : TTT_CIRCLE;

    std::vector<std::vector<int>> field = f.get_field();
    // horizontal


    if (field[1][1] == TTT_EMPTY){
        f.make_move(this->get_figure(), 1, 1);
        return true;
    }

    for ( int i = 0; i < TTT_FIELDSIZE; i++ ){
        if ( field[i][0] == this->get_figure() && field[i][1] == this->get_figure() && field[i][2] == TTT_EMPTY){
            f.make_move(this->get_figure(), 2, i);
            return true;
        }
        if ( field[i][0] == this->get_figure() && field[i][2] == this->get_figure() && field[i][1] == TTT_EMPTY){
            f.make_move(this->get_figure(), 1, i);
            return true;
        }
        if ( field[i][1] == this->get_figure() && field[i][2] == this->get_figure() && field[i][0] == TTT_EMPTY){
            f.make_move(this->get_figure(), 0, i);
            return true;
        }
    }

    for ( int i = 0; i < TTT_FIELDSIZE; i++ ){
        if (field[0][i] == this->get_figure() && field[1][i] == this->get_figure() && field[2][i] == TTT_EMPTY){
            f.make_move(this->get_figure(), i, 2);
            return true;
        }
        if (field[0][i] == this->get_figure() && field[2][i] == this->get_figure() && field[1][i] == TTT_EMPTY){
            f.make_move(this->get_figure(), i, 1);
            return true;
        }
        if (field[1][i] == this->get_figure() && field[2][i] == this->get_figure() && field[0][i] == TTT_EMPTY){
            f.make_move(this->get_figure(), i, 0);
            return true;
        }
    }

    for ( int i = 0; i < TTT_FIELDSIZE; i++ ){
        if ( field[i][0] == enemy && field[i][1] == enemy && field[i][2] == TTT_EMPTY){
            f.make_move(this->get_figure(), 2, i);
            return true;
        }
        if ( field[i][0] == enemy && field[i][2] == enemy && field[i][1] == TTT_EMPTY){
            f.make_move(this->get_figure(), 1, i);
            return true;
        }
        if ( field[i][1] == enemy && field[i][2] == enemy && field[i][0] == TTT_EMPTY){
            f.make_move(this->get_figure(), 0, i);
            return true;
        }
    }


    if (field[0][0] == this->get_figure() && field[1][1] == this->get_figure() && field[2][2] == TTT_EMPTY){
        f.make_move(this->get_figure(), 2, 2);
        return true;
    }
    if (field[0][0] == this->get_figure() && field[2][2] == this->get_figure() && field[1][1] == TTT_EMPTY)
    {
        f.make_move(this->get_figure(), 1, 1);
        return true;
    }
    if (field[1][1] == this->get_figure() && field[2][2] == this->get_figure() && field[0][0] == TTT_EMPTY)
    {
        f.make_move(this->get_figure(), 0, 0);
        return true;
    }

    if (field[2][0] == this->get_figure() && field[1][1] == this->get_figure() && field[0][2] == TTT_EMPTY)
    {
        std::cout << "   dewr";
        f.make_move(this->get_figure(), 2, 0);
        return true;
    }
    if (field[0][2] == this->get_figure() && field[2][0] == this->get_figure() && field[1][1] == TTT_EMPTY)
    {
        f.make_move(this->get_figure(), 1, 1);
        return true;
    }
    if (field[1][1] == this->get_figure() && field[0][2] == this->get_figure() && field[2][0] == TTT_EMPTY)
    {
        f.make_move(this->get_figure(), 0, 2);
        return true;
    }

    // vertical
    for ( int i = 0; i < TTT_FIELDSIZE; i++ ){
        if (field[0][i] == enemy && field[1][i] == enemy && field[2][i] == TTT_EMPTY){
            f.make_move(this->get_figure(), i, 2);
            return true;
        }
        if (field[0][i] == enemy && field[2][i] == enemy && field[1][i] == TTT_EMPTY){
            f.make_move(this->get_figure(), i, 1);
            return true;
        }
        if (field[1][i] == enemy && field[2][i] == enemy && field[0][i] == TTT_EMPTY){
            f.make_move(this->get_figure(), i, 0);
            return true;
        }
    }

    if (field[0][0] == enemy && field[1][1] == enemy && field[2][2] == TTT_EMPTY){
        f.make_move(this->get_figure(), 2, 2);
        return true;
    }
    if (field[0][0] == enemy && field[2][2] == enemy && field[1][1] == TTT_EMPTY)
    {
        f.make_move(this->get_figure(), 1, 1);
        return true;
    }
    if (field[1][1] == enemy && field[2][2] == enemy && field[0][0] == TTT_EMPTY)
    {
        f.make_move(this->get_figure(), 0, 0);
        return true;
    }

    if (field[2][0] == enemy && field[1][1] == enemy && field[0][2] == TTT_EMPTY)
    {
        std::cout << "   dewr";
        f.make_move(this->get_figure(), 2, 0);
        return true;
    }
    if (field[0][2] == enemy && field[2][0] == enemy && field[1][1] == TTT_EMPTY)
    {
        f.make_move(this->get_figure(), 1, 1);
        return true;
    }
    if (field[1][1] == enemy && field[0][2] == enemy && field[2][0] == TTT_EMPTY)
    {
        f.make_move(this->get_figure(), 0, 2);
        return true;
    }


    return false;
}

void Bot::random_move (Field &f)
{
    int x = -1, y = -1;
    while (!f.make_move (this->get_figure(), x, y)){
        // std::cout << "rand";
        x = rand () % 3;
        y = rand () % 3;
    }
}

void Bot::make_move (Field & f)
{
    cout << "BOT MAKING A MOVE..." << endl;
    
    if (!this->interrupt_enemy(f))
        this->random_move(f);
}
