#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parents {	   /* struct  holds objects and number of objects*/
	   double nums;
	   char *name; 
};

int parser(char *skey, struct parents nParent[]){	/* to parse answer entered by user and to store a struct*/
	
	int i = 0;
	double number;
	char *temp;

	temp = strtok (skey, " ");			/* i use strtok function to parse childern of parents*/
	while(temp!=NULL){
		
		number = atof(temp);			/* to convert string to float */
		temp = strtok (NULL, " ");
		nParent[i].nums = number;		/* to store number of object */
		nParent[i].name = (char*)malloc(sizeof(char)*strlen(temp)+1);
		strcpy(nParent[i].name,temp); 	/* to store object name*/
		temp = strtok (NULL, " ");
		i++;
	}
	return i;							/* function store all name and numbers in struct and returns number of children*/
}

float definec(char *object, char *parentObject,double total){ 	/* function use object name, parent name and total price*/
	
	char *temp, tmp, answer[100],check[100];
	struct parents nParent[20];
	double value;
	int i = 0,flag = 0, count;
	
	if(!strcmp(object,parentObject))	/* to control statement askin question  object or parent */
		printf("Define %s:\n",object);
	else
		printf("Define %s in %s:\n",object,parentObject);
	scanf("%c",&tmp);
	scanf("%[^\n]",answer);			/* the answer may be objects or price */
	//gets(answer);

	strcpy(check,answer); 			/* to define answer type object or price*/
	temp = strtok (check, " ");
	value =  atof(temp);
	temp = strtok (NULL, " ");

	if(temp == NULL)				/* if answer is price return  value to sum*/
		return value;
	else{							/* if answer is contain objects i call parser function to parse all object*/

		count = parser(answer,nParent);
		while(i < count){			/* in the loop every object calls one-by-one recursively and calculatin*/

			value = definec(nParent[i].name,object,total);
			total += value*nParent[i].nums;
			i++;
		}
		return total;
	}
}

int main(void){
	
	char  nameObjet[100];
	char * temp,tmp;
	double number = 1.00, result = 0.00;
	
	printf("Name the object:\n");	/* the user enters object name*/
	//scanf("%c",&tmp);
	scanf("%[^\n]",nameObjet);			

	temp = strtok (nameObjet, " ");	/* if user enter a number that is number of object like " 2 Bicycle " */
	if(atoi(temp)){
		number = atof(temp);
		temp = strtok (NULL, " ");
	}
	result = definec(temp,temp,result);	
	printf("Total cost of %s %.2f",temp, result*number);
}