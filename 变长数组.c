#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int BLOCK = 20;
typedef struct {
	int* a;
	int size;
}Array;
int* Array_Creat(Array* t1, int array_size);
void Array_Free(Array* t1);
int Array_Size(const Array* t1);
int* Array_at(Array* t1, int index);
void Array_inflate(Array* t1, int more_size);
int* Array_Creat(Array* t1,int array_size) {
	t1->a =(int*)malloc(sizeof(int) * array_size);
	t1->size = array_size;
	return t1->a;
}
void Array_Free(Array* t1) {
	t1->a = NULL;
	t1->size = 0;
}
int Array_Size(const Array* t1) {
	return t1->size;
}
int* Array_at(Array* t1, int index) {
	if (index >= t1->size) {
		Array_inflate(t1, (index / BLOCK + 1) * sizeof(int)*BLOCK - t1->size);
	}
	return &(t1->a[index]);
}//¶ÁÐ´Ò»Ìå
void Array_inflate(Array* t1, int more_size) {
	int* p;
	p = (int*)malloc(sizeof(int) * (t1->size + more_size));
	memcpy_s(p, sizeof(int) * (t1->size + more_size), t1->a, sizeof(int) * (t1->size));
	free(t1->a);
	t1->a = p;
	t1->size += more_size;
}
int main(int argc, char** argv) {
	Array a;
	int cnt = 0;
	Array_Creat(&a, BLOCK);
	while (~scanf("%d", Array_at(&a, cnt++)));
	return 0;
}