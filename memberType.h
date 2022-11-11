#include<iostream>
using namespace std;

class memberType
{
    unsigned int ID, bookBought, amountSpent;
    string name;

public:
    memberType()
    {
        name = "";
        ID = bookBought = amountSpent = 0;
    }
    string setName(string);
    unsigned int setID(unsigned int);
    unsigned int setBookBought(unsigned int);
    unsigned int setAmountSpent(unsigned int);
    unsigned int getID();
    unsigned int getBookBought();
    unsigned int getAmountSpent();
    void showMember();
};


////////////////////////////////////////////////////////////////////////////
// memberType Class Functions......

string memberType::setName(string name)
{
    this->name = name;
    return name;
}

unsigned int memberType::setID(unsigned int id)
{
    this->ID = id;
    return id;
}

unsigned int memberType::setBookBought(unsigned int bookBought)
{
    this->bookBought = bookBought;
    return bookBought;
}

unsigned int memberType::setAmountSpent(unsigned int amountSpent)
{
    this->amountSpent = amountSpent;
    return amountSpent;
}

unsigned int memberType::getID()
{
    return ID;
}

unsigned int memberType::getBookBought()
{
    return bookBought;
}

unsigned int memberType::getAmountSpent()
{
    return amountSpent;
}

void memberType::showMember()
{
    cout << "Name : " << name << endl;
    cout << "ID : " << ID << endl;
    cout << "bookBought : " << bookBought << endl;
    cout << "amountSpent : " << amountSpent << endl;
}




memberType memberSetter(memberType *member, unsigned int id)
{
    system("clear");
    static unsigned int ID; ID++;
    unsigned int bookBought = 0, amountSpent = 0;
    member->setID(ID);
    string name;
    cout << "Please Give Your Name \n";
    cin.ignore();
    getline(cin, name);
    member->setName(name);
    member->setBookBought(bookBought);
    member->setAmountSpent(amountSpent);
    cout << endl
         << "Please Deposit a $10 Membership Fess \n";
    cout << "I am Kidding Just Type '10' Here :-) \n";
    cin >> amountSpent;
    cout << "You Are Now A Memeber Of HappyBook Store, Your ID is " << id << endl;
    return *member;
}

