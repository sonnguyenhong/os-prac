#include<bits/stdc++.h>

using namespace std;

int main() {
    int i = 8;
    int f = 0;
    while(i > 0) {
        f = f + 3;
        f = f * 2;
        i--;
    }
    cout<<f<<endl;
}