#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct userID {

	string username;
	string password;
	int lended;

}users[100];

struct booklist {

	string name;
	string author;
	string publishDate;
	string username;
	int ISBN;
	int quantity;

}books[10000], Lended[10000];

int book_quantity = 0;
int lended_quantity = 0;
int total_quantity = 0;
int book_index = 0;
int user_index = 0;
int lended_index = 0;


void loginFetch(int& i);

bool Login(const int size, int& current_index);

void convert_to_lower(string& s);

bool Format_error(const string s);

void bookFetch(int& i);

void lendedFetch(int& i);

void updateBooks(const int size);

void updateLogin(const int size);

void updateLended(const int size);

bool Signup(int& size);

bool format_error_email(const string email);

bool format_error_password(const string pass1, const string pass2);

int MainMenu();

void Admin_Menu(int current_index);

void User_Menu(int current_index);

void Available_books(const int size);

void Account_information(const int index);

void AllUsers(const int size);

void Lended_Books(const int size);

bool Add_Book(int& size);

bool DeleteBook(int& size);

bool LendBook(int& size, int user_index, int book_index);

bool ReturnBook(int& size);

void DisplayBooks(const int size);

int main() {

	loginFetch(user_index);

	bookFetch(book_index);
	lendedFetch(lended_index);

	do {
		int option;
		option = MainMenu();

		if (option == 0) {
			return 1;
		}
		else if (option == 2) {
			if (Signup(user_index)) {
				cout << "Signed Up successfully" << endl;
				updateLogin(user_index);
			}
		}
		else if (option == 1) {
			int current_index;
			if (Login(user_index, current_index)) {
				cout << "Logged in Successfuly" << endl;
				if (current_index == 0)
					Admin_Menu(current_index);
				else
					User_Menu(current_index);
			}
			else {
				cout << "Login Failed" << endl;
			}
		}

	} while (1);

}

int MainMenu() {

	cout << "|-----------------Menu-----------------|" << endl;
	cout << "|                                      |" << endl;
	cout << "| 1 - Login                2 - Sign Up |" << endl;
	cout << "|                                      |" << endl;
	cout << "|-------------- 0 - Exit---------------|" << endl;
	int option;
	cout << "Enter desired Option: " << endl;
a:	cin >> option;

	if (option > 2 || option < 0) {
		cout << "Invalid Option, Enter again: ";
		goto a;
	}


	return option;
}

void Admin_Menu(int current_index) {

	while (1)
	{

		cout << "|------------------------Menu----------------------------|" << endl;
		cout << "| 1 - Add Book                    2 - Check Quantity     | " << endl;
		cout << "| 3 - Remove Book                 4 - Lended Books       | " << endl;
		cout << "| 5 - User Info                   6 - Account Information| " << endl;
		cout << "| 7 - Book List                                          |" << endl;
		cout << "|------------------- 0 - Log out-------------------------|" << endl;
		cout << endl;

		int option;
		cout << "Enter option: ";
	b:	cin >> option;

		if (option > 8 && option < 0) {
			cout << "Invalid option, Enter again: ";
			goto b;
		}

		switch (option)
		{
		case 0:
			return;
			break;
		case 1:
			Add_Book(book_index);
			break;
		case 2:
			cout << "Total Quanity of Books is: " << book_quantity << endl;
			break;
		case 3:
			DeleteBook(book_index);
			break;
		case 4:
			Lended_Books(lended_index);
			break;
		case 5:
			AllUsers(user_index);
			break;
		case 6:
			Account_information(current_index);
			break;
		case 7:
			DisplayBooks(book_index);
			break;
		default:
			cout << "Invalid Option" << endl;
			break;
		}

	}
}

void User_Menu(int current_index) {

	while (1) {

		cout << "|------------------------Menu----------------------------|" << endl;
		cout << "| 1 - Lend Book                  2 - See Available Books | " << endl;
		cout << "| 3 - Return Book                4 - Account informatiom | " << endl;
		cout << "|-------------------0 - Sign Out-------------------------|" << endl;
		cout << endl;

		int option;
		cout << "Enter option: ";
	b:	cin >> option;

		if (option > 5 && option < 0) {
			cout << "Invalid option, Enter again: ";
			goto b;
		}

		switch (option)
		{
		case 0:
			return;
			break;
		case 1:
			LendBook(lended_index, user_index, book_index);
			break;
		case 2:
			Available_books(book_index);
			break;
		case 3:
			ReturnBook(book_index);
			break;
		case 4:
			Account_information(current_index);
			break;
		default:
			break;
		}

	}

}

