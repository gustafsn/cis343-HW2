# cis343-HW2
Excersice with pointers. Reverses a file's contents then writes to a new file.

file_utils.h/c contains the method read_file() for reading data from a file, and then putting it into memory where it can be modified.
Then that modified data in memory can be saved to a new file using the method write_file.

reverse.c uses the above methods to reverse a text file and write it to a new one.
