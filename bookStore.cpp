
#include "bookStore.h"

#include <iostream>
#include <string>
using namespace std;


//////////////////////////////////////////////////////////////////////////
// Some Other Important Functions..

int memberWorks(bookStore *happyBooks,unsigned int &totalBooks, unsigned int &totalMembers)
{   int choise = 0;
    start : {
    cout << "What Do You Wanna Do?? \n";
    cout << "1. Buy A Book?? \n";
    cout << "2. See All Books? \n";
    cout << "3. Go To The Start Of Program? \n";
    cout << "Type appropriate numbers of above options... \n";
    cin>>choise;
    switch(choise) {
        case 1: {
            happyBooks->buyBooks(totalBooks,totalMembers);
            goto start;
        }
        break;
        case 2: {
            happyBooks->visitStore(totalBooks);
            goto start;
        }
        break;
        case 3: {
            return 1;
        }
        default:
        cout << " Sorry.. Given Option is not availabale \n";
        goto start;
        break;
    }
} 
    return 0; 
}



int main1(bookStore *happyBooks, memberType *tempMember, unsigned int &totalBooks, unsigned int &totalMember, unsigned int password)
{

    char isMember = 'N';
    unsigned int userPass = 0;
    bool isAdmin = false;
start:
{   cout<<endl<<endl;
    cout << "Are You a Member Of HappyBook Store? Type Y/N \n";
    cout << " Are you an Admin Here?? Type 'A' \n";
    cin >> isMember;
    switch (isMember)
    {
    case 'Y': {
        int val = memberWorks(happyBooks,totalBooks,totalMember);
        if(val) return 1;
        goto start;
    }
    break;
    case 'N':
    {
        cout << "Do You Want To Become Member? Type Y/N \n";
        cin >> isMember;
        switch (isMember)
        {
        case 'N':
        {
            cout << "Do You Wanna Buy Any Books or Just Visit Our BookStore? Type B/V \n";
            cin >> isMember;
            switch (isMember)
            {
            case 'V':
            {
                happyBooks->visitStore(totalBooks);
                goto start;
            }
            break;
            case 'B':
            {
                happyBooks->visitStore(totalBooks);
                if (totalBooks == 0) goto start;
                happyBooks->buyBooks(totalBooks, totalMember);
                goto start;
            }
             break;
            }
        }
        break;
        case 'Y':
        {
            memberType *member = new memberType;
            memberSetter(tempMember, totalMember);
            memberType addedMember = happyBooks->addMember(member, totalMember);
            addedMember.showMember();
            goto start;
        }
        break;
        }
    }
    break;
    case 'A':
    {
        cout << "Please Insert Admin Password... :) 1234 \n";
        cin >> userPass;
        if (userPass == password)
        {
            isAdmin = true;
            system("clear");
            userPass = happyBooks->adminWorks(happyBooks, totalBooks, totalMember);
            if (userPass) return 1;       
        }
         else {
            cout<<" Wrong Password..... \n";
            goto start;
         }
    }
    break;
    default:
        break;
    }
}

    return 0;
}

int main()
{
    system("clear");

    unsigned int totalBooks = 0, totalMember = 0;
    unsigned int password = 1234;
    bookStore *happyBooks = new bookStore;
    memberType *tempMember = new memberType;
    int val = 0;
    do
    {
        val = main1(happyBooks, tempMember, totalBooks, totalMember, password);

    } while (val);

    return 0;
}