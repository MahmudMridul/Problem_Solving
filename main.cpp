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
#define t_p double duration = double(stop-start) / double(CLOCKS_PER_SEC); printf("RUNTIME: %.10f\n",duration);

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



void solve(lli currentFloorFE, lli currentFloorSE, lli desFloorSE) 
{
    lli firstElevetorTime = abs(currentFloorFE - 1);
    lli secondElevetorTime = 0;

    if(desFloorSE == 1)
    {
        secondElevetorTime = abs(desFloorSE - currentFloorSE);
    }
    else
    {
        secondElevetorTime = abs(currentFloorSE - desFloorSE) + abs(desFloorSE - 1);
    }

    if(firstElevetorTime < secondElevetorTime) ol(1);
    else if(firstElevetorTime > secondElevetorTime) ol(2);
    else ol(3);
}


int main()
{
    fast;
    clr;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    t_st
    #endif

    lli test, currentFloorFE, currentFloorSE, desFloorSE;
    i1(test);

    while(test--)
    {
        i3(currentFloorFE, currentFloorSE, desFloorSE);
        solve(currentFloorFE, currentFloorSE, desFloorSE);
    }

    #ifndef ONLINE_JUDGE
    t_en
    t_p
    fclose(stdin);
    #endif


    return 0;
}
