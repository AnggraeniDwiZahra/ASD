#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

int main() {
    int menu;
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save = -1;

    randomize();

    do {
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> menu;

        if (menu == 1) {
            clrscr();
            printf("generating 100 number ...\n");
            for (int i = 0; i < 100; i++) {
                data[i] = random(100) + 1;
                printf("%d ", data[i]);
            }
            printf("\ndone.\n");

            cout << "\nMasukkan angka yang ingin dicari (sequential): ";
            cin >> cari;

            counter = 0;
            flag = 0;

            for (int i = 0; i < 100; i++) {
                if (data[i] == cari) {
                    counter++;
                    flag = 1;
                    save = i;
                }
            }

            if (flag == 1) {
                printf("Data ada, sebanyak %d!\n", counter);
                printf("pada indeks ke %d", save);
            } else {
                printf("Data tidak ada!\n");
            }

            system("pause");
        }

        else if (menu == 2) {
            clrscr();
            int n, kiri, kanan, tengah, temp, key;
            bool ketemu = false;

            cout << "masukkan jumlah data? ";
            cin >> n;
            int angka[n];
            for (int i = 0; i < n; i++) {
                cout << "Angka ke - [" << i << "] : ";
                cin >> angka[i];
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (angka[j] > angka[j + 1]) {
                        temp = angka[j];
                        angka[j] = angka[j + 1];
                        angka[j + 1] = temp;
                    }
                }
            }

            cout << "=============================================================\n";
            cout << "Data yang telah diurutkan adalah:\n";
            for (int i = 0; i < n; i++) {
                cout << angka[i] << " ";
            }
            cout << "\n===========================================================\n";
            cout << "Masukkan angka yang dicari: ";
            cin >> key;

            kiri = 0;
            kanan = n - 1;
            while (kiri <= kanan) {
                tengah = (kiri + kanan) / 2;
                if (key == angka[tengah]) {
                    ketemu = true;
                    break;
                } else if (key < angka[tengah]) {
                    kanan = tengah - 1;
                } else {
                    kiri = tengah + 1;
                }
            }

            if (ketemu == true) {
                cout << "Angka ditemukan! ";
            } else {
                cout << "Angka tidak ditemukan!";
            }

            system("pause");
        }

        else if (menu == 3) {
            clrscr();
            cout << "\n Perbedaan Sequential dan Binary Search\n";
            cout << "- Sequential Search: Merupakan metode pencarian data yang terurut ataupun tidak terurut.\n";
            cout << "  Pada metode ini, data dicari dengan membandingkan setiap elemen dalam array dengan nilai yang dicari secara berurutan.\n";
            cout << "  Kelebihan: Sederhana dan fleksibel, karena tidak membutuhkan data terurut  \n";
            cout << "  Kekurangan: Tidak efisien untuk data besar, karena waktu pencarian lambat tertutama ketika data tidak ditemukan \n";
            cout << "- Binary Search: Merupakan metode pencarian data dengan membagi dua bagian terus-menerus.\n";
            cout << "  Pada metode ini, data harus dalam keadaan terurut.\n";
            cout << "  Kelebihan: Waktu pencarian cepat dan efisien untuk data besar dan terurut \n";
            cout << "  Kekurangan: Data harus terurut, tidak efisien untuk data kecil, dan tidak cocok untuk daftar tertaut \n";
            system("pause");
        }

        else if (menu == 4) {
            cout << "Terima kasih telah menggunakan program.\n";
        }

        else {
            cout << "Pilihan tidak valid. Silakan pilih 1-4.\n";
            system("pause");
        }

    } while (menu != 4);

    return 0;
}