void Available_books(const int size) {
	cout << "Available Books are" << endl;
	for (int i = 0; i < size; i++) {
		cout << books[i].name << endl;
		cout << books[i].author << endl;
		cout << books[i].publishDate << endl;
		cout << books[i].ISBN << endl;
		cout << books[i].quantity << endl;
	}
}

bool Add_Book(int& size) {

	if (book_quantity >= 10000) {
		cout << "No space left" << endl;
		return false;
	}

	string bookname, publish_Date, Author;
	int isbn, Quantity;

	cout << "Enter Book Name: ";
	cin.ignore();
	getline(cin, bookname);
	convert_to_lower(bookname);

	cout << "Enter Author Name: ";
	cin.ignore();
	getline(cin, Author);
	convert_to_lower(Author);

	cout << "Enter publish_Date: ";
	cin.ignore();
	getline(cin, publish_Date);

	cout << "Enter ISBN number: ";
	cin >> isbn;

c:	cout << "Enter quantity: ";
	cin >> Quantity;

	if (book_quantity + Quantity > 10000) {
		cout << "Not enough Space. " << endl;
		goto c;
	}

	book_quantity = book_quantity + Quantity;

	books[size].name = bookname;
	books[size].author = Author;
	books[size].publishDate = publish_Date;
	books[size].ISBN = isbn;
	books[size].quantity = Quantity;

	size++;

	return true;
}

bool DeleteBook(int& size) {

	string bookname;

	cout << "Enter Book Name: ";
	cin.ignore();
	getline(cin, bookname);
	convert_to_lower(bookname);

	for (int i = 0; i < size; i++) {
		if (books[i].name == bookname) {
			book_quantity = book_quantity - books[i].quantity;
			for (int j = i; j < size - 1; j++) {
				books[j].name = books[j + 1].name;
				books[j].author = books[j + 1].author;
				books[j].publishDate = books[j + 1].publishDate;
				books[j].quantity = books[j + 1].quantity;
				books[j].ISBN = books[j + 1].ISBN;
			}

			size--;
			cout << "book removed successfully" << endl;
			return true;
		}
	}
	cout << "book not available" << endl;
	return false;
}

bool LendBook(int& size, int user_index, int book_index) {
	if (users[user_index].lended >= 5) {
		cout << "You can not lend more than 5 books" << endl;
		return false;
	}

	string bookname;
	cout << "Enter the book name you want to lend: ";
	cin.ignore();
	getline(cin, bookname);

	for (int i = 0; i < book_index; i++) {
		if (bookname == books[i].name) {
			if (books[i].quantity > 0) {
				Lended[size].name = books[i].name;
				Lended[size].author = books[i].author;
				Lended[size].quantity = books[i].quantity;
				books[i].quantity--;
				Lended[size].publishDate = books[i].publishDate;
				Lended[size].ISBN = books[i].ISBN;
				Lended[size].username = users[user_index].username;
				size++;

				updateLended(size);

				cout << "Book lended successfully." << endl;
				return true;
			}
		}
	}

	cout << "Book not available." << endl;
	return false;
}


void Lended_Books(const int size) {

	cout << "Lended Books are" << endl;
	for (int i = 0; i < size; i++) {
		cout << Lended[i].name << endl;
		cout << Lended[i].author << endl;
		cout << Lended[i].publishDate << endl;
		cout << Lended[i].ISBN << endl;
		cout << Lended[i].quantity << endl;
		cout << Lended[i].username << endl;
	}

}

bool ReturnBook(int& size) {
	string bookname;
	cout << "Enter the name of the book you want to return: ";
	cin.ignore();
	getline(cin, bookname);

	for (int i = 0; i < size; i++) {
		if (bookname == Lended[i].name) {
			Lended[i] = Lended[size - 1];

			updateLended(size - 1);

			cout << "Book returned successfully." << endl;
			size--;
			return true;
		}
	}

	cout << "Book not found in the list of lent books." << endl;
	return false;
}


void loginFetch(int& i) {
	string temp;
	int lend;
	fstream userdata("Login/username.txt", ios::in);

	while (1) {
		getline(userdata, temp);

		if (userdata.eof()) {
			break;
		}

		users[i].username = temp;

		getline(userdata, temp);


		users[i].password = temp;

		i++;
	}
	userdata.close();

}

