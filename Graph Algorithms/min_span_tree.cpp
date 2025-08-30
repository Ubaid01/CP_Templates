#include<bits/stdc++.h>
using namespace std ;
#define all(x) (x).begin() , (x).end()

class DSU {
private:
    vector<int> parent , size ;
public:
    DSU( int n ) : size( n + 1 , -1 ) {
        parent.resize( n + 1 ) ;
        iota( all( parent ) , 0 ) ;
    }

    int findPar( int node ) {
        if( parent[node] == node )
            return node ;
        return parent[node] = findPar( parent[node] ) ;
    }

    void unionSize( int u , int v ) {
        int pU = findPar( u ) , pV = findPar( v ) ;
        if( pU == pV )
            return ;
        if( size[pU] < size[pV] ) {
            parent[pU] = pV ;
            size[pV] += size[pU] ;
        }
        else {
            parent[pV] = pU ;
            size[pU] += size[pV] ;
        }
    }
} ;

vector<vector<int>> kruskalMST( int n , vector<vector<int>>& edges ) {
    // edges = { { wt , u , v } }
    sort( all( edges ) ) ;
    // int n = 0 ;
    // for( vector<int>& edge : edges )
    //     n = max( { n , edge[1] , edge[2] } ) ;
    // n++ ; // To include last node.
        
    DSU dsu( n ) ;
    vector<vector<int>> MST ;
    for( vector<int>& edge : edges ) {
        int wt = edge[0] , u = edge[1] , v = edge[2] ;
        if( dsu.findPar( u ) == dsu.findPar( v ) )
            continue ;
        dsu.unionSize( u , v ) ;
        MST.push_back( { min( u , v ) , max( u , v ) , wt } ) ;
    }
    return MST ;
}

vector<vector<int>> primsMST( int n , vector<vector<int>>& edges ) {
    vector<vector<vector<int>>> adj( n ) ;
    for( vector<int>& edge : edges ) {
        int u = edge[0] , v = edge[1] , wt = edge[2] ;
        adj[u].push_back( { v , wt } ) ;
        adj[v].push_back( { u , wt } ) ;
    }

    priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq ;
    pq.push( { 0 , 0 , -1 } ) ; // { wt , node , parent }
    vector<bool> visited( n , false ) ;
    vector<vector<int>> MST ;

    while( !pq.empty() ) {
        int wt = pq.top()[0] ;
        int node = pq.top()[1] ;
        int parent = pq.top()[2] ;
        pq.pop() ;

        if( visited[node] ) continue ;
        visited[node] = true ;

        if( parent != -1 )
            MST.push_back( { parent , node , wt } ) ;
        
        for( vector<int>& ngbr : adj[node] ) {
            int ngbrWt = ngbr[1] ;
            if( !visited[ ngbr[0] ] )
                pq.push( { ngbrWt , ngbr[0] , node } ) ;
        }
    }
    return MST ;
}