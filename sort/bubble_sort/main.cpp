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

	printf("�Է��� ���� ���� : ");
	scanf("%d", &inputSize);
	inputArray = new int[inputSize];

	printf("�Է�(������: ����) : ");
	for (int i = 0; i < inputSize; i++) {
		scanf("%d", &inputArray[i]);
	}

	for (int i = 0; i < inputSize - 1; i++) {
		//�� �õ� ���� ���� �ڿ��� ���� ���ĵ�
		//�� �õ� ���� ���� �õ����� ���ĵ� ���Ҹ� �����ϰ� ��
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