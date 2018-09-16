#ifndef AI_H
#define AI_H

#include <vector>
#include <moves.h>
#include <game.h>
#include <iostream>
#define pb push_back
using namespace std;

class AI{
	int id;
	vector<vector<moves>> allMoves;
	public:
		// game g;
		AI();
		int removedRings1,removedRings2;
		moves makeDecision();
		double utility(int player);
		double maxValue(int player,double alpha,double beta); 
		double minValue(int player,double alpha,double beta);
		void getAllMoves(game g,vector<moves> ans,bool moveMade);
		bool isTerminal();
		void print();
};

#endif