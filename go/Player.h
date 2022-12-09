#pragma once

class Player
{
public:
	Player();
	Player(int id);
	int getId();

private:
	int id;
	int score;
};

