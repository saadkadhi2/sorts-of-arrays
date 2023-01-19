//
// Created by Saad on 9/26/2022.
//

#include "IS.h"
#include <iostream>

using namespace std;
int insertionSort(int *A, int p, int r, int flag, int printArray) {
    int key;
    int k;
    int ewc = 0;
    for(int i = 1; i < r; i++) {
        int temp = ewc;
        key = A[i];
        k = i-1;


        while(k >= 0 && A[k] > key) {
            ewc++;
            if(flag == 1) {
                cout << "EWC: " << A[k] << " > " << key << "?" << endl;
            }
            A[k + 1] = A[k];
            if(printArray==1) {
                cout << "A[" << p << ":" << r << "]:";
                for(int j = 0; j < r; j++) {
                    cout << " " << A[j];
                }
                cout << endl;
            }
            k--;
        }
        if (ewc == temp) {
            ewc++;
            if(flag == 1) {
                cout << "EWC: " << A[k] << " > " << key << "?" << endl;
            }
        }


        A[k+1] = key;
        if(printArray==1) {
            cout << "A[" << p << ":" << r << "]:";
            for(int j = 0; j < r; j++) {
                cout << " " << A[j];
            }
            cout << endl;
        }
    }
    return ewc;
}



#include "IS.h"
