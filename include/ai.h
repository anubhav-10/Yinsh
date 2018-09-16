#ifndef AI_H
#define AI_H

#include <vector>
#include <moves.h>
#include <game.h>
#include <allvalidmoves.h>
#include <iostream>
#define pb push_back
using namespace std;

class AI{
	int id;
	int opponent_id;
	public:
		// game g;
		AI(int id);
		int removedRings1,removedRings2;
		pair<vector<moves>,game> makeDecision(game g);
		double utility(int player);
		double maxValue(game g,double alpha,double beta,int depth); 
		double minValue(game g,double alpha,double beta,int depth);
		void getAllMoves(int player,game g,vector<moves> ans,bool moveMade);
		bool isTerminal();
		void print();
};

#endif