//First Come First Serve
#include<stdio.h>
#include<stdlib.h>


void main(){
	int i,j;
	int process[4][3] = {{0,1,0},{1,4,3},{2,1,4},{3,1,5}};
	printf("Process\tBurst\tArrival\n");
	for(i = 0; i<4;i++){
			printf("%d\t%d\t%d\n", process[i][0], process[i][1], process[i][2]);
	}
	
//	printf("Completed\tWaiting\tTurnaround\n");
	int time = 0;
	int completed[4],turn[4], wait[4];
	float wsum = 0, tsum = 0;
	i = 0;
	printf("\nGantt Chart \n");
	while(i < 4){
		if(time >= process[i][2]){
			time += process[i][1];
			printf("P%d ", i);
			completed[i] = time;
			i++;
			}
		else{
			time++;
			printf(" Wait ");
		}
	}
	
		
	printf("\n\nCompleted\tTurnaround\tWaiting\n");
	for(i = 0;i<4;i++){
		wait[i] = completed[i] - process[i][2] - process[i][1];
		turn[i] = completed[i] - process[i][2];
		wsum += wait[i];
		tsum += turn[i];
		printf("%d\t\t%d\t\t%d\n", completed[i], completed[i] - process[i][2], completed[i] - process[i][2] - process[i][1]);
	}
	
	printf("\nAvg turn: %f\n", tsum / 4);
	printf("Avg Wait: %f", wsum / 4);
}

