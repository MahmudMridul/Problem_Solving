#include <bits/stdc++.h>

#define i1(x) cin >> x
#define i2(x,y) cin >> x >> y
#define i3(x,y,z) cin >> x >> y >> z
#define i4(w,x,y,z) cin >> w >> x >> y >> z
#define i5(w,x,y,z,a) cin >> w >> x >> y >> z >> a
#define i6(w,x,y,z,a,b) cin >> w >> x >> y >> z >> a >> b

#define os(x) cout << x << " "
#define o(x) cout << x
#define ol(x) cout << x << "\n"

using namespace std;

template<typename type>
type getNthBit(type number, type n)
{
    type num = (1 << n);
    type m = (number & num);
    return m > 0 ? 1 : 0;
}

template<typename type>
type clearNthBit(type number, type n)
{
    type num = ~(1 << n);
    number = (number & num);
    return number;
}

template<typename type>
type setNthBit(type number, type n)
{
    type num = (1 << n);
    number = (number | num);
    return number;
}

template<typename type>
type updateNthBit(type number, type n, type value)
{
    if(value != 0 && value != 1) return INT_MIN;
    if(value == 1) return setNthBit(number, n);
    if(value == 0) return clearNthBit(number, n);
}

template<typename type>
type clearNBits(type number, type n)
{
    type num = (-1 << n); // -1 is all ones in binary
    number = (number & num);
    return number;
}

template<typename type>
type clearBitsRange(type number, type left, type right)
{
    type a = (-1 << (left + 1));
    type b = (1 << right) - 1;
    type num = a | b;
    number = (number & num);
    return number;
}

template<typename type>
bool isPowerofTwo(type n)
{
    return n & (n - 1) == 0;
}

template<typename type>
type countSetBits(type number)
{
    int count = 0;

    while(number > 0)
    {
        number = number & (number - 1);
        ++count;
    }
    return count;
}

// bit starts from 0
int main()
{
    int num = 10;
    bitset<8> bits;
    ol(bits);
    int n = countSetBits(num);
    bits.set(3,1);
    ol(bits);
    //ol(n);
    return 0;
}