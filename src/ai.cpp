#include <game.h>
#include <iostream>
#include <ai.h>
#include <limits>
using namespace std;

AI::AI(int id){
	this->id=id;
	opponent_id=(id==1)?2:1;
	removedRings1=0;
	removedRings2=0;
}

double AI::utility(int player){
	int score=0;
	if(removedRings1==3 && removedRings2==0)
		score = 10;
	else if(removedRings1==3 && removedRings2==1)
		score = 9;
	else if(removedRings1==3 && removedRings2==2)
		score = 8;
	else if(removedRings1==2 && removedRings2==0)
		score = 7;
	else if(removedRings1==2 && removedRings2==1)
		score = 6;
	else if(removedRings1==1 && removedRings2==0)
		score = 6;
	else if(removedRings1==2 && removedRings2==2)
		score = 5;
	else if(removedRings1==1 && removedRings2==1)
		score = 5;
	else if(removedRings1==0 && removedRings2==0)
		score = 5;
	else if(removedRings1==0 && removedRings2==1)
		score = 4;
	else if(removedRings1==1 && removedRings2==2)
		score = 4;
	else if(removedRings1==0 && removedRings2==2)
		score = 3;
	else if(removedRings1==2 && removedRings2==3)
		score = 2;
	else if(removedRings1==1 && removedRings2==3)
		score = 1;
	else if(removedRings1==0 && removedRings2==3)
		score = 0;
	return (player==1)?score:(10-score);
}

vector<moves> AI::makeDecision(){
	double resultValue=numeric_limits<double>::min();
	vector<moves> result;
	allvalidmoves p;
	vector<moves> v;
	vector<vector<moves>> allMoves;
	p.getAllMoves(id,g,v,0);
	cout<<p.allMoves.size()<<endl;
	for(int i=0;i<p.allMoves.size();i++){
		game b=g;
		for(int j=0;j<p.allMoves[i].size();j++){
			b.performMove(p.allMoves[i][j],id);
		}
		double value=minValue(numeric_limits<double>::min(),numeric_limits<double>::max());
		if(value >= resultValue){
			resultValue = value;
			result = p.allMoves[i];
			// cout<<p.allMoves[i].size()<<endl;
		}
	}
	return result;
}

double AI::maxValue(double alpha,double beta){
	if(g.terminal())
		return utility(id);

	double value = numeric_limits<double>::min();
	game a = g;

	allvalidmoves p;
	vector<moves> v;
	vector<vector<moves>> allMoves;
	p.getAllMoves(id,g,v,0);

	// getAllMoves(id,a,v,0);
	if(allMoves.size()==0)
		return utility(id);

	for(int i=0;i<p.allMoves.size();i++){
		game b=g;
		for(int j=0;j<p.allMoves[i].size();j++){
			b.performMove(p.allMoves[i][j],id);
		}
		value = max(value,minValue(alpha,beta));
		if(value>=beta)
			return value;
		alpha = max(alpha,value);
	}
	return value;
}

double AI::minValue(double alpha,double beta){
	if(g.terminal())
		return utility(opponent_id);

	double value = numeric_limits<double>::max();
	game a = g;

	allvalidmoves p;
	vector<moves> v;
	vector<vector<moves>> allMoves;
	p.getAllMoves(opponent_id,g,v,0);

	if(allMoves.size()==0)
		return utility(opponent_id);

	for(int i=0;i<p.allMoves.size();i++){
		game b=g;
		for(int j=0;j<p.allMoves[i].size();j++){
			b.performMove(p.allMoves[i][j],opponent_id);
		}
		value = min(value,maxValue(alpha,beta));
		if(value<=alpha)
			return value;
		alpha = min(alpha,value);
	}
	return value;
}

bool AI::isTerminal(){
	if(removedRings1==3 || removedRings2==3)
		return 1;
	return 0;
}
