#include "bookType.h"
#include "memberType.h"
#include<iostream>
#define BSIZE 10
#define MSIZE 2
using namespace std;


class bookStore
{
    bookType *books[BSIZE];
    memberType *members[1];

public:
    bookType addBook(bookType *, unsigned int &totalBooks);
    memberType addMember(memberType *, unsigned int &totalMembers);
    bookType *getBooks();
    memberType *getMembers();
    void removeBook(unsigned int &totalBooks);
    void removeMember(unsigned int &totalMembers);
    void visitStore(unsigned int);
    void visitMembers(unsigned int);
    int buyBooks(unsigned int &totalBooks, unsigned int &totalMembers);
    int adminWorks(bookStore *happyBooks, unsigned int &totalBooks, unsigned int &totalMembers);
};


/////////////////////////////////////////////////////////////////////////////
// bookStore Class Functions.......

bookType bookStore::addBook(bookType *book, unsigned int &totalBooks)
{
    books[totalBooks] = new bookType;
    *books[totalBooks] = *book;
    totalBooks++;
    return *book;
}

bookType *bookStore::getBooks()
{
    return books[BSIZE];
}

memberType bookStore::addMember(memberType *member, unsigned int &totalMember)
{

    members[totalMember] = member;
    totalMember++;
    return *member;
}

memberType *bookStore::getMembers()
{
    return members[MSIZE];
}

