#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
char name;
void printparenth(int i,int j,int n,int b[n][n])
{
    if(i == j)
    {
        printf("%c",name);
        name++;
        return;
    }
    printf("(");
    printparenth(i,b[i][j],n,b);
    printparenth(b[i][j]+1,j,n,b);
    printf(")");

}
int matrixchain(int d[],int n)
{
    int c[n][n],b[n][n];
    int i,j,k,l,q;
    for(i=1;i<n;i++)
    {
        c[i][i] =0;
    }
    for(l=2;l<n;l++)
    {
        for(i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            c[i][j] =INT_MAX;
            for(k=i;k<j;k++)
            {
                q=c[i][k]+c[k+1][j]+d[i-1]*d[k]*d[j];
                if(q<c[i][j])
                {
                    c[i][j] =q;
                    b[i][j]=k;
                }
            }
        }

    }
    name='A';
    printf("Optimal parenthesization is:\n");
    printparenth(1,n-1,n,b);
    return c[1][n-1];

}
int main()
{
    int n;
    printf("Enter the number of matrices: \n");
    scanf("%d", &n);
    int arr[n+1];
    printf("Enter the dimensions: \n");
    for(int i=0;i<n+1;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nMinimum number of multiplications are:  %d\n ",matrixchain(arr,n+1));
    
    return 0;
}