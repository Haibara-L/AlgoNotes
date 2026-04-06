#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<long long> A;
vector<long long> B; 
int m,n;
long long K;

long long check(long long x)
{
    long long num=0;
    int i=0;
    int j=n-1;
    while(i<m&&j>=0)
    {
        if(A[i]>x)
        {
            break;
        }
        while(B[j]+A[i]>x)
        {
            j--;
            if(j<0)
            {
                return num;
            }
        }
        num+=(j+1);
        i++;
    }
    return num;

}
int main()
{
    cin>>m>>n>>K;
    A.resize(m);
    B.resize(n);
    for(int i=0;i<m;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    long long left=A[0]+B[0];
    long long right=A[m-1]+B[n-1];
    long long mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(check(mid)>=K)
        {
           right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    cout<<left<<endl;
    return 0;



}