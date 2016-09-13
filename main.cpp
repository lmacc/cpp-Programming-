/*Leslie McCarthy Object Oriented Programming Level 6 2015 Programmin Assignment*/
using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Methods.cpp"

furniture afurniture[orders];
SquarTable aSquare[SquareNum];
Stool aStool[StoolsNum];
RectTable PlainDining[PlainNum];
bookShelf aBook[BookshelfNum];
CurvDiningTable CurvedDining[curvTableNum];

int main(){

    do{
        mainMenu.print();
        switch(choice){
        case '1': PlainDining[plainTables].getRecTableDetails();
                  PlainDining[plainTables].CalcRectArea();
                  PlainDining[plainTables].CalcCost();
                  PlainDining[plainTables].outputCost();
                  PlainDining[plainTables].placeOrder();
                  if (order == 'y' || order == 'Y'){
                    PlainDining[plainTables].getCustomerDetails();
                    PlainDining[plainTables].itemDetail = "Plain Dining Table";
                    PlainDining[plainTables].printOrder();
                    PlainDining[plainTables].AllOrders();
                    PlainDining[plainTables++];
                    CurrentOrders++;//Keep account of all orders up to 30 orders max
                    CustomerNo++;//Customer is given a number when they place an order

                  }
                  break;

        case '2': CurvedDining[CurvedTables].getRecTableDetails();
                  CurvedDining[CurvedTables].CalcCurvArea();
                  CurvedDining[CurvedTables].CalcCost();
                  CurvedDining[CurvedTables].outputCost();
                  CurvedDining[CurvedTables].placeOrder();
                  if (order == 'y' || order == 'Y'){
                    CurvedDining[CurvedTables].getCustomerDetails();
                    CurvedDining[CurvedTables].itemDetail = "Curved Dining Table";
                    CurvedDining[CurvedTables].printOrder();
                    CurvedDining[CurvedTables].AllOrders();
                    CurvedDining[CurvedTables++];
                    CurrentOrders++;
                    CustomerNo++;

                  }
                  break;

        case '3': aSquare[SquarTables].getSqTableDetails();
                  aSquare[SquarTables].CalcSqArea();
                  aSquare[SquarTables].CalcCost();
                  aSquare[SquarTables].outputCost();
                  aSquare[SquarTables].placeOrder();
                  if (order == 'y' || order == 'Y'){
                    aSquare[SquarTables].getCustomerDetails();
                    aSquare[SquarTables].itemDetail = "Coffee Table";
                    aSquare[SquarTables].printOrder();
                    aSquare[SquarTables].AllOrders();
                    aSquare[SquarTables++];
                    CurrentOrders++;
                    CustomerNo++;

                  }
                  break;

        case '4': aStool[StoolsCount].getStoolDetails();
                  aStool[StoolsCount].CalcStArea();
                  aStool[StoolsCount].CalcCost();
                  aStool[StoolsCount].outputCost();
                  aStool[StoolsCount].placeOrder();
                  if (order == 'y' || order == 'Y'){
                    aStool[StoolsCount].getCustomerDetails();
                    aStool[StoolsCount].itemDetail = "Stool";
                    aStool[StoolsCount].printOrder();
                    aStool[StoolsCount].AllOrders();
                    aStool[StoolsCount++];
                    CurrentOrders++;
                    CustomerNo++;

                  }
                  break;

        case '5': aBook[bookShelves].getBookDetails();
                  aBook[bookShelves].CalcBkArea();
                  aBook[bookShelves].CalcCost();
                  aBook[bookShelves].outputCost();
                  aBook[bookShelves].placeOrder();
                  if (order == 'y' || order == 'Y'){
                    aBook[bookShelves].getCustomerDetails();
                    aBook[bookShelves].itemDetail = "Bookshelf";
                    aBook[bookShelves].printOrder();
                    aBook[bookShelves].AllOrders();
                    aBook[bookShelves++];
                    CurrentOrders++;
                    CustomerNo++;

                  }
                  break;

        case '6': afurniture[CustomerNo].collectOrder();//when a customer enters their order return their order details
                  break;

        case 'L': afurniture[CustomerNo].printAllOrders();//print all order placed by customers
                  break;

        }
    }while(choice != '7');

 return 0;
}


void furniture::collectOrder(){
//Output the customer order after customer enter their order number

    cout <<"\n\tEnter in your customer number "
         <<"\n\t> ";
    cin >>CustomerNo;

    bool found = false;

    while (!found) {
        for (unsigned short i = 0; i <= SquareNum - 1; i++)
            if (PlainDining[i].orderNo == CustomerNo){
                        PlainDining[i].printOrder();
                        found = true;
            }
        if (!found)
            for (unsigned short i = 0; i <= SquareNum - 1; i++)
            if (CurvedDining[i].orderNo == CustomerNo){
                        CurvedDining[i].printOrder();
                        found = true;
                    }
        if (!found)
            for (unsigned short i = 0; i <= SquareNum - 1; i++)
            if (aSquare[i].orderNo == CustomerNo){
                        aSquare[i].printOrder();
                        found = true;
            }

        if (!found)
            for (unsigned short i = 0; i <= SquareNum - 1; i++)
            if (aStool[i].orderNo == CustomerNo){
                        aStool[i].printOrder();
                        found = true;
            }

        if (!found)
            for (unsigned short i = 0; i <= SquareNum - 1; i++)
            if (aBook[i].orderNo == CustomerNo){
                        aBook[i].printOrder();
                        found = true;
            }


        }
}

void furniture::printAllOrders(){
//Print all orders taken and output total value

    for (unsigned short i = 0; i <= plainTables; i++)
    if (PlainDining[i].custNo != 0){
                PlainDining[i].printOrder();


        }

    for (unsigned short i = 0; i <= CurvedTables; i++)
    if (CurvedDining[i].custNo != 0){
                CurvedDining[i].printOrder();

        }

    for (unsigned short i = 0; i <= SquarTables; i++)
    if (aSquare[i].custNo != 0){
                aSquare[i].printOrder();

        }

    for (unsigned short i = 0; i <= StoolsCount; i++)
    if (aStool[i].custNo != 0){
                aStool[i].printOrder();

        }

    for (unsigned short i = 0; i <= bookShelves; i++)
    if (aBook[i].custNo != 0){
                 aBook[i].printOrder();

        }
}
