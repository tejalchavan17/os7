#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	int nc,ncr,r[50],i,sh,fd,m,sum=0,totalmov,tfd,tm,j,flag=0;
	printf("\nEnter no. of Cylinders:");
	scanf("%d",&nc);
	printf("\nEnter no. of Cylinder requests:");
	scanf("%d",&ncr);
	printf("\nEnter requests:");
	for(i=0;i<ncr;i++)
		scanf("%d",&r[i]);
	r[ncr]=-1;
	printf("Enter Starting head:");
	scanf("%d",&sh);
	i=0;
	j=1;
	/*if first request is same as head*/
	if(r[0]==sh)
	{
		/*To check next valid request*/
		while((r[j]<0||r[j]>(nc-1))&&r[j]!=-1)
				j++;
		if(r[j]!=-1)
		{
			tfd=sh-r[j];
			fd=abs(tfd);
			printf("\n%d-%d=%d",sh,r[j],fd);
		}
	}
	/*To calculate movement from starting head to first request*/
	else
	{
		if(r[0]>=0&&r[0]<nc)
		{
			tfd=sh-r[0];				
			fd=abs(tfd);
			printf("\n%d-%d=%d",sh,r[0],fd);
		}
		/*if first request is negative*/
		else
		{	
			while((r[i]<0||r[i]>(nc-1))&&r[i]!=-1)
				i++;
			if(r[i]!=-1)
			{
				tfd=sh-r[i];
				fd=abs(tfd);
				printf("\n%d-%d=%d",sh,r[i],fd);
			}
		}
	}
	/*Movement from first request to last request*/
	for(i=0;i<(ncr-1)&&r[i+1]!=-1;i++)
	{
		if(i==0&&r[0]==sh)					//if first request is same as head
			continue;
		/*if request is not valid */
		if(r[i]<0||r[i]>(nc-1))				
			continue;
		if(r[i+1]<0||r[i+1]>(nc-1))
		{
			j=i+1;
			while((r[j]<0||r[j]>(nc-1))&&r[j]!=-1)
				j++;
			if(r[j]!=-1)
			{
				tm=r[i]-r[j];
				m=abs(tm);
				printf("\n%d-%d=%d",r[i],r[j],m);
				sum=sum+m;
			}
		}
		else
		{
			
			tm=r[i]-r[i+1];
			m=abs(tm);
			printf("\n%d-%d=%d",r[i],r[i+1],m);
			sum=sum+m;
		}
	}
	sum=sum+fd;
	printf("\nTotal movement=%d",sum);
}

/*Output
tejal@ubuntu:~/Desktop$ gcc os7t.c
tejal@ubuntu:~/Desktop$ ./a.out

Enter no. of Cylinders:200

Enter no. of Cylinder requests:9

Enter requests:50 20 5 10 -40 15 60 222 70    
Enter Starting head:50

50-20=30
20-5=15
5-10=5
10-15=5
15-60=45
60-70=10
Total movement=110tejal@ubuntu:~/Desktop$ 

*/
