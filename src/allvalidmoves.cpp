#include <allvalidmoves.h>
#include <iostream>
using namespace std;

void allvalidmoves::getAllMoves(int player,game g,vector<moves> v,bool moveMade){
	if(g.terminal()){
		allMoves.pb(v);
		return;
	}

	vector<moves> runs=g.getRun(player);
	for(int i=0;i<runs.size();i++){
		game a=g;
		a.performMove(runs[i],player);
		vector<moves> b=v;
		b.pb(runs[i]);
		vector<moves> removes=a.validRemoveRing(player);
		for(int j=0;j<removes.size();j++){
			game c=a;
			c.performMove(removes[j],player);
			vector<moves> d=b;
			d.pb(removes[j]);
			// cout<<"abc";
			getAllMoves(player,c,d,moveMade);
		}
	}
	if(runs.size()>0){
		return;
	}
	if(moveMade){
		allMoves.pb(v);
		return;
	}

	vector<moves> possibleMoves=g.validMoves(player);
	for(int i=0;i<possibleMoves.size();i++){
		game a=g;
		a.performMove(possibleMoves[i],player);
		vector<moves> b=v;
		b.pb(possibleMoves[i]);
		getAllMoves(player,a,b,1);
	}
}

void allvalidmoves::print(){
	cout<<allMoves.size()<<endl;
	for(int i=0;i<allMoves.size();i++){
		for(int j=0;j<allMoves[i].size();j++){
			cout<<allMoves[i][j].type<<" ";
			for(int k=0;k<allMoves[i][j].coord.size();k++)
				cout<<allMoves[i][j].coord[k]<<" ";
		}
		cout<<endl;
	}
}