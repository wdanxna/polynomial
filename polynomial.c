#include<stdio.h>
#include<stdlib.h>
#define MAX_INPUT 300

int read_row(int row[]);
void process(int row[], int num, int lead[], int power[]);
void printResult(int lead[], int power[]);
int binarySearch(int num, int arr[],int left, int right);
void quickSort(int arr[], int left, int right);

int main(void){
	int n,c,set;
	int row[MAX_INPUT], num_per_row;
	int lead[MAX_INPUT],power[MAX_INPUT];

	scanf("%d",&n);
	scanf("%c",&c);
	while(n--){
		set = -1;
		while(++set < 2){
			num_per_row = read_row(row);
			process(row,num_per_row,lead,power);
		}
		printResult(lead,power);
	}
}

int read_row(int row[]){
	int num = 0;
	while (num < MAX_INPUT && scanf("%d",&row[num]) == 1){
		if (num % 2 != 0 && row[num]<0)//power is negative, means end!
		{
			num--;//count out the nonsence lead
			break;	
		}
		num++;
	}
	return num;
}

void process(int row[], int num, int lead[], int power[]){
	int curLead[num/2], curPower[num/2],i;
	int k=0;
	if (num % 2 !=0){
		printf("num_per_row needs to be paired.");
		exit(0);
	}
	for (i=0;i<num;i+=2){
		curLead[k] = row[i];
		curPower[k++] = row[i+1];
	}

	printf("\n current lead:\n");
	for (i=0;i<k;i++){
		printf("%d ",curLead[i]);
	}	
	printf("\n current power:\n");
	for (i=0;i<k;i++){
		printf("%d ",curPower[i]);
	}	
	printf("\n");

	for (i=0;i<k;i++){
		lead[binarySearch(curPower[k],power,0,MAX_INPUT)] += curLead[k];
	}
}

int binarySearch(int num, int arr[],int left, int right){
	int mid,i,swp1,swp2;
	if (left > right){
		//insert at right
		swp1 = num;
		for (i=right;i<k;i++){
			swp2 = arr[i+1];
			arr[i+1] = arr[i];
			
		}	
	}
	mid = (left+right)/2;
	if (arr[mid] > num) binarySearch(num,arr,left,mid-1);
	if (arr[mid] < num) binarySearch(num,arr,mid+1,right);
	return mid;
}

void quickSort(int arr[], int left, int right){

}

void printResult(int lead[], int power[]){

}


