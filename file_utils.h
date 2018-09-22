/*****************************************************************************************************************
 * file_utils.h
 *
 * @author Nolan Gustafson
 * @version Sep. 21 2018
 ****************************************************************************************************************/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef FILE_UTILS
#define FILE_UTILS

/*****************************************************************************************************************
 * Finds the size of the given file then allocates memory that will be filled with the contents of that file.
 *
 * @param filename The name of the file that will be placed in memory.
 * @param buffer A pointer that holds the address of a pointer that holds the address where the file contents 
 * 	will be held.
 * @return The number of bytes successfully read.
 * **************************************************************************************************************/
int read_file( char* filename, char **buffer );

/*****************************************************************************************************************
 * Writes the contents in the given memory location to a file
 *
 * @param filename The name of a file that the contents of 'buffer' will be written to. If the file does not 
 * 	already exist, one will be created.
 * @param buffer A pointer to the memory location of the data that will be written to a file.
 * @param size An int that is the number of bytes that 'buffer' points to.
 * @return the number of bytes successfully written to the file.
 * **************************************************************************************************************/
int write_file( char* filename, char *buffer, int size);

#endif
