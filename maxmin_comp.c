#include<stdio.h>
#include<stdlib.h>
int min,max;
int a[]={10,20,45,50,56,64,78,89,91,100};

int max_min1()
{	int c1=0;
	min=max=a[0];
	for(int i=1;i<10;i++)
	
	{
		c1++;
		if(a[i]>max)
		max=a[i];
		c1++;
			
		if(a[i]<min)
		min=a[i];
			
	}
	return c1;

}
int max_min2()
{
	int c2=0;
	min=max=a[0];
	for(int i=1;i<10;i++)
	{
		c2++;
		if(a[i]>max)
		max=a[i];
		else
		{	c2++;
			if(a[i]<min)
			min=a[i];		
		}
	}
	return c2;
}

void maxmin_dac(int *arr,int i,int j)
{
	int max1,min1,mid;
	if(i==j)
	{
		max=min=arr[i];
	}
	else
	{
		if(i==j-1)
		{
			if(arr[i]<arr[j])
			{
			max=arr[j];
			min=arr[i];
			}
		
			else
			{
			min=arr[j];
			max=arr[i];
			
			}
			
		}
	
		else
		{
			mid=(i+j)/2;
			maxmin_dac(arr,i,mid);
			max1=max;
			min1=min;
			maxmin_dac(arr,mid+1,j);
			if(max<max1)
				max=max1;
			if(min>min1)
				min=min1;
	
		}
	}	
	
}
int main()
{
	int v1=0,v2=0,i,num,*arr;
	v1=max_min1();
	v2=max_min2();
	printf("max_min1 is running %d times and max_min2 is running %d times\n",v1,v2);
	if(v1<v2)
		printf("max_min1 is better\n");
		
	else if(v2<v1)
		printf("max_min2 is better\n");
	else
		printf("both are same and this is the worst case\n");
	printf("Enter array size: \n");
		scanf("%d",&num);
	arr=(int *)malloc((num+1)*sizeof(int));
	printf("Enter the elements of the array: \n");
	for(i=1;i<=num;i++)
		scanf("%d",&arr[i]);
	max=arr[0];
	min=arr[0];
	maxmin_dac(arr,1,num);
	printf("Minimum element of the array is %d\n",min);
	printf("maximum element of the array is %d\n",max);
return 0;
}

