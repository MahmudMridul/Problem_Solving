//#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define t_st clock_t start = clock();
#define t_en clock_t stop = clock();
#define t_p double duration = double(stop-start) / double(CLOCKS_PER_SEC); printf("RUNTIME: %.10f\n",duration);

#define endline "\n"

#define ulli unsigned long long int //64
#define lli long long int //64
#define uli unsigned long int //32
#define li long int //32
#define pi 3.1415926535897932384626433832795

using namespace std;

template<typename type>
void readArray(type arr[], int size)
{
    for(int i=0; i<size; ++i) { cin >> arr[i]; }
}

template<typename type>
void readVector(vector<type>& vec, int size)
{
    for(int i=0; i<size; ++i) { type x; cin >> x; vec.push_back(x); }
}

template<typename type>
void readSet(set<type>& list, int size)
{
    for(int i=0; i<size; ++i) { type x; cin >> x; list.insert(x); }
}

template<typename type>
void printArray(type arr[], int n)
{
    for(int i=0; i<n; ++i) 
    {
        if(i == n-1) { cout << arr[i] << endline; }
        else { cout << arr[i] ; } 
    } 
}

template<typename type>
void printVector(vector<type>& vec, int n)
{
    for(int i=0; i<n; ++i) 
    { 
        if(i == n-1) { cout << vec[i] << endline; }
        else { cout << vec[i] << " "; } 
    }
}

template<typename type>
void printVectorPair(vector< pair<type, type> >& vec, int size)
{
    for(int i=0; i<size; ++i) { cout << vec[i].first << " " << vec[i].second << endline; }
}

// SOLVE : https://codeforces.com/problemset/problem/1195/A
void solve(int n, int m)
{
    if(n < 2 || m < 2)
    {
        cout << n << " " << m << endline;
        return;
    }
    for(int r = 1; r <= n; ++r)
    {
        for(int c = 1; c <= m; ++c)
        {
            if( (r-2 < 1 || c-1 < 1) && (r-2 < 1 || c+1 > m) )
            {
                if( (r+2 > n || c-1 < 1) && (r+2 > n || c+1 > m) )
                {
                    if( (r-1 < 1 || c-2 < 1) && (r-1 < 1 || c+2 > m) )
                    {
                        if( (r+1 > n || c-2 < 1) && (r+1 > n || c+2 > m) )
                        {
                            cout << r << " " << c << endline;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << n << " " << m << endline;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    t_st
    #endif

    int test, n, m;
    cin >> test;

    while(test--)
    {
        cin >> n >> m;
        solve(n, m);
    }

    #ifndef ONLINE_JUDGE
    t_en
    t_p
    #endif


    return 0;
}