void bookStore::removeBook(unsigned int &totalBooks)
{
    unsigned int isbn = 0, count = 0;
    bookType *temp = new bookType;
    cout << "Please Give The ISBN Of Book You Wanna Remove \n";
    cin >> isbn; cout<<endl;
    for (int i = 0; i < totalBooks; i++)
    {
        if (books[i]->getISBN() == isbn)
        {
            temp = books[totalBooks-1];
            books[totalBooks-1] = books[i];
            books[i] = temp;
            delete temp,books[totalBooks-1];
            temp = NULL;
            totalBooks--;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Couldn't Remove The Book.. Given ISBN Not Found..\n";
    }
    else
    {
        cout << "Removed Corresponding Book For Given ISBN....\n";
        cout<< "See All Books Again For Confirmation \n";
    }
}

void bookStore::removeMember(unsigned int &totalMembers)
{
    unsigned int id = 0, count = 0;
    memberType *temp = new memberType;
    cout << "Please Give The ID Of Member To Remove \n";
    cin >> id; cout<<endl;
    for (int i = 0; i < totalMembers; i++)
    {
        if (members[i]->getID() == id)
        {
            temp = members[i];
            members[i] = members[totalMembers-1];
            members[totalMembers-1] = temp;
            
            delete temp, members[totalMembers-1];
            temp = NULL;
            totalMembers--;
            count++;
            
        }
    }
    if (count == 0)
    {
        cout << "Couldn't Remove The Member.. Given ID Not Found..\n";
    }
    else
    {
        cout << "Removed Corresponding Member For Given ID....\n";
        cout<< " See All Members For Confirmation. \n";
    }
}

int bookStore::buyBooks(unsigned int &totalBooks, unsigned int &totalMembers)
{    if(totalBooks == 0) {
       cout<<" Sorry No Books Available \n"<<endl;
       return 1;
    } 
    unsigned int isbn = 0;
    cout<<endl<<endl;
    cout << "Please Give The ISBN Of The Book You Wanna Buy...\n";
    cin >> isbn;
    for (int i = 0; i < totalBooks; i++)
    {   if(books[i]->getISBN() != isbn)
         cout<<"Book Not Found \n";
        if (books[i]->getISBN() == isbn)
        {
            if (books[i]->getStock() == 0)
            {
                cout << "Sorry This Book is Not Availible in Stocks.. \n";
                break;
            }
            cout << "How Many Books You Wanna Buy? Type Number \n";
            cout << "We Only Have " << books[i]->getStock() << " Books Availibe..\n";
            cin >> isbn;
            if (books[i]->getStock() < isbn)
            {
                cout << "Sorry We Only Have " << books[i]->getStock() << " Books Availibe..\n";
            }
            else if (books[i]->getStock() >= isbn)
            {
                unsigned int price = books[i]->getPrice();
                unsigned int discount = (price / 10) / 2;
                int memberPrice = (price * isbn) - (discount * isbn);
                unsigned int normalPrice = price * isbn;
                unsigned int newStock = 0;

                unsigned int id;
                char isMember = 'N';
                cout << "Are You A Member Of HappyBook Store?? Type Y/N.. \n";
                cin >> isMember;
                if (isMember == 'Y')
                {
                    cout << "Please Give Your Member ID!! \n";
                    cin >> id;
                    for (int i = 0; i < totalMembers; i++)
                    {
                        if (members[i]->getID() == id)
                        {
                            if (members[i]->getBookBought() == 10)
                            {
                                price = members[i]->getAmountSpent();
                                discount = ((price / 10) / 2);
                                memberPrice = memberPrice - discount;
                                cout << " Its Your 11th BOOK So You Get " << discount << " Rupees Discount \n";
                            }
                        deposit:
                        {
                            cout << "Please Deposit " << memberPrice << " Rupess To Proceed \n";
                            cout << "Just Type " << memberPrice << " Here :) \n";
                            cin >> id;
                        }
                            if (id != memberPrice)
                                goto deposit;
                            else
                            {
                                newStock = books[i]->getStock() - isbn;
                                books[i]->inStock(newStock);
                                isbn = members[i]->getBookBought() + isbn;
                                members[i]->setBookBought(isbn);
                                members[i]->setAmountSpent(memberPrice);
                                cout << "Thanks For Buying Books From Our HappyBook Store \n";
                                cout << "For Confirmation Visit The Store Again And Check Stocks..\n";
                                cout<<endl<<endl;
                            }
                        }
                    }
                }
                else if (isMember == 'N')
                {
                pay:
                {
                    cout << " Please Deposit " << normalPrice << " Rupess To Procceed \n";
                    cout << "Just Type " << normalPrice << " Here :) \n";
                    cin >> id;
                }
                    if (id != normalPrice)
                        goto pay;
                    else
                    {
                        newStock = books[i]->getStock() - isbn;
                        books[i]->inStock(newStock);
                        cout << "Thanks For Buying Books From Our HappyBook Store \n";
                        cout << "For Confirmation Visit The Store Again And Check Stocks.. \n";
                        cout << endl
                             << endl;
                    }
                }
            }
        }
    }
        return 0;
}

void bookStore::visitStore(unsigned int totalBooks)
{
    cout<<endl<<endl;
    if (totalBooks == 0)
        cout << "Sorry No Books Availibale in BookStore...\n";
    else
        cout << "These Are All Books Availible in Our BookStore \n";
    for (int i = 0; i < totalBooks; i++)
    {
        cout << " [[" << endl;
        books[i]->showBook();
        cout << "            ]]" << endl;
    }
}

void bookStore::visitMembers(unsigned int totalMembers)
{
    cout << endl<<endl;
    if(totalMembers == 0)
    cout<<"No Members Yet In The BookStore \n";
    else cout<<"These Are All Members Of BookStore \n";
    for (int i = 0; i < totalMembers; i++)
    {
        cout << " {{ " << endl;
        cout<<members[i]<<endl;
        members[i]->showMember();
        cout << "                }} " << endl;
    }
}


int bookStore::adminWorks(bookStore *happyBooks, unsigned int &totalBooks, unsigned int &totalMembers)
{
start:
{   cout<<endl<<endl;
    cout << "What Do You Wanna Do?? \n";
    cout << "1. Add a new book to HappyBook Store? \n";
    cout << "2. Remove a book from HappyBook Store? \n";
    cout << "3. Add a new custom member to HappyBook Store? \n";
    cout << "4. Remove a member from HappyBook Store? \n";
    cout << "5. Add books to Stock?? \n";
    cout << "6. See All Available Books ? \n";
    cout << "7. See All Members Of HappyBook Store? \n";
    cout << "8. Go To The Start Of The Program...\n";
    cout << "Type appropriate numbers of above options... \n";
    unsigned int choise;
    cin >> choise;
    switch (choise)
    {
    case 1: {
       if(totalBooks == BSIZE) {
        cout<<"Can't Add More Books, Storage Full \n";
        cout<<"Please Contact The Administration... \n";
        cout<<endl<<endl; goto start;
    }
        bookType *temp = new bookType;
        bookSetter(temp);
        happyBooks->addBook(temp, totalBooks);
        delete temp; temp = NULL;
        happyBooks->visitStore(totalBooks);
        goto start;
    }
    break;
    case 2:
    {
        // cout<<" Sorry This Feature is Under Developement \n";
          happyBooks->removeBook(totalBooks);
        goto start;
    }
    break;
    case 3: {
    //    if(totalMembers == MSIZE) {
    //     cout<<"Can't Add More Members, Already Full \n";
    //     cout<<"Please Contact The Administration... \n";
    //     goto start;
    // }
        memberType *temp = new memberType;
        memberSetter(temp, totalMembers);
        happyBooks->addMember(temp, totalMembers);
        goto start;
    }
    break;
    case 4:
    {
        // cout<<" Sorry This Feature is Under Developement \n";
          happyBooks->removeMember(totalMembers);
        goto start;
    }
    break;
    case 5:
    {
         cout<<" Sorry This Feature is Under Developement \n";
         goto start;
    }
    break;
    case 6:
    {
        happyBooks->visitStore(totalBooks);
        goto start;
    }
    break;
    case 7:
    {
        happyBooks->visitMembers(totalMembers);
        goto start;
    }
    break;
    case 8:
    {
        return 1;
    }
    break;
    default:
        cout << " Sorry.. Given Option is not availabale \n";
        goto start;
        break;
    }
}
    return 0;
}
