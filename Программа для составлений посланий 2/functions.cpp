#include "functions.h"


void coutChar(char sym, int num) {
	int count = 0;
	if (num > 0) {
		do {
			cout << sym;
			count++;
		} while (count != num);
	}
}

//Проверяет соответствие передаваемому диапазону. 
int checkNumberAndDiapason(int a, int b, string mass) {
	int number;
	int choice = 0;
	do {
		while (true) {
			cout << mass;
			cin >> number;
			InputInt(number);
			if (number< a || number>b) {
				number = 0;//для возвращения на прошлое меню
				cout << "Некорректное значение." << endl;
				cout << "Повтрорить?\n1 - Да         0 - Нет\nВыбор:";
				cin >> choice;
				if (choice != 1)return 0;
			}
			else return number;
		}
	} while (choice);
}
void InputInt(int& x) {
	while (cin.get() != '\n')
	{
		cout << "Неверный ввод!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Введите заного:";
		cin >> x;
	}
};
void InputDouble(double& x) {
	while (cin.get() != '\n')
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Неверный ввод!\n";
		cout << "Введите заного:";
		cin >> x;
	}

};
//----------------------------------------------------------------------------//