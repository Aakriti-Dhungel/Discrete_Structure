#include<stdio.h>
#include<conio.h>
int fact(int a){
	if(a>1){
		return a*fact(a-1);
	}else{
		return 1;
		
	}
}
int main(){
	int num1,num2,num3,n,r,choice;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	printf("Enter the value of r: ");
	scanf("%d",&r);
	if(n<r){
		printf("The value of n must be greater than r.\n");
		printf("Enter again: ");
		scanf("%d %d",&n,&r);
		
	}
	printf("\nEnter 1 to find permutation ");
	printf("\nEnter 2 to find combination ");
	printf("\nEnter your choice ");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			num1=fact(n);
			num2=fact(n-r);
			num3=num1/num2;
			printf("nPr =%d ",num3);
			break;
		}
		case 2:{
			num1=fact(n);
			num2=fact(n-r)*fact(r);
			num3=num1/num2;
			printf("nCr = %d ",num3);
			break;
		}
		
		default:{
			printf("You entered an incorrect choice :");
			break;
		}
		return 0;
	}
	
}
