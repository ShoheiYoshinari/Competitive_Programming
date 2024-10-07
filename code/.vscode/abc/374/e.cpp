// C++ includes used for precompiling -*- C++ -*-
// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.
// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.
/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */
// 17.4.1.2 Headers
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
using ll = long long;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()

struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

ll n, x;

bool taskAchieve(ll W_target, vector<ll>& a, vector<ll>& p, vector<ll>& b, vector<ll>& q) {
    ll total_cost = 0;

    rep(i, n) {
        ll min_cost_s = LLONG_MAX, min_cost_t = LLONG_MAX;
        for (ll s = 0; s <= a[i]; s++) {
            ll remaining_capacity = max(0LL, W_target - s * a[i]);
            ll t = (remaining_capacity + b[i] - 1) / b[i];
            ll total = s * p[i] + t * q[i];
            min_cost_s = min(min_cost_s, total);
        }

        for(ll t = 0; t <= b[i]; i++){
            ll remaining_capacity = max(0LL, W_target - t * b[i]);
            ll s = (remaining_capacity + a[i] - 1) / a[i];
            ll total = s * p[i] + t * q[i];
            min_cost_t = min(min_cost_t, total);
        }
        total_cost = min(min_cost_s, min_cost_t);
        if (total_cost > x) return false;
    }

    return total_cost <= x;
}

int main() {
    cin >> n >> x;
    vector<ll> a(n), b(n), p(n), q(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    ll ans = 0;
    ll ok = -1, ng = 1e9 + 1;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (taskAchieve(mid, a, p, b, q)) {
            ans = mid;
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ans << endl; 
    return 0;
}
