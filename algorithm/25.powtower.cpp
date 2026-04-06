#include<iostream>
using namespace std;
#include<numeric>

int main()
{
    int n=1;
    for(int i=1;i<=1632;i++)
    {
        n*=3;
        n%=1632;
    }
    n+=1632;
    int remain=1;
    for(int i=1;i<=n;i++)
    {
        remain*=2;
        remain%=2023;
    }
    cout<<remain<<endl;
    return 0;

}