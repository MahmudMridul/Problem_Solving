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

lli canChange(string& line, lli lenofLine, lli half)
{
    for(lli i = 0; i <= half; ++i)
    {
        if(line[i] == 'L') { line[i] = 'R'; return i; }
    }

    for(lli i = half; i < lenofLine; ++i)
    {
        if(line[i] == 'R') { line[i] = 'L'; return i; }
    }

    return -1;
}

lli calculateSum(string line, lli lenofLine)
{
    lli sum = 0;

    for(int i = 0; i < lenofLine; ++i)
    {
        if(line[i] == 'L')
        {
            sum += i;
        }
        else
        {
            sum += (lenofLine - 1) - i;
        }
    }
    return sum;
}

void solve(string line, lli lenofLine) 
{
    lli half = (half&1) == 1 ? lenofLine / 2 : (lenofLine / 2) - 1;
    vector<lli> result(lenofLine); 

    lli currentSum = calculateSum(line, lenofLine);

    for(lli k = 1; k <= lenofLine; ++k)
    {
        lli index = canChange(line, lenofLine, half);
        if(index != -1)
        {
            lli currentValue = 0, updatedValue = 0;
            if(index <= half)
            {
                currentValue = index;
                updatedValue = (lenofLine - 1) - index;
            }
            else
            {
                currentValue = (lenofLine - 1) - index;
                updatedValue = index;
            }
            lli differece = abs(currentValue - updatedValue);
            currentSum += differece;
            result.push_back(currentSum);
        }
    }

    printVector(result, lenofLine);
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

    lli test, lenofLine;
    i1(test);

    while(test--)
    {
        i1(lenofLine);
        string line;
        i1(line);

        solve(line, lenofLine);
    }

    #ifndef ONLINE_JUDGE
    t_en
    t_p
    #endif


    return 0;
}
