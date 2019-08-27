#include "bits/stdc++.h"
using namespace std;

#ifndef INCLUDED_YDK_GRAPH_CPP
#define INCLUDED_YDK_GRAPH_CPP

//@@@@@@@
//@ snippet edge
//@ alias   graph
//@ options  head
struct Edge { // {{{
    int src, to;
    int64_t cost = 0;

    inline Edge(int src,  int to, const int64_t &cost) noexcept :
        src(src), to(to), cost(cost) {}

    inline Edge(int to, const int64_t &cost) noexcept :
       src(-1), to(to), cost(cost) {}

    inline Edge() noexcept {}

    bool operator< (const Edge &o) const noexcept { return cost < o.cost; }
    bool operator> (const Edge &o) const noexcept { return o < *this; }

    Edge& operator=(int to) noexcept {
        this->to = to;
        return *this;
    }

    operator int() const noexcept { return to; }
};
// }}}
using WeightedGraph     = vector<vector<Edge>>;
using UnWeightedGraph   = vector<vector<int>>;
//@@@@@@


//@@@@@@@
//@ snippet MatrixGraph
//@ alias   matrixGraph
//@ options  head
template<size_t N>
class MatrixGraph { // {{{
    int64_t G[N][N];

public:
    constexpr MatrixGraph() noexcept { init(); }

    inline void init() noexcept {
        memset(G, 0x3f, sizeof(G));
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
//@ snippet dfs_arrivable
//@ alias   arrivable
//@ options head
template<class GraphType>
void dfs_arrivable(int u, const GraphType &G, bool visited[]) { // {{{
    if (!visited[u]) {
        visited[u] = true;
        for (const int to : G[u]) dfs_arrivable(to, G, visited);
    }
} // }}}
//@@@@@@@@@@

#endif /* End of include-guard */
