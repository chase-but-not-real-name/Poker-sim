#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "Poker.h"
const bool RUNCATCH = true;

int main( int argc, char **argv)
{
    Catch::Session session;
    int result;
    if( RUNCATCH )
    {
        result = session.run();
        if( result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }
    int seed;
    int size = 0;
    int b;
    bool isseed = false;
    bool isfile = false;
    bool zero = false;
    if(argc != 4)
    {
        cout << "Invalid Option" << endl;
        return 0;
    }
    if(strcmp (argv[1], "-s") == 0)
    {
        seed = (stoi (argv[2]));
        size = (stoi (argv[3]));
        isseed = true;
        if(size <= 0)
        {
            zero = true;
        }
    }
    else if(strcmp (argv[1], "-f") == 0)
    {
        isfile = true;
    }
    else
    {
        cout << "Invalid Option" << endl;
        return 0;
    }
    double count[9];
    for(int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    if(isfile)
    {
        string Input = argv[2];
        ifstream fin;
        string Output = argv[3];
        ofstream fout;
        fin.open(Input);
        if(!fin.is_open())
        {
            cout << "Unable to open file: " << argv[2] << endl;
            return 0;
        }
        while(!fin.eof())
        {
            int Hand[5];
            for(int i = 0; i < 5; i++)
            {
                int x;
                fin >> x;
                Hand[i] = x;
            }
            b = classifyHand(Hand, 5);
            count[b] += 1;
            size += 1;
        }
        count[b] -= 1;
        size -= 1;
        if(size <= 0)
        {
            zero = true;
        }
        fin.close();
        
        fout.open(Output);
        if(!fout.is_open())
        {
            cout << "Unable to open file: " << argv[3] << endl;
            return 0;
        }
        if(zero)
        {
            size = 1;
        }
        fout.precision(6);
        fout << setw(20) << left << "Hand Name" << right << setw(10) << "Dealt"
        << setw(15) << "Chance" << endl;
        
        fout << setw(20) << left << "Royal Flush" << right << setw(10) << count[9]
        << setw(15) << fixed << (count[9] / size) * 100 << "%" << defaultfloat << endl;
        
        fout << setw(20) << left << "Straight Flush" << right << setw(10) << count[8]
        << setw(15) << fixed << (count[8] / size) * 100 << "%" << defaultfloat << endl;
        
        fout << setw(20) << left << "Four of a Kind" << right << setw(10) << count[7] 
        << setw(15) << fixed << (count[7] / size) * 100 << "%" << defaultfloat << endl;
        
        fout << setw(20) << left << "Full House" << right << setw(10) << count[6] 
        << setw(15) << fixed << (count[6] / size) * 100 << "%" << defaultfloat << endl;
        
        fout << setw(20) << left << "Flush" << right << setw(10) << count[5] 
        << setw(15) << fixed << (count[5] / size) * 100 << "%" << defaultfloat << endl;
        
        fout << setw(20) << left << "Straights" << right << setw(10) << count[4]
        << setw(15) << fixed << (count[4] / size) * 100 << "%" << defaultfloat << endl;
        
        fout << setw(20) << left << "Three of a Kind" << right << setw(10) << count[3] 
        << setw(15) << fixed << (count[3] / size) * 100 << "%" << defaultfloat << endl;
        
        fout << setw(20) << left << "Two Pair" << right << setw(10) << count[2] 
        << setw(15) << fixed << (count[2] / size) * 100 << "%" << defaultfloat << endl;
        
        fout << setw(20) << left << "Two of a kind" << right << setw(10) << count[1] 
        << setw(15) << fixed << (count[1] / size) * 100 << "%" << defaultfloat << endl;
        
        fout << setw(20) << left << "High Card" << right << setw(10) << count[0] 
        << setw(15) << fixed << (count[0] / size) * 100 << "%" << defaultfloat << endl;
        if(zero)
        {
            size = 0;
        }
        fout << setw(20) << left << "Total Hands Dealt" << right << setw(10) << size
        << endl;
        fout.close();
    }
    
    if(isseed)
    {
        for(int i = 0; i < size; i++)
        {
            int Hand[5];
            DrawHand(Hand, seed);
            b = classifyHand(Hand, 5);
            count[b] += 1;
        }
        if(zero)
        {
            size = 1;
        }
        cout.precision(6);
        cout << setw(20) << left << "Hand Name" << right << setw(10) << "Dealt"
        << setw(15) << "Chance" << endl;

        cout << setw(20) << left << "Royal Flush" << right << setw(10) << count[9]
        << setw(15) << fixed << (count[9] / size) * 100 << "%" << defaultfloat << endl;
        
        cout << setw(20) << left << "Straight Flush" << right << setw(10) << count[8]
        << setw(15) << fixed << (count[8] / size) * 100 << "%" << defaultfloat << endl;
        
        cout << setw(20) << left << "Four of a Kind" << right << setw(10) << count[7] 
        << setw(15) << fixed << (count[7] / size) * 100 << "%" << defaultfloat << endl;
        
        cout << setw(20) << left << "Full House" << right << setw(10) << count[6] 
        << setw(15) << fixed << (count[6] / size) * 100 << "%" << defaultfloat << endl;
        
        cout << setw(20) << left << "Flush" << right << setw(10) << count[5] 
        << setw(15) << fixed << (count[5] / size) * 100 << "%" << defaultfloat << endl;
        
        cout << setw(20) << left << "Straights" << right << setw(10) << count[4]
        << setw(15) << fixed << (count[4] / size) * 100 << "%" << defaultfloat << endl;
        
        cout << setw(20) << left << "Three of a Kind" << right << setw(10) << count[3] 
        << setw(15) << fixed << (count[3] / size) * 100 << "%" << defaultfloat << endl;
        
        cout << setw(20) << left << "Two Pair" << right << setw(10) << count[2] 
        << setw(15) << fixed << (count[2] / size) * 100 << "%" << defaultfloat << endl;
        
        cout << setw(20) << left << "Two of a kind" << right << setw(10) << count[1] 
        << setw(15) << fixed << (count[1] / size) * 100 << "%" << defaultfloat << endl;
        
        cout << setw(20) << left << "High Card" << right << setw(10) << count[0] 
        << setw(15) << fixed << (count[0] / size) * 100 << "%" << defaultfloat << endl << endl;
        if(zero)
        {
            size = 0;
        }
        cout << setw(20) << left << "Total Hands Dealt" << right << setw(10) << size
        << endl;
    }
    return 0;
}