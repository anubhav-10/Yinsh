#include <game.h>
#include <iostream>
#include <climits>
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

pair<vector<moves>,game> AI::makeDecision(game g){
	double resultValue=INT_MIN;
	vector<moves> result;
	game result_state;
	allvalidmoves p;
	vector<moves> v;
	vector<vector<moves>> allMoves;
	p.getAllMoves(id,g,v,0);
	// cout<<p.allMoves.size()<<endl;
	for(int i=0;i<p.allMoves.size();i++){
		game b=g;
		for(int j=0;j<p.allMoves[i].first.size();j++){
			b.performMove(p.allMoves[i].first[j],id);
		}
		double value=maxValue(b,INT_MIN,numeric_limits<double>::max(),2);
		// cerr<<value<<endl;
		if(value > resultValue){
			resultValue = value;
			result_state = p.allMoves[i].second;
			result = p.allMoves[i].first;
			// cout<<p.allMoves[i].size()<<endl;
		}
	}
	// cout<<result.size()<<endl;
	return make_pair(result,result_state);
}

double AI::maxValue(game g,double alpha,double beta,int depth){
	if(g.terminal() || depth==0)
		return g.eval(id);
		// return utility(id);

	double value = INT_MIN;
	// game a = g;

	allvalidmoves p;
	vector<moves> v;
	vector<vector<moves>> allMoves;
	p.getAllMoves(id,g,v,0);
	// getAllMoves(id,a,v,0);
	if(p.allMoves.size()==0)
		return g.eval(id);
		// return utility(id);

	for(int i=0;i<p.allMoves.size();i++){
		game b=g;
		for(int j=0;j<p.allMoves[i].first.size();j++){
			b.performMove(p.allMoves[i].first[j],id);
		}
		value = max(value,minValue(b,alpha,beta,depth-1));
		alpha = max(alpha,value);
		if(alpha>=beta)
			return value;
	}
	return value;
}

double AI::minValue(game g,double alpha,double beta,int depth){
	if(g.terminal() || depth==0){
		// return utility(opponent_id);
		return g.eval(opponent_id);
	}

	double value = numeric_limits<double>::max();
	// game a = g;

	allvalidmoves p;
	vector<moves> v;
	vector<vector<moves>> allMoves;
	p.getAllMoves(opponent_id,g,v,0);

	// cout<<p.allMoves.size()<<endl;
	if(p.allMoves.size()==0){
		return g.eval(opponent_id);
		// return utility(opponent_id);
	}

	for(int i=0;i<p.allMoves.size();i++){
		game b=g;
		for(int j=0;j<p.allMoves[i].first.size();j++){
			b.performMove(p.allMoves[i].first[j],opponent_id);
		}
		value = min(value,maxValue(b,alpha,beta,depth-1));
		beta = min(beta,value);
		if(alpha>=beta)
			return value;
	}
	return value;
}

bool AI::isTerminal(){
	if(removedRings1==3 || removedRings2==3)
		return 1;
	return 0;
}
