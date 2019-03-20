#include <iostream>

using namespace std;

class A1
{
public:
    A1(int x){
    cout<<"A1::A1(int) called"<<endl;}

};
class A2:public A1
{
public:
    A2(int x,int y){
    cout<<"A2::A2(int) called"<<endl;}

};
class A3:public A1
{
public:
    A3(int x){
    cout<<"A3::A3(int) called"<<endl;}

};
class A4: virtual public A2
{
public:
    A4(int x){
    cout<<"A4::A4(int) called"<<endl;}

};
class A5: virtual public A3
{
public:
    A5(int x){
    cout<<"A5::A5(int) called"<<endl;}

};
class A6: public A4,public A5
{
public:
    A6(int x){
    cout<<"A6::A6(int) called"<<endl;}

};
int main()
{
    A6 A61(30);
    return 0;
}




