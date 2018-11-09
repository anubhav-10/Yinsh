#include<game.h>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> features;

vector<int> game::get_features(){
    int s1[] = {0 ,0, 0, 0, 0, 0};
    int s2[] = {0 ,0, 0, 0, 0, 0};

    int count = 0, x, y;
    int white_marker = 3;
    int black_marker = 4;
    int count1 = 0;
    // int k1 = k;
    for(auto u: vertical){
        count = 0;
        count1 = 0;
        for(auto v: u){
            x = v.first;
            y = v.second;
            if(state[x][y] == white_marker){
                count++;
            }
            else{
                s1[count-1]++;
                count = 0;
            }
            if(count == nom){
                s1[count-1]++;
                count--;
            }
            // opponent
            if(state[x][y] == black_marker){
                count1++;
            }
            else{
                s2[count1-1]++;
                count1 = 0;
            }
            if(count1 == nom){
                s2[count1-1]++;
                count1--;
            }
        }
    }

    for(auto u: diagonal1){
        count = 0;
        count1 = 0;
        for(auto v: u){
            x = v.first;
            y = v.second;
            if(state[x][y] == white_marker){
                count++;
            }
            else{
                s1[count-1]++;
                count = 0;
            }

            if(count == nom){
                s1[count-1]++;
                count--;
            }
            // opponent
            if(state[x][y] == black_marker){
                count1++;
            }
            else{
                s2[count1-1]++;
                count1 = 0;
            }
            if(count1 == nom){
                s2[count1-1]++;
                count1--;
            }
        }
    }

    for(auto u: diagonal2){
        count = 0;
        count1 = 0;
        for(auto v: u){
            x = v.first;
            y = v.second;
            if(state[x][y] == white_marker){
                count++;
            }
            else{
                s1[count-1]++;
                count = 0;
            }

            if(count == nom){
                s1[count-1]++;
                count--;
            }
            // opponent
            if(state[x][y] == black_marker){
                count1++;
            }
            else{
                s2[count1-1]++;
                count1 = 0;
            }
            if(count1 == nom){
                s2[count1-1]++;
                count1--;
            }
        }
    }
    vector<int> ret(s1, s1 + 6);
    for(int i=0;i<6;i++)
    	ret.pb(s2[i]);
    return ret;
}

double game::eval(int player){
	features = get_features();

    return pow(-1,player+1)*(weights[0]*removedWhite-weights[1]*removedBlack +weights[2]*features[0]- weights[8] *features[6] + weights[3]*features[1]-weights[9]*features[7] + weights[4]*features[2]-weights[10]*features[8] + weights[5]*features[3]-weights[11]*features[9] + weights[6]*features[4]-weights[12]*features[10] + weights[7]*features[5]-weights[13]*features[11]);
}