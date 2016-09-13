

#include "Carpentry.h"
#define orders 30
#define labour 60
#define SquareNum 5
#define StoolsNum 5
#define PlainNum 5
#define BookshelfNum 5
#define curvTableNum 5


void SquarTable::getSqTableDetails(){
//get square table details
    cout<<"\n\tEnter length "
        <<"\n\t> ";
    cin>>length;
    if (length >= 8)
        numLegs = 6;
    else
        numLegs = 4;

}

void Stool::getStoolDetails(){
//get stool diminsions
do {
    cout <<"\n\tEnter the radius of stool "
         <<"\n\t> ";
    cin >>radius;
    cout <<"\n\tEnter legs 1 or 4"
         <<"\n\t> ";
    cin>> numLegs;
}while(!(numLegs == 1 || numLegs == 4));
    if (numLegs == 1)
        stoolBase = radius / 2;
    else
        stoolBase == 0;

}


void menu::printTopOrBottom (char firstChar,char lastChar) {
// Print the first character, lines and the last character.

    cout << "\t\t" << char (firstChar) << setfill (char(196)) << setw (42) << char (lastChar) << "\n";
}

void menu::printLine (string text) {
// Print an | followed by the string, followed by |.

    cout << "\t\t" << char (179) << text << char (179) << "\n";
}
// Output the menu.
void menu::print () {
// Print the main menu options

    bool OK;

    cout << "\n\n";
    do {
        printTopOrBottom (218, 191);
        printLine ("              CARPENTRY COSTING          ");
        printLine ("     _________________________________   ");
        printLine ("                                         ");
        printLine ("                                         ");
        printLine (" 1  Plain Table        Curved Table    2 ");
        printLine ("                                         ");
        printLine (" 3  Coffee Table       Stool           4 ");
        printLine ("                                         ");
        printLine (" 5  Bookshelf          Collect Order   6 ");
        printLine ("                                         ");
        printLine (" 7  Exit                                 ");
        printLine ("                                         ");
        printTopOrBottom (192, 217);
        cout << "\n\n\t\t\t\t> ";
        cin >> choice;
        OK = validate (choice);
        if (!OK)
            cout << "\a\a\n\n\t" << choice << " is not a valid choice. Please reenter when prompted.\n\n\n";
       }
    while (!OK);
    }



bool menu::validate (char choice) {
// Accept choice and return true if valid, false if invalid.

    return (choice >= '1' && choice <= '7' || toupper(choice) =='L');
    }


void RectTable::getRecTableDetails(){
//get details for plain table
    cout <<"\n\tEnter length of table "
         <<"\n\t> ";
    cin >>length;
    cout <<"\n\tEnter width of table "
         <<"\n\t> ";
    cin >>width;
    if (length >= 8)
        numLegs = 6;
    else
        numLegs = 4;

}

void bookShelf::getBookDetails(){
//Get details for boookshelf
    cout <<"\n\tEnter height "
         <<"\n\t> ";
    cin >>height;
    cout <<"\n\tEnter width "
         <<"\n\t> ";
    cin >>width;
    cout <<"\n\tEnter width of sides "
         <<"\n\t> ";
    cin >>side;
    cout <<"\n\tEnter amount of shelves requried "
         <<"\n\t> ";
    cin >>shelves;
}

void furniture::placeOrder(){
//place customer order
    bool yes;
do{
    cout <<"\n\tDo you want to place this order Y/N \n"
         <<"\n\t> ";
    cin >>order;
    yes = valid(order);
     if (!yes)
            cout << "\a\a\n\n\t" << order << " is not a valid choice. Please re-enter when prompted.\n\n\n";




}while(!yes);
}

bool furniture::valid (char order) {
// Accept choice and return true if valid, false if invalid.

    return (toupper(order) == 'Y' || toupper(order) == 'N');
    }

void customer::getCustomerDetails(){
//If order is true, then get customer details

    custNo = CustomerNo;
    orderNo = CurrentOrders;

    cin.ignore();
    cout << "\n\tEnter your name "
         <<"\n\t> ";
    getline(cin, name, '\n');
    cout <<"\n\tEnter your address "
         <<"\n\t> ";
    getline(cin, address, '\n');

    cout <<"\n\tEnter your phone number  "
         <<"\n\t> ";
    cin >>phone;

}


void furniture::printOrder(){
//print order details to console

     cout << "\n\tCustomer Number: "<<"\t"<< CustomerNo <<"\n"
         << "\n\t--------------------------------------------"
         << "\n\n\tCustomer Name: "<<"\t\t"<<name
         << "\n\t--------------------------------------------"
         << "\n\n\tCustomer Address: "<<"\t"<<address
         << "\n\t--------------------------------------------"
         << "\n\n\tContact Number: "<<"\t"<<phone
         << "\n\t--------------------------------------------"
         << "\n\n\tItem Details: "<<"\t\t" <<itemDetail
         << "\n\t--------------------------------------------"
         << "\n\n\tCost before taxes: "<<"\t" <<cost
         << "\n\t--------------------------------------------"
         << "\n\n\tVat @ 21% "<<"\t\t" <<vat
         << "\n\t--------------------------------------------"
         << "\n\n\tTotal cost: "<<"\t\t" <<totalCost
         << "\n\t--------------------------------------------"
         << "\n\n\tEND OF FILE \n\n";



}


void furniture::AllOrders(){
//Store all orders to text file
    ofstream  AllOrders("CustomerOrders.txt", ios::app);
    AllOrders << "\n\tCustomer Number: "<<"\t"<< CustomerNo <<"\n"
              << "\n\t--------------------------------------------"
              << "\n\n\tCustomer Name: "<<"\t\t"<<name
              << "\n\t--------------------------------------------"
              << "\n\n\tCustomer Address: "<<"\t"<<address
              << "\n\t--------------------------------------------"
              << "\n\n\tContact Number: "<<"\t"<<phone
              << "\n\t--------------------------------------------"
              << "\n\n\tItem Details: "<<"\t\t" <<itemDetail
              << "\n\t--------------------------------------------"
              << "\n\n\tCost before taxes: "<<"\t" <<cost
              << "\n\t--------------------------------------------"
              << "\n\n\tVat @ 21% "<<"\t\t" <<vat
              << "\n\t--------------------------------------------"
              << "\n\n\tTotal cost: "<<"\t\t" <<totalCost
              << "\n\t--------------------------------------------"
              << "\n\n\tEND OF FILE \n\n";

    AllOrders.close();

}


