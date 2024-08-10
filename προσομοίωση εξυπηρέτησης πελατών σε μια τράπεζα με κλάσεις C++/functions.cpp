#include <iostream>
#include "bank.h"
using namespace std;

int i = 0;

const int K = 3;
const int L = 10;

void bank:: enter(void)
{
    if(check_to_open() == 1)
    {
        curr_serving++;
        cout << "A customer just entered!\n";
    }

    else
    {
        if(C1.is_open() == 0)
        {
            C1.open_cash();
            curr_serving++;
            cout << "A customer just entered!\n";
        }
        else if(C2.is_open() == 0)
        {
            C2.open_cash();
            curr_serving++;
            cout << "A customer just entered!\n";
        }
        else if(C3.is_open() == 0)
        {
            C3.open_cash();
            curr_serving++;
            cout << "A customer just entered!\n";
        }
        else if(C4.is_open() == 0)
        {
            C4.open_cash();
            curr_serving++;
            cout << "A customer just entered!\n";
        }
        else if(C5.is_open() == 0)
        {
            C5.open_cash();
            curr_serving++;
            cout << "A customer just entered!\n";
        }

        if(open_cashiers() == 5 && C1.is_free() == 0 && C2.is_free() == 0 &&  C3.is_free() == 0 && C4.is_free() == 0 && C5.is_free() == 0)
            cout << "\nSorry you cannot enter until some customers are served!\n";
    }
}

/////////////////////////////////////////////////////////////////////

void bank:: exit(void)
{
    last_customer++;

    if(check_to_close() == 1)
    {
        if(C1.is_open() == 1 && C1.is_free() == 1)
        {
            C1.close_cash();
            cout << "There are too many open cashiers so the first cashier will close!\n";
        }
        else if(C2.is_open() == 1 && C2.is_free() == 1)
        {
            C2.close_cash();
            cout << "There are too many open cashiers so the second cashier will close!\n";
        }
        else if(C3.is_open() == 1 && C3.is_free() == 1)
        {
            C3.close_cash();
            cout << "There are too many open cashiers so the third cashier will close!\n";
        }
        else if(C4.is_open() == 1 && C4.is_free() == 1)
        {
            C4.close_cash();
            cout << "There are too many open cashiers so the fourth cashier will close!\n";
        }
        else if(C5.is_open() == 1 && C5.is_free() == 1)
        {
            C5.close_cash();
            cout << "There are too many open cashiers so the fifth cashier will close!\n";
        }
    }
    if(serve() == 1)
        C1.free_cash();
    else if(serve() == 2)
        C2.free_cash();
    else if(serve() == 3)
        C3.free_cash();
    else if(serve() == 4)
        C4.free_cash();
    else if(serve() == 5)
       C5.free_cash();
}

/////////////////////////////////////////////////////////////////////

void bank:: open(int n)
{
    if(n == 1)
    {
        if(C1.is_open() == 1)
        {    
            cout << "The first cashier is already open!\n";
        }
        else 
        {
            C1.open_cash();
            cout << "The first cashier just opened!\n";
        }
    }

    if(n == 2)
    {
        if(C2.is_open() == 1)
        {
            cout << "The second cashier is already open!\n";
        }
        else
        {
            C2.open_cash();
            cout << "The second cashier just opened!\n";
        }
    }

    if(n == 3)
    {
        if(C3.is_open() == 1)
        {    
            cout << "The third cashier is already open!\n";
        }
        else
        {
            C3.open_cash();
            cout << "The third cashier just opened!\n";
        }
    }

    if(n == 4)
    {
        if(C4.is_open() == 1)
        {    
            cout << "The fourth cashier is already open!\n";
        }
        else
        {
            C4.open_cash();
            cout << "The fourth cashier just opened!\n";
        }
    }

    if(n == 5)
    {
        if(C5.is_open() == 1)
        {    
            cout << "The fifth cashier is already open!\n";
        }
        else
        {
            C5.open_cash();
            cout << "The fifth cashier just opened!\n";
        }
    }
}

/////////////////////////////////////////////////////////////////////

void bank:: close(int n)
{
    if(n == 1)
    {
        if(C1.is_open() == 0)
        {    
            cout << "The first cashier is already close!\n";
        }
        else
        {
            C1.close_cash();
            cout << "The first cashier just closed!\n";
        }
    }

    if(n == 2)
    {
        if(C2.is_open() == 0)
        {    
            cout << "The second cashier is already close!\n";
        }
        else
        {
            C2.close_cash();
            cout << "The second cashier just closed!\n";
        }
    }

    if(n == 3)
    {   
        if(C3.is_open() == 0)
        {    
            cout << "The third cashier is already close!\n";
        }
        else
        {
            C3.close_cash();
            cout << "The third cashier just closed!\n";
        }
    }

    if(n == 4)
    {
        if(C4.is_open() == 0)
        {    
            cout << "The fourth cashier is already close!\n";
        }
        else
        {
            C4.close_cash();
            cout << "The fourth cashier just closed!\n";
        }
    }

    if(n == 5)
    {
        if(C5.is_open() == 0)
        {    
            cout << "The fifth cashier is already close!\n";
        }
        else
        {
            C5.close_cash();
            cout << "The fifth cashier just closed!\n";
        }
    }
}

/////////////////////////////////////////////////////////////////////

int bank:: serve(void)
{
    if(open_cashiers() == 0) 
    {
        C1.open_cash();
        C1.serve_client();
        i = 1;
        cout << "Customer no: " << curr_serving << " by cashier no: " << i << endl;
    }

    else if(C1.is_open() == 1 && C1.is_free() == 1)
    {
        i = 1;
        C1.serve_client();
        cout << "Customer no: " << curr_serving << " by cashier no: " << i << endl;
    }

    else if(C2.is_open() == 1 && C2.is_free() == 1)
    {
        i = 2;
        C2.serve_client();
        cout << "Customer no: " << curr_serving << " by cashier no: " << i << endl;
    }

    else if(C3.is_open() == 1 && C3.is_free() == 1)
    {
        i = 3;
        C3.serve_client();
        cout << "Customer no: " << curr_serving << " by cashier no: " << i << endl;
    }

    else if(C4.is_open() == 1 && C4.is_free() == 1)
    {
        i = 4;
        C4.serve_client();
        cout << "Customer no: " << curr_serving << " by cashier no: " << i << endl;
    }

    else if(C5.is_open() == 1 && C5.is_free() == 1)
    {
        i = 5;
        C5.serve_client();
        cout << "Customer no: " << curr_serving << " by cashier no: " << i << endl;
    }
    else if(i == 0)
    {
        cout << "Customer no: " << curr_serving << " can not be served until another customer is served!" << endl;
    }

    return i;
}
