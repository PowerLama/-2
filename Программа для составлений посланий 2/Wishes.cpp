
#include "Accounts.h"
#include"Wishes.h"
using namespace std;
const string FILE_OF_DATA = "MyFile.txt"; //���� � ����� � �������
const int RESERVE_SIZE = 100; //������������ ���������� ��������� ������� � ������� 100

/*
class Wishes {
private:
	int id_of_wish;//����� �������
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
	if (num_of_wishes == -1) return;//������� ��� �������
	bool choice = true;
	while (choice) {
		readFileOfWishes(arr_of_wishes, num_of_wishes);
		string mass = "1 - �������� ���� ������\n2 - �������� ������� � ����������� ����\n3 - ������������� �� ��������\n4 - ����� �� ��������\n5 - ������������� �� ��������\n6 - ������������� �� ����\n0 - �����\n�����:";
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
	if (num_of_wishes == -1) return;//������� ��� �������
	bool choice = true;
	while (choice) {
		readFileOfWishes(arr_of_wishes, num_of_wishes);
		string mass = "1 - ����� �������������� ���������\n2 - ����� ���������\n0 - �����\n�����:";
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
		string mass = "1 - �������� ���� ������ ���������\n2 - �������� ��� ���� ���������\n3 - �������� ����� ����\n4 - �������� ���� ���������\n5 - ������� ��������� ����\n6 - ������� ��������� ���������\n0 - �����\n�����:";
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
		string mass = "1 - ������������� �� ����\n2 - ����� �� ��������\n3 - ������������� �� ��������\n4 - ������������� �� ����\n0 - �����\n�����:";
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
	cout << "�����:" << endl;
	string new_theme;
	inputTheme(new_theme);
	int status = 0;
	for (int i = 0; i < number_of_toyes; i++)
		if (arr_of_toyes[i].getTheme() == new_theme) {
			if (status == 0) {
				coutChar('=', 72);
				cout << endl;
				cout << "| � |���� ���������"; coutChar(' ', 2); //5+18
				cout << "|����� ���������"; coutChar(' ', 24);//1+39
				cout << "|By |To |" << endl;//9
				coutChar('=', 72);
				cout << endl;
			}
			status = 1;
			showOneElement(arr_of_toyes, number_of_toyes, i + 1);
		}
	if (status == 0) cout << "���������� �� �������." << endl;
}

//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
//������ ���������� ��������� � �������

void changeParametr(Wishes* arr_of_toyes, int number_of_toyes) {
	int user_id;
	int choice;
	while (true) {
		showAllWishes(arr_of_toyes, number_of_toyes);
		string mass = "��� ����� 0, ��, ��������� �����.\n����� ������, ������� ���� ��������:";
		user_id = checkNumberAndDiapason(0, number_of_toyes, mass);
		if (user_id == 0) {
			system("cls");
			return;
		}

		mass = "����� �������� ��������?\n1 - ��������\n2 - ����\n3 - �������������\n4 - ����������\n5 - PG\n0 - �����\n�����:";
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
//��������������� �������
void changeText(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	string new_name;
	cout << "���� ������ ������ ��� ��������� ��� ������� " << id_of_toy << ":\n";
	inputText(new_name);
	bool choice;
	cout << "�� �������?\n1 - ���    0 - ��\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].setText(new_name);
		cout << "������." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}
}
/*void changeCost(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	string new_cost;
	cout << "���� ����� ���� ��� ������ " << id_of_toy << ":\n";
	inputCost(new_cost);
	bool choice;
	cout << "�� �������?\n1 - ���    0 - ��\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].cost = new_cost;
		cout << "������." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}

}*/
void changeTheme(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	string new_theme;
	cout << "���� ����� ���� ��� ������ " << id_of_toy << ":\n";
	inputTheme(new_theme);
	bool choice;
	cout << "�� �������?\n1 - ���    0 - ��\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].setTheme(new_theme);
		cout << "������." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}
}
/*void changeNum(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	int new_num;
	cout << "���� ������ ���������� ��� ������ " << id_of_toy << ":\n";
	inputNum(new_num);
	bool choice;
	cout << "�� �������?\n1 - ���    0 - ��\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].num = new_num;
		cout << "������." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}
}
void changePG(Wishes* arr_of_toyes, int number_of_toyes, int id_of_toy) {
	int new_pg;
	cout << "���� ������ PG ��� ������ " << id_of_toy << ":\n";
	inputPG(new_pg);
	bool choice;
	cout << "�� �������?\n1 - ���    0 - ��\n";
	cin >> choice;
	if (choice != 0) return;
	else {
		arr_of_toyes[id_of_toy - 1].pg = new_pg;
		cout << "������." << endl;
		saveWishListInFile(arr_of_toyes, number_of_toyes);
	}
}
*/
//--------------------------------------------
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
//��������������� ������� ��� ������� showToyArray

