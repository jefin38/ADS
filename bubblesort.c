#include <stdio.h>
void main()
{
int a[10],i, j, temp,n;
printf("\nEnter number of elements of an array:\n");
scanf("%d",&n);
printf("\nEnter elements: \n");
for (i=0; i<n; i++)
scanf("%d", &a[i]);
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]   = a[j+1];
a[j+1] = temp;
}
}
}
printf("Sorted list is :\n");
for (i = 0; i < n; i++)
printf("%d\n", a[i]); 
}
