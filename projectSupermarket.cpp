#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t-------------------------------------\n";
    cout << "\t\t\t\t                                     \n";
    cout << "\t\t\t\t        Supermarket Main Menu        \n";
    cout << "\t\t\t\t                                     \n";
    cout << "\t\t\t\t-------------------------------------\n";
    cout << "\t\t\t\t                                     \n";
    cout << "\t\t\t\t |      1. Administrator       |\n";
    cout << "\t\t\t\t |                             |\n";
    cout << "\t\t\t\t |      2. Buyer               |\n";
    cout << "\t\t\t\t |                             |\n";
    cout << "\t\t\t\t |      3. Exit                |\n";
    cout << "\t\t\t\t |                             |\n";
    cout << "\n\t\t\t Please Select : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email \n";
        cin >> email;
        cout << "\t\t\t Password \n";
        cin >> password;

        if ((email == "admin@gmail.com") && (password == "admin14"))
        {
            administrator();
        }
        else
        {
            cout << "Invalid Credntials";
        }
        break;

    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please select only from given options";
    }
    }
    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu";
    cout << "\n\t\t\t|--------1.Add Product--------------|";
    cout << "\n\t\t\t|                                   |";
    cout << "\n\t\t\t|                                   |";
    cout << "\n\t\t\t|--------2.Modify Product-----------|";
    cout << "\n\t\t\t|                                   |";
    cout << "\n\t\t\t|                                   |";
    cout << "\n\t\t\t|--------3.Delete Product-----------|";
    cout << "\n\t\t\t|                                   |";
    cout << "\n\t\t\t|                                   |";
    cout << "\n\t\t\t|--------4.Back to Main Menu--------|";
    cout << "\n\n\t Please enter your choice";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid choice";
    }
    goto m;
}

void shopping ::buyer()
{
m:
    int choice;
    cout << "\t\t\t   Buyer \n";
    cout << "\t\t\t-----------------\n";
    cout << "                         ";
    cout << "\t\t\t  1. Buy Product \n";
    cout << "                         ";
    cout << "\t\t\t  2. Go back     \n";
    cout << "\t\t\t Entre your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    dafault:
        cout << "Invalid choice ";
    }
    goto m;
}

void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t Add new product";
    cout << "\n\n\t Product code of thr product ";
    cin >> pcode;
    cout << "\n\n\t Name of thr product";
    cin >> pname;
    cout << "\n\n\t Price of the product";
    cin >> price;
    cout << "\n\n\t Discount on the product";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
            goto m;

        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Record Inserted";
}

void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code : ";
    cin >> pkey;

    data.open("database.txt, ios::in");
    if (!data)
    {
        cout << "\n\n File dose not exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the product :";
                cin >> n;
                cout << "\n\t\t Price :";
                cin >> p;
                cout << "\n\t\t Discount :";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited";
            }
            else
            {
                data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("databse1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found !";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code";
    cin >> pkey;

    data.open("databse.txt", ios::in);

    if (!data)
    {
        cout << "File dose not exists";
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted succesfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("databse1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n---------------------------------\n";
    cout << "ProNo\t\tname\t\tPrice\n";
    cout << "\n\n---------------------------------\n";
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
}

void shopping ::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t  RECEIPT";
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Database is empty";
    }

    else
    {
        data.close();
        list();

        cout << "\n-----------------------------------------------------------------------------\n";
        cout << "\n                                                                             \n";
        cout << "\n                          Please place your order                            \n";
        cout << "\n                                                                             \n";
        cout << "\n-----------------------------------------------------------------------------\n";

        do
        {
        m:
            cout << "\n\n Enter the product code";
            cin >> arrc[c];
            cout << "\n\n Enter the quantity of product";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code, please try again";
                    goto m;
                }
            }

            c++;
            cout << "\n\n Do you want to buy another product? if yes then press y else n";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t -----------------------RECEIPT-------------------------\n";
        cout << "\nProduct no \t Product name \t Product quantity \t Price \t Amount \t Amount with discount \n";
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n--------------------------------------------------------------------------------------";
    cout << "\n Total Amount : " << total;
}


int main()
{
    shopping Shop;
    Shop.menu();
}
