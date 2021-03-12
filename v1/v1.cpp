#include <stdio.h>  
#include <stdlib.h> 
#define N 100

void ascending_sort(int a[], int len)
{
	int i, j, temp;
	for (j = 0; j < len - 1; j++)
	{
		for (i = 0; i < len - 1 - j; i++)
		if (a[i] < a[i + 1])
		{
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
}

void descending_sort(int a[], int len)
{
	int i, j, temp;
	for (j = 0; j < len - 1; j++)
	{
		for (i = 0; i < len - 1 - j; i++)
		if (a[i] > a[i + 1])
		{
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
}
    
int main() 
{     
      int count = 0;
      char filename[] = "C:\\Users\\123\\Desktop\\example\\file24.TXT"; 
      FILE *fp; 
      int data[N];
      int Num = 0;
      char StrLine[1024];   
	  count = count+1;           
      if((fp = fopen(filename,"a+")) == NULL) 
      { 
          printf("error!"); 
          return -1; 
      } 
      while (!feof(fp)) 
      { 
          data[Num] = atoi(fgets(StrLine,1024,fp)); 
          Num++;
      } 
      
      fclose(fp);
	  count = count-1;    
	  int staify = 0;
	  
	  for(int i =0;i<Num;i++)
	  {
	  	staify+=data[i];
	  }
	  
	  if(staify  >100&&staify<200)
	  {
	  	ascending_sort(data,Num);
	  
	  }
	  else if(staify>200)
	  {
	  	descending_sort(data,Num);
	  }
	  else
	  {
	  	fclose(fp);
	  	count = count-1; 
	  } 
	  int Edge_1 = data[0];
	  int Edge_2 = data[1];
	  int Edge_3 = data[2];
	
	  fp = fopen(filename,"a+");
	  count = count+1;  
	  
	  if(Edge_1+Edge_2>Edge_3&&Edge_2+Edge_3>Edge_1&&Edge_1+Edge_3>Edge_2)
      {
	
        if(Edge_1==Edge_2 &&Edge_1==Edge_3)
        {
        	 fputs("Form an equilateral triangle",fp);
		}
           
        else if(Edge_1==Edge_2|| Edge_1 ==Edge_3||Edge_2==Edge_3)
		{
		    fputs("Form an isosceles triangle",fp);
		}
           
        else if((Edge_1*Edge_1+Edge_2*Edge_2==Edge_3*Edge_3)||(Edge_1*Edge_1+Edge_3* Edge_3==Edge_2*Edge_2)||(Edge_2*Edge_2+Edge_3*Edge_3==Edge_1*Edge_1))
		{
			fputs("Form a right triangle",fp);
		}
           
        else
		{
			fputs("Make a regular triangle",fp);
		}
            
     }
     else
	 {
	     fputs("It can't make a triangle",fp); 
	 }
    fclose(fp);
    count = count-1; 
    printf("%d",count);
}

