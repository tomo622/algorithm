#include <iostream>

using namespace std;

int routine_cnt = 0;

//s: 검사 시작 인덱스
//e: 검사 끝 인덱스, 기준 인덱스(비교대상)
int routine(int* arr, int arr_size/*배열 상태print를 위해*/,  int s, int e)
{
	//print
	printf("%d 회차 (기준-%d,index : %d, start index : %d, end index : %d)\n", ++routine_cnt, arr[e], e, s, e);
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("->");
	//print

	int to = s - 1; //기준 인덱스가 이동할 위치 인덱스
	int check = 0; //검사 인덱스, 기준 인덱스와 비교 대상
	int temp = 0;

	//기준 인덱스(e) 전까지 검사
	for (check = s; check < e; check++)
	{
		//기준 인덱스(e)의 값 보다 작은 경우
		//기준 인덱스가 이동할 위치 인덱스(to)를 앞으로 뒤로 이동시킨다.
		//이때 뒤로 이동된 to와 check가 다른 경우 자리를 교환한다. (to의 값이 기준 값 보다 큰 경우일 것)
		//이렇게 큰 수를 뒤로 이동 시킨다.
		//기준 인덱스(e)의 값 보다 큰 경우
		//검사 인덱스(check)만 증가한다.
		if (arr[check] <= arr[e])
		{
			to++;

			if (to != check) {
				temp = arr[to];
				arr[to] = arr[check];
				arr[check] = temp;
			}
		}
	}

	//기준 인덱스(e) 값을 이동할 위치로 옮긴다.
	//이때 이동할 위치는 현재 to의 바로 뒤 인덱스이다.
	to++;
	temp = arr[to];
	arr[to] = arr[e];
	arr[e] = temp;


	//print
	for (int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	//print

	return to;
}

//s: 검사 시작 인덱스
//e: 검사 끝 인덱스
int selection_algorithm(int* arr, int arr_size/*배열 상태print를 위해*/, int s, int e, int target) {
	if (s == e) {
		return arr[s];
	}

	int std = routine(arr, arr_size, s, e); //std : 기준인덱스

	//기준값은 해당 인덱스의 + 1 번째로 작은 수 이다. 또한 시작 위치에 따라 앞에 개수를 제외하고 몇번째 인지 계산해야하지 때문에 시작 인덱스 값도 
	//빼줘야함 ex) 기준 인덱스가 3일때 이것은 4번째 이지만, 검색 시작이 인덱스 1 부터 일 경우 앞에 인덱스 0에 해당하는 것은 제외해야함. 따라서
	// 인덱스 1부터 검사를 시작할때 기준 인덱스 3은 3번째 이다.
	//찾고자 하는 값이 기준값 보다 큰 경우
	//후반 후 탐색
	//시작위치 : 기준 값 다음
	//끝 위치 : 배열 마지막
	//목표 : 본래 목표에서 기준 값의 순서 ex) 4번째로 작은 수를 찾을때 기준점이 2이면 후반부에서는 4-2 번째로 작은수이다.
	//전반부와 기준점을 제외하므로.
	if (target - 1 > std) {
		return selection_algorithm(arr, arr_size, std + 1, e, target);
	}
	//찾고자 하는 값이 기준값과 같은 경우
	else if(target -1 == std) {
		return arr[std];
	}
	//찾고자 하는 값이 기준값과 작은 경우
	//끝 위치 : 기준 값 전
	else {
		return selection_algorithm(arr, arr_size, s, std -1, target);
	}
}




int main() {
	int N = 0;
	int* arr = NULL;
	int target = 0;

	printf("숫자 개수 입력 : ");
	scanf("%d", &N);
	
	arr = new int[N];
	memset(arr, 0, sizeof(int) * N);

	printf("숫자 입력(구분자 : 공백) : ");
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	printf("n 번째로 작은 원소 찾기 : ");
	scanf("%d", &target);

	printf("%d 번째로 작은 원소는 : %d 입니다.", target, selection_algorithm(arr, N, 0, N-1, target));
	
	delete[] arr;

	return 0;
}