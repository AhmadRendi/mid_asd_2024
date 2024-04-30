#include<iostream>

using namespace std;

struct Person
{
    string name, nim, fakultas;
};

Person tambahPerson(){
    Person p;
    cout << "Masukkan Nama : ";
    getline(cin, p.name);
    cout << "Masukan Fakultas : ";
    getline(cin, p.fakultas);
    cout << "Masukkan Stanbuk : ";
    getline(cin, p.nim);
    cout << "==============================" << endl;
    return p;
}

void tampilkanDataPerson(Person person[], int n){
    for (int i = 0; i < n; i++){
        if (!person[i].name.empty()){
            cout << "Nama \t\t: " << person[i].name << endl;
            cout << "Stanbuk \t: " << person[i].nim << endl;
            cout << "Fakultas \t: " << person[i].fakultas << endl;
            cout << "=============================================" << endl;
        }
    }
}

void sort(Person person[], int n){
    for (int i = 0; i < n; i++){
        for (int k = i + 1; k < n; k++){
            if(person[i].name > person[k].name){
                Person temp = person[k];
                person[k] = person[i];
                person[i] = temp;
            }
        }
    }
}

int main(){

    Person person[10];

    int lengthArrayPerson = sizeof(person) / sizeof(person[0]);

    Person p;

    int i = 0;
    string pil;

    do {

        person[i] = tambahPerson();

        cout << "Apakah Ingin Lanjut (y/n) : "; getline(cin, pil);
        if(pil == "n"){
            break;
        }else if (pil == "y"){
            i++;
            continue;
        }else {
            cout << "pilihan tidak tersedia" << endl;
            break;
        }
    }while (true);

    cout << "Sebelum Dilakukannya Sorting" << endl;
    cout << "=============================" << endl;
    tampilkanDataPerson(person, lengthArrayPerson);


    sort(person, lengthArrayPerson);

    cout << endl;
    cout << "===============================" << endl;
    cout << endl;
    cout << "Setelah di sort" << endl;

    cout << endl;
    cout << "===============================" << endl;

    tampilkanDataPerson(person, lengthArrayPerson);

    return 0;
}