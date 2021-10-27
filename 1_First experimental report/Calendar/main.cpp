#include<iostream>
#include <iomanip>

using namespace std;

inline void print_head()
{
    cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat"<<endl;
}

int main()
{
    int day, stop, day_1 = 1;

    cout<<"请输入每月第一天起始位置和每月天数：";
    cin>>day>>stop;

    print_head();
    
    for(int i = 0; i < day; i++) {
        cout<<"     ";
    }
    while(day_1 <= stop){
        cout<<setw(5)<<setfill(' ')<<day_1++;
        day++;
        if(!(day % 7)){
            cout<<endl;
            day = 0;
        }
    }

    return 0;
}
