#pragma once


#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
	Player(int id, int score);

	int getId();
	int getScore();
	void setScore(int score);
	int incrementScore();

private:
	int id;
	int score;
};


#endif
