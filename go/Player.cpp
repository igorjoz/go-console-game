#include "Player.h"

Player::Player() {
	this->id = 0;
	this->score = 0;
}

Player::Player(int id = 1) {
    if (id != 1 and id != 2) {
		throw "Invalid player id";
    }

	this->id = id;
	this->score = 0;
}


int Player::getId() {
	return this->id;
}
