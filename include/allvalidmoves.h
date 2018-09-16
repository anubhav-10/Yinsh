#ifndef ALLVALIDMOVES_H
#define ALLVALIDMOVES_H

#include <vector>
#include <moves.h>
#include <game.h>
#include <iostream>
#define pb push_back
using namespace std;

class allvalidmoves {
	public:
		vector<vector<moves>> allMoves;
		void getAllMoves(int player,game g,vector<moves> ans,bool moveMade);
		void print();
};

#endif