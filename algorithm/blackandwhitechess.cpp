#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<set>
#include<algorithm>
string getlines(int n)
{
    string s="";
    while(n>0)
    {
        s.insert(0,1,n%2+'0');
        n/=2;
    }
    if(s.size()<6)
    {
        s.insert(0,6-s.size(),'0');
    }
    return s;
}
int main()
{
    vector<string> line;
    for(int i=0;i<63;i++)
    {
        string s=getlines(i);
        int whitenum=0;
        bool flag=false;
        for(int i=0;i<6;i++)
        {
            if(i<=3)
            {
                if(s[i]==s[i+1]&&s[i+1]==s[i+2])
                {
                    flag=true;
                    break;
                }
            }
            if(s[i]=='0')
            {
                whitenum++;
            }
        }
        if(flag||whitenum!=3)
        {
            continue;
        }
        else
        {
            line.push_back(s);
        }
    }
    int len=line.size();
    for(int x1=0;x1<len;x1++)
    {
        if(line[x1][0]!='1'||line[x1][1]!='0'||line[x1][2]!='1'||line[x1][3]!='0')
        {
            continue;
        }
        for(int x2=0;x2<len;x2++)
        {
            if(x2==x1)
            {
                continue;
            }
            if(line[x2][3]!='0')
            {
                continue;
            }
            for(int x3=0;x3<len;x3++)
            {
                if(x3==x1||x3==x2)
                {
                    continue;
                }
                if(line[x3][3]!='1'||line[x3][4]!='0'||line[x3][5]!='0')
                {
                    continue;
                }
                for(int x4=0;x4<len;x4++)
                {
                    if(x4==x3||x4==x2||x4==x1)
                    {
                        continue;
                    }
                    for(int x5=0;x5<len;x5++)
                    {
                        if(x5==x4||x5==x3||x5==x2||x5==x1)
                        {
                            continue;
                        }
                        if(line[x5][2]!='1'||line[x5][5]!='1')
                        {
                            continue;
                        }
                        for(int x6=0;x6<len;x6++)
                        {
                            if(x6==x5||x6==x4||x6==x3||x6==x2||x6==x1)
                            {
                                continue;
                            }
                            if(line[x6][1]!='0'||line[x6][4]!='1')
                            {
                                continue;
                            }
                            set<string> s;
                            bool flag=false;
                            for(int i=0;i<6;i++)
                            {
                                string m_s;
                                m_s+=line[x1][i];
                                m_s+=line[x2][i];
                                m_s+=line[x3][i];
                                m_s+=line[x4][i];
                                m_s+=line[x5][i];
                                m_s+=line[x6][i];
                                if(find(line.begin(),line.end(),m_s)==line.end())
                                {
                                    flag=true;
                                    break;
                                }
                                s.insert(m_s);
                            }
                            if(flag)
                            {
                                continue;
                            }
                            if(s.size()==6)
                            {
                                cout<<line[x1]<<line[x2]<<line[x3]<<line[x4]<<line[x5]<<line[x6]<<endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }

    }
    return 0;
}