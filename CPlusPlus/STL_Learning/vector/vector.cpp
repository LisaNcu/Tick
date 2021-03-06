// vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class B
{
public:
    B();
    ~B();
    B(const B& a)
    {
        cout << "B的复制构造函数" << endl;
    }
private:
    
};

B::B()
{
    cout << "B的构造" << endl;
}

B::~B()
{
    cout << "B的析构" << endl;
}

class A
{
public:

    A();
    ~A();
    void Display()
    {
        cout << i<<endl;
        cout << "A的Display"<< endl;
    }
    A(int i)
        :i(i)
    {

        this->i = i;
        this->p[0] = '1';
        cout << "A的int参数构造" << endl;
    }
    A(const A& a)
    {
        i = a.i;
        cout << "A的复制构造函数" << endl;
    }
    A(A&& a) 
        :i(a.i)
    {
        cout << i << endl;
        cout << "A的移动构造" << endl;
    }
    A& operator=(A& a)
    {
        cout << "A的赋值运算符";
        return *this;
    }
    int i;
    B b;
    char p[100];
private:

};

A::A()
{
    i = 0;
    cout << "A的构造" << endl;
}

A::~A()
{
    cout << "A的析构" << endl;
}

//#define  Testvector<bool>
//#define  vector存放struct或class复制构造模式
//define vector存放struct或class移动构造模式
//#define  存放vector
//#define 存放引用
void Test()
{
#ifdef  Testvector<bool>
    vector<bool> t1;
    t1.push_back(true);
    t1.push_back(false);

    bool* p = &(t1[1]);

    cout << p;
#endif // Testvector<bool>

#ifdef vector存放struct或class复制构造模式
    vector<A> t2;
    //auto a1 = A(1);
    A a1(1);
    t2.push_back(a1);
#endif // vector存放struct或class,复制构造模式

#ifdef vector存放struct或class移动构造模式
    vector<A> t2;
    A a1(1);
    t2.push_back(move(a1));
    t2[0].Display();
    a1.Display();
#endif // vector存放struct或class移动构造模式

#ifdef 存放vector
    vector<vector<A>> t3;
    vector<A> At;
    At.push_back(A(1));
    t3.push_back(At);
    At[0].i += 1;
    At.push_back(A(2));
    At[0].Display();
    t3[0][0].Display(); //已经是新对象了，


#endif // 存放vector

#ifdef 存放引用
    vector<A&> t5;
    A a1;
    t5.push_back(a1);
    a1.i += 1;
    t5[0].Display();
#endif // 存放引用


    system("pause");
}

int main()
{
    Test();

    //vector<int> ta;
    //for (int i = 0; i < 10; ++i)
    //{
    //    ta.push_back(i);
    //}

    //auto it = ta.back();

    //it += 5;
    //cout << "容量是  " << ta.capacity() << endl;
    //cout << "it的值是  " << *it << endl;

    //ta.erase(it);
    //cout << "erase后容量是    " << ta.capacity() << endl;
    //cout << "此时it指向的值是    " << *it << endl;
    system("pause");
    return 0;
}
//
//// iterator_debugging_5.cpp
//// compile by using: /EHsc /MDd
//#include <vector>


//int main()
//{
//    auto vect = std::vector<int>(10);
//    auto sink = new auto(std::begin(vect));
//    ::operator delete(sink); // frees the memory without calling ~iterator()
//} // access violation
