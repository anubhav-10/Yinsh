#include <iostream>
#include <game.h>
using namespace std;

int main(int argc, char const *argv[])
{
	game g;
	g.insertRing(2,1,1);
	g.insertRing(1,5,2);
	g.insertRing(2,9,1);
	g.insertRing(0,0,1);
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