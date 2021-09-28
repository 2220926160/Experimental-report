#include <iostream>
#include<string>
using namespace std;


int main()
{
	string names[10];
	int i;
	int j;
	string temp;

	cout << "Please enter your name:";
	for (i = 0; i < 10; i++)
	{
		cin >> names[i];
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (names[j].compare(names[j + 1]) < 0)
			{
				temp.assign(names[j]);
				names[j].assign(names[j + 1]);
				names[j + 1].assign(temp);
			}
		}
	}

    cout << "---------------------------" << endl;

	for (i = 0; i < 10; i++)
	{
		cout << names[i] << endl;
	}
	system("pause");
	return 0;
}
