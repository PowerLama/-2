#pragma once

#include"functions.h"
#include "Accounts.h"
#include <iostream>
using namespace std;


class Wishes {
private:
	int id_of_wish;//номер сообщения
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
	~Wishes() {};
};

//-------------------------------------------------------------------------------//
void adminModule(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account);//модуль адмистаратора
void InfEditMode(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account);//Режим редактирования товаров
void userModule(Wishes* arr_of_wishes, int number_of_wishes);//модуль пользователя
void ProcessingMode(Wishes* arr_of_wishes, int number_of_wishes);//Режим обработки
//-------------------------------------------------------------------------------//


//-------------------------------------------------------------------------------//

void createEmptyElement(int& number_of_wishes);//создает пустой файл
//-------------------------------------------------------------------------------//
void searchByTheme(Wishes* arr_of_wishes, int number_of_wishes);//поиск по названию
//-----------------------------------------------
//сортировки
//--------------
//-------------------------------------------------------------------------------//

void changeParametr(Wishes* arr_of_wishes, int number_of_wishes);//замена параметра определенного элемента массива
//-----------------------------------------------
//функции для замены соответсвующего параметра
void changeText(Wishes* arr_of_wishes, int number_of_wishes, int id_of_wish);//замена названия
void changeTheme(Wishes* arr_of_wishes, int number_of_wishes, int id_of_wish);//замена производителя
//-----------------------------------------------
//-------------------------------------------------------------------------------//


//-------------------------------------------------------------------------------//
void backStrNumFromFile(int& n);//возвращает количество строк в файле и если таковых нет, то функция возвращает -1
int getNumOfWishes();
void readFileOfWishes(Wishes* arr_of_wishes, int& number_of_wishes);//считывает информацию с файла
void addWishInFile(Wishes* arr_of_wishes, int& number_of_wishes);//добавляет новый элемент в файл 
void addWishInArray(Wishes* arr_of_wishes, int& num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account);//добавляет новый элемент в массив и увеличивает число игрушек на 1;
void saveWishListInFile(Wishes* arr_of_wishes, int& number_of_wishes);//сохраняет весь массив в файл
void showAllWishes(Wishes* arr_of_wishes, int number_of_wishes);//выводит массив в виде таблицы 
void searchOneElement(Wishes* arr_of_wishes, int number_of_wishes);//выводит конкретный элемент в развернутом виде
void showOneElement(Wishes* arr_of_wishes, int number_of_wishes, int user_id);//находит конкретный элемент
void deleteWish(Wishes* arr_of_wishes, int& number_of_wishes);//удаляет элемент и записывает результат в файл
//-------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------//
//вспомогательные функции для showToyArray, возвращают количество символов соответсвующего элемента 
int returnNumIdOfWish(Wishes* arr_of_wishes, int number_of_wishes);//для id
int returnNumSymOfWish(Wishes* arr_of_wishes, int number_of_wishes, int max);//для name
int returnNcost(Wishes* arr_of_wishes, int number_of_wishes);//для cost
int returnNBySender(Wishes* arr_of_wishes, int number_of_wishes, int max);//для manufacturer
int returnNnum(Wishes* arr_of_wishes, int number_of_wishes);// для num
//-------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------//
//функции для ввода соответствующих данных
void inputText(string& name);//ввод названия
void inputTheme(string& manufacturer);//ввод производителя
void inputSendTo(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account);//ввод получателя сообщения
//-------------------------------------------------------------------------------//



