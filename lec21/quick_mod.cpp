#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int P = 999999937;
unsigned long long invP;
i64 mo(i64 x) { return x-(__int128(x)*invP>>64)*P; }



int main() {
    invP = -1ull/P + 1;

    
}