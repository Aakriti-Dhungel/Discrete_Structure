//program t o compute a^n, b^n mod m, linear search, etc by using recursion.
#include<stdio.h>
long int pow(int x, int y);
int mod(long int x, int y);
void search(int a[10],int, int,int);
int main(){
	int a, b,n,m;
	long int a_pow, bn_mod;
	
	printf("Enter the value of a and n:");
	scanf("%d %d",&a,&n);
	printf("\n Enter the value of b and m:");
	scanf("%d %d",&b,&m);
	a_pow=pow(a,n);
	printf("\nThe value of %d^%d=%ld", a , n , a_pow);
	bn_mod=mod(pow(b,n),m);
	printf("\nThe value of (%d^%d)mod %d=%d",b,n,m,bn_mod);
	
	//For linear search

{
		int a[10],value,size;
	int i;
	printf("\nEnter the size of array:");
	scanf("%d",&size);
	printf("\n Enter the elements of array:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n Enter the value which we need to search:");
	scanf("%d",&value);
	search(a,0,value,size);
}

return 0;
}
long int pow(int x, int y){
	while(y>=0){
		if( x == 0)
		 return 0;
		if( y == 0)
		return 1;
		else
		return x*pow(x,y-1);
	}
}
int mod(long int x, int y){
	if(x<y)
	return x;
	else
	return mod(x-y,y);
}
void search(int a[], int low,int value,int size)
{
	if( a[low]==value)
	{
		printf("The search value %d is found at a[%d]",value,low);
	}
	else if(low==size)
	{
		printf("The search value is not found.\n");
	}
	else
	return search(a,low+1,value,size);
}
