#pragma once

// board constants
int const BOARD_SIZE = 9;

int const VERTICAL_BOARD_PADDING = 2;
int const HORIZONTAL_BOARD_PADDING = 2 * 2;

int constexpr TOP_BOARD_BORDER_Y = VERTICAL_BOARD_PADDING + 1;
int constexpr BOTTOM_BOARD_BORDER_Y = BOARD_SIZE + VERTICAL_BOARD_PADDING + 2;
int constexpr LEFT_BOARD_BORDER_X = HORIZONTAL_BOARD_PADDING + 1;
int constexpr RIGHT_BOARD_BORDER_X = (BOARD_SIZE * 2) + HORIZONTAL_BOARD_PADDING + 3;

int const I_KEY_CODE = 0x69;

unsigned char const DOUBLE_HORIZONTAL_LINE_CODE = 205;
unsigned char const DOUBLE_VERTICAL_LINE_CODE = 186;

unsigned char const TOP_LEFT_DOUBLE_LINE_CORNER_CODE = 201;
unsigned char const TOP_RIGHT_DOUBLE_LINE_CORNER_CODE = 187;
unsigned char const BOTTOM_RIGHT_DOUBLE_LINE_CORNER_CODE = 188;
unsigned char const BOTTOM_LEFT_DOUBLE_LINE_CORNER_CODE = 200;

unsigned char const BOTTOM_INTERSECTION_CHARACTER_CODE = 193;
unsigned char const TOP_INTERSECTION_CHARACTER_CODE = 194;
unsigned char const LEFT_INTERSECTION_CHARACTER_CODE = 195;
unsigned char const RIGHT_INTERSECTION_CHARACTER_CODE = 180;

unsigned char const INTERSECTION_CHARACTER_CODE = 197;
unsigned char const HORIZONTAL_LINE_CHARACTER_CODE = 196;

unsigned char const TOP_LEFT_LINE_CORNER_CODE = 218;
unsigned char const TOP_RIGHT_LINE_CORNER_CODE = 191;
unsigned char const BOTTOM_RIGHT_LINE_CORNER_CODE = 217;
unsigned char const BOTTOM_LEFT_LINE_CORNER_CODE = 192;

unsigned short int const WHITE_PLAYER_ID = 1;
unsigned short int const BLACK_PLAYER_ID = 2;
