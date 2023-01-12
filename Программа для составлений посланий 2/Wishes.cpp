
#include "Accounts.h"
#include"Wishes.h"
using namespace std;
const string FILE_OF_DATA = "MyFile.txt"; //Путь к файлу с данными
const int RESERVE_SIZE = 100; //Максимальное количество элементов массива с данными 100

/*
class Wishes {
private:
	int id_of_wish;//номер игрушки
	int sent_by;//отправитель
	int send_to;//кому отправить
	string theme;//тема сообщения
	string text;//текст сообщения
public:
	Wishes() {
		id_of_wish = 0;
		sent_by = 0;
		send_to = 0;
		theme = "---";
		text = "---";
	}
	Wishes(int id, int sent_by, int send_to, string theme, string text) {
		setIdOfWish(id);
		setSentBy(sent_by);
		setSendTo(send_to);
		setTheme(theme);
		setText(text);
	}
	void setIdOfWish(int id) {
		this->id_of_wish = id;
	}
	int getIdOfWish() {
		return this->id_of_wish;
	}
	void setSentBy(int id) {
		this->sent_by = id;
	}
	int getSentBy() {
		return this->sent_by;
	}
	void setSendTo(int id) {
		this->send_to = id;
	}
	int getSendTo() {
		return this->send_to;
	}
	void setTheme(string theme) {
		this->theme = theme;
	}
	string getTheme() {
		return this->theme;
	}
	void setText(string text) {
		this->text = text;
	}
	string getText() {
		return this->text;
	}
};
*/

//----------------------------------------------------------------------------//
void userModule(Wishes* arr_of_wishes, int num_of_wishes) {
	backStrNumFromFile(num_of_wishes);
	if (num_of_wishes == -1) return;//выходим при неудаче
	bool choice = true;
	while (choice) {
		readFileOfWishes(arr_of_wishes, num_of_wishes);
		string mass = "1 - Показать весь список\n2 - Показать элемент в развернутом виде\n3 - Отфильтровать по возрасту\n4 - Поиск по названию\n5 - Отсортировать по возрасту\n6 - Отсортировать по цене\n0 - Выход\nВыбор:";
		int choice = checkNumberAndDiapason(0, 6, mass);
		switch (choice) {
		case 1: system("cls"); showAllWishes(arr_of_wishes, num_of_wishes); system("pause"); system("cls"); break;
		case 2: system("cls"); searchOneElement(arr_of_wishes, num_of_wishes); system("cls"); break;
		case 3: system("cls");  system("pause"); system("cls"); break;
		case 4: system("cls"); searchByTheme(arr_of_wishes, num_of_wishes); system("pause"); system("cls"); break;
		case 5: system("cls"); system("pause"); system("cls"); break;
		case 6: system("cls"); system("pause"); system("cls"); break;
		case 0:default:system("cls"); return;
		}
	}
}

void adminModule(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account) {
	//backStrNumFromFile(num_of_wishes);
	num_of_wishes = getNumOfWishes();
	if (num_of_wishes == -1) return;//выходим при неудаче
	bool choice = true;
	while (choice) {
		readFileOfWishes(arr_of_wishes, num_of_wishes);
		string mass = "1 - Режим редактирования сообщений\n2 - Режим обработки\n0 - Выход\nВыбор:";
		int choice = checkNumberAndDiapason(0, 2, mass);
		switch (choice) {
		case 1: system("cls"); InfEditMode(arr_of_wishes, num_of_wishes, arr_of_accounts, num_of_accounts, id_of_this_account);  system("cls"); break;
		case 2: system("cls"); ProcessingMode(arr_of_wishes, num_of_wishes); system("cls"); break;
		case 0:default:system("cls"); return;
		}
	}
}

void InfEditMode(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account) {
	while (true) {
		readFileOfWishes(arr_of_wishes, num_of_wishes);
		string mass = "1 - Показать весь список сообщений\n2 - Показать все темы сообщений\n3 - Добавить новую тему\n4 - Поменять тему сообщения\n5 - Удалить выбранную тему\n6 - Удалить выбранное сообщение\n0 - Выход\nВыбор:";
		int choice = checkNumberAndDiapason(0, 5, mass);
		switch (choice) {
		case 1: system("cls"); showAllWishes(arr_of_wishes, num_of_wishes); system("pause"); system("cls"); break;
		case 2: system("cls"); searchOneElement(arr_of_wishes, num_of_wishes); system("cls"); break;
		case 3: system("cls"); addWishInArray(arr_of_wishes, num_of_wishes, arr_of_accounts, num_of_accounts, id_of_this_account); system("cls"); break;
		case 4: system("cls"); changeParametr(arr_of_wishes, num_of_wishes); break;
		case 5: system("cls"); deleteWish(arr_of_wishes, num_of_wishes); system("cls"); break;
			//case 6: system("cls");
		case 0:default:system("cls"); return;
		}
	}
}

