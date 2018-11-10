#include<game.h>
#include <iostream>
#include <cmath>
using namespace std;

double game::flippedScore(int player){
	double flipped_score = 0;
	if(player==1){
		for(int i=0;i<white.size();i++){
			if(white[i]!=make_pair(-1,-1)){
				// cout<<"Ab"<<endl;
				int x = white[i].first;
				int y = white[i].second;
				flipped_score += flippedUtilUP(1,x,y);
				flipped_score += flippedUtilDown(1,x,y);
				flipped_score += flippedUtilSE(1,x,y);
				flipped_score += flippedUtilSW(1,x,y);
				flipped_score += flippedUtilNE(1,x,y);
				flipped_score += flippedUtilNW(1,x,y);
			}
		}
	}
	else{
		for(int i=0;i<black.size();i++){
			if(black[i]!=make_pair(-1,-1)){
				int x = black[i].first;
				int y = black[i].second;
				flipped_score += flippedUtilUP(1,x,y);
				flipped_score += flippedUtilDown(1,x,y);
				flipped_score += flippedUtilSE(1,x,y);
				flipped_score += flippedUtilSW(1,x,y);
				flipped_score += flippedUtilNE(1,x,y);
				flipped_score += flippedUtilNW(1,x,y);
			}
		}
	}
	return flipped_score;
}

int game::flippedUtilUP(int player,int x,int y){
	int marker = (player==1)?3:4;
	int marker_count = 0;
	pair<int,int> p=get0(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]!=-1){
		if(state[x][y]==marker)
			marker_count++;
		else if(state[x][y]==0)
			return marker_count;
		else if(state[x][y]==1 || state[x][y]==2)
			return 0;
		pair<int,int> p=get0(x,y);
		x=p.first;
		y=p.second;
	}
	return 0;
}

int game::flippedUtilDown(int player,int x,int y){
	int marker = (player==1)?3:4;
	int marker_count = 0;
	pair<int,int> p=get3(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]!=-1){
		if(state[x][y]==marker)
			marker_count++;
		else if(state[x][y]==0)
			return marker_count;
		else if(state[x][y]==1 || state[x][y]==2)
			return 0;
		pair<int,int> p=get3(x,y);
		x=p.first;
		y=p.second;
	}
	return 0;
}

int game::flippedUtilSE(int player,int x,int y){
	int marker = (player==1)?3:4;
	int marker_count = 0;
	pair<int,int> p=get2(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]!=-1){
		if(state[x][y]==marker)
			marker_count++;
		else if(state[x][y]==0)
			return marker_count;
		else if(state[x][y]==1 || state[x][y]==2)
			return 0;
		pair<int,int> p=get2(x,y);
		x=p.first;
		y=p.second;
	}
	return 0;
}

int game::flippedUtilSW(int player,int x,int y){
	int marker = (player==1)?3:4;
	int marker_count = 0;
	pair<int,int> p=get4(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]!=-1){
		if(state[x][y]==marker)
			marker_count++;
		else if(state[x][y]==0)
			return marker_count;
		else if(state[x][y]==1 || state[x][y]==2)
			return 0;
		pair<int,int> p=get4(x,y);
		x=p.first;
		y=p.second;
	}
	return 0;
}

int game::flippedUtilNE(int player,int x,int y){
	int marker = (player==1)?3:4;
	int marker_count = 0;
	pair<int,int> p=get1(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]!=-1){
		if(state[x][y]==marker)
			marker_count++;
		else if(state[x][y]==0)
			return marker_count;
		else if(state[x][y]==1 || state[x][y]==2)
			return 0;
		pair<int,int> p=get1(x,y);
		x=p.first;
		y=p.second;
	}
	return 0;
}

int game::flippedUtilNW(int player,int x,int y){
	int marker = (player==1)?3:4;
	int marker_count = 0;
	pair<int,int> p=get5(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]!=-1){
		if(state[x][y]==marker)
			marker_count++;
		else if(state[x][y]==0)
			return marker_count;
		else if(state[x][y]==1 || state[x][y]==2)
			return 0;
		pair<int,int> p=get5(x,y);
		x=p.first;
		y=p.second;
	}
	return 0;
}

double game::countMarkers(int player){
	int marker = (player==1)?3:4;
	double marker_count = 0;
	for(int i=0;i<state.size();i++){
		for(int j=0;j<state[i].size();j++){
			if(state[i][j] == marker)
				marker_count++;
		}
	}	
	return marker_count;
}

