#include <bits/stdc++.h>
using namespace std;
int adjacent[20][20];
int visited[20];
int n;
void DFS(int vtx)
{
    int i;
    cout<<vtx<<" ";
    visited[vtx]=1;
    for(i=0;i<n;i++)
    {
        if(adjacent[vtx][i] && !visited[i])
            DFS(i);
    }
}

void connected()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(i);
            cout<<"\n";
        }
    }
}

int main()
{
    int i,j;
	cout<<"Enter the size of square matrix:";
    cin>>n;
	cout<<"Enter the matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
			cin>>adjacent[i][j];
        visited[i]=0;
    }
	cout<<"Path:"<<endl;
    connected();
	return 0;
}
