#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include "Bot.h"
#include "Field.h"

class Tree{
public:
    int player = 0;
    // last made move coordinates
    int last_move_x = -1;
    int last_move_y = -1;
    // number of wins
    int w = 0;
    // number of simulations
    int n = 0;
    Tree * parent = nullptr;
    std::vector < Tree * >  Nodes;
};

class MNTS : public Player
{
private:
    Field previous_step;

    void latest_step (Field & f, int & x, int & y )
    {
        std::vector<std::vector<int>> field = f.get_field();
        std::vector<std::vector<int>> prev_field = this->previous_step.get_field();
        for (int i = 0; i < TTT_FIELDSIZE; i++)
            for (int j = 0; j < TTT_FIELDSIZE; j++)
                if ( field[i][j] != prev_field[i][j] ){
                    x = j;
                    y = i;
                }
        this->previous_step = Field(field);
    }

    Tree * tree;
    Tree * current;
    void add_node(Field& field);
    Tree * selection(Field& field);
    Tree * expanding(Field& field, Tree * bestnode);
    void simulation(Field& field, Tree * newnode);
    void backpropagation(Field& field, Tree * newnode);

public:
    MNTS (int fig): Player(fig)
    {
        this->tree = new Tree;
        this->current = this->tree;
        this->previous_step = Field();
    }

    void search(Field& field){
        cout << "MONTE-CARLO BOT MAKING MOVE..." << endl;
        add_node(field);
        Tree * bestnode = selection(field);
        Tree * newnode = expanding(field, bestnode);
        simulation(field, newnode);
        backpropagation(field, newnode);
        this->current = newnode;
        field.make_move(this->get_figure(), this->current->last_move_x, this->current->last_move_y);
    }

    void Reset (){
        this->current = this->tree;
        this->previous_step = Field();
    }
};
