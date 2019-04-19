#pragma once 

#include <iostream>
#include <vector>
using namespace std;

#define TTT_EMPTY 0
#define TTT_CROSS 1
#define TTT_CIRCLE 2
#define TTT_FIELDSIZE 3

class Field{
public:
    Field(std::vector< std::vector<int> > f): field(f){};
    Field(const Field&) = default;
    Field(){
    	std::vector<std::vector<int>> tmp(TTT_FIELDSIZE, std::vector<int>(TTT_FIELDSIZE, 0));
    	this->field = tmp;
    }
    std::vector< std::vector<int> > get_field() const;
    bool make_move(int who, int x, int y);
    int check_win() const;
    bool is_playable() const;
    bool check_pos(int x, int y) const;
    friend std::ostream& operator << (std::ostream &ostr, const Field &field);
private:
    std::vector< std::vector<int> > field;
};