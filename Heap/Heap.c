#include"Heap.h"

void HPInit(HP* php) {
	php->arr = NULL;
	php->size = php->capacity = 0;
}
void HPDestroy(HP* php) {
	{
		if (php->arr) {
			free(php->arr);
		}
		php->arr = NULL;
		php->size = php->capacity = 0;
	}

}
void HPPrint(HP* php) {
	for (int i = 0; i < php->size; i++) {
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}
void Swap(HPDataType* x, HPDataType* y) {
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}
void AdjustUp(HPDataType* arr,int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (arr[child] < arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
void HPPush(HP* php, HPDataType x) {
	assert(php);
	//determine whether sufficient space is available
	if (php->size == php->capacity) {
		int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->arr, newCapacity*sizeof(HPDataType));
		if (tmp == NULL) {
			perror("realloc fail");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = newCapacity;
	}
	php->arr[php->size] = x;
	AdjustUp(php->arr, php->size);
	php->size++;
}
bool HPEmpty(HP* php) {
	assert(php);
	return php->size == 0;
}
void AdjustDown(HPDataType* arr, int parent,int n) {
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1<n && arr[child]< arr[child + 1]) {
			child++;
		}
		if (arr[child] > arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
void HPPop(HP* php) {
	assert(!HPEmpty(php));
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	--php->size;
	AdjustDown(php->arr, 0, php->size);
}

HPDataType HPTop(HP* php) {
	assert(!HPEmpty(php));
	return php->arr[0];
}
