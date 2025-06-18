#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string sortString(const string& str) {
    string sortedStr = str; // Salin string ke variabel baru
    sort(sortedStr.begin(), sortedStr.end()); // Mengurutkan karakter
    return sortedStr; // Mengembalikan string yang sudah diurutkan
}

string sortNIM(const string& nim) {
    string nimStr = nim; // Mengonversi NIM ke string
    sort(nimStr.begin(), nimStr.end()); // Mengurutkan karakter
    return nimStr; // Mengembalikan NIM yang sudah diurutkan
}

void insertionSort (vector<string>& data) {
    for (size_t i = 1; i < data.size(); i++ ) {
        string key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data [j];
            j--;
        }
        data[j+1] = key;
    }
}

void mergeSort (vector<string>& data, int left, int right) {
   if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);

    vector<string> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (data[i] < data[j]) {
            temp.push_back(data[i]);
            i++;
        } else {
            temp.push_back(data[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(data[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(data[j]);
        j++;
    }

    for (int k = left; k <= right; k++) {
        data[k] = temp[k - left];
    }
}

void shellSort(vector<string>& data) {
    int n = data.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i= gap; i < n; i++) {
            string temp = data [i];
            int j = i;
            while (j >= gap && data [j - gap] > temp) {
                data[j] = data [j - gap];
                j -= gap;
            }
            data[j] = temp;
        }
    }
}

void quickSort (vector<string>& data, int left, int right) {
    if (left >= right)
        return;

        string pivot = data[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (data[j] < pivot) {
                i++;
                swap(data[i], data[j]);
            }
        }
        swap(data[i + 1], data[right]);
        int p = i + 1;
        quickSort(data, left, p - 1);
        quickSort(data, p + 1, right);
}

void bubbleSort (vector<string>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void selectionSort(vector<string>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        swap(data[i], data[min_idx]);
    }
}

int main() {
    int pilihan;
    do {
    cout << "======================" << endl;
    cout << "|      SORTING       |" << endl;
    cout << "======================" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Shell Sort" << endl;
    cout << "4. Quick Sort" << endl;
    cout << "5. Bubble Sort" << endl;
    cout << "6. Selection Sort" << endl;
    cout << "-----------------------" << endl;
    cout << "Masukkan Pilihan: ";
    cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
                int n;
                string temp;
                vector <string> data;
                cout << "Masukkan Jumlah Data Nama: \n";
                cin >> n;
                cin.ignore();

                for (int i = 0; i < n;  i++) {
                cout << "Nama ke- " << i+1 << ": ";
                getline(cin, temp);
                data.push_back (sortString(temp));
                }

                switch (pilihan) {
                    case 1:
                    insertionSort(data);
                    break;

                    case 2:
                    mergeSort (data, 0, data.size()-1);
                    break;

                    case 3:
                    shellSort (data);
                    break;
                }

                cout << "Hasil setelah sorting: \n";
                for (const string& nama : data) {
                    cout << nama << endl;
                }
            } else if (pilihan >= 4 && pilihan <= 6) {
                int n;
                string temp;
                vector<string> data;
                cout << "Masukkan jumlah data NIM: ";
                cin >> n;
                cin.ignore();

            for (int i = 0; i < n; i++) {
                cout << "NIM ke-" << i+1 << ": ";
                getline (cin, temp);
                data.push_back(temp);
            }

            switch (pilihan) {
                case 4: quickSort(data, 0, data.size()-1);
                break;
                case 5: bubbleSort(data);
                break;
                case 6: selectionSort(data);
                break;
            }

            cout << "\nHasil sorting NIM:\n";
            for (const string& v : data) {
                cout << sortNIM(v) << endl; // Mengurutkan digit dalam NIM saat output
            }
        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid! Silahkan Coba Lagi \n";
        }
    } while (pilihan != 0);
    return 0;
}
