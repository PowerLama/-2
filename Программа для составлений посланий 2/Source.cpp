#include <windows.h>
#include "Accounts.h"
#include "Wishes.h"

//using namespace std;

const int SALT_SIZE = 16;
const int SYMBOLS_SIZE = 62;

const string FILE_OF_DATA = "MyFile.txt"; //���� � ����� � �������
const int RESERVE_SIZE = 100; //������������ ���������� ��������� ������� � ������� 100
const string FILE_OF_ACCOUNTS = "MyAccounts.txt";//���� � ����� � ����������
const int RESERVE_SIZE_OF_ACCOUNTS = 8;//������������ ���������� ��������� ������� � ���������� 8



#pragma once

//#include "Structers.h"
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;
/*
class Account {
private:
	int id;//����� ��������
	string login;
	string name;
	string surname;
	string address;
	string salt;
	string hash;
	int role;//0-������������;1-�������������
	int verification;//1-�������;2-���������
public:

	int getId() {
		return this->id;
	}

	void setId(int id) {
		this->id = id;
	}

	string getLogin() {
		return this->login;
	}

	void setLogin(string login) {
		this->login = login;
	}

	string getName() {
		return this->name;
	}

	void setName(string name) {
		this->name = name;
	}

	string getSurname() {
		return this->surname;
	}

	void setSurname(string surname) {
		this->surname = surname;
	}

	string getAddress() {
		return this->address;
	}

	void setAddress(string address) {
		this->address = address;
	}
	string getSalt() {
		return this->salt;
	}

	void setSalt(string salt) {
		this->salt = salt;
	}

	string getHash() {
		return this->hash;
	}

	void setHash(string hash) {
		this->hash = hash;
	}

	int getRole() {
		return this->role;
	}

	void setRole(int role) {
		this->role = role;
	}

	int getAccess() {
		return this->verification;
	}

	void setAccess(int access) {
		this->verification = access;
	}

	Account() {
		id = 0;
		login = "0";
		name = "---";
		surname = "---";
		address = "---";
		salt = "0";
		hash = "0";
		role = 0;
		verification = 0;
	}
	~Account() {};
	
	friend Account* readFileOfAccounts(Account* arr_of_accounts, int& number_of_accounts); //���������� ���������� �� ����� � ����������

//-------------------------------------------------------------------------------//
	friend void saveAllAccountsInFile(Account* arr_of_accounts, int number_of_acounts);//���������� ���� ��������� ��������� � ����
	friend void writeEndFileAccounts(Account new_account);//���������� � ����� ����� ��������


//-------------------------------------------------------------------------------//



//-------------------------------------------------------------------------------//
	friend void WorkingWithAccounts(Account* arr_of_accounts, int& number_of_accounts, int n_id);//������� ������ � ����������(�������, ��������, ��������, �������� ������)
	friend void showAccountsForAdmin(Account* arr_of_accounts, int number_of_acounts);//����� ������ ���� ��������� 
	friend void showAccountsForUsers(Account* arr_of_accounts, int number_of_acounts);//����� ������ ���� ��������� 
	friend void addAccount(Account* arr_of_accounts, int& number_of_accounts);//���������� ��������
	friend void delAccount(Account* arr_of_accounts, int& number_of_accounts, int n_id);//�������� ���������� �������� 
	friend void updateAccount(Account* arr_of_accounts, int number_of_accounts, int n_id);//��������������(����������) ���������� ��������
//-------------------------------------------------------------------------------//



//-------------------------------------------------------------------------------//
	friend void inputLogin(Account* accounts_arr, int number_of_accounts, string& login);//���� ������
	friend void inputPassword(Account* accounts_arr, int& number_of_accounts, string& pass);//���� ������
	friend void inputName(Account* accounts_arr, int number_of_accounts);//���� �����
	friend void inputSurname(Account* accounts_arr, int number_of_accounts);//���� �������
	friend void inputAddress(Account* accounts_arr, int number_of_accounts);//���� ������
//-------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------//

	friend int isUniqLogin(Account* accounts_arr, int number_of_accounts, string login);//�������� �� ������������ ������
	friend void Entering(Account* accounts_arr, int& number_of_accounts, int& n_id);//�������, ������� ������������ ��� ������ ����������� ��� �����������
	//-------------------------------------------------------------------------------//

	//-------------------------------------------------------------------------------//
	friend void Registration(Account* accounts_arr, int& number_of_accounts);//������� ��� �����������
	friend int Autoresation(Account* accounts_arr, int& number_of_accounts);//������� ��� �����������
	//-------------------------------------------------------------------------------//
};
*/
string generateSalt(int salt_size);//��������� ����

string getSymbolsForSalt();//��������� �������� ��� ����

void checkPassword(string& password);//����� �������� '*' �� �������(������������ ��� ����� ������)

int getNumOfAccounts();
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int num_of_accounts = 0, num_of_wishes = 0;
	num_of_wishes = getNumOfWishes();
	num_of_accounts = getNumOfAccounts();
	Wishes* arr_of_wishes=new Wishes[num_of_wishes];
	Account* arr_of_accounts = new Account[num_of_accounts];
	
	int n_id, choice = 1, j = 0;
	while (true) {

		arr_of_accounts = readFileOfAccounts(arr_of_accounts, num_of_accounts);
		readFileOfWishes(arr_of_wishes, j);
		Entering(arr_of_accounts, num_of_accounts, n_id);//���� � �������
		system("cls");

		if (n_id == -1)return;//����� ��� ���� ������� Entering �������� ������ �� ��������� -1
		if (arr_of_accounts[n_id - 1].getRole() == 1) {//� ����������� �� ���� ����������� �������������� ����
			while (choice != 0) {
				cout << "����� ������:" << endl;
				cout << "1 - ������ � �������\n2 - ������ � ����������\n0 - �����\n";
				string mass = "�����:";
				choice = checkNumberAndDiapason(0, 2, mass);
				switch (choice) {
				case 1:system("cls"); adminModule(arr_of_wishes, j, arr_of_accounts, num_of_accounts, n_id); break;
				case 2:system("cls"); WorkingWithAccounts(arr_of_accounts, num_of_accounts, n_id); break;
				default:system("cls"); break;
				}
			}
		}
		else {
			cout << "\n����� ������������:" << endl;
			userModule(arr_of_wishes, j);
		}
	}
	delete[]arr_of_accounts;
}