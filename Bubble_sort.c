#include<stdio.h>
#include<conio.h>
void main()
{
    int n;
    printf("\n Enter the no. of element :");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
     //bubble sort
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                //swapping logic
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    
    printf("Sorted array : ");
    //printing sorted array
    for(int i=0;i<n;i++)
    {
        printf("\n %d \t:\t %d",i+1,a[i]);
    }
    getch();
}
