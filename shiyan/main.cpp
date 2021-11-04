#include <iostream>
#include <memory.h>

using namespace std;

class Set
{
public:
    int *Array; // 数组指针
    int Num;    // 元素数
public:
    /******** 成员集合函数 *********/
    Set() // 无参构造函数    添加构造函数完成初始化
    {
        int i = 0;
        cout << "请输入集合中元素个数：";
        cin >> Num;
        Array = new int[Num];
        cout << "请输入" << Num << "个整形数：";
        while (i != Num)
        {
            cin >> *(Array + i);
            i++;
        }
        display();
    }

    bool isExist(int a) // 判断元素重复函数 重复返回true 不重复返回false
    {
        int i = 0;
        while (i != Num)
        {
            if (*(Array + i) == a)
                return true;
            i++;
        }
        return false;
    }

    void addOne(int addNum) // 添加函数    能添加一个元素，元素不重复
    {
        if (isExist(addNum))
        {
            cout << "元素 " << addNum << "已存在，添加失败！" << endl;
            return;
        }

        expanssionOne(addNum);
        display();
    }

    void expanssionOne(int expanssionNum) // 数组扩容函数 仅+1
    {
        Num++;
        int *NewArray = new int[Num];
        int i = 0;
        while (i != Num - 1)
        {
            *(NewArray + i) = *(Array + i);
            i++;
        }
        *(NewArray + i) = expanssionNum;

        delete[] Array;
        Array = NewArray;
    }

    void deleteOne(int deleteNum) // 数组删除函数    能删除一个元素
    {
        int i = 0, j = 0;
        int *NewArray = new int[Num - 1];
        while (i != Num)
        {
            if (*(Array + i) != deleteNum)
            {
                *(NewArray + j) = *(Array + i);
                j++;
            }
            i++;
        }
        Num--;
        delete[] Array;
        Array = NewArray;
        display();
    }

    void display() // 输出函数 直接输出类成员数组
    {
        int i = 0;
        cout << "Set = {";
        while (i != Num - 1)
        {
            cout << *(Array + i) << ", ";
            i++;
        }
        cout << *(Array + i) << "}" << endl;
    }

    /******** 操作函数 *********/
    void intersection(int array2[], int array2Size) // 交集函数    求两个集合对象的交集
    {
        int hash[1000 * Num], i = 0;
        memset(hash, 0, 1000 * Num);
        int inter[Num];
        int interNum = 0;

        for (i = 0; i < Num; i++)
            hash[Array[i]] = 1;
        for (i = 0; i < array2Size; i++)
        {
            if (hash[array2[i]])
            {
                inter[interNum] = array2[i];
                interNum++;
            }
        }
        cout << "Intersection(Set, OpearateSet) = {";
        Condisplay(inter, interNum);
    }

    void unionSet(int array[], int arraySize) // 并集函数  求两个集合对象的并集
    {
        int i = 0, j = 0;
        int unSet[Num], unSetNum = 0;

        for (i = 0; i < Num; i++)
        {
            unSet[i] = Array[i];
            unSetNum++;
        }
        for (i = 0; i < arraySize; i++)
        {
            for (j = 0; j < unSetNum; j++)
            {
                if (array[i] == unSet[j])
                    break;
            }
            if (j > Num - 1)
            {
                unSet[j] = array[i];
                unSetNum++;
            }
        }

        cout << "UnionSet(Set, OpearateSet) = {";
        Condisplay(unSet, unSetNum);
    }

    void differrentSet(int array[], int arraySize) // 差集函数     求两个集合对象的差集
    {
        int i = 0, j = 0;
        int diff[Num], diffNum = 0;

        for (i = 0; i < Num; i++)
        {
            diff[i] = Array[i];
            diffNum++;
        }

        for (i = 0; i < arraySize; i++)
        {
            for (j = 0; j < diffNum; j++)
            {
                if (Array[i] == diff[j])
                {
                    for (int x = j; x < diffNum - 1; x++)
                    {
                        diff[x] = diff[x + 1];
                    }
                    diffNum--;
                    break;
                }
            }
        }

        cout << "differentSet(Set, OpearateSet) = {";
        Condisplay(diff, diffNum);
    }

    void Condisplay(int a[], int n) // 输出函数 输出给定数组
    {
        int i = 0;
        for (i = 0; i < n - 1; i++)
        {
            cout << a[i] << ", ";
        }
        cout << a[i] << "}" << endl;
    }

    ~Set() {}
};

int main()
{
    /**** Set类操作 ****/
    Set gather;
    int addNum, deleteNum;

    cout << "请输入增加的元素值：";
    cin >> addNum;
    gather.addOne(addNum);

    cout << "请输入删除的元素值：";
    cin >> deleteNum;
    gather.deleteOne(deleteNum);

    /**** 创建操作集合 ****/
    int i = 0, OperateSetNum = 0, *OperateSet;
    cout << "请输入集合中元素个数：";
    cin >> OperateSetNum;
    OperateSet = new int[OperateSetNum];
    cout << "请输入" << OperateSetNum << "个整形数：";
    while (i != OperateSetNum)
    {
        cin >> *(OperateSet + i);
        i++;
    }

    cout << endl;
    gather.display();
    cout << "OperateSet = {";
    gather.Condisplay(OperateSet, OperateSetNum);

    /**** OperateSet操作 ****/
    cout << endl;
    gather.intersection(OperateSet, OperateSetNum);
    cout << endl;
    gather.unionSet(OperateSet, OperateSetNum);
    cout << endl;
    gather.differrentSet(OperateSet, OperateSetNum);
    cout << endl;
    system("pause");

    return 0;
}
