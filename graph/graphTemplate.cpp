#include "bits/stdc++.h"
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF  = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;


//@@@@@@@
//@ snippet edge
//@ alias   graph
//@ options  head
struct Edge { // {{{
    int src, to;
    i64 cost;
    Edge(int src,  int to, i64 cost) : src(src), to(to), cost(cost) {}
    Edge(int to, i64 cost = 0) : Edge(-1, to, cost) {}
    Edge() {}
    bool operator< (const Edge &o) const { return cost < o.cost; }
    bool operator> (const Edge &o) const { return cost > o.cost; }
};
using Edges = vector<Edge>;
using WGraph = vector<vector<Edge>>;
using UGraph = vector<vector<int>>;
// }}}
//@@@@@@


//@@@@@@@
//@ snippet MatrixGraph
//@ alias   matrixGraph
//@ options  head
template<size_t N>
struct MatrixGraph { // {{{
    i64 G[N][N];
    constexpr explicit MatrixGraph() {
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) G[i][j] = LINF;
        for (int i = 0; i < N; ++i) G[i][i] = 0;
    }
    i64* operator[] (size_t i) { return G[i]; }
    const i64* operator[] (size_t i) const { return G[i]; }
};
// }}}
//@@@@@@@@
