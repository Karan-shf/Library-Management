#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <string.h>

using namespace std;

    fstream booklist , reservationInfo  ;
    string username , password ;
    bool is_Admin = false  ;
    bool goldenUser = false;

    int UserNum = 0;

class reserveList {

    public:

    string reserverUser ;
    string reserverNum ;
    string bookTitle ;
    string reservedBookNum ;

};

class admin {

    public:

    string username;
    string password;
    string name;

};

class book {

    public:

    string BookID;
    string title;
    string author;
    string FinePrice;
    bool regular;
    bool borrowable;
    string LastUser;
    string lastBoTime;
    string dateGivenBack;

};

class users {

    public:

    string username;
    string password;
    string FirstName;
    string LastName;
    string BirthDate;
    string address;
    string PhoneNumber;
    string JoinDate;
    bool HaveNotif;
    bool type;
    string MaxBow ;
    string TimeLimit;
    string borrowed_books_count;
    string borrowed_book_list;
    string total_latency;
    bool is_banned;

};

class Date {

    public :

	int d;
    int m;
    int y;

};

///////////////////////////////////PROTOTYPES////////////////////////////////////////////

string todayDate();

int Book_count_line();

void insert_value_Book_class(book []);

void adminDashboard() ;

void userDashboard() ;

void reserveBook();

void refreshBooks(book []);

void refreshUsers(users []);

string string_rearranger(string );

int dateDif(string) ;

void extened_reserve_time();

int finePrice(int i ) ;

void giveBackBook();

void reservationList(int) ;

void reservationListApply(int);

void personalInformation();

void editUser();

void book_id_sort(book books[]);

int user_count_line();

int reserve_count_line();

void insert_value_Reserves_class(reserveList reserves[]);

void insert_value_admin_class(admin);

void insert_value_Users_class(users);

void showBooks();

int book_search();

string random_Book_ID_Gen();

string rand_pass_generator();

bool pass_length_check(string);

int pass_security_check(string ) ;

string string_rearranger(string );

void AddBook() ;

void deleteBook ();

void editBook() ;

void BanUser() ;

void UnBanUser() ;

void Logout(bool *);

int countLeapYears(Date );

int calDifference(Date,Date );

void show_options ();

void registery();

void login ();

void admin_login();

void user_options();

/////////////////////////////////////////////////////////////////////////////////////////

