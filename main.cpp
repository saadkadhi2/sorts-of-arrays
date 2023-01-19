#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include "IS.h"
#include "MS.h"
#include "QS.h"
using namespace std;

int main(int argc, char *argv[]){
    //declare variables
    void printUsage();
    FILE *fp;
    int *A;
    int printResult, printArray, n, scan;


    if(argc == 3) {
        int flag = stoi(string(argv[2]));
        if(flag == 0 || flag == 1) {
            if(strcmp(argv[1],"InsertionSort")==0) {
                //INSERTION SORT, opens file and take command line arguments and completes algorithm
                fp = fopen("INPUT.txt", "r");
                if(fp == NULL) {
                    fprintf(stderr, "Error: cannot open file INPUT.txt\n");
                    exit(1);
                }
                fscanf(fp, "%d", &n);
                printResult = n;
                fscanf(fp, "%d", &n);
                printArray = n;
                fscanf(fp, "%d", &n);
                A = (int *) malloc(n*sizeof(int));
                if (A == NULL) {
                    fprintf(stderr, "Error: cannot allocate memory\n");
                    exit (1);
                }
                for(int i = 0; i < n; i++) {
                    fscanf(fp, "%d", &scan);
                    A[i] = scan;
                }
                //ewc returned from method
                int ewc = insertionSort(A, 1, n, flag, printArray);
                if(printResult==1) {
                    printf("A[1:%d] after sorting:", n);
                    for(int i = 0; i < n; i++) {
                        cout << " " << A[i];
                    }
                    cout << endl;
                }
                cout << "Number of EWCs: " << ewc << endl;


            } else if(strcmp(argv[1],"MergeSort")==0) {
                //MERGE SORT
                fp = fopen("INPUT.txt", "r");
                if(fp == NULL) {
                    fprintf(stderr, "Error: cannot open file INPUT.txt\n");
                    exit(1);
                }
                fscanf(fp, "%d", &n);
                printResult = n;
                fscanf(fp, "%d", &n);
                printArray = n;
                fscanf(fp, "%d", &n);
                A = (int *) malloc(n*sizeof(int));
                if (A == NULL) {
                    fprintf(stderr, "Error: cannot allocate memory\n");
                    exit (1);
                }
                for(int i = 0; i < n; i++) {
                    fscanf(fp, "%d", &scan);
                    A[i] = scan;
                }
                //ewc returned as int from method
                int ewc = 0;
                mergeSort(A,1, n, flag, printArray, ewc);
                if(printResult==1) {
                    printf("A[1:%d] after sorting:", n);
                    for(int i = 0; i < n; i++) {
                        cout << " " << A[i];
                    }
                    cout << endl;
                }
                cout << "Number of EWCs: " << ewc << endl;

            } else if (strcmp(argv[1],"QuickSort")==0) {
                //QUICK SORT
                fp = fopen("INPUT.txt", "r");
                if(fp == NULL) {
                    fprintf(stderr, "Error: cannot open file INPUT.txt\n");
                    exit(1);
                }
                fscanf(fp, "%d", &n);
                printResult = n;
                fscanf(fp, "%d", &n);
                printArray = n;
                fscanf(fp, "%d", &n);
                A = (int *) malloc(n*sizeof(int));
                if (A == NULL) {
                    fprintf(stderr, "Error: cannot allocate memory\n");
                    exit (1);
                }
                for(int i = 0; i < n; i++) {
                    fscanf(fp, "%d", &scan);
                    A[i] = scan;
                }
                //pass ewc back by reference into main
                int ewc = 0;
                quickSort(A, 1, n, flag, printArray, ewc);
                if(printResult==1) {
                    printf("A[1:%d] after sorting:", n);
                    for(int i = 0; i < n; i++) {
                        cout << " " << A[i];
                    }
                    cout << endl;
                }
                cout << "Number of EWCs: " << ewc << endl;

            } else {
                printUsage();
                exit(1);
            }
        } else {
            printUsage();
            exit(1);
        }
    } else {
        printUsage();
        exit(1);
    }
    //free memory of array "A"
    free(A);
    return 0;

}
void printUsage() {
    printf("Usage: ./PJ1 alg flag\n       alg should be in {InsertionSort, MergeSort, QuickSort}\n       flag should be in {0, 1}\n");
}
