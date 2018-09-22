/*****************************************************************************************************************
 * reverse.c
 *
 * @author Nolan Gustafson
 * @version Sep. 21 2018
 ****************************************************************************************************************/

#include "file_utils.h"

/*****************************************************************************************************************
 * the main method
 *
 * @param argc the command line argument count
 * @param argv the command line argumnents
 * **************************************************************************************************************/
int main ( int argc, char** argv)
{	
	//check for arguments only for an input and output files
	if (argc !=3){
		fprintf( stderr, "ERROR: This program requires two command line arguments.\n");
		fprintf( stderr, "First argument: Input file to reverse. Second argument: Output file for reversed text.\n\n");
	}
	else{	
		/* the input file */
		char *textFile = argv[1]; 
		
		/* the output file */
		char *newTextFile = argv[2];
		
		/* the space in memory used to reverse the input */
		char *buffer;
		
		//use read_file() to fill buffer with the file contents, and collect the file's size in 'fileSize'
		int fileSize = read_file(textFile, &buffer);

		//reverse the contents now in buffer
		int i = 0;		// begining of 'buffer'
		int j = fileSize-1;	// end of 'buffer'
		char temp;		

		//swaps the chars from front to back, until the two positions cross
		while (i < j) {
			temp = buffer[i];
			buffer[i] = buffer[j];
			buffer[j] = temp;
			i++;
			j--;
		}

		//write the new contents of buffer to a new file
		write_file(newTextFile, buffer, fileSize);
		free(buffer);
	}
}
