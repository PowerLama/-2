#include "Accounts.h"
#include "sha256.h"
#include"functions.h"
#include <fstream>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <iomanip>

const int SALT_SIZE = 16;
const int SYMBOLS_SIZE = 62;


const string FILE_OF_ACCOUNTS = "MyAccounts.txt";//Путь к файлу с аккаунтами
const int RESERVE_SIZE_OF_ACCOUNTS = 8;//Максимальное количество элементов массива с аккаунтами 8



//---------------------------------------------------------------------------------------------------------------

void WorkingWithAccounts(Account* arr_of_accounts, int& number_of_accounts, int n_id) {
	while (true) {
		readFileOfAccounts(arr_of_accounts, number_of_accounts);
		cout << "Меню для работы с учётными записями пользователей" << endl;
		string mass = "1 - Показать все аккаунты\n2 - Добавить новый аккаунт\n3 - Удалить аккаунт\n4 - Отредактировать аккаунт\n0 - Выход\nВыбор:";
		int choice = checkNumberAndDiapason(0, 4, mass);
		switch (choice) {
		case 1: system("cls"); showAccountsForAdmin(arr_of_accounts, number_of_accounts); system("pause"); system("cls"); break;
		case 2: system("cls"); addAccount(arr_of_accounts, number_of_accounts); system("pause"); system("cls"); break;
		case 3: system("cls"); delAccount(arr_of_accounts, number_of_accounts, n_id); system("pause"); system("cls"); break;
		case 4: system("cls"); updateAccount(arr_of_accounts, number_of_accounts, n_id); system("pause"); system("cls"); break;
		case 0:default:system("cls"); return;
		}
	}
}

int getNumOfAccounts() {
	int n = 0;
	ifstream in(FILE_OF_ACCOUNTS);
	if (!in.is_open()) {
		Account arr_of_accounts[1];
		arr_of_accounts[0].setId(1);
		arr_of_accounts[0].setLogin("admin");
		arr_of_accounts[0].setName("Administrator");
		arr_of_accounts[0].setSurname("None");
		arr_of_accounts[0].setAddress("Server");
		arr_of_accounts[0].setSalt(generateSalt(16));
		arr_of_accounts[0].setHash(sha256(sha256("12345678" + arr_of_accounts[0].getSalt())));
		arr_of_accounts[0].setRole(1);
		arr_of_accounts[0].setAccess(1);

		saveAllAccountsInFile(arr_of_accounts, 1);
	}
	else {
		string line;
		while (getline(in, line)) {
			n++;
			if (n + 1 > RESERVE_SIZE_OF_ACCOUNTS) {
				cout << "Недостаточно памяти для чтения всех данных!" <<
					endl;
				return n;
			}
		}
	}
	return n;
}

Account* readFileOfAccounts(Account* arr_of_accounts, int& number_of_accounts)//считывает информацию из файла и считает количество строк
{
	/*delete[] arr_of_accounts;
	arr_of_accounts = new Account[number_of_accounts];*/
	ifstream fin(FILE_OF_ACCOUNTS, ios::in);//открыли файл для чтения
	number_of_accounts = 0;
	while (!fin.eof()) {
		int buf_id, buf_role, buf_access;
		string buf_login, buf_salt, buf_hash, buf_name, buf_surname, buf_address;
		fin >> buf_id
			>> buf_login
			>> buf_name
			>> buf_surname
			>> buf_address
			>> buf_salt
			>> buf_hash
			>> buf_role
			>> buf_access;
		arr_of_accounts[number_of_accounts].setId(buf_id);
		arr_of_accounts[number_of_accounts].setRole(buf_role);
		arr_of_accounts[number_of_accounts].setAccess(buf_access);
		arr_of_accounts[number_of_accounts].setLogin(buf_login);
		arr_of_accounts[number_of_accounts].setSalt(buf_salt);
		arr_of_accounts[number_of_accounts].setHash(buf_hash);
		arr_of_accounts[number_of_accounts].setName(buf_name);
		arr_of_accounts[number_of_accounts].setSurname(buf_surname);
		arr_of_accounts[number_of_accounts].setAddress(buf_address);
		number_of_accounts++;
		if (number_of_accounts == RESERVE_SIZE_OF_ACCOUNTS) {//проверка на количество аккаунтов
			cout << "Недостаточно памяти для чтения всех данных!"
				<< endl;
			return arr_of_accounts;
		}
	}

	fin.close();// закрыли открытый файл
	return arr_of_accounts;
}


