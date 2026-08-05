#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;

class Graph{
  int V;
  list<int>* l;
  bool isUndir;
  public:
  Graph(int V,bool isUndir=true){
    this->V=V;
    l=new list<int> [V];
    this->isUndir=isUndir;
    

  }

  void addEdge(int u,int v){//u--v
    l[u].push_back(v);
    if(isUndir)
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

  void bfsHelper(int st,vector<bool>& vis){//O(V+E)
    queue<int> q;
    
    q.push(st);
    vis[st]=true;

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

  void bfs(){
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++){
      if(!vis[i]){
        bfsHelper(i,vis);
        cout<<endl;
      }
    }
  }

  void dfsHelper(int u,vector<bool> &vis){//O(V+E)
    vis[u]=true;
    cout<<u<<" ";

    list<int> neighbours=l[u];
    for(int v:neighbours){
      if(!vis[v]){
        dfsHelper(v,vis);
      }
    }
  }
  void dfs(){
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++){
      if(!vis[i]){
        dfsHelper(i,vis);
      }
    }
    cout<<endl;
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

  bool UndirCycleHelper(int src,int par,vector<bool> &vis){//O(V+E)
    vis[src]=true;
    list<int> neigh=l[src];

    for(int v: neigh){
      if(!vis[v]){
        if(UndirCycleHelper(v,src,vis)){
          return true;
        }
      }else{
        if(v!=par){
          return true;
        }
      }
    }
    return false;
  }


  bool isCycleUndir(){
    vector<bool> vis(V,false);
    return UndirCycleHelper(0,-1,vis);
  }
bool dirCycleHelper(int src,vector<bool> &vis,vector<bool> &recPath){
  vis[src]=true;
  recPath[src]=true;
  list<int> neigh=l[src];

  for(int v: neigh){
    if(!vis[v]){
      if(dirCycleHelper(v,vis,recPath)){
        return true;
      }
    }else{
      if(recPath[v]){
        return true;
      }
    }
  }
  recPath[src]=false;
  return false;
}

bool isCycleDir(){
  vector<bool> vis(V,false);
  vector<bool> recPath(V,false);
  for(int i=0;i<V;i++){
    if(!vis[i]){
      if(dirCycleHelper(i,vis,recPath)){
        return true;
      }
    }


  }
  return false;

}

bool isBipartite(){
  queue<int> q;
  vector<bool> vis(V,false);
  vector<int> color(V,-1);

  q.push(0);
  color[0]=0;

  while(q.size()>0){
    int curr=q.front();
    q.pop();
    list<int> neigh=l[curr];

    for(int v : neigh){
      if(!vis[v]){
        vis[v]=true;
        color[v]=!color[curr];
        q.push(v);
      }else{
        if(color[v]==color[curr]){
          return false;
        }
      }
    }
  }
  return true;
}

void pathHelperr(int src,int dest,vector<bool>& vis,string & path){

  if(src==dest){
    cout<<path<<dest<<endl;
    return;
  }
  vis[src]=true;
  path+=to_string(src);
  list<int> neigh=l[src];
  for(int v:neigh){
    if(!vis[v]){
      pathHelperr(v,dest,vis,path);
    }
  }
  path=path.substr(0,path.size()-1);
  vis[src]=false;
}

void printAllPaths(int src,int dest){
  vector<bool> vis(V,false);
  string path="";
  pathHelperr(src,dest,vis,path);
}

void topoHelper(int src,vector<bool>& vis,stack<int> &s){

  vis[src]=true;
  list<int> neigh=l[src];
  for(int v: neigh){
    if(!vis[v]){
      topoHelper(v,vis,s);
    }
  }
  s.push(src);

}

void topoSort(){
  vector<bool> vis(V,false);
  stack<int> s;

  for(int i=0;i<V;i++){
    if(!vis[i]){
      topoHelper(i,vis,s);
    }
  }

  while(s.size()>0){
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl;
}

void calcIndegree(vector<int>& Indeg){
  for(int u=0;u<V;u++){
    list<int> neigh=l[u];
    for(int v: neigh){
      Indeg[v]++;
    }
  }
}

void topoSort2(){
  vector<int> Indeg(V,0);
  calcIndegree(Indeg);
  queue<int> q;
  for(int i=0;i<V;i++){
    if(Indeg[i]==0){
      q.push(i);
    }
  }
  while(q.size()>0){
    int curr=q.front();
    q.pop();
    cout<<curr<<" ";
    list<int> neigh=l[curr];
    for(int v : neigh){
      Indeg[v]--;
      if(Indeg[v]==0){
        q.push(v);
      }
    }
  }
  cout<<endl;
}




};

int main(){
  /*Graph graph(7);

  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(1,3);
  graph.addEdge(2,4);
  graph.addEdge(3,4);
  graph.addEdge(3,5);
  graph.addEdge(4,5);
  graph.addEdge(5,6);

  graph.bfs();
  graph.dfs();

  //vector<bool> vis(7,false);

  //graph.dfs(0,vis);

  cout<<graph.hasPath(0,5)<<endl;*/

  /*int V=5;
  Graph graph(V);
  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(0,3);
  graph.addEdge(1,2);
  graph.addEdge(3,4);
  cout<<graph.isCycleUndir()<<endl;*/
  /*int V=4;

  Graph graph(V,false);
  graph.addEdge(0,1);
  graph.addEdge(0,2);
  graph.addEdge(1,3);
  graph.addEdge(2,3);
  graph.addEdge(0,3);
  //graph.addEdge(3,0);

  cout<<graph.isBipartite()<<endl;

  Graph graph(6,false);
  graph.addEdge(0,3);
  graph.addEdge(2,3);
  graph.addEdge(3,1);
  graph.addEdge(4,0);
  graph.addEdge(4,1);
  graph.addEdge(5,0);
  graph.addEdge(5,2);

  graph.printAllPaths(5,1);*/

  Graph graph(6,false);
  
  graph.addEdge(2,3);
  graph.addEdge(3,1);
  graph.addEdge(4,0);
  graph.addEdge(4,1);
  graph.addEdge(5,0);
  graph.addEdge(5,2);

  graph.topoSort();
  graph.topoSort2();

  return 0;
}