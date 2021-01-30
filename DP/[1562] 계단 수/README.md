# [1562] 계단 수
## 💡Algorithm

다이나믹 프로그래밍

## 💡Logic

쉬운 계단 수 문제에서 조건이 추가되었다. 0 ~ 9 까지 수가 모두 포함되어 있어야 한다. 수가 모두 포함되었는지 확인하기 위해 bitmask 기법을 사용한다.

기저사례는 길이가 n과 같고, 수가 모두 포함되었을 경우가 된다.

이외의 코드는 쉬운 계단 수 문제와 똑같다.

```
int stair_number(int input, int length, int mask) {
    if(length == n && mask == 1023) return 1;
    if(length == n && mask != 1023) return 0;
    int& ret = cache[input][length][mask];
    if(ret != -1) return ret;
    
    int res = 0;
    if(input != 9) res = res + stair_number(input + 1, length + 1, mask | 1 << (input + 1));
    if(input != 0) res = res + stair_number(input - 1 , length + 1, mask | 1 << (input - 1));
    ret = res % MOD;
    
    return ret;
}
```

## 💡Review

조건이 하나 추가되어 문제의 난이도가 상당히 어려워졌다. 수가 포함되었는지 확인하는 부분을 어떻게 구현할 지 몰라서 검색해봤다.

bitmask를 적용하면 쉽게 해결할 수 있는 문제였다. 배울게 많았던 문제인 것 같다.
