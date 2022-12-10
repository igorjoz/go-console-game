#include "Player.h"


Player::Player(int id) {
    if (id != 1 and id != 2) {
		throw "Invalid player id";
    }

	this->id = id;
	this->score = 0;
}


int Player::getId() {
	return this->id;
}


int Player::getScore() {
	return this->score;
}


int Player::incrementScore() {
	this->score++;
	
	return this->score;
}
