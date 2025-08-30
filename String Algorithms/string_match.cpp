#include<bits/stdc++.h>
using namespace std ;

void computeLPS( string& pattern , vector<int>& lps ) {
    lps[0] = 0 ;
    int len = 0 ;
    int i = 1 , m = pattern.length() ;

    while( i < m ) {
        if( pattern[i] == pattern[len] ) {
            len++ ;
            lps[i] = len ;
            i++ ;
        }
        else {
            if( len != 0 )
                len = lps[ len - 1 ] ;
            else {
                lps[i] = 0 ; 
                i++ ;
            }
        }
    }
}

void KMP( string text , string pattern ) {
    int m = pattern.length() ;
    int n = text.length() ;
    vector<int> lps(m) ;
    computeLPS( pattern , lps ) ; 
    int i = 0 , j = 0 ;

    while( i < n ) {
        if( text[i] == pattern[j] ) {
            i++ ;
            j++ ;
        }

        if ( j == m ) {
            cout << "Pattern found at index " << i - j << '\n' ;
            j = lps[j - 1] ;
            // return ;
        }
        else if( i < n && text[i] != pattern[j] ) {
            if( j != 0 )
                j = lps[ j - 1 ] ;
            else
                i++ ;
        }
    }
}