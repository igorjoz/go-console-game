#define _CRT_SECURE_NO_WARNINGS

#include "Board.h"


void converNumberAndWriteToBuffer(int number, char* buffer, int* bufferIndex) {
	char* digits = Helper::convertNumberIntoDigitsArray(number);
	int digitsIndex = 0;

	while (digits[digitsIndex] != '\0') {
		buffer[(*bufferIndex)++] = digits[digitsIndex++];
	}
	buffer[(*bufferIndex)++] = '\n';
}


void Board::saveBoardToFile(char* fileName) {
	FILE* file;
	char buffer[20000];
	int bufferIndex = 0;

	// conver board size & write to the file
	converNumberAndWriteToBuffer(this->getCurrentPlayerId(), buffer, &bufferIndex);
	converNumberAndWriteToBuffer(this->size, buffer, &bufferIndex);
	
	
	for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
		for (int columnIndex = 0; columnIndex < this->size; columnIndex++) {
			buffer[bufferIndex++] = '0' + this->board[rowIndex][columnIndex];
		}	
	}
	buffer[bufferIndex++] = '\n';

	//buffer[0] = '0' + digitsIndex;
	//buffer[1] = '\n';

	for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
		for (int columnIndex = 0; columnIndex < this->size; columnIndex++) {
			buffer[bufferIndex++] = '0' + this->previousBoard[rowIndex][columnIndex];
		}
	}
	buffer[bufferIndex++] = '\n';
	
	file = fopen(fileName, "wb");

	/* FORMAT:
	current PLAYER ID
	black player SCORE
	white player SCORE
	board SIZE
	BOARD (0 - empty, 1 - black, 2 - white)
	PREVIOUS board
	*/
	fwrite(buffer, sizeof(char), bufferIndex, file);
	
	fclose(file);
}

void Board::loadBoardFromFile(char* fileName) {
	FILE* file;
	long size;
	char* buffer;
	size_t result;

	file = fopen(fileName, "rb");
	if (file == NULL) {
		exit(1);
	}

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

	fclose(file);
	free(buffer);
}
