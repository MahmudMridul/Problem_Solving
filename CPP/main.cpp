//#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false)
#define clr cin.tie(NULL)

#define i1(x) cin >> x
#define i2(x,y) cin >> x >> y
#define i3(x,y,z) cin >> x >> y >> z
#define i4(w,x,y,z) cin >> w >> x >> y >> z
#define i5(w,x,y,z,a) cin >> w >> x >> y >> z >> a
#define i6(w,x,y,z,a,b) cin >> w >> x >> y >> z >> a >> b
#define min_pq(x) priority_queue<x, vector<x>, greater<x> >
#define max_pq(x) priority_queue<x>
#define t_st clock_t start = clock();
#define t_en clock_t stop = clock();
#define t_p double duration = double(stop-start) / double(CLOCKS_PER_SEC); printf("%.10f\n",duration);

#define os(x) cout << x << " "
#define o(x) cout << x
#define ol(x) cout << x << "\n"

#define ulli unsigned long long int //64
#define lli long long int //64
#define uli unsigned long int //32
#define li long int //32
#define pi 3.1415926535897932384626433832795

using namespace std;


void read_array(int arr[], int size)
{
    for(int i=0; i<size; ++i) { i1(arr[i]); }
}

void read_vector(vector<int>& vec, int size)
{
    for(int i=0; i<size; ++i) { int x; i1(x); vec.push_back(x); }
}

void print_array(int arr[], int n)
{
    for(int i=0; i<n; ++i) { os(arr[i]); } ol("");
}

void print_vector(vector<int>& vec, int size)
{
    for(int i=0; i<size; ++i) { os(vec[i]); } ol("");
}

void print_vecpair(vector< pair<int, int> >& vec, int size)
{
    for(int i=0; i<size; ++i) { os(vec[i].first); ol(vec[i].second); }
}


void solve(int a[], int size) 
{
    int freq[size];
}


int main()
{
    fast;
    clr;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    lli test, size;
    i1(test);

    while(test--)
    {
        i1(size);
        int a[size];
        read_array(a, size);

        int query;
        i1(query);
        vector< pair<int, int> > step_in;


        while(query--)
        {
            int index, step;
            i2(index, step);
            step_in.push_back({step, index});
        }
        solve(a, size);
    }
    
    return 0;
}

