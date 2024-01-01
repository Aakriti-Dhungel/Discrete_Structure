#include<stdio.h>
void split(int arr[], int num){
	int i;
	for(i=0;i<4;i++){
		arr[i]=num%10;
		num/=10;
	}
}
int main(){
	int num1,num2;
	int arr1[4]={0},arr2[4]={0},arr3[4]={0};
	printf("Enter first and second number:\n");
	scanf("%d%d",&num1,&num2);
	split(arr1,num1);
	split(arr2,num2);
	int carry=0;
	int i;
	for(i=0;i<4;i++){
		int sum=arr1[i]+arr2[i]+carry;
		if(sum>9){
			arr3[i]=sum%10;
			carry=sum/10;
		}
		else{
			arr3[i]=sum;
			carry=0;
		}
	}
	if(carry!=0){
		printf("overflow \n");
		return 0;
	}
	
	printf("Separate sum:");
	for(i=3;i>=0;i--){
		printf("%d",arr3[i]);
	}
	printf("\n");
	return 0;
}