void book_id_sort(book books[]) {

    int BookCount = Book_count_line();

    book temp;
    for (int i=0;i<BookCount;i++) {
        for (int j=0;j<BookCount-1-i;j++) {
            if (books[j].BookID[0]>books[j+1].BookID[0]) {
                temp=books[j];
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
}

int user_count_line() {

    fstream file;
    string line;

    file.open("users.txt",ios::in);
    string countLine;
    int w=0;
    if (file.is_open()) {
        while(getline(file,countLine)) {
            w++;
        }

    }
    file.close();

    return w;

}

int Book_count_line() {

    fstream file;
    string line;

    file.open("Books.txt",ios::in);
    string countLine;
    int w=0;
    if (file.is_open()) {
        while(getline(file,countLine)) {
            w++;
        }

    }
    file.close();

    return w;

}

int reserve_count_line() {

    fstream file;
    string line;

    file.open("reservation list.txt",ios::in);
    string countLine;
    int w=0;
    if (file.is_open()) {
        while(getline(file,countLine)) {
            w++;
        }

    }
    file.close();

    return w;

}

void insert_value_Reserves_class(reserveList reserves[]){

    fstream file;
    string line;

    string reserveID[4];

    int j=0;
    file.open("reservation list.txt",ios::in);
    if (file.is_open()) {
        while(getline(file,line)) {

            stringstream section(line);
            for(int i = 0 ; i < 4 ; i++){
                getline(section , reserveID[i] , ',');
            }
            reserves[j].bookTitle = reserveID[0];
            reserves[j].reservedBookNum =reserveID[1];
            reserves[j].reserverNum = reserveID[2];
            reserves[j].reserverUser = reserveID[3];


            j++;

        }
    }
    file.close();

}

void insert_value_Users_class(users users[]){

    fstream file;
    string line;

    string UserID[16];

    int j=0;
    file.open("users.txt",ios::in);
    if (file.is_open()) {
        while(getline(file,line)) {

            stringstream section(line);
            for(int i = 0 ; i < 16 ; i++){
                getline(section , UserID[i] , ',');
            }

            users[j].username=UserID[0];
            users[j].password=UserID[1];
            users[j].FirstName=UserID[2];
            users[j].LastName=UserID[3];
            users[j].BirthDate=UserID[4];
            users[j].address=UserID[5];
            users[j].PhoneNumber=UserID[6];
            users[j].JoinDate=UserID[7];
            if (UserID[8]=="true") {
                users[j].HaveNotif=true;
            } else {
                users[j].HaveNotif=false;
            }
            if (UserID[9]=="regular") {
                users[j].type=false;
            } else {
                users[j].type=true;
            }
            users[j].MaxBow=UserID[10];
            users[j].TimeLimit=UserID[11];
            users[j].borrowed_books_count=UserID[12];
            users[j].borrowed_book_list=UserID[13];
            users[j].total_latency=UserID[14];
            if (UserID[15]=="banned") {
                users[j].is_banned=true;
            } else {
                users[j].is_banned=false;
            }


            j++;

        }
    }
    file.close();

}

void insert_value_admin_class(admin admins[]){

    fstream file;
    string line;

    string AdminID[3];

    int j=0;
    file.open("Admins.txt",ios::in);
    if (file.is_open()) {
        while(getline(file,line)) {

             stringstream section(line);
            for(int i = 0 ; i < 3 ; i++){
                getline(section , AdminID[i] , ',');
            }
            admins[j].username=AdminID[0];
            admins[j].password=AdminID[1];
            admins[j].name=AdminID[2];

            j++;

        }
    }
    file.close();

}

void insert_value_Book_class(book books[]) {

    fstream file;
    string line;

    string bookID[9];

    int j=0;
    file.open("Books.txt",ios::in);
    if (file.is_open()) {
        while(getline(file,line)) {
            stringstream section(line);
            for(int i = 0 ; i < 9 ; i++){
                getline(section , bookID[i] , ',');
            }

            books[j].BookID=bookID[0];
            books[j].title=bookID[1];
            books[j].author=bookID[2];
            books[j].FinePrice=bookID[3];

            if (bookID[4]=="true"){
                books[j].regular=true;
            } else {
                books[j].regular=false;
            }

            if (bookID[5]=="true"){
                books[j].borrowable=true;
            } else {
                books[j].borrowable=false;
            }

            books[j].LastUser=bookID[6];
            books[j].lastBoTime=bookID[7];
            books[j].dateGivenBack=bookID[8];

            j++;

        }
    }
    file.close();

    book_id_sort(books);

}

void showBooks(){

    int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class( books );

    cout <<endl;

    cout <<"List of Books:\n\n";

    for(int i = 0 ; i < BookCount ; i++){
        cout<< i+1 <<"."<< endl;
        cout<< "Book ID: " << books[i].BookID <<endl;
        cout<< "Book name: " << books[i].title <<endl;
        cout<< "Book author: " << books[i].author <<endl;
        cout<< "Book fine price: " << books[i].FinePrice <<endl;
        if(books[i].regular == false) {
            cout<< "this book is only for golden members "<<endl;
        }
        if(!books[i].borrowable) {
            cout<< "this book is not available right now "<<endl;
        }
        if (is_Admin == true) {

            cout<< "Date last borrowed: " << books[i].lastBoTime<<endl ;
            cout<< "Last user: " << books[i].LastUser<<endl ;
            cout<< "Date last given back: " << books[i].dateGivenBack<<endl ;

        }

        cout<<"====================================================="<< endl ;

    }
}

int book_search(){

    int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class(books);

    string bookToSearch;

    cout <<endl;

    while (true) {

        cout<< "Enter the Book's Title : ";

        getline(cin , bookToSearch ) ;
        getline(cin , bookToSearch ) ;

        bookToSearch = string_rearranger(bookToSearch);

        for (int i = 0 ; i < BookCount ; i++ ) {

            if (bookToSearch==books[i].title) {
                return i;
            }

        }

        cout <<endl;

        cout<< "Book was not found :((\n";
        cout <<"search the book again\n";

    }

}

string random_Book_ID_Gen(){

    string all[3] = {"abcdefghijklmnopqrstuvwxyz" , "ABCDEFGHIJKLMNOPQRSTUVWXYZ" , "123456789"};

    srand(time(0));
    int l,k,j;
    string ID;
    for (int i=0;i<10;i++) {

        j = rand()%3;

        l = all[j].length();

        k = rand()%l;

        ID += all [j] [k];

    }

    return ID;

}

string rand_pass_generator(){
    string all[4] = {"abcdefghijklmnopqrstuvwxyz" , "ABCDEFGHIJKLMNOPQRSTUVWXYZ" , "123456789" , "!@#$%^&*"};

    srand(time(0));
    int l,k,j;
    string pass;
    for (int i=0;i<8;i++) {

        j = rand()%4;

        l = all[j].length();

        k = rand()%l;

        pass += all [j] [k];

    }

    return pass;
}

bool pass_length_check(string pass){
    int l;

    l = pass.length();

    if (l == 8) {
        return true;
    } else {
        return false;
    }

}

int pass_security_check(string pass) {

    string all[4] = {"abcdefghijklmnopqrstuvwxyz" , "ABCDEFGHIJKLMNOPQRSTUVWXYZ" , "123456789" , "!@#$%^&*"};

    int a[8];

    for (int i=0;i<8;i++) {
        //i=index of char in pass
        for (int j=0;j<4;j++) {
            //j=type of char
            for (int k=0;k<all[j].length();k++) {

                if (pass[i]==all[j][k]) {
                    a[i]=j;
                    break;
                }

            }

        }

    }

    bool c[4] = {false , false , false, false};

    for (int i=0;i<8;i++) {
        if (a[i]==0) {c[0]=true;}
        if (a[i]==1) {c[1]=true;}
        if (a[i]==2) {c[2]=true;}
        if (a[i]==3) {c[3]=true;}
    }

    int security_level=0;
    for (int i=0;i<4;i++) {
        if (c[i]) {security_level++;}
    }

    return security_level;

}

string string_rearranger(string str) {

    int l;

    str [0] = toupper(str [0]);

    l=str.length();

    for (int i=1;i<l;i++) {
        if (str[i]==' ') {
            str[i+1]=toupper(str[i+1]);
            i++;
        } else {
            str[i]=tolower(str[i]);
        }
    }

    return str;
}

void refreshUsers(users users[]){

    fstream file;

    int UserCount = user_count_line();

    file.open("users.txt",ios::out);
    if (file.is_open()) {

        for(int i = 0 ; i < UserCount ; i++){

            file <<users[i].username <<',';
            file <<users[i].password <<',';
            file <<users[i].FirstName <<',';
            file <<users[i].LastName<<',';
            file <<users[i].BirthDate <<',';
            file <<users[i].address <<',';
            file <<users[i].PhoneNumber <<',';
            file <<users[i].JoinDate<<',';
            if (users[i].HaveNotif) {
                file <<"true,";
            } else {
                file <<"false,";
            }
            if (users[i].type) {
                file <<"golden,";
            } else {
                file <<"regular,";
            }
            file <<users[i].MaxBow <<',';
            file <<users[i].TimeLimit<<',';
            file <<users[i].borrowed_books_count <<',';
            file <<users[i].borrowed_book_list <<',';
            file <<users[i].total_latency <<',';
            if (users[i].is_banned) {
                file <<"banned";
            } else {
                file <<"not banned";
            }
            file <<endl;

        }
    }
    file.close();
}

void refreshBooks(book books[]){
    int Bookcount = Book_count_line() ;

    int i ;
    ofstream file ("Books.txt");

        for(i = 0 ; i < Bookcount ; i++){
            file <<books[i].BookID <<',';
            file <<books[i].title <<',';
            file <<books[i].author <<',';
            file <<books[i].FinePrice <<',';
            if (books[i].regular) {
                file <<"true" <<',';
            } else {
                file <<"false" <<',';
            }
            if (books[i].borrowable) {
                file <<"true" <<',';
            } else {
                file <<"false" <<',';
            }
            file <<books[i].LastUser <<',';
            file <<books[i].lastBoTime <<',';
            file <<books[i].dateGivenBack;


            file <<endl;
        }

    file.close() ;

}

void AddBook() {

    int BookCount = Book_count_line();

    book books[BookCount+1];

    insert_value_Book_class(books);

    books[BookCount].BookID=random_Book_ID_Gen();

    bool Book_ID_Check = true;

    while (Book_ID_Check) {
        for (int i=0;i<BookCount;i++) {
            if (books[BookCount].BookID==books[i].BookID) {
                Book_ID_Check=true;
                books[BookCount].BookID=random_Book_ID_Gen();
                break;
            } else {
                Book_ID_Check=false;
            }
        }
    }

    cout <<"enter book title: ";
    getline(cin,books[BookCount].title);
    getline(cin,books[BookCount].title);
    cout <<endl;
    books[BookCount].title=string_rearranger(books[BookCount].title);
    cout <<"enter book author: ";
    getline(cin,books[BookCount].author);
    books[BookCount].author=string_rearranger(books[BookCount].author);
    cout <<endl;
    cout <<"enter book fine price: ";
    getline(cin,books[BookCount].FinePrice);
    cout <<endl;

    string answer;
    while (true) {

        cout <<"is this book for golden members only? (yes/no)";
        cin >>answer;

        if (answer=="yes") {
            books[BookCount].regular=false;
            break;
        } else if (answer=="no") {
            books[BookCount].regular=true;
            break;
        } else {
            cout <<"invalid input!\n";
        }

    }

    cout <<endl;

    books[BookCount].borrowable=true;
    books[BookCount].LastUser="NULL";
    books[BookCount].lastBoTime="NULL";
    books[BookCount].dateGivenBack="NULL";


    fstream file;

    file.open("Books.txt",ios::app);
    if (file.is_open()) {
        file <<books[BookCount].BookID <<',';
        file <<books[BookCount].title <<',';
        file <<books[BookCount].author <<',';
        file <<books[BookCount].FinePrice <<',';
        if (books[BookCount].regular) {
            file <<"true" <<',';
        } else {
            file <<"false" <<',';
        }
        if (books[BookCount].borrowable) {
            file <<"true" <<',';
        } else {
            file <<"false" <<',';
        }
        file <<books[BookCount].LastUser <<',';
        file <<books[BookCount].lastBoTime <<',';
        file <<books[BookCount].dateGivenBack;
        file <<endl;
    }

    cout <<"BOOK SUCCESFULLY ADDED!\n";
    cout <<"----------------------------------------------------------------------------\n";

}

void reservationListApply(int chosen){

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class(books);



    int reserveCount = reserve_count_line();

    reserveList reserves[reserveCount];

    insert_value_Reserves_class( reserves );

    int i , j;

    for( i = 0 ; i < reserveCount ; i++){
        int a = stoi(reserves[i].reservedBookNum);
        if( a == chosen){
            int b = stoi(reserves[i].reserverNum);
            books[chosen].LastUser = reserves[i].reserverUser ;
            books[chosen].lastBoTime = todayDate() ;
            books[chosen].borrowable = false ;
            users[b].HaveNotif=true;
            refreshBooks(books);
            refreshUsers(users);
            break ;
        }
    }
    fstream file ;
    file.open("reservation list.txt" , ios::out);
        if (file.is_open()){

        for(j = 0 ; j < reserveCount ; j++){
            if(j == i){
                continue;
            }
            file << reserves[j].bookTitle<<","<<reserves[j].reservedBookNum<<",";
            file <<reserves[j].reserverNum<<","<< reserves[j].reserverUser<<endl ;
        }

    }


}

void reservationListWrite( int chosen ){

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);



    int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class(books);



    fstream file ;
    file.open("reservation list.txt" , ios:: app);
    if(file.is_open()){
        file << books[chosen].title<<","<<chosen<<",";
        file <<UserNum<<","<< users[UserNum].username<<endl ;
    }
    
    cout <<endl;

    cout <<"RESERVATION SUCCESSFULL :)\n";
    
}

void deleteBook () {

    int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class(books);

    fstream file;

    cout <<"Do You Wish to Search the Books by \n\n";
    cout <<"[1]Name \n";
    cout <<" or \n";
    cout <<"[2]Booklist?\n\n";
    int n;
    int ChosenBook;

    bool validNum = false;

    while(!validNum) {

        cin>> n;

        switch (n) {
            case 1:
                ChosenBook = book_search() ;
                validNum = true ;
                break;
            case 2:
                showBooks();
                cout <<"Enter the number of the book you want to delete: ";
                cin>> ChosenBook;
                ChosenBook--; //because users booklist starts from 1 not 0
                validNum = true ;
                break;
            default:
                cout <<"invalid number\n";
                cout <<"please enter command again\n";
        }

    }

    cout <<endl;    

    if(!books[ChosenBook].borrowable){
        cout<<"Book can not be deleted because it is borrowed \n";
    } else {

        file.open("Books.txt",ios::out);
        if(file.is_open()) {

            for (int i=0 ; i < BookCount ; i++) {

                if (i == ChosenBook) {continue;}

                file <<books[i].BookID <<',';
                file <<books[i].title <<',';
                file <<books[i].author <<',';
                file <<books[i].FinePrice <<',';
                if (books[i].regular) {
                    file <<"true" <<',';
                    } else {
                    file <<"false" <<',';
                }
                if (books[i].borrowable) {
                    file <<"true" <<',';
                } else {
                    file <<"false" <<',';
                }
                file <<books[i].LastUser <<',';
                file <<books[i].lastBoTime <<',';
                file <<books[i].dateGivenBack;
                file <<endl;

            }

        }
        file.close();

        cout <<"BOOK SUCCESSFULLY DELETED :)\n";
    }

    cout <<"----------------------------------------------------------------------------\n";

}

void editBook(){

    int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class(books);

    cout <<"Do You Wish to Search the Books by \n\n";
    cout <<"[1]Name \n";
    cout <<" or \n";
    cout <<"[2]Booklist?\n\n";
    int n;
    int ChosenBook;


    bool Valid_cmnd = false;
    bool done = false ;


    while(!Valid_cmnd) {

        cin>> n;

        switch (n) {
            case 1:
                ChosenBook = book_search() ;
                Valid_cmnd = true ;
                break;
            case 2:
                showBooks();
                cout <<"Enter the number of the book you want to edit: ";
                cin>> ChosenBook;
                ChosenBook--; //because users booklist starts from 1 not 0
                Valid_cmnd = true ;
                break;
            default:
                cout <<"invalid number\n";
                cout <<"please enter command again\n";
        }

    }

    int m;
    string UpdatedType;
    cout <<endl;

    while(!done){

        cout << "which part of the book are you going to edit ?" <<endl;
        cout << "[1]Title \t [2]Author \n";
        cout << "[3]Fine Price \t [4]Choose the Type Again  \n";

        cin >>m;

        cout <<endl;

        switch(m) {

            case 1:
                cout<<"Enter book's new title : ";
                getline(cin , books[ChosenBook].title ) ;
                getline(cin , books[ChosenBook].title ) ;
                books[ChosenBook].title=string_rearranger(books[ChosenBook].title);
                break;
            case 2:
                cout<<"Enter book's new author : ";
                getline(cin , books[ChosenBook].author ) ;
                getline(cin , books[ChosenBook].author ) ;
                books[ChosenBook].author=string_rearranger(books[ChosenBook].author);
                break;
            case 3:
                cout<<"Enter book's renewed fine price : ";
                getline(cin , books[ChosenBook].FinePrice ) ;
                getline(cin , books[ChosenBook].FinePrice ) ;
                break;
            case 4:
                cout<<"what type do you want this book to be (golden/regular)? \n";

                while(true) {
                    cin >> UpdatedType;
                    if(UpdatedType == "golden"){
                        books[ChosenBook].regular = false;
                        break;
                    }else if (UpdatedType == "regular"){
                        books[ChosenBook].regular = true;
                        break;
                    }else{
                        cout<<"invalid input";
                    }
                }
                break;
            default:
                cout<< "invalid number\n" ;
                cout <<"please enter command again: ";
        }

        cout <<endl;
        cout << "do you want to continue editing this book ?" <<endl;
        cout << "[1]Yes \t  [2]No\n";
        int c ;
        while(true){
            cin >> c ;
            if(c == 2){
                done = true ;
                refreshBooks(books);
                break;
            }else if (c == 1) {
                break;
            } else {
                cout<<"invalid number";
            }
        }

    }

    cout <<"BOOK SUCCESSFULLY EDITED :)\n";

    cout <<"----------------------------------------------------------------------------\n";

}

void BanUser() {

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    cout <<"List of Users:\n";

    int i;
    for (i=0;i<UserCount;i++) {
        cout <<i+1 <<'.' <<users[i].username <<endl;
    }

    cout<<endl;

    int j;
    cout <<"choose the user you want to ban:";
    cin >>j;
    j--;

    cout <<endl;

    if (users[j].is_banned) {
        cout <<"USER IS ALREADY BANNED\n";
    } else {
        users[j].is_banned = true;
        refreshUsers(users);
        cout <<"USER SUCCESSFULLY BANNED\n";
    }
    
    cout <<"----------------------------------------------------------------------------\n";

}

void UnBanUser() {

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    bool UsersBanned = false;

    for (int i=0;i<UserCount;i++) {

        if (users[i].is_banned) {
            UsersBanned = true;
            break;
        }

    }

    if (!UsersBanned) {

        cout <<"There Are No Banned Users :)\n";

    } else {

        cout <<"List of Banned Users:\n";

        int j=1;
        for (int i=0;i<UserCount;i++) {

            if (users[i].is_banned) {
                cout <<j <<'.' <<users[i].username <<endl;
                j++;
            }

        }

        cout <<endl;

        int k;

        while (true) {

            cout <<"Choose the User You Want to Unban: ";
            cin >>k;

            if (k>j || k<1) {
                cout <<"invalid input\n";
                cout <<"please try again\n";
            } else {

                int z=1;
                int res;
                for (int i=0;i<UserCount;i++) {

                    if (users[i].is_banned) {
                        if (z==k) {
                            res=i;
                            break;
                        } else {
                            z++;
                        }
                    }
                }

                users[res].is_banned=false;

                refreshUsers(users);

                cout <<"USER SUCCESSFULLY UNBANNED\n";

                break;

            }

        }
        
    }

    cout <<"----------------------------------------------------------------------------\n";
    
}

void Logout(bool *ptr_logout) {

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    int borrowedBookNum = stoi(users[UserNum].borrowed_books_count);

    if (borrowedBookNum != 0) {
        cout <<"You Can Not Log-Out Now Because You Have Some Books Borrowed\n";
        cout <<"Return Your Books to be able to Log-Out\n\n";
        *ptr_logout=false;
    } else {

        fstream file;

        int n;

        cout <<"Are You Sure You Want to Delete Your Account?\n";
        cout <<"[1]Yes  \t  [2]No \n";

        bool cmnd = true;

        while (cmnd) {

            cin >>n;

            if (n==1){
                *ptr_logout=true;
                file.open("users.txt",ios::out);
                if (file.is_open()) {
                    
                    for(int i = 0 ; i < UserCount ; i++){

                        if (i==UserNum) {continue;}

                        file <<users[i].username <<',';
                        file <<users[i].password <<',';
                        file <<users[i].FirstName <<',';
                        file <<users[i].LastName<<',';
                        file <<users[i].BirthDate <<',';
                        file <<users[i].address <<',';
                        file <<users[i].PhoneNumber <<',';
                        file <<users[i].JoinDate<<',';
                        file <<users[i].HaveNotif <<',';
                        if (users[i].type) {
                            file <<"golden,";
                        } else {
                            file <<"regular,";
                        }
                        file <<users[i].MaxBow <<',';
                        file <<users[i].TimeLimit<<',';
                        file <<users[i].borrowed_books_count <<',';
                        file <<users[i].borrowed_book_list <<',';
                        file <<users[i].total_latency <<',';
                        if (users[i].is_banned) {
                            file <<"banned";
                        } else {
                            file <<"not banned";
                        }
                        file <<endl;

                    }

                }
                break;

            } else if (n==2) {
                *ptr_logout=false;
                break;
            } else {
                cout <<"invalid input!\n";
            }

        }


    }

    cout <<"----------------------------------------------------------------------------\n";

    
    
}

int finePrice(int i ){


    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);



    int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class(books);


    int timelimit ;
    int fineRate , fine ;
    int finePriceint = stoi(books[i].FinePrice);
    fineRate = finePriceint ;

    if(users[UserNum].type == true){
        timelimit = 30 ;
    }else{
        timelimit = 7 ;
    }

    int fineDay = dateDif(books[i].lastBoTime) - timelimit ;

    if( fineDay > 0 ){

       fine = fineDay * finePriceint ;
    }else{
        fine = 0 ;
    }
    return fine ;

}

int countLeapYears(Date d){
	int years = d.y;

	if (d.m <= 2)
		years--;
	return years / 4
		- years / 100
		+ years / 400;
}

int calDifference(Date dt1, Date dt2){
    const int monthDays[12]
	= { 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31 };

	long int n1 = dt1.y * 365 + dt1.d;
	for (int i = 0; i < dt1.m - 1; i++)
		n1 += monthDays[i];
	n1 += countLeapYears(dt1);

	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i < dt2.m - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);
	return (n2 - n1);
}

