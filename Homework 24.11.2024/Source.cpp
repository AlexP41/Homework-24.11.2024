/*
	����ֲ�
	=======


�5
	�������� �������, ��� ������ ����������� ����� � 100 ����� �����, ���������� ���������� ����� (������� � ������ ������� 10�10),
	� ��������� �������, � ��� ���������� ����������� � 10 �����, ���� ���� ��������




+++++++ ���������� ������� ����������� �� ����������
	https://fsx1.itstep.org/api/v1/files/v7HPgHcT8eeoPIvbWucTtQp
*/

/*
�1
	�������� �������� �������, �� �������� �� ����� min �� max �� ����� �����.
*/

/*
#include <iostream>

using namespace std;

int main() {
	system("chcp 1251>null");

	void minMaxFunction(int n1, int n2, int n3);

	int num1, num2, num3;
	cout << "������ ��� ����� ����� �����" << endl; 
	cout << "����� �����: ";
	cin >> num1;
	cout << endl;
	cout << "����� �����: ";
	cin >> num2;
	cout << endl;
	cout << "���� �����: ";
	cin >> num3;
	cout << endl;

	minMaxFunction(num1, num2, num3);

	return 0;
}

void minMaxFunction(int n1, int n2, int n3) {
	int arr[] = {n1, n2, n3};
	int min = n1, max = n1;
	for (auto const& num : arr) {
		if (min > num) min = num;
		if (max < num) max = num;
	}

	cout << "̳������� ��������: " << min << endl;
	cout << "����������� ��������: " << max << endl;
}
*/

/*
�2
	�������� �������� �������, �� ������� ������� ��������, ��'����� � �������� �������� ���������� �� ������.
	����� ����� ����������, ���������� ������ ��������.
*/
/*
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
	srand(time(NULL));
	system("chcp 1251>null");

	void NumbersForArray(int length, vector <int> arr);

	int length;
	cout << "Input array's length: ";
	cin >> length;

	vector <int> arr(length);

	int randomNum;
	for (int i = 0; i < length; i++) {
		randomNum = -100 + rand() % 201;
		arr[i] = randomNum;
	}
	cout << "Array: ";
	for (auto const& num : arr) {
		cout << setw(5) << num;
	}
	cout << endl;

	NumbersForArray(length, arr);
	return 0;
}

void NumbersForArray(int length, vector <int> arr) {
	int SumForPos = 0, SumForNeg = 0, SumForZer = 0;
	for (auto const& num : arr) {
		num > 0 ? SumForPos++ : num < 0 ? SumForNeg++ : SumForZer++;
	}

	cout << "\033[031mʳ������ ���������� ������� � �����: \033[0m" << SumForPos << endl;
	cout << "\033[032mʳ������ ���������� ������� � �����: \033[0m" << SumForNeg << endl;
	cout << "\033[033mʳ������ ���� � �����: \033[0m" << SumForZer << endl;
}
*/

/*
�3
	��� ����� ����� ��������� 10 ��������. �������� �������, ��� ����� ����� �� ���������� ��� �� ���������,
	������� �� �������� ��������� �������. ���� �� ������� 1, ���������� ��� �� ���������, ���� 0, �� �� ����������.
	 ����� 2 ��������� ������� � �� ����� ���� �����, ����� �������� �� ������������� ������� 1.
*/
/*
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

const int LENGTH = 10;

int main() {
	srand(time(NULL));
	system("chcp 1251>null");

	void NumbersForArray(int length, int arr[], int pathToSort = 1);
	int arr[LENGTH];

	int randomNum;
	for (int i = 0; i < LENGTH; i++) {
		randomNum = -100 + rand() % 201;
		arr[i] = randomNum;
	}
	cout << "Array: ";
	for (int i = 0; i < LENGTH; i++) {
		cout << setw(5) << arr[i];
	}
	cout << endl;


	int userChoice;
	while (true) {
		cout << "\033[033m�� ������ ����������� �����?\n�� ��������� - 1;\n�� ���������� - 0;\n��� ����: \033[0m";
		cin >> userChoice;
		if (cin.fail()) {
			cout << "\033[031m �������! ���� �����, ������ �����(1 ��� 0).\033[0m\n";
			cin.clear(); 
			cin.ignore(1000, '\n');
			continue;
		}
		if (userChoice != 1 && userChoice != 0) {
			cout << "\033[031m �������! ���� �����, ������ ��� 1, ��� 0.\033[0m\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	}

	userChoice == 1 ? NumbersForArray(LENGTH, arr) : NumbersForArray(LENGTH, arr, 0);

	return 0;
}

void NumbersForArray(int length, int arr[], int pathToSort = 1) {

	pathToSort == 1 ? (sort(arr, arr + length), reverse(arr, arr + length)) : sort(arr, arr + length);
	cout << "³����������� �����: ";
	for (int i = 0; i < LENGTH; i++) {
		cout << setw(5) << arr[i];
	}
	cout << endl;
}
*/

