// print in c++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;

class Print
{
public:
	void print(string&);
	void print(string&, int);
	void display();
private:
	string str;
	int num;
};



void Print::print(string&temp)
{
	str = temp.substr(0, 10);
}

void Print::print(string&temp, int num1)
{
	str = temp.substr(0, num1);
}

void Print::display()
{
	cout << str << endl;
}
int main()
{
	string str1;
	int num1;
	Print test;

	cout << "please enter the str:";
	cin >> str1;
	cout << "please enter the number:";
	cin >> num1;
	
	if (num1 == 0)
	{
		test.print(str1);
	}
	else
	{
		test.print(str1, num1);
	}

	test.display();
	system("pause");
	return 0;

}