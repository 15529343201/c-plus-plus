#include<iostream>
using namespace std;

class Person
{
	//重载操作符：加法
	public:
		void operator+(const Person& rhs)
		{
			cout<<"执行了重载的加法操作"<<endl;
		} 
};

int main()
{
	int a,b;
	a=12;
	b=9;
	cout<<a+b<<endl;
	
	Person p1,p2;
	p1+p2;
	
	cout<<"hello"<<endl;
	return 0;
}
/*输出结果
21
执行了重载的加法操作
hello
*/ 
