#include<iostream>
using namespace std;

float PI=3.14;

class Circle
{
    public:
        Circle();  // 默认构造函数
        Circle(float); // 含参构造函数
        void area(); // 面积计算函数
        void display(); // 打印函数
    private:
        float radius, S;  // 半径
};
Circle::Circle()
{
    radius = 0;
}
Circle::Circle(float x)
{
    radius = x;
}
void Circle::area()
{
    S = PI * radius * radius;
    display();
}
void Circle::display()
{
    cout<<"半径为"<<radius<<"的圆的面积为"<<S<<endl;
}
int main()
{
    float R;

    cout<<"请输入圆的半径:";
    cin>>R;
    if(R < 0){cout << "圆的半径不能为复数！"; return 0;}

    Circle cir(R);
    cir.area();

    return 0;
}
