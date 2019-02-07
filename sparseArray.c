#include<stdio.h>
int main(){
    int r, c, i, j, nonZero=0;
    printf("Enter number of rows and columns : ");
    scanf("%d%d", &r, &c);
    int array[r][c];
    printf("Enter Array : \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d", &array[i][j]);
            if(array[i][j]!=0)
                nonZero++;
        }
    }
    printf("Given array is : \n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
    if(r*c/4 < nonZero)
        printf("This array is not sparse array.\n ");
    else{
        int sparseArray[nonZero+1][3], k=1;
        sparseArray[0][0] = r;
        sparseArray[0][1] = c;
        sparseArray[0][2] = nonZero;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(array[i][j]!=0){
                    sparseArray[k][0] = i;
                    sparseArray[k][1] = j;
                    sparseArray[k][2] = array[i][j];
                    k++;
                }
            }
        }
        printf("\nMatrix triplet form of  given matrix : \n");
        for(i=0;i<sparseArray[0][2]+1;i++){
            for(j=0;j<3;j++){
                printf("%3d ", sparseArray[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
