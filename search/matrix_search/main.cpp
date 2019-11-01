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
	printf("행 우선 탐색\n");
	
	for (int r = 0; r < ROW_SIZE; r++) {
		for (int c = 0; c < COL_SIZE; c++) {
			printf("%d ", arr[r][c]);
		}

		printf("\n");
	}

	printf("\n");
}

void column_major_order() {
	printf("열 우선 탐색\n");

	for (int c = 0; c < COL_SIZE; c++) {
		for (int r = 0; r < ROW_SIZE; r++) {
			printf("%d ", arr[r][c]);
		}

		printf("\n");
	}

	printf("\n");
}

void zigzag_order() {
	printf("지그재그 탐색\n");

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
	printf("대각선 탐색\n");

	int spin = COL_SIZE + (ROW_SIZE - 1); //총 순회 횟수
	int c = 0;

	for (int s = 0; s < spin; s++) {
		//s는 각 순회의 칸 이동 수 이면서 시작 위치의 column index
		//row index는 각 순회의 칸 이동 수 까지 증가
		//한 칸 이동할 때마다 column index는 감소
		for (int r = 0, c = s; r <= s; r++, c--) {

			//배열의 범위에 있을 때만 순회한다.
			if (r >= 0 && r < ROW_SIZE && c >= 0 && c < COL_SIZE) {
				printf("%d ", arr[r][c]);
			}
		}

		printf("\n");
	}

	printf("\n");
}

void delta_order() {
	printf("델타를 이용한 탐색\n");

	int dx[4] = { 0, 0, -1, 1 }; //좌우
	int dy[4] = { -1, 1, 0, 0 }; //상하
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
	printf("<2차원 배열 탐색>\n");

	row_major_order();
	column_major_order();
	zigzag_order();
	diagonal_order();
	delta_order();

	return 0;
}