#define PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
// Verified On : 2019-08-27

#include "../src/bits/stdc++.h"
#include "../src/commonHeader.hpp"

#include "../src/graphTemplate.cpp"
#include "../src/dijkstra.cpp"

signed main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int V, E, src;
    cin >> V >> E >> src;

    WeightedGraph G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        G[s].emplace_back(t, c);
    }

    const auto dist = dijkstra<less<>, LINF>(G, { src });

    for (i64 d : dist) {
        if (d >= LINF) cout << "INF" << "\n";
        else cout << d << "\n";
    }

    return 0;
}
