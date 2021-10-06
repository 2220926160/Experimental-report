#include<iostream>

using namespace std;

class Book
{
    public:
        Book();
        Book(int w);
        // static int sumnum;
        static void dissumnum();
    private:
        int num;
        static int sumnum;
};

Book::Book()
{
    num = 0;
}
Book::Book(int w)
{
    num = w;
    sumnum -= w;
}

int Book::sumnum = 120;

void Book::dissumnum()
{
    cout<<Book::sumnum<<endl;
}

int main()
{
    
    Book b1(20);
    Book b2(70);
    // cout<<Book::sumnum<<endl;
    Book::dissumnum();

    return 0;
}