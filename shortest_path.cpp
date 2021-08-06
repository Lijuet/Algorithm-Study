#include <iostream>
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

class AdjListNode{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w) { v = _v; weight = _w;}
    int getV() { return v; }
    int getWeight() { return weight; }
};

class Graph {
    int V;
    list<AdjListNode>* adj;
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
    int getMinimumPathVertex(int dist[], bool spSet[]);

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void topologicalSP(int s);
    void dijsktraSP_Array(int s);
    void dijsktraSP_Heap(int s);
    void bellmanFordSP(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<AdjListNode>[V];
};

void Graph::addEdge(int u, int v, int weight){
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack){
    visited[v] = true;

    for(auto i:adj[v]){
        if(!visited[i.getV()]) topologicalSortUtil(i.getV(), visited, Stack);
    }

    Stack.push(v);
}

void Graph::topologicalSP(int s){
    stack<int> Stack;
    int dist[V];
    bool* visited = new bool[V];

    for(int i = 0; i < V; i++) {
        dist[i] = (i == s) ? 0 : INF;
        visited[i] = false;
    }

    for(int i = 0; i < V; i++)
        if(!visited[i]) topologicalSortUtil(i, visited, Stack);

    while(!Stack.empty()){
        int u = Stack.top();
        Stack.pop();

        if(dist[u] != INF)
            for(auto i : adj[u])
                if(dist[i.getV()] > dist[u] + i.getWeight()) 
                    dist[i.getV()] = dist[u] + i.getWeight();
        
    }

    for(int i = 0; i < V; i++) 
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    cout << "\n";

    delete[] visited;
}

int Graph::getMinimumPathVertex(int dist[], bool spSet[]){
    int min = INF, minIdx;
    for(int i = 0; i < V; i++)
        if(!spSet[i] && min > dist[i]) min = dist[i], minIdx = i;
    return minIdx;
}

void Graph::dijsktraSP_Array(int s){
    bool spSet[V]; // Shortest Path determined vertices, need not to repeat peak the minimum path vertex
    int dist[V];

    for(int i = 0; i < V; i++) spSet[i] = false, dist[i] = INF;
    dist[s] = 0;

    for(int i = 0; i < V - 1; i++){
        int u = getMinimumPathVertex(dist, spSet);
        spSet[u] = true;

        if(dist[u] != INF)
            for(auto v:adj[u])
                if(!spSet[v.getV()] && dist[v.getV()] > dist[u] + v.getWeight())
                    dist[v.getV()] = dist[u] + v.getWeight();
    }

    for(int i = 0; i < V; i++) 
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    cout << "\n";
}

typedef pair<int, int> vPair; //distance, vertex

void Graph::dijsktraSP_Heap(int s){
    priority_queue<vPair, vector<vPair>, greater<vPair>> pq;
    vector<int> dist(V, INF);

    pq.push(make_pair(0, s));
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto v:adj[u]){
            int vertex = v.getV();
            int weight = v.getWeight();
            if(dist[vertex] > dist[u] + weight){
                dist[vertex] = dist[u] + weight;
                pq.push(make_pair(dist[vertex], vertex));
            }
        }
    }

    for(int i = 0; i < V; i++) 
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    cout << "\n";
}

void Graph::bellmanFordSP(int s){
    bool hasNegativeCycle = false;
    //Init
    vector<int> dist(V, INF);
    dist[0] = 0;
    //Shortest Path
    for(int i = 0; i < V - 1; i++){
        for(int f = 0; f < V; f++){
            for(auto t:adj[f]){
                int vertex = t.getV();
                int weight = t.getWeight();

                if(dist[f] != INF && dist[vertex] > dist[f] + weight) dist[vertex] = dist[f] + weight;
            }
        }
    }
    //Negative Weight Cycle Check
    for(int f = 0; !hasNegativeCycle && f < V; f++){
        for(auto t:adj[f]){
            if(dist[f] != INF && dist[t.getV()] > dist[f] + t.getWeight()) {
                hasNegativeCycle = true;
                break;
            }
        }
    }

    if(hasNegativeCycle) cout << "This graph has negative cycle." << endl;
    else {
        for(int i = 0; i < V; i++) 
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
        cout << "\n";
    }
}


int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 2);
 
    int s = 1;
    cout << "Following are shortest distances from source " << s <<"\n";
    g.topologicalSP(s);
    g.dijsktraSP_Array(s);
    g.dijsktraSP_Heap(s);

    Graph g2(5);
    g2.addEdge(0, 1, -1);
    g2.addEdge(0, 2, 4);
    g2.addEdge(1, 2, 3);
    g2.addEdge(1, 3, 2);
    g2.addEdge(1, 4, 2);
    g2.addEdge(3, 2, 5);
    g2.addEdge(3, 1, 1);
    g2.addEdge(4, 3, -3);
 
    s = 0;
    cout << "Following are shortest distances from source " << s <<"\n";
    g2.bellmanFordSP(s); // 0 -1 2 -2 1

    Graph g3(5);
    g3.addEdge(0, 1, -1);
    g3.addEdge(0, 2, 4);
    g3.addEdge(1, 2, 3);
    g3.addEdge(1, 3, 2);
    g3.addEdge(1, 4, 2);
    g3.addEdge(3, 2, 5);
    g3.addEdge(3, 1, 1);
    g3.addEdge(4, 3, -5);
 
    s = 0;
    cout << "Following are shortest distances from source " << s <<"\n";
    g3.bellmanFordSP(s); //Negative Weight Cycle
  
    return 0;
}