#include<bits/stdc++.h>
using namespace std ;

bool detectUdCycle( int src , int par , vector<vector<int>>& adj , vector<bool>& visited ) {
    visited[src] = true ;
    for( int& ngbr : adj[src] ) {
        if( !visited[ngbr] ) { // USING && will give wrong ANS as if rec=false SO else-if will run for BASE-CASE giving false cycle.
            if( detectUdCycle( ngbr , src , adj , visited ) )
                return true ;
        }
        else if( par != ngbr )
            return true ;
    }
    return false ;
}

bool detectDirCycle( int src , vector<vector<int>>& adj , vector<int>& visited ) {
    visited[src] = 1 ;
    for( int& ngbr : adj[src] ) {
        if( !visited[ngbr] && detectDirCycle( ngbr , adj , visited ) )
            return true ;
        else if( visited[ngbr] == 1 )
            return true ;
    }

    visited[src] = 2 ; 
    return false ;
}