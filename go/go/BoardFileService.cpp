#define _CRT_SECURE_NO_WARNINGS

#include "Board.h"


void Board::convertNumberAndWriteToBuffer(int number, char* buffer, int* bufferIndex) {
	char* digits = Helper::convertNumberIntoDigitsArray(number);
	int digitsIndex = 0;

	while (digits[digitsIndex] != '\0') {
		buffer[(*bufferIndex)++] = digits[digitsIndex++];
	}
	buffer[(*bufferIndex)++] = '\n';
}


int Board::readAndConvertToNumber(char* buffer, int* bufferIndex) {
	char digits[100];
	int digitsIndex = 0;

	char currentCharacter = buffer[(*bufferIndex)++];
	
	while (currentCharacter != '\n') {
		digits[digitsIndex++] = currentCharacter;

		currentCharacter = buffer[(*bufferIndex)++];
	}

	int number = Helper::convertDigitsArrayIntoNumber(digits, digitsIndex);

	return number;
}


void Board::saveBoardToFile(char* fileName) {
	FILE* file;
	char buffer[20000];
	int bufferIndex = 0;

	// conver board size & write to the file
	Board::convertNumberAndWriteToBuffer(this->getCurrentPlayerId(), buffer, &bufferIndex);
	Board::convertNumberAndWriteToBuffer(this->blackPlayer->getScore(), buffer, &bufferIndex);
	Board::convertNumberAndWriteToBuffer(this->whitePlayer->getScore(), buffer, &bufferIndex);
	Board::convertNumberAndWriteToBuffer(this->size, buffer, &bufferIndex);
	
	for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
		for (int columnIndex = 0; columnIndex < this->size; columnIndex++) {
			buffer[bufferIndex++] = '0' + this->board[rowIndex][columnIndex];
		}	
	}
	buffer[bufferIndex++] = '\n';

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

	int bufferIndex = 0;
	int currentPlayerId = -1;
	int blackPlayerScore = -1;
	int whitePlayerScore = -1;
	int boardSize = -1;

	file = fopen(fileName, "rb");
	if (file == NULL) {
		exit(1);
	}

	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);

	buffer = (char*)malloc(sizeof(char) * size);
	if (buffer == NULL) {
		exit(2);
	}

	result = fread(buffer, 1, size, file);
	if (result != size) {
		exit(3);
	}

	currentPlayerId = this->readAndConvertToNumber(buffer, &bufferIndex);
	blackPlayerScore = this->readAndConvertToNumber(buffer, &bufferIndex);
	whitePlayerScore = this->readAndConvertToNumber(buffer, &bufferIndex);
	boardSize = this->readAndConvertToNumber(buffer, &bufferIndex);

	this->blackPlayer->setScore(blackPlayerScore);
	this->whitePlayer->setScore(whitePlayerScore);

	*this = Board(boardSize, true, this->blackPlayer, this->whitePlayer, currentPlayerId);

	for (int rowIndex = 0; rowIndex < this->size; rowIndex++) {
		for (int columnIndex = 0; columnIndex < this->size; columnIndex++) {
			this->board[rowIndex][columnIndex] = buffer[bufferIndex++] - '0';
		}
	}

	fclose(file);
	free(buffer);
}
