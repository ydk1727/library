#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

//@@@@@@@@@@@
//@ snippet SegTree
//@ alias   segtree
//@ options head
template<class Monoid>
struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const int sz;
    const Func fn;
    const Monoid unity;
    vector<Monoid> dat;

    SegTree(int n, const Monoid &u, Func f)
        : sz(1 << (__lg(n+5) + 1)), fn(f), unity(u), dat(sz*2, unity) {}

    void set(int k, const Monoid &v) { dat[k + sz] = v; }

    Monoid& operator[] (int k) { return dat[k + sz]; }

    void build() { for (int k = sz-1; k > 0; --k) dat[k] = fn(dat[2*k], dat[2*k+1]); }

    void update(int k, const Monoid &v) {
        dat[ k += sz ] = v;
        while(k >>= 1) dat[k] = fn(dat[2*k], dat[2*k+1]);
    }

    Monoid query(int a, int b) const {
        Monoid L = unity,  R = unity;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = fn(L, dat[a++]);
            if (b & 1) R = fn(dat[--b], R);
        }
        return fn(L, R);
    }
};
//@@@@@@@@@



/*
 * Verified on 2019-06-02
 * https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
 */
void AOJ_DSL_2_A()
{
    int N, Q;
    int com, x, y;

    scanf("%d%d", &N, &Q);
    SegTree<int> seg(N, (1LL << 31) - 1, [](int a, int b){ return min(a,b); });

    while(Q--) {
        scanf("%d%d%d", &com, &x, &y);
        if (com == 0) {
            seg.update(x, y);
        } else {
            printf("%d\n", seg.query(x, y+1));
        }
    }
    return;
}

int main()
{
    AOJ_DSL_2_A();
    return 0;
}