void saveAllAccountsInFile(Account* arr_of_accounts, int number_of_acounts) {

	ofstream fout(FILE_OF_ACCOUNTS, ios_base::out | ios_base::trunc);

	if (!fout.is_open()) // если файл небыл открыт
		cout << "Указанный файл не существует!\n";
	for (int i = 0; i < number_of_acounts; i++) {
		fout << i + 1 <<
			" " << arr_of_accounts[i].getLogin() <<
			" " << arr_of_accounts[i].getName() <<
			" " << arr_of_accounts[i].getSurname() <<
			" " << arr_of_accounts[i].getAddress() <<
			" " << arr_of_accounts[i].getSalt() <<
			" " << arr_of_accounts[i].getHash() <<
			" " << arr_of_accounts[i].getRole() <<
			" " << arr_of_accounts[i].getAccess();
		if (i != number_of_acounts - 1)fout << endl;
	}
	fout.close(); // программа больше не использует файл, поэтому его нужно закрыть
	cout << "Данные успешно записаны в файл: " << FILE_OF_ACCOUNTS << "\n";
}

void writeEndFileAccounts(Account new_account)
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::app);//открыли файл для дозаписи
	fout << endl;
	fout << new_account.getId() <<
		" " << new_account.getLogin() <<
		" " << new_account.getName() <<
		" " << new_account.getSurname() <<
		" " << new_account.getAddress() <<
		" " << new_account.getSalt() <<
		" " << new_account.getHash() <<
		" " << new_account.getRole() <<
		" " << new_account.getAccess();
	fout.close();

}
void showAccountsForAdmin(Account* arr_of_accounts, int number_of_acounts) {
	cout << "Список учётных записей пользователей: " << endl;
	for (int i = 0; i < number_of_acounts; i++)
		cout << "----------" << i + 1 << "----------" <<
		"\nLogin:" << arr_of_accounts[i].getLogin() <<
		"\nName:" << arr_of_accounts[i].getName() <<
		"\nSurname:" << arr_of_accounts[i].getSurname() <<
		"\nAddress:" << arr_of_accounts[i].getAddress() <<
		"\nAccess:" << arr_of_accounts[i].getAccess() <<
		"\nRole:" << arr_of_accounts[i].getRole() <<
		"\n---------------------" << endl;
}
void showAccountsForUsers(Account* arr_of_accounts, int number_of_acounts) {
	cout << "Список учётных записей пользователей: " << endl;
	for (int i = 0; i < number_of_acounts; i++)
		cout << "-------Id:" << i + 1 << "----------" <<
		"\nName:" << arr_of_accounts[i].getName() <<
		"\nSurname:" << arr_of_accounts[i].getSurname() <<
		"\nAddress:" << arr_of_accounts[i].getAddress() <<
		"\n---------------------" << endl;
}
void addAccount(Account* arr_of_accounts, int& number_of_accounts) {
	string mass = "Вы уверенны?\n1 - Да\n0 - Нет\nВыбор:";
	int choice = checkNumberAndDiapason(0, 1, mass);
	if (choice == 1)
		Registration(arr_of_accounts, number_of_accounts);
}

void delAccount(Account* arr_of_accounts, int& number_of_accounts, int n_id) {
	showAccountsForAdmin(arr_of_accounts, number_of_accounts);
	string mass = "При вводе 0, Вы, вернетесь назад.\nВведите номер удаляемой записи: ";
	int del_item = checkNumberAndDiapason(0, number_of_accounts, mass);
	if (del_item == 0) return;
	mass = "Вы уверенны?\n1 - Да\n0 - Нет\nВыбор:";
	int choice = checkNumberAndDiapason(0, 1, mass);
	if (choice == 1) {
		if (del_item == n_id) cout << "Вы не можете удалить собственный аккаунт!" << endl;
		else {
			for (int i = del_item - 1; i < number_of_accounts; i++)
				arr_of_accounts[i] = arr_of_accounts[i + 1];
			number_of_accounts--;
			cout << "Запись удалена!" << endl;
			cout << endl;
		}
		saveAllAccountsInFile(arr_of_accounts, number_of_accounts);
	}
}


