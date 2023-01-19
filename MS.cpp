//
// Created by Saad on 9/26/2022.
//
#include <cstdlib>
#include <iostream>
#include "MS.h"
using namespace std;

void merge(int *A, int p, int q, int r, int flag, int printArray, int &ewc) {
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++) {
        L[i] = A[p + i - 1];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = A[q + j];
    }
    L[n1] = 999999;
    R[n2] = 999999;
    int i = 0;
    int j = 0;
    for(int k = p-1; k < r; k++) {
        if(L[i] <= R[j]) {
            if(L[i]!= 999999 && R[j]!= 999999) {
                ewc++;
                if(flag == 1) {
                    cout << "EWC: " << L[i] << " <= " << R[j] << "?" << endl;
                }
            }
            A[k] = L[i];
            i++;
            if(printArray==1) {
                cout << "A[" << p << ":" << r << "]:";
                for(int f = p-1; f < r; f++) {
                    cout << " " << A[f];
                }
                cout << endl;
            }
        } else {
            if(L[i]!= 999999 && R[j]!= 999999) {
                ewc++;
                if(flag == 1) {
                    cout << "EWC: " << L[i] << " <= " << R[j] << "?" << endl;
                }
            }
            A[k] = R[j];
            j++;
            if(printArray==1) {
                cout << "A[" << p << ":" << r << "]:";
                for(int f = p-1; f < r; f++) {
                    cout << " " << A[f];
                }
                cout << endl;
            }
        }
    }


}
void mergeSort(int *A, int p, int r, int flag, int printArray, int &ewc) {

    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p , q, flag, printArray, ewc);
        mergeSort(A, q+1, r, flag, printArray ,ewc );
        merge(A, p, q , r, flag, printArray, ewc);
    }
}
