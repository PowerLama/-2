#pragma once

#include"functions.h"
#include "Accounts.h"
#include <iostream>
using namespace std;


class Wishes {
private:
	int id_of_wish;//����� ���������
	int sent_by;//�����������
	int send_to;//���� ���������
	string theme;//���� ���������
	string text;//����� ���������
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
void adminModule(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account);//������ �������������
void InfEditMode(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account);//����� �������������� �������
void userModule(Wishes* arr_of_wishes, int number_of_wishes);//������ ������������
void ProcessingMode(Wishes* arr_of_wishes, int number_of_wishes);//����� ���������
//-------------------------------------------------------------------------------//


//-------------------------------------------------------------------------------//

void createEmptyElement(int& number_of_wishes);//������� ������ ����
//-------------------------------------------------------------------------------//
void searchByTheme(Wishes* arr_of_wishes, int number_of_wishes);//����� �� ��������
//-----------------------------------------------
//����������
//--------------
//-------------------------------------------------------------------------------//

void changeParametr(Wishes* arr_of_wishes, int number_of_wishes);//������ ��������� ������������� �������� �������
//-----------------------------------------------
//������� ��� ������ ��������������� ���������
void changeText(Wishes* arr_of_wishes, int number_of_wishes, int id_of_wish);//������ ��������
void changeTheme(Wishes* arr_of_wishes, int number_of_wishes, int id_of_wish);//������ �������������
//-----------------------------------------------
//-------------------------------------------------------------------------------//


//-------------------------------------------------------------------------------//
void backStrNumFromFile(int& n);//���������� ���������� ����� � ����� � ���� ������� ���, �� ������� ���������� -1
int getNumOfWishes();
void readFileOfWishes(Wishes* arr_of_wishes, int& number_of_wishes);//��������� ���������� � �����
void addWishInFile(Wishes* arr_of_wishes, int& number_of_wishes);//��������� ����� ������� � ���� 
void addWishInArray(Wishes* arr_of_wishes, int& num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account);//��������� ����� ������� � ������ � ����������� ����� ������� �� 1;
void saveWishListInFile(Wishes* arr_of_wishes, int& number_of_wishes);//��������� ���� ������ � ����
void showAllWishes(Wishes* arr_of_wishes, int number_of_wishes);//������� ������ � ���� ������� 
void searchOneElement(Wishes* arr_of_wishes, int number_of_wishes);//������� ���������� ������� � ����������� ����
void showOneElement(Wishes* arr_of_wishes, int number_of_wishes, int user_id);//������� ���������� �������
void deleteWish(Wishes* arr_of_wishes, int& number_of_wishes);//������� ������� � ���������� ��������� � ����
//-------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------//
//��������������� ������� ��� showToyArray, ���������� ���������� �������� ��������������� �������� 
int returnNumIdOfWish(Wishes* arr_of_wishes, int number_of_wishes);//��� id
int returnNumSymOfWish(Wishes* arr_of_wishes, int number_of_wishes, int max);//��� name
int returnNcost(Wishes* arr_of_wishes, int number_of_wishes);//��� cost
int returnNBySender(Wishes* arr_of_wishes, int number_of_wishes, int max);//��� manufacturer
int returnNnum(Wishes* arr_of_wishes, int number_of_wishes);// ��� num
//-------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------//
//������� ��� ����� ��������������� ������
void inputText(string& name);//���� ��������
void inputTheme(string& manufacturer);//���� �������������
void inputSendTo(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account);//���� ���������� ���������
//-------------------------------------------------------------------------------//



