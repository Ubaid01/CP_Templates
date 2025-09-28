#include<bits/stdc++.h>
using namespace std ;
// Changed macro to more generalize due to stack-based class-type confusion on raw-arrays.
#define all(x) begin(x), end(x) 
#define nl "\n"

const int alphas = 26 ;
struct Node {
    Node* links[alphas] ;
    bool isEnd ;

    Node() : isEnd( false ) {
        fill( all( links ) , nullptr ) ;
        // memset( links , 0 , sizeof( links ) );
    }

    void deleteChildren() {
        for ( int i = 0; i < alphas ; i++ ) {
            if ( links[i] != nullptr ) {
                links[i] -> deleteChildren() ;
                delete links[i] ;
                links[i] = nullptr ;
            }
        }
    }
} ;

class Trie {
    private:
        Node* root ;
        // Prevent copying to avoid double deletion
        Trie( const Trie& ) = delete ;
        Trie& operator=( const Trie& ) = delete ;
        int convert( char ch ) const { return ch - 'a' ; }

        void dfs( Node* node , const string& pref , int d ) {
            if ( node -> isEnd )
                cout << string( d + 1.0l , ' ' ) << "Word: " << pref << nl ;
            
            for ( int i = 0; i < alphas; i++ ) {
                if ( node -> links[i] ) {
                    cout << string( d + 1.0l , ' ' ) << static_cast<char>( 'a' + i ) << " -> " << nl ;
                    dfs( node -> links[i] , pref + static_cast<char>( 'a' + i ) , d + 1) ;
                }
            }
        }
    public:
        Trie() {
            root = new Node() ;
        }

        void insert( string word ) {
            Node* node = root ;
            for( int i = 0 ; i < word.size() ; i++ ) {
                int idx = convert( word[i] ) ;
                if( ! node -> links[idx] )
                    node -> links[idx] = new Node() ;
                node = node -> links[idx] ;
            }
            node -> isEnd = true ;
        }

        bool search( string word ) {
            Node* node = root ;
            for( int i = 0 ; i < word.size() ; i++ ) {
                int idx = convert( word[i] ) ;
                if( ! node -> links[idx] )
                    return false ;
                
                node = node -> links[idx] ;
            }
            return node -> isEnd ;
        }

        void debug() {
            dfs( root , "" , 0 ) ;
        }

        ~Trie() {
            root -> deleteChildren() ;
            delete root ; root = nullptr ;
        }
} ;