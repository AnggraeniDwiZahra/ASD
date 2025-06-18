#include <iostream>
#include <conio.h>
#include<stdlib.h>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET();

int PIL, F, R;
char Q[n];
char PILIHAN[10];

void Inisialisasi() {
    F = 0;
    R = -1;
}

void INSERT() {
    if (R < n - 1) {
        R++;
        cout << "Masukkan data (char): ";
        cin >> Q[R];
        cout << "Data '" << Q[R] << "' dimasukkan ke antrian." << endl;
    } else {
        cout << "Antrian penuh!" << endl;
    }
}

void DELETE() {
    if (F <= R) {
        cout << "Data '" << Q[F] << "' dihapus dari antrian." << endl;
        F++;
        if (F > R) {
            RESET();
        }
    } else {
        cout << "Antrian kosong!" << endl;
    }
}

void CETAKLAYAR() {
    if (F <= R) {
        cout << "Isi antrian: ";
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Antrian kosong!" << endl;
    }
}

void RESET() {
    F = 0;
    R = -1;
}

int main()
{
    Inisialisasi();
    do
    {
        cout << "QUEUE" << endl;
        cout << "===============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4.QUIT" << endl;
        cout << "PILIHAN : " << endl;
        cin >> PILIHAN;
        PIL=atoi(PILIHAN);

        switch (PIL)
        {
            case 1:
                INSERT ();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR ();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }
        cout << "press any key to continue" << endl;
        getch();
        system("cls");
    }
    while (PIL<4);
}
