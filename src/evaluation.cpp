#include<game.h>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> features;

vector<int> game::get_features(int player){
    int s1[] = {0 ,0, 0, 0, 0, 0};
    int s2[] = {0 ,0, 0, 0, 0, 0};
    int r_m_1 = 0;
    int r_m_2 = 0;

    int count = 0, x, y;
    int opponent = (player==1)?2:1;
    int mymarker = (player == 1)?3:4;
    int oppmarker = (player == 1)?4:3;
    int white_marker = 3;
    int black_marker = 4;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
    bool b1 = 0, b2 = 0, b3 = 0, b4 = 0;
    // int k1 = k;
    for(auto u: vertical){
        count = 0;
        count1 = 0; count2 = 0; count3 = 0, count4 = 0;
        b1 = 0; b2 = 0;
        for(auto v: u){
	        // k markers in row
            x = v.first;
            y = v.second;
            if(state[x][y] == mymarker){
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
            if(state[x][y] == mymarker){
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

            // four m's and 1 ring // mine
            if(state[x][y] == mymarker){
            	count2++;
            }
            else if(state[x][y] == player && !b1){
            	count2++;
            	b1 = 1;
            }
            else{
            	count2 = 0;
            	b1 = 0;
            }
            if(count2 == nom){
            	r_m_1++;
            }
            // four m's and 1 ring // opponent
            if(state[x][y] == oppmarker){
            	count3++;
            }
            else if(state[x][y] == opponent && !b2){
            	count3++;
            	b2 = 1;
            }
            else{
            	count3 = 0;
            	b2 = 0;
            }
            if(count3 == nom){
            	r_m_2++;
            }
        }
    }

    for(auto u: diagonal1){
        count = 0;
        count1 = 0;
        count1 = 0; count2 = 0; count3 = 0;
        b1 = 0; b2 = 0;
        for(auto v: u){	
        	// k markers in row
            x = v.first;
            y = v.second;
            if(state[x][y] == mymarker){
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
            if(state[x][y] == oppmarker){
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

            // four m's and 1 ring // mine
            if(state[x][y] == mymarker){
            	count2++;
            }
            else if(state[x][y] == player && !b1){
            	count2++;
            	b1 = 1;
            }
            else{
            	count2 = 0;
            	b1 = 0;
            }
            if(count2 == nom){
            	r_m_1++;
            }
            // four m's and 1 ring // opponent
            if(state[x][y] == oppmarker){
            	count3++;
            }
            else if(state[x][y] == opponent && !b2){
            	count3++;
            	b2 = 1;
            }
            else{
            	count3 = 0;
            	b2 = 0;
            }
            if(count3 == nom){
            	r_m_2++;
            }
        }
    }

    for(auto u: diagonal2){
        count = 0;
        count1 = 0;
        count1 = 0; count2 = 0; count3 = 0;
        b1 = 0; b2 = 0;
        for(auto v: u){
        	// k markers in row
            x = v.first;
            y = v.second;
            if(state[x][y] == mymarker){
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
            if(state[x][y] == oppmarker){
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

            // four m's and 1 ring // mine
            if(state[x][y] == mymarker){
            	count2++;
            }
            else if(state[x][y] == player && !b1){
            	count2++;
            	b1 = 1;
            }
            else{
            	count2 = 0;
            	b1 = 0;
            }
            if(count2 == nom){
            	r_m_1++;
            }
            // four m's and 1 ring // opponent
            if(state[x][y] == oppmarker){
            	count3++;
            }
            else if(state[x][y] == opponent && !b2){
            	count3++;
            	b2 = 1;
            }
            else{
            	count3 = 0;
            	b2 = 0;
            }
            if(count3 == nom){
            	r_m_2++;
            }
        }
    }
    vector<int> ret;
    if(player == 1){
    	ret.pb(removedWhite);
    }
    else{
    	ret.pb(removedBlack);
    }
    for(int i=0;i<6;i++)
    	ret.pb(s1[i]);
	ret.pb(r_m_1);    
	if(player == 1){
    	ret.pb((1)*removedBlack);		
	}
	else{
		ret.pb((1)*removedWhite);
	}
    for(int i=0;i<6;i++)
    	ret.pb((1)*s2[i]);
    ret.pb(r_m_2);
    // }
    // else{
    // 	ret.pb(removedBlack);
	   //  for(int i=0;i<6;i++)
	   //  	ret.pb(s2[i]);
    // 	ret.pb((-1)*removedWhite);
	   //  for(int i=0;i<6;i++)
	   //  	ret.pb((-1)*s1[i]);
    // }
    return ret;
}

double game::eval(int player){
	features = get_features(player);

	double ret = 0;
	// if(player == 1){
		for(int i=0;i<16;i++)
			ret += features[i] * weights1[i];
	// }
	// else{
	// 	for(int i=0;i<16;i++)
	// 		ret += features[i] * weights1[i];
	// }

	return ret;
	// if(player == 1)
    // else
    // 	(weights[0]*removedBlack + weights[1]*removedWhite +weights[2]*features[6] + weights[8] *features[0] + weights[3]*features[7] + weights[9]*features[1] + weights[4]*features[8] + weights[10]*features[2] + weights[5]*features[9] + weights[11]*features[3] + weights[6]*features[10] + weights[12]*features[4] + weights[7]*features[11] + weights[13]*features[5]);
}