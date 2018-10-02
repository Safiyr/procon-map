#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

inline void InitRand()
{
	srand((int)time(NULL));
}

inline int my_random()
{
	return rand() % 4;
}

int sign(int n)
{
	return (rand() % 5 < 1) ? n *= -1 : n;
}

void dec_date(int date[12][12], int x, int y, int h_y, int h_x);

void show(int date[12][12], int x, int y);


int main()
{
	int date[12][12] = {};
	int x, y, half_X = 0, half_Y = 0;
	int i, j;
	int rem_x, rem_y;
	int PLAYER[2];
	
	vector<string> V;

	InitRand();

	cin >> x >> y;

	(x % 2) ? rem_x = 1 : rem_x = 0;
	(y % 2) ? rem_y = 1 : rem_y = 0;

	half_X = x / 2;
	half_Y = y / 2;

	for (i = 0; i < half_Y; i++) {
		for (j = 0; j < half_X; j++) {
			date[i][j] = sign(my_random());
		}
	}

	if (rem_x) {
		for (i = 0; i < y; i++) {
			date[i][half_X] = sign(my_random());
		}
	}

	if (rem_y) {
		for (i = 0; i < x; i++) {
			date[half_Y][i] = sign(my_random());
		}
	}

	dec_date(date, x, y, half_Y, half_X);

	show(date, x, y);

	V.push_back(std::to_string(y));
	V.push_back(" ");
	V.push_back(std::to_string(x));
	V.push_back(":");

	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			V.push_back(std::to_string(date[i][j]));
			V.push_back(" ");
		}
		V.push_back(":");
	}

	for (i = 0; i < V.size(); i++) {
		cout << V[i];
	}

	return 0;
}

void dec_date(int date[12][12], int x, int y, int h_y, int h_x)
{
	for (int h = 0; h <= h_y; h++) {
		for (int i = 0; i <= h_x; i++) {
			for (int j = x; j >= h_x - 1; j--) {
				if (x - i - j == 1) {
					date[h][j] = date[h][i];
				}
			}
		}
	}

	for (int h = 0; h <= h_y; h++) {
		for (int i = 0; i <= h_x; i++) {
			for (int j = y; j >= h_y - 1; j--) {
				if (y - h - j == 1) {
					date[j][i] = date[h][i];
				}
			}
		}
	}

	for (int h = h_y; h <= y; h++) {
		for (int i = 0; i <= h_x; i++) {
			for (int j = x; j >= h_x - 1; j--) {
				if (x - i - j == 1) {
					date[h][j] = date[h][i];
				}
			}
		}
	}


}

void show(int date[12][12], int x, int y)
{
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			printf("%3d", date[i][j]);
		}
		cout << endl;
	}
}
