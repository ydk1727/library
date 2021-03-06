#include "bits/stdc++.h"
#include "commonHeader.hpp"

//@@@@@@
//@ snippet digits
//@ options head
inline vector<int> digits(unsigned long long n) { // {{{
    vector<int> ret;
    do { ret.push_back(n % 10); n /= 10; } while(n > 0);
    reverse(ret.begin(), ret.end());
    return ret;
} // }}}
//@@@@



//@@@@@@@@@@
//@ snippet clamp
//@ options head
template <class T, class Low, class High>
common_type_t<T, Low, High> clamp(const T &x, const Low &low, const High &high) {
    return (x < low) ? low : (x > high) ? high : x;
}
//@@@@@@@@@@



//@@@@@@@@@@
//@ snippet runLengthEncoding
//@ alias   RLE RunLengthEnc
//@ options head
template<class Iterator>
auto runLengthEncoding(Iterator begin, Iterator end) { // {{{
    using value_type = typename iterator_traits<Iterator>::value_type;

    vector<pair<value_type, int>> res;
    res.reserve(distance(begin, end));
    int cnt = 1;

    Iterator prevBegin;
    for (prevBegin = begin++;  begin != end;  prevBegin = begin++) {
        if (*prevBegin == *begin) {
            ++cnt;
        } else {
            res.emplace_back(*prevBegin, cnt);
            cnt = 1;
        }
    }
    res.emplace_back(*prevBegin, cnt);

    return res;
} // }}}
//@@@@@@@@@@


//@@@@@@@@@@
//@ snippet syakutori
//@ alias   shakutori
//@ options head
// syakutori {{{
    template<class Array>
i64 syakutori(const Array &a, int N)
{
    i64 ans = 0;
    int left, right = 0;

    const auto isOK = [&](int i) { return i; };
    const auto proc = [&](int i) { i; };

    for (left = 0; left < N; ++left) {
        while(right < N && isOK(right)) {
            proc(right);
            ++right;
        }

        /* TODO update ans */

        if (right == left) {
            ++right;
        } else {
            // sum -= a[left];
        }
    }

    return ans;
}
// }}}
//@@@@@@@@@@


//@@@@@@@@@@
//@ snippet split
//@ options head
vector<string> split(const string &str, const string &delim) // {{{
{
    vector<string> ret;
    string buf;

    for (char c : str) {
        if (any_of(delim.begin(), delim.end(), [c](char x) { return c == x; })) {
            if (!buf.empty()) { ret.push_back(buf); buf.clear(); }
        } else {
            buf += c;
        }
    }

    return ret;
} // }}}
//@@@@@@@@@@
