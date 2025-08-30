#include<bits/stdc++.h>
using namespace std ;

bool bipartiteDFS( int node , int c , vector<vector<int>>& adj , vector<int>& colors ) {
    colors[node] = c ;
    for( int& ngbr : adj[node] ) {
        if( colors[ngbr] == -1 ) {
            if( bipartiteDFS( ngbr , 1 - c , adj , colors ) )
                return false ;
        }
        else if( colors[ngbr] == c )
            return false ;
    }    
    return true ;
}

bool isBipartite( int n , vector<vector<int>>& edges ) {
    vector<vector<int>> adj( n ) ;
    for( vector<int>& edge : edges ) {
        int u = edge[0] , v = edge[1] ;
        adj[u].push_back( v ) ;
        adj[v].push_back( u ) ;
    }

    vector<int> colors( n , -1 ) ;
    for( int i = 0 ; i < n ; i++ ) {
        if( colors[i] == -1 && !bipartiteDFS( i , 0 , adj , colors ) )
            return false ;
    }
    return true ;
}