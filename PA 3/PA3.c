#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()//I'm importing data from polynomial.txt into array.
{
	

FILE *fs=fopen("polynomial.txt","r");

double katsayi[1000];
char poly[1000];
char temp[1000];
int j=0;
while(!feof(fs)) //I'm importing data from polynomial.txt into array.
{
    fscanf(fs,"%c",&poly[j]);
    j++;

}
int a=0;
//In the code lines below, we collect the coefficients in front of the x unknowns of the process in polynomial.txt into an array.
for(int i=0 ; i<100;i++)
{
	if(poly[i]=='x')//The if will be entered when I find the unknown in the array where the process
	{
		if(poly[i-1]=='+'||poly[i-1]=='-')//The value before the unknown is checked to see if it is a number.
		{
			temp[a]='0';
			a++;
			temp[a]=' ';
			a++;
		}	
			
		else //If there is no number before the unknown, I print '0' to the array where I will add the coefficients
		{	

			for(int k=i;k>=0;k--) //It starts from the part of the sequence where the operation is and continues until there are no numbers left.
			{
				if(poly[k]=='+' || poly[k]=='-') //when there are no numbers left before the unknown, it encounters the operation and enters the if.
				{
					for(int j=k ;j<i ; j++) //writes the numbers from operation to unknown to the array as char.
					{
						temp[a]=poly[j];
						a++;
					
					}
					k=0;
					temp[a]=' ';
					a++;
				}
			}
		}
	}
}




int z=0;
double d1 ;
double coefficient[100];
for(int i=0; i<a;i++) //I am transferring the numbers that I have stringed as char to a double array.
{	if(temp[i]=='+'||temp[i]=='-'||temp[i]=='0')
	{
		sscanf(temp+i,"%lf",&d1);
		coefficient[z]=d1;
		z++;
	}
	
}



//The part where we will distinguish the exponential expressions in Polynomail.txt

int length = strlen(poly); // We learn the number of characters in polynomials.txt and assign the length to the variable length
int a1=0;	//The variable to determine how many elements of the array to which we will assign the exponent expression
char temp1[1000];// the array to which we will assign the exponent expression
//In the following operations, we first check whether there is an exponential expression after the unknown value and perform the remaining operations accordingly.
for(int i=0  ;i<length;i++)
{
	if(poly[i]=='x')
	{   //In the if part, it checks if the exponent is 2 or more and where the operations are done if the exponents are less than 2.
		if(poly[i+1]!='^')
		{
			temp1[a1]='0';
			a1++;
			temp1[a1]=' ';
			a1++;
		}

		//In the else part, we assign the values of the exponents directly to the temp1 array.
		else
			{
			for(int k=i;k<length;k++)
				{
					if(poly[k+2]=='+'||poly[k+2]=='-'||poly[k+2]==' ')
					{
						k=length;
						temp1[a1]=' ';
						a1++;
			
					}
					else
					{

						temp1[a1]=poly[k+2];
						a1++;	
				
					}
				}
			}
	}
}

//The part of the code where we convert the values we receive as char to double.

int z1=1;
double d2 ; //The variable that we will temporarily assign the exponent values in the char
double degree[100]; //double variable to which we will assign the exponents
sscanf(temp1,"%lf",&d2);//he process of converting the number value in char to double
degree[0]=d2;

//Operations where we will assign values after the first exponent
for(int i=0; i<a1;i++)
{	if(temp1[i]==' ')
	{
		sscanf(temp1+i,"%lf",&d2);//he process of converting the number value in char to double
		degree[z1]=d2;
		z1++;
	}
	
}






FILE* fp=fopen("values.txt","r");//Command to read values.txt file
FILE* fk=fopen("evaluate.txt","w");//Command to create and process the evaluate.txt file
double evaluate[100];
double values[100];
int count=0;

while(!feof(fp))
{
	fscanf(fp,"%lf",&values[count]);
	count++;


}
double sum=0;
double tempp=1;
//Loop where we get the numbers from the values.txt file and assign them to the values variable
for(int j=0; j<count;j++)
{
	for(int i=1 ; i<a1;i++)
	{
		if(degree[i]<1)
		{
			evaluate[i]=values[j]*coefficient[i];
			
		}
		else
		{	
			for(int p=0 ; p<degree[i];p++)
			{
				tempp=tempp*values[j];
				
			}
			evaluate[i]=coefficient[i]*tempp;
			
			tempp=1;
		}
		sum=sum+evaluate[i];
		
	}
fprintf(fk,"%.6lf \n",sum); //The part we print to the evaluate.txt file

sum=0;
}


return 0 ;
}