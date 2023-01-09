#include "sort.h"

void createRandomArray(int arrTampung[], int banyak){
    for (int i=0; i<banyak;i++){
        arrTampung[i] = rand()%10000+1;
    }
}

void cetakArray(int arrTampung[], int banyak){
    cout << "\n\nArray Anda adalah : " << endl;
    for (int i=0; i<banyak; i++){
        cout << arrTampung[i] << endl;
    }
}

void bubbleSort(int arrTampung[], int banyak){

    for (int i = banyak-1; i>=0; i--){
        for (int j=1; j<=i;j++){
            if (arrTampung[j-1] > arrTampung[j]){
                int temp = arrTampung[j-1];
                arrTampung[j-1] = arrTampung[j];
                arrTampung[j] = temp;
            }
        }
    }
}


void radixSort(int *arr, int n, int banyak) {
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];
   for(i = 0; i< banyak; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}

void menuAwal(){
    cout << "=============== BUBBLE SORT VS RADIX SORT ===============" << endl;
    cout << " Masukkan Banyak Indeks Array yang diinginkan (n) :  ";
}

void menuUtama(){
    cout << "   Kelompok 13 - Bubble Sort dan Radix Sort" << endl;
    cout << " " << endl;
    cout << "================BUBBLE SORT VS RADIX SORT================" << endl;
    cout << "|   Pilihan Menu yang tersedia :                        |" << endl;
    cout << "|   1. Tampilkan Array                                  |" << endl;
    cout << "|   2. Bubble Sort                                      |" << endl;
    cout << "|   3. Radix Sort                                       |" << endl;
    cout << "|   4. Reset isi Array                                  |" << endl;
    cout << "|   0. Keluar dari program                              |" << endl;
    cout << "=========================================================" << endl;
    cout << "    Pilihan Anda : ";
}

void menuPilihan(int pilihan, int arrTampung[],int banyak){
    switch (pilihan){
        case 1:
            cetakArray(arrTampung,banyak);
            break;
        case 2:{
            auto t1 = GetTickCount();
            bubbleSort(arrTampung,banyak);
            auto t2=GetTickCount();
            cout << endl << "Waktu eksekusi Bubble Sort dengan "<<banyak <<" angka acak = " << (float)(t2 - t1) << " ms";
            cout<<endl;
            }break;
        case 3:
            {
            auto t1 = GetTickCount();
            radixSort(arrTampung,0,banyak);
            auto t2=GetTickCount();
            cout << endl << "Waktu eksekusi Radix Sort dengan "<<banyak <<" angka acak = " << (float)(t2 - t1) << " ms";
            cout<<endl;
            }
            break;
        case 4:
            createRandomArray(arrTampung,banyak);
            break;
        case 0:
            break;
        default:
            cout << "Masukkan angka yang valid" << endl;
            break;
    }
}
