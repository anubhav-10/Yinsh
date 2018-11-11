#include <fstream>
#include <iostream>
#include <game.h>
#include <ai.h>
#include <string>
using namespace std;
int nom, nor;
vector<vector<pair<int,int>>> vertical, diagonal1, diagonal2;
vector<double> weights1 {100000000, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000 -100000000, -1, -10, -100, -1000, -10000, -100000, -1000000, -10000};
vector<int> final_features_value;

vector<pair<int,int>> convert_to_vector(string s){
    string temp="";
    vector<pair<int,int>> v;
    int n = 1, a = 0, b = 0;
    for(auto i: s){
        if(i == ' '){
            if (n==1){
                a = stoi(temp);
                n++;
            }
            else{
                b = stoi(temp);
                v.pb({a,b});
                n = 1;
            }
            temp = "";
        }
        else{
            temp+=i;
        }
    }
    return v;
}

void init_diagonal(){
    string line;
    if(nor==5){
        ifstream file1("vert5");
        while (getline(file1, line)){
            // cout<<line<<endl;
            vertical.pb(convert_to_vector(line));
        }
        file1.close();

        // freopen("diag15","r",stdin);
        ifstream file2("diag15");
        while (getline(file2, line)){
            // cout<<line<<endl;
            diagonal1.pb(convert_to_vector(line));
        }
        file2.close();

        ifstream file3("diag25");
        while (getline(file3, line)){
            // cout<<line<<endl;
            diagonal2.pb(convert_to_vector(line));
        }
        file3.close();

        // cout<<diagonal2.size()<<endl;
        // for(auto u: diagonal2){
        //     for(auto v: u){
        //         cout<< v.first<<" "<<v.second<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    else{
        ifstream file1("vert6");
        while (getline(file1, line)){
            // cout<<line<<endl;
            vertical.pb(convert_to_vector(line));
        }
        file1.close();

        // freopen("diag15","r",stdin);
        ifstream file2("diag16");
        while (getline(file2, line)){
            // cout<<line<<endl;
            diagonal1.pb(convert_to_vector(line));
        }
        file2.close();

        ifstream file3("diag26");
        while (getline(file3, line)){
            // cout<<line<<endl;
            diagonal2.pb(convert_to_vector(line));
        }
        file3.close();

        // cout<<vertical.size()<<endl;
        // for(auto u: vertical){
        //     for(auto v: u){
        //         cout<< v.first<<" "<<v.second<<" ";
        //     }
        //     cout<<endl;
        // }
    }

    // weights1 = {}
    // ifstream file("weights1");
    // double inp;
    // for(int i=0;i<16;i++){
    // 	file>>inp;
    // 	weights1.pb(inp);
    // }
    // file.close();
}


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
	no_of_moves=0;
	// game temp;
	// temp.initialize();
	int id,n,t,k;
	cin>>id>>n>>t>>k;
	nor = n;
	nom = k;
	init_diagonal();
	cin.ignore();
	game g;
	// g.print();
	AI player(id);
	int opponet_id=(id==1)?2:1;
	// cout<<opponet_id;
	string move;
	vector<moves> v;
	ofstream write;

		if(id == 1)
			write.open("features1");
		else
			write.open("features2");

	if(id==2){
		// cin>>move;
		getline(cin,move);
		v=convertToMyMove(move);
		for(int i=0;i<v.size();i++){
			g.performMove(v[i],opponet_id);
		}
	}
	while(!g.terminal()){
		if(g.terminal()){
			cerr << "Sucess exit"<<endl;
			break;
		}
		pair<vector<moves>,game> z= player.makeDecision(g);
		cout<<convertTo(z.first)<<endl;

		// double reward = 0;
		// if(id == 1){
		// 	reward += z.second.removedWhite - g.removedWhite;
		// 	reward += g.removedBlack - z.second.removedBlack;
		// 	if(z.second.removedWhite == 3){
		// 		reward = 10;
		// 	}
		// 	if(z.second.removedBlack == 3){
		// 		reward = -10;
		// 	}
		// }
		// else{
		// 	reward += z.second.removedBlack - g.removedBlack;
		// 	reward += g.removedWhite - z.second.removedWhite;
		// 	if(z.second.removedWhite == 3){
		// 		reward = -10;
		// 	}
		// 	if(z.second.removedBlack == 3){
		// 		reward = 10;
		// 	}
		// }


		g = z.second;

		// if(g.terminal()){
		// 	if(id == 1 && g.removedWhite == 3)
		// 		reward = 10;
		// 	else if(id == 1 && g.removedBlack == 3)
		// 		reward = -10;

		// 	if(id == 2 && g.removedBlack == 3)
		// 		reward = 10;
		// 	else if(id == 2 && g.removedWhite == 3)
		// 		reward = -10;
	
		// 	for(auto u: final_features_value){
		// 		write << u << " ";
		// 	}
		// 	write << reward << endl;

		// }

		// write << g.removedWhite << " " << g.removedBlack << " ";

		// cerr << g.removedWhite << " " << g.removedBlack << " ";
	
		// for(auto u: final_features_value){
		// 	write << u << " ";
		// 	cerr << u <<  " ";
		// }
		// write << reward << endl;
		// cerr << reward <<endl;

		if(g.terminal()){
			cerr << "Sucess exit"<<endl;
			break;
		}
		getline(cin,move);
		v=convertToMyMove(move);

		game xyz = g;

		for(int i=0;i<v.size();i++){
			xyz.performMove(v[i],opponet_id);
		}
		// double reward = 0;
		// if(id == 1){
		// 	reward += xyz.removedWhite - g.removedWhite;
		// 	reward += g.removedBlack - xyz.removedBlack;
		// 	if(xyz.removedWhite == 3){
		// 		reward = 10;
		// 	}
		// 	if(xyz.removedBlack == 3){
		// 		reward = -10;
		// 	}
		// }
		// else{
		// 	reward += xyz.removedBlack - g.removedBlack;
		// 	reward += g.removedWhite - xyz.removedWhite;
		// 	if(xyz.removedWhite == 3){
		// 		reward = -10;
		// 	}
		// 	if(xyz.removedBlack == 3){
		// 		reward = 10;
		// 	}
		// }

		g = xyz;

		// for(auto u: final_features_value){
		// 	write << u << " ";
		// 	cerr << u <<  " ";
		// }
		// write << reward << endl;
		// cerr << reward <<endl;
	}
	write.close();

	return 0;
}
