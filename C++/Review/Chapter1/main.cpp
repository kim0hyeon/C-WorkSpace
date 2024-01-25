#include <iostream>
using namespace std;

inline int SQUARE(int n){
    return n*n;
}

int main(){
    cout << SQUARE(5) << endl; // 전처리 과정을 거치면 cout << 5*5 << endl;로 바뀜
    return 0;
}