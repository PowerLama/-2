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

//��������� ������������ ������������� ���������. 
int checkNumberAndDiapason(int a, int b, string mass) {
	int number;
	int choice = 0;
	do {
		while (true) {
			cout << mass;
			cin >> number;
			InputInt(number);
			if (number< a || number>b) {
				number = 0;//��� ����������� �� ������� ����
				cout << "������������ ��������." << endl;
				cout << "����������?\n1 - ��         0 - ���\n�����:";
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
		cout << "�������� ����!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "������� ������:";
		cin >> x;
	}
};
void InputDouble(double& x) {
	while (cin.get() != '\n')
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������� ����!\n";
		cout << "������� ������:";
		cin >> x;
	}

};
//----------------------------------------------------------------------------//