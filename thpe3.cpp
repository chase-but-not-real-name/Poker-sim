#include "thpe3.h"

int getRandom(int seed){
    static default_random_engine generator( seed );
    uniform_int_distribution<int> distribution(0,51);
    return distribution( generator );
}

void DrawHand(int Hand[], int seed){
    for(int i = 0; i < 5; i++){
        Hand[i] = getRandom(seed);
        //draws random numbers between 0 and 51
        for(int j = 0; j < i; j++){
            if(Hand[j] == Hand[i]){
                //if dupelicate then draw another card
                Hand[i] = getRandom(seed);
                j = -1;
            }
        }
    }
}

void sort(int ArrayN[], const int size){
    //GOOD OLD BUBBLE SORT WOOOOOO MY FAVORITE (;
    bool swapMade = true;
    int i, j;
    for(i = 0; i < size - 1 && swapMade; i++){
        swapMade = false;
        for(j = 0; j < size - 1 - i; j ++){
            if( ArrayN[j] > ArrayN[j + 1] ){
                int temp = ArrayN[j];
                ArrayN[j] = ArrayN[j + 1];
                ArrayN[j + 1] = temp;
                swapMade = true;
            }
        }
    }
}
