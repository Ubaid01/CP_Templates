#include<bits/stdc++.h>
using namespace std ;

vector<int> kahnAlgo( vector<vector<int>>& adj ) {
    int n = adj.size();
    vector<int> indegree( n , 0 ) ;

    for( int i = 0; i < n; i++ ) {
        for( int& ngbr : adj[i] )
            indegree[ ngbr ]++ ;
    }

    queue<int> q ;
    for( int i = 0 ; i < n ; i++ ) {
        if( !indegree[i] )
            q.push( i ) ;
    }

    vector<int> res ;
    while( !q.empty() ) {
        int node = q.front();
        q.pop();

        res.push_back( node ) ;
        for( int& ngbr : adj[node] ) {
            indegree[ ngbr ]-- ;

            if( indegree[ ngbr ] == 0 )
                q.push( ngbr ) ;
        }
    }
    return res.size() < n ? vector<int>() : res ; // For DFS ; reverse "vector" in end.
}