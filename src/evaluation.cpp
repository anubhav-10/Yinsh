#include<game.h>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> row_weights = {1, 3, 9, 27, 81};
int w0 = 1;
int w9 = 1;
int w8 = 1;
int w7 = 1;
int w6 = 1;
int w5 = 1;
int w4 = 1;
int w3 = 1;
int w2 = 1;
int w1 = 1;
double a0 = 0.5;
double b0 = 0.5;
double b1 = 0.5;
vector<int> s1,s2;
int mark_ring_W, mark_ring_B;
void init(){
	s1.clear();
	s2.clear();
	for(int i=0;i<5;i++){
		s1.pb(0);
		s2.pb(0);
	}
	mark_ring_B=0;
	mark_ring_W=0;
	// cout<<s1.size()<<endl;
}

double game::markerScore(int player){
	int marker = (player==1)?3:4;
	double marker_score = 0;
	
	marker_score += markerScoreDown(player);
	marker_score += markerScoreSE(player);
	marker_score += markerScoreSW(player);

	return marker_score;
}

double game::markerScoreDown(int player){
	double marker_score = 0;
	marker_score += markerScoreDownUtil(player,5,1,4);
	marker_score += markerScoreDownUtil(player,5,26,29);
	marker_score += markerScoreDownUtil(player,4,0,0);
	return marker_score;
}

double game::markerScoreDownUtil(int player,int startx,int a,int b){
	int marker = (player==1)?3:4;
	double marker_score=0;
	for(int i=a;i<=b;i++){
		int sx=startx,sy=i;
		int allot = 0;
		int x = sx, y = sy;
		while(state[x][y]!=-1){
			if(state[x][y]==marker){
				marker_score += row_weights[allot];
	 			if(allot!=4)
	 				allot++;
 			}
 			else if(state[x][y]==player){
 				marker_score += 0.5 * row_weights[allot];
 				// allot=0;jf[]
	 			if(allot!=4)
	 				allot++;
	 			else{
	 				if(player==1)
	 					mark_ring_W++;
	 				else
	 					mark_ring_B++;
	 				allot=0;
	 			}
 			}
 			else{
 				// cerr<<allot<<endl;
				if(player==1) s1[allot]++;
				else s2[allot]++;
 				allot = 0;
 			}
 			pair<int,int> p = get3(x,y);
 			x = p.first;
 			y = p.second;
		}
	}
	return marker_score;
}

double game::markerScoreSE(int player){
	double marker_score = 0;
	marker_score += markerScoreSEUtil(player,5,1,4);
	marker_score += markerScoreSEUtil(player,5,26,29);
	marker_score += markerScoreSEUtil(player,4,20,20);
	return marker_score;
}

double game::markerScoreSEUtil(int player,int startx,int a,int b){
	int marker = (player==1)?3:4;
	double marker_score=0;
	// bool b=0;
	for(int i=a;i<=b;i++){
		int sx=startx,sy=i;
		int allot = 0;
		int x = sx, y = sy;
		while(state[x][y]!=-1){
			if(state[x][y]==marker){
				marker_score += row_weights[allot];
	 			if(allot!=4)
	 				allot++;
 			}
 			else if(state[x][y]==player){
 				marker_score += 0.5 * row_weights[allot];
 				// allot=0;
	 			if(allot!=4)
	 				allot++;
	 			else{
	 				if(player==1)
	 					mark_ring_W++;
	 				else
	 					mark_ring_B++;
	 				allot=0;
	 			}
 			}
 			else{
 				if(player==1) s1[allot]++;
				else s2[allot]++;
				allot = 0;
 			}
 			pair<int,int> p = get2(x,y);
 			x = p.first;
 			y = p.second;
		}
	}
	return marker_score;
}

double game::markerScoreSW(int player){
	double marker_score = 0;
	marker_score += markerScoreSWUtil(player,5,1,4);
	marker_score += markerScoreSWUtil(player,5,6,9);
	marker_score += markerScoreSWUtil(player,4,4,4);
	return marker_score;
}

double game::markerScoreSWUtil(int player,int startx,int a,int b){
	int marker = (player==1)?3:4;
	double marker_score=0;
	for(int i=a;i<=b;i++){
		int sx=startx,sy=i;
		int allot = 0;
		int x = sx, y = sy;
		while(state[x][y]!=-1){
			if(state[x][y]==marker){
				marker_score += row_weights[allot];
	 			if(allot!=4)
	 				allot++;
 			}
 			else if(state[x][y]==player){
 				marker_score += 0.5 * row_weights[allot];
 				// allot=0;
	 			if(allot!=4)
	 				allot++;
	 			else{
	 				if(player==1)
	 					mark_ring_W++;
	 				else
	 					mark_ring_B++;
	 				allot=0;
	 			}
 			}
 			else{
 				if(player==1) s1[allot]++;
				else s2[allot]++;
				allot = 0;
 			}
 			pair<int,int> p = get4(x,y);
 			x = p.first;
 			y = p.second;
		}
	}
	return marker_score;
}

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

