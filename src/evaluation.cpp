#include<game.h>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> features;

vector<int> game::get_features(int player){
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
    double white_mobility = mobilityScore(1);
    double black_mobility = mobilityScore(2);
    vector<int> ret;
    if(player == 1){
    	ret.pb(removedWhite);
	    for(int i=0;i<6;i++)
	    	ret.pb(s1[i]);
	    ret.pb(white_mobility);
    	ret.pb(removedBlack);
	    for(int i=0;i<6;i++)
	    	ret.pb(s2[i]);
	    ret.pb(black_mobility);
    }
    else{
    	ret.pb(removedBlack);
	    for(int i=0;i<6;i++)
	    	ret.pb(s2[i]);
	    ret.pb(black_mobility);
    	ret.pb(removedWhite);
	    for(int i=0;i<6;i++)
	    	ret.pb(s1[i]);
	    ret.pb(white_mobility);
    }
    return ret;
}

double game::eval(int player){
	features = get_features(player);

	double ret = 0;
	if(player == 1){
		for(int i=0;i<16;i++)
			ret += features[i] * weights1[i];
	}
	else{
		for(int i=0;i<16;i++)
			ret += features[i] * weights2[i];
	}

	return ret;
	// if(player == 1)
    // else
    // 	(weights[0]*removedBlack + weights[1]*removedWhite +weights[2]*features[6] + weights[8] *features[0] + weights[3]*features[7] + weights[9]*features[1] + weights[4]*features[8] + weights[10]*features[2] + weights[5]*features[9] + weights[11]*features[3] + weights[6]*features[10] + weights[12]*features[4] + weights[7]*features[11] + weights[13]*features[5]);
}