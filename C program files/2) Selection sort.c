#include <stdio.h>
void main()
{
    int i, temp, j, num, min_index;
    printf("Enter number of elements : ");
    scanf("%d", &num);
    int sort[num];
    for(i = 0; i < num; i++){
        printf("Enter an element : ");
        scanf("%d", &sort[i]);
    }
    for(i = 0; i < num - 1; i++){
        min_index = i;
        for(j = i+1; j < num; j++){
            if(sort[j] < sort[min_index]){
                min_index = j;
            }
        }
        temp = sort[min_index];
        sort[min_index] = sort[i];
        sort[i] = temp;
    }
    for(i = 0; i < num; i++){
        printf("%d  ",sort[i]);
    }
}