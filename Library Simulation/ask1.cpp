#include <iostream>
#include <cstring>
#include "library.h"
using namespace std;

int main(void)
{
    int N = 6;
    book Book_a1[N];
    book Book_a2[N];
    book Book_a3[N];
    book Book_a4[N];
    book Book_a5[N];

/////////////////////////////////////////////////////////////////////

    book BOOK(4568, "HYQP", "ABC DEF");
    book BOOK1(2451, "YENS", "ERA THE");
    book BOOK2(9063, "HYQP", "OQA BNW");
    base Base{ };
    self self1(Book_a1);
    self self2(Book_a2);
    self self3(Book_a3);
    self self4(Book_a4);
    self self5(Book_a5);
    
    locker Locker(self4, self5);
    library Library(Base, Locker, self1, self2, self3);

    Library.take_book(Book_a1, 2, 2);
    Library.place_book(BOOK, 2, 2);
    Library.take_book(Book_a1, 1, 1);
    Library.place_book(BOOK1, 1, 1);
    Library.take_book(Book_a1, 5, 3);
    Library.place_book(BOOK2, 4, 3);

    cout << "The higher bookcase self is: \n";
    Library.print(1);
    cout << "The middle bookcase self is: \n";
    Library.print(2);
    cout << "The lower bookcase self is: \n";
    Library.print(3);
    cout << "The higher locker self is: \n";
    Library.print(4);
    cout << "The lower locker self is: \n";
    Library.print(5);
    
    return 0;
}
