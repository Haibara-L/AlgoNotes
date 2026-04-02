#include<iostream>
using namespace std;
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
bool compare(pair<double,double>p1,pair<double,double>p2)
{
    return p1.first<p2.first;
}
int main()
{
    int numofbomb;
    cin>>numofbomb;
    vector<pair<double,double>> v;
    for(int i=0;i<numofbomb;i++)
    {
        double x,y,r;
        cin>>x>>y>>r;
        double dis=hypot(x,y);
        double ang=atan2(y,x);
        if(r>=dis)
        {
            cout<<fixed<<setprecision(3)<<0<<endl;
            return 0;
        }
        else
        {
            double deltaagt=asin(r/dis);
            v.push_back(make_pair(max(ang-deltaagt,0.0),min(ang+deltaagt,acos(-1.0)/2)));
        }
    }
    sort(v.begin(),v.end(),compare);
    double totalangle=0;
    double startangle=v[0].first;
    double endangle=v[0].second;
    for(int i=1;i<numofbomb;i++)
    {
        if(v[i].first>endangle)
        {
            totalangle+=(endangle-startangle);
            startangle=v[i].first;
            endangle=v[i].second;
        }
        else
        {
            endangle=max(v[i].second,endangle);
        }
    }
    totalangle+=(endangle-startangle);
    cout<<fixed<<setprecision(3)<<1-2*totalangle/acos(-1.0)<<endl;
    return 0;
}