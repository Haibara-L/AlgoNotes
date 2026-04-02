#include<iostream>
using namespace std;

int main()
{
    int n;
    int line,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>line>>num;
        num--;
        int numofone=0;
        while(num>0)
        {
            numofone+=(num%2);
            num/=2;
        }
        if(numofone%2==0)
        {
            cout<<"RED"<<endl;
        }
        else
        {
            cout<<"BLACK"<<endl;
        }
    }
    return 0;
}