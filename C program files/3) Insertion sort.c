#include <stdio.h>
void main()
{
    int i, temp, j, num, key;
    printf("Enter number of elements : ");
    scanf("%d", &num);
    int sort[num];
    for(i = 0; i < num; i++){
        printf("Enter an element : ");
        scanf("%d", &sort[i]);
    }
    for(i = 1; i < num; i++){
        key = sort[i];
        j = i - 1;
        while (j >= 0 && sort[j] > key){
            sort[j + 1] = sort[j];
            j = j - 1;
        }
        sort[j + 1] = key;
    }
    for(i = num - 1; i <= 0; i--){
        printf("%d  ",sort[i]);
    }
}