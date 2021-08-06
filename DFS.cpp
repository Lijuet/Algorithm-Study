#include <bits/stdc++.h>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS(int s){
    bool *visited = new bool[V];
    
    for(int i = 0; i < V; i++) visited[i] = false;

    list<int> stack;

    visited[s] = true;
    stack.push_back(s);

    list<int>::iterator i;

    while(!stack.empty()){
        s = stack.back();
        cout << s << " ";
        stack.pop_back();

        for(i = adj[s].begin(); i != adj[s].end(); i++){
            if(!visited[*i]){
                visited[*i] = true;
                stack.push_back(*i);
            }
        }
    }
    
}

class Graph_R{
public:
    map<int, bool> visited;
    map<int, bool> recurStack;
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void DFS(int v);
    void DFS_All();
    bool detectCycle(int v);
    bool detectCycle_All();
};

void Graph_R::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph_R::DFS(int v){
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i]) DFS(*i);
}

void Graph_R::DFS_All(){
    for(auto i:adj)
        if(visited[i.first] == false) DFS(i.first);
}

bool Graph_R::detectCycle(int v){
    visited[v] = true;
    recurStack[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!recurStack[*i]) detectCycle(*i);
        else return true;
    }
    recurStack[v] = false;
}

bool Graph_R::detectCycle_All(){
    for(auto i:adj)
        if(!visited[i.first])
            if(detectCycle(i.first)) return true;
    return false;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    g.addEdge(4, 5);
    g.addEdge(4, 3);
 
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 0) \n";
    g.DFS(0);

    Graph_R gr;
    gr.addEdge(0, 4);
    gr.addEdge(2, 1);
    gr.addEdge(3, 2);
    gr.addEdge(4, 3);
    gr.addEdge(4, 5);

    cout << "\nFollowing is Depth First Traversal with Recursion "
         << "(starting from vertex 0) \n";
    gr.DFS(0);

    Graph_R gr2;
    gr2.addEdge(0, 4);
    gr2.addEdge(2, 1);
    gr2.addEdge(3, 2);
    gr2.addEdge(4, 3);
    gr2.addEdge(4, 5);
    gr2.addEdge(6, 7);
    gr2.addEdge(7, 8);
    gr2.addEdge(8, 6);

    cout << "\nFollowing is Cycle Detection of the Disconnected Graph" << endl;
    if(gr2.detectCycle_All()) cout << "Cycle is found" << endl;
    else cout << "Cycle is not found" << endl;
 
    return 0;
}
