#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> round(3,vector<int>(n,0));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>round[i][j];
        }
    }
    int totalmoney=0;
    int times;
    cin>>times;
    int pos1=0,pos2=0,pos3=0;
    for(int i=0;i<times;i++)
    {
        int x1,x2,x3;
        int r1,r2,r3;
        cin>>r1>>r2>>r3;
        x1=round[0][(pos1+r1)%n];
        x2=round[1][(pos2+r2)%n];
        x3=round[2][(pos3+r3)%n];
        pos1=(pos1+r1)%n;
        pos2=(pos2+r2)%n;
        pos3=(pos3+r3)%n;

        if(x1==x2&&x2==x3&&x1==x3)
        {
            totalmoney+=200;
        }
        else if(x1==x2||x2==x3||x1==x3)
        {
            totalmoney+=100;
        }
        else if(x2==x1+1&&x3==x2+1)
        {
            totalmoney+=200;
        }
        else
        {
            vector<int> v{x1,x2,x3};
            sort(v.begin(),v.end());
            if(v[1]==v[0]+1&&v[2]==v[1]+1)
            {
                totalmoney+=100;
            }
        }
    }
    cout<<totalmoney<<endl;
    return 0;
}