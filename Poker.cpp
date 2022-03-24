#include "Poker.h"

int getRandom(int seed)
{
    static default_random_engine generator( seed );
    uniform_int_distribution<int> distribution(0,51);
    return distribution( generator );
}

void DrawHand(int Hand[], int seed)
{
    for(int i = 0; i < 5; i++)
    {
        Hand[i] = getRandom(seed); //draws random numbers between 0 and 51
        for(int j = 0; j < i; j++)
        {
            if(Hand[j] == Hand[i])
            {
                //if dupelicate then draw another card
                Hand[i] = getRandom(seed);
                j = -1;
            }
        }
    }
}

void sort(int ArrayN[], const int size)
{
    //GOOD OLD BUBBLE SORT WOOOOOO MY FAVORITE (;
    bool swapMade = true;
    int i, j;
    for(i = 0; i < size - 1 && swapMade; i++)
    {
        swapMade = false;
        for(j = 0; j < size - 1 - i; j ++)
        {
            if( ArrayN[j] > ArrayN[j + 1] )
            {
                int temp = ArrayN[j];
                ArrayN[j] = ArrayN[j + 1];
                ArrayN[j + 1] = temp;
                swapMade = true;
            }
        }
    }
}

bool CheckRoyalFlush(int ArrayS[], int ArrayN[], const int size)
{
    if(ArrayN[4] != 12)
    {
        // checks if last card is a king else false
        return false;
    }
    else
    {
        for(int i = 1; i < size - 1; i++)
        {
            //checks if n+1 to n+4 is counting up else false
            int j = i + 1;
            if(ArrayN[i] + 1 != ArrayN[j])
            {
                return false;
            }
        }
        if(ArrayN[0] != 0)
        {
            // checks if first card is an ace else false
            return false;
        }
    }
    for(int i = 0; i < size - 1; i++)
    {
        int j = i + 1;
        if(ArrayS[i] != ArrayS[j])
        {
            //checks if all numbers have same suit value else false
            return false;
        }
    }
    return true;
}


bool CheckStraitFlush(int ArrayS[], int ArrayN[], const int size)
{
    int a = 0;
    for(int i = 0; i < size - 1; i++)
    {
        int j = i + 1;
        if(ArrayN[i] + 1 != ArrayN[j])
        {
            //checks if n to n+4 is counting up else false
            return false;
        }
    }
    for(int i = 0; i < size - 1; i++)
    {
        int j = i + 1;
        if(ArrayS[i] != ArrayS[j])
        {
            //checks if all numbers have same suit value else false
            return false;
        }
    }
    return true;
}


bool CheckFlush(int ArrayS[], const int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int j = i + 1;
        if(ArrayS[i] != ArrayS[j])
        {
            //checks if all numbers have same suit value else false
            return false;
        }
    }
    return true;
}


bool CheckStrait(int ArrayN[], const int size)
{
    if(ArrayN[4] == 12 && ArrayN[0] == 0)
    {
        //checks if first card is ace and last card is king
        for(int i = 1; i < size - 1; i++)
        {
            if(ArrayN[i] + 1 != ArrayN[i+1])
            {
                //checks if n to n+4 is counting up else false
                return false;
            }
        }
    }
    else
    {
        for(int i = 0; i < size - 1; i++)
        {
            if(ArrayN[i] + 1 != ArrayN[i+1])
            {
                //checks if n to n+4 is counting up else false
                return false;
            }
        }
    }
    return true;
}


bool CheckFourKind(int ArrayN[], const int size)
{
    int a = 0;
    int b = 0;
    bool c = true;
    for(int i = 0; i < size; i++)
    {
        int j = i + 1;
        if(ArrayN[i] == ArrayN[j] && c)
        {
            //compares and counts how many times it finds the name number
            a += 1;
        }
        else
        {
            //counting checker
            c = false;
            if (a == 0)
            {
                c = true;
            }
        }
    }
    if(a == 3)
    {
        //if compare counter = 3 then return true
        return true;
    }
    return false;
}


