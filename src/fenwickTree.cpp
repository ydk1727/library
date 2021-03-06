#include "bits/stdc++.h"
#include "commonHeader.hpp"

#ifndef INCLUDED_YDK_FENWICK_TREE_CPP
#define INCLUDED_YDK_FENWICK_TREE_CPP

//@@@@@
//@ snippet FenwickTree
//@ alias   BIT
//@ options head
template <class T> struct FenwickTree { // {{{
    vector<T> dat;
    const size_t SIZE_POW2;

    explicit FenwickTree(int size): dat(size+5, 0), SIZE_POW2(1 << (__lg(size+5)+1)) {}

    inline void add(int i, const T &v){
        for (++i; i < dat.size(); i += i & -i) dat[i]+=v;
    }

    inline T sum(int i) const {
        T s = 0;
        for (++i; i > 0; i -= i & -i) s += dat[i];
        return s;;
    }

    inline T sum(int s, int t) const {
        if (s > t) swap(s, t);
        return sum(t) - sum(s - 1);
    }

    inline int lower_bound(T v) const {
        if (v <= 0) return 0;
        int i = 0;
        for (int w = SIZE_POW2; w > 0; w >>= 1) {
            if (i + w < dat.size() && dat[i + w] < v) {
                v -= dat[i + w];
                i += w;
            }
        }
        return i;
    }
}; // }}}
//@@@@@

#endif /* end of include guard */
