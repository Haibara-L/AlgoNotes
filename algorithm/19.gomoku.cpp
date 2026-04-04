#include<iostream>
using namespace std;
#include<vector>

string getlines(int n)
{
    string s="";
    while(n>0)
    {
        s.insert(0,1,n%2+'0');
        n/=2;
    }
    if(s.size()<5)
    {
        s.insert(0,5-s.size(),'0');
    }
    return s;
}

int main()
{
    vector<string> lines;
    int tienum=0;
    for(int i=1;i<31;i++)
    {
        lines.push_back(getlines(i));
    }
    for(int x1=0;x1<30;x1++)
    {
        for(int x2=0;x2<30;x2++)
        {
            for(int x3=0;x3<30;x3++)
            {
                for(int x4=0;x4<30;x4++)
                {
                    for(int x5=0;x5<30;x5++)
                    {
                        bool flag=false;
                        vector<string> test;
                        int blacknum=0;
                        for(int i=0;i<5;i++)
                        {
                            string col;
                            col+=lines[x1][i];
                            blacknum+=lines[x1][i]-'0';
                            col+=lines[x2][i];
                            blacknum+=lines[x2][i]-'0';
                            col+=lines[x3][i];
                            blacknum+=lines[x3][i]-'0';
                            col+=lines[x4][i];
                            blacknum+=lines[x4][i]-'0';
                            col+=lines[x5][i];
                            blacknum+=lines[x5][i]-'0';
                           if(col=="00000"||col=="11111")
                           {
                            flag=true;
                            break;
                           }
                           test.push_back(col);
                        }
                        if(flag||blacknum!=12)
                        {
                            continue;
                        }
                        string left,right;
                        for(int i=0;i<5;i++)
                        {
                            left+=test[i][i];
                            right+=test[i][4-i];
                        }
                        if(left=="00000"||right=="00000"||left=="11111"||right=="11111")
                        {
                            continue;
                        }
                        tienum++;
                    }
                }
            }
        }
    }
    cout<<tienum;
    return 0;
}