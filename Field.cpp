#include <iostream>
#include <vector>
#include "Field.h"
using namespace std;
std::ostream& operator << (std::ostream &ostr, const Field &f)
{
	std::vector<std::vector<int>> field = f.get_field();
    std::string s = "";
    for (int i = 0; i < TTT_FIELDSIZE; i++){
        s+="----";
    }
	for (int i = 0; i < TTT_FIELDSIZE; i++){
        for (int j = 0; j < TTT_FIELDSIZE; j++){
            if (j != 0) 
                ostr << '|';
            if (field[i][j] == 1){
                ostr << " x ";
            } 
            if (field[i][j] == 2) {
                ostr << " o ";
            }
            if (field[i][j] == 0){
                ostr << "   ";
            }             }
        if ( i != TTT_FIELDSIZE - 1 )

            ostr << endl << s << endl;
        else
            ostr << endl;
	}
	return ostr;
}

std::vector< std::vector<int> > Field::get_field() const {
	return field;
}

bool Field::check_pos(int x, int y) const{
    if (x < 0 || x >= TTT_FIELDSIZE)
        return false;
    if (y < 0 || y >= TTT_FIELDSIZE)
        return false;
    if (field[y][x] != TTT_EMPTY)
        return false;
    return true;
}

bool Field::make_move(int who, int x, int y){
	if (check_pos(x, y)){
    	field[y][x] = who;
    	return true;
    }
    return false;
}

int Field::check_win() const{
	std::vector<std::vector<int>> f = get_field();
    for (int i = 0; i < TTT_FIELDSIZE; i++){
        if (f[0][i] == f[1][i] && f[1][i] == f[2][i] && f[1][i] != TTT_EMPTY )
            return f[1][i];
    }

    for (int i = 0; i < TTT_FIELDSIZE; i++){
        if ( f[i][0] == f[i][1] && f[i][1] == f[i][2] && f[i][1] != TTT_EMPTY )
            return f[i][1];
    }
    
    if ( f[0][0] == f[1][1] && f[1][1] == f[2][2] && f[1][1] != TTT_EMPTY )
        return f[1][1];

    if ( f[0][2] == f[1][1] && f[1][1] == f[2][0] && f[1][1] != TTT_EMPTY )
        return f[1][1];

    return 0;
}


bool Field::is_playable() const{
    if (check_win()) 
    	return false;

	std::vector<std::vector<int>> f = get_field();
    for (int i = 0; i < TTT_FIELDSIZE; i++)
        for (int j = 0; j < TTT_FIELDSIZE; j++)
            if (f[i][j] == TTT_EMPTY)
                return true;

    return false;
}
