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
void solve(int n, int k)
{
    int sets = (int)ceil(n / 2.0);
    int no = 0;

    vector<int> count(1001);
    vector< pair<int,int> > c_tp;

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ++count[x];
    }

    for (int i = 1; i <= k; ++i)
    {
        if(count[i] > 0)
        {
            c_tp.push_back({count[i], i});
        }
    }
    
    sort(c_tp.begin(), c_tp.end());
    

    for(int i = c_tp.size() - 1; i >= 0 && sets > 0; --i)
    {
        if(c_tp[i].first > 0)
        {
            if((c_tp[i].first&1) == 1 && i > 0 && c_tp[i - 1].first > 0)
            {
                // i > 0 skips 0th index, that't why maybe?
                ++no;
                --c_tp[i - 1].first;   
            }
            --sets;
        }
    }

    cout << (n - no) << endline;
    
    
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

    int test = 1, n, k;
    //cin >> test;

    while(test--)
    {
        cin >> n >> k;
        solve(n, k);
    }

    #ifndef ONLINE_JUDGE
    t_en
    t_p
    #endif


    return 0;
}
