/*
	ФУНКЦІЇ
	=======


№5
	Напишіть функцію, яка приймає одновимірний масив зі 100 цілих чисел, заповнених випадковим чином (вивести у вигляді таблиці 10Х10),
	і знаходить позицію, з якої починається послідовність з 10 чисел, сума яких мінімальна




+++++++ Навчальний матеріал знаходиться за посиланням
	https://fsx1.itstep.org/api/v1/files/v7HPgHcT8eeoPIvbWucTtQp
*/

/*
№1
	Написати прототип функцію, що виводить на екран min та max із трьох чисел.
*/

/*
#include <iostream>

using namespace std;

int main() {
	system("chcp 1251>null");

	void minMaxFunction(int n1, int n2, int n3);

	int num1, num2, num3;
	cout << "Введіть три чсила через пробіл" << endl; 
	cout << "Перше число: ";
	cin >> num1;
	cout << endl;
	cout << "Друге число: ";
	cin >> num2;
	cout << endl;
	cout << "Третє число: ";
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

	cout << "Мінімальне значення: " << min << endl;
	cout << "Максимальне значення: " << max << endl;
}
*/

/*
№2
	Написати прототип функцію, що визначає кількість додатних, від'ємних і нульових елементів переданого їй масиву.
	Розмір вказує користувач, заповнення масиву рандомне.
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

	cout << "\033[031mКількість позитивних значень у масиві: \033[0m" << SumForPos << endl;
	cout << "\033[032mКількість негативних значень у масиві: \033[0m" << SumForNeg << endl;
	cout << "\033[033mКількість нулів у масиві: \033[0m" << SumForZer << endl;
}
*/

/*
№3
	Дан масив чисел розмірністю 10 елементів. Написати функцію, яка сортує масив за зростанням або за спаданням,
	залежно від третього параметра функції. Якщо він дорівнює 1, сортування йде за спаданням, якщо 0, то за зростанням.
	 Перші 2 параметри функції — це масиві його розмір, третій параметр за замовчуванням дорівнює 1.
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
		cout << "\033[033mЯк бажаєте відсортувати масив?\nЗа спаданням - 1;\nЗа зростанням - 0;\nВаш вибір: \033[0m";
		cin >> userChoice;
		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, введіть число(1 або 0).\033[0m\n";
			cin.clear(); 
			cin.ignore(1000, '\n');
			continue;
		}
		if (userChoice != 1 && userChoice != 0) {
			cout << "\033[031m Помилка! Будь ласка, введіть або 1, або 0.\033[0m\n";
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
	cout << "Відсортований масив: ";
	for (int i = 0; i < LENGTH; i++) {
		cout << setw(5) << arr[i];
	}
	cout << endl;
}
*/

