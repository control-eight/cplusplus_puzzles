// C++ Implementation of Kosaraju's algorithm to print all SCCs 
#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {

public:
    Graph(int V);

    void addEdge(int v, int w, double p);

    // The main function that finds and prints strongly connected 
    // components 
    void printSCCs();

    // Function that returns reverse (or transpose) of this graph 
    Graph getTranspose();

private:
    int V;    // No. of vertices
    list<pair<int, double>> *adj;    // An array of adjacency lists

    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing
    // time
    void fillOrder(int v, bool visited[], stack<pair<int, double>> &Stack);

    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[]);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<pair<int, double>>[V];
}

// A recursive function to print DFS starting from v 
void Graph::DFSUtil(int v, bool visited[]) {
    // Mark the current node as visited and print it 
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex 
    list<pair<int, double>>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[get<0>(*i)])
            DFSUtil(get<0>(*i), visited);
}

Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++) {
        // Recur for all the vertices adjacent to this vertex 
        list<pair<int, double>>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[get<0>(*i)].push_back(make_pair(v, get<1>(*i)));
        }
    }
    return g;
}

void Graph::addEdge(int v, int w, double p) {
    adj[v].push_back(make_pair(w, p)); // Add w to v’s list.
}

void Graph::fillOrder(int v, bool visited[], stack<pair<int, double>> &Stack) {
    // Mark the current node as visited and print it 
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex 
    list<pair<int, double>>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[get<0>(*i)])
            fillOrder(get<0>(*i), visited, Stack);

    // All vertices reachable from v are processed by now, push v  
    Stack.push(make_pair(v, 0.01));
}

// The main function that finds and prints all strongly connected  
// components 
void Graph::printSCCs() {
    stack<pair<int, double>> Stack;

    // Mark all the vertices as not visited (For first DFS) 
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times 
    for (int i = 0; i < V; i++)
        if (!visited[i])
            fillOrder(i, visited, Stack);

    // Create a reversed graph 
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS) 
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Now process all vertices in order defined by Stack 
    while (!Stack.empty()) {
        // Pop a vertex from stack 
        pair<int, double> p = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        int v = get<0>(p);
        if (!visited[v] ) {
            gr.DFSUtil(v, visited);
            cout << endl;
        }
    }
}

// Driver program to test above functions 
int main() {
    // Create a graph given in the above diagram 
    Graph g(4);
    g.addEdge(0, 1, 0.75);
    g.addEdge(0, 3, 0.75);
    g.addEdge(1, 0, 0.75);
    g.addEdge(1, 2, 0.75);
    g.addEdge(2, 1, 0.75);
    g.addEdge(2, 3, 0.75);
    g.addEdge(3, 2, 0.75);
    g.addEdge(3, 0, 0.75);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();

    return 0;
} 