int dateDif(string date ){

    stringstream Datee(date);
    string yearS , monthS , dayS ;
    int year1,month1,day1 ;
    getline(Datee , yearS , '/');
    getline(Datee , monthS , '/');
    getline(Datee , dayS , '/');


    year1= stoi(yearS);
    month1 = stoi(monthS);
    day1 = stoi(dayS);
    time_t now ;
    struct tm nowLocal ;
    now = time(NULL) ;
    nowLocal = *localtime(&now);
    int year2 = nowLocal.tm_year + 1900 ;
    int month2 = nowLocal.tm_mon + 1 ;
    int day2 = nowLocal.tm_mday ;


	Date dt1 = { day1, month1, year1 };
	Date dt2 = { day2 , month2 , year2 };

	return calDifference(dt1 , dt2);

}

void extened_reserve_time(){
	
	int reserveCount = reserve_count_line();

    reserveList reserves[reserveCount];

    insert_value_Reserves_class( reserves );
    
	int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class(books);

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    int borrowedBookNum = stoi(users[UserNum].borrowed_books_count);

    if (borrowedBookNum==0) {
        cout<<"you have no books borrowed\n";
    } else {

        int i ;
        for(i = 0 ; i < BookCount ; i++){

            if((books[i].LastUser == users[UserNum].username)&&books[i].borrowable == false ){
                cout<< books[i].title <<endl ;
                cout<< finePrice(i) << endl ;
                cout << "/////////////////////////////////////////////////////////////"<<endl ;
            }
        }
        cout<<"Enter the title of the book you want to extend reservation time : " ;
        string bookName ;

        bool check = true;

        while (check) {
			bool notInList = true;
            getline(cin , bookName);
            getline(cin , bookName);
            bookName=string_rearranger(bookName);
            for(i = 0 ; i < BookCount ; i++){
                if((books[i].LastUser == users[UserNum].username)&&books[i].borrowable == false) {
                    if(books[i].title == bookName ){
                    	for(int k = 0 ; k < reserveCount ; k ++){
                            int a = stoi(reserves[k].reservedBookNum);
                    		if(a== i){
                    			notInList = false;
                    			break;
							}
						}
                        if(notInList){
                            check = false;
                            books[i].lastBoTime = todayDate() ;
                            cout<<"reservation was successfully extended \n" ;
                            refreshUsers(users);
                            refreshBooks(books);
                            break;
                        }
                    }
                }
                
            }
            if (check) {
                cout <<"book was not found\n";
                cout <<"please try entering book title: ";
            }
        }       	
	}	               
}

