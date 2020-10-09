//segment tree

//this is my cpp functions that i used to solve segmented tree problems


// limit for array size 
const ll N = 1000001; 

ll n; // array size 

// Max size of tree 
ll tree[2 * N]; 

// function to build the tree 
void build( ll arr[]) 
{ 
	// insert leaf nodes in tree 
	for (ll i=0; i<n; i++)	 
		tree[n+i] = arr[i]; 
	
	// build the tree by calculating parents 
	for (ll i = n - 1; i > 0; --i)	 
		tree[i] = tree[i<<1] + tree[i<<1 | 1];	 
} 

// function to update a tree node 
void upN(ll p, ll value) 
{ 
	// set value at position p 
	tree[p+n] += value; 
	p = p+n; 
	
	// move upward and update parents 
	for (ll i=p; i > 1; i >>= 1) 
		tree[i>>1] = tree[i] + tree[i^1]; 
} 

ll query(ll l, ll r) 
{ 
	ll res = 0; 
	
	// loop to find the sum in the range 
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
	{ 
		if (l&1) 
			res += tree[l++]; 
	
		if (r&1) 
			res += tree[--r]; 
	} 
	
	return res; 
} 
void solsegt(){
     ll a[size];//fill array
     n = sizeof(a)/sizeof(a[0]); 	// n is global 
     // build tree 
     build(a); // build tree 
  //if position-based
    cout << query(5-1, 9)<<endl;  // print the sum in range(5,9) position-based
   
    upN(2-1, 1); // modify element at 2nd position
    
}
