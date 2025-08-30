#include<bits/stdc++.h>
using namespace std ;
#define all(x) (x).begin() , (x).end()

// Only for Directed Graphs.
void topoSort( int node , vector<vector<int>>& adj , vector<bool>& visited , vector<int>& topo ) {
    visited[node] = true ;
    for( int& ngbr : adj[node] ) {
        if( !visited[ngbr] )
            topoSort( ngbr , adj , visited , topo ) ;
    }
    topo.push_back( node ) ;
}

void getComponent( int node , vector<vector<int>>& adj , vector<bool>& visited , vector<int>& curComp ) {
    visited[node] = true ;
    curComp.push_back( node ) ;
    for( int& ngbr : adj[node] ) {
        if( !visited[ngbr] )
            getComponent( ngbr , adj , visited , curComp ) ;
    }
}

vector<vector<int>> kosarajuSCC( int n , vector<vector<int>>& adj ) {
    vector<bool> visited( n , false ) ;
    vector<int> topo ;
    for( int i = 0 ; i < n ; i++ ) {
        if( !visited[i] )
            topoSort( i , adj , visited , topo ) ;
    }

    vector<vector<int>> revAdj( n ) ;
    for( int i = 0 ; i < n ; i++ ) {
        for( int& ngbr : adj[i] )
            revAdj[ ngbr ].push_back( i ) ;
    }

    fill( all( visited ) , false ) ;
    vector<vector<int>> sccComps ;
    for( int i = topo.size() - 1 ; i >= 0 ; i-- ) {
        if( !visited[ topo[i] ] ) {
            vector<int> curComp ;
            getComponent( topo[i] , revAdj , visited , curComp ) ;
            sccComps.push_back( curComp ) ;
        }
    }
    return sccComps ;
}