void bookFetch(int& i) {

	ifstream book("Books/books name.txt");
	string bookname;
	while (1) {

		getline(book, bookname);

		if (book.eof()) {
			break;
		}
		books[i].name = bookname;
		i++;
	}

	book.close();

	string author;
	book.open("Books/author name.txt");

	i = 0;
	while (1) {


		getline(book, author);

		if (book.eof()) {
			break;
		}
		books[i].author = author;
		i++;
	}
	book.close();

	string publish_date;

	book.open("Books/publish dates.txt");

	i = 0;
	while (1) {


		getline(book, publish_date);

		if (book.eof()) {
			break;
		}
		books[i].publishDate = publish_date;
		i++;
	}
	book.close();

	int isbn;
	book.open("Books/isbn.txt");

	i = 0;
	while (1) {

		book >> isbn;

		if (book.eof()) {
			break;
		}
		books[i].ISBN = isbn;
		i++;
	}

	book.close();

	int quantity;
	book.open("Books/quantity.txt");

	i = 0;
	while (1) {

		book >> quantity;

		if (book.eof()) {
			break;
		}

		books[i].quantity = quantity;
		book_quantity = book_quantity + quantity;
		i++;
	}

	book.close();

}

void lendedFetch(int& i) {

	ifstream book("Lended Books/books name.txt");
	string bookname;
	while (1) {

		getline(book, bookname);

		if (book.eof()) {
			break;
		}
		Lended[i].name = bookname;
		i++;
	}

	book.close();

	string author;
	book.open("Lended Books/author name.txt");

	i = 0;
	while (1) {


		getline(book, author);

		if (book.eof()) {
			break;
		}
		Lended[i].author = author;
		i++;
	}
	book.close();

	string publish_date;
	book.open("Lended Books/publish dates.txt");

	i = 0;
	while (1) {


		getline(book, publish_date);

		if (book.eof()) {
			break;
		}
		Lended[i].publishDate = publish_date;
		i++;
	}
	book.close();

	int isbn;
	book.open("Lended Books/isbn.txt");

	i = 0;
	while (1) {

		book >> isbn;

		if (book.eof()) {
			break;
		}
		Lended[i].ISBN = isbn;
		i++;
	}

	book.close();

	int quantity;
	book.open("Lended Books/quantity.txt");

	i = 0;
	while (1) {

		book >> quantity;

		if (book.eof()) {
			break;
		}

		Lended[i].quantity = quantity;
		lended_quantity = lended_quantity + quantity;
		i++;
	}

	book.close();

	string temp;
	fstream userdata("Lended Books/username.txt", ios::in);

	i = 0;
	while (1) {
		getline(userdata, temp);

		if (userdata.eof()) {
			break;
		}

		Lended[i].username = temp;
		i++;

	}
	userdata.close();


}

bool Login(const int size, int& current_index) {

	string username, password;

	do
	{
		cout << "Enter username: ";
		getline(cin, username);
		convert_to_lower(username);
	} while (Format_error(username));

	cout << "Enter password: ";
	cin.ignore();;
	getline(cin, password);

	int flag_user = 0;
	int flag_pass = 0;
	for (int i = 0; i < size; i++) {
		flag_user = 0;
		flag_pass = 0;
		if (users[i].username == username) {
			flag_user = 1;
		}

		if (users[i].password == password) {
			flag_pass = 1;
		}

		if (flag_user == 1 && flag_pass == 1) {
			current_index = i;
			return true;
		}

	}

	return false;
}

void convert_to_lower(string& s) {

	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}

}

bool Format_error(const string s) {

	if (s.length() == 0) {
		cout << "Enter Something. " << endl;
		return true;
	}

	for (int i = 0; i < s.length(); i++) {
		if ((s[i] < 48) || (s[i] > 57 && s[i] < 65) || (s[i] > 90 && s[i] < 97) || (s[i] > 122)) {
			cout << "Only alphabets and numbers can be used." << endl;
			return true;
		}
	}

	return false;

}

void updateBooks(const int size) {

	ofstream book("Books/books name.txt");

	string bookname;

	for (int i = 0; i < size; i++) {
		bookname = books[i].name;

		book << bookname << endl;
	}

	book.close();


	book.open("Books/author name.txt");


	string author;

	for (int i = 0; i < size; i++) {
		author = books[i].author;

		book << author << endl;
	}

	book.close();

	book.open("Books/isbn.txt");

	int isbn;

	for (int i = 0; i < size; i++) {
		isbn = books[i].ISBN;

		book << isbn << endl;
	}

	book.close();


	book.open("Books/quantity.txt");

	int quantity;
	for (int i = 0; i < size; i++) {
		quantity = books[i].quantity;

		book << quantity << endl;
	}

	book.close();

}

void updateLogin(const int size) {

	ofstream userdata("Login/username.txt");

	for (int i = 0; i < size; i++) {

		userdata << users[i].username << endl;

		userdata << users[i].password << endl;

	}

	userdata.close();

}

