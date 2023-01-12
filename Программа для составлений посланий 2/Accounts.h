#pragma once

//#include "Structers.h"
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;

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

string generateSalt(int salt_size);//получение соли

string getSymbolsForSalt();//генерация символов для соли

void checkPassword(string& password);//вывод символов '*' на консоль(используется при вводе пароля)

int getNumOfAccounts();
