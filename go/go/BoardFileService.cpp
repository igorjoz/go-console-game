#define _CRT_SECURE_NO_WARNINGS

#include "Board.h"


void Board::saveBoardToFile(char* fileName) {
	FILE* file;
	char buffer[] = { 'x' , 'y' , 'z' };
	
	//file = fopen("myfile.bin", "wb");
	file = fopen(fileName, "wb");
	
	fwrite(buffer, sizeof(char), sizeof(buffer),file);
	
	fclose(file);
}

void Board::loadBoardFromFile(char* fileName) {
	FILE* file;
	long size;
	char* buffer;
	size_t result;

	//file = fopen("myfile.bin", "rb");
	file = fopen(fileName, "rb");
	if (file == NULL) {
		exit(1);
	}

	// obtain file size:
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);

	// allocate memory to contain the whole file:
	buffer = (char*)malloc(sizeof(char) * size);
	if (buffer == NULL) {
		exit(2);
	}

	// copy the file into the buffer:
	result = fread(buffer, 1, size, file);
	if (result != size) {
		exit(3);
	}

	/* the whole file is now loaded in the memory buffer. */

	// terminate
	fclose(file);
	free(buffer);
}
