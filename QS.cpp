//
// Created by Saad on 9/26/2022.
//

#include <iostream>
#include "QS.h"
using namespace std;
//define methods
int partition(int *A, int p, int r, int flag, int printArray, int &ewc) {
    int x = A[r-1];
    int i = (p-2);
    for(int j = p-1; j < r-1; j++) {
        //increment ewc and pass back into main
        ewc++;
        //flag to show ewc or not
        if(flag == 1) {
            cout << "EWC: " << A[j] << " <= " << x << "?" << endl;
        }
        if(A[j] <= x) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            //print array
            if(printArray==1) {
                cout << "A[" << p << ":" << r << "]:";
                for(int f = p-1; f < r; f++) {
                    cout  << " " << A[f];
                }
                cout << endl;
            }
            A[j] = temp;
            //print array
            if(printArray==1) {
                cout << "A[" << p << ":" << r << "]:";
                for(int f = p-1; f < r; f++) {
                    cout  << " " << A[f];
                }
                cout << endl;
            }
        }
    }
    int temp = A[i+1];
    A[i+1] = A[r-1];
    //print array
    if(printArray==1) {
        cout << "A[" << p << ":" << r << "]:";
        for(int f = p-1; f < r; f++) {
            cout  << " " << A[f];
        }
        cout << endl;
    }
    A[r-1] = temp;
    //print array
    if(printArray==1) {
        cout << "A[" << p << ":" << r << "]:";
        for(int f = p-1; f < r; f++) {
            cout  << " " << A[f];
        }
        cout << endl;
    }
    return (i+1);

}
void quickSort(int *A, int p, int r, int flag, int printArray, int &ewc) {
    if((p-1) < (r-1)) {
        int q = partition(A, p, r, flag, printArray, ewc);
        quickSort(A, p, q, flag, printArray, ewc);
        quickSort(A, q+2, r, flag, printArray, ewc);
    }
}