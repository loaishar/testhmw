#include <stdio.h>
#include <stdlib.h>
int main(){



int *ptr,size_of_array,sum=0;
float  avg=0;
printf("enter number of students: \n");
scanf("%d",&size_of_array);
ptr=(int*)malloc(size_of_array*sizeof(int));
if(ptr==NULL){
    printf("can not allocate memory");
}
else{
    for (int i = 0; i < size_of_array; i++)
    {
        scanf("%d",&ptr[i]);
        sum+=ptr[i];
    }
    avg=sum/size_of_array;
    

}

    printf("the average is %f",avg);
}