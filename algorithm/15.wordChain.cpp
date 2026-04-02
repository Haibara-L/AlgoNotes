#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
struct edge
{
    int to;
    string word;
    bool used=false;
    edge(int t, string w) : to(t), word(w), used(false) {}
};

int main()
{
   int n;
   cin>>n;
   vector<string> inputstring(n);
   for(int i=0;i<n;i++)
   {
    cin>>inputstring[i];
   }
   sort(inputstring.begin(),inputstring.end());
   int indegree[26]={0};
   int outdegree[26]={0};
   int appeared[26]={0};
   vector<edge> adj[26];
   for(int i=0;i<n;i++)
   {
    int startindex=inputstring[i][0]-'a';
    int endindex=inputstring[i][inputstring[i].size()-1]-'a';
    adj[startindex].push_back(edge {endindex,inputstring[i]});
    outdegree[startindex]++;
    indegree[endindex]++;
    appeared[startindex]=1;
    appeared[endindex]=1;


   }
}