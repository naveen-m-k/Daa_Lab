#include<iostream>
#include<vector>

using namespace std;
#define V 5

int selectMinVertex(vector<int>&value, vector<bool>&setMST)
{
    int min=INT_MAX;
    int vertex;

    for(int i=0;i<V;i++)
    {
        if(setMST[i]==false&&value[i]<min){
            vertex=i;
            min=value[i];
        }
    }
    return vertex;
}

void findMST(int graph[V][V])
{
    int parent[V];
    vector<int> value(V,INT_MAX);
    vector<bool> setMST(V,false);

    parent[0]=-1;
    value[0]=0;

    for(int i=0;i<V-1;++i){
        int u=selectMinVertex(value,setMST);
        setMST[u]=true;

        for(int j=0;j<V;j++){
            if(graph[u][j]!=0&&setMST[j]==false&&graph[u][j]<value[j]){
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }

    for(int i=1;i<V;++i)
        cout<<"U->V: "<<parent[i]<<"->"<<i<<" wt = "<<graph[parent[i]][i]<<endl;
}

int main()
{
    int graph[V][V]={
        {0,5,3,0,0},
        {5,0,0,1,7},
        {3,0,0,2,0},
        {0,1,2,0,8},
        {0,7,0,8,0}
    };
    findMST(graph);
    return 0;
}
