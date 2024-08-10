#include <iostream>
#include "bank.h"
using namespace std;

int main(void)
{
    cashier c1{ }; 
    cashier c2{ }; 
    cashier c3{ }; 
    cashier c4{ }; 
    cashier c5{ }; 

    bank Bank(c1, c2, c3, c4, c5);
    cout << Bank.open_cashiers() << " are the open cashiers!\n";
    cout << Bank.waiting_customers() << " customers are waiting!\n";
    
    Bank.enter();
    Bank.serve();
    Bank.exit();
    Bank.enter();
    Bank.serve();
    Bank.enter();
    Bank.serve();
    Bank.enter();
    Bank.serve();
    Bank.enter();
    Bank.serve();
    Bank.exit();

    Bank.enter();
    Bank.serve();
    Bank.exit();
    Bank.exit();
    Bank.enter();
    Bank.serve();
    Bank.enter();
    Bank.serve();
    Bank.enter();
    Bank.serve();

    cout << "\n" << Bank.open_cashiers() << " are the open cashiers!\n";
    
    return 0;
}
