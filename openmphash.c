#include<stdlib.h>
#include <stdio.h>
#include<omp.h>
#include <time.h>
#include <stdlib.h>
int no;
void heapsort(int *array)
{
int *heap=array;
int i,j,c,root,temp;
for(i=1;i<no;i++)
{
c=i;
do
{
root=(c-1) /2;
if (heap[root]< heap[c])
{
temp=heap[root];
heap[root]=heap[c];
heap[c]=temp;
}
c=root;
}
while (c!=0);
}

printf("heap array :");
for(i=0;i<no;i++)
printf("%d\t",heap[i]);
for(j=no -1 ; j>=0;j--)
{
temp=heap[0];
heap[0]=heap[j];
heap[j]=temp;
root=0;
do
{
c=2*root +1;
if((heap[c] <heap[c+1]) && c<j-1)
c++;
if(heap[root]<heap[c] && c<j)
{
temp=heap[root];
heap[root]=heap[c];
heap[c]=temp;
}
root=c;
} while (c<j);
}

printf("\n SORTED ARRAY IS: ");
for(i=0;i<no;i++)
printf("\t %d", heap[i]);
}


int main()
{
int i,j,c,root,temp;
printf("enter no of elements: ");
scanf("%d", &no);
//printf("\n enter nos :");
int heap[20000];
srand(time(NULL));
for (i=0;i<no;i++)
{
	int r=rand() % 1000;	// is "1000" ko change krne se range change hojaegi
	heap[i]=r;
}
//scanf("%d",&heap[i]);
for(i=0;i<no;i++)
printf("\n%d", heap[i]);
clock_t start, end;
start=clock();
#pragma omp parallel num_threads(1) 
{
 heapsort(heap);
}
#pragma omp barrier
end=clock();
printf("\ntime taken: %lf\n",(double)end-start);
}
