#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>

class Graph {
    long mod = 1000000000;
    long V;
    std::vector<long> *adj;
    std::vector<long> *revAdj;
    bool* reachable;
    bool isCyclicUtil(long v, bool visited[], bool *rc);
    // bool isReady(long v);
    // std::set<long>* waitSets;
    // std::set<long>* regSets;
public:
    Graph(long V);
    void addEdge(long v, long w);
    bool isCyclic();
    long pathCount();
    void analyzeReachables();
};

Graph::Graph(long V) {
    this->V = V;
    adj = new std::vector<long>[V];
    revAdj = new std::vector<long>[V];
    reachable = new bool[V];
    // waitSets = new std::set<long>[V];
    // regSets = new std::set<long>[V];
    for (long i = 0; i < V; ++i) reachable[i] = false;
}

void Graph::addEdge(long v, long w) {
    adj[v].push_back(w);
    revAdj[w].push_back(v);
}

void Graph::analyzeReachables() {
    std::queue<long> q;
    q.push(V-1);
    reachable[V-1] = true;
    long v;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (long i : revAdj[v]) {
            // waitSets[v].insert(i);
            if (!reachable[i]) {
                q.push(i);
                reachable[i] = true;
            }
        }
    }
}

bool Graph::isCyclicUtil(long v, bool *visited, bool *rc) {
    std::stack<std::pair<long,long>>* stk = new std::stack<std::pair<long,long>>;
    visited[v] = true;
    rc[v] = true;

    long u, w, node;
    stk->push(std::make_pair(v,0));
    while (!stk->empty()) {
        u = stk->top().first;
        w = stk->top().second;
        if (stk->top().second >= adj[u].size()) {
            stk->pop();
            rc[u] = false;
            continue;
        }
        node = adj[u][w];
        if (!reachable[node]) {
            ++stk->top().second;
            continue;
        }
        if (!visited[node]) {
            visited[node] = true;
            rc[node] = true;
            stk->push(std::make_pair(node,0));
            continue;
        } else if (rc[node]) return true;
        ++stk->top().second;
    }
    rc[v] = false;
    return false;
}


bool Graph::isCyclic() {
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (long i = 0; i < V; ++i) {
        visited[i] = false;
        recStack[i] = false;
    }
    return isCyclicUtil(0, visited, recStack);
}

/*
bool Graph::isReady(long v) {
    return regSets[v].size() == waitSets[v].size();
}*/

long Graph::pathCount() {

    long *counts = new long[V]{0};
    counts[0] = 1;
    std::set<long> set1, set2, *s1 = &set1, *s2 = &set2;
    set2.insert(0);
    while (!s2->empty()) {
        if (s1 == &set1) {
            s1 = &set2;
            s2 = &set1;
        } else {
            s1 = &set1;
            s2 = &set2;
        }
        s2->clear();
        for (long v : *s1) {
            for (long j : adj[v]) {
                if (!reachable[j]) continue;
                counts[j] = (counts[j] + counts[v]) % mod;
                if (j != V-1) s2->insert(j);
            }
            counts[v] = 0;
        }
    }
    return counts[V-1];
}

int main() {
    long n, m, u, v;
    std::cin >> n >> m;
    Graph g(n);
    for (long i = 0; i < m; ++i) {
        std::cin >> u >> v;
        g.addEdge(u-1,v-1);
    }
    g.analyzeReachables();
    if (g.isCyclic()) std::cout << "INFINITE PATHS" << std::endl;
    else std::cout << g.pathCount() << std::endl;
    return 0;
}