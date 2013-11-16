#include<stdio.h>
#include<stdlib.h>
#define MAX_INPUT 300

int read_row(int row[]);
void process(int row[], int num, int lead[], int power[]);
void printResult(int lead[], int power[]);
int binarySearch(int num, int power[],int lead[],int left, int right);

int main(void){
	int n,c,set;
	int row[MAX_INPUT], num_per_row;
	int lead[MAX_INPUT],power[MAX_INPUT];
	//init
	for (n=0;n<MAX_INPUT;n++){
		lead[n] = 0;
		power[n] = -1;
	}

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
	int curLead[num/2], curPower[num/2],i,j,pos;
	int k=0;
	if (num % 2 !=0){
		printf("num_per_row needs to be paired.");
		exit(0);
	}
	for (i=0;i<num;i+=2){
		curLead[k] = row[i];
		curPower[k++] = row[i+1];
	}

	/*printf("\n current lead:\n");
	for (i=0;i<k;i++){
		printf("%d ",curLead[i]);
	}	
	printf("\n current power:\n");
	for (i=0;i<k;i++){
		printf("%d ",curPower[i]);
	}	
	printf("\n");*/

	for (i=0;i<k;i++){
		pos = binarySearch(curPower[i],power,lead,0,MAX_INPUT);
		//printf("pos: %d",pos);
		lead[pos] += curLead[i];
	}
	/*printf("\npower:");
	for (j=0;j<k;j++){
			printf("%d ",power[j]);
	}

	printf("\nlead: ");
	for (j=0;j<k;j++){
			printf("%d ",lead[j]);
	}
	printf("\n");*/
}

int binarySearch(int num, int power[],int lead[],int left, int right){
	int mid,i,len,result;
	if (left > right){
		//find the valid bound for arr, since arr is power
		//the valid value cannot be negative.
		//printf("through here %d mid: %d\n",num,right+1);
		len = 0;
		while (power[len++] > 0);
		len--;
		for (i=len;i>=right+1;i--){
			power[i+1] = power[i];
			lead[i+1] = lead[i];
		}
		lead[right+1] = 0;
		power[right+1] = num;
		return right+1;	
	}
	mid = (left+right)/2;
	result = mid;
	//printf("mid:%d num: %d ",mid,num);	
	if (power[mid] > num) result=binarySearch(num,power,lead,mid+1,right);
	if (power[mid] < num) result=binarySearch(num,power,lead,left,mid-1);
	return result;
}

void printResult(int lead[], int power[]){
	int i;
	int len = 0;
	while (power[len++] > 0);
	for (i=0;i<len-1;i++){
		printf("[%d,%d]",power[i],lead[i]);
	}
}


