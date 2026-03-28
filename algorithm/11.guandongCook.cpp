#include<iostream>
using namespace std;
int main()
{
    int eat=0;
    int have=11;
    int regret=0;
    while(regret/3!=(regret+have/2)/3)
    {
        eat++;
        have--;
        if(eat%2==0)
        {
            regret++;
        }
        if(regret%3==0)
        {
            eat++;
            if(eat%2==0)
            {
                regret++;
            }
        }
    }
    cout<<eat<<endl;
    return 0;
}