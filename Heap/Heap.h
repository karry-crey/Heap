#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//堆的结构
typedef int HPDataType;
typedef struct Heap{
	HPDataType* arr;
	int size;//valid data count
	int capacity;//spcae size
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);
void HPPrint(HP* php);
void Swap(HPDataType* x, HPDataType* y);
void AdjustUp(HPDataType* arr,int child);
void AdjustDown(HPDataType* arr, int parent,int n);

void HPPush(HP* php, HPDataType x);
void HPPop(HP* php);
//retrieve the top element of the heap
HPDataType HPTop(HP* php);
bool HPEmpty(HP* php);

void Print(int* arr, int n);