int returnNumIdOfWish(Wishes* arr_of_wishes, int number_of_wishes) {
	int n_id = 0;
	if (arr_of_wishes[number_of_wishes].getIdOfWish() > 0 && arr_of_wishes[number_of_wishes].getIdOfWish() < 10)
		n_id = 2;//������������ ����� �������� 3
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
	if (n_name > max) n_name = -1;//���� �������� ������ ����������� �����������, �� �������� �� -1
	else n_name = max - n_name;
	return n_name;
}

int returnNumSymOfTheme(Wishes* arr_of_wishes, int number_of_wishes, int max) {
	int n_name;
	string buf_string;
	buf_string = arr_of_wishes[number_of_wishes].getTheme();
	n_name = buf_string.length();
	if (n_name > max) n_name = -1;//���� �������� ������ ����������� �����������, �� �������� �� -1
	else n_name = max - n_name;
	return n_name;
}

int returnNumIdBySender(Wishes* arr_of_wishes, int number_of_wishes) {
	int n_id = 0;
	if (arr_of_wishes[number_of_wishes].getSentBy() > 0 && arr_of_wishes[number_of_wishes].getSentBy() < 10)
		n_id = 2;//������������ ����� �������� 3
	if (arr_of_wishes[number_of_wishes].getSentBy() >= 10 && arr_of_wishes[number_of_wishes].getSentBy() < 100)
		n_id = 1;
	if (arr_of_wishes[number_of_wishes].getSentBy() >= 100)
		n_id = 0;
	return n_id;
}

int returnNumIdByRecepient(Wishes* arr_of_wishes, int number_of_wishes) {
	int n_id = 0;
	if (arr_of_wishes[number_of_wishes].getSendTo() > 0 && arr_of_wishes[number_of_wishes].getSendTo() < 10)
		n_id = 2;//������������ ����� �������� 3
	if (arr_of_wishes[number_of_wishes].getSendTo() >= 10 && arr_of_wishes[number_of_wishes].getSendTo() < 100)
		n_id = 1;
	if (arr_of_wishes[number_of_wishes].getSendTo() >= 100)
		n_id = 0;
	return n_id;
}

//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
//������ � �������

