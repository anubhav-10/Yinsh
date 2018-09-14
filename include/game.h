#ifndef GAME_H
#define GAME_H

#include <vector>
#include <moves.h>
#include <iostream>
#define pb push_back
using namespace std;
class game{
	vector<vector<int>> state;
	vector<pair<int,int>> white,black;
	public:
		game();
		void placeMarker(int x,int y,int e); // for testing purposes
		void insertRing(int x,int y,int element);
		void removeRing(int x,int y);
		void moveRing(int sx,int sy,int ex,int ey); 
		void removeRun(int sx,int sy,int ex,int ey); // for executing opponent's move
		vector<moves> validMoves(int player);		
		// Auxiliary functions
		void flip(int sx,int sy,int ex,int ey,int direction);
		int getDirection(int sx,int sy,int ex,int ey);
		int getAxis(int x,int y); // get axis or region
		pair<int,int> getN0(int x,int y);
		pair<int,int> getN1(int x,int y);
		pair<int,int> getN2(int x,int y);
		pair<int,int> getN3(int x,int y);
		pair<int,int> getN4(int x,int y);
		pair<int,int> getN5(int x,int y);

		vector<moves> getValidN0(int sx,int sy);
		vector<moves> getRunDown(int player);
		void print();
};

#endif