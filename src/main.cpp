#include <iostream>
#include <game.h>
#include <ai.h>
#include <string>
using namespace std;

vector<moves> convertToMyMove(string s){
	vector<moves> result;
	vector<string> v;
	string temp="";
	for(int i=0;i<s.size();i++){
		if(s[i]==' '){
			v.pb(temp);
			temp="";
		}
		else
			temp+=s[i];
	}
	v.pb(temp);

	int i=0,n=v.size();
	while(i<n){
		string a=v[i];
		// cout<<"a"<<endl;
		if(a=="P"){
			int a1=stoi(v[i+1]),a2=stoi(v[i+2]);
			moves m;
			m.type=Place;
			m.coord.pb(a1);
			m.coord.pb(a2);
			result.pb(m);
			i+=3;
		}
		else if(a=="S"){
			int a1=stoi(v[i+1]),a2=stoi(v[i+2]),a3=stoi(v[i+4]),a4=stoi(v[i+5]);
			moves m;
			m.type=Move;
			m.coord.pb(a1);
			m.coord.pb(a2);
			m.coord.pb(a3);
			m.coord.pb(a4);
			result.pb(m);
			i+=6;
		}
		else if(a=="RS"){
			int a1=stoi(v[i+1]),a2=stoi(v[i+2]),a3=stoi(v[i+4]),a4=stoi(v[i+5]);
			moves m;
			m.type=RemoveRun;
			m.coord.pb(a1);
			m.coord.pb(a2);
			m.coord.pb(a3);
			m.coord.pb(a4);
			result.pb(m);
			i+=6;
		}
		else{
			int a1=stoi(v[i+1]),a2=stoi(v[i+2]);
			moves m;
			m.type=RemoveRing;
			m.coord.pb(a1);
			m.coord.pb(a2);
			result.pb(m);
			i+=3;			
		}
	}
	return result;
	// cout<<s<<endl;
} 

string convertTo(vector<moves> v){
	string result="";
	for(int i=0;i<v.size();i++){
		moves m=v[i];
		if(m.type==Place){
			result+="P ";
			result+=to_string(m.coord[0])+" ";
			result+=to_string(m.coord[1])+" ";
		}
		else if(m.type==Move){
			result+="S ";
			result+=to_string(m.coord[0])+" ";
			result+=to_string(m.coord[1])+" ";
			result+="M ";
			result+=to_string(m.coord[2])+" ";
			result+=to_string(m.coord[3])+" ";
		}
		else if(m.type==RemoveRun){
			result+="RS ";
			result+=to_string(m.coord[0])+" ";
			result+=to_string(m.coord[1])+" ";
			result+="RE ";
			result+=to_string(m.coord[2])+" ";
			result+=to_string(m.coord[3])+" ";
		}
		else{
			result+="X ";
			result+=to_string(m.coord[0])+" ";
			result+=to_string(m.coord[1])+" ";			
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	// game g;
	// g.insertRing(2,1,1);
	// g.insertRing(4,22,1);
	// g.insertRing(1,3,1);
	// g.insertRing(1,5,1);

	// g.insertRing(2,0,2);
	// g.insertRing(2,2,2);
	// g.insertRing(1,4,2);
	// g.insertRing(5,18,2);

	// g.placeMarker(1,0,3);
	// g.placeMarker(2,11,3);
	// g.placeMarker(3,16,3);
	// g.placeMarker(2,6,3);
	// g.placeMarker(3,9,3);

	// g.placeMarker(5,3,3);
	// g.placeMarker(5,4,3);
	
	// g.placeMarker(4,3,3);
	// g.placeMarker(4,4,3);
	// g.placeMarker(5,6,3);

	// g.placeMarker(5,7,3);

	// g.placeMarker(3,4,3);
	// g.placeMarker(5,8,3);

	// g.placeMarker(4,7,3);
	// g.placeMarker(5,9,3);

	// g.placeMarker(2,4,3);
	// g.placeMarker(4,8,3);

	// g.placeMarker(3,7,3);
	// g.placeMarker(4,9,3);
	// g.placeMarker(5,11,3);

	// g.placeMarker(5,12,3);
	// g.placeMarker(5,13,3);
	// g.placeMarker(5,14,3);

	// g.placeMarker(5,29,4);
	// g.placeMarker(4,22,4);
	// g.placeMarker(3,16,4);
	// g.placeMarker(2,7,4);
	// g.placeMarker(3,10,4);

	// g.placeMarker(4,0,4);
	// g.placeMarker(4,12,4);

	// g.placeMarker(5,1,4);
	// g.placeMarker(1,1,4);
	// g.placeMarker(1,2,4);
	// g.placeMarker(2,5,4);
	// g.placeMarker(3,8,4);
	// g.placeMarker(4,11,4);

	// g.placeMarker(5,2,4);
	// g.placeMarker(4,2,4);
	// g.placeMarker(3,2,4);
	// g.placeMarker(2,3,4);
	// g.placeMarker(4,10,4);

	// g.placeMarker(3,3,4);
	// g.placeMarker(3,5,4);
	// g.placeMarker(3,6,4);

	// g.placeMarker(4,5,4);
	// g.placeMarker(4,6,4);

	// g.insertRing(4,16,1);
	// g.removeRing(4,16);
	// g.insertRing(5,25,2);
	// g.removeRing(5,25);

	// vector<moves> x=g.getRunDown(2);
	// for(int i=0;i<x.size();i++){
	// 	cout<<x[i].type<<" ";
	// 	cout<<x[i].coord[0]<<" "<<x[i].coord[1]<<" "<<x[i].coord[2]<<" "<<x[i].coord[3]<<" ";
	// 	cout<<endl;
	// }
	// allvalidmoves y;
	// y.getAllMoves(2,g,x,0);
	// y.print();

	int id,n,t;
	cin>>id>>n>>t;
	cin.ignore();
	AI player(id);
	int opponet_id=(id==1)?2:1;
	// cout<<opponet_id;
	string move;
	vector<moves> v;
	if(id==2){
		// cin>>move;
		getline(cin,move);
		v=convertToMyMove(move);
		for(int i=0;i<v.size();i++){
			player.g.performMove(v[i],opponet_id);
		}
	}
	while(!player.g.terminal()){
		vector<moves> v=player.makeDecision();

		// for(int j=0;j<v.size();j++){
		// 	cout<<v[j].type<<" ";
		// 	for(int k=0;k<v[j].coord.size();k++)
		// 		cout<<v[j].coord[k]<<" ";
		// }
		// cout<<endl;
		cout<<convertTo(v)<<endl;
		for(int i=0;i<v.size();i++){
			player.g.performMove(v[i],id);
		}
		// player.g.print();

		// cin>>move;
		getline(cin,move);
		v=convertToMyMove(move);
		for(int i=0;i<v.size();i++){
			// for(int j=0;j<v.size();j++){
			// 	cout<<v[j].type<<" ";
			// 	for(int k=0;k<v[j].coord.size();k++)
			// 		cout<<v[j].coord[k]<<" ";
			// }
			// cout<<endl;

			player.g.performMove(v[i],opponet_id);
		}
		// player.g.print();
	}

	return 0;
}