#include <iostream>
#include "library.h"
using namespace std;

int N_max = 6;

void library:: place_book(book Book, int n, int k)
{
    if(n == 1)
    {   
        if(Self1.get_number() == N_max)
        {    
            cout << "Shelf is full!\n" << endl;
        }
        else
        {
            Self1.set_book(Book, k);
            Self1.add();
            cout << "Placing a book in higher bookcase self\n\n";
        }
    }

    if(n == 2)
    {
        if(Self2.get_number() == N_max)
        {    
            cout << "Shelf is full!\n" << endl;
        }
        else
        {
            Self2.set_book(Book, k);
            Self2.add();
            cout << "Placing a book in middle bookcase self\n\n";
        }
    }

    if(n == 3)
    {
        if(Self3.get_number() == N_max)
        {    
            cout << "Shelf is full!\n" << endl;
        }
        else
        {
            Self3.set_book(Book, k);
            Self3.add();
            cout << "Placing a book in lower bookcase self\n\n";
        }
    }

    if(n == 4)
    {
        if(get_locker().get_self4().get_number() == N_max)
        {
            cout << "Shelf is full!\n" << endl;
        }
        else
        {
            get_locker().get_self4().set_book(Book, k);
            get_locker().add4();
            cout << "Placing a book in higher locker self\n\n";
        }
    }

    if(n == 5)
    {
        if(get_locker().get_self5().get_number() == N_max)
        {   
            cout << "Shelf is full!\n" << endl; 
        }
        else
        {   
            get_locker().get_self5().set_book(Book, k);
            get_locker().add5();
            cout << "Placing a book in lower locker self\n\n";
        }
    }
}

void library:: take_book(book *BOOK, int n, int i) 
{
    book BOOK1(0, "EMPTY", "EMPTY");
    if(n == 1)
    {
        if(Self1.get_number() == 0)
        {    
            cout << "Shelf is empty!\n\n";
        }
        else
        {
            int y = Self1.get_book_ISBN(BOOK[i]);
            string tit = Self1.get_book_title(BOOK[i]);
            string name = Self1.get_book_writer_name(BOOK[i]);
            Self1.set_book(BOOK1, i);
            Self1.sub();
            cout << "Removing a book ,from higher bookcase self, its isbn is: " << y;
            cout << " ,its title is:" << " ' " << tit << " ' ";
            cout << ",its writer's name is:" << " ' " << name << " ' \n" << endl;
        }
    }

    if(n == 2)
    {
        if(Self2.get_number() == 0)
        {    
            cout << "Shelf is empty!\n\n";
        }
        else
        {
            int y = Self2.get_book_ISBN(BOOK[i]);
            string tit = Self2.get_book_title(BOOK[i]);
            string name = Self2.get_book_writer_name(BOOK[i]);
            Self2.set_book(BOOK1, i);
            Self2.sub();
            cout << "Removing a book ,from middle bookcase self, its isbn is: " << y;
            cout << " ,its title is:" << " ' " << tit << " ' ";
            cout << ",its writer's name is:" << " ' " << name << " ' \n" << endl;
        }

    }

    if(n == 3)
    {
        if(Self3.get_number() == 0)
        {    
            cout << "Shelf is empty!\n\n";
        }
        else
        {
            int y = Self3.get_book_ISBN(BOOK[i]);
            string tit = Self3.get_book_title(BOOK[i]);
            string name = Self3.get_book_writer_name(BOOK[i]);
            Self3.set_book(BOOK1, i);
            Self3.sub();
            cout << "Removing a book ,from lower bookcase self, its isbn is: " << y;
            cout << " ,its title is:" << " ' " << tit << " ' ";
            cout << ",its writer's name is:" << " ' " << name << " ' \n" << endl;
        }
    }

    if(n == 4)
    {
        if(get_locker().get_self4().get_number() == 0)
        {    
            cout << "Shelf is empty!\n\n";
        }
        else
        {
            int y = get_locker().get_self4().get_book_ISBN(BOOK[i]);
            string tit = get_locker().get_self4().get_book_title(BOOK[i]);
            string name = get_locker().get_self4().get_book_writer_name(BOOK[i]);
            get_locker().get_self4().set_book(BOOK1, i);
            get_locker().sub4();
            cout << "Removing a book ,from higher locker self, its isbn is: " << y;
            cout << " ,its title is:" << " ' " << tit << " ' ";
            cout << ",its writer's name is:" << " ' " << name << " ' \n" << endl;
        }
    }

    if(n == 5)
    {
        if(get_locker().get_self5().get_number() == 0)
        {    
            cout << "Shelf is empty!\n\n";
        }
        else
        {
            int y = get_locker().get_self5().get_book_ISBN(BOOK[i]);
            string tit = get_locker().get_self5().get_book_title(BOOK[i]);
            string name = get_locker().get_self5().get_book_writer_name(BOOK[i]);
            get_locker().get_self5().set_book(BOOK1, i);
            get_locker().sub5();
            cout << "Removing a book ,from lower locker self, its isbn is: " << y;
            cout << " ,its title is:" << " ' " << tit << " ' ";
            cout << ",its writer's name is:" << " ' " << name << " ' \n" << endl;
        }
    }
}

void library:: print(int n) const
{
    if(n == 1)
    {
        cout << "The ISBN is: ";
        Self1.get_book_ISBN2(Self1.get_book());
        cout << "The title is: ";
        Self1.get_book_title2(Self1.get_book());
        cout << "The writer name is: ";
        Self1.get_book_writer_name2(Self1.get_book());
        cout  << endl;
    }

    if(n == 2)
    {
        cout << "The ISBN is: ";
        Self2.get_book_ISBN2(Self2.get_book());
        cout << "The title is: ";
        Self2.get_book_title2(Self2.get_book());
        cout << "The writer name is: ";
        Self2.get_book_writer_name2(Self2.get_book());
        cout  << endl;
    }

    if(n == 3)
    {
        cout << "The ISBN is: ";
        Self3.get_book_ISBN2(Self3.get_book());
        cout << "The title is: ";
        Self3.get_book_title2(Self3.get_book());
        cout << "The writer name is: ";
        Self3.get_book_writer_name2(Self3.get_book());
        cout  << endl;
    }

    if(n == 4)
    {
        cout << "The ISBN is: ";
        get_locker().get_self4().get_book_ISBN2(get_locker().get_self4().get_book());
        cout << "The title is: ";
        get_locker().get_self4().get_book_title2(get_locker().get_self4().get_book());
        cout << "The writer name is: ";
        get_locker().get_self4().get_book_writer_name2(get_locker().get_self4().get_book());
        cout  << endl;
    }

    if(n == 5)
    {
        cout << "The ISBN is: ";
        get_locker().get_self5().get_book_ISBN2(get_locker().get_self5().get_book());
        cout << "The title is: ";
        get_locker().get_self5().get_book_title2(get_locker().get_self5().get_book());
        cout << "The writer name is: ";
        get_locker().get_self5().get_book_writer_name2(get_locker().get_self5().get_book());
        cout  << endl;
    }
}
