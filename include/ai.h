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
		game g;
		AI(int id);
		int removedRings1,removedRings2;
		vector<moves> makeDecision();
		double utility(int player);
		double maxValue(double alpha,double beta); 
		double minValue(double alpha,double beta);
		void getAllMoves(int player,game g,vector<moves> ans,bool moveMade);
		bool isTerminal();
		void print();
};

#endif