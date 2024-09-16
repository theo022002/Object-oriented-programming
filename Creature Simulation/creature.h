#include <cstring>
using namespace std;

extern int L;
extern int good_thrsh;
extern int bad_thrsh;

class creature 
{
    protected:
        char* name;
        int life;
        bool flag; 

    public:
        creature(const char *n = "ahjk", int l = L) : life(l)
        {   
            name = new char[strlen(n) + 1];
            strcpy(name, n);
            //cout << "I just constructed a creature!" << endl;
        }

        creature(const creature& cr)
        {
            name = new char[strlen(cr.name) + 1];
            strcpy(name, cr.name);
            life = cr.life;
        }

        creature& operator=(const creature& cr)
        {
            if (this != &cr) 
            {
                delete[] name;
                name = new char[strlen(cr.name) + 1];
                strcpy(name, cr.name);
                life = cr.life;
            }
            return *this;
        }

        ~creature(void)
        {
            //cout << "Deleting creature with name: " << name << endl ;
            delete[] name;
        }

///////////////////////////////////////////////////////////////////////////////////////////////////

        int get_life(void) const
        {
            return life;
        }

        char* get_name(void) const
        {
            return name;
        }

        int get_flag(void) const
        {
            return flag;
        }

        void set_flag(int a)
        {
            flag = a;
        }

///////////////////////////////////////////////////////////////////////////////////////////////////

        int is_a_zobbie(void) const
        {
            if(life <= 0)
            {
                cout << "The creature is a zobbie!\n";
                return 1;
            }
            else
            {
                cout << "The creature is not a zobbie!\n";
                return 0;
            }
        }

        virtual int is_a_good(void)
        {
            return -1;
        }

///////////////////////////////////////////////////////////////////////////////////////////////////

        void clone(creature* c1)
        {
            delete[] c1->name;
            c1->name = new char[strlen(name) + 1];
            strcpy(c1->name, name);
            delete[] name;
            name = new char[strlen(c1->name) + 1];
            strcpy(name, " ");

            c1->life = life;
            life = 0;

            cout << "A creature just cloned!\n";
        }

///////////////////////////////////////////////////////////////////////////////////////////////////

        void bless(void)
        {
            if(life != 0)
                life++;
        }

        void beat(void)
        {
            if(life != 0)
                life--;
        }
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class good_creature : public creature
{
    public:
    good_creature(const char* n = "bbb") : creature(n)
    {
        flag = 1; 
        //cout << "I just created a good creature!" << endl;
    }

    good_creature(const good_creature& cr) : creature(cr)
    {
        flag = 1; 
        //cout << "I just created a good creature by Copying!" << endl;
    }

    ~good_creature(void)
    { 
        //cout << "Destroynig a good creature!" << endl; 
    }

///////////////////////////////////////////////////////////////////////////////////////////////////

    int is_a_good(void) const
    {
        if(flag == 1)
            return 1;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class bad_creature : public creature
{
    public:
    bad_creature(const char* n = "aaa") : creature(n)
    {
        flag = 0; 
        //cout << "I just created a bad creature!" << endl;
    }

    bad_creature(const bad_creature& cr) : creature(cr)
    {
        flag = 0; 
        //cout << "I just created a bad creature by Copying!" << endl;
    }

    ~bad_creature(void)
    { 
        //cout << "Destroynig a bad creature!" << endl; 
    }

///////////////////////////////////////////////////////////////////////////////////////////////////

    int is_a_good(void) const
    {
        if(flag == 0)
            return 0;
    }
};