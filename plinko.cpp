// plinko plus
// Caleb Rudder

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void main() {
	ifstream fin("plinko.in");
	if (fin.is_open()) {
		ofstream fout("plinko.out");

		vector < vector<pair<int, int>>> gameBoard;
		vector <pair<int, int>> pairs;
		pair<int, int> pair;
		int number;
		string line;
		int gameSize;
		int maxValue;
		fin >> gameSize;
		
		while (gameSize != 0) {

			maxValue = 0;

			if (gameSize == 1) {
				fin >> maxValue;
			}
			else {
				for (int row = 0; row < gameSize; row++) {
					for (int col = 0; col <= row; col++) {
						fin >> number;
						pair.first = number;
						pair.second = 0;
						pairs.push_back(pair);
					}
					gameBoard.push_back(pairs);
					pairs.clear();
				}

				for (int row = 0; row < gameSize; row++) {
					for (int col = 0; col <= row; col++) {
						if (row == 1) {
							gameBoard[row][col].second = gameBoard[row][col].first + gameBoard[0][0].first;
						}
						else if (row > 1 && col == 0) {
							gameBoard[row][col].second = gameBoard[row][col].first + gameBoard[row - 1][col].second;
						}
						else if (row > 1 && col > 0 && col != row) {
							int left = gameBoard[row - 1][col - 1].second;
							int right = gameBoard[row - 1][col].second;

							if (left > right) {
								gameBoard[row][col].second = gameBoard[row][col].first + left;
							}
							else {
								gameBoard[row][col].second = gameBoard[row][col].first + right;
							}
						}
						else if (row > 1 && col > 0 && col == row) {
							gameBoard[row][col].second = gameBoard[row][col].first + gameBoard[row - 1][col - 1].second;
						}
					}
				}
				maxValue = gameBoard[gameSize - 1][0].second;
				for (int col = 0; col < gameSize; col++) {
					if (gameBoard[gameSize - 1][col].second > maxValue) {
						maxValue = gameBoard[gameSize - 1][col].second;
					}
				}
			}
			fout << maxValue << endl;
			fin >> gameSize;
			gameBoard.clear();
		}
		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}