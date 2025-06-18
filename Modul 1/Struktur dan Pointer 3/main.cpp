#include <iostream>

using namespace std;

struct Input
{
  char huruf;
  string kata;
  int angka;
};

int main () {
    Input data;

    cout<<"Masukkan sebuah huruf = ";
    cin >> data.huruf;

    cout<<"Masukkan sebuah kata =  ";
    cin>> data.kata;

    cout<<"Masukkan Angka = ";
    cin>> data.angka;

    // output data
    cout<<"Huruf yang Anda masukkan adalah " << data.huruf <<endl;
    cout<<"Kata yang Anda masukkan adalah " << data.kata << endl;
    cout<<"Angka yang Anda masukkan adalah " << data.angka << endl;

  return 0;
}
