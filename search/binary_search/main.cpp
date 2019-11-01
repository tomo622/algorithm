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
			//������ ����
			if (arr[mid] > key) {
				end = mid - 1;
			}
			//ũ�� ������
			else {
				first = mid + 1;
			}

			//ó���� ���� �ڹٲ�� ����
			if (first > end) {
				return -1;
			}
		}
	}
}

int main() {
	printf("<����Ž��>\n");

	int n = 0;
	int key = 0;
	int* arr = NULL;

	printf("������ ���� �Է� : ");
	scanf("%d", &n);

	arr = new int[n];

	printf("�������� ������ ���� �Է� (������: ����) : ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("�˻� ���� �Է� : ");
	scanf("%d", &key);

	printf("%d ��° ����\n", binary_search(arr, n, key) + 1);

	delete[] arr;

	return 0;
}