void ProcessingMode(Wishes* arr_of_toyes, int number_of_toyes) {
	while (true) {
		readFileOfWishes(arr_of_toyes, number_of_toyes);
		string mass = "1 - Отфильтровать по теме\n2 - Поиск по названию\n3 - Отсортировать по возрасту\n4 - Отсортировать по цене\n0 - Выход\nВыбор:";
		int choice = checkNumberAndDiapason(0, 5, mass);
		switch (choice) {
		case 1: system("cls");/* filtrByPG(arr_of_toyes, number_of_toyes);*/ system("pause"); system("cls"); break;
		case 2: system("cls"); searchByTheme(arr_of_toyes, number_of_toyes); system("pause"); system("cls"); break;
		case 3: system("cls"); /*sortByPG(arr_of_toyes, number_of_toyes);*/ system("pause"); system("cls"); break;
		case 4: system("cls"); /*sortByCost(arr_of_toyes, number_of_toyes);*/ system("pause"); system("cls"); break;
		case 0:default:system("cls"); return;
		}
	}
}



void searchByTheme(Wishes* arr_of_toyes, int number_of_toyes) {
	cout << "Поиск:" << endl;
	string new_theme;
	inputTheme(new_theme);
	int status = 0;
	for (int i = 0; i < number_of_toyes; i++)
		if (arr_of_toyes[i].getTheme() == new_theme) {
			if (status == 0) {
				coutChar('=', 72);
				cout << endl;
				cout << "| № |Тема сообщения"; coutChar(' ', 2); //5+18
				cout << "|Текст сообщения"; coutChar(' ', 24);//1+39
				cout << "|By |To |" << endl;//9
				coutChar('=', 72);
				cout << endl;
			}
			status = 1;
			showOneElement(arr_of_toyes, number_of_toyes, i + 1);
		}
	if (status == 0) cout << "Совпадений не найдено." << endl;
}

//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
//замена выбранного параметра в массиве

void changeParametr(Wishes* arr_of_toyes, int number_of_toyes) {
	int user_id;
	int choice;
	while (true) {
		showAllWishes(arr_of_toyes, number_of_toyes);
		string mass = "При вводе 0, Вы, вернетесь назад.\nНомер записи, которую надо изменить:";
		user_id = checkNumberAndDiapason(0, number_of_toyes, mass);
		if (user_id == 0) {
			system("cls");
			return;
		}

		mass = "Какой параметр изменить?\n1 - Название\n2 - Цена\n3 - Производитель\n4 - Количество\n5 - PG\n0 - Назад\nВыбор:";
		choice = checkNumberAndDiapason(0, 5, mass);

		switch (choice) {
		case 1: changeText(arr_of_toyes, number_of_toyes, user_id); system("cls"); break;
		case 2: /*changeCost(arr_of_toyes, number_of_toyes, user_id);*/ system("cls"); break;
		case 3: changeTheme(arr_of_toyes, number_of_toyes, user_id); system("cls"); break;
		case 4: /*changeNum(arr_of_toyes, number_of_toyes, user_id);*/ system("cls"); break;
		case 5: /*changePG(arr_of_toyes, number_of_toyes, user_id);*/ system("cls"); break;
		case 0: defult: system("cls"); return;
		}
	}
}

