#include <iostream>
#include "society.h"

using namespace std;

int L = 0;
int R = 2;
int R1 = 5;
int good_thrsh = 0;
int bad_thrsh = 0;

int main(void)
{   
    int M;
    cout << "Give M: ";
    cin >> M;
    cout << endl;

    cout << "Give the life of a creature: ";
    cin >> L;
    cout << endl;
    while(L <= 0) 
    {
        cout << "The life must be a positive number give it again: ";
        cin >> L;
        cout << endl;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "Give the good_thrsh: ";
    cin >> good_thrsh;
    cout << endl;

///////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "Give the bad_thrsh: ";
    cin >> bad_thrsh;
    cout << endl;

///////////////////////////////////////////////////////////////////////////////////////////////////

    creature_society Society(R);

///////////////////////////////////////////////////////////////////////////////////////////////////

    if(R1 < 4)
    {
        for(int i = 0; i < M; i++)
            Society.beat(R1);
        cout << "A creature is beat " << M << " times!\n";
    }
    else
    {
        for(int i = 0; i < M; i++)
            Society.bless(R1);
        cout << "A creature is blessed " << M << " times!\n";
    }

///////////////////////////////////////////////////////////////////////////////////////////////////

    int k = Society.no_of_zobies();
    cout << endl << "There are: " << k << " zobies in the society!" << endl;
    int j = Society.no_of_good();
    cout << "There are: " << j << " good creatures in the society!" << endl << endl;

///////////////////////////////////////////////////////////////////////////////////////////////////

    if(j == Society.get_number())
        cout << "Good Dominates in the World!\n" << endl;
    else if(k == Society.get_number())
        cout << "This is a dead society!\n" << endl;
    else
        cout << "Try again to improve the world!\n" << endl;
}