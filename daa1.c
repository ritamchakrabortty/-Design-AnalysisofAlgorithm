#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a[] = {-100,-89,-56,-5,0,6,10,75,99};
int N=9;
int Linear_search(int x)
{
	int c=0;
	for(int i=0;i<N;i++)
	{
		c++;
		if(a[i]==x)
		break;
	
	}
	return c;
}

int Binary_search(int x)
{
	int c1=0,high=N-1,low=0,mid;
	while(low<=high)
	{
		mid=(high+low)/2;
		c1++;
		if(a[mid]==x)
			break;
		c1++;
		if(a[mid]>x)
		{
			high=mid-1;
		
		}
		else
		{
			low=mid+1;
		}
		
		
		
	
	}
	return c1;
	

}
int main()
{
	int v1=0,v2=0,n;
	printf("Enter the element you want to search: \n");
	scanf("%d",&n);
	v1=Linear_search(n);
	v2=Binary_search(n);
	if(v1>=v2)
		printf("Binary search is better than linear search");
	else
		printf("Linear search is better than binary search");
		
	return 0;
	
}

