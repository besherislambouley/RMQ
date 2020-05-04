/*
 * let L[i] & R[i] as the interval that i should be in 
 * Mx [i] the minimum value of a number can be in the i'th postion 
 * we can fill both easily
 * now we will try to build the permutation according to the previous two arrays 
 * the Mx [i] condtion can be done by putting the lowest value greater than or equel to Mx [i] in the i'th postion 
 * the L[i] & R[i] problem can be done greedly , suppose we are at postion POS , sort every L[i] & R[i] which L[i] <= POS according to R[i] now if i of the lowest R[i]  >= Mx [POS] put i in the POS 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , k ;
vi in [100009] , out [100009] ;
mset < int > s ;
int Mx [100009] , Val [100009] , done [100009] , L [100009] , R [100009] ;
void no () {
	for ( int i = 0 ; i < n ; i ++ ) cout << -1 << " " ;
	cout << endl ; 
	exit (0) ;
}
int main () {
	cin >> n >> k ;
	for ( int i = 0 ; i < n ; i ++ ) {
		Val [i] = -1 ;
		L [i] = 0 , R [i] = n - 1 ;
	}
	for ( int i = 0 ; i < k ; i ++ ) {
		int l , r , x ;
		cin >> l >> r >> x ;
		in [l] .pb ( x ) ;
		out[r] .pb ( x ) ;
		done [x] = 1 ;
		L [x] = max ( L [x] , l ) ;
		R [x] = min ( R [x] , r ) ;
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( auto u : in [i] ) s .ins ( u ) ;
		if  (s.size()) Mx [i] = *s.rbegin() ;
		for ( auto u : out[i] ) s .era ( s .find ( u ) ) ;
	}
	for ( int i = 0 ; i < n ; i ++ ) in [i] .clear () , out [i] .clear () ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( L [i] > R [i] ) no () ;
		if ( ! done [i] ) C ;
		in [ L[i] ] .pb ( i ) ;
		out[ R[i] ] .pb ( i ) ;
	}
	set < pi > interval ;
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( auto u : in [i] ) interval .ins ( { R [u] , u } ) ;
		if ( interval.size() && interval.begin() -> se >= Mx [i]  ) {
			Val [i] = interval.begin() -> se ;
			interval .era ( interval.begin() ) ;
		}
		for ( auto u : out[i] ) if ( interval .count ( { R[u] , u } ) ) no () ;
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( ! done [i] ) s .ins ( i ) ;
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( Val [i] == -1 ) {
			auto it = s.lb ( Mx [i] ) ;
			if ( it == s.end() ) break ; 
			Val [i] = *it ;
			s .era ( it ) ;
		}
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( Mx [i] > Val [i] ) no () ;
	}
	for ( int i = 0 ; i < n ; i ++ ) cout << Val [i] << " " ;
	cout << endl ;
}
