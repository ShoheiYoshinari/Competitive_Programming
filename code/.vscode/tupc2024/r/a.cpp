あ
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
// #include "Src/Utility/BinarySearch.hpp"
// #include "Src/Sequence/CompressedSequence.hpp"
// #include "Src/Sequence/RunLengthEncoding.hpp"
// using namespace zawa;
// #include "atcoder/modint"
// using mint = atcoder::modint998244353;
bool good(const std::string& T) {
    int b = 0;
    for (auto c : T) {
        assert(c != '?');
        b += (c == '(' ? 1 : -1);
        if (b < 0) return false;
    }
    return b == 0;
}
int pw[21];
bool judge(const std::string& S) {
    std::string T = S;
    auto balance = [&]() -> bool {
        int b = 0;
        for (auto c : T) {
            assert(c != '?');
            b += (c == '(' ? 1 : -1);
            if (b < 0) return false;
        }
        return b == 0;
    };
    auto dfs = [&](auto dfs, int t) -> bool {
        bool fn = false;
        for (int i = 0 ; i < (int)T.size() ; i++) if (T[i] == '?') {
            fn = true;
            for (auto c : { '(', ')' }) {
                T[i] = c;
                auto res = dfs(dfs, t ^ 1);
                T[i] = '?';
                if (t == 0 and res) return true;
                else if (t == 1 and !res) return false;
            }
        }
        if (fn == false) return balance();
        else {
            if (t == 0) return false;
            else return true;
        }
    };
    return dfs(dfs, 0);
}
template <class F, class G>
void enumerate(int n, F f, G g) {
    char s[3]{'(', ')', '?'};
    for (int bit = 0 ; bit < pw[n] ; bit++) {
        int v = bit;
        std::string S;
        S.reserve(n);
        for (int i = 0 ; i < n ; i++) {
            S.push_back(s[v % 3]);
            v /= 3;
        }
        if (judge(S)) f(S);
        else g(S);
    }
}
bool solve(const std::string& s) {
    if (std::count(s.begin(), s.end(), '?') == 0) {
        return good(s);
    }
    {
        int sum = 0;
        for (int i = 0 ; i < (int)s.size() ; i++) {
            if (s[i] == '(' or s[i] == '?') sum++;
            else sum--;
            if (sum < 0) return false;
        }
    }
    {
        int sum = 0;
        for (int i = (int)s.size() - 1 ; i >= 0 ; i--) {
            if (s[i] == ')' or s[i] == '?') sum++;
            else sum--;
            if (sum < 0) return false;
        }
    }
    if(s.at(0) == '?' && s.at(s.size()-1) == '?')
    {
        return false;
        // cout << "Second" << endl;
        // continue;
    }
    else if(s.at(0) == ')' || s.at(s.size()-1) == '(')
    {
        return false;
        // cout << "Second" << endl;
        // continue;
    }
    int sum = 0;
    int tem = 0;
    int cnt = 0;
    bool f = true;
    for (int j = 0 ; j < (int)s.size() ; j++) 
    // rep(j,len(s))
    {
        if(s.at(j) == '(')
        {
            sum++;
            tem++;
        }
        else if(s.at(j) == ')')
        {
            sum--;
            tem--;
        }
        else if(s.at(j) == '?')
        {
            cnt++;
            if(cnt == 1)
            {
                if(tem < 0)
                {
                    return false;
                    // cout << "Second" << endl;
                    // f = false;
                    // break;;
                }
            }
            tem = 0;
        }
    }
    if(tem > 0)
    {
        return false;
        // cout << "Second" << endl;
        // continue;
    }

    // if(!f)
    // {
    //     continue;
    // }

    if(cnt == 0)
    {
        if(sum == 0)
        {
            return true;
            // cout << "First" << endl;
        }
        else
        {
            return false;
            // cout << "Second" << endl;
        }
    }
    else
    {
        if(sum == 1)
        {
            if(s.at(0) == '?')
            {
                return false;
                // cout << "Second" << endl;
            }
            else
            {
                return true;
                // cout << "First" << endl;
            }
        }
        else if(sum == -1)
        {
            if(s.at(s.size()-1) == '?')
            {
                return false;
                // cout << "Second" << endl;
            }
            else
            {
                return true;
                // cout << "First" << endl;
            }
        }
        else
        {
            return false;
            // cout << "Second" << endl;
        }
    }
}
int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    // int T;
    // std::cin >> T;
    // while (T--) {
    //     std::string S;
    //     std::cin >> S;
    //     std::cout << (solve(S) ? "First\n" : "Second\n");
    // }
    pw[0] = 1; 
    for (int i = 1 ; i < 21 ; i++) pw[i] = pw[i - 1] * 3;
    int n;
    std::cin >> n;
    auto f = [](const std::string& s) {
        std::cout << "win " << s << std::endl;
        assert(solve(s));
    };
    auto g = [](const std::string& s) {
        std::cout << "lose " << s << std::endl;
        assert(!solve(s));
    };
    enumerate(n, f, g);
}