//--------------------------------------------
//вспомогательные функции
void changeText(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	string new_name;
	cout << "Ввод нового тукста для сообщения под номером " << id_of_toy << ":\n";
	inputText(new_name);
	bool choice;
	cout << "Вы уверены?\n1 - Нет    0 - Да\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].setText(new_name);
		cout << "Готово." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}
}
/*void changeCost(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	string new_cost;
	cout << "Ввод новой цены для номера " << id_of_toy << ":\n";
	inputCost(new_cost);
	bool choice;
	cout << "Вы уверены?\n1 - Нет    0 - Да\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].cost = new_cost;
		cout << "Готово." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}

}*/
void changeTheme(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	string new_theme;
	cout << "Ввод новой темы для номера " << id_of_toy << ":\n";
	inputTheme(new_theme);
	bool choice;
	cout << "Вы уверены?\n1 - Нет    0 - Да\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].setTheme(new_theme);
		cout << "Готово." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}
}
/*void changeNum(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	int new_num;
	cout << "Ввод нового количества для номера " << id_of_toy << ":\n";
	inputNum(new_num);
	bool choice;
	cout << "Вы уверены?\n1 - Нет    0 - Да\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].num = new_num;
		cout << "Готово." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}
}
void changePG(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	int new_pg;
	cout << "Ввод нового PG для номера " << id_of_toy << ":\n";
	inputPG(new_pg);
	bool choice;
	cout << "Вы уверены?\n1 - Нет    0 - Да\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].pg = new_pg;
		cout << "Готово." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}
}
*/
//--------------------------------------------
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
//вспомогательные функции для функции showToyArray

int returnNumIdOfWish(Wishes* arr_of_wishes, int number_of_wishes) {
	int n_id = 0;
	if (arr_of_wishes[number_of_wishes].getIdOfWish() > 0 && arr_of_wishes[number_of_wishes].getIdOfWish() < 10)
		n_id = 2;//максимальное число символов 3
	if (arr_of_wishes[number_of_wishes].getIdOfWish() >= 10 && arr_of_wishes[number_of_wishes].getIdOfWish() < 100)
		n_id = 1;
	if (arr_of_wishes[number_of_wishes].getIdOfWish() >= 100)
		n_id = 0;
	return n_id;
}

int returnNumSymOfWish(Wishes* arr_of_wishes, int number_of_wishes, int max) {
	int n_name;
	string buf_string;
	buf_string = arr_of_wishes[number_of_wishes].getText();
	n_name = buf_string.length();
	if (n_name > max) n_name = -1;//если символов больше максимально допустимого, то заменяем на -1
	else n_name = max - n_name;
	return n_name;
}

int returnNumSymOfTheme(Wishes* arr_of_wishes, int number_of_wishes, int max) {
	int n_name;
	string buf_string;
	buf_string = arr_of_wishes[number_of_wishes].getTheme();
	n_name = buf_string.length();
	if (n_name > max) n_name = -1;//если символов больше максимально допустимого, то заменяем на -1
	else n_name = max - n_name;
	return n_name;
}

int returnNumIdBySender(Wishes* arr_of_wishes, int number_of_wishes) {
	int n_id = 0;
	if (arr_of_wishes[number_of_wishes].getSentBy() > 0 && arr_of_wishes[number_of_wishes].getSentBy() < 10)
		n_id = 2;//максимальное число символов 3
	if (arr_of_wishes[number_of_wishes].getSentBy() >= 10 && arr_of_wishes[number_of_wishes].getSentBy() < 100)
		n_id = 1;
	if (arr_of_wishes[number_of_wishes].getSentBy() >= 100)
		n_id = 0;
	return n_id;
}

int returnNumIdByRecepient(Wishes* arr_of_wishes, int number_of_wishes) {
	int n_id = 0;
	if (arr_of_wishes[number_of_wishes].getSendTo() > 0 && arr_of_wishes[number_of_wishes].getSendTo() < 10)
		n_id = 2;//максимальное число символов 3
	if (arr_of_wishes[number_of_wishes].getSendTo() >= 10 && arr_of_wishes[number_of_wishes].getSendTo() < 100)
		n_id = 1;
	if (arr_of_wishes[number_of_wishes].getSendTo() >= 100)
		n_id = 0;
	return n_id;
}

//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
//Работа с файлами

