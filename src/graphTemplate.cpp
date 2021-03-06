#include "bits/stdc++.h"
using namespace std;

#ifndef INCLUDED_YDK_GRAPH_CPP
#define INCLUDED_YDK_GRAPH_CPP

//@@@@@@@
//@ snippet graph
//@ options head
// graph {{{
struct Edge { // {{{
    int src, to;
    int64_t cost = 0;

    inline Edge() noexcept {}
    inline Edge(int s,  int t, int64_t c = 1) noexcept : src(s), to(t), cost(c) {}

    inline bool operator<(const Edge &rhs) const noexcept { return cost < rhs.cost; }
    inline bool operator>(const Edge &rhs) const noexcept { return rhs < *this; }

    inline operator int() const noexcept { return to; }

    inline Edge& operator=(int rhs_to) noexcept { this->to = rhs_to; return *this; }
};
// }}}

class Graph : public vector<vector<Edge>> { // {{{
    using super = vector<vector<Edge>>;
public:
    Graph() noexcept {}
    Graph(int V) noexcept : super(V) {}

    Graph& addEdge(int from, int to, int64_t cost = 1) noexcept {
        super::operator[](from).emplace_back(from, to, cost);
        return *this;
    }

    Graph& addEdge(const Edge &e) noexcept {
        return addEdge(e.src, e.to, e.cost);
    }

    friend ostream& operator<<(ostream &out, const Graph &g) {
        for (int i = 0; i < g.size(); ++i) {
            out << '[' << setw(2) << i << ']';
            for (const auto &e : g[i]) {
                out << ' ' << setw(2) << e.to;
            }
            out << '\n';
        }
        return out;
    }
}; // }}}
// }}}
//@@@@@@


//@@@@@@@
//@ snippet MatrixGraph
//@ alias   matrixGraph
//@ options  head
template <size_t N>
class MatrixGraph { // {{{
    int64_t G[N][N];

    #ifdef DBG
    #define constexpr /* disable constexpr */
    #endif

public:
    constexpr MatrixGraph() noexcept { init(); }

    inline constexpr void init() noexcept {
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) G[i][j] = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0; i < N; ++i) G[i][i] = 0;
    }

    int64_t* operator[](int i) noexcept {
        return G[i];
    }

    const int64_t* operator[] (int i) const noexcept {
        return G[i];
    }
};
// }}}
//@@@@@@@@

//@@@@@@@@@@
//@ snippet reverseGraph
//@ options head
Graph reverseGraph(const Graph &G) noexcept { // {{{
    const int V = G.size();
    Graph revG(V);
    for (int i = 0; i < V; ++i) {
        const auto &nodes = G[i];
        revG.reserve(nodes.size());
        for (const auto &e : nodes) revG.addEdge(e.to, i, e.cost);
    }
    return revG;
} // }}}
//@@@@@@@@@@


//@@@@@@@@@@
//@ snippet dfs_arrivable
//@ alias   arrivable
//@ options head
template <class BoolArray>
void dfs_reachable(const Graph &G, int v, BoolArray &visited) { // {{{
    if (!visited[v]) {
        visited[v] = true;
        for (const int to : G[v]) dfs_reachable(G, to, visited);
    }
} // }}}
//@@@@@@@@@@

//@@@@@@@@@@
//@ snippet onlyReachableNode
//@ alias   filter_onlyReachableNode
//@ options head
Graph filter_onlyReachableNode(const Graph &g, int startNode) noexcept { // {{{
    const int V = g.size();
    vector<uint8_t> visited(V, 0u);
    Graph filteredGraph(V);

    dfs_reachable(g, startNode, visited);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) continue;
        for (const Edge &e : g[i]) {
            if (visited[e.to]) filteredGraph.addEdge(e);
        }
    }

    return filteredGraph;
} // }}}
//@@@@@@@@@@

#endif /* End of include-guard */
