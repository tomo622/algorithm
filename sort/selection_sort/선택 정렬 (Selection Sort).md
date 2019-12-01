## 선택 정렬 (Selection Sort)

- 비교와 교환

- 가장 작은 원소부터 차례대로 선택하여 위치를 교환하는 방식

- 선택 알고리즘 (Selection Algorithm) 을 전체 자료에 적용한 것

- 시간 복잡도

  | 최선   | 평균   | 최악   |
  | ------ | ------ | ------ |
  | O(n^2) | O(n^2) | O(n^2) |

- 과정

  1. 주어진 리스트 중에서 최소값을 찾는다.
  2. 그 값을 리스트의 맨 앞에 위치한 값과 교환한다.
  3. 맨 처음 위치를 제외한 나머지 리스트를 대상으로 위 과정을 반복한다.

  ```java
  // 최소값과 비교를 하면서 진행되기 때문에 배열 마지막 전 까지 탐색
  // 1회전 할 때 마다 i의 위치가 최소값으로 교체된다. (i는 정렬 위치)
  int min = 0;
  for(int i = 0; i < arr.length - 1; i++){
      min = i; //무조건 첫 시작을 최소로 생각
      
      //i 즉 min 값과 그 이후의 데이터를 비교해야하기 때문에 i+1 부터 시작
      for(int j = i + 1; j < arr.length; j++){
          //비교하면서 더 작은 값이 있다면 최소값의 인덱스를 변경
          if(arr[min] > arr[j]){
              min = j;
          }
      }
      
      //비교가 끝난 후 정렬 위치 i의 값을 최소값으로 교체
      if(min != i){
          swap(arr, min, i);
      }
  }
  ```
  
  ![selection_sort_0](https://user-images.githubusercontent.com/19742979/69917497-0ccd5300-14aa-11ea-9601-bb908d44b19d.PNG)
  
  1. 가장 처음 정렬될 위치를 최소값의 위치로 정한다.
      ![selection_sort_1](https://user-images.githubusercontent.com/19742979/69917275-929bcf00-14a7-11ea-82b5-fe2993916a1c.PNG)
  2. 정렬될 위치 다음 인덱스 부터 끝까지 탐색하며 현재 최소값 보다 작은 경우 최소값의 위치를 변경한다.
      ![selection_sort_2](https://user-images.githubusercontent.com/19742979/69917276-929bcf00-14a7-11ea-941a-763557686b4f.PNG)
  3. 배열 끝까지 진행한다.
      ![selection_sort_3](https://user-images.githubusercontent.com/19742979/69917567-cc220980-14aa-11ea-87e3-947fc173ace0.PNG)
  4. 정렬 위치와 최소값 위치의 값을 교체하여 정렬시킨다.
      ![selection_sort_4](https://user-images.githubusercontent.com/19742979/69917273-92033880-14a7-11ea-94f0-955a72941956.PNG)
  5. 다음 회전은 정렬된 위치 다음 부터 똑같이 진행한다.
      ![selection_sort_5](https://user-images.githubusercontent.com/19742979/69917274-929bcf00-14a7-11ea-86d6-a47e25f1991d.PNG)