void showAllWishes(Wishes* arr_of_wishes, int number_of_wishes) {
	system("cls");
	coutChar('=', 120);
	cout << endl;
	cout << "| № |Тема сообщения"; coutChar(' ', 2); //5+18
	cout << "|Текст сообщения"; coutChar(' ', 24);//1+39
	cout << "|By |To |" << endl;//9
	coutChar('=', 72+48);
	cout << endl;
	for (int i = 0; i < number_of_wishes; i++) {

		int n_id_of_wish = returnNumIdOfWish(arr_of_wishes, i);
		int n_theme = returnNumSymOfTheme(arr_of_wishes, i, 18);
		int n_wish = returnNumSymOfWish(arr_of_wishes, i, 39);
		int n_sender = returnNumIdBySender(arr_of_wishes, i);
		int n_recipient = returnNumIdByRecepient(arr_of_wishes, i);

		string buf_string;

		cout << "|";//выводим id строки в центре соответствующего столбца   
		if (n_id_of_wish == 0)
			cout << " " << arr_of_wishes[i].getIdOfWish() << " ";
		if (n_id_of_wish == 1)
			cout << " " << arr_of_wishes[i].getIdOfWish();
		if (n_id_of_wish == 2) cout << arr_of_wishes[i].getIdOfWish();


		else { cout << "|" << buf_string; coutChar(' ', n_wish); }
		if (n_theme < 0) {//выводим 15 символов, так как в конце надо вывести еще дополнительно "...", что отнимет 3 от максимального
			buf_string = arr_of_wishes[i].getTheme();
			cout << "|";
			for (int j = 0; j < 25; j++)
				putchar(buf_string[j]);
			cout << "...";
		}
		else { cout << "|" << buf_string; coutChar(' ', n_theme); }
		if (n_wish < 0) {//выводим 36 символов, так как в конце надо вывести еще дополнительно "...", что отнимет 3 от максимального
			buf_string = arr_of_wishes[i].getText();
			cout << "|";
			for (int j = 0; j < 66; j++)
				putchar(buf_string[j]);
			cout << "...";
		}
		cout << "|";//выводим id строки в центре соответствующего столбца   
		if (n_sender == 0)
			cout << " " << arr_of_wishes[i].getSentBy() << " ";
		if (n_sender == 1)
			cout << " " << arr_of_wishes[i].getSentBy();
		if (n_sender == 2) cout << arr_of_wishes[i].getSentBy();
		cout << "|";//выводим id строки в центре соответствующего столбца   
		if (n_recipient == 0)
			cout << " " << arr_of_wishes[i].getSendTo() << " ";
		if (n_recipient == 1)
			cout << " " << arr_of_wishes[i].getSendTo();
		if (n_recipient == 2) cout << arr_of_wishes[i].getSendTo();
		cout << endl;
		coutChar('=', 72);
		cout << endl;
	}
}
void searchOneElement(Wishes* arr_of_toyes, int number_of_toyes) {
	showAllWishes(arr_of_toyes, number_of_toyes);
	string mass = "При вводе 0, Вы, вернетесь назад.\nНомер записи, которую надо вывести:";
	int user_id = checkNumberAndDiapason(0, number_of_toyes, mass);
	if (user_id == 0) {
		system("cls");
		return;
	}
	coutChar('=', 72);
	cout << endl;
	cout << "| № |Тема сообщения"; coutChar(' ', 2); //5+18
	cout << "|Текст сообщения"; coutChar(' ', 24);//1+39
	cout << "|By |To |" << endl;//9
	coutChar('=', 72);
	cout << endl;
	showOneElement(arr_of_toyes, number_of_toyes, user_id);
	system("pause");
}
void showOneElement(Wishes* arr_of_wishes, int number_of_wishes, int user_id) {
	int n_id_of_wish = returnNumIdOfWish(arr_of_wishes, number_of_wishes);
	int n_theme = returnNumSymOfTheme(arr_of_wishes, number_of_wishes, 18);
	int n_wish = returnNumSymOfWish(arr_of_wishes, number_of_wishes, 39);
	int n_sender = returnNumIdBySender(arr_of_wishes, number_of_wishes);
	int n_recipient = returnNumIdByRecepient(arr_of_wishes, number_of_wishes);

	string buf_string;

	cout << "|";//выводим id строки в центре соответствующего столбца   
	if (n_id_of_wish == 2)
		cout << " " << arr_of_wishes[number_of_wishes].getIdOfWish() << " ";
	if (n_id_of_wish == 1)
		cout << " " << arr_of_wishes[number_of_wishes].getIdOfWish();
	if (n_id_of_wish == 0) cout << arr_of_wishes[number_of_wishes].getIdOfWish();
	else { cout << "|" << buf_string; coutChar(' ', n_wish); }
	if (n_theme < 0) {//выводим 15 символов, так как в конце надо вывести еще дополнительно "...", что отнимет 3 от максимального
		buf_string = arr_of_wishes[number_of_wishes].getTheme();
		cout << "|";
		for (int j = 0; j < 15; j++)
			putchar(buf_string[j]);
		cout << "...";
	}
	else { cout << "|" << buf_string; coutChar(' ', n_theme); }
	if (n_wish < 0) {//выводим 36 символов, так как в конце надо вывести еще дополнительно "...", что отнимет 3 от максимального
		buf_string = arr_of_wishes[number_of_wishes].getText();
		cout << "|";
		for (int i = 0; i < 36; i++)
			putchar(buf_string[i]);
		cout << "...";
	}
	cout << "|";//выводим id строки в центре соответствующего столбца   
	if (n_sender == 2)
		cout << " " << arr_of_wishes[number_of_wishes].getSentBy() << " ";
	if (n_sender == 1)
		cout << " " << arr_of_wishes[number_of_wishes].getSentBy();
	if (n_sender == 0) cout << arr_of_wishes[number_of_wishes].getSentBy();
	cout << "|";//выводим id строки в центре соответствующего столбца   
	if (n_recipient == 2)
		cout << " " << arr_of_wishes[number_of_wishes].getSendTo() << " ";
	if (n_recipient == 1)
		cout << " " << arr_of_wishes[number_of_wishes].getSendTo();
	if (n_recipient == 0) cout << arr_of_wishes[number_of_wishes].getSendTo();
	coutChar('=', 72);
	cout << endl;
}
void addWishInArray(Wishes* arr_of_wishes, int& num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account) {
	bool choice;
	cout << "Вы уверены?\n1 - Да     0 - Нет\nВыбор:";
	cin >> choice;
	if (choice != 1) return;
	else {
		if (num_of_wishes + 1 <= RESERVE_SIZE)
		{
			num_of_wishes++;
			Wishes* buf_arr_of_wishes = new Wishes[num_of_wishes];
			for (int i = 0; i < num_of_wishes - 1; i++)
				buf_arr_of_wishes[i] = arr_of_wishes[i];
			delete []arr_of_wishes;
			arr_of_wishes = buf_arr_of_wishes;
			delete []buf_arr_of_wishes;
			Account* accounts_arr = new Account[num_of_wishes];
			string buf_string;
			arr_of_wishes[num_of_wishes].setIdOfWish(num_of_wishes);
			inputText(buf_string);
			arr_of_wishes[num_of_wishes].setText(buf_string);
			inputTheme(buf_string);
			arr_of_wishes[num_of_wishes].setTheme(buf_string);
			inputSendTo(arr_of_wishes, num_of_wishes, arr_of_accounts, num_of_accounts, id_of_this_account);
			addWishInFile(arr_of_wishes, num_of_wishes);
		}
		else cout << "Недостаточно памяти для добавления нового элемента!" << endl;

	}
}
void addWishInFile(Wishes* arr_of_wishes, int& number_of_wishes) {
	//добавление товара, если не происходит выход за пределы массива
	if (number_of_wishes + 1 <= RESERVE_SIZE)
	{
		//int buf_id_of_wish, buf_sent_by, buf_send_to;
		//string buf_theme, buf_text;
		ofstream fadd(FILE_OF_DATA, ios::app); // Открыли файл для дозаписи
		if (number_of_wishes > 1)
			fadd << endl;
		/*buf_id_of_wish = arr_of_wishes[number_of_wishes-1].getIdOfWish();
		buf_sent_by = arr_of_wishes[number_of_wishes-1].getSentBy();
		buf_send_to = arr_of_wishes[number_of_wishes-1].getSendTo();
		buf_theme = arr_of_wishes[number_of_wishes-1].getTheme();
		buf_text = arr_of_wishes[number_of_wishes-1].getText();*/
		fadd << arr_of_wishes[number_of_wishes - 1].getIdOfWish() << " "
			<< arr_of_wishes[number_of_wishes - 1].getSentBy() << " "
			<< arr_of_wishes[number_of_wishes - 1].getSendTo() << " "
			<< arr_of_wishes[number_of_wishes - 1].getTheme() << " "
			<< arr_of_wishes[number_of_wishes - 1].getText() << " ";
		fadd.close();
	}
	else cout << "Недостаточно памяти для добавления нового элемента!" <<
		endl;
}
void saveWishListInFile(Wishes* arr_of_wishes, int& number_of_wishes) {
	ofstream fout(FILE_OF_DATA, ios_base::out | ios_base::trunc);

	if (!fout.is_open()) // если файл небыл открыт
		cout << "Файл не может быть открыт или создан\n";
	for (int i = 0; i < number_of_wishes; i++) {

		fout << arr_of_wishes[number_of_wishes].getIdOfWish() << " "
			<< arr_of_wishes[number_of_wishes].getSentBy() << " "
			<< arr_of_wishes[number_of_wishes].getSendTo() << " "
			<< arr_of_wishes[number_of_wishes].getTheme() << " "
			<< arr_of_wishes[number_of_wishes].getText() << " ";
		if (i != number_of_wishes - 1)fout << endl;//переходим на новую строку пока не дойдем до последнего элемента 
	}
	fout.close(); // программа больше не использует файл, поэтому его нужно закрыть
	cout << "Данные успешно записаны в файл: " << FILE_OF_DATA << "\n";
}
void deleteWish(Wishes* arr_of_wishes, int& number_of_wishes) {
	int user_id;
	bool choice = 0;

	showAllWishes(arr_of_wishes, number_of_wishes);

	string mass = "При вводе 0, Вы, вернетесь назад.\nВведите номер удаляемой записи:";
	user_id = checkNumberAndDiapason(0, number_of_wishes, mass);
	if (user_id == 0)return;
	else {
		cout << "Вы уверены?\n1 - Нет    0 - Да\n";
		cin >> choice;
		if (choice != 1) choice = 0;
		else return;
		do {
			for (int i = user_id - 1; i + 1 < number_of_wishes; ++i)
				arr_of_wishes[i] = arr_of_wishes[i + 1];
			--number_of_wishes;
		} while (choice);
		for (int i = 0; i < number_of_wishes; i++)//изменяем id строк
			arr_of_wishes[i].setIdOfWish(i + 1);
		cout << "Удаление произошло." << endl;
		saveWishListInFile(arr_of_wishes, number_of_wishes);//сохраняем результат
	}
}

