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

//for customized sort: sort(begin, end, compare)
//if x should appear before y then return true
bool compare(int x, int y) 
{
    return false;
}

// SOLVE : https://codeforces.com/contest/1742/problem/F

void solve(vector<int>& arr, int n)
{
    vector<int> pre;

    sort(arr.begin(), arr.end());
    pre.push_back(arr[n - 1]);
    int val = arr[n - 1];
    
    arr[n - 1] = -1;

    for(int c = 1; c <= n - 1; ++c)
    {
        int max_val = -1;
        int max_val_in = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(arr[i] != -1)
            {
                int temp = val | arr[i];
                if(temp >= max_val)
                {
                    max_val = val | arr[i];
                    max_val_in = i;
                }
            }
        }
        val = val | arr[max_val_in];
        pre.push_back(arr[max_val_in]);
        arr[max_val_in] = -1;

    }

    printVector(pre, pre.size());
    cout << "===================" << endline;

    cout << pre[0] << " ";
    for(int i = 1; i < pre.size(); ++i)
    {
        cout << pre[i] << " ";
    }
    cout << endline;


}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("TextFiles/input.txt", "r", stdin);
    freopen("TextFiles/output.txt", "w", stdout);
    t_st
    #endif

    int test, n;
    cin >> test;

    while(test--)
    {
        cin >> n;
        vector<int> arr;
        readVector(arr, n);
        solve(arr, n);
    }

    #ifndef ONLINE_JUDGE
    t_en
    t_p
    #endif


    return 0;
}
