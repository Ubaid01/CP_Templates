#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ;
using namespace chrono;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Ordered Set (PBDS): Used when need indexing in sets for keys NOT duplicates. To use dups; replace 'T' with pair<T, int> and use counter for 2nd with increasing value.
// os.order_of_key(x) -> # elements strictly < x (like lower_bound index)
// os.find_by_order(k) -> iterator to k-th smallest (0-based)
// Think of:
//   order_of_key(x)  -> "index of x" if sorted
//   find_by_order(k) -> "element at index k"
// Use for: rank queries, inversion count, kth smallest/largest, etc.

using ld = long double ;
using pi = pair<int, int> ;
using ppi = pair<int , pi> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vs = vector<string> ;
using vpi = vector<pi> ;
using vvi = vector<vi> ;

#define f first
#define ss second
#define ctz __builtin_ctzll
#define clz __builtin_clzll
#define popc __builtin_popcountll 
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define all1(x) (x).begin(), (x).end()
#define all3(x, a, b) (x).begin() + (a), (x).begin() + (b)
#define all(...) GET_MACRO(__VA_ARGS__, all3, , all1)(__VA_ARGS__)
#define rall(x) (x).rbegin(), (x).rend()

const int MOD = 1e9 + 7 ;
const int INF = LLONG_MAX ;
#define nl "\n"
#define forn( i, b, e ) for( int i = (b) ; i < (e) ; i++ )
#define forr( i, b, e ) for( int i = (b) ; i >= (e) ; i-- )
void yesNo( bool b ) { cout << ( b ? "YES" : "NO" ) << "\n" ; }
int lcm( int a , int b ) { return a / gcd(a, b) * b ; }
int customPow( int base , int exp , int mod ) { int res = 1LL ; base %= mod ;  while ( exp > 0 ) {  if ( exp & 1 ) res = (res * base) % mod ;  base = (base * base) % mod ;  exp >>= 1LL ;  }  return res ; }
vi sieve( int n ) { vb isPrime( n + 1 , true ) ; isPrime[0] = isPrime[1] = false ;  vi primes ; for( int i = 2 ; i * i <= n ; i++ ) {  if( isPrime[i] ) {  primes.push_back( i ) ;  for( int j = i * i ; j <= n ; j += i )  isPrime[j] = false ;  }  }  return primes ;  }

// Req C++17 version using structured SFINAE, type_traits , iterators
template<typename Container,
         typename = std::enable_if_t<!std::is_same<Container, std::string>::value>>
istream& operator>>(istream& in, Container& cont) { for (auto& ele : cont)  in >> ele;  return in; }

template <typename T>  using detect_begin_t = decltype( begin( declval<T&>() ) ) ;
template <typename T>  using detect_end_t = decltype( end( declval<T&>() ) ) ;
template <typename T,  typename = void>  struct is_iterable : std::false_type {} ;
template <typename T>  struct is_iterable<T, std::void_t<detect_begin_t<T>, detect_end_t<T>>> : std::true_type {};

template<typename T, typename Stream>
class has_ostream_operator {
    template<typename U, typename S>
    static auto test(int) -> decltype( declval<S&>() << declval<U>(), std::true_type() ) ;

    template<typename, typename>
    static std::false_type test(...) ;

public:
    static constexpr bool value = decltype( test<T, Stream>(0) )::value ;
} ;

template<typename Container,
         typename std::enable_if_t<
            is_iterable<Container>::value &&
            !std::is_same<Container, std::string>::value &&
            !has_ostream_operator<Container, std::ostream>::value,
         int> = 0>
ostream& operator<<( ostream& out, const Container& cont ) { out << "{ " ; for ( auto it = begin(cont) ; it != end(cont) ; it++ ) { out << *it ;  if ( next(it) != end(cont) ) out << ", " ; }  out << " }" ;  return out ;  }


void solve() {
    
}

signed main() {
#ifndef ONLINE_JUDGE
    if ( FILE* file = fopen("input.txt", "r") ) {
        freopen("input.txt", "r", stdin) ;
        freopen("output.txt", "w", stdout) ;
        freopen("Error.txt", "w", stderr) ;
        fclose(file) ;
    }
#endif
    FAST_IO

    auto start = high_resolution_clock::now() ;
    int t = 1 ;
    cin >> t ;
    for( int i = 1 ; i <= t ; i++ ) { 
        // cout << "Case " << i << ": " << nl ; 
        solve() ; 
    } 

    auto end = high_resolution_clock::now() ;
    auto duration = duration_cast<milliseconds>( end - start ) ;
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl ;
#endif
    return 0 ;
}