void adminDashboard(){

    cout<< "===========================** YOU ENTERED ADMIN DASHBOARD **================================= \n\n";
    bool check = true;
    while(check){

        cout <<"press [1] to add books  \t";
        cout <<"press [2] to delete books \n";
        cout <<"press [3] to edit books \t";
        cout <<"press [4] to ban user\n";
        cout <<"press [5] to unban user  \t";
        cout <<"press [6] to exit" <<endl;
        int n ;
        cin >>n;
        switch (n){
            case 1 :
                system("clear");
                AddBook();
                break ;
            case 2 :
                system("clear");
                deleteBook();
                break ;
            case 3 :
                system("clear");
                editBook();
                break ;
            case 4 :
                system("clear");
                BanUser();
                break ;
            case 5 :
                system("clear");
                UnBanUser();
                break;
            case 6 :
                check = false;
                break;
            default:
                cout<<"invalid number" ;
        }

    }

}

void show_options () {

    cout <<"                                                                                               \n";
    cout <<"                                                                                               \n";
    cout <<"\t ______ _      ____       _______   _      _____ ____  _____            _______     __         \n";
    cout <<"\t|  ____| |    / __ \\   /\\|__   __| | |    |_   _|  _ \\|  __ \\     /\\   |  __ \\ \\   / /  \n";
    cout <<"\t| |__  | |   | |  | | /  \\  | |    | |      | | | |_) | |__) |   /  \\  | |__) \\ \\_/ /      \n";
    cout <<"\t|  __| | |   | |  | |/ /\\ \\ | |    | |      | | |  _ <|  _  /   / /\\ \\ |  _  / \\   /      \n";
    cout <<"\t| |    | |___| |__| / ____ \\| |    | |____ _| |_| |_) | | \\ \\  / ____ \\| | \\ \\  | |      \n";
    cout <<"\t|_|    |______\\____/_/    \\_\\_|    |______|_____|____/|_|  \\_//_/    \\_\\_|  \\_\\ |_|    \n";
    cout <<"                                                                                               \n";
    cout <<"                                                                                               \n";
    cout <<"\t\t\t\t  *Press [1] To Enter As an Admin* \n";
    cout <<"\t\t\t\t  *Press [2] To Enter As a User*   \n";
    
}

