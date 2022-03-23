#include "thpe3.h"

int getRandom(int seed){
    static default_random_engine generator( seed );
    uniform_int_distribution<int> distribution(0,51);
    return distribution( generator );
}


void DrawHand(int Hand[], int seed){
    for(int i = 0; i < 5; i++){
        Hand[i] = getRandom(seed);//draws random numbers between 0 and 51
        
        for(int j = 0; j < i; j++){
            if(Hand[j] == Hand[i]){
                //if dupelicate then draw another card
                Hand[i] = getRandom(seed);
                j = -1;
            }
        }
    }
}
