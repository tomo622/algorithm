#include <iostream>

using namespace std;

void print_array(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
}

int main() {
	printf("<bubble sort>\n");

	int inputSize = 0;
	int* inputArray = NULL;

	printf("입력할 숫자 개수 : ");
	scanf("%d", &inputSize);
	inputArray = new int[inputSize];

	printf("입력(구분자: 공백) : ");
	for (int i = 0; i < inputSize; i++) {
		scanf("%d", &inputArray[i]);
	}

	for (int i = 0; i < inputSize - 1; i++) {
		//각 시도 마다 가장 뒤에서 부터 정렬됨
		//각 시도 마다 이전 시도에서 정렬된 원소를 제외하고 비교
		for (int j = 0; j < inputSize - 1 - i; j++) {
			if (inputArray[j] > inputArray[j + 1]) {
				int temp = inputArray[j];
				inputArray[j] = inputArray[j + 1];
				inputArray[j + 1] = temp;
			}

			print_array(inputArray, inputSize);
		}
	}

	delete[] inputArray;

	return 0;
}