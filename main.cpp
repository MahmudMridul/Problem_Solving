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

// SOLVE : https://codeforces.com/contest/1742/problem/F

void solve(int q)
{
    int d, k, slen = 1, tlen = 1
    string x = "", s = "a", t = "a";
    char biggest_charoft = '0', smallest_charofs = '0', biggest_charofs = '0';
    bool s_issmaller = false;

    vector<int> s_chars(26);
    vector<int> t_chars(26);

    s_chars[0] = 1; 
    t_chars[0] = 1;

    while(q--)
    {
        cin >> d >> k >> x;


        if(d == 1) //append to s
        {
            for(int i = 0; i < x.length(); ++i)
            {
                s_chars[x[i] - 'a'] += k;
                slen += k;
            }
        }
        else //append to t 
        {
            for(int i = 0; i < x.length(); ++i)
            {
                t_chars[x[i] - 'a'] += k;
                tlen += k;
            }
        }

        for(int i = 25; i >= 0; --i)
        {
            if(t_chars[i] > 0) { biggest_charoft = 'a' + i; break; }
        }

        for(int i = 0; i < 26; ++i)
        {
            if(s_chars[i] > 0) { smallest_charofs = 'a' + i; break; }
        }

        for(int i = 25; i >= 0; --i)
        {
            if(s_chars[i] > 0) { smallest_charofs = 'a' + i; break; }
        }

        if(smallest_charofs < biggest_charoft) { s_issmaller = true; }
        else if(smallest_charofs > biggest_charoft) { s_issmaller = false; }
        else if(smallest_charofs == biggest_charofs && slen >= tlen) { false; }
        else if(smallest_charofs == biggest_charofs && slen < tlen) { true; }

        if(s_issmaller) { cout << "YES" << endline; }
        else { cout << "NO" << endline; }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("TextFiles/input.txt", "r", stdin);
    freopen("TextFiles/output.txt", "w", stdout);
    t_st
    #endif

    int test, q;
    cin >> test;

    while(test--)
    {
        cin >> q;
        solve(q);
    }

    #ifndef ONLINE_JUDGE
    t_en
    t_p
    #endif


    return 0;
}
