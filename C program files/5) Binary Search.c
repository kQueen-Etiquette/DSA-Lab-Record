#include <stdio.h>
int BinarySearch(int array[], int L, int R, int search);
void main()
{
    int i, num, search;
    printf("Enter number of elements : ");
    scanf("%d", &num);
    int array[num];
    for(i = 0; i < num; i++){
        printf("Enter an element : ");
        scanf("%d", &array[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &search);
    int ans = BinarySearch(array, 0, num - 1, search);
    if (ans == -1){
        printf("The entered element is not found in the given array.");
    }
    else{
        printf("The entered element is found in the array at the index %d.", ans);
    }
}

int BinarySearch(int array[], int L, int R, int search){
    while(L <= R){
        int mid = L + (R - L) / 2;
        if (array[mid] == search){
            return mid;
        }
        if (array[mid] < search){
            L = mid + 1;
        }
        else{
            R = mid - 1;
        }
    }
    return -1;
}