# [12869] 뮤탈리스크
## 💡Algorithm
- DP
## 📚Logic
```c++
int min_attack(int scv1, int scv2, int scv3) {
    if (scv1 <= 0 && scv2 <= 0 && scv3 <= 0) return 0;
    if (scv1 < 0) scv1 = 0;
    if (scv2 < 0) scv2 = 0;
    if (scv3 < 0) scv3 = 0;
    int &ret = cache[scv1][scv2][scv3];
    if (ret != -1) return ret;
    ret = 15;
    
    ret = min(ret, min_attack(scv1 - 9, scv2 - 3, scv3 - 1) + 1);
    ret = min(ret, min_attack(scv1 - 9, scv2 - 1, scv3 - 3) + 1);
    ret = min(ret, min_attack(scv1 -3, scv2 - 9, scv3 - 1) + 1);
    ret = min(ret, min_attack(scv1- 3, scv2 - 1, scv3 - 9) + 1);
    ret = min(ret, min_attack(scv1 - 1, scv2 - 9, scv3 - 3) + 1);
    ret = min(ret, min_attack(scv1 - 1, scv2 - 3, scv3 - 9) + 1);
    
    return ret;
}
```
## 📝Review
쉬운문제
