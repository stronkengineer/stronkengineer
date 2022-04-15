#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

void displayBoard(char arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
void compAI(char arr[3][3]) {
	int pos = rand() % 3 + 0;
	int pos2 = rand() % 3 + 0;
	if (arr[pos][pos2] >= 'a' && arr[pos][pos2] <= 'j')
		arr[pos][pos2] = 'o';

	else if (arr[pos][pos2] == 'x') {
		pos = rand() % 3 + 0;
		pos2 = rand() % 3 + 0;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << arr[i][j] << " ";
		cout << endl;

	}
}
void winCheck(char arr[3][3]) {
	bool human_check_1 = arr[0][0] == 'x' && arr[0][1] == 'x' && arr[0][2] == 'x';
	bool human_check_2 = arr[1][0] == 'x' && arr[1][1] == 'x' && arr[1][2] == 'x';
	bool human_check_3 = arr[2][0] == 'x' && arr[2][1] == 'x' && arr[2][2] == 'x';
	bool human_check_4 = arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == 'x';
	bool human_check_5 = arr[0][1] == 'x' && arr[1][1] == 'x' && arr[2][0] == 'x';
	bool human_check_6 = arr[0][0] == 'x' && arr[1][0] == 'x' && arr[2][0] == 'x';

	bool bot_check_1 = arr[0][0] == 'o' && arr[0][1] == 'o' && arr[0][2] == 'o';
	bool bot_check_2 = arr[1][0] == 'o' && arr[1][1] == 'o' && arr[1][2] == 'o';
	bool bot_check_3 = arr[2][0] == 'o' && arr[2][1] == 'o' && arr[2][2] == 'o';
	bool bot_check_4 = arr[0][0] == 'o' && arr[1][1] == 'o' && arr[2][2] == 'o';
	bool bot_check_5 = arr[0][1] == 'o' && arr[1][1] == 'o' && arr[2][0] == 'o';
	bool bot_check_6 = arr[0][0] == 'o' && arr[1][0] == 'o' && arr[2][0] == 'o';
	if (human_check_1 || human_check_2 || human_check_3 || human_check_4 || human_check_5 || human_check_6) {
		cout << "You won!" << endl;
		
	}
	if (bot_check_1 || bot_check_2 || bot_check_3 || bot_check_4 || bot_check_5 || bot_check_6) {
		cout << "Computer won!" << endl;
	}
}
int main() {
	int x;
	cout << "Welcome to Tic-Tac-Toe. would you like to start a new game?" << endl;
	string check;
	char board[3][3] = { {'a','b','c'},{'e','f','g'},{'h','i','j'} };
	cin >> check;
	while (check == "Yes" || "yes") {
		cout << "enter the desired row and column: " << endl;
		displayBoard(board);
		int row, column;
		cin >> row >> column;
		if (board[row][column] == 'o') {
			cout << "Invalid move, please input other numbers: " << endl;
			cin >> row >> column;
		}
		else board[row][column] = 'x';
		compAI(board);
		winCheck(board);
		cout << "Continue? (yes/no)" << endl;
		cin >> check;
	}

}
