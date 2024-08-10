#include <cstring>
#include "creature.h"
using namespace std;

extern int R;
const int N = 10;

const char* good[26] = {"Good1", "Good2", "Good3", "Good4", "Good5", "Good6", "Good7", "Good8", "Good9", "Good10", "Good11", "Good12", "Good13", "Good14", "Good15", "Good16", "Good17", "Good18", "Good19", "Good20", "Good21", "Good22", "Good23", "Good24", "Good25", "Good26"};
const char* bad[26] = {"Bad1", "Bad2", "Bad3", "Bad4", "Bad5", "Bad6", "Bad7", "Bad8", "Bad9", "Bad10", "Bad11", "Bad12", "Bad13", "Bad14", "Bad15", "Bad16", "Bad17", "Bad18", "Bad19", "Bad20", "Bad21", "Bad22", "Bad23", "Bad24", "Bad25", "Bad26"};

class creature_society
{
    private:
        int number;
        creature *soc[N];

    public:
        creature_society(int r = R, int num = N) : number(num) 
        {
            for(int k = 0; k < N; k++)
                soc[k] = new creature;
            cout << "I just constructed a society!\n\n";

            if(r <= 3)
            {
                good_creature *soc_g[num];
                for(int k = 0; k < N; k++)
                    soc_g[k] = new good_creature(good[k]);
                for(int i = 0; i < num; i++)
                {   
                    soc[i] = soc_g[i];
                    soc[i]->set_flag(1);
                }
                cout << "I have constructed a society with " << N << " good creatures!\n";
            }

            else
            {
                bad_creature *soc_b[num];
                for(int k = 0; k < N; k++)
                    soc_b[k] = new bad_creature(bad[k]);
                for(int i = 0; i < num; i++)
                {    
                    soc[i] = soc_b[i];
                    soc[i]->set_flag(0);
                }
                cout << "I have constructed a society with " << N << " bad creatures!\n";
            }

        }
        ~creature_society(void) 
        {
            for(int k = 0; k < N; k++)
                delete soc[k];
            cout << "\nI just deleted a society!\n";
        }

///////////////////////////////////////////////////////////////////////////////////////////////////

        creature* get_soc(int i) const
        {
            return soc[i];
        }

        int get_number(void) const
        {
            return number;
        }

///////////////////////////////////////////////////////////////////////////////////////////////////

        int no_of_zobies(void) const
        {   
            int count = 0;
            for(int i = 0; i < number; i++) 
            {
                if(soc[i]->get_life() <= 0)
                    count++;
            }
            return count;
        }

        int no_of_good(void) const 
        {
            int count = 0;  
            for(int i = 0; i < number; i++)
            {
                if(soc[i]->get_flag() == 1)
                    count++;
            }

            return count;
        }

///////////////////////////////////////////////////////////////////////////////////////////////////

        void clone_next(int i)
        {
            soc[i]->clone(soc[i + 1]);
            if(i == number - 1)
            {
                soc[0] = soc[i];
            }
        }

        void clone_zobies(int i)
        {
            for(int k = i; k < number - 1; k++)
            {
                clone_next(k);
            }
            if(i == number - 1)
            {
                soc[0] = soc[i];
            }

        }

///////////////////////////////////////////////////////////////////////////////////////////////////

        void beat(int i)
        {
            soc[i]->beat();
        }

        void bless(int i)
        {
            soc[i]->bless();
            if(soc[i]->get_flag() == 1)
            {
                if(soc[i]->get_life() > good_thrsh)
                    clone_next(i);
            }
            else
            {
                if(soc[i]->get_life() > bad_thrsh)
                    clone_zobies(i);
            }
        }
};