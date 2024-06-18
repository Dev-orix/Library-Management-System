Library Management System Description

This code implements a basic library management system that allows administrators and users to manage and interact with a collection of books. It supports functionalities like user authentication, book lending, returning, and management of user accounts. The system reads and writes data to and from files to persist user and book information.

Key Functionalities:

1. User Authentication:
   - *Login*: Users can log in using their username and password.
   - *Signup*: New users can create an account by signing up with a unique username and password.
   - *Account Information*: Users can view and update their account information, including changing their username or password.

2. Admin Functions:
   - *Add Book*: Admins can add new books to the library by providing details like name, author, publish date, ISBN, and quantity.
   - *Delete Book*: Admins can remove books from the library based on the book's name.
   - *Check Quantity*: Admins can view the quantity of a specific book.
   - *View All Users*: Admins can view a list of all users in the system.

3. User Functions_:
   - *Lend Book*: Users can borrow books from the library if they are available.
   - *Return Book*: Users can return books they have borrowed.
   - *View Available Books*: Users can view a list of all available books in the library.
   - *View Lent Books*: Users can view a list of all books they have borrowed.

4. *Data Management*:
   - *Fetch Data*: The system reads user and book information from files when it starts.
   - *Update Data*: The system updates the files with any changes made to the user or book information during its operation.


Functions Overview:

- *main()*: The entry point of the program, which initializes the system and displays the main menu.
- *MainMenu()*: Displays the main menu and handles user selection.
- *Admin_Menu()*: Displays the admin menu and handles admin actions.
- *User_Menu()*: Displays the user menu and handles user actions.
- *Available_books()*: Displays a list of all available books.
- *Add_Book()*: Adds a new book to the library.
- *DeleteBook()*: Deletes a book from the library.
- *LendBook()*: Allows a user to borrow a book.
- *Lended_Books()*: Displays a list of all lent books.
- *ReturnBook()*: Allows a user to return a borrowed book.
- *Loginfetch()*, *BookFetch()*, *LendedFetch()*: Fetch user and book data from files.
- *Login()*: Handles user login.
- *Signup()*: Handles user signup.
- *Account_information()*: Manages user account information.
- *AllUsers()*: Displays all users in the system.
- *format_error_email()*, *format_error_password()*, *Format_error()*: Helper functions for input validation.
- *UpdateBooks()*, *UpdateLogin()*, *UpdateLended()*: Update the respective files with current data.


Data Files:

- *users.txt*: Stores user information.
- *books.txt*: Stores book information.
- *lended.txt*: Stores information about lent books.

This system provides a comprehensive set of features for managing a small library, allowing both administrators and users to efficiently manage and use the library resources.