double game::mobilityScore(int player){
	double mobility_score = 0;
	if(player==1){
		for(int i=0;i<white.size();i++){
			if(white[i]!=make_pair(-1,-1)){
				int x = white[i].first;
				int y = white[i].second;
				mobility_score += mobilityUtilUP(player,x,y);
				mobility_score += mobilityUtilDown(player,x,y);
				mobility_score += mobilityUtilSE(player,x,y);
				mobility_score += mobilityUtilSW(player,x,y);
				mobility_score += mobilityUtilNE(player,x,y);
				mobility_score += mobilityUtilNW(player,x,y);
			}
		}
	}
	else{
		for(int i=0;i<black.size();i++){
			if(black[i]!=make_pair(-1,-1)){
				int x = black[i].first;
				int y = black[i].second;
				mobility_score += mobilityUtilUP(player,x,y);
				mobility_score += mobilityUtilDown(player,x,y);
				mobility_score += mobilityUtilSE(player,x,y);
				mobility_score += mobilityUtilSW(player,x,y);
				mobility_score += mobilityUtilNE(player,x,y);
				mobility_score += mobilityUtilNW(player,x,y);
			}
		}		
	}
	return mobility_score;
}

int game::mobilityUtilUP(int player,int x,int y){
	int space_count = 0;
	pair<int,int> p=get0(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]==0){
		space_count++;
		pair<int,int> p=get0(x,y);
		x=p.first;
		y=p.second;
	}
	while(state[x][y]!=-1){
		if(state[x][y]==0)
			return space_count+1;
		else if(state[x][y]==1 || state[x][y]==2)
			return space_count;
		pair<int,int> p=get0(x,y);
		x=p.first;
		y=p.second;
	}
	return space_count;
}

int game::mobilityUtilDown(int player,int x,int y){
	int space_count = 0;
	pair<int,int> p=get3(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]==0){
		space_count++;
		pair<int,int> p=get3(x,y);
		x=p.first;
		y=p.second;
	}
	while(state[x][y]!=-1){
		if(state[x][y]==0)
			return space_count+1;
		else if(state[x][y]==1 || state[x][y]==2)
			return space_count;
		pair<int,int> p=get3(x,y);
		x=p.first;
		y=p.second;
	}
	return space_count;
}

int game::mobilityUtilSE(int player,int x,int y){
	int space_count = 0;
	pair<int,int> p=get2(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]==0){
		space_count++;
		pair<int,int> p=get2(x,y);
		x=p.first;
		y=p.second;
	}
	while(state[x][y]!=-1){
		if(state[x][y]==0)
			return space_count+1;
		else if(state[x][y]==1 || state[x][y]==2)
			return space_count;
		pair<int,int> p=get2(x,y);
		x=p.first;
		y=p.second;
	}
	return space_count;
}

int game::mobilityUtilSW(int player,int x,int y){
	int space_count = 0;
	pair<int,int> p=get4(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]==0){
		space_count++;
		pair<int,int> p=get4(x,y);
		x=p.first;
		y=p.second;
	}
	while(state[x][y]!=-1){
		if(state[x][y]==0)
			return space_count+1;
		else if(state[x][y]==1 || state[x][y]==2)
			return space_count;
		pair<int,int> p=get4(x,y);
		x=p.first;
		y=p.second;
	}
	return space_count;
}

int game::mobilityUtilNE(int player,int x,int y){
	int space_count = 0;
	pair<int,int> p=get1(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]==0){
		space_count++;
		pair<int,int> p=get1(x,y);
		x=p.first;
		y=p.second;
	}
	while(state[x][y]!=-1){
		if(state[x][y]==0)
			return space_count+1;
		else if(state[x][y]==1 || state[x][y]==2)
			return space_count;
		pair<int,int> p=get1(x,y);
		x=p.first;
		y=p.second;
	}
	return space_count;
}

int game::mobilityUtilNW(int player,int x,int y){
	int space_count = 0;
	pair<int,int> p=get5(x,y);
	x=p.first;
	y=p.second;
	while(state[x][y]==0){
		space_count++;
		pair<int,int> p=get5(x,y);
		x=p.first;
		y=p.second;
	}
	while(state[x][y]!=-1){
		if(state[x][y]==0)
			return space_count+1;
		else if(state[x][y]==1 || state[x][y]==2)
			return space_count;
		pair<int,int> p=get5(x,y);
		x=p.first;
		y=p.second;
	}
	return space_count;
}

