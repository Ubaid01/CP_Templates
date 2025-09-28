#include<bits/stdc++.h>
using namespace std ;

const int alphas = 26 ;
struct Node {
    vector<int> links ; // OR can use unordered_map<char, Node*> OR Node* links[26] directly with Node* root BUT avoided due to manual dels/resource acquisition.
    bool isEnd ;
    // int countPref , countEnd ;

    Node() : isEnd( false ) {
        links = vector<int>( alphas, -1 ) ;
    }
} ;

class Trie {
private:
    vector<Node> root ;
    int convert( char ch ) const { return ch - 'a'; }
public:
    Trie() {
        root.push_back( Node() ) ;
    }
    void insert( string word ) {
        int node = 0 ;
        for( char& ch : word ) {
            int idx = convert(ch) ;
            if( root[node].links[idx] == -1 ) {
                root[node].links[idx] = root.size() ;
                root.push_back( Node() ) ;
            }
            node = root[node].links[idx] ;
        }
        root[node].isEnd = true ;
    }
    bool search( string word ) {
        int node = 0 ;
        for( char& ch : word ) {
            int idx = convert(ch) ;
            if( root[node].links[idx] == -1 ) 
                return false ;
            node = root[node].links[idx] ;
        }
        return root[node].isEnd ;
    }
} ;