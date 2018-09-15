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
		// Auxiliary functions
		void flip(int sx,int sy,int ex,int ey,int direction);
		int getDirection(int sx,int sy,int ex,int ey);
		int getRegion(int x,int y); // get axis or region
		pair<int,int> get0(int x,int y);
		pair<int,int> get1(int x,int y);
		pair<int,int> get2(int x,int y);
		pair<int,int> get3(int x,int y);
		pair<int,int> get4(int x,int y);
		pair<int,int> get5(int x,int y);
		// valid moves
		vector<moves> validMoves(int player);		
		vector<moves> getValid0(int sx,int sy);
		vector<moves> getValid1(int sx,int sy);
		vector<moves> getValid2(int sx,int sy);
		vector<moves> getValid3(int sx,int sy);
		vector<moves> getValid4(int sx,int sy);
		vector<moves> getValid5(int sx,int sy);
		vector<moves> getRun(int player);
		vector<moves> getRunDown(int player);
		vector<moves> getRunDownUtil(int player,int startx,int a,int b);
		vector<moves> getRunSE(int player);
		vector<moves> getRunSEUtil(int player,int startx,int a,int b);
		vector<moves> getRunSW(int player);
		vector<moves> getRunSWUtil(int player,int startx,int a,int b);
		void print();
};

#endif