void updateAccount(Account* arr_of_accounts, int number_of_accounts, int n_id) {
	showAccountsForAdmin(arr_of_accounts, number_of_accounts);
	cout << "Введите номер редактируемой записи: ";
	int upd_item;
	Account buf_account[1];
	string buf_password, buf_string;
	cin >> upd_item;
	cout << "Какой параметр следует изменить?" << endl;
	cout << "1 - Login\n2 - Password\n3 - Role\n4 - Access\n0 - Выход" << endl;
	int choice = checkNumberAndDiapason(0, 4, "Выбор:");
	switch (choice) {
	case 1: system("cls");
		cout << "Вы уверенны?\n1 - Да\n0 - Нет" << endl;
		choice = checkNumberAndDiapason(0, 1, "Выбор:");
		if (choice == 0) break;
		inputLogin(arr_of_accounts, number_of_accounts, buf_string);
		buf_account[0].setLogin(buf_string);
		arr_of_accounts[upd_item - 1].setLogin(buf_account[0].getLogin());
		saveAllAccountsInFile(arr_of_accounts, number_of_accounts);//сохраняем результат в файл
		break;
	case 2: system("cls");
		cout << "Вы уверенны?\n1 - Да\n0 - Нет" << endl;
		choice = checkNumberAndDiapason(0, 1, "Выбор:");
		if (choice == 0) break;
		inputPassword(buf_account, choice, buf_password);
		arr_of_accounts[upd_item - 1].setHash(buf_account[0].getHash());
		arr_of_accounts[upd_item - 1].setSalt(buf_account[0].getSalt());
		saveAllAccountsInFile(arr_of_accounts, number_of_accounts);//сохраняем результат в файл
		break;
	case 3: system("cls");
		if (upd_item == n_id) {//проверка на возможность редактирования теккущего аккаунта
			cout << "Вы не можете изменить Role вашего аккаунта!" << endl;
			break;
		}
		else {
			cout << "0 - Пользователь\n1 - Администратор\n2 - Выход" << endl;
			choice = checkNumberAndDiapason(0, 2, "Выбор:");
			if (choice == 2)break;
			arr_of_accounts[upd_item - 1].setRole(choice);
			saveAllAccountsInFile(arr_of_accounts, number_of_accounts);//сохраняем результат в файл
			break;
		}
	case 4: system("cls");
		if (arr_of_accounts[upd_item - 1].getAccess() == 0) {
			arr_of_accounts[upd_item - 1].setAccess(1);
			cout << "Доступ разрешен." << endl;
		}
		else {
			arr_of_accounts[upd_item - 1].setAccess(0);
			cout << "В доступе отказано." << endl;
		}
		saveAllAccountsInFile(arr_of_accounts, number_of_accounts);
		break;
	case 0:default:system("cls"); return;
	}

}

//---------------------------------------------------------------------------------------------------------------




//---------------------------------------------------------------------------------------------------------------
void inputLogin(Account* accounts_arr, int number_of_accounts, string& login) {
	system("cls");
	int number_of_letters;
	bool uniq_login; // 0 - non uniq 1 - uniq
	cout << "Login:\n";
	cin >> login;
	number_of_letters = login.length();

	uniq_login = isUniqLogin(accounts_arr, number_of_accounts, login);

	while (number_of_letters < 4 or uniq_login == 0) {
		if (number_of_letters < 4 and uniq_login == 0) { // if 2 variants
			cout << endl << "Логин должен содержать более 3-х символов!\nLogin\n";
			cin >> login;
			number_of_letters = login.length();
			uniq_login = isUniqLogin(accounts_arr, number_of_accounts, login);
		}
		if (number_of_letters < 4) { // if login < 4 letters
			cout << "Логин не может быть кароче 4-х символов!\nLogin\n";
			cin >> login;
			number_of_letters = login.length();
			uniq_login = isUniqLogin(accounts_arr, number_of_accounts, login);
		}
		if (uniq_login == 0) { // non-uniq
			cout << "Такой логин уже существует!\nLogin:\n";
			cin >> login;
			number_of_letters = login.length();
			uniq_login = isUniqLogin(accounts_arr, number_of_accounts, login);
		}
		if (number_of_letters > 3 and uniq_login == 1) // exit
			break;
	}
}
void inputName(Account* accounts_arr, int number_of_accounts) {
	string name;
	cout << "Введите имя:\n";
	cin >> name;
	accounts_arr[number_of_accounts - 1].setName(name);

}
void inputSurname(Account* accounts_arr, int number_of_accounts) {
	string surname;
	cout << "Введите фамилию:\n";
	cin >> surname;
	accounts_arr[number_of_accounts - 1].setSurname(surname);
}

