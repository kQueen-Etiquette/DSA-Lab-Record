#include <stdio.h>
#include <stdlib.h>

void HeapSort(int sort[], int n);
void Heapify(int sort[], int n, int i);

void main() {
    int num;
    printf("Enter number of elements: ");
    scanf("%d", &num);
    int sort[num];
    for (int i = 0; i < num; i++) {
        printf("Enter %d element: ", i +1);
        scanf("%d", &sort[i]);
    }
    HeapSort(sort, num);
    printf("The sorted array using Heap sort:  ");
    for (int i = 0; i < num; i++) {
        printf("%d  ", sort[i]);
    }
}

void HeapSort(int sort[], int n) {
    int temp;
    for (int i = n /2 -1; i >= 0; i--) {
        Heapify(sort, n, i);
    }
    for (int i = n -1; i >= 0; i--) {
        temp = sort[i];
        sort[i] = sort[0];
        sort[0] = temp;
        Heapify(sort, i, 0);
    }
}

void Heapify(int sort[], int n, int i) {
    int largest = i;
    int left = 2 *i +1;
    int right = 2 *i +2;
    int temp = 0;

    if (left < n && sort[left] > sort[largest]) {
        largest = left;
    }
    if (right < n && sort[right] > sort[largest]) {
        largest = right;
    }
    if (largest != i) {
        temp = sort[i];
        sort[i] = sort[largest];
        sort[largest] = temp;
        Heapify(sort, n, largest);
    }
}