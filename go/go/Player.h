#pragma once

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

