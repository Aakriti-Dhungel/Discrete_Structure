#include<stdio.h>
int main(){
	printf("Representing graph in Adjacency matrix: \n");
	int i,j,n;
	printf("Enter the total number of variable:");
	scanf("%d",&n);
	char var[n];
	printf("Enter the variables used: ");
	for(i=0;i<n;i++){
		fflush(stdin);
		scanf("%c",&var[i]);
		
	}
	int result[n][n];
	printf("\n 1 for yes , 0 for no: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Is %c and %c connected? ",var[i],var[i]);
			scanf("%d",&result[i][j]);
		}
	}
	printf("\n Adjacent matrix representing the graph is :");
	printf("\n \t");
	
	for(i=0;i<n;i++){
		printf("%c \t",var[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%c \t ",var[i]);
		for(j=0;j<n;j++){
			printf("%d \t",result[i][j]);
		}
		printf("\n");
	}
	//Shortest path
	printf("\n Shortest path \n");
	int n1,x,y,k=0;
	printf("Total vertices:");
	scanf("%d",&n1);
	int m=n1-1;
	char reached[n1];
	printf("Enter the starting vertex:");
	fflush(stdin);
	scanf("%c",&reached[0]);
	fflush(stdin);
	printf("Enter the ending vertex:");
	scanf("%c",&reached[(n1-1)]);
	fflush(stdin);
	
	char z=reached[n1-1];
	int final=0;
	while(z!=reached[k])
	{
	printf("How many vertices are %c connected to ignoring itsself and other vertices which are previously asked? \n",reached[k]);
	k++;
	scanf("%d",&x);
	int size[x];
	printf("Enter the weights of the connected vertices:");
	for(i=0;i<x;i++){
		scanf("%d",&size[i]);
		
	}
	//find smallest weight
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			if(size[i]>size[j+1]){
				int temp=size[i];
				size[i]=size[j+1];
				size[j+1]=temp;
			}
		}
	}
	final=final+size[0];
	fflush(stdin);
	printf("Which of the current entered verices has weight of %d",size[0]);
	scanf("%d",&reached[k]);
	fflush(stdin);
	printf("\n");
	
	}
	printf("Shortest path");
	for(i=0;i<k;i++){
		printf("%c",reached[i]);
	}
	printf("\n Shortest length %d",final);
	
	//Minimum spanning tree
	printf("\n minimum spanning tree \n");
	int v,e;
	printf("Enter number of vertex and edge:");
	scanf("%d%d",&v,&e);
	int weight[e],edge[e][2],span[e][2];
	printf("Enter all %d weights of the graph:",e);
	for(i=0;i<e;i++){
		scanf("%d",&weight[i]);
	}
	//ascending order
	for(i=0;i<e;i++){
		for(j=i;j<e;j++){
			if(weight[i]>weight[j+1]){
				int temp=weight[i];
				weight[i]=weight[j+1];
				weight[j+1]=temp;
			}
		}
	}
	for(i=0;i<e;i++){
		printf("Enter edge having weight of %d ",weight[i]);
		for(j=0;j<2;j++){
			fflush(stdin);
			scanf("%c",&edge[i]);
			
		}
	}
	char check='n';
	
	int counts=0;
	printf("Press y if these edges from a cycle & n if they don't:\n'");
	fflush(stdin);
	int val[e],w=0;
	
	//if they form cycle,val[i]=0,else val[i]=1
	//problem
	printf("Check the edge which don't form cycle and shown edge before pressing y/n : \n");
	
	for(i=0;i<e;i++){
		if(check=='y'){
			val[i]=0;
		}else{
			val[i]=1;
		}
		counts++;
		for(j=0;j<2;j++){
			printf("%c",edge[i][j]);
			{
				printf("\n =>");
				scanf("%c",&check);
				fflush(stdin);
				printf("\n");
			}
			//logic
			counts=counts-1;
			for(i=0;i<counts;i++){
				if(val[i]==1){
					for(j=0;j<2;j++){
						printf("%c",edge[i][j]);
					}
					
					printf("__");
				}
			}
			int sum=0;
			for(i=0;i<counts;i++){
				if(val[i]==1){
					sum=sum+weight[i];
				}
			}
			printf("\n Weight : %d",sum);
			return 0;
		}
	}
}
