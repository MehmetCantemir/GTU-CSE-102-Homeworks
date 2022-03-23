#include <stdio.h>

int main()
{	
	// Access to file.txt is provided for reading and writing.
	FILE *write =fopen("file.txt","r+");
	FILE *read =fopen("file.txt","r+");
	

	int a;  //  variable that we will throw the integer values in the file
	int b;	//  similar to a 
	int n=0; // variable used to detect repeated numbers in the program
	int digit =0; // variable used to detect how many digits a repeating number has
	
	
	
	int firstnumber ;
	fscanf(read,"%d",&firstnumber);
	fprintf(write,"%d ",firstnumber);


	while(!feof(read)) // // loop to get all numbers in the file
	{
		fscanf(read,"%d",&a);// numbers in the file are assigned to variable a until the end of the loop
		
		FILE *read1=fopen("file.txt","r+");////Again, the file.txt file is accessed for reading and writing to compare the numbers in the file

		
		/*Again, all numbers in the file are accessed and assigned to the variable 
		'b' in the while loop, and it is tested whether the numbers are repeated in the loop.*/ 
		
		while(!feof(read1))
		{	

			fscanf(read1,"%d",&b);
			

			/*The process is done whether the value taken from the file are the same one by one. 
		If there are identical numbers, the variable n is incremented.*/

			if(a==b)
				{
					n++;

				}
			
			
		}

		//Since the number is compared with itself once, n will definitely increase by 1 time. Therefore, n ==1 means that the number is written once and prints the number again.

		if(n==1)
			fprintf(write,"%d ",a);


		// If n is not equal to 1, it is stated that the number is repeated more than once and the next operations are performed.
		else
		{
			fprintf(write,"%c",' ');
		
			/*

			The code part in the comment line specified the amount of spaces to be written in place of the 
			repeated numbers even though the program was working correctly.However, since the program does not
			work at the desired level, I wanted to share it as a comment line.
				
			
			if(a<0) 
			{
				fprintf(write,"%s"," ");
			}

			
			
			while(a=!0)
			{
				a=a/10;
				digit++;
			}
			for(int i=0 ; i<digit ;i++)
			{
				fprintf(write,"%s"," ");
			}
			

			*/
		}
		
		fclose(read1);
		n=0;



	}

	fclose(write);
	fclose(read);
	return 0 ;
	
}