/*
�4
	��� "������". �����: � ��� ������ ������ � ���������� �� 1 �� 6. ��� ���������� � ����'������,
	������ ��������� �� ����. �������� ���, � ���� ���� ����, �� ������, �� ��������� �'��� ����� �����.
	���������� ��������� ��������� ������� ���� ������� �� ����'������. ������ ������������� �� ��������� �������.
	��������� ��� ��������� �������� ������� ���� �� ������� ��� ���� ��������. ������� ��� �� �������� �������.
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <thread>  // ��� std::this_thread::sleep_for
#include <chrono>  // ��� std::chrono::seconds


using namespace std;

const int numberOfDiceRolling = 5;

int main() {
	srand(time(NULL));
	system("chcp 1251>null");

	bool WhoThrow_a_DiceFirst();
	void printDieFace(int face);
	void userWon(int sumOfPoints_Computer = 0, int sumOfPoints_User = 0);
	void computerWon(int sumOfPoints_Computer = 0, int sumOfPoints_User = 0);

	if ( WhoThrow_a_DiceFirst() ) {
		userWon();
	}
	else {
		computerWon();
	}

	return 0;
}

bool WhoThrow_a_DiceFirst() {
	int randomNumber, userChoice;
	while (true) {
		cout << "\033[033m��������� ����� (1 ��� 2)\n��� ����: \033[0m";
		cin >> userChoice;
		if (cin.fail()) {
			cout << "\033[031m �������! ���� �����, ������ �����(1 ��� 2).\033[0m\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (userChoice != 1 && userChoice != 2) {
			cout << "\033[031m �������! ���� �����, ������ ��� 1, ��� 2.\033[0m\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	}

	cout << "\033[032m��������� ����� ...\033[0m" << endl;
	this_thread::sleep_for(chrono::seconds(2));
	randomNumber = 1 + rand() % 2;
	cout << "�������� �����: " << randomNumber << endl;

	return randomNumber == userChoice ? true : false;
}

void printDieFace(int face) {
	switch (face) {
	case 1:
		std::cout << " ----- \n|     |\n|  *  |\n|     |\n ----- \n";
		break;
	case 2:
		std::cout << " ----- \n| *   |\n|     |\n|   * |\n ----- \n";
		break;
	case 3:
		std::cout << " ----- \n| *   |\n|  *  |\n|   * |\n ----- \n";
		break;
	case 4:
		std::cout << " ----- \n| * * |\n|     |\n| * * |\n ----- \n";
		break;
	case 5:
		std::cout << " ----- \n| * * |\n|  *  |\n| * * |\n ----- \n";
		break;
	case 6:
		std::cout << " ----- \n| * * |\n| * * |\n| * * |\n ----- \n";
		break;
	default:
		std::cout << "Invalid face\n";
	}
}

void userWon(int sumOfPoints_Computer = 0, int sumOfPoints_User = 0) {
	cout << "\033[032m³���! �� ������ ������.\033[0m" << endl;
	int randFaceNum;
	for (int i = 0; i < numberOfDiceRolling; i++) {

		// Player's throw

		randFaceNum = 1 + rand() % 6;
		sumOfPoints_User += randFaceNum;

		cout << "��� �����: " << endl;
		this_thread::sleep_for(chrono::seconds(2));
		printDieFace(randFaceNum);
		if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[32m���� ������� ���� ���������: ";
		else if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[031m���� ������� ���� ���������: ";
		else cout << "\033[033m���� ������� ���� ���������: ";

		cout << sumOfPoints_User;
		cout << "\033[0m" << endl;

		// Computer's throw

		randFaceNum = 1 + rand() % 6;
		sumOfPoints_Computer += randFaceNum;

		cout << "����� ����'�����: " << endl;
		this_thread::sleep_for(chrono::seconds(2));
		printDieFace(randFaceNum);
		if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[32m������� ���� ����'����� ���������: ";
		else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[031m������� ���� ����'����� ���������: ";
		else cout << "\033[033m������� ���� ����'����� ���������: ";

		cout << sumOfPoints_Computer;
		cout << "\033[0m" << endl;
	}


	// Summing up
	cout << "\033[034mϳ�������� ������� ... \033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(3));
	if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[32m���� ��������� ���� ���������: ";
	else if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[031m���� ��������� ���� ���������: ";
	else cout << "\033[033m���� ��������� ���� ���������: ";
	this_thread::sleep_for(chrono::seconds(2));

	cout << sumOfPoints_User;
	cout << "\033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(3));
	if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[32m��������� ���� ����'����� ���������: ";
	else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[031m��������� ���� ����'����� ���������: ";
	else cout << "\033[033m��������� ���� ����'����� ���������: ";

	this_thread::sleep_for(chrono::seconds(2));
	cout << sumOfPoints_Computer;
	cout << "\033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(2));

	cout << "\033[2J\033[1;1H";


	if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[31m �� ����, �� ��������(" << endl;
	else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[032m³���! �� ���������!" << endl;
	else cout << "\033[033m������ ����!" << endl;

	cout << "\033[0m" << endl;
}

void computerWon(int sumOfPoints_Computer = 0, int sumOfPoints_User = 0) {
	cout << "\033[031m�� ���� �� �� �������( ����'���� ������ ������ ������.\033[0m" << endl;
	int randFaceNum;
	for (int i = 0; i < numberOfDiceRolling; i++) {

		// Computer's throw

		randFaceNum = 1 + rand() % 6;
		sumOfPoints_Computer += randFaceNum;

		cout << "����� ����'�����: " << endl;
		this_thread::sleep_for(chrono::seconds(2));
		printDieFace(randFaceNum);
		if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[32m������� ���� ����'����� ���������: ";
		else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[031m������� ���� ����'����� ���������: ";
		else cout << "\033[033m������� ���� ����'����� ���������: ";

		cout << sumOfPoints_Computer;
		cout << "\033[0m" << endl;

		// Player's throw

		randFaceNum = 1 + rand() % 6;
		sumOfPoints_User += randFaceNum;

		cout << "��� �����: " << endl;
		this_thread::sleep_for(chrono::seconds(2));
		printDieFace(randFaceNum);
		if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[32m���� ������� ���� ���������: ";
		else if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[031m���� ������� ���� ���������: ";
		else cout << "\033[033m���� ������� ���� ���������: ";

		cout << sumOfPoints_User;
		cout << "\033[0m" << endl;

	}

	// Summing up
	cout << "\033[034mϳ�������� ������� ... \033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(3));
	if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[32m���� ��������� ���� ���������: ";
	else if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[031m���� ��������� ���� ���������: ";
	else cout << "\033[033m���� ��������� ���� ���������: ";
	this_thread::sleep_for(chrono::seconds(2));

	cout << sumOfPoints_User;
	cout << "\033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(3));
	if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[32m��������� ���� ����'����� ���������: ";
	else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[031m��������� ���� ����'����� ���������: ";
	else cout << "\033[033m��������� ���� ����'����� ���������: ";

	this_thread::sleep_for(chrono::seconds(2));
	cout << sumOfPoints_Computer;
	cout << "\033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(2));

	cout << "\033[2J\033[1;1H";


	if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[31m �� ����, �� ��������(" << endl;
	else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[032m³���! �� ���������!" << endl;
	else cout << "\033[033m������ ����!" << endl;

	cout << "\033[0m" << endl;
}

