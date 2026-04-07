#include<iostream>
using namespace std;
#include<vector>

int N;
vector<vector<char>> oldstate;
vector<vector<int>> state;
vector<int> numof1inrow;
vector<int> numof1incol;
bool found=false;
bool hassamerow(int row,int col)
{
    for(int i=0;i<row;i++)
    {
        if(state[i]==state[row])
        {
            return true;
        }
    }
    return false;
}
bool hassamecol(int row,int col)
{
   
    for(int i=0;i<col;i++)
    {
        bool thesame=true;
        for(int j=0;j<N;j++)
        {
            if(state[j][i]!=state[j][col])
            {
                thesame=false;
                break;
            }
        }
        if(thesame)
        {
            return true;
        }
    }
    return false;
}
void dfs(int row,int col)
{
    if(row==N)
    {
        found=true;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<state[i][j];
            }
            cout<<endl;
        }
        return;
    }
    if(oldstate[row][col]=='1')
    {
        state[row][col]=1;
        if(col>=2&&state[row][col]==state[row][col-1]&&state[row][col]==state[row][col-2])
        {
            return;
        }
        if(row>=2&&state[row][col]==state[row-1][col]&&state[row][col]==state[row-2][col])
        {
            return;
        }
        if(row>=1&&col==N-1&&hassamerow(row,col))
        {
            return;
        }
        if(col>=1&&row==N-1&&hassamecol(row,col))
        {
            return;
        }
        dfs(row+col/(N-1),(col+1)%N);
    }
    else if(oldstate[row][col]=='0')
    {
        state[row][col]=0;
        if(col>=2&&state[row][col]==state[row][col-1]&&state[row][col]==state[row][col-2])
        {
            return;
        }
        if(row>=2&&state[row][col]==state[row-1][col]&&state[row][col]==state[row-2][col])
        {
            return;
        }
        if(row>=1&&col==N-1&&hassamerow(row,col))
        {
            return;
        }
        if(col>=1&&row==N-1&&hassamecol(row,col))
        {
            return;
        }
        dfs(row+col/(N-1),(col+1)%N);
    }
    else
    {
        state[row][col]=1;
        numof1inrow[row]++;
        numof1incol[col]++;
        if(numof1inrow[row]>N/2||col+1-numof1inrow[row]>N/2||numof1incol[col]>N/2||row+1-numof1incol[col]>N/2)
        {
            numof1inrow[row]--;
            numof1incol[col]--;
        }
        else if(col>=2&&state[row][col]==state[row][col-1]&&state[row][col]==state[row][col-2])
        {
            numof1inrow[row]--;
            numof1incol[col]--;
        }
        else if(row>=2&&state[row][col]==state[row-1][col]&&state[row][col]==state[row-2][col])
        {
            numof1inrow[row]--;
            numof1incol[col]--;
        }
        else if(row>=1&&col==N-1&&hassamerow(row,col))
        {
            return;
        }
        else if(col>=1&&row==N-1&&hassamecol(row,col))
        {
            return;
        }
        else
        {
            dfs(row+col/(N-1),(col+1)%N);
            if(found)
            {
                return;
            }
            numof1inrow[row]--;
            numof1incol[col]--;
        }
        state[row][col]=0;
        if(numof1inrow[row]>N/2||col+1-numof1inrow[row]>N/2||numof1incol[col]>N/2||row+1-numof1incol[col]>N/2)
        {
            return;
        }
        if(col>=2&&state[row][col]==state[row][col-1]&&state[row][col]==state[row][col-2])
        {
            return;
        }
        if(row>=2&&state[row][col]==state[row-1][col]&&state[row][col]==state[row-2][col])
        {
            return;
        }
        if(row>=1&&col==N-1&&hassamerow(row,col))
        {
            return;
        }
        if(col>=1&&row==N-1&&hassamecol(row,col))
        {
            return;
        }
        dfs(row+col/(N-1),(col+1)%N);
    }
    return;
}
int main()
{
    cin>>N;
    oldstate.resize(N,vector<char>(N));
    state.resize(N,vector<int>(N));
    numof1inrow.resize(N,0);
    numof1incol.resize(N,0);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>oldstate[i][j];
            if(oldstate[i][j]=='1')
            {
                numof1inrow[i]++;
                numof1incol[j]++;
            }
        }
    }
    dfs(0,0);
    return 0;
}