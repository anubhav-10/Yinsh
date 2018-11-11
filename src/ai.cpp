#include <game.h>
#include <iostream>
#include <climits>
#include <ai.h>
#include <limits>
#include <algorithm>
using namespace std;

AI::AI(int id){
	this->id=id;
	opponent_id=(id==1)?2:1;
	removedRings1=0;
	removedRings2=0;
}
int no_of_moves;

struct sort_inc{
	bool operator()(const std::pair<vector<moves>, double> &left, const std::pair<vector<moves>, double> &right){
		return left.second < right.second;
	}
};
struct sort_dec{
	bool operator()(const std::pair<vector<moves>, double> &left, const std::pair<vector<moves>, double> &right){
		return left.second > right.second;
	}
};

pair<vector<moves>,game> AI::makeDecision(game g){
	int depth = 2;
	// no_of_moves++;
	cerr<<depth<<endl;
	double resultValue=INT_MIN;
	vector<moves> result;
	game result_state;
	allvalidmoves p;
	vector<moves> v;
	vector<vector<moves>> allMoves;
	p.getAllMoves(id,g,v,0);

	// vector<pair<game, double>> sorted;
	// for(int i=0;i<p.allMoves.size();i++){
	// 	sorted.pb({p.allMoves[i].second, p.allMoves[i].second.eval(id)});
	// }
	sort(p.allMoves.begin(), p.allMoves.end(), sort_inc());
	// cout<<p.allMoves.size()<<endl;
	for(int i=0;i<p.allMoves.size();i++){
		game b=g;
		for(int j=0;j<p.allMoves[i].first.size();j++){
			b.performMove(p.allMoves[i].first[j],id);
		}
		double value=minValue(b,INT_MIN,numeric_limits<double>::max(),depth);
		// cerr<<value<<endl;
		if(value > resultValue){
			resultValue = value;
			result_state = b;
			result = p.allMoves[i].first;
			final_features_value = features;
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
	// vector<pair<game, double>> sorted;
	// for(int i=0;i<p.allMoves.size();i++){
	// 	sorted.pb({p.allMoves[i].second, p.allMoves[i].second.eval(id)});
	// }
	if(depth != 1)
		sort(p.allMoves.begin(), p.allMoves.end(), sort_inc());

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
		return g.eval(id);
	}

	double value = numeric_limits<double>::max();
	// game a = g;

	allvalidmoves p;
	vector<moves> v;
	vector<vector<moves>> allMoves;
	p.getAllMoves(opponent_id,g,v,0);

	// cout<<p.allMoves.size()<<endl;
	if(p.allMoves.size()==0){
		return g.eval(id);
		// return utility(opponent_id);
	}

	// vector<pair<game, double>> sorted;
	// for(int i=0;i<p.allMoves.size();i++){
	// 	sorted.pb({p.allMoves[i].second, p.allMoves[i].second.eval(opponent_id)});
	// }
	if(depth != 1)
		sort(p.allMoves.begin(), p.allMoves.end(), sort_dec());

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
