#include "bits/stdc++.h"
using namespace std;

//@@@@@
//@ snippet FenwickTree
//@ alias   BIT
//@ options head
template <class T> struct FenwickTree { // {{{
    vector<T> dat;
    explicit FenwickTree(int size): dat(size + 5, 0) {}
    inline void add(int i, const T&v) { while(i < dat.size()){ dat[i]+=v; i += i&-i;} }
    inline T sum(int i)         const { return (i<=0)? 0 : dat[i] + sum(i - (i&-i)); }
    inline T sum(int s, int t)  const { if(s>t) swap(s,t); return sum(t) - sum(s-1); }
}; // }}}
//@@@@@


/*
 * Verified on : 2019-06-02
 * https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
 */
void AOJ_DSL_2_B() // {{{
{
    int N, Q;
    cin >> N >> Q;

    FenwickTree<int> ft(N);
    while(Q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            ft.add(x, y);
        } else {
            cout << (ft.sum(x, y)) << '\n';
        }
    }
} // }}}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    AOJ_DSL_2_B();

    return 0;
}
