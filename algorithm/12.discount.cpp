#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
    int N;
    cin>>N;
    vector<int> price(N);
    long long discount=0;
    for(int i=0;i<N;i++)
    {
        cin>>price[i];
    }
    sort(price.begin(),price.end(),[](int a,int b){return a>b;});
    for(int i=0;i<N;i++)
    {
        if(i%3!=2)
        {
            discount+=price[i];
        }
    }
    cout<<discount<<endl;
    return 0;


}