#include<bits/stdc++.h>
using namespace std ;
// Changed macro to more generalize due to stack-based class-type confusion on raw-arrays.
#define all(x) begin(x), end(x) 

const int alphas = 26 ;
struct Node {
    Node* links[alphas] ;
    bool isEnd ;

    Node() : isEnd( false ) {
        fill( all( links ) , nullptr ) ;
        // memset( links , 0 , sizeof( links ) );
    }
} ;

class Trie {
    private:
        Node* root ;
    public:
        Trie() {
            root = new Node() ;
        }

        void insert( string word ) {
            Node* node = root ;
            for( int i = 0 ; i < word.size() ; i++ ) {
                int idx = word[i] - 'a' ;
                if( ! node -> links[idx] )
                    node -> links[idx] = new Node() ;
                node = node -> links[idx] ;
            }
            node -> isEnd = true ;
        }

        bool search( string word ) {
            Node* node = root ;
            for( int i = 0 ; i < word.size() ; i++ ) {
                int idx = word[i] - 'a' ;
                if( ! node -> links[idx] )
                    return false ;
                
                node = node -> links[idx] ;
            }
            return node -> isEnd ;
        }
} ;