/*
№4
	Гра "Кубики". Умова: є два гральні кубики зі значеннями від 1 до 6. Гра відбувається з комп'ютером,
	кубики кидаються по черзі. Перемагає той, у кого сума балів, що випали, за підсумками п'яти кидків більше.
	Передбачте можливість отримання першого ходу людиною чи комп'ютером. Кубики відображаються за допомогою символів.
	Наприкінці гри необхідно виводити середню суму за кидками для обох учасників. Розбити гру на декалька функцій.
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <thread>  // Для std::this_thread::sleep_for
#include <chrono>  // Для std::chrono::seconds


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
		cout << "\033[033mЗагадайте число (1 або 2)\nВаш вибір: \033[0m";
		cin >> userChoice;
		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, введіть число(1 або 2).\033[0m\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (userChoice != 1 && userChoice != 2) {
			cout << "\033[031m Помилка! Будь ласка, введіть або 1, або 2.\033[0m\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	}

	cout << "\033[032mГенерація числа ...\033[0m" << endl;
	this_thread::sleep_for(chrono::seconds(2));
	randomNumber = 1 + rand() % 2;
	cout << "Рандомне число: " << randomNumber << endl;

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
	cout << "\033[032mВітаю! Ви ходите першим.\033[0m" << endl;
	int randFaceNum;
	for (int i = 0; i < numberOfDiceRolling; i++) {

		// Player's throw

		randFaceNum = 1 + rand() % 6;
		sumOfPoints_User += randFaceNum;

		cout << "Ваш кидок: " << endl;
		this_thread::sleep_for(chrono::seconds(2));
		printDieFace(randFaceNum);
		if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[32mВаша поточна сума становить: ";
		else if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[031mВаша поточна сума становить: ";
		else cout << "\033[033mВаша поточна сума становить: ";

		cout << sumOfPoints_User;
		cout << "\033[0m" << endl;

		// Computer's throw

		randFaceNum = 1 + rand() % 6;
		sumOfPoints_Computer += randFaceNum;

		cout << "Кидок комп'ютера: " << endl;
		this_thread::sleep_for(chrono::seconds(2));
		printDieFace(randFaceNum);
		if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[32mПоточна сума комп'ютера становить: ";
		else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[031mПоточна сума комп'ютера становить: ";
		else cout << "\033[033mПоточна сума комп'ютера становить: ";

		cout << sumOfPoints_Computer;
		cout << "\033[0m" << endl;
	}


	// Summing up
	cout << "\033[034mПідведення підсумків ... \033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(3));
	if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[32mВаша остаточна сума становить: ";
	else if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[031mВаша остаточна сума становить: ";
	else cout << "\033[033mВаша остаточна сума становить: ";
	this_thread::sleep_for(chrono::seconds(2));

	cout << sumOfPoints_User;
	cout << "\033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(3));
	if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[32mОстаточна сума комп'ютера становить: ";
	else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[031mОстаточна сума комп'ютера становить: ";
	else cout << "\033[033mОстаточна сума комп'ютера становить: ";

	this_thread::sleep_for(chrono::seconds(2));
	cout << sumOfPoints_Computer;
	cout << "\033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(2));

	cout << "\033[2J\033[1;1H";


	if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[31m На жаль, Ви програли(" << endl;
	else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[032mВітаю! Ви перемогли!" << endl;
	else cout << "\033[033mБойова нічия!" << endl;

	cout << "\033[0m" << endl;
}

void computerWon(int sumOfPoints_Computer = 0, int sumOfPoints_User = 0) {
	cout << "\033[031mНа жаль Ви не вгадали( Комп'ютер ходить першим першим.\033[0m" << endl;
	int randFaceNum;
	for (int i = 0; i < numberOfDiceRolling; i++) {

		// Computer's throw

		randFaceNum = 1 + rand() % 6;
		sumOfPoints_Computer += randFaceNum;

		cout << "Кидок комп'ютера: " << endl;
		this_thread::sleep_for(chrono::seconds(2));
		printDieFace(randFaceNum);
		if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[32mПоточна сума комп'ютера становить: ";
		else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[031mПоточна сума комп'ютера становить: ";
		else cout << "\033[033mПоточна сума комп'ютера становить: ";

		cout << sumOfPoints_Computer;
		cout << "\033[0m" << endl;

		// Player's throw

		randFaceNum = 1 + rand() % 6;
		sumOfPoints_User += randFaceNum;

		cout << "Ваш кидок: " << endl;
		this_thread::sleep_for(chrono::seconds(2));
		printDieFace(randFaceNum);
		if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[32mВаша поточна сума становить: ";
		else if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[031mВаша поточна сума становить: ";
		else cout << "\033[033mВаша поточна сума становить: ";

		cout << sumOfPoints_User;
		cout << "\033[0m" << endl;

	}

	// Summing up
	cout << "\033[034mПідведення підсумків ... \033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(3));
	if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[32mВаша остаточна сума становить: ";
	else if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[031mВаша остаточна сума становить: ";
	else cout << "\033[033mВаша остаточна сума становить: ";
	this_thread::sleep_for(chrono::seconds(2));

	cout << sumOfPoints_User;
	cout << "\033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(3));
	if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[32mОстаточна сума комп'ютера становить: ";
	else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[031mОстаточна сума комп'ютера становить: ";
	else cout << "\033[033mОстаточна сума комп'ютера становить: ";

	this_thread::sleep_for(chrono::seconds(2));
	cout << sumOfPoints_Computer;
	cout << "\033[0m" << endl;

	this_thread::sleep_for(chrono::seconds(2));

	cout << "\033[2J\033[1;1H";


	if (sumOfPoints_Computer > sumOfPoints_User) cout << "\033[31m На жаль, Ви програли(" << endl;
	else if (sumOfPoints_Computer < sumOfPoints_User) cout << "\033[032mВітаю! Ви перемогли!" << endl;
	else cout << "\033[033mБойова нічия!" << endl;

	cout << "\033[0m" << endl;
}

