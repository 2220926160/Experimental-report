#include<iostream>

using namespace std;

float PI=3.14;

class Book
{
    public:
        Book();
        Book(float);
        void area();
        void display();
    private:
        float radius, S;  // 半径
};

Book::Book()
{
    radius = 0;
}
Book::Book(float x)
{
    radius = x;
}
void Book::area()
{
    S = PI * radius * radius;
    display();
}
void Book::display()
{
    cout<<"半径为"<<radius<<"的圆的面积为"<<S<<endl;
}

int main()
{
    
    float R;
    cout<<"请输入圆的半径:";
    cin>>R;
    Book cir(R);
    cir.area();

    return 0;
}