#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int moveTimes,posNum,Pos;
    cin>>moveTimes>>posNum>>Pos;
    vector<int> circle(moveTimes);
    for(int i=0;i<moveTimes;i++)
    {
        cin>>circle[i];
    }
    int n=0;
    int move=0;
    while(move<moveTimes)
    {
        Pos+=circle[move];
        Pos%=posNum;
        move++;
        if(Pos==0)
        {
            n++;
        }
    }
    cout<<n<<endl;
    return 0;
}