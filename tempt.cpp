#include<iostream>
using namespace std;
template<class T>
void f(T x,T y)
{
cout<<x+y<<endl;
}

int main()
{

int x=10;
double y=15.55;
f(x,y);

return 0;

}
