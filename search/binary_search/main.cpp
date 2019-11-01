#pragma once

#include <iostream>

using namespace std;

int binary_search(int* arr, int arrSize, int key) {
	int first = 0;
	int end = arrSize - 1;
	int mid = 0;

	while (true) {
		mid = (first + end) / 2;

		if (arr[mid] == key) {
			return mid;
		}
		else {
			//작으면 왼쪽
			if (arr[mid] > key) {
				end = mid - 1;
			}
			//크면 오른쪽
			else {
				first = mid + 1;
			}

			//처음과 끝이 뒤바뀌면 종료
			if (first > end) {
				return -1;
			}
		}
	}
}

int main() {
	printf("<이진탐색>\n");

	int n = 0;
	int key = 0;
	int* arr = NULL;

	printf("숫자의 개수 입력 : ");
	scanf("%d", &n);

	arr = new int[n];

	printf("오름차순 정렬의 숫자 입력 (구분자: 공백) : ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("검색 숫자 입력 : ");
	scanf("%d", &key);

	printf("%d 번째 숫자\n", binary_search(arr, n, key) + 1);

	delete[] arr;

	return 0;
}