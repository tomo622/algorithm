#pragma once
#include <iostream>

using namespace std;

const int ROW_SIZE = 4;
const int COL_SIZE = 5;
int arr[ROW_SIZE][COL_SIZE] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20}
};

void row_major_order() {
	printf("�� �켱 Ž��\n");
	
	for (int r = 0; r < ROW_SIZE; r++) {
		for (int c = 0; c < COL_SIZE; c++) {
			printf("%d ", arr[r][c]);
		}

		printf("\n");
	}

	printf("\n");
}

void column_major_order() {
	printf("�� �켱 Ž��\n");

	for (int c = 0; c < COL_SIZE; c++) {
		for (int r = 0; r < ROW_SIZE; r++) {
			printf("%d ", arr[r][c]);
		}

		printf("\n");
	}

	printf("\n");
}

void zigzag_order() {
	printf("������� Ž��\n");

	for (int r = 0; r < ROW_SIZE; r++) {
		for (int c = 0; c < COL_SIZE; c++) {
			int c_ = c + ((COL_SIZE - 1) - (2 * c)) * (r % 2);
			printf("%d ", arr[r][c_]);
		}

		printf("\n");
	}

	printf("\n");
}

void diagonal_order() {
	printf("�밢�� Ž��\n");

	int spin = COL_SIZE + (ROW_SIZE - 1); //�� ��ȸ Ƚ��
	int c = 0;

	for (int s = 0; s < spin; s++) {
		//s�� �� ��ȸ�� ĭ �̵� �� �̸鼭 ���� ��ġ�� column index
		//row index�� �� ��ȸ�� ĭ �̵� �� ���� ����
		//�� ĭ �̵��� ������ column index�� ����
		for (int r = 0, c = s; r <= s; r++, c--) {

			//�迭�� ������ ���� ���� ��ȸ�Ѵ�.
			if (r >= 0 && r < ROW_SIZE && c >= 0 && c < COL_SIZE) {
				printf("%d ", arr[r][c]);
			}
		}

		printf("\n");
	}

	printf("\n");
}

void delta_order() {
	printf("��Ÿ�� �̿��� Ž��\n");

	int dx[4] = { 0, 0, -1, 1 }; //�¿�
	int dy[4] = { -1, 1, 0, 0 }; //����
	int tempR, tempC;

	for (int r = 0; r < ROW_SIZE; r++) {
		for (int c = 0; c < COL_SIZE; c++) {
			for (int d = 0; d < 4; d++) {
				tempR = r + dy[d];
				tempC = c + dx[d];
				if (tempR >= 0 && tempR < ROW_SIZE && tempC >= 0 && tempC < COL_SIZE) {
					printf("%d ", arr[tempR][tempC]);
				}
			}

			printf("\n");
		}

		printf("\n");
	}

	printf("\n");
}

int main() {
	printf("<2���� �迭 Ž��>\n");

	row_major_order();
	column_major_order();
	zigzag_order();
	diagonal_order();
	delta_order();

	return 0;
}