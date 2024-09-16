#include <iostream>
#include <cstring>
using namespace std;

extern int N_max;

class book
{
    private:
        string title;
        string writer_name;
        int ISBN;
    
    public:
        book(int isbn = 1234, string tit = "abc", string writer = "abca") : ISBN(isbn), writer_name(writer), title(tit)
        {
            //cout << "I just constructed a book." << endl;
        }

        ~book()
        {
            title = { };
            writer_name = { };
            //cout << "I just deleted a book."<< endl;
        }

        void set_title(string tit)
        {
            title = tit;

            return;
        }

        void set_writer_name(string name)
        {
            writer_name = name;

            return;
        }

        void set_ISBN(int y)
        {
            ISBN = y;

            return;
        }

        string get_title() const
        {
            return title;
        }

        string get_writer_name() const
        {
            return writer_name;
        }

        int get_ISBN() const
        {
            return ISBN;
        }
};

/////////////////////////////////////////////////////////////////////

class self
{
    private:
        int number;
        book *Book;

    public:
        self(book *BOOK) : Book(BOOK)
        {
            Book = new book;
            number = N_max;
            Book = BOOK;
            //cout << "I just constructed a self.\n" << endl;
        }

        ~self( )
        {
            number = 0;
            //cout << "Deleting self.\n" << endl;
        }

        void set_number(int num)
        {
            number = num;

            return;
        }

        void set_book(book BOOK, int i)
        {
            Book[i] = BOOK;

            return;
        }

        int get_number(void) const
        {
            return number;
        }

        void get_book_ISBN2(book *BOOK) const
        {
            for(int i = 0; i < number; i++)
                cout << BOOK[i].get_ISBN( ) << " \\ ";
            cout << endl;
        }

        void get_book_title2(book *BOOK) const
        {
            for(int i = 0; i < number; i++)
                cout << BOOK[i].get_title( ) << " \\ ";
            cout << endl;
        }

        void get_book_writer_name2(book *BOOK) const
        {
            for(int i = 0; i < number; i++)
                cout << BOOK[i].get_writer_name( ) << " \\ ";
            cout << endl;
        }

        int get_book_ISBN(book BOOK) const
        {
            return BOOK.get_ISBN( );
        }

        string get_book_title(book BOOK) const
        {
            return BOOK.get_title( );
        }

        string get_book_writer_name(book BOOK) const
        {
            return BOOK.get_writer_name( );
        }

        void add(void)
        {
            number++;
        }

        void sub(void)
        {
            number--;
        }

        book* get_book(void) const
        {
            return Book;
        }
};

/////////////////////////////////////////////////////////////////////

class locker
{
    private:
        self Self4;
        self Self5;

    public:
        locker(self self4, self self5) : Self4(self4), Self5(self5)
        {
            //cout << "I just constructed a locker.\n" << endl; 
        }

        ~locker( )
        {
            //cout << "Deleting locker.\n" << endl;
        }

        void set_self(self self4, self self5)
        {
            Self4 = self4;
            Self5 = self5;

            return;
        }

        self get_self4(void) const
        {
            return Self4;
        }

        self get_self5(void) const
        {
            return Self5;
        }

        void add4(void)
        {
            Self4.add();
        }

        void add5(void)
        {
            Self5.add();
        }

        void sub4(void)
        {
            Self4.sub();
        }

        void sub5(void)
        {
            Self5.sub();
        }      
};

/////////////////////////////////////////////////////////////////////

class base
{
    private:
        bool initialized;

    public:
        base( )
        {
            initialized = true;
            //cout << "I just constructed a base.\n" << endl;
        }

        ~base( )
        {
            initialized = false;
            //cout << "I just deleted a base.\n" << endl;
        }
};

/////////////////////////////////////////////////////////////////////

class library
{
    private:
        base Base;
        locker Locker;
        self Self1;
        self Self2;
        self Self3;

    public:
        library(base BASE, locker LOCKER, self self1, self self2, self self3) :
        Base(BASE), Locker(LOCKER), Self1(self1), Self2(self2), Self3(self3)
        {
            cout << "I just constructed a library.\n" << endl;
        }

        ~library()
        {
            cout << "I just deleted a library.\n" << endl;
        }

        void set_base(base BASE)
        {
            Base = BASE;

            return; 
        }

        void set_locker(locker LOCKER)
        {
            Locker = LOCKER;

            return;
        }

        void set_self(self self1, self self2, self self3)
        {
            Self1 = self1;
            Self2 = self2;
            Self3 = self3;

            return;
        }

        base get_base(void) const
        {
            return Base;
        }

        locker get_locker(void) const
        {
            return Locker;
        }

        self get_self1(void) const
        {
            return Self1;
        }

        self get_self2(void) const
        {
            return Self2;
        }

        self get_self3(void) const
        {
            return Self3;
        }

        void place_book(book , int ,int );
        void take_book(book *, int ,int );
        void print(int ) const;
};

/////////////////////////////////////////////////////////////////////
