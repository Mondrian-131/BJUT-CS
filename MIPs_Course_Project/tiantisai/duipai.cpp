#include<bits/stdc++.h>
using namespace std;
 
void solve() {

    system("g++ bf.cpp -o bf.exe");
    system("g++ test.cpp -o test");
    system("g++ data.cpp -o data.exe");    
    
    while(1) {
        system("data.exe > data.txt");
        system("bf.exe < data.txt > bf.txt");
        system("test.exe < data.txt > test.txt");
        if (system("fc test.txt bf.txt")) {
            cout << "wrong!" << endl;
            // break;
        }
    }
    system("pause");
}
 
int main() {
    solve();
    return 0;
}