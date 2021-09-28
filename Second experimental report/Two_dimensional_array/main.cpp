#include <iostream>
#include<string>
#include<iomanip>
using namespace std;


struct twodim{
int r;
int c;
float *a;
};
void get_twodim(twodim&s,int row,int col)
{
	//初始化数组
    s.a = new float[row * col];
}
float & val(twodim&s, int i,int j)
{
	//返回i行j列的值
    return s.a[i * j];
}
void free_twodim(twodim &s)
{
	//释放数组空间
    delete s.a;
}
int main()
{
	struct twodim s;
	int i,j;
	get_twodim(s,3,4);

	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			val(s,i,j)=5;

	for(i=0;i<3;i++)
	{	for(j=0;j<4;j++)
			cout<<setw(5)<<val(s,i,j);

		cout<<endl;
	}
	free_twodim(s);

    return 0;
}
