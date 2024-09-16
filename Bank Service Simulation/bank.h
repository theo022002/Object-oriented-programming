#include <iostream>
using namespace std;

extern const int K;
extern const int L;

class cashier
{
    private:
        bool open_flag;
        bool serving_flag;
        int customers_served;

    public:
        cashier(void) 
        {
            open_flag = false;
            serving_flag = false;
            customers_served = 0;

            //cout << "I just constructed a cashier!\n";
        }

        ~cashier(void)
        {
            open_flag = false;
            serving_flag = false;
            customers_served = 0;

            //cout << "I just deleted a cashier!\n";
        }

        void open_cash(void) 
        {
            open_flag = true;
            customers_served = 0;

            return;
        }

        void close_cash(void)
        {
            open_flag = false;

            return;
        }

        void serve_client(void)
        {
            serving_flag = true;

            return;
        }

        int free_cash(void)
        {
            serving_flag = false;
            customers_served++;

            if(customers_served == L)
            {
                close_cash();
                cout << "The cashier will close because it overworked!\n";
                return 0;
            }

            return 1;
        }

        int is_open(void) const
        {
            if(open_flag == true) 
            {
                //cout << "The cashier is open!\n";
                return 1;
            }
            else
            {
                //cout << "The cashier is close!\n";
                return 0;
            }
        }

        int is_free(void) const
        {
            if(serving_flag == false) 
            { 
                //cout << "The cashier is free!\n";
                return 1;
            }
            else 
            {
               //cout << "The cashier is not free!\n";
                return 0;
            }
        }
};

class bank 
{
    private:
        cashier C1;
        cashier C2;
        cashier C3;
        cashier C4;
        cashier C5;
        int last_customer;
        int curr_serving;

    public:
    bank(cashier cash1, cashier cash2, cashier cash3, cashier cash4, cashier cash5) :
    C1(cash1), C2(cash2), C3(cash3), C4(cash4), C5(cash5)
    {   
        curr_serving = 0;
        last_customer = 1;
        C1.open_cash( );
        C1.free_cash( );

        cout << "I just constructed a bank!\n\n";
    }

    ~bank(void)
    {
        curr_serving = 0;
        last_customer = 0;
        C1.close_cash( );
        C2.close_cash( );
        C3.close_cash( );
        C4.close_cash( );
        C5.close_cash( );

        cout << "\nI just destroy a bank!\n";
    }

    int check_to_open(void) const 
    {
        int x = last_customer - curr_serving;
        int open = open_cashiers();

        if(x > open*K)
            return 1;
        else 
            return 0;
    }

    int check_to_close(void) const
    {
        int x = last_customer - curr_serving;
        int y = open_cashiers() - 1;

        if(x <= y*K)
            return 1;
        else 
            return 0;
    }

    int waiting_customers(void) const 
    {
        return (last_customer - curr_serving);
    }

    int open_cashiers(void) const
    {
        int count = 0;
        if(C1.is_open() == 1)
            count++;
        if(C2.is_open() == 1)
            count++;
        if(C3.is_open() == 1)
            count++;
        if(C4.is_open() == 1)
            count++;
        if(C5.is_open() == 1)
            count++;
        
        return count;
    }

    void enter(void);
    int serve(void);
    void exit(void);
    void open(int n);
    void close(int n);
};
