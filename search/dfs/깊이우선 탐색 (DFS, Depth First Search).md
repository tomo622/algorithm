## 깊이우선 탐색 (DFS, Depth First Search)

- 비선형구조(ex: 트리, 그래프)의 완전탐색 방법 중 하나
- 주로 스택이나 재귀함수(함수의 콜스택)를 이용하여 구현
- 시간 복잡도
- 과정 (스택을 이용한 방법)

  1. 정점 v를 결정하여 방문
  2. 정점 v에 인접한 정점 중 방문하지 않는 정점 w가 있는 경우 정점 v를 스택에 push 후 정점 w를 방문
  3. w를 v로 하여 과정 2 반복
  4. 정점 v에 인접한 정점 중 방문하지 않은 정점이 없다면 탐색 방향을 바꾸기 위해 스택을 pop하여 가장 마지막 방문 정점을 v로 하여 과정 2 반복
  5. 스택이 공백이 될 때까지 과정 2 반복

![dfs_1](https://user-images.githubusercontent.com/19742979/70814443-d7602800-1e0e-11ea-91d8-0009bf22cd10.png)
![dfs_2](https://user-images.githubusercontent.com/19742979/70814444-d7602800-1e0e-11ea-856c-8d60437282c3.png)
![dfs_3](https://user-images.githubusercontent.com/19742979/70814445-d7f8be80-1e0e-11ea-8618-3f5bd4e487b2.png)


