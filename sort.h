#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <list>
#include <cmath>



using namespace std;

void createRandomArray(int arrTampung[], int banyak);
void cetakArray(int arrTampung[], int banyak);
void bubbleSort(int arrTampung[], int banyak);
void radixSort(int *arr, int n, int max);

void menuAwal();
void menuUtama();
void menuPilihan(int pilihan, int arrTampung[],int banyak);


#endif // SORT_H_INCLUDED
