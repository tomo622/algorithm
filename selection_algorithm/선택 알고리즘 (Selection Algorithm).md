## 선택 알고리즘 (Selection Algorithm)

- 최소값, 최대값, 중간값을 찾는 알고리즘 (**특정 위치의 원소를 찾기 위함**)

- 과정에서 정렬되는 듯 하나 **정렬되는 것은 아니다.**

- 시간 복잡도

  | 최선 | 평균 | 최악   |
  | ---- | ---- | ------ |
  | O(n) | O(n) | O(n^2) |

- 과정
  k번째로 작은 원소 찾기
  1번 부터 k번째까지 작은 원소들을 찾아 배열 앞쪽으로 이동시키고 배열의 k번째를 반환한다.
  ![selection_algorithm_1](https://user-images.githubusercontent.com/19742979/69904352-1773e380-13e9-11ea-935d-699d7ee55cae.PNG)
  
  ```java
  for(...){ //회전 루틴
      for(...){ //배열 탐색 루틴
          if(기준 값 > 탐색 값){
              //마커 한 칸 이동
              if(마커 위치 != 탐색 위치){ //마커와 탐색 위치 중간에 기준 값 보다 큰 값이 존재하는 경우임
                  //마커 위치 값과 탐색 값 swap
              }
          }
      }
      //한 회전 종료 후 마커 값 다음 위치의 값과 기준 값 swap
  }
  ```
  1.
  ![selection_algorithm_2](https://user-images.githubusercontent.com/19742979/69904360-25296900-13e9-11ea-9b7a-ab040b801c5b.PNG)
  2.
  ![selection_algorithm_3](https://user-images.githubusercontent.com/19742979/69904419-84877900-13e9-11ea-90f5-ebc5b0685ba3.PNG)
  3.
  ![selection_algorithm_4](https://user-images.githubusercontent.com/19742979/69904423-a3860b00-13e9-11ea-8bba-3019551169cd.PNG)
  4.
  ![selection_algorithm_5](https://user-images.githubusercontent.com/19742979/69904424-a41ea180-13e9-11ea-8762-39543968b7f2.PNG)
  5.
  ![selection_algorithm_6](https://user-images.githubusercontent.com/19742979/69904425-a41ea180-13e9-11ea-95a7-fc75a09ce9ef.PNG)
  6.
  ![selection_algorithm_7](https://user-images.githubusercontent.com/19742979/69904428-a8e35580-13e9-11ea-8399-e213df168b1a.PNG)
  7.
  ![selection_algorithm_8](https://user-images.githubusercontent.com/19742979/69904429-a97bec00-13e9-11ea-8617-6409e19fe698.PNG)
  8.
  ![selection_algorithm_9](https://user-images.githubusercontent.com/19742979/69904430-a97bec00-13e9-11ea-86dd-9bfd0155c7c0.PNG)
  9.
  ![selection_algorithm_10](https://user-images.githubusercontent.com/19742979/69904588-530fad00-13eb-11ea-97c1-4b08fb714eda.PNG)
  1회전 결과 옮겨진 기준 값 위치의 앞 그룹(A)은 기준 값 보다 작고 뒤 그룹(B)은 기준 값 보다 크다. (각 그룹 자체는 정렬되어있지 않음)
  
  **찾으려는 수와 기준 값의 위치가 같을 때 까지 회전을 시행한다.** 찾으려는 수가 옮겨진 기준 값이 아니라면 다음 회전을 시행한다. 예를 들어 찾는 수가 6번째로 작은 수 (index 5) 인 경우 옮겨진 기준 값 위치 index 4 보다 크기 때문에 다음 회전을 시행한다.
  
  **찾는 수가 기준 값 보다 작은 경우 A그룹에서 다음 회전을 시행한다.** 이때 검색 범위는 index 0~3 까지 이고 기준 위치는 index 3이 된다.
  
  **찾는 수가 기준 값 보다 큰 경우 B그룹에서 다음 회전을 시행한다.** 이때 검색 범위는 index 5~7 까지 이고 기준 위치는 index 7이 된다. 이때 주의할 것은 검색 범위가 아닌 것은 제외한다. **예를 들어 6번째로 작은 수를 찾는 경우 B그룹에서 2번째로 작은 수를 찾으면 된다.** 다음 회전 결과는 아래와 같다.
  ![selection_algorithm_11](https://user-images.githubusercontent.com/19742979/69904725-51df7f80-13ed-11ea-9cad-a1d41e9ff35d.PNG)

