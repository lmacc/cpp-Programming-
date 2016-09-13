
using namespace std;
#define labour 60

char choice;
char order;
unsigned short CustomerNo = 0;
unsigned short CurrentOrders = 0;




class menu{
public:
    void print ();
    void printTopOrBottom (char, char);
    void printLine (string);
    bool validate (char);
}mainMenu;

class customer{//Base class customer
protected:
    string name, address, phone;
    unsigned short custNo, orderNo;

public:
    void getCustomerDetails();
    void printCustomerDetails();
};

class furniture: public customer{
protected:
    string paint, varnish;
    float vat, cost, totalCost, net, assets, area;
    unsigned short numLegs;
public:

    furniture(){numLegs = 0;};
    string itemDetail;
    void CalcCost(){cost = area * 15 + numLegs * 20 + area * 2 + numLegs + labour; vat = cost * .21; totalCost = vat + cost; assets+= totalCost;};
    void outputCost(){cout <<"\n\tCost\t\t"<< cost <<"\n\tvat @ 21%\t"<<vat << "\n\tTotal Cost\t"<<totalCost<<"\n\n";};
    void printOrder();
    void placeOrder();
    void collectOrder();
    bool valid (char);
    void AllOrders();
    void printAllOrders();

};


unsigned short SquarTables;
class SquarTable: virtual public furniture{//Class Square table will inherit form furniture
protected:
    float length;

public:
    void getSqTableDetails();
    void CalcSqArea(){area = length * length;};

};//Square Array with five elements


class Stool: virtual public furniture {//Class stool will inherit from furniture
protected:
    float  radius, stoolBase;

public:
    void getStoolDetails();
    void CalcStArea(){area = 3.14 * (radius * radius) * (stoolBase);};

};
unsigned short StoolsCount = 0;


class RectTable: public SquarTable{
protected:
    float width;

public:

    void getRecTableDetails();
    void CalcRectArea(){area = width * length;};

};
unsigned short plainTables = 0;


class bookShelf: public RectTable{
protected:
    float height, side;
    unsigned short shelves;
public:

    void getBookDetails();
    void CalcBkArea(){area = (height * width) + (side * height * 2) + width * side * shelves;};

};
unsigned short bookShelves = 0;


class CurvDiningTable: public bookShelf, public Stool{

public:
   // radius = width / 2;
    void CalcCurvArea(){area = (length * width) + 3.14 * ((width/2) * (width/2));};
};
unsigned short CurvedTables = 0;
