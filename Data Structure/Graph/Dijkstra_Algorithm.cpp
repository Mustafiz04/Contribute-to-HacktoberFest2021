/*Dijkstra's algorithm performs n iterations. On each iteration it selects an unmarked vertex v with the lowest value d[v], marks it and checks all the edges (v,to) attempting to improve the value d[to].

The running time of the algorithm consists of:

n searches for a vertex with the smallest value d[v] among O(n) unmarked vertices
m relaxation attempts
For the simplest implementation of these operations on each iteration vertex search requires O(n) operations, and each relaxation can be performed in O(1). Hence, the resulting asymptotic behavior of the algorithm is:

O(n2+m)
This complexity is optimal for dense graph, i.e. when m≈n2. However in sparse graphs, when m is much smaller than the maximal number of edges n2, the problem can be solved in O(nlogn+m) complexity. The algorithm and implementation can be found on the article Dijkstra on sparse graphs.
*/


const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}


/*
Here the graph adj is stored as adjacency list: for each vertex v adj[v] contains the list of edges going from this vertex, i.e. the list of pair<int,int> where the first element in the pair is the vertex at the other end of the edge, and the second element is the edge weight.

The function takes the starting vertex s and two vectors that will be used as return values.

First of all, the code initializes arrays: distances d[], labels u[] and predecessors p[]. Then it performs n iterations. At each iteration the vertex v is selected which has the smallest distance d[v] among all the unmarked vertices. If the distance to selected vertex v is equal to infinity, the algorithm stops. Otherwise the vertex is marked, and all the edges going out from this vertex are checked. If relaxation along the edge is possible (i.e. distance d[to] can be improved), the distance d[to] and predecessor p[to] are updated.

After performing all the iterations array d[] stores the lengths of the shortest paths to all vertices, and array p[] stores the predecessors of all vertices (except starting vertex s). The path to any vertex t can be restored in the following way:
*/


vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}