double game::eval(int player){
	init();
	double no_of_w_markers = countMarkers(1);
	double no_of_b_markers = countMarkers(2);

	double w_row = markerScore(1);
	double b_row = markerScore(2);	
	int ring_count_w=0,ring_count_b=0;
	for(int i=0;i<5;i++){
		if(white[i]!=make_pair(-1,-1))
			ring_count_w++;
		if(black[i]!=make_pair(-1,-1))
			ring_count_b++;
	}
	// double flip_w_markers = flippedScore(2);
	// double flip_b_markers = flippedScore(1);
	// 			// cout<<"Ab"<<endl;

	double mobility_w_ring = mobilityScore(1);
	double mobility_b_ring = mobilityScore(2);
	double x=100000;
	// if(removedWhite==2)
	// 	x=10000000;
	// double b_score = (w0*no_of_b_markers + w1*b_row + w2*flip_b_markers + w3*mobility_b_ring + w4*removedBlack) * (a0 + b0*removedBlack);
	// double w_score = (w5*no_of_w_markers + w6*w_row + w7*flip_w_markers + w8*mobility_w_ring + w9*removedWhite) * (a0 + b1*removedWhite);
	// double w_score = pow(-1,player-1)*(-100000*(removedBlack)+1000000000*(removedWhite)+(s1[0]-s2[0])+400*(s1[1]-s2[1])+10000*(s1[2]-s2[2])+500000*(s1[3]-s2[3])+100000000*(s1[4]-s2[4])+1000*(mobility_w_ring-mobility_b_ring)); 
	// double b_score = 10000*(removedBlack)+(s2[0]-s1[0])+4*(s2[1]-s1[1])+100*(s2[2]-s1[2])+1000*(s2[3]-s1[3])+10000*(s2[4]-s1[4]); 
	// double w_score = pow(-1,player-1)*(-100000*(removedBlack)+1000000000*(removedWhite)+(s1[0]-s2[0])+400*(s1[1]-s2[1])+10000*(s1[2]-s2[2])+500000*(s1[3]-s2[3])+100000000*(s1[4]-s2[4])+1000*(mobility_w_ring-mobility_b_ring)); 
 	// double w_score = pow(-1,player-1)*(-200000*(removedBlack)+x*(removedWhite)+1000*(mark_ring_W-10*mark_ring_B)+(s1[0]-s2[0])+4*(s1[1]-s2[1])+24*(4*s1[2]-2*s2[2])+160*(s1[3]-50*s2[3])+950*(s1[4]-70*s2[4])); 
	// return (player==1)?w_score:b_score;
	double w1_score = pow(-1,player-1)*(-1000000*(removedBlack)+10000000*(removedWhite)+(s1[0]-s2[0])+40*(s1[1]-s2[1])+1000*(s1[2]-s2[2])+10000*(s1[3]-s2[3])+1000000*(s1[4]-s2[4])+500000);
	double w_score = pow(-1,player-1)*(-200000*(removedBlack)+10000000*(removedWhite)+1000*(10*mark_ring_W-mark_ring_B)+(s1[0]-s2[0])+4*(s1[1]-s2[1])+24*(4*s1[2]-2*s2[2])+160*(200*s1[3]-50*s2[3])+950*(500*s1[4]-70*s2[4]));
	double b_score = pow(-1,player-2)*(-200000*(removedWhite)+10000000*(removedBlack)+1000*(10*mark_ring_B-mark_ring_W)+(s2[0]-s1[0])+4*(s2[1]-s1[1])+24*(4*s2[2]-2*s1[2])+160*(200*s2[3]-50*s1[3])+950*(500*s2[4]-70*s1[4]));

	return (player==1)?w_score:b_score;
	// return pow(-1,player-1)*((s1[0]-s2[0])+4*(s1[1]-s2[1])+24*(4*s1[2]-20*s2[2])+160*(s1[3]-50*s2[3])+950*(s1[4]-70*s2[4]));
	// return pow(-1,player-1)*(7*(no_of_w_markers-no_of_b_markers)+19*(mobility_w_ring-mobility_b_ring));
}