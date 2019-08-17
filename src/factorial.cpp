#include "bits/stdc++.h"
#include "commonHeader.hpp"

#include "modint.cpp"

#ifndef INCLUDED_YDK_FACTORIAL_CPP
#define INCLUDED_YDK_FACTORIAL_CPP

//@@@@@@@
//@ snippet Factorial
//@ alias   invfact nCr nPr
//@ options head
// Factorial, InvFact {{{
#ifdef DBG
#define constexpr /* Disable constexpr */
#endif
template<size_t N, int MOD = int(1e9) + 7>
struct Factorial {
    uint_fast64_t f[N+1];

    constexpr inline Factorial() : f{1} {
        for (int i = 1; i <= N; ++i) f[i] = (f[i-1] * i) % MOD;
    }

    constexpr inline ModInt<MOD> operator[] (size_t i) const { return f[i]; }
};

template<size_t N, int MOD = int(1e9) + 7>
struct InvFact {
    uint_fast64_t inv[N+1];
    uint_fast64_t f[N+1];

    constexpr inline InvFact() : inv{0, 1}, f{1, 1} {
        for (int i = 2; i <= N; ++i) {
            inv[i] = (MOD - MOD/i) * inv[MOD % i] % MOD;
            f[i] = f[i-1] * inv[i] % MOD;
        }
    }

    constexpr inline ModInt<MOD> operator[] (size_t i) const { return f[i]; }
};
#ifdef constexpr
#undef constexpr
#endif
// }}}

constexpr int MOD = int(1e9) + 7;

Factorial<100010, MOD> fact;
InvFact<100010, MOD> invFact;

ModInt<MOD> nCr(int n, int r) { return (r < 0 || n < r) ? 0 : (fact[n] * (invFact[r] * invFact[n-r])); }
ModInt<MOD> nPr(int n, int r) { return (r < 0 || n < r) ? 0 : (fact[n] * invFact[r]); }
ModInt<MOD> nHr(int n, int r) { return nCr(n+r-1, r); }
//@@@@@@@

#endif /* End of include-guard */