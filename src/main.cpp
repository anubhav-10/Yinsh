#include <iostream>
#include <game.h>
#include <ai.h>
using namespace std;

int main(int argc, char const *argv[])
{
	game g;
	g.insertRing(2,1,1);
	g.insertRing(1,5,2);
	g.insertRing(2,9,1);
	g.insertRing(0,0,1);
	g.insertRing(1,0,1);

	// g.placeMarker(3,3,3);
	// g.placeMarker(4,3,4);
	g.insertRing(3,5,1);

	g.placeMarker(4,23,3);
	g.placeMarker(3,17,3);
	g.placeMarker(2,11,3);
	g.placeMarker(1,5,3);
	g.placeMarker(1,4,3);
	// g.placeMarker(2,7,3);
	// g.placeMarker(3,10,3);
	// g.placeMarker(4,13,3);
	// g.placeMarker(5,16,3);

	AI p;
	vector<moves> v;
	vector<vector<moves>> allMoves;
	p.getAllMoves(g,v,0);
	p.print();

	// g.placeMarker(3,5,3);
	// g.placeMarker(2,4,3);
	// g.placeMarker(2,5,3);
	// g.placeMarker(2,6,3);
	// g.placeMarker(3,10,3);
	// g.placeMarker(4,14,3);
	// g.placeMarker(5,18,3);
	// moves m;
	// m.type=Move;
	// m.coord.pb(3);
	// m.coord.pb(5);
	// m.coord.pb(3);
	// m.coord.pb(16);
	// vector<moves> ans=g.getRun(1);
	// for(int i=0;i<ans.size();i++){
	// 	cout<<ans[i].type<<endl;
	// 	for(int j=0;j<ans[i].coord.size();j++){
	// 		cout<<ans[i].coord[j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// g.performMove(m,1);

	// g.print();
	// g.moveRing(1,5,0,0);
	// g.moveRing(2,9,1,4);
	// g.print();
	// g.moveRing(2,1,3,13);
	// g.print();
	// g.placeMarker(2,9,3);
	// g.placeMarker(2,8,3);
	// g.placeMarker(3,11,3);
	// g.placeMarker(4,14,3);
	// g.placeMarker(5,17,3);
	// g.print();

	// g.removeRun(2,9,5,17);
	// g.print();

	return 0;
}