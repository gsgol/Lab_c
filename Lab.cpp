// Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Задача 8
#include <iostream>
using namespace std;
int main()
{
    int a[8];
	for (int i = 0; i < 8; i++) {
		cin >> a[i]; 
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			if (a[j] < a[j + 1]) {
				int b = a[j]; 
				a[j] = a[j + 1]; 
				a[j + 1] = b; 
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		cout << a[i] << ' ' ;
	}


}
// Точки с координатами
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;

double distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow((x2 - x1),2) + pow((y2  - y1),2));
}
int main()
{
	int x[6] = { 2,3,4,5,6,7 };
	int y[6] = { 1,8,7,9,6,2 };
	double dist[6][6];
	double min = distance(x[1], y[1], x[2], y[2]), max = -1;
	int min_1_id = 1, min_2_id = 2, max_id = -1;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			dist[i][j] = distance(x[i], y[i], x[j], y[j]);
			if (dist[i][j] < min && i != j)
			{
				min = dist[i][j];
				min_1_id = i;
				min_2_id = j;
			}
		}
	}
	for (int i = 0; i < 6; ++i)
	{
		if (dist[min_1_id][i] + dist[min_2_id][i] > max)
		{
			max = dist[min_1_id][i] + dist[min_2_id][i];
			max_id = i;
		}

	}
	cout << min << ' ' << min_1_id << ' ' << min_2_id << ' ' << max << ' ' << max_id;
}
