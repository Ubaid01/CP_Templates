// Credits to HealthyUG for the inspiration.
// Highly customizable Segment Tree.

#include<bits/stdc++.h>
using namespace std ;
#define all(x) (x).begin() , (x).end()

struct Node {
    int val ;
    Node( int val = 0 ) : val(val) {}
    void merge( Node& left , Node& right ) {
        val = left.val + right.val ;
    }
} ;

struct Update {
    int val ;
    Update( int val = 0 ) : val(val) {}
    void apply( Node& node , int l , int r ) {
        node.val += val * ( r - l + 1ll ) ; // Currently lazyUpdate is via updating val NOT replacing.
    }
    void propagate( Update& newU ) {
        val += newU.val ;
    }
    void modify( Node& node ) {
        node.val = val ;
    }
} ;

class SegmentTree {
    private:
        int n ;
        vector<Node> segTree ;
        vector<Update> lazyTree ;

        void buildTree( int node , int start , int end , vector<int>& arr ) {
            if( start == end ) {
                segTree[node] = Node( arr[start] ) ;
                return ;
            }

            int mid = start + (end - start) / 2 ;
            buildTree( 2 * node + 1 , start , mid , arr ) ;
            buildTree( 2 * node + 2 , mid + 1 , end , arr ) ;
            segTree[ node ].merge( segTree[2 * node + 1] , segTree[2 * node + 2] ) ;
        }

        void updateTree( int i , int l , int r , int& idx , Update& u1 ) {
            pushdown( i , l , r ) ;
            if( l == r ) {
                u1.modify( segTree[i] ) ;
                return ;
            }

            int mid = l + (r - l) / 2 ;
            if( idx <= mid )
                updateTree( 2*i + 1 , l , mid , idx , u1 ) ;
            else
                updateTree( 2*i + 2 , mid + 1 , r , idx , u1 ) ;
            
            segTree[i].merge( segTree[2 * i + 1] , segTree[2 * i + 2] ) ;
        }

        void pushdown( int i , int l , int r ) {
            if( lazyTree[i].val ) {
                lazyTree[i].apply( segTree[i] , l , r ) ;
                if( l != r ) {
                    lazyTree[2 * i + 1].propagate( lazyTree[i] ) ;
                    lazyTree[2 * i + 2].propagate( lazyTree[i] );
                }
                lazyTree[i] = Update() ;
            }
        }

        void lazyUpdateRange( int i , int l , int r , int start , int end , Update& u1 ) {
            if( r < start || l > end )
            return ;
            
            pushdown( i , l , r ) ;
            if( start <= l && r <= end ) {
                u1.apply( segTree[i] , l , r ) ;
                if( l != r ) {
                    lazyTree[2 * i + 1].propagate( u1 ) ;
                    lazyTree[2 * i + 2].propagate( u1 ) ;
                }
                return ;
            }

            int mid = l + (r - l) / 2 ;
            lazyUpdateRange( 2*i + 1 , l , mid , start , end , u1 ) ;
            lazyUpdateRange( 2*i + 2 , mid + 1 , r , start , end , u1 ) ;
            segTree[i].merge( segTree[2 * i + 1] , segTree[2 * i + 2] ) ;
        }

        Node query( int i , int l , int r , int start , int end ) {
            if( r < start || l > end )
                // return Node( numeric_limits<int>::lowest() );
                return Node() ;
            
            pushdown( i , l , r ) ;
            if( start <= l && r <= end )
                return segTree[i] ;
            
            int mid = l + (r - l) / 2 ;
            Node left = query( 2*i + 1 , l , mid , start , end ) ;
            Node right = query( 2*i + 2 , mid + 1 , r , start , end ) ;
            Node res ;
            res.merge( left , right ) ;
            return res ;
        }

    public:
        SegmentTree( vector<int> nums ) : n( nums.size() ) , segTree(4 * n , 0) , lazyTree( 4 * n , 0 ) {
            // segTree.resize( 2 * n - 1 ) ;
            fill( all( segTree ) , Node() ) ;
            fill( all( lazyTree ) , Update() ) ;
            buildTree( 0 , 0 , n - 1 , nums ) ;
        }

        void update( int index , int val ) {
            if( index < 0 || index >= n )  return ;
            Update u1( val ) ;
            updateTree( 0 , 0 , n - 1  , index , u1 ) ;
        }

        void lazyUpdateRange( int start , int end , int val ) {
            Update u1( val ) ;
            lazyUpdateRange( 0 , 0 , n - 1 , start , end , u1 ) ;
        }

        int query( int start , int end ) {
            // if( start > end )   swap( start, end ) ;
            return query( 0 , 0 , n - 1 , start , end ).val ;
        }
} ;