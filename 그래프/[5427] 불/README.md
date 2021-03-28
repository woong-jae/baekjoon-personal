# [5427] 불
## 💡Algorithm
- Graph
- BFS
## 📚Logic
불을 먼저 퍼뜨리고 난 후 상근이를 이동시킨다.

상근이가 더이상 이동할 곳이 없다면 "IMPOSSIBLE"을 출력한다.

상근이가 테두리에 도달하면 탈출에 성공한 것이기 때문에 (현재까지 걸린 시간 + 1)을 출력한다.

```c++
        //불 번지기
        for (int i = 0; i < fire_size; i++) {
            for (int j = 0; j < 4; j++) {
                int nr = fire.front().first + dr[j], nc = fire.front().second + dc[j];
                if (0 <= nr && nr < h && 0 <= nc && nc < w && building[nr][nc] != '#' && building[nr][nc] != '*') {
                    building[nr][nc] = '*';
                    fire.push(make_pair(nr, nc));
                }
            }
            fire.pop();
        }
        //상근이 움직이기
        int mv_size = (int)movement.size();
        for (int i = 0; i < mv_size; i++) {
            int cr = movement.front().first, cc = movement.front().second;
            if (0 == cr || cr == h - 1 || 0 == cc || cc == w - 1) return res + 1; //escaped!
            for (int j = 0; j < 4; j++) {
                int nr = cr + dr[j], nc = cc + dc[j];
                if (0 <= nr && nr < h && 0 <= nc && nc < w && building[nr][nc] == '.') {
                    building[nr][nc] = '@';
                    movement.push(make_pair(nr, nc));
                }
            }
            movement.pop();
        }
        if (movement.size() == 0) return 0;//더이상 움질일 곳이 없음
```
## 📝Review
문제 자체는 빨리 풀었지만, 메모리 초과 때문에 애먹었다. 상근이 움직인 후 갔던 곳으로는 다시 가면 안되는데, 이걸 처리를 안해줘서 메모리 초과가 났다. 바보같다.
            
