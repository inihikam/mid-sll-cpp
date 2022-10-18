#include "pustaka.h"

main(){

    //inisialisasi variable
    int choose, data1, data2, cari;

    //melakukan perulangan untuk menu menggunakan do while
    do{
        //clear terminal menggunakan system cls
        system("cls");
        cout << endl;
        cout << " =============================" << endl;
        cout << " =    SINGLE LINKED LIST     =" << endl;
        cout << " =============================" << endl;
        cout << " = 1. Insert Front           =" << endl;
        cout << " = 2. Insert Middle          =" << endl;
        cout << " = 3. Insert End             =" << endl;
        cout << " = 4. Delete Front           =" << endl;
        cout << " = 5. Delete Middle          =" << endl;
        cout << " = 6. Delete End             =" << endl;
        cout << " = 7. Search Data            =" << endl;
        cout << " = 8. Show Data              =" << endl;
        cout << " = 9. Clear                  =" << endl;
        cout << " = 10. Exit                  =" << endl;
        cout << " =============================" << endl;
        cout << " Select Menu : ";
        //memilih menu
        cin >> choose;

        //mengeksekusi kondisi menggunakan switch case
        switch (choose){
            case 1 : system("cls");{
                cout << "Enter first data = ";
                cin >> data1;
                cout << "Enter second data = ";
                cin >> data2;
                insertFront(data1, data2);
                break;
            }
            case 2 : system("cls");{
                cout << "Enter first data = ";
                cin >> data1;
                cout << "Enter second data = ";
                cin >> data2;
                insertMiddle(data1, data2);
                break;
            }
            case 3 : system("cls");{
                cout << "Enter first data = ";
                cin >> data1;
                cout << "Enter second data = ";
                cin >> data2;
                insertEnd(data1, data2);
                break;
            }
            case 4 : system("cls");{
                deleteFront();
                break;
            }
            case 5 : system("cls");{
                deleteMiddle();
                break;
            }
            case 6 : system("cls");{
                deleteEnd();
                break;
            }
            case 7 : system("cls");{
                searchData();
                break;
            }
            case 8 : system("cls");{
                showData();
                break;
            }
            case 9 : system("cls");{
                clearData();
                break;
            }
            case 10 : system("cls");{
                return 0;
                break;
            }
            default : system("cls");{
                cout << "Sorry, the option you chose doesn't exist.\n";
                break;
            }
        }
        getch();
    } while (choose != 10);
}