#include<iostream>
#include<string>
bool checkforWin(std::string tictactoe[3][3], std::string player) {
	for (int i = 0; i < 3; i++) {
		// Check row i
		if (tictactoe[i][0] == player && tictactoe[i][1] == player && tictactoe[i][2] == player) {
			return true;
		}
		// Check column i
		if (tictactoe[0][i] == player && tictactoe[1][i] == player && tictactoe[2][i] == player) {
			return true;
		}
	}
	// Check diagonals
	if (tictactoe[0][0] == player && tictactoe[1][1] == player && tictactoe[2][2] == player) {
		return true;
	}
	if (tictactoe[0][2] == player && tictactoe[1][1] == player && tictactoe[2][0] == player) {
		return true;
	}
	return false;
}

void displayboard(std::string tictactoe2[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << tictactoe2[i][j] << " ";
		}
		std::cout << '\n';
	}
}
bool checkinput(std::string choice) {
	if (choice == "1" || choice == "2" || choice == "3" || choice == "4" ||
		choice == "5" || choice == "6" || choice == "7" || choice == "8" ||
		choice == "9") {
		return true;
	}
	return false;
}
int main() {
	std::string tictactoe1[3][3] = { {"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"} };
	std::string tictactoe2[3][3] = { {"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"} };
	std::string choice;
	bool loopcondition = false;
	bool wronginput = false;
	displayboard(tictactoe2);
	while(true) {
	while (true) {
		std::cout << "\nChoose for X: ";
		std::cin >> choice;
		if (checkinput(choice) == false) {
			std::cout << "\nThat is not a viable square.Try again.\n";
			continue;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; i < 3; j++) {
				if (tictactoe1[i][j] == choice) {
					loopcondition = true;
					if (tictactoe2[i][j] == "X" || tictactoe2[i][j] == "O") {
						std::cout << "\nThat square is occupied.Try again.\n";
						wronginput = true;
						break;
					}
					else {
						tictactoe2[i][j] = "X";
						wronginput = false;
						break;
					}
				}
			}
			if (loopcondition) {
				break;
			}
		}
		if (wronginput) {
			continue;
		}
		std::cout << '\n';
		displayboard(tictactoe2);
		break;
	}
	//Checks for win
	if (checkforWin(tictactoe2, "X") == true) {
		std::cout << "\nWoohoo! Player X wins!\n";
		break;
	}
	while (true) {

		std::cout << "Choose for O: ";
		std::cin >> choice;
		if (checkinput(choice) == false) {
			std::cout << "\nThat is not a viable square.Try again.\n";
			continue;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; i < 3; j++) {
				if (tictactoe1[i][j] == choice) {
					loopcondition = true;
					if (tictactoe2[i][j] == "X" || tictactoe2[i][j] == "O") {
						std::cout << "\nThat square is occupied.Try again.\n";
						wronginput = true;
						break;
					}
					else {
						tictactoe2[i][j] = "O";
						wronginput = false;
						break;
					}
				}
			}
			if (loopcondition) {
				break;
			}
		}
		if (wronginput) {
			continue;
		}
		std::cout << '\n';
		displayboard(tictactoe2);
		break;
	}
	//Checks for win
	if (checkforWin(tictactoe2, "O") == true) {
		std::cout << "\nWoohoo! Player O wins!\n";
		break;
	}
}
	return 0;
}