int getNumOfWishes() {
	int n = 0;
	ifstream in(FILE_OF_DATA);
	if (!in.is_open()) {
		int i = 1;
		cout << "Создали новый файл для сообщений." << endl;
		Wishes arr_of_wishes[1];
		arr_of_wishes[0].setIdOfWish(1);
		arr_of_wishes[0].setSentBy(0);
		arr_of_wishes[0].setSendTo(0);
		arr_of_wishes[0].setTheme("None");
		arr_of_wishes[0].setText("None");
		addWishInFile(arr_of_wishes, i);
		return i;
	}
	else {
		string line;
		while (getline(in, line)) {
			n++;
			if (n + 1 > RESERVE_SIZE) {
				cout << "Недостаточно памяти для чтения всех сообщений!" <<
					endl;
				return n;
			}
		}
	}
	return n;
}

void readFileOfWishes(Wishes* arr_of_wishes, int& number_of_wishes)
{
	/*number_of_wishes = getNumOfWishes();
	delete[] arr_of_wishes;
	arr_of_wishes = new Wishes[number_of_wishes];*/

	string buf_theme, buf_text;
	int buf_id_of_wish, buf_sent_by, buf_send_to;
	int i = 0;
	ifstream fin(FILE_OF_DATA, ios::in); // Открыли файл для чтения
	if (!fin.is_open()) {
		cout << "Создали новый файл для сообщений." << endl;
		delete arr_of_wishes;
		number_of_wishes = 1;
		arr_of_wishes = new Wishes[number_of_wishes];
		arr_of_wishes[0].setIdOfWish(1);
		arr_of_wishes[0].setSentBy(0);
		arr_of_wishes[0].setSendTo(0);
		arr_of_wishes[0].setTheme("None");
		arr_of_wishes[0].setText("None");
		
		addWishInFile(arr_of_wishes, number_of_wishes);
	}
	else
	{
		while (!fin.eof())
		{
			if (i == number_of_wishes) break;
			if (number_of_wishes == RESERVE_SIZE) {
				cout << "Недостаточно памяти для чтения всех данных!"
					<< endl;
				break;
			}

			for (i; i < number_of_wishes; i++) {
				fin >> buf_id_of_wish
					>> buf_theme
					>> buf_text
					>> buf_sent_by
					>> buf_send_to;
				arr_of_wishes[number_of_wishes].setIdOfWish(buf_id_of_wish);
				arr_of_wishes[number_of_wishes].setTheme(buf_theme);
				arr_of_wishes[number_of_wishes].setText(buf_text);
				arr_of_wishes[number_of_wishes].setSentBy(buf_sent_by);
				arr_of_wishes[number_of_wishes].setSendTo(buf_send_to);
			}
		}

	}
	fin.close(); //Закрыли файл
}

