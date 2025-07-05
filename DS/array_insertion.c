#include <stdio.h>


void InsertArray(int arr[], int *n, int pos, int value){
	for(int i = *n; i > pos; i--){
		arr[i] = arr[i-1];
	}
	(*n)++;
	arr[pos] = value;
}

void printArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}

int main(){
	int array[10] = {2, 5, 5, 2, 9};
	int size = 5, value = 7, pos = 3;

	printArray(array, size);

	InsertArray(array, &size, pos, value);

	printf("\n");

	printArray(array, size);


	return 0;
}