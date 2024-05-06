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
#define rep(i, s) for(int i = 1; i < (int)s; i++)
#define rep2(i, v, s) for(int i = (int)v; i <= (int)s; i++)

int main(){
    int a, b, c, x, y, sum = 0;
    cin >> a >> b >> c >> x >> y;

    if(a + b <= c * 2){
        cout << a * x + b * y << endl;
    }else{
        int min_half = min(x, y);
        int max_half = max(x, y);
        int candi1 =  a*(x-min_half) + b*(y-min_half) + c*2*min_half;
        int candi2 = c*2*max_half;
        cout << min(candi1, candi2) << endl;
    }
}
