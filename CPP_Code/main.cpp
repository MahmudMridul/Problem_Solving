//#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <chrono>

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
using namespace std::chrono;

template<typename type>
void readArray(type arr[], int size)
{
    for(int i=0; i<size; ++i) { i1(arr[i]); }
}

template<typename type>
void readVector(vector<type>& vec, int size)
{
    for(int i=0; i<size; ++i) { type x; i1(x); vec.push_back(x); }
}

template<typename type>
void readSet(set<type>& list, int size)
{
    for(int i=0; i<size; ++i) { type x; i1(x); list.insert(x); }
}

template<typename type>
void printArray(type arr[], int n)
{
    for(int i=0; i<n; ++i) { os(arr[i]); } ol("");
}

template<typename type>
void printVector(vector<type>& vec, int size)
{
    for(int i=0; i<size; ++i) { os(vec[i]); } ol("");
}

template<typename type>
void printVectorPair(vector< pair<type, type> >& vec, int size)
{
    for(int i=0; i<size; ++i) { os(vec[i].first); ol(vec[i].second); }
}


void solve(set<string> p1, set<string> p2, set<string> p3, int numofWords) 
{
    int p1Points = 0;
    int p2Points = 0;
    int p3Points = 0;

    set<string>::iterator iter1 = p1.begin();
    set<string>::iterator iter2 = p2.begin();
    set<string>::iterator iter3 = p3.begin();

    while(iter1 != p1.end())
    {
        string word1 = *(iter1);
        string word2 = *(iter2);
        string word3 = *(iter3);

        //For three points
        if(!p2.count(word1) && p3.count(word1) != 1)
        {
            p1Points += 3;
        }
        if(!p1.count(word2) && !p3.count(word2))
        {
            p2Points += 3;
        }
        if(!p1.count(word3) && !p2.count(word3))
        {
            p3Points += 3;
        }

        //For one point
        if((!p2.count(word1) && p3.count(word1)) || (p2.count(word1) && !p3.count(word1)))
        {
            p1Points += 1;
        }
        if((!p1.count(word2) && p3.count(word2)) || (p1.count(word2) && !p3.count(word2)))
        {
            p2Points += 1;
        }
        if((!p1.count(word3) && p2.count(word3)) || (p1.count(word3) && !p2.count(word3)))
        {
            p3Points += 1;
        }


        ++iter1;
        ++iter2;
        ++iter3;
    }

    os(p1Points);
    os(p2Points);
    ol(p3Points);
}



int main()
{
    fast;
    clr;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    #ifndef ONLINE_JUDGE
    //clock_t startOverall = clock();
    auto start = high_resolution_clock::now();
    #endif

    lli test, numberofWords;
    i1(test);

    while(test--)
    {
        i1(numberofWords);
        set<string> p1; set<string> p2; set<string> p3;
        readSet(p1, numberofWords);
        readSet(p2, numberofWords);
        readSet(p3, numberofWords);
        solve(p1, p2, p3, numberofWords);
    }

    #ifndef ONLINE_JUDGE
    //clock_t endOverall = clock();
    auto end = high_resolution_clock::now();
    //double durationOverall = double(endOverall-startOverall) / double(CLOCKS_PER_SEC); 
    auto duration = duration_cast<milliseconds>(end - start);
    printf("%.10f\n",duration);
    #endif
    return 0;
}