bool CheckFullHouse(int ArrayN[], const int size)
{
    int a = 0;
    int b = 0;
    bool c = true;
    for(int i = 0; i < size; i++)
    {
        int j = i + 1;
        if(ArrayN[i] == ArrayN[j] && c)
        {
            //compares and counts how many times it finds the name number
            a += 1;
        }
        else
        {
            //counting checker
            c = false;
            if (a == 0)
            {
                c = true;
            }
        }
        if(ArrayN[i] == ArrayN[j] && c == false)
        {
            b += 1;
        }
    }
    if(a == 1 && b == 2)
    {
        //if compare counter = 1 and second compare counter = 2 then return true
        return true;
    }
    if(a == 2 && b == 1)
    {
        //if compare counter = 2 and second compare counter = 1 then return true
        return true;
    }
    return false;
}


bool CheckThreeKind(int ArrayN[], const int size)
{
    int a = 0;
    int b = 0;
    bool c = true;
    for(int i = 0; i < size; i++)
    {
        int j = i + 1;
        if(ArrayN[i] == ArrayN[j] && c)
        {
            //compares and counts how many times it finds the name number
            a += 1;
        }
        else
        {
            //counting checker
            c = false;
            if (a == 0)
            {
                c = true;
            }
        }
    }
    if(a == 2)
    {
        //if compare counter = 2 then return true
        return true;
    }
    return false;
}


bool CheckTwoPair(int ArrayN[], const int size)
{
    int a = 0;
    int b = 0;
    bool c = true;
    for(int i = 0; i < size; i++)
    {
        int j = i + 1;
        if(ArrayN[i] == ArrayN[j] && c)
        {
            //compares and counts how many times it finds the name number
            a += 1;
        }
        else
        {
            //counting checker
            c = false;
            if (a == 0)
            {
                c = true;
            }
        }
        if(ArrayN[i] == ArrayN[j] && c == false)
        {
            b += 1;
        }
    }
    if(a == 1 && b == 1)
    {
        //if compare counter = 1 and second compare counter = 1 then return true
        return true;
    }
    return false;
}


bool CheckTwoKind(int ArrayN[], const int size)
{
    int a = 0;
    bool c = true;
    for(int i = 0; i < size; i++)
    {
        int j = i + 1;
        if(ArrayN[i] == ArrayN[j] && c)
        {
            //compares and counts how many times it finds the name number
            a += 1;
        }
        else
        {
            //counting checker
            c = false;
            if (a == 0)
            {
                c = true;
            }
        }
    }
    if(a == 1)
    {
        //if compare counter = 1 then return true
        return true;
    }
    return false;
}

int classifyHand(int Hand[], int num)
{
    int ArrayS[5];
    int ArrayN[5];
    for(int i = 0; i < num; i++)
    {
        //takes card value and splits it between card number and card suit
        int a = Hand[i];
        ArrayS[i] = a / 13;
        ArrayN[i] = a%13;
    }
    sort(ArrayN, num);//sorts number array so it could be compared easier
    if(CheckRoyalFlush( ArrayS, ArrayN, num))
    {
        return RoyalFlush;
    }
    else if(CheckStraitFlush( ArrayS, ArrayN, num))
    {
        return StraitFlush;
    }
    else if(CheckFourKind( ArrayN, num))
    {
        return FourKind;
    }
    else if(CheckFullHouse( ArrayN, num))
    {
        return FullHouse;
    }
    else if(CheckFlush( ArrayS, num))
    {
        return Flush;
    }
    else if(CheckStrait( ArrayN, num))
    {
        return Strait;
    }
    else if(CheckThreeKind( ArrayN, num))
    {
        return ThreeKind;
    }
    else if(CheckTwoPair( ArrayN, num))
    {
        return TwoPair;
    }
    else if(CheckTwoKind( ArrayN, num))
    {
        return TwoKind;
    }
    else
    {
        return HighCard;
    }
    return 0;
}
