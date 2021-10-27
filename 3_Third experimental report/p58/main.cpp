#include <iostream>

using namespace std;

class Point
{
private:
    int X, Y;

public:
    Point(int = 0, int = 0);
    Point(const Point&);
    void displayxy();
    ~Point();
};

Point::Point(int x, int y)
{
    X = x;
    Y = y;
    cout << "Constructor is called!";
    displayxy();
}

Point::Point(const Point &p)
{
    X = p.X;
    Y = p.Y;
    cout << "Copy constructor is called!";
    displayxy();
}
void Point::displayxy()
{
    cout << "(" << X << "," << Y << ")" << endl;
}

Point::~Point()
{
    cout << "Destructor is called!";
    displayxy();
}

Point func(Point p)
{
    int x = 10 * 2;
    int y = 10 * 2;
    Point pp(x, y);
    return pp;
}

int main()
{
    Point p1(3, 4);
    Point p2 = p1;
    p2 = func(p1);

    return 0;
}