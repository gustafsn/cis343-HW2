/*****************************************************************************************************************
 * file_utils.c
 *
 * @author Nolan Gustafson
 * @version Sep. 21 2018
 ****************************************************************************************************************/

#include "file_utils.h"

/*****************************************************************************************************************
 * Finds the size of the given file then allocates memory that will be filled with the contents of that file.
 *
 * @param filename The name of the file that will be placed in memory.
 * @param buffer A pointer that holds the address of a pointer that holds the address where the file contents 
 * 	will be held.
 * @return The number of bytes successfully read.
 * **************************************************************************************************************/
int read_file( char* filename, char **buffer ){

	/* the file that will be read */	
	FILE *data;

       	data = fopen(filename,"r");//opens an existing file with the 'filename' param.

	//Finding the size of the file. This code is from BlackBoard.
	struct stat st;		 
	stat(filename, &st);	
	int size = st.st_size;	

	//allocate memory and have 'buffer' contain its address
	*buffer = (char *)malloc(size);

	//check to see if malloc succeeded
	if( *buffer == NULL ){
		fprintf( stderr, "Error: Memory was not allocated properly\n Exitting programm...\n\n");
		exit(1);
	}

	//uses fread to fill the memory 'buffer' is pointing to
	int bytesRead = fread(*buffer,sizeof(char),size,data);

	//check to see if the fread was successful. 
	if( bytesRead != size ){
		fprintf( stderr, "Error: File did not read to buffer properly\n Exitting program...\n\n" );
		exit(1);
	}
	
	//close data stream to prevent leaks
	fclose(data);

	return bytesRead; //returns the number of bytes fread read
}

/*****************************************************************************************************************
 * Writes the contents in the given memory location to a file
 *
 * @param filename The name of a file that the contents of 'buffer' will be written to. If the file does not 
 * 	already exist, one will be created.
 * @param buffer A pointer to the memory location of the data that will be written to a file.
 * @param size An int that is the number of bytes that 'buffer' points to.
 * @return the number of bytes successfully written to the file.
 * **************************************************************************************************************/
int write_file( char* filename, char *buffer, int size){

	/* the file that will be written to */
	FILE *newData;

	newData = fopen(filename, "w");//opens an existing file or creates a new one with the name from 'filename'
	
	//uses fwrite to write the array into the file from 'filename' param
	int bytesWritten = fwrite( buffer, sizeof(char), size, newData);
	
	//check to see if write to file was successful
	if( bytesWritten != size ){
		fprintf( stderr, "Error: Did not write to file properly\n Exitting program...\n\n" );
		exit(1);
	}

	//close data stream to prevent leaks
	fclose(newData);

	return bytesWritten; //returns the number of bytes successfully written
}
