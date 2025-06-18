#include <iostream>
using namespace std;

#define max 5

struct stack
{
    int atas;
    int data[max];
};

stack Tumpuk;

int penuh()
{
    if(Tumpuk.atas == max-1)
        return 1;
    else
        return 0;
}

bool kosong()
{
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

void hapus() {
    if (!kosong()) {
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " dihapus " << endl;
        Tumpuk.atas--;
    } else {
        cout << "Stack kosong, tidak ada data yang bisa dihapus." << endl;
    }
}

void input (int data)
{
    if (kosong()==1)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas];
        cout << " Masuk Ke Stack ";
    }
    else if(penuh()==0)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas];
        cout << "Masuk Ke Stack ";
    } else {
        cout << "Tumpukan Penuh";
    }
}

void cetakStack() {
    if (kosong()) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Isi Stack dari atas ke bawah:\n";
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << Tumpuk.data[i] << endl;
        }
    }
}
    int main() {
    int PIL, nilai;
    Tumpuk.atas = -1;

    do {
        cout << "STACK" << endl;
        cout << "===============" << endl;
        cout << "1. PUSH (Input Data)" << endl;
        cout << "2. POP (Hapus Data)" << endl;
        cout << "3. CETAK STACK" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN: ";
        cin >> PIL;

        switch (PIL) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                input(nilai);
                break;
            case 2:
                hapus();
                break;
            case 3:
                cetakStack();
                break;
            default:
                cout << "TERIMA KASIH!" << endl;
                break;
        }

        cout << endl;
    } while (PIL < 4);

    return 0;
}
