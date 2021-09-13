#include<iostream>

using namespace std;

int main()
{
    double num, max;

    cout<<"请输入数字（输入0结束）：";
    cin>>max;

    while(true) {
        cin>>num;
        if(!num)
            break;
        if(num > max) max = num;
    }

    cout<<max;

    return 0;
}