#include <game.h>
#include <iostream>
#include <ai.h>
#include <limits>
using namespace std;

AI::AI(){
	id=1;
	removedRings1=0;
	removedRings2=0;
}

double AI::utility(int player){
	if(removedRings1==3 && removedRings2==0)
		return 10;
	else if(removedRings1==3 && removedRings2==1)
		return 9;
	else if(removedRings1==3 && removedRings2==2)
		return 8;
	else if(removedRings1==2 && removedRings2==0)
		return 7;
	else if(removedRings1==2 && removedRings2==1)
		return 6;
	else if(removedRings1==1 && removedRings2==0)
		return 6;
	else if(removedRings1==2 && removedRings2==2)
		return 5;
	else if(removedRings1==1 && removedRings2==1)
		return 5;
	else if(removedRings1==0 && removedRings2==0)
		return 5;
	else if(removedRings1==0 && removedRings2==1)
		return 4;
	else if(removedRings1==1 && removedRings2==2)
		return 4;
	else if(removedRings1==0 && removedRings2==2)
		return 3;
	else if(removedRings1==2 && removedRings2==3)
		return 2;
	else if(removedRings1==1 && removedRings2==3)
		return 1;
	else if(removedRings1==0 && removedRings2==3)
		return 0;
}

double AI::maxValue(int player,double alpha,double beta){
	if(isTerminal())
		return utility(player);


	double value = numeric_limits<double>::max();
}

bool AI::isTerminal(){
	if(removedRings1==3 || removedRings2==3)
		return 1;
	return 0;
}

void AI::getAllMoves(game g,vector<moves> v,bool moveMade){
	if(g.terminal()){
		allMoves.pb(v);
		return;
	}

	vector<moves> runs=g.getRun(id);
	for(int i=0;i<runs.size();i++){
		game a=g;
		a.performMove(runs[i],id);
		vector<moves> b=v;
		b.pb(runs[i]);
		vector<moves> removes=a.validRemoveRing(id);
		for(int j=0;j<removes.size();j++){
			game c=a;
			c.performMove(removes[j],id);
			vector<moves> d=b;
			d.pb(removes[j]);
			cout<<"abc";
			getAllMoves(c,d,moveMade);
		}
	}
	if(runs.size()>0){
		return;
	}
	if(moveMade){
		allMoves.pb(v);
		return;
	}

	vector<moves> possibleMoves=g.validMoves(id);
	for(int i=0;i<possibleMoves.size();i++){
		game a=g;
		a.performMove(possibleMoves[i],id);
		vector<moves> b=v;
		b.pb(possibleMoves[i]);
		getAllMoves(a,b,1);
	}
}

void AI::print(){
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