void giveBackBook(){

    int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class(books);

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    int borrowedBookNum = stoi(users[UserNum].borrowed_books_count);

    if (borrowedBookNum==0) {
        cout<<"You Have No Books Borrowed\n";
    } else {

        cout <<"List of Borrowed Books:\n\n";

        int i ;
        for(i = 0 ; i < BookCount ; i++){

            if((books[i].LastUser == users[UserNum].username)&&books[i].borrowable == false ){
                cout<< books[i].title <<endl ;
                cout<<"Fine Price: " << finePrice(i) <<'$' << endl ;
                cout << "/////////////////////////////////////////////////////////////"<<endl ;
            }
        }
        cout<<"Enter the Title of The Book You Want to Give Back: " ;

        string bookName ;

        bool check = true;

        while (check) {

            getline(cin , bookName);
            getline(cin , bookName);
            bookName=string_rearranger(bookName);
            cout <<endl;
            for(i = 0 ; i < BookCount ; i++){
                if((books[i].LastUser == users[UserNum].username)&&books[i].borrowable == false) {
                    if(books[i].title == bookName ){
                        check = false;
                        books[i].borrowable = true ;
                        books[i].dateGivenBack = todayDate();
                        cout<<"BOOK WAS SUCCESSFULLY RETURNED\n";
                        int t = stoi(users[UserNum].borrowed_books_count);
                        t--;
                        users[UserNum].borrowed_books_count = to_string(t) ;
                        refreshBooks(books);
                        refreshUsers(users);
                        reservationListApply(i);
                        break;
                    }
                }
            }
            if (check) {
                cout <<"Book Was Not Found\n";
                cout <<"Please Try Entering Book Title Again : ";
            }
        }
    }

    cout <<"----------------------------------------------------------------------------\n";

}

