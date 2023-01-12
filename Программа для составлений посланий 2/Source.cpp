#include <windows.h>
#include "Accounts.h"
#include "Wishes.h"

//using namespace std;

const int SALT_SIZE = 16;
const int SYMBOLS_SIZE = 62;

const string FILE_OF_DATA = "MyFile.txt"; //Путь к файлу с данными
const int RESERVE_SIZE = 100; //Максимальное количество элементов массива с данными 100
const string FILE_OF_ACCOUNTS = "MyAccounts.txt";//Путь к файлу с аккаунтами
const int RESERVE_SIZE_OF_ACCOUNTS = 8;//Максимальное количество элементов массива с аккаунтами 8



#pragma once

//#include "Structers.h"
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;
/*
class Account {
private:
	int id;//номер аккаунта
	string login;
	string name;
	string surname;
	string address;
	string salt;
	string hash;
	int role;//0-Пользователь;1-Администратор
	int verification;//1-Допущен;2-Недопущен
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
	
	friend Account* readFileOfAccounts(Account* arr_of_accounts, int& number_of_accounts); //считывание информации из файла с аккаунтами

//-------------------------------------------------------------------------------//
	friend void saveAllAccountsInFile(Account* arr_of_accounts, int number_of_acounts);//сохранение всех имеющихся аккаунтов в файл
	friend void writeEndFileAccounts(Account new_account);//добавление в конец файла аккаунта


//-------------------------------------------------------------------------------//



//-------------------------------------------------------------------------------//
	friend void WorkingWithAccounts(Account* arr_of_accounts, int& number_of_accounts, int n_id);//функция работы с аккаунтами(удалить, добавить, обновить, изменить статус)
	friend void showAccountsForAdmin(Account* arr_of_accounts, int number_of_acounts);//вывод списка всех аккаунтов 
	friend void showAccountsForUsers(Account* arr_of_accounts, int number_of_acounts);//вывод списка всех аккаунтов 
	friend void addAccount(Account* arr_of_accounts, int& number_of_accounts);//добавление аккаунта
	friend void delAccount(Account* arr_of_accounts, int& number_of_accounts, int n_id);//удаление выбранного аккаунта 
	friend void updateAccount(Account* arr_of_accounts, int number_of_accounts, int n_id);//редактирование(обновление) выбранного аккаунта
//-------------------------------------------------------------------------------//



//-------------------------------------------------------------------------------//
	friend void inputLogin(Account* accounts_arr, int number_of_accounts, string& login);//ввод логина
	friend void inputPassword(Account* accounts_arr, int& number_of_accounts, string& pass);//ввод пароля
	friend void inputName(Account* accounts_arr, int number_of_accounts);//ввод имени
	friend void inputSurname(Account* accounts_arr, int number_of_accounts);//ввод фамилии
	friend void inputAddress(Account* accounts_arr, int number_of_accounts);//ввод адреса
//-------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------//

	friend int isUniqLogin(Account* accounts_arr, int number_of_accounts, string login);//проверка на уникальность логина
	friend void Entering(Account* accounts_arr, int& number_of_accounts, int& n_id);//функция, которая используется для выбора регистрации или авторизации
	//-------------------------------------------------------------------------------//

	//-------------------------------------------------------------------------------//
	friend void Registration(Account* accounts_arr, int& number_of_accounts);//функция для регистрации
	friend int Autoresation(Account* accounts_arr, int& number_of_accounts);//функция для авторизации
	//-------------------------------------------------------------------------------//
};
*/
string generateSalt(int salt_size);//получение соли

string getSymbolsForSalt();//генерация символов для соли

void checkPassword(string& password);//вывод символов '*' на консоль(используется при вводе пароля)

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
		Entering(arr_of_accounts, num_of_accounts, n_id);//вход в систему
		system("cls");

		if (n_id == -1)return;//выход при если функция Entering закончит работу со значением -1
		if (arr_of_accounts[n_id - 1].getRole() == 1) {//в зависимости от роли открывается соответсвующее меню
			while (choice != 0) {
				cout << "Режим админа:" << endl;
				cout << "1 - Работа с данными\n2 - Работа с аккаунтами\n0 - Выход\n";
				string mass = "Выбор:";
				choice = checkNumberAndDiapason(0, 2, mass);
				switch (choice) {
				case 1:system("cls"); adminModule(arr_of_wishes, j, arr_of_accounts, num_of_accounts, n_id); break;
				case 2:system("cls"); WorkingWithAccounts(arr_of_accounts, num_of_accounts, n_id); break;
				default:system("cls"); break;
				}
			}
		}
		else {
			cout << "\nРежим пользователя:" << endl;
			userModule(arr_of_wishes, j);
		}
	}
	delete[]arr_of_accounts;
}