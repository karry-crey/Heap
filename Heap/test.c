#include"Heap.h"

void Print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void HeapSort1(int* arr, int n) {
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < n; i++) {
		HPPush(&hp, arr[i]);
	}
	int i = 0;
	while (!HPEmpty(&hp)) {
		HPDataType top = HPTop(&hp);
		arr[i++] = top;
		HPPop(&hp);
	}
	HPDestroy(&hp);
}

void HeapSort(int* arr, int n) {
	//build heap
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(arr, i, n);
	}
	int end = n - 1;
	while (end > 0) {
	   Swap(&arr[0], &arr[end]);
	   AdjustDown(arr, 0, end);
	   end--;
	}
	
}

void test01() {
	HP hp;
	HPInit(&hp);
	HPPush(&hp, 56);
	HPPush(&hp, 10);
	HPPush(&hp, 15);
	HPPush(&hp, 30);
	HPPush(&hp, 75);
	HPPush(&hp, 35);
	HPPrint(&hp);
	HPPop(&hp);
	HPPrint(&hp);
	HPPop(&hp);
	HPPrint(&hp);
	HPPop(&hp);
	HPPrint(&hp);
	HPPop(&hp);
	HPPrint(&hp);
	HPPop(&hp);
	HPPrint(&hp);
	HPPop(&hp);
	HPPrint(&hp);
	HPDestroy(&hp);
}

void test02() {
	HP hp;
	HPInit(&hp);
	HPPush(&hp, 56);
	HPPush(&hp, 10);
	HPPush(&hp, 15);
	HPPush(&hp, 30);
	HPPrint(&hp);
	while (!HPEmpty(&hp)) {
		HPDataType top = HPTop(&hp);
		printf("%d ", top);
		HPPop(&hp);
	}
	HPDestroy(&hp);
}

int main() {
	//test01();
	//test02();
	int arr[6] = { 19,15,20,17,13,10 };
	Print(arr, 6);
	HeapSort(arr, 6);
	Print(arr, 6);
	return 0;
}