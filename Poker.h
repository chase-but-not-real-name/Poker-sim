<<<<<<< HEAD:Poker.h
#pragma once
#include <fstream>
#include <iostream>
#include <random>

using namespace std;

void sort(int ArrayN[], const int size);

const int RoyalFlush = 9;   //RoyalFlush is assigned the number 9 for classifyHand
const int StraitFlush = 8;  //StraitFlush is assigned the number 8 for classifyHand
const int FourKind = 7;     //FourKind is assigned the number 7 for classifyHand
const int FullHouse = 6;    //FullHouse is assigned the number 6 for classifyHand
const int Flush = 5;        //Flush is assigned the number 5 for classifyHand
const int Strait = 4;       //Strait is assigned the number 4 for classifyHand
const int ThreeKind = 3;    //ThreeKind is assigned the number 3 for classifyHand
const int TwoPair = 2;      //TwoPair is assigned the number 2 for classifyHand
const int TwoKind = 1;      //TwoKind is assigned the number 1 for classifyHand
const int HighCard = 0;     //HighCard is assigned the number 0 for classifyHand


bool CheckRoyalFlush(int ArrayS[], int ArrayN[], const int size);
bool CheckStraitFlush(int ArrayS[], int ArrayN[], const int size);
bool CheckFourKind(int ArrayN[], const int size);
bool CheckFullHouse(int ArrayN[], const int size);
bool CheckFlush(int ArrayS[], const int size);
bool CheckStrait(int ArrayN[], const int size);
bool CheckThreeKind(int ArrayN[], const int size);
bool CheckTwoPair(int ArrayN[], const int size);
bool CheckTwoKind(int ArrayN[], const int size);

int getRandom(int seed);
void DrawHand(int Hand[], int seed);
int classifyHand(int Hand[], int num);
=======
#pragma once
#include <fstream>
#include <iostream>
#include <random>

using namespace std;

void sort(int ArrayN[], const int size);

const int RoyalFlush = 9;   //RoyalFlush is assigned the number 9 for classifyHand
const int StraitFlush = 8;  //StraitFlush is assigned the number 8 for classifyHand
const int FourKind = 7;     //FourKind is assigned the number 7 for classifyHand
const int FullHouse = 6;    //FullHouse is assigned the number 6 for classifyHand
const int Flush = 5;        //Flush is assigned the number 5 for classifyHand
const int Strait = 4;       //Strait is assigned the number 4 for classifyHand
const int ThreeKind = 3;    //ThreeKind is assigned the number 3 for classifyHand
const int TwoPair = 2;      //TwoPair is assigned the number 2 for classifyHand
const int TwoKind = 1;      //TwoKind is assigned the number 1 for classifyHand
const int HighCard = 0;     //HighCard is assigned the number 0 for classifyHand


bool CheckRoyalFlush(int ArrayS[], int ArrayN[], const int size);
bool CheckStraitFlush(int ArrayS[], int ArrayN[], const int size);
bool CheckFourKind(int ArrayN[], const int size);
bool CheckFullHouse(int ArrayN[], const int size);
bool CheckFlush(int ArrayS[], const int size);
bool CheckStrait(int ArrayN[], const int size);
bool CheckThreeKind(int ArrayN[], const int size);
bool CheckTwoPair(int ArrayN[], const int size);
bool CheckTwoKind(int ArrayN[], const int size);

int getRandom(int seed);
void DrawHand(int Hand[], int seed);
int classifyHand(int Hand[], int num);
>>>>>>> e2b4d4eb940a9710d7ef07876d5267b4aee4c6a5:thpe3.h