//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
// Ввод данных

void inputText(string& text) {
	string text_2;
	int choice = 0;
	do {
		text = "";
		cout << "Текст пожелания:\n";
		cin >> text;
		getline(cin, text_2);
		text.append(text_2);
		if (text == "")text = "None";//если пользователь нажал enter сразу, то строка заменяется на "---"
		else {
			int n = text.length();

			for (int i = 0; i < text.length(); i++)//заменяем пробелы на '_', чтобы не было разрывов в строке 
				if (text[i] == ' ') text[i] = '_';

			for (int i = n - 1; i > 0; i--) { //убираем '_' с конца строки, если таковые имеются			
				if (text[i] == '_')
					text.pop_back();
				else break;
			}
			if (text == "_")//если строка выглядит как "_", то заменяем её на "---"
				text = "---";

			n = text.length();
			if (n > 150) {
				text.clear();
				cout << "Вы достигли лимита. Было введенно больше 150 символов." << endl;
				cout << "Повтрорить?\n1 - да         0 - нет\n";
				cin >> choice;
			}
		}
	} while (choice);
}
void inputTheme(string& theme) {
	int choice = 0;
	do {
		cout << "Тема сообщения:\n";
		getline(cin, theme);
		if (theme == "")theme = "None";//если пользователь нажал enter сразу, то строка заменяется на "---"
		else {
			int n = theme.length();

			for (int i = 0; i < theme.length(); i++)//заменяем пробелы на '_', чтобы не было разрывов в строке 
				if (theme[i] == ' ') theme[i] = '_';

			for (int i = n - 1; i > 0; i--) { //убираем '_' с конца строки, если таковые имеются			
				if (theme[i] == '_')
					theme.pop_back();
				else break;
			}
			if (theme == "_")//если строка выглядит как "_", то заменяем её на "---"
				theme = "---";

			n = theme.length();
			if (n > 50) {
				theme.clear();
				cout << "Вы достигли лимита. Было введенно больше 50 символов." << endl;
				cout << "Повтрорить?\n1 - да         0 - нет\n";
				cin >> choice;
			}
		}
	} while (choice);
}
void inputSendTo(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account) {
	arr_of_wishes[num_of_wishes - 1].setSentBy(id_of_this_account);
	showAccountsForUsers(arr_of_accounts, num_of_accounts);
	string mass = "Какой аккант выбрать?\nВыбор:";
	int choice = checkNumberAndDiapason(1, num_of_accounts, mass);
	arr_of_wishes[num_of_wishes - 1].setSendTo(num_of_accounts - 1);
}

//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
//спец функции

void createEmptyElement(int& number_of_wishes) {
	string mass = "Вы уверены?\n1 - Да     0 - Нет\nВыбор:";
	Wishes new_element;
	int choice = checkNumberAndDiapason(0, 1, mass);
	if (choice != 1) return;
	else {
		number_of_wishes++;//добавляем в массив
		addWishInFile(&new_element, number_of_wishes);
	}
}



void backStrNumFromFile(int& n) {
	n = 0;
	ifstream in(FILE_OF_DATA);
	if (!in.is_open()) {
		cout << "Указанный файл не существует!" << endl;
		string mass = "Создать новый файл?\n1 - Да     0 - Нет\nВыбор:";
		int choice = checkNumberAndDiapason(0, 1, mass);

		if (choice == 1) {
			n = 1;
			createEmptyElement(n);
			system("cls");
		}
		else {
			return;
		}//закрываем программу при неудаче 
	}
	else {
		string line;
		while (getline(in, line)) {
			n++;
			if (n + 1 > RESERVE_SIZE) {
				cout << "Недостаточно памяти для чтения всех данных!" <<
					endl;
				return;
			}
		}
	}
};

//----------------------------------------------------------------------------//

