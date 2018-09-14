#include<game.h>
#include <iostream>
using namespace std;

vector<moves> game::validMoves(int player){
	vector<moves> ans;
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
						ans.pb(m);
					}
			}
			return ans;
		}
		// check for a run

		// move a ring
	 	for(int i=0;i<1;i++){
			pair<int,int> ring=white[i];
			int x,y,sx,sy;
			sx=ring.first; sy=ring.second;
			vector<moves> v;
			v=getValid0(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid1(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid2(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid3(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid4(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid5(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
 		}
 	}
}

vector<moves> game::getValid0(int sx,int sy){
	vector<moves> v;
	// up
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get0(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get0(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get0(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get0(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid1(int sx,int sy){
	vector<moves> v;
	// NE
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get1(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		// cout<<x<<" "<<y<<endl;
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get1(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get1(x,y);
				x=next.first; y=next.second;
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get1(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid2(int sx,int sy){
	vector<moves> v;
	// SE
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get2(x,y);
	x=next.first; y=next.second;
	cout<<x<<" "<<y<<endl;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get2(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get2(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get2(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid3(int sx,int sy){
	vector<moves> v;
	// Down
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get3(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get0(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get3(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get3(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid4(int sx,int sy){
	vector<moves> v;
	// up
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get4(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get4(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get4(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get4(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid5(int sx,int sy){
	vector<moves> v;
	// up
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get5(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get5(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get5(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get5(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getRunDown(int player){
	int c=(player==1)?3:4;
	vector<moves> v;
	// Down
	for(int i=1;i<=4;i++){
		int sx=5,sy=i,x,y;
		int l=0;
		x=sx;y=sy;
		while(state[x][y]!=-1){
			if(state[x][y]==c){
				l=1;
				pair<int,int> p=get3(x,y);
				x=p.first; y=p.second;
				while(state[x][y]==c){
					l++;
					if(l==5){
						// add in vector
						moves m;
						m.type = RemoveRun;
						m.coord.pb(sx);
						m.coord.pb(sy);
						m.coord.pb(x);
						m.coord.pb(y);
						v.pb(m);
						l=4;
						pair<int,int> temp=get3(sx,sy);
						sx=temp.first; sy=temp.second;
					}
					pair<int,int> p=get3(x,y);
					x=p.first; y=p.second;
				}
				if(state[x][y]==-1) break;
			}
			pair<int,int> p=get3(x,y);
			x=p.first; y=p.second;
		}
	}

	return v;
}