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

	printf("�Է��� ���� ���� : ");
	scanf("%d", &inputSize);

	inputArray = new int[inputSize];
	resultArray = new int[inputSize];

	printf("���� �Է�(������ : ����) : ");
	for (int i = 0; i < inputSize; i++) {
		scanf("%d", &inputArray[i]);
	}

	//�ִ� ã��
	for (int i = 0; i < inputSize; i++) {
		if (inputArray[i] > max) {
			max = inputArray[i];
		}
	}

	//Ƚ��ǥ �����
	cntArray = new int[max + 1];
	memset(cntArray, 0, sizeof(int) * (max + 1));
	for (int i = 0; i < inputSize; i++) {
		(cntArray[inputArray[i]])++;
	}
	printf("Ƚ��ǥ\n");
	print_array(cntArray, max + 1);

	//����ǥ�� ��ȯ
	for (int i = 0; i < max + 1 - 1; i++) {
		cntArray[i + 1] += cntArray[i];
	}
	printf("����ǥ\n");
	print_array(cntArray, max + 1);

	//��� ������ �ڿ��� ���� ��ȸ
	for (int i = inputSize - 1; i >= 0; i--) {
		index = --cntArray[inputArray[i]];
		resultArray[index] = inputArray[i];
	}
	printf("���\n");
	print_array(resultArray, inputSize);

	return 0;
}