void updateLended(const int size) {

	ofstream book("Lended Books/books name.txt");

	string bookname;

	for (int i = 0; i < size; i++) {
		bookname = Lended[i].name;

		book << bookname << endl;
	}

	book.close();


	book.open("Lended Books/author name.txt");


	string author;

	for (int i = 0; i < size; i++) {
		author = Lended[i].author;

		book << author << endl;
	}

	book.close();

	book.open("Lended Books/isbn.txt");

	int isbn;

	for (int i = 0; i < size; i++) {
		isbn = Lended[i].ISBN;

		book << isbn << endl;
	}

	book.close();


	book.open("Lended Books/quantity.txt");

	int quantity;
	for (int i = 0; i < size; i++) {
		quantity = Lended[i].quantity;

		book << quantity << endl;
	}

	book.close();

	ofstream userdata("Lended Books/username.txt");

	for (int i = 0; i < size; i++) {

		userdata << Lended[i].username << endl;

	}

	userdata.close();

}

bool Signup(int& size) {

	string username = "";
	string password = "";
	string temp = "";
	string email = "";

	do {
		cout << "Enter username: ";
		cin.ignore();
	a:		getline(cin, username);
		convert_to_lower(username);
		for (int i = 0; i < size; i++) {
			if (users[i].username == username) {
				cout << "username already exist. Enter again : ";
				goto a;
			}
		}


	} while (Format_error(username));

	do {

		cout << "Enter password: ";
		cin.ignore();
		getline(cin, temp);

		cout << "Enter password again: ";
		cin.ignore();
		getline(cin, password);
	} while (format_error_password(temp, password));

	do {

		cout << "Enter email for recovery: ";
		cin >> email;
	} while (format_error_email(email));

	users[size].username = username;
	users[size].password = password;

	size++;

	return true;
}

void Account_information(const int index) {

	while (1) {
		cout << "Current Username: " << users[index].username << endl;
		cout << "Current Password: " << users[index].password << endl;
		cout << endl;
		cout << "-------Menu-------" << endl;
		cout << "1- Change Username" << endl;
		cout << "2- Change Password" << endl;
		cout << "0- Exit" << endl;

		int option;
		cout << "Enter Option: ";
		cin >> option;

		string current_name, new_username, current_pass, new_pass, new_pass2;
		switch (option)
		{
		case 0:
			return;
		case 1:
		e:		cout << "Enter Current Username: ";
			cin.ignore();
			getline(cin, current_name);
			if (current_name == users[index].username) {
				cout << "Enter new username: ";
				cin.ignore();
			d:			getline(cin, new_username);
				if (Format_error(new_username)) {
					cout << "invalid format, Enter again: ";
					goto d;
				}
				else {
					users[index].username = new_username;
					cout << "Username changed successfully" << endl;
				}
			}
			else {
				cout << "Username not mathced." << endl;
				goto e;
			}
			break;

		case 2:
		g:			cout << "Enter Current Password: ";
			cin.ignore();
			getline(cin, current_pass);
			if (current_pass == users[index].password) {
			f:			cout << "Enter new password: ";
				cin.ignore();
				getline(cin, new_pass);
				cout << "Enter new password again: ";
				cin.ignore();
				getline(cin, new_pass2);
				if (format_error_password(new_pass, new_pass2)) {
					cout << "Enter again: ";
					goto f;
				}
				else {
					users[index].password = new_pass;
					cout << "Password changed successfully" << endl;
				}
			}
			else {
				cout << "Password not mathced." << endl;
				goto g;
			}
			break;
		default:
			cout << "Invalid Option" << endl;
			break;
		}
	}

}

void AllUsers(const int size) {

	for (int i = 1; i < size; i++) {
		cout << i << ". " << users[i].username << endl;
	}
}

bool format_error_email(const string email) {

	if (email.length() < 3) {

		cout << "Enter vaild email " << endl;
		return true;
	}

	for (int i = 0; i < email.length(); i++) {

		if (email[i] == 64) {
			return false;
		}
	}

	cout << "@ is missing" << endl;
	return true;
}

bool format_error_password(const string pass1, const string pass2) {

	if (pass1 != pass2) {
		cout << "Password not matching" << endl;
		return true;
	}

	if (pass1.length() < 8) {
		cout << "Password must be greater than 8 digits" << endl;
		return true;
	}

	return false;
}

void DisplayBooks(const int size) {
	for (int i = 0; i < size; i++) {
		convert_to_lower(books[i].name);
		convert_to_lower(books[i].author);
		cout << books[i].name << endl;
		cout << books[i].author << endl;
		cout << books[i].publishDate << endl;
		cout << books[i].ISBN << endl;
		cout << books[i].quantity << endl;
	}
}

