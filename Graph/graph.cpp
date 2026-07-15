#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
  int V;
  list<int>* l;
  public:
  Graph(int V){
    this->V=V;
    l=new list<int> [V];

  }

  void addEdge(int u,int v){//u--v
    l[u].push_back(v);
    l[v].push_back(u);

  }
  void print(){
    for(int u=0;u<V;u++){//0,1,2,3,4
      list<int> neighbours=l[u];
      cout<<u<<" ";
      for(int v: neighbours){
        cout<<v <<" ";
      }
      cout<<endl;
    }
  }

  void bfs(){//O(V+E)
    queue<int> q;
    vector<bool> vis(V,false);
    q.push(0);
    vis[0]=true;

    while(q.size()>0){
      int u=q.front();
      q.pop();
      cout<<u<<" ";

      list<int> neighbours=l[u];
      for(int v:neighbours){
        if(!vis[v]){
          vis[v]=true;
          q.push(v);
        }
      }
    }
    cout<<endl;
  }

  void dfs(int u,vector<bool> &vis){//O(V+E)
    vis[u]=true;
    cout<<u<<" ";

    list<int> neighbours=l[u];
    for(int v:neighbours){
      if(!vis[v]){
        dfs(v,vis);
      }
    }
  }

  bool pathHelper(int src,int dest,vector<bool> &vis){
    if(src==dest){
      return true;
    }

    vis[src]=true;

    list<int> neighbours=l[src];
    for(int v : neighbours){
      if(!vis[v]){
        if(pathHelper(v,dest,vis)){
          return true;
        }
      }
    }
    return false;
  }

  bool hasPath(int src,int dest){
  vector<bool> vis(7,false);
  return pathHelper(src,dest,vis);
  }
};

int main(){
  Graph graph(7);

  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(1,3);
  graph.addEdge(2,4);
  graph.addEdge(3,4);
  graph.addEdge(3,5);
  graph.addEdge(4,5);
  graph.addEdge(5,6);

  graph.bfs();

  //vector<bool> vis(7,false);

  //graph.dfs(0,vis);

  cout<<graph.hasPath(0,5)<<endl;
  return 0;
}