#include<game.h>
#include <iostream>
using namespace std;

/*
	0 -> empty
	-1 -> no point
	1 -> WR or P1
	2 -> BR or P2
	3 -> WM or P1
	4 -> BM or P2
*/

game::game(){
	for(int i=0;i<=6;i++){
		vector<int> v;
		if(i==0) v.push_back(0);
		for(int j=0;j<6*i;j++){
			if(i==5 && j%5==0) v.pb(-1);
			else if(i==6) v.pb(-1);
			else v.pb(0);
		}
		state.pb(v);
	}
}
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
		pair<int,int> p=getN0(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=getN0(sx,sy);
		}
	}
	else if(z==1){
		pair<int,int> p=getN1(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=getN1(sx,sy);
		}
	}
	else if(z==2){
		pair<int,int> p=getN2(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=getN2(sx,sy);
		}
	}
	else if(z==3){
		pair<int,int> p=getN3(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=getN3(sx,sy);
		}
	}
	else if(z==4){
		pair<int,int> p=getN4(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=getN4(sx,sy);
		}
	}
	else if(z==5){
		pair<int,int> p=getN5(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=0;
			p=getN5(sx,sy);
		}
	}
	state[ex][ey]=0;
}

vector<moves> game::validMoves(int player){
	vector<moves> v;
	if(player==1){
		// place a ring
		if(white.size()<5){
			for(int i=0;i<state.size();i++){
				for(int j=0;j<state[i].size();j++)
					if(state[i][j]==0){
						moves m;
						m.type=Place;
						m.coord.pb(i);
						m.coord.pb(j);
					}
			}	
		}
		// move a ring
		
 	}
}

void game::flip(int sx,int sy,int ex,int ey,int direction){
	if(direction==0){
		pair<int,int> p=getN0(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=getN0(sx,sy); 
		}
	}
	else if(direction==1){
		pair<int,int> p=getN1(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=getN1(sx,sy); 
		}		
	}
	else if(direction==2){
		pair<int,int> p=getN2(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=getN2(sx,sy); 
		}		
	}
	else if(direction==3){
		pair<int,int> p=getN3(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=getN3(sx,sy); 
		}		
	}
	else if(direction==4){
		pair<int,int> p=getN4(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=getN4(sx,sy); 
		}		
	}
	else if(direction==5){
		pair<int,int> p=getN5(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=getN5(sx,sy); 
		}		
	}
}

int game::getDirection(int sx,int sy,int ex,int ey){
	int z=0;
	/*
		0 -> up
		1 -> ne
		2 -> se
		3 -> down
		4 -> sw
		5 -> nw
	*/
	pair<int,int> dest=make_pair(ex,ey);
	int x,y;
	pair<int,int>p;

	x=sx;y=sy;
	p=getN0(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 0;
		x = p.first; y = p.second;
		p=getN0(x,y);
	}

	x=sx;y=sy;
	p=getN1(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 1;
		x = p.first; y = p.second;
		p=getN1(x,y);
	}

	x=sx;y=sy;
	p=getN2(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 2;
		x = p.first; y = p.second;
		p=getN2(x,y);
	}

	x=sx;y=sy;
	p=getN3(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 3;
		x = p.first; y = p.second;
		p=getN3(x,y);
	}
	x=sx;y=sy;
	p=getN4(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 4;
		x = p.first; y = p.second;
		p=getN4(x,y);
	}

	return 5;
}

int game::getAxis(int x,int y){
/*
	0 -> origin
	1 - 6
	7 -> N
	8 -> S
	9 -> NE
	10 -> SW
	11 -> NW
	12 -> SE
*/
	if(x==0 && y==0)
		return 0;
	else if(y==0)
		return 7;
	else if(y<x)
		return 1;
	else if(y==x)
		return 9;
	else if(y<2*x && y>x)
		return 2;
	else if(y==2*x)
		return 12;
	else if(y<3*x && y>2*x)
		return 3;
	else if(y==3*x)
		return 8;
	else if(y<4*x && y>3*x)
		return 4;
	else if(y==4*x)
		return 10;
	else if(y<5*x && y>4*x)
		return 5;
	else if(y==5*x)
		return 11;
	
	return 6;
}
pair<int,int> game::getN0(int x,int y){ // UP or N
	int z = getAxis(x,y);
	if(z==0 || z==1 || z==7 || z==9)
		return make_pair(x+1,y);
	else if(z==2 || z==12)
		return make_pair(x,y-1);
	else if(z==3 || z==4 || z==8)
		return make_pair(x-1,y-3);
	else if(z==5 || z==10)
		return make_pair(x,y+1);
	
	return make_pair(x+1,y+6);
}

pair<int,int> game::getN1(int x,int y){ // NE
	int z = getAxis(x,y);
	if(z==1 || z==2 || z==7 || z==9 || z==12 || z==0)
		return make_pair(x+1,y+1);
	else if(z==3 || z==8)
		return make_pair(x,y-1);
	else if(z==4 || z==5 || z==10)
		return make_pair(x-1,y-4);

	return make_pair(x,(y+1)%(6*x));
}

pair<int,int> game::getN2(int x,int y){ // SE
	int z = getAxis(x,y);
	if(z==1 || z==4 || z==10)
		return make_pair(x,y-1);
	else if(z==2 || z==3 || z==8 || z==9 || z==12 || z==0)
		return make_pair(x+1,y+2);
	else if(z==6 && y==6*x-1)
		return make_pair(x-1,0);
	else if(z==5 || z==6 || z==11)
		return make_pair(x-1,y-5);

	return make_pair(x,y-1);
}

pair<int,int> game::getN3(int x,int y){ // DOWN or S
	int z = getAxis(x,y);
	if(z==1 || z==7)
		return make_pair(x-1,y);
	else if(z==2 || z==9)
		return make_pair(x,y+1);
	else if(z==3 || z==4 || z==8 || z==12 || z==0 || z==10)
		return make_pair(x+1,y+3);
	else if(z==5 || z==11)
		return make_pair(x,y-1);
	
	return make_pair(x-1,y-6);
}

pair<int,int> game::getN4(int x,int y){ // SW
	int z = getAxis(x,y);
	if(z==1 || z==2 || z==9)
		return make_pair(x-1,y-1);
	else if(z==3 || z==12)
		return make_pair(x,y+1);
	else if(z==4 || z==5 || z==8 || z==10 || z==11 || z==0)
		return make_pair(x+1,y+4);
	else if(z==6)
		return make_pair(x,y-1);

	return make_pair(x,6*x-1);
}

pair<int,int> game::getN5(int x,int y){ // NW
	int z = getAxis(x,y);
	if(z==1 || z==4 || z==8)
		return make_pair(x,y+1);
	else if(z==2 || z==3 || z==12)
		return make_pair(x-1,y-2);
	else if(z==5 || z==6 || z==10 || z==11 || z==0)
		return make_pair(x+1,y+5);
	else if(z==7)
		return make_pair(x+1,(x+1)*6 -1);

	return make_pair(x,y-1);
}
	
void game::print(){
	for(int i=0;i<state.size();i++){
		for(int j=0;j<state[i].size();j++)
			cout<<state[i][j]<<" ";
		cout<<endl;
	}	
}

void game::placeMarker(int x,int y,int e){
	state[x][y]=e;
}