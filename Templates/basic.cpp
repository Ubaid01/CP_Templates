#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
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
#define int long long
#define all(x) begin(x), end(x)
#define nl "\n"
void yesNo( bool b ) { cout << ( b ? "YES" : "NO" ) << "\n" ; }

void solve() {

}

signed main() {
    FAST_IO
    int t = 1 ;
    cin >> t ;
    for( int i = 1 ; i <= t ; i++ ) { 
        // cout << "Case " << i << ": " << nl ; 
        solve() ; 
    } 
    return 0;
}