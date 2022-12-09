#pragma once


class Point
{
public:
	Point();
	Point(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
private:
	int x;
	int y;
};

