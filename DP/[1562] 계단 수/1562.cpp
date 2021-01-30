#include <iostream>
#include <cstring>

#define MOD 1000000000
using namespace std;

int n;
int cache[10][101][1<<10];//비트마스크를 사용해서 수를 다 썼는지 확인한다.

int stair_number(int input, int length, int mask) {//처음 숫자와 구할 계단 수의 길이
    if(length == n && mask == 1023) return 1;//기저사례: 길이가 n과 같아지고, 모든 수를 다 쓴 경우
    if(length == n && mask != 1023) return 0;//모든 수를 다 쓰지 않은 경우
    int& ret = cache[input][length][mask];
    if(ret != -1) return ret;
    
    int res = 0;
    if(input != 9) res = res + stair_number(input + 1, length + 1, mask | 1 << (input + 1));
    if(input != 0) res = res + stair_number(input - 1 , length + 1, mask | 1 << (input - 1));
    ret = res % MOD;
    
    return ret;
}

int main() {
    int counter = 0;
    cin >> n;
    memset(cache, -1, sizeof(cache)); //cache 초기화
    
    for(int i = 1; i < 10; i++) {
        counter = (counter + stair_number(i, 1, 1 << i)) % MOD;
        
    }
    
    cout << counter % MOD << '\n';
}
