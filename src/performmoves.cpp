#include<game.h>
#include <iostream>
using namespace std;

void game::insertRing(int x,int y,int element){ // element = player
	state[x][y]=element;
	if(element==1)
		white.pb(make_pair(x,y));
	else
		black.pb(make_pair(x,y));
}

void game::removeRing(int x,int y){
	int p=state[x][y];
	state[x][y]=0;
	if(p==1){
		for(int i=0;i<5;i++)
			if(white[i]==make_pair(x,y)){
				white[i]=make_pair(-1,-1);
				break;
			}
	}
	else{
		for(int i=0;i<5;i++)
			if(black[i]==make_pair(x,y)){
				black[i]=make_pair(-1,-1);
				break;
			}	
	}
}
void game::moveRing(int sx,int sy,int ex,int ey){
	state[ex][ey]=state[sx][sy];
	
	if(state[sx][sy]==1){
		for(int i=0;i<5;i++){
			if(white[i]==make_pair(sx,sy)){
				white[i]=make_pair(ex,ey);
				break;
			}
		}
		state[sx][sy]=3;
	}
	else if(state[sx][sy]==2){
		for(int i=0;i<5;i++){
			if(black[i]==make_pair(sx,sy)){
				black[i]=make_pair(ex,ey);
				break;
			}
		}
		state[sx][sy]=4;
	}

	int z =  getDirection(sx,sy,ex,ey);
	flip(sx,sy,ex,ey,z);

}

void game::removeRun(int sx,int sy,int ex,int ey){
	int z = getDirection(sx,sy,ex,ey);
	state[sx][sy]=0;
	pair<int,int> d=make_pair(ex,ey);
	if(z==0){
		pair<int,int> p=get0(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=get0(sx,sy);
		}
	}
	else if(z==1){
		pair<int,int> p=get1(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=get1(sx,sy);
		}
	}
	else if(z==2){
		pair<int,int> p=get2(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=get2(sx,sy);
		}
	}
	else if(z==3){
		pair<int,int> p=get3(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=get3(sx,sy);
		}
	}
	else if(z==4){
		pair<int,int> p=get4(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=get4(sx,sy);
		}
	}
	else if(z==5){
		pair<int,int> p=get5(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=get5(sx,sy);
		}
	}
	state[ex][ey]=0;
}

void game::placeMarker(int x,int y,int e){
	state[x][y]=e;
}
