#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf(" enter size of matrix\n");
    scanf("%d", n);
    int r = malloc(n * sizeof(int));
    int arr[r][r];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", arr[i]);
        }

    }
    int j=0;
    for (int i = 0; i < n; i++)
    {
        printf("%d%d",arr[i][j],arr[i+1][j]);


}