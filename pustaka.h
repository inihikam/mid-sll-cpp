#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//Membuat Constructor
struct Data{
    int angka1;
    int angka2;
    Data *next;
};

//Membuat Head dan Tail untuk Data
Data *head, *tail;

//Inisialisasi awal data
void init(){
    head == NULL;
    tail == NULL;
}

//pengecekan data
bool kosong(){
    if (head == NULL && tail == NULL){
        return true;
    } else {
        return false;
    }
}

//Masukkan data di depan
void insertFront(int x, int y){
    Data *baru;
    baru = new Data;
    //mengisi data ke node baru
    baru->angka1 = x;
    baru->angka2 = y;
    baru->next = NULL;
    //mengecek kondisi data pada memory
    if (kosong() == true){
        head = baru;
        tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
    system("cls");
    cout << " =============================" << endl;
    cout << " = Data entered successfully =" << endl;
    cout << " =============================" << endl;
}

void insertMiddle(int x, int y){
    int select;
    Data *baru;
    Data *bantu;
    baru = new Data;
    //mengisi data ke baru
    baru->angka1 = x;
    baru->angka2 = y;
    baru->next = NULL;
    //bantu diisi oleh head untuk memudahkan pencarian
    bantu = head;
    system("cls");
    cout << endl;
    cout << " =============================" << endl;
    cout << " =    SELECT MODE INSERT     =" << endl;
    cout << " =============================" << endl;
    cout << " = 1. Insert Before          =" << endl;
    cout << " = 2. Insert After           =" << endl;
    cout << " =============================" << endl;
    cout << " Select Menu : ";
    cin >> select;
    switch (select){
        //kondisi insert before
        case 1 : system("cls");{
            //menggunakan variabel baru untuk menjaga segmentation fault
            Data *prebantu;
            prebantu = bantu;
            bool find = false;
            if (kosong() == true){
                head = baru;
                tail = baru;
            } else {
                int before;
                cout << " =============================" << endl;
                cout << " = Input before data : ";
                cin >> before;
                do{
                    if (before == bantu->angka1 || before == bantu->angka2){
                        baru->next = prebantu->next;
                        prebantu->next = baru;
                        find = true;
                        system("cls");
                        cout << " =============================" << endl;
                        cout << " = Data entered successfully =" << endl;
                        cout << " =============================" << endl;
                    }
                    
                    //memposisikan prebantu sebelum bantu selanjutnya
                    prebantu = bantu;
                    bantu = bantu->next;
                } while (bantu != NULL);
            }

            //jika data sebelum yang dicari tidak ketemu
            if (find == false){
                system("cls");
                cout << "=====================================================" << endl;
                cout << "= Sorry, the data you are looking for is not found! =\n";
                cout << "=====================================================" << endl;
            }
            
            break;
        }        
        case 2 : system("cls");{
            bool find = false;
            if (kosong() == true){
                head = baru;
                tail = baru;
            } else {
                int after;
                cout << " =============================" << endl;
                cout << " = Input after data : ";
                cin >> after;
                do{
                    if (after == bantu->angka1 || after == bantu->angka2){
                        baru->next = bantu->next;
                        bantu->next = baru;
                        find = true;
                        system("cls");
                        cout << " =============================" << endl;
                        cout << " = Data entered successfully =" << endl;
                        cout << " =============================" << endl;
                    }
                    
                    bantu = bantu->next;
                } while (bantu != NULL);

            }
            //jika data setelah yang dicari tidak ketemu
            if (find == false){
                system("cls");
                cout << "=====================================================" << endl;
                cout << "= Sorry, the data you are looking for is not found! =\n";
                cout << "=====================================================" << endl;
            }
            
            break;
        }        
        default : system("cls");{
            cout << "Sorry, the option you chose doesn't exist.\n";
            break;
        }
    }
}

void insertEnd(int x, int y){
    Data *baru;
    baru = new Data;
    baru->angka1 = x;
    baru->angka2 = y;
    baru->next = NULL;
    if (kosong() == true){
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    system("cls");
    cout << " =============================" << endl;
    cout << " = Data entered successfully =" << endl;
    cout << " =============================" << endl;
}

void deleteFront(){
    Data *hapus;
    int data1, data2;
    //Pengecekan data kosong atau tidak
    if (kosong() == true){
        system("cls");
        cout << " =============================" << endl;
        cout << " =       Data is empty       =" << endl;
        cout << " =============================" << endl;
    } else {
        //pengecekan apakah head sama dengan tail (Data hanya ada satu)
        if (head == tail){
            hapus = head;
            data1 = hapus->angka1;
            data2 = hapus->angka2;
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            hapus = head;
            head = hapus->next;
            hapus->next = NULL;
            data1 = hapus->angka1;
            data2 = hapus->angka2;
            delete hapus;
        }
        //Mengoutputkan data yang terhapus
        cout << " ================================== " << endl;
        cout << " = Data " << data1 << " & " << data2 << " deleted successfully = \n";
        cout << " ================================== " << endl;
    }
    
}

void deleteMiddle(){
    int dataHapus, data1, data2;
    Data *hapus;
    Data *prehapus;
    bool success = false;
    //pengecekan data kosong atau tidak
    if (kosong() == true){
        system("cls");
        cout << " =============================" << endl;
        cout << " =       Data is empty       =" << endl;
        cout << " =============================" << endl;
    } else {
        //pengecekan apakah head sama dengan tail (Data hanya ada satu)
        if (head == tail){
            hapus = head;
            data1 = hapus->angka1;
            data2 = hapus->angka2;
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            hapus = head;
            prehapus = hapus;
            cout << " =============================================" << endl;
            cout << " = Enter the data that you want to delete : ";
            cin >> dataHapus;
            do{
                if (dataHapus == hapus->angka1 || dataHapus == hapus->angka2){
                    prehapus->next = hapus->next;
                    data1 = hapus->angka1;
                    data2 = hapus->angka2;
                    success = true;
                    delete hapus;
                }
                prehapus = hapus;
                hapus = hapus->next;
            } while (hapus != NULL);
        }
        //Mengoutputkan data yang terhapus
        cout << " ================================== " << endl;
        cout << " = Data " << data1 << " & " << data2 << " deleted successfully = \n";
        cout << " ================================== " << endl;
    }

    if (success == false){
        system("cls");
        cout << "=====================================================" << endl;
        cout << "= Sorry, the data you are looking for is not found! =\n";
        cout << "=====================================================" << endl;
    }
       
}

void deleteEnd(){
    Data *hapus;
    Data *prehapus;
    int data1, data2;
    //pengecekan apakah data hanya ada 1
    if (kosong() == true){
        system("cls");
        cout << " =============================" << endl;
        cout << " =       Data is empty       =" << endl;
        cout << " =============================" << endl;
    } else {
        //pengecekan apakah head sama dengan tail (Data hanya ada satu)
        if (head == tail){
            hapus = head;
            data1 = hapus->angka1;
            data2 = hapus->angka2;
            head = NULL;
            tail = NULL;
            //Mengoutputkan data yang terhapus
            cout << " ================================== " << endl;
            cout << " = Data " << data1 << " & " << data2 << " deleted successfully = \n";
            cout << " ================================== " << endl;
            delete hapus;
        } else {
            hapus = head;
            // do{
            //     if (hapus->next == NULL){
                    
            //     }
                
            //     prehapus = hapus;
            //     hapus = hapus->next
            // } while (hapus != NULL);
            while (hapus->next != NULL){
                prehapus = hapus;
                hapus = hapus->next;
            }
            prehapus->next = NULL;
            tail = prehapus;
            cout << " ================================== " << endl;
            cout << " = Data " << hapus->angka1 << " & " << hapus->angka2 << " deleted successfully = \n";
            cout << " ================================== " << endl;
            delete hapus;
        }
    }
}

void searchData(){
    Data *list;
    list = head;
    int search;
    if (kosong() == true){
        system("cls");
        cout << " =============================" << endl;
        cout << " =       Data is empty       =" << endl;
        cout << " =============================" << endl;
    } else {
        cout << " =============================================" << endl;
        cout << " = Enter the data that you want to search : ";
        cin >> search;
        system("cls");
        cout << " =============================" << endl;
        do{
            if (list->angka1 == search || list->angka2 == search){
                cout << " = Data " << list->angka1 << " " << list->angka2 << " was found        =\n";
            }
            
            list = list->next;
        } while (list != NULL);
        cout << " =============================" << endl;
    }
}

void showData(){
    Data *list;
    list = head;
    int i = 1;
    if (kosong() == true){
        system("cls");
        cout << " =============================" << endl;
        cout << " =       Data is empty       =" << endl;
        cout << " =============================" << endl;
    } else {
        system("cls");
        cout << " =============================" << endl;
        while (list != NULL){
            cout << " = " << i << ". " << list->angka1 << " " << list->angka2 << "\n";
            list = list->next;
            i++;
        }
        cout << " =============================" << endl;
    }
}

void clearData(){
    Data *list;
    Data *hapus;
    list = head;
    do{
        hapus = list;
        list = list->next;
        delete hapus;
    } while (list != NULL);
    
    head = NULL;
    tail = NULL;
    system("cls");
    cout << " ======================================== " << endl;
    cout << " =  Data has been cleared successfully  = " << endl;
    cout << " ======================================== " << endl;
}