void inputAddress(Account* accounts_arr, int number_of_accounts) {
	string address;
	int choice = 0;
	do {
		address = "";
		cout << "Введите адресс:\n";
		cin >> address;
		getline(cin, address);
		address.append(address);
		if (address == "")address = "---";//если пользователь нажал enter сразу, то строка заменяется на "---"
		else {
			int n = address.length();

			for (int i = 0; i < address.length(); i++)//заменяем пробелы на '_', чтобы не было разрывов в строке 
				if (address[i] == ' ') address[i] = '_';

			for (int i = n - 1; i > 0; i--) { //убираем '_' с конца строки, если таковые имеются			
				if (address[i] == '_')
					address.pop_back();
				else break;
			}
			if (address == "_")//если строка выглядит как "_", то заменяем её на "---"
				address = "---";

			n = address.length();
			if (n > 50) {
				address.clear();
				cout << "Вы достигли лимита. Было введенно больше 50 символов." << endl;
				cout << "Повтрорить?\n1 - да         0 - нет\n";
				cin >> choice;
			}
		}
	} while (choice);
	accounts_arr[number_of_accounts - 1].setSurname(address);
}


void inputPassword(Account* accounts_arr, int& number_of_accounts, string& pass) {
	string pass2;
	int choice;
	int number_of_letters;
	while (true) {
		cout << "Password:\n";
		checkPassword(pass);
		cout << "\nRepeat Password:\n";
		checkPassword(pass2);
		if (pass != pass2) {
			cout << "\nПароли не совпадают!" << endl;
			cout << "Повторить?\n1 - Да\n0 - Нет\n";
			choice = checkNumberAndDiapason(0, 1, "Выбор:");
			if (choice != 1) {
				number_of_accounts--;
				return;
			}
		}
		if (pass.size() < 8) {
			cout << "\nВведите более надежный пароль!" << endl;
			cout << "Повторить?\n1 - Да\n0 - Нет\n";
			choice = checkNumberAndDiapason(0, 1, "Выбор:");
			if (choice != 1) {
				number_of_accounts--;
				return;
			}
		}
		else break;
	}
	accounts_arr[number_of_accounts - 1].setSalt(generateSalt(SALT_SIZE));
	accounts_arr[number_of_accounts - 1].setHash(sha256(sha256(pass + accounts_arr[number_of_accounts - 1].getSalt())));
	system("cls");
	return;
}
void checkPassword(string& password) {
	int ch = 0;
	while ((ch = _getch()) != '\r') {
		if ((int)ch == 8) { // Установка Backspace на удаление символов.
			cout << (char)8 << ' ' << char(8);
			if (!password.empty())
				//Если строка pass не являеться пустой, то из неё можно удалять  последний символ 
				password.erase(password.length() - 1);
			// позволяет удалить последний символ из строки pass
		}
		else {
			cout << '*';            // Замена символов на *
			password += (char)ch;       // Преврашение кода из целого числа в символ.
		}
	}
}
//---------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------
string generateSalt(int salt_size) {
	string sym = getSymbolsForSalt();
	srand(time(NULL));
	string salt;
	salt.reserve(salt_size);
	for (int i = 0; i < salt_size; i++)
		salt.push_back(sym[rand() % SYMBOLS_SIZE]);
	return salt;
}
string getSymbolsForSalt() {
	string str;
	str.reserve(SYMBOLS_SIZE);

	char little_letter = 'a';
	char big_letter = 'A';
	char number = '0';
	int i = 0;
	for (int k = 0; k < 26; k++) {
		str.push_back(little_letter++);
		str.push_back(big_letter++);
		if (k < 10) str.push_back(number++);
	}
	return str;
}
//---------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------
int isUniqLogin(Account* accounts_arr, int number_of_accounts, string login) {
	for (int i = 0; i < number_of_accounts - 1; i++)
		if (accounts_arr[i].getLogin() == login)
			return 0;
}
//---------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------
void Entering(Account* accounts_arr, int& number_of_accounts, int& n_id) {
	string login;
	string password;
	int choose;
	while (true) {
		cout << "---------------- " << endl;
		cout << "1 - Вход" << endl;
		cout << "2 - Регистрация" << endl;
		cout << "0 - Выход" << endl;
		choose = checkNumberAndDiapason(0, 2, "Выбор:");
		switch (choose) {
		case 1: n_id = Autoresation(accounts_arr, number_of_accounts);
			return;
		case 2: Registration(accounts_arr, number_of_accounts);
			break;
		case 0:n_id = -1; return;
		}
	}

}
void Registration(Account* accounts_arr, int& number_of_accounts) {
	string login, pass;
	number_of_accounts++;
	if (number_of_accounts == RESERVE_SIZE_OF_ACCOUNTS) {
		cout << "Достигнуто максимальное количество аккаунтов!" << endl;
		number_of_accounts--;
	}
	else {

		Account* buf_accounts_arr = new Account[number_of_accounts];
		for (int i = 0; i < number_of_accounts - 1; i++)
			buf_accounts_arr[i] = accounts_arr[i];
		delete[]accounts_arr;
		Account* accounts_arr = new Account[number_of_accounts];
		for (int i = 0; i < number_of_accounts - 1; i++)
			accounts_arr[i] = buf_accounts_arr[i];
		delete[]buf_accounts_arr;

		accounts_arr[number_of_accounts - 1].setId(number_of_accounts);
		inputLogin(accounts_arr, number_of_accounts, login);
		inputPassword(accounts_arr, number_of_accounts, pass);//сохраняет хеш и соль
		accounts_arr[number_of_accounts - 1].setLogin(login);
		accounts_arr[number_of_accounts - 1].setName("---");
		accounts_arr[number_of_accounts - 1].setSurname("---");
		accounts_arr[number_of_accounts - 1].setAddress("---");
		accounts_arr[number_of_accounts - 1].setRole(0);
		accounts_arr[number_of_accounts - 1].setAccess(0);
		saveAllAccountsInFile(accounts_arr, number_of_accounts);
	}

}
int Autoresation(Account* accounts_arr, int& number_of_accounts) {
	accounts_arr = readFileOfAccounts(accounts_arr, number_of_accounts);
	string login;
	string password;
	int n_id;
	int number = 0;
	system("cls");
	cout << "Вход: " << endl;
	cout << "Login:\n";
	cin >> login;
	cout << "Password:\n";
	checkPassword(password);
	while (true) {
		for (int i = 0; i < number_of_accounts; i++) {
			if (login == accounts_arr[i].getLogin()) { // if login is correct
				string input_hash = accounts_arr[i].getHash();
				string input_salt = accounts_arr[i].getSalt();
				string hash = sha256(sha256(password + input_salt));
				if (input_hash == hash) {
					if (accounts_arr[i].getAccess() == 0) { // if access - blocked
						system("cls");
						number = 0;
						cout << "Вход: " << endl;
						cout << "В доступе отказано!\nВозможно ваш аккаунт не подтвердили, пожалуйста подождите." << endl;
						string mass = "Повторить?\n1 - Да\n0 - Нет\nВыбор:";
						int choice = checkNumberAndDiapason(0, 1, mass);
						if (choice == 1) return Autoresation(accounts_arr, number_of_accounts);
						else return -1;
						//continue;
					}
					if (accounts_arr[i].getAccess() == 1) { // if access - allowed
						number = 0;
						return n_id = accounts_arr[i].getId();//возвращаем номер аккаунта
					}
					i = 0;
				}
				else {
					number++;
					if (number == number_of_accounts) {
						i = 0;
						number = 0;
						system("cls");
						cout << "Вход: ";
						cout << "Неправильно введены логин или пароль!" << endl;
						string mass = "Повторить?\n1 - Да\n0 - Нет\nВыбор:";
						int choice = checkNumberAndDiapason(0, 1, mass);
						if (choice == 1) return Autoresation(accounts_arr, number_of_accounts);
						else return -1;
					}
				}
			}
			else {
				number++;
				if (number == number_of_accounts) {
					i = 0;
					number = 0;
					system("cls");
					cout << "Вход: " << endl;
					cout << "Неправильно введены логин или пароль!" << endl;
					string mass = "Повторить?\n1 - Да\n0 - Нет\nВыбор:";
					int choice = checkNumberAndDiapason(0, 1, mass);
					if (choice == 1) return Autoresation(accounts_arr, number_of_accounts);
					else return -1;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------------