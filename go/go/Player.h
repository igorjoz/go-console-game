#pragma once


#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
	Player(int id);

	int getId();
	int getScore();
	int incrementScore();

private:
	int id;
	int score;
};


#endif
