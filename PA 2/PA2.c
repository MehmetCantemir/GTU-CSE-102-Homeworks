#include <stdio.h>

int main()
{
	FILE *fp= fopen("input.txt","r+");   /*Accessing the input.txt file  */
	FILE *fs=fopen("output.txt","w+");	/*Accessing the input.txt file  */
	int input_numbers[100];				/* Array where we will assign the data in the input.txt file */
	int count[100];						/* the array to which we will pass the amount of repetitions */
	int file_numbers ;					/* Variable to assign numbers in input.txt file */
	int b=0;							/* number amount in input.txt file */
	int numbers2[100];					/*  The string in which the digits in the input.txt file will be written once. */


	/*  Using the while loop, all numbers in the input.txt file are assigned to the input_numbers variable. */
	while(!feof(fp))
	{	

		fscanf(fp,"%d",&file_numbers);
		input_numbers[b]=file_numbers;
		b++;

	}

	
	 /*  */ 
	int g = 0 ,  /* This variable serves to determine the index numbers of the numbers we will operate in the arrays.*/
	 	o = 0 ,	 /* The variable to specify the number of elements in the numbers2[] array */
	 	z = 0 ,  /* This variable serves to determine the index numbers of the numbers we will operate in the arrays. */
	 	count1=0,/* Variable that temporarily holds repeated numbers   */
		temp_number ; /* We assign the numbers that we will process in the input_numbers array, in order */
	

	/* while loop used to write the numbers in the input.txt file once */
	while(z<b)
	{
		temp_number=input_numbers[z];
		
		while(g<b)
		{
			if(temp_number==numbers2[g])
			{
				count1++;
			}
			g++;
		}
		g=0;

		if(count1<1)
		{
			numbers2[o]=input_numbers[z];
			o++;

		}
		count1=0;
		z++;
	}
	/* The part where we will print the numbers in the numbers2 array, where we take each number once, from least to greatest. */
	int temp1 , hide2;
	for(temp1=1;temp1<o;temp1++)
	{
		for(int i=0; i<o-1;i++)
		{
			if(numbers2[i]>numbers2[i+1])
			{
				hide2=numbers2[i];
				numbers2[i]=numbers2[i+1];
				numbers2[i+1]=hide2;
			}
		}
	}
	/* The part of the code where we find how many times the numbers in the input.txt file are repeated */	
	int n=0 , m=0, l=0;
	while(n<o)
	{
		while(m<b)
		{
			if(numbers2[n]==input_numbers[m])
			{
				l++;
			}
			
			m++;
		}
		count[n]=l;
		l=0;
		m=0;
		n++;
	}



/* The part of the code where we determine the repeating numbers from least to most and then print them to the output.txt file. */
int p , temp , hide , hide1;
for(temp=1;temp<o-1;temp++)
{
	for(p=0;p<o-1;p++)
	{
		if(count[p]>count[p+1])
		{
			hide=count[p];
			count[p]=count[p+1];
			count[p+1]=hide;

			hide1=numbers2[p];
			numbers2[p]=numbers2[p+1];
			numbers2[p+1]=hide1;
		}
	}
}

for(int i=0; i<o;i++)
{

	fprintf(fs, "%d  : %d\n",numbers2[i],count[i]);
}

fclose(fp);
fclose(fs);
return 0;
}