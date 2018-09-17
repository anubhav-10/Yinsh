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
	int removedWhite,removedBlack;
	public:
		game();
		void placeMarker(int x,int y,int e); // for testing purposes
		void insertRing(int x,int y,int element);
		void removeRing(int x,int y);
		void moveRing(int sx,int sy,int ex,int ey); 
		void removeRun(int sx,int sy,int ex,int ey); // for executing opponent's move
		bool terminal();
		void performMove(moves m,int player);
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
		vector<moves> validRemoveRing(int player);
		vector<moves> getRun(int player);
		vector<moves> getRunDown(int player);
		vector<moves> getRunDownUtil(int player,int startx,int a,int b);
		vector<moves> getRunSE(int player);
		vector<moves> getRunSEUtil(int player,int startx,int a,int b);
		vector<moves> getRunSW(int player);
		vector<moves> getRunSWUtil(int player,int startx,int a,int b);
		// evaluation function
		double markerScore(int player);
		double markerScoreDown(int player);
		double markerScoreDownUtil(int player,int startx,int a,int b);
		double markerScoreSE(int player);
		double markerScoreSEUtil(int player,int startx,int a,int b);
		double markerScoreSW(int player);
		double markerScoreSWUtil(int player,int startx,int a,int b);

		double flippedScore(int player);
		int flippedUtilUP(int player,int x,int y);
		int flippedUtilDown(int player,int x,int y);
		int flippedUtilSE(int player,int x,int y);
		int flippedUtilSW(int player,int x,int y);
		int flippedUtilNE(int player,int x,int y);
		int flippedUtilNW(int player,int x,int y);

		double countMarkers(int player);

		double mobilityScore(int player);
		int mobilityUtilUP(int player,int x,int y);
		int mobilityUtilDown(int player,int x,int y);
		int mobilityUtilSE(int player,int x,int y);
		int mobilityUtilSW(int player,int x,int y);
		int mobilityUtilNE(int player,int x,int y);
		int mobilityUtilNW(int player,int x,int y);
		
		double eval(int player);

		void print();
};

#endif