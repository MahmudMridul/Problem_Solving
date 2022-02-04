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


void readArray(int arr[], int size)
{
    for(int i=0; i<size; ++i) { i1(arr[i]); }
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; ++i) { os(arr[i]); } ol("");
}

bool isPalindrome(string str, int len)
{
    int i = 0, j = len - 1;
    while(i <= j)
    {
        if(str[i] != str[j]) { return false; }
        ++i; --j;
    }
    return true;
}

void solve(string str, int len) 
{
    int turns = len;
    bool lastReverse = false;
    bool isAlice = true;
    int alicePay = 0, bobPay = 0;
    while(turns--)
    {
        if(!isPalindrome && !lastReverse)
        {
            reverse(str.begin(), str.end());
            if(isAlice)
            {
                alicePay += 0;
                isAlice = false;
            }
            else
            {
                bobPay += 0;
                isAlice = true;
            }
            lastReverse = true;
        }
        else
        {
            bool hasZero = false;
            for(int i=0; i<len; ++i)
            {
                if(str[i] == '0') { str[i] = '1'; hasZero = true; break; }
            }

            if(!hasZero) { break; }

            if(isAlice)
            {
                alicePay += 1;
                isAlice = false;
            }
            else
            {
                bobPay += 1;
                isAlice = true;
            }
            lastReverse = false;

        }
        ol(str);
        os("ALICE "); ol(alicePay);
        os("BOB "); ol(bobPay);
    }

    if(alicePay < bobPay) { ol("ALICE"); }
    else if(alicePay > bobPay) { ol("BOB"); }
    else { ol("DRAW"); }
}

int main()
{
    fast;
    clr;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int test; 
    i1(test);
    
    while(test--)
    {
        int len;
        i1(len);
        string str;
        i1(str);
        solve(str, len);
    }


    return 0;
}

