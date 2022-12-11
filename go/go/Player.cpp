#include "Player.h"


Player::Player(int id, int score = 0) {
	if (id != 1 and id != 2) {
		throw "Invalid player id";
	}

	this->id = id;
	this->score = score;
}


int Player::getId() {
	return this->id;
}


int Player::getScore() {
	return this->score;
}


void Player::setScore(int score) {
	this->score = score;
}


int Player::incrementScore() {
	this->score++;

	return this->score;
}
