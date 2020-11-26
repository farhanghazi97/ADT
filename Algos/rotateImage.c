#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5
#define MAX_VALUE 100

void printImage(int array[ROWS][COLS]) {
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void rotateImage90(int array[ROWS][COLS]) {
	for(int i = 0; i < ROWS; i++) {
		for(int j = i; j < COLS; j++) {
			int temp = array[i][j];
			array[i][j] = array[j][i];
			array[j][i] = temp;
		}
	}

	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < (COLS/2); j++) {
			int temp = array[i][j];
			array[i][j] = array[i][ROWS-1-j];
			array[i][ROWS-1-j] = temp;
		}
	}
}

int main(void) {


	int image[ROWS][COLS];
	time_t t;

	srand((unsigned) time(&t));

	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++) {
			image[i][j] = (rand() % MAX_VALUE);
		}
	}

	printImage(image);
	rotateImage90(image);
	printImage(image);
}