void showAllWishes(Wishes* arr_of_wishes, int number_of_wishes) {
	system("cls");
	coutChar('=', 120);
	cout << endl;
	cout << "| � |���� ���������"; coutChar(' ', 2); //5+18
	cout << "|����� ���������"; coutChar(' ', 24);//1+39
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

		cout << "|";//������� id ������ � ������ ���������������� �������   
		if (n_id_of_wish == 0)
			cout << " " << arr_of_wishes[i].getIdOfWish() << " ";
		if (n_id_of_wish == 1)
			cout << " " << arr_of_wishes[i].getIdOfWish();
		if (n_id_of_wish == 2) cout << arr_of_wishes[i].getIdOfWish();


		else { cout << "|" << buf_string; coutChar(' ', n_wish); }
		if (n_theme < 0) {//������� 15 ��������, ��� ��� � ����� ���� ������� ��� ������������� "...", ��� ������� 3 �� �������������
			buf_string = arr_of_wishes[i].getTheme();
			cout << "|";
			for (int j = 0; j < 25; j++)
				putchar(buf_string[j]);
			cout << "...";
		}
		else { cout << "|" << buf_string; coutChar(' ', n_theme); }
		if (n_wish < 0) {//������� 36 ��������, ��� ��� � ����� ���� ������� ��� ������������� "...", ��� ������� 3 �� �������������
			buf_string = arr_of_wishes[i].getText();
			cout << "|";
			for (int j = 0; j < 66; j++)
				putchar(buf_string[j]);
			cout << "...";
		}
		cout << "|";//������� id ������ � ������ ���������������� �������   
		if (n_sender == 0)
			cout << " " << arr_of_wishes[i].getSentBy() << " ";
		if (n_sender == 1)
			cout << " " << arr_of_wishes[i].getSentBy();
		if (n_sender == 2) cout << arr_of_wishes[i].getSentBy();
		cout << "|";//������� id ������ � ������ ���������������� �������   
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
	string mass = "��� ����� 0, ��, ��������� �����.\n����� ������, ������� ���� �������:";
	int user_id = checkNumberAndDiapason(0, number_of_toyes, mass);
	if (user_id == 0) {
		system("cls");
		return;
	}
	coutChar('=', 72);
	cout << endl;
	cout << "| � |���� ���������"; coutChar(' ', 2); //5+18
	cout << "|����� ���������"; coutChar(' ', 24);//1+39
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

	cout << "|";//������� id ������ � ������ ���������������� �������   
	if (n_id_of_wish == 2)
		cout << " " << arr_of_wishes[number_of_wishes].getIdOfWish() << " ";
	if (n_id_of_wish == 1)
		cout << " " << arr_of_wishes[number_of_wishes].getIdOfWish();
	if (n_id_of_wish == 0) cout << arr_of_wishes[number_of_wishes].getIdOfWish();
	else { cout << "|" << buf_string; coutChar(' ', n_wish); }
	if (n_theme < 0) {//������� 15 ��������, ��� ��� � ����� ���� ������� ��� ������������� "...", ��� ������� 3 �� �������������
		buf_string = arr_of_wishes[number_of_wishes].getTheme();
		cout << "|";
		for (int j = 0; j < 15; j++)
			putchar(buf_string[j]);
		cout << "...";
	}
	else { cout << "|" << buf_string; coutChar(' ', n_theme); }
	if (n_wish < 0) {//������� 36 ��������, ��� ��� � ����� ���� ������� ��� ������������� "...", ��� ������� 3 �� �������������
		buf_string = arr_of_wishes[number_of_wishes].getText();
		cout << "|";
		for (int i = 0; i < 36; i++)
			putchar(buf_string[i]);
		cout << "...";
	}
	cout << "|";//������� id ������ � ������ ���������������� �������   
	if (n_sender == 2)
		cout << " " << arr_of_wishes[number_of_wishes].getSentBy() << " ";
	if (n_sender == 1)
		cout << " " << arr_of_wishes[number_of_wishes].getSentBy();
	if (n_sender == 0) cout << arr_of_wishes[number_of_wishes].getSentBy();
	cout << "|";//������� id ������ � ������ ���������������� �������   
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
	cout << "�� �������?\n1 - ��     0 - ���\n�����:";
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
		else cout << "������������ ������ ��� ���������� ������ ��������!" << endl;

	}
}
void addWishInFile(Wishes* arr_of_wishes, int& number_of_wishes) {
	//���������� ������, ���� �� ���������� ����� �� ������� �������
	if (number_of_wishes + 1 <= RESERVE_SIZE)
	{
		//int buf_id_of_wish, buf_sent_by, buf_send_to;
		//string buf_theme, buf_text;
		ofstream fadd(FILE_OF_DATA, ios::app); // ������� ���� ��� ��������
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
	else cout << "������������ ������ ��� ���������� ������ ��������!" <<
		endl;
}
void saveWishListInFile(Wishes* arr_of_wishes, int& number_of_wishes) {
	ofstream fout(FILE_OF_DATA, ios_base::out | ios_base::trunc);

	if (!fout.is_open()) // ���� ���� ����� ������
		cout << "���� �� ����� ���� ������ ��� ������\n";
	for (int i = 0; i < number_of_wishes; i++) {

		fout << arr_of_wishes[number_of_wishes].getIdOfWish() << " "
			<< arr_of_wishes[number_of_wishes].getSentBy() << " "
			<< arr_of_wishes[number_of_wishes].getSendTo() << " "
			<< arr_of_wishes[number_of_wishes].getTheme() << " "
			<< arr_of_wishes[number_of_wishes].getText() << " ";
		if (i != number_of_wishes - 1)fout << endl;//��������� �� ����� ������ ���� �� ������ �� ���������� �������� 
	}
	fout.close(); // ��������� ������ �� ���������� ����, ������� ��� ����� �������
	cout << "������ ������� �������� � ����: " << FILE_OF_DATA << "\n";
}
void deleteWish(Wishes* arr_of_wishes, int& number_of_wishes) {
	int user_id;
	bool choice = 0;

	showAllWishes(arr_of_wishes, number_of_wishes);

	string mass = "��� ����� 0, ��, ��������� �����.\n������� ����� ��������� ������:";
	user_id = checkNumberAndDiapason(0, number_of_wishes, mass);
	if (user_id == 0)return;
	else {
		cout << "�� �������?\n1 - ���    0 - ��\n";
		cin >> choice;
		if (choice != 1) choice = 0;
		else return;
		do {
			for (int i = user_id - 1; i + 1 < number_of_wishes; ++i)
				arr_of_wishes[i] = arr_of_wishes[i + 1];
			--number_of_wishes;
		} while (choice);
		for (int i = 0; i < number_of_wishes; i++)//�������� id �����
			arr_of_wishes[i].setIdOfWish(i + 1);
		cout << "�������� ���������." << endl;
		saveWishListInFile(arr_of_wishes, number_of_wishes);//��������� ���������
	}
}

int getNumOfWishes() {
	int n = 0;
	ifstream in(FILE_OF_DATA);
	if (!in.is_open()) {
		int i = 1;
		cout << "������� ����� ���� ��� ���������." << endl;
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
				cout << "������������ ������ ��� ������ ���� ���������!" <<
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
	ifstream fin(FILE_OF_DATA, ios::in); // ������� ���� ��� ������
	if (!fin.is_open()) {
		cout << "������� ����� ���� ��� ���������." << endl;
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
				cout << "������������ ������ ��� ������ ���� ������!"
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
	fin.close(); //������� ����
}

//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
// ���� ������

void inputText(string& text) {
	string text_2;
	int choice = 0;
	do {
		text = "";
		cout << "����� ���������:\n";
		cin >> text;
		getline(cin, text_2);
		text.append(text_2);
		if (text == "")text = "None";//���� ������������ ����� enter �����, �� ������ ���������� �� "---"
		else {
			int n = text.length();

			for (int i = 0; i < text.length(); i++)//�������� ������� �� '_', ����� �� ���� �������� � ������ 
				if (text[i] == ' ') text[i] = '_';

			for (int i = n - 1; i > 0; i--) { //������� '_' � ����� ������, ���� ������� �������			
				if (text[i] == '_')
					text.pop_back();
				else break;
			}
			if (text == "_")//���� ������ �������� ��� "_", �� �������� � �� "---"
				text = "---";

			n = text.length();
			if (n > 150) {
				text.clear();
				cout << "�� �������� ������. ���� �������� ������ 150 ��������." << endl;
				cout << "����������?\n1 - ��         0 - ���\n";
				cin >> choice;
			}
		}
	} while (choice);
}
void inputTheme(string& theme) {
	int choice = 0;
	do {
		cout << "���� ���������:\n";
		getline(cin, theme);
		if (theme == "")theme = "None";//���� ������������ ����� enter �����, �� ������ ���������� �� "---"
		else {
			int n = theme.length();

			for (int i = 0; i < theme.length(); i++)//�������� ������� �� '_', ����� �� ���� �������� � ������ 
				if (theme[i] == ' ') theme[i] = '_';

			for (int i = n - 1; i > 0; i--) { //������� '_' � ����� ������, ���� ������� �������			
				if (theme[i] == '_')
					theme.pop_back();
				else break;
			}
			if (theme == "_")//���� ������ �������� ��� "_", �� �������� � �� "---"
				theme = "---";

			n = theme.length();
			if (n > 50) {
				theme.clear();
				cout << "�� �������� ������. ���� �������� ������ 50 ��������." << endl;
				cout << "����������?\n1 - ��         0 - ���\n";
				cin >> choice;
			}
		}
	} while (choice);
}
void inputSendTo(Wishes* arr_of_wishes, int num_of_wishes, Account* arr_of_accounts, int num_of_accounts, int id_of_this_account) {
	arr_of_wishes[num_of_wishes - 1].setSentBy(id_of_this_account);
	showAccountsForUsers(arr_of_accounts, num_of_accounts);
	string mass = "����� ������ �������?\n�����:";
	int choice = checkNumberAndDiapason(1, num_of_accounts, mass);
	arr_of_wishes[num_of_wishes - 1].setSendTo(num_of_accounts - 1);
}

//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
//���� �������

void createEmptyElement(int& number_of_wishes) {
	string mass = "�� �������?\n1 - ��     0 - ���\n�����:";
	Wishes new_element;
	int choice = checkNumberAndDiapason(0, 1, mass);
	if (choice != 1) return;
	else {
		number_of_wishes++;//��������� � ������
		addWishInFile(&new_element, number_of_wishes);
	}
}



void backStrNumFromFile(int& n) {
	n = 0;
	ifstream in(FILE_OF_DATA);
	if (!in.is_open()) {
		cout << "��������� ���� �� ����������!" << endl;
		string mass = "������� ����� ����?\n1 - ��     0 - ���\n�����:";
		int choice = checkNumberAndDiapason(0, 1, mass);

		if (choice == 1) {
			n = 1;
			createEmptyElement(n);
			system("cls");
		}
		else {
			return;
		}//��������� ��������� ��� ������� 
	}
	else {
		string line;
		while (getline(in, line)) {
			n++;
			if (n + 1 > RESERVE_SIZE) {
				cout << "������������ ������ ��� ������ ���� ������!" <<
					endl;
				return;
			}
		}
	}
};

//----------------------------------------------------------------------------//

