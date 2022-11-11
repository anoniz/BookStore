#include<iostream>
using namespace std;


class bookType { 
    string title, author, publisher;
    unsigned int ISBN, yop, price, stock;

    
public:
    bookType()
    {   
        title = author = publisher = "";
        ISBN = yop = price = stock = 0;
    }
    string setTitle(string);
    string setAuthor(string);
    string setPublisher(string);
    unsigned int setISBN(unsigned int);
    unsigned int setPrice(unsigned int);
    unsigned int inStock(unsigned int);
    unsigned int setYOP(unsigned int);
    unsigned int getISBN();
    unsigned int getStock();
    unsigned int getPrice();
    void showBook();
};

/////////////////////////////////////////////////////////////////////////////
// bookType Class Functions.......

string bookType::setTitle(string title)
{
    this->title = title;
    return title;
}

string bookType::setAuthor(string author)
{
    this->author = author;
    return author;
}
string bookType::setPublisher(string publisher)
{
    this->publisher = publisher;
    return publisher;
}
unsigned int bookType::setISBN(unsigned int isbn)
{
    ISBN = isbn;
    return isbn;
}

unsigned int bookType::setPrice(unsigned int price)
{
    this->price = price;
    return price;
}

unsigned int bookType::inStock(unsigned int stock)
{
    this->stock = stock;
    return stock;
}

unsigned int bookType::setYOP(unsigned int yop)
{
    this->yop = yop;
    return yop;
}

unsigned int bookType::getISBN()
{
    return ISBN;
}

unsigned int bookType::getStock()
{
    return stock;
}

unsigned int bookType::getPrice()
{
    return price;
}

void bookType::showBook()
{
    cout << "Title : " << title << endl;
    cout << "Author : " << author << endl;
    cout << "Published By : " << publisher << endl;
    cout << "Year of Publication : " << yop << endl;
    cout << "ISBN : " << ISBN << endl;
    cout << "Price : " << price << endl;
    cout << "in Stock : " << stock << endl;
}



bookType bookSetter(bookType *book)
{
    string title, author, publisher;
    unsigned int ISBN, yop, price, stock;

    cout << "please give title for the book \n";
    cin.ignore();
    getline(cin, title);
    book->setTitle(title);
    cout << "please give the author name \n";
    // cin.ignore();
    getline(cin, author);
    book->setAuthor(author);
    cout << "please give the publisher name \n";
    getline(cin, publisher);
    book->setPublisher(publisher);
    cout << "please give ISBN of the book \n";
    cin >> ISBN;
    book->setISBN(ISBN);
    cout << "please give the price of book \n";
    cin >> price;
    book->setPrice(price);
    cout << "please give year of publication....\n";
    cin >> yop;
    book->setYOP(yop);
    cout << "please give number of books in Stock you want! \n";
    cin >> stock;
    book->inStock(stock);
    cout << "The book has been set successfully! \n";
    return *book;
}
