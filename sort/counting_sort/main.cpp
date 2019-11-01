#pragma once
#include <iostream>

using namespace std;

void print_array(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
}

int main() {
	printf("<counting sort>\n");

	int inputSize = 0;
	int* inputArray = NULL;
	int* resultArray = NULL;
	int* cntArray = NULL;
	int max = 0;
	int index = 0;

	printf("입력할 수의 개수 : ");
	scanf("%d", &inputSize);

	inputArray = new int[inputSize];
	resultArray = new int[inputSize];

	printf("숫자 입력(구분자 : 공백) : ");
	for (int i = 0; i < inputSize; i++) {
		scanf("%d", &inputArray[i]);
	}

	//최댓값 찾기
	for (int i = 0; i < inputSize; i++) {
		if (inputArray[i] > max) {
			max = inputArray[i];
		}
	}

	//횟수표 만들기
	cntArray = new int[max + 1];
	memset(cntArray, 0, sizeof(int) * (max + 1));
	for (int i = 0; i < inputSize; i++) {
		(cntArray[inputArray[i]])++;
	}
	printf("횟수표\n");
	print_array(cntArray, max + 1);

	//누적표로 변환
	for (int i = 0; i < max + 1 - 1; i++) {
		cntArray[i + 1] += cntArray[i];
	}
	printf("누적표\n");
	print_array(cntArray, max + 1);

	//대상 데이터 뒤에서 부터 순회
	for (int i = inputSize - 1; i >= 0; i--) {
		index = --cntArray[inputArray[i]];
		resultArray[index] = inputArray[i];
	}
	printf("결과\n");
	print_array(resultArray, inputSize);

	return 0;
}