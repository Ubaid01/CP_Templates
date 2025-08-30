#include<bits/stdc++.h>
using namespace std ;

vector<int> dijkstra( int src , vector<vector<int>>& adj ) {
    int n = adj.size() ;
    priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>>> pq ; 
    pq.push( { 0 , src } ) ;
    vector<int> dist( n , INT_MAX ) ;
    vector<int> par( n , -1 ) ;
    dist[src] = 0 ;

    while( !pq.empty() ) {
        int d = pq.top()[0] ;
        int node = pq.top()[1] ;
        pq.pop() ;

        if( d > dist[node] ) continue ;
        for( int& ngbr : adj[node] ) {
            if( dist[node] + 1 < dist[ngbr] ) {
                dist[ngbr] = dist[node] + 1 ;
                par[ngbr] = node ;
                pq.push( { dist[ngbr] , ngbr } ) ;
            }
        }
    }
    return dist ;
}

vector<int> bellmanFord( int n , int src , vector<vector<int>>& edges ) {
    vector<int> dist( n , INT_MAX ) ;
    dist[src] = 0 ;

    for( int i = 0 ; i < n - 1 ; i++ ) {
        for( vector<int>& edge : edges ) {
            int u = edge[0] , v = edge[1] , wt = edge[2] ;
            
            if( dist[u] != INT_MAX && dist[u] + wt < dist[v] )
                dist[v] = dist[u] + wt ;
        }
    }

    for( vector<int>& edge : edges ) {
        int u = edge[0] , v = edge[1] , wt = edge[2] ;
        
        if( dist[u] != INT_MAX && dist[u] + wt < dist[v] )
            return {} ; // -ve DIST CYCLE only.
    }
    return dist ;
}

vector<vector<int>> floydWarshall( int n , vector<vector<int>>& edges ) {
    vector<vector<int>> dist( n , vector<int>( n , INT_MAX ) ) ;
    for( int i = 0 ; i < n ; i++ ) 
        dist[i][i] = 0 ;
    
    for( vector<int>& edge : edges ) {
        int u = edge[0] , v = edge[1] , wt = edge[2] ;
        dist[u][v] = min( dist[u][v] , wt ) ;
    }

    for( int k = 0 ; k < n ; k++ ) {
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if ( dist[i][k] != INT_MAX && dist[k][j] != INT_MAX )
                    dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j] ) ;
            }
        }
    }
    return dist ;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},  // neighbors of 0
        {3},     // neighbors of 1
        {3},     // neighbors of 2
        {4},     // neighbors of 3
        {}       // neighbors of 4
    };

    vector<int> dist = dijkstra(0, adj);
    for (int i = 0; i < dist.size(); i++) {
        cout << "Distance from 0 to " << i << " = " << dist[i] << "\n";
    }

    int n = 5; // number of nodes
    int src = 0;

    // Each edge is {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, -22},
        {2, 3, 3},
        {3, 4, 2}
    };

    vector<int> dist2 = bellmanFord(n , src, edges);

    if ( dist2.empty() )
        cout << "Negative cycle detected.\n";
    else {
        for (int i = 0; i < n; ++i) {
            if (dist2[i] == INT_MAX) cout << "Distance to " << i << ": INF\n";
            else cout << "Distance to " << i << ": " << dist2[i] << "\n";
        }
    }

    vector<vector<int>> dist3 = floydWarshall(n , edges);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist3[i][j] == INT_MAX) cout << "Distance from " << i << " to " << j << ": INF\n";
            else cout << "Distance from " << i << " to " << j << ": " << dist3[i][j] << "\n";
        }
    }
    return 0;
}
