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
	for(int i=0;i<=nor+1;i++){
		vector<int> v;
		if(i==0) v.push_back(0);
		for(int j=0;j<6*i;j++){
			if(i==5 && j%5==0 && nor == 5) v.pb(-1);
			else if(i == 6 && j%6==0 && nor == 6) v.pb(-1);
			else if(i==nor+1) v.pb(-1);
			else v.pb(0);
		}
		state.pb(v);
	}
	removedWhite=0;
	removedBlack=0;
}
	
void game::print(){
	for(int i=0;i<state.size();i++){
		for(int j=0;j<state[i].size();j++)
			cout<<state[i][j]<<" ";
		cout<<endl;
	}	
}
