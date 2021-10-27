#include <iostream>

using namespace std;

const int Queue_Size_Max = 100;

class Circle_Queue
{
public:
	Circle_Queue() //构造函数，置空队列
	{
		front = rear = 0;
	}
	~Circle_Queue() { cout << "Destructor is called"; } //析构函数
	void Put(int x);			   //元素x入队
	int Pop();					   //队头元素出队
	int Get_Head();					   //获取队头元素，不删除队头
	bool Circle()					   //判断队列是否循环完毕
	{
		if (front == rear)
			return 1;
		else
			return 0;
	}

private:
	int data[Queue_Size_Max]; //存放队列的数组
	int front, rear;	 //头指针与尾指针
};

void Circle_Queue::Put(int x)
{
	if ((rear + 1) % Queue_Size_Max == front) //判断队列是否已满
		cout << "Queue is full,can't input " << x << "!" << endl;
	else
	{
		data[rear] = x;				   //元素x入队
		rear = (rear + 1) % Queue_Size_Max; //移动尾指针指向下一个空间
	}
}

int Circle_Queue::Pop() //队头元素出栈
{
	if (Circle())
	{ //判断队列是否循环完毕
		front = 1;
		return data[0];
	}
	else
	{
		front = (front + 1) % Queue_Size_Max; //移动队头指针指向下一个空间，即被删元素所在位置
		return data[front - 1];			 //返回被删除的元素的值
	}
}

int Circle_Queue::Get_Head()
{
	if (Circle())
	{
		front = 1;
		return data[0];
	}
	else
	{
		return data[(front) % Queue_Size_Max];
	}
}

int main()
{
	Circle_Queue Q;

	int i = 0;
	while((i++) != 5) // 将数据入队列
	{
		Q.Put(i);
	}

	i = 2 * (i - 1);
	while(i--)          // 循环队列输出
	{
		cout << Q.Pop() << endl;
	}
	cout << Q.Get_Head() << endl; 

	return 0;
}