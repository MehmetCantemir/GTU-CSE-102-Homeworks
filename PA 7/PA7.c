#include<stdio.h>
#define LENGTH 512				/* row size and column size */

struct area{		/* struct of lands*/

	int value;		/* save input values*/
	int id;	        /* save number of island parts like it is first part of island or second.. */
	int control;		/* save if land is checked */

}island[LENGTH][LENGTH];	/* N x N land */

int read(FILE * input, struct area island[][LENGTH]){	/* read input.txt file */

	int l, number , x=0 , y=0;
	
	fscanf(input,"%d",&l);					/* I read first line is L  and save it */
	while(!feof(input)){
		fscanf(input,"%d",&number);			/* I read each number of island L and save array of struct */

		island[x][y].value = number;
		island[x][y].id = 0;				
		island[x][y].control = 0;			

		if(y== LENGTH-1){
			x++;
			y = 0;
		}
		else
			y++;
	}
	fclose(input);
	return l;								/* return L value */
}

void findIsland(struct area island[][LENGTH], int level, int x, int y, int iNo){	/*  find islands if island value greather then L*/

	if(x < 0 || y < 0 || x >= LENGTH || y >= LENGTH || island[x][y].control == 1)
		 return;	/* first four statement checking where it goes, if it goes out of land or already checked it return*/
	
	if(island[x][y].value < level){	/* if value of input less then L marked it is wather and checked */
	
		island[x][y].id = 0;
		island[x][y].control = 1;
		return;		/* return back */
	}

	if(island[x][y].value > level){		/* if value greather then L  */

		island[x][y].id = iNo;	/* iNo is counter of islands, I find out which coordinate the island starts from */
		island[x][y].control = 1;			/* to mark land is checked   */
	}
		findIsland(island,level,x,y+1,iNo+1);	/* to check right of the island */
		findIsland(island,level,x+1,y,iNo+1);	/* to check bottom of the island */
		findIsland(island,level,x,y-1,iNo+1);	/* to check left of the island */
		findIsland(island,level,x-1,y,iNo+1);	/* to check top of the island */
}

int numberOfIsland(struct area island[][LENGTH], int level){	/* I call findIsland function for every cell of matrix */
	
	int x, y, n = 0;

	for(x = 0; x < LENGTH; x++){
		for(y = 0; y < LENGTH; y++){
			findIsland(island,level,x,y,1);	
			if(island[x][y].id == 1)	/* if id_number equal to 1 the land is the first coordinate of the island*/
				n++;					/* to count number of islands if id equal to 1 */
		}
		y = 0;
	}
	return n;		/* functions returns number of islads */
}

void writeIsland(FILE* output, struct area island[][LENGTH], int count){ 	/* to write output.txt file */

	int x, y, counter = 0;

	fprintf(output,"%d", count);	/* first line is the total number of islands */

	if(count)						/* if number of island greather then zero go new line*/
		fprintf(output, "\n");

	for(x = 0; x < LENGTH; x++){
	
		for(y = 0; y < LENGTH; y++){

			if(island[x][y].id == 1){		/* if id_number is 1 this part of island is the first coordinate of island */
				fprintf(output,"%d %d", x, y);	/* write x,y of first part of islands*/
				count--;
				if(count)							/* if there is still new island go new line (to dosent write last new line) */ 
					fprintf(output, "\n");
			}
		}
		y = 0;
	}
}

int main(void){

	int level, numOfIsland;							/* level is value of L , numOfIslan is total islands number */

	FILE * inputFile = fopen("input.txt", "r");			/* input.txt file opened read mode */
	FILE * outputFile = fopen("output.txt","w");			/* output.txt file opened write mode */

	level = read(inputFile,island);				/* firs read input file and find L value */
	numOfIsland = numberOfIsland(island, level);		/* compare all cell of land with L value island or water and count number of island*/
	writeIsland(outputFile, island, numOfIsland);	/* write number of island and coordinates */
}