void registery() {

    int UserCount = user_count_line();

    users users[UserCount+1];

    insert_value_Users_class(users);


    //input username
    bool check_username = true;
    while (check_username) {
        cout <<"Enter Your Username: ";
        getline(cin, users[UserCount].username);
        getline(cin, users[UserCount].username);
        for (int i=0;i<UserCount;i++) {
            if (users[UserCount].username == users[i].username) {
                cout <<"username already taken :(\n";
                cout <<"please try again\n";
                check_username = true;
                break;
            } else {
                check_username = false;
            }
        }
    }

    cout <<endl;

    //input user password
    cout <<"Enter Your Password (password must be 8 charachters long)\n";
    cout <<"(Enter [0] to Assign a Random Password)\n";
    bool check_pass = false;
    while (!check_pass) {

        cout <<endl;

        cout <<"Your Password: ";

        getline(cin, users[UserCount].password);

        if (users[UserCount].password == "0") {
            users[UserCount].password = rand_pass_generator();
            cout <<endl;
            cout <<"Your Random Assigned Password: " <<users[UserCount].password <<endl;
        }

        if (!pass_length_check(users[UserCount].password)) {
            cout <<endl;
            cout <<"Password Must be 8 Charachters Long\n";
            cout <<"Try Again\n";
        } else {
            check_pass = true;
        }
        int pass_security_level;
        string answer;
        if (check_pass) {
            pass_security_level=pass_security_check(users[UserCount].password);
            cout <<endl;
            switch (pass_security_level) {
                case 1:
                    cout <<"Your Password is Not Strong at All! :(\n";
                    cout <<"Are You Sure You Want to Have This Password? (yes/no) ";
                    getline(cin, answer);
                    if (answer=="no") {
                        check_pass=false;
                    }
                    break;
                case 2:
                    cout <<"Your Password is Not Very Strong!\n\n";
                    cout <<"Are You Sure You Want To Have This Password? (yes/no) ";
                    getline(cin, answer);
                    if (answer=="no") {
                        check_pass=false;
                    }
                    break;
                case 3:
                    cout <<"Your Password is Semi-Strong\n";
                    break ;
                case 4:
                    cout <<"Your Password is Strong :)\n";
                    break;
                default:
                    cout <<"Your Password is Not Strong ! :(\n";
                    cout <<"Are You Sure You Want to Have This password? (yes/no) ";
                    getline(cin, answer);
                    if (answer=="no") {
                        check_pass=false;
                    }
                    break;
            }
        }

    }

    cout <<endl;

    //input first name and last name
    cout <<"Enter Firstname: ";
    getline(cin, users[UserCount].FirstName);

    cout<<endl;

    cout <<"Enter Lastname: ";
    getline(cin, users[UserCount].LastName);

    cout <<endl;

    cout <<"Enter Birth Date: ";
    cin >> users[UserCount].BirthDate;

    cout <<endl;

    cout <<"Enter Your Address: ";
    getline(cin, users[UserCount].address);
    getline(cin, users[UserCount].address);

    cout <<endl;

    cout <<"Enter Phone Number: ";
    getline(cin, users[UserCount].PhoneNumber);

    cout <<endl;

    users[UserCount].JoinDate = todayDate() ;

    users[UserCount].HaveNotif=false;

    cout <<"Choose Your Membership Type\n";
    cout <<"Enter [1] For Golden Membership\n";
    cout <<"Enter [2] For Regular Membership\n";
    int membership_type;
    cin >>membership_type;
    bool done = true;
    while (done) {
        switch (membership_type) {
        case 1:
            goldenUser = true ;
            users[UserCount].type = true;
            users[UserCount].MaxBow = "20";
            users[UserCount].TimeLimit = "1 month";
            done = false;
            break;
        case 2:
            users[UserCount].type = false;
            users[UserCount].MaxBow = "5";
            users[UserCount].TimeLimit = "1 week";
            done = false;
            break;
        default:
            cout <<"invalid input!";
        }
    }
    users[UserCount].borrowed_books_count = "0";
    users[UserCount].borrowed_book_list = "NULL";
    users[UserCount].total_latency = "0";
    users[UserCount].is_banned=false;

    fstream file;


    file.open("users.txt",ios::app);
    if (file.is_open()) {
        file <<users[UserCount].username <<',';
        file <<users[UserCount].password <<',';
        file <<users[UserCount].FirstName <<',';
        file <<users[UserCount].LastName<<',';
        file <<users[UserCount].BirthDate <<',';
        file <<users[UserCount].address <<',';
        file <<users[UserCount].PhoneNumber <<',';
        file <<users[UserCount].JoinDate<<',';
        file <<users[UserCount].HaveNotif <<',';
        if (users[UserCount].type) {
            file <<"golden,";
        } else {
            file <<"regular,";
        }
        file <<users[UserCount].MaxBow <<',';
        file <<users[UserCount].TimeLimit<<',';
        file <<users[UserCount].borrowed_books_count <<',';
        file <<users[UserCount].borrowed_book_list <<',';
        file <<users[UserCount].total_latency <<',';
        if (users[UserCount].is_banned) {
            file <<"banned";
        } else {
            file <<"not banned";
        }
        // file <<"not banned";
        file <<endl;
    }
    file.close();
    cout <<"SIGN UP SUCCESSFULL :)\n";
    UserNum = UserCount ;
    userDashboard();

}

string todayDate(){
    string date ;
    time_t now ;
    struct tm nowLocal ;
    now = time(NULL) ;
    nowLocal = *localtime(&now);
    int year = nowLocal.tm_year + 1900 ;
    int month = nowLocal.tm_mon + 1 ;
    int day = nowLocal.tm_mday ;
    date = to_string(year) + "/" + to_string(month) + "/" + to_string(day) ;
    return date ;
}

void login() {

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    string username;

    string password;

    int i;

    bool user_found = false;

    while (!user_found) {

        cout <<"Enter Username: ";
        cin >> username;

        for (i=0;i<UserCount;i++) {
            if (username==users[i].username) {
                user_found = true;
                break;
            }
        }

        cout <<endl;

        if (!user_found) {
            cout <<"username not found!\n";
            cout <<"please try again\n\n";
        }

    }

    bool pass_check = false;

    while (!pass_check) {

        cout <<"Enter Password: ";
        cin >>password;

        cout <<endl;

        if (password==users[i].password) {
            pass_check = true;
            UserNum=i;
            goldenUser = users[i].type ;
            if (!users[i].is_banned) {
                cout <<"LOGIN SUCCESSFULL :)\n\n";
                cout <<"Welcome " <<users[i].FirstName <<" " <<users[i].LastName <<endl <<endl;
                userDashboard();
            } else {
                cout <<"Sorry, you were banned by the admin :(\n";
                cout <<"try to behave better next time :)\n";
                cout <<"contact us at @JL_Biing or @the_mr_polarbear ";
                cout <<"(if you are narjes we can't do anything for you please don't call)\n";
            }

        }  else {
            cout <<"wrong password\n";
            cout <<"please try again\n\n";
        }

    }

}

void admin_login() {

    system("clear");

    string user;
    string pass;

    admin admins[2];

    insert_value_admin_class(admins);


    bool admin_found = false;

    int i;

    while (!admin_found) {

        cout <<"enter your username:";
        cin>>user;

        for (i=0;i<2;i++) {
            if (user==admins[i].username) {
                admin_found = true;
                break;
            }
        }

        if (!admin_found) {
            cout <<"admin not found!\n";
            cout <<"please try again\n";
        }

    }

    bool pass_check = false;
    cout <<endl;

    while (!pass_check) {

        cout <<"enter your password:";
        cin>>pass;

        if (pass==admins[i].password) {

            pass_check = true;
            cout <<"Welcome " <<admins[i].name <<" !\n";

            is_Admin = true ;
            adminDashboard();

        } else {

            cout <<"wrong password\n";
            cout <<"please try again\n";

        }

    }

}

void userDashboard (){

    cout <<"============================**You Entered the Dashboard**================================ \n\n";

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    if (users[UserNum].HaveNotif) {
        cout <<" ______________________________________________________ \n";
        cout <<"| You Have a Notif:                                    |\n";
        cout <<"|                                                      |\n";
        cout <<"| a Book That You Have Reserved is Available Right Now |\n";
        cout <<" -----------------------------------------------------\n\n";
        users[UserNum].HaveNotif = false;
        refreshUsers(users);
    }
    
    int n ;

    bool user_cmnd = true;

    bool logout=true;

    while(user_cmnd){

        cout <<"press [1] to choose your book  \t\t\t  ";
        cout <<"press [2] to view your personal information \n";
        cout <<"press [3] to edit your personal information  \t  ";
        cout <<"press [4] to give back the books you borrowed \n";
        cout <<"press [5] to extend reserve time  \t\t  ";
        cout <<"press [6] to log-out  \n";
        cout <<"press [7] to exit \n";

        cin>> n;

        switch(n){
            case 1 :
                system("clear");
                reserveBook();
                break ;
            case 2 :
                system("clear");
                personalInformation ();
                break ;
            case 3 :
                system("clear");
                editUser();
                break ;
            case 4 :
                system("clear");
                giveBackBook();
                break;
            case 5:
                system("clear");
                extened_reserve_time();
                break;
            case 6 :
                system("clear");
                Logout(&logout);
                if (!logout) {break;}
            case 7 :
                user_cmnd=false;
                break;
            default :
                cout<<"invalid number \n" ;
        }
    }
}

void user_options() {

    cout <<"\t\t\t\t     ______________________    \n";
    cout <<"\t\t\t\t    |  Press 1 to Sign up  |   \n";
    cout <<"\t\t\t\t    |  Press 2 to Login    |   \n";
    cout <<"\t\t\t\t     ----------------------    \n";
    int n;

    bool check = true;

    cout <<"\t\t\t\t\t\t";

    while (check) {

        cin >>n;

        switch (n) {
            case 1:
                system("clear");
                registery();
                check = false;
                break;
            case 2:
                system("clear");
                login();
                check = false;
                break;
            default:
                cout <<"invalid input!\n";
        }
    }
}

void personalInformation(){

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    int BookCount = Book_count_line();

    book books[BookCount];

    insert_value_Book_class(books);

    cout <<"Your Account Info:\n\n";

    cout <<"Username: "                 <<users[UserNum].username     <<endl;
    cout <<"Password: "                 <<users[UserNum].password     <<endl;
    cout <<"First Name: "               <<users[UserNum].FirstName    <<endl;
    cout <<"Last Name: "                <<users[UserNum].LastName     <<endl;
    cout <<"Address: "                  <<users[UserNum].address      <<endl;
    cout <<"Phone Number: "             <<users[UserNum].PhoneNumber  <<endl;
    cout <<"Join Date: "                <<users[UserNum].JoinDate     <<endl;
    cout <<"subscription Type: ";
    if (users[UserNum].type) {
        cout <<"golden\n";
    } else {
        cout <<"regular\n";
    }
    cout <<"Number of Borrrowed Books: " <<users[UserNum].borrowed_books_count  <<endl;
    cout <<"Borrowed Books: ";
    bool BorrowedBook = false;
    int k=1;
    int z = stoi(users[UserNum].borrowed_books_count);
    for (int i=0;i<BookCount;i++) {
        if (!books[i].borrowable) {
            if (books[i].LastUser==users[UserNum].username) {
                cout <<books[i].title;
                if (k != z) {
                    cout <<" , ";
                    k++;
                }
                BorrowedBook = true;
            }
        }
    }
    if (!BorrowedBook) {
        cout <<"you have not borrowed any books\n";
    } else {
        cout <<endl;
    }
    cout <<"========================================================================\n";

}

void editUser(){

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    int n;

    bool user_cmnd = true;

    while (user_cmnd) {

        cout <<"What Part of Your Account Do You Wish to Edit?\n";
        cout <<"[1]Password    \t     [2]Address \n";
        cout <<"[3]First Name  \t     [4]Last Name \n";
        cout <<"[5]Phone Number \n";

        cin >>n;

        cout <<endl;

        switch (n) {
            case 1:
                cout <<"Enter Your New Password: ";
                getline(cin,users[UserNum].password);
                getline(cin,users[UserNum].password);
                break;
            case 2:
                cout <<"Enter Your New Address:";
                getline(cin,users[UserNum].address);
                getline(cin,users[UserNum].address);
                break;
            case 3:
                cout <<"Enter Your New First name:";
                getline(cin,users[UserNum].FirstName);
                getline(cin,users[UserNum].FirstName);
                break;
            case 4:
                cout <<"Enter Your New Last Name:";
                getline(cin,users[UserNum].LastName);
                getline(cin,users[UserNum].LastName);
                break;
            case 5:
                cout <<"Enter Your New Phone Number:";
                getline(cin,users[UserNum].PhoneNumber);
                getline(cin,users[UserNum].PhoneNumber);
                break;
            default:
                cout <<"invalid input!";
        }

        cout <<endl;

        int m;
        cout <<"Do You Want to Keep Editing Your Profile ? \n";
        cout <<"[1]Yes  \t  [2]No \n";
        cin >>m;
        switch (m) {
            case 1:
                break;
            case 2:
                user_cmnd = false;
                break;
            default:
                cout <<"invalid input!";
        }

    }

    refreshUsers(users);

    cout <<endl;

    cout <<"PROFILE SUCCESSFULLY UPDATED :)\n";

    cout <<"----------------------------------------------------------------------------\n";

}

void reserveBook(){

    int UserCount = user_count_line();

    users users[UserCount];

    insert_value_Users_class(users);

    string maxBorowed ;

    int t;

    if(goldenUser){
       maxBorowed = "20" ;
    }else{
        maxBorowed = "5" ;
    }

    if( users[UserNum].borrowed_books_count == maxBorowed ){

        cout <<"You Have Reached the Borrow Limit \n";
        cout <<"You Can Not Reserve Any More Books \n";
    
    } else {

        int BookCount = Book_count_line();

        book books[BookCount];

        insert_value_Book_class(books);

        fstream file ;

        cout<< "Press [1] to Search for Books" << endl;
        cout<< "Press [2] to View the Books" << endl;
        int n , a , i;
        int result ;
        int ChosenBook;
        bool validNum = false  ;
        bool Valid_cmnd = false;
        while(!Valid_cmnd){

            cin>> n;

            switch (n) {
                case 1:
                    ChosenBook = book_search() ;
                    Valid_cmnd = true ;
                    break;
                case 2:
                    showBooks();
                    cout <<"Enter the Number of the Book You Want to Get: ";
                    cin>> ChosenBook;
                    ChosenBook--; //because users booklist starts from 1 not 0
                    cout <<endl;
                    Valid_cmnd = true ;
                    break;
                default:
                    cout <<"invalid number\n";
                    cout <<"please enter command again\n\n";
            }
        }

        if ( books[ChosenBook].borrowable == true){

            if(books[ChosenBook].regular == false && goldenUser == false ){
                cout<<"sorry :(( this book is just for our golden members\n\n" ;
            } else {

                books[ChosenBook].borrowable = false;
                books[ChosenBook].lastBoTime = todayDate();
                books[ChosenBook].LastUser = users[UserNum].username;

                t = stoi(users[UserNum].borrowed_books_count);
                t++ ;
                users[UserNum].borrowed_books_count = to_string(t) ;
                refreshUsers(users);
                refreshBooks(books);
                cout<<"BOOK WAS RESERVED SUCCESSFULLY! ENJOY ;) \n";

            }   

        } else {
            cout<<"The Book You Wish to Borrow is Not Currently Available\n\n";
            cout<<"Do You Want to Go on Reservation List ?"<< endl ;
            cout<<"[1]Yes \t [2]No \n" ;
            cin>> n ;
            bool validNum2 = false;
            while(!validNum2){
                if( n == 1){

                    t = stoi(users[UserNum].borrowed_books_count);
                    t++ ;
                    users[UserNum].borrowed_books_count = to_string(t) ;

                    reservationListWrite(ChosenBook);
                    validNum2 = true ;
                    refreshUsers(users);
                }else if ( n == 2){
                    userDashboard();
                    validNum2 = true ;

                }else{
                    cout<<"invalid number\n";
                }
            }

        }

    }

    cout <<"----------------------------------------------------------------------------\n";

}

int main () {

    show_options();

    bool check = true;
    int n;

    while (check) {

        cout <<"\t\t\t\t\t\t ";


        cin >>n;

        switch (n) {
            case 1 :

                admin_login ();
                check = false;
                break;

            case 2:

                user_options();
                check = false;
                break;

            default:
                cout <<"invalid number!" <<endl;

        }

    }

    cout <<"THANKS FOR USING OUR LIBRARY :)\n";
    cout <<"COME BACK SOON... :)\n";

    return 0;
}
