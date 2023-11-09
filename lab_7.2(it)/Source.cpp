#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void CreateIterative(int** a, const int n, const int Low, const int High);
void PrintIterative(int** a, const int n);
void SeparateArraysIterative(int** a, const int n, int* aboveDiagonal, int* belowDiagonal);
void MinIterative(int* array, const int size, int& min);
void SwapMinMaxAndSumIterative(int** a, const int n);
void SwapElementsIterative(int** a, const int n, const int minAboveDiagonal, const int maxBelowDiagonal);

int main() {
    srand((unsigned)time(nullptr));

    int Low = 7;
    int High = 65;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    CreateIterative(a, n, Low, High);
    PrintIterative(a, n);

    int minAboveDiagonal = INT_MAX;
    int maxBelowDiagonal = INT_MIN;
    SeparateArraysIterative(a, n, &minAboveDiagonal, &maxBelowDiagonal);
    SwapMinMaxAndSumIterative(a, n);
    
    cout << "Matrix after swapping:" << endl;
    PrintIterative(a, n);

    int sum = minAboveDiagonal + maxBelowDiagonal;
    cout << "Sum of min above diagonal and max below diagonal elements: " << sum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateIterative(int** a, const int n, const int Low, const int High) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            a[row][col] = Low + rand() % (High - Low + 1);
        }
    }
}

void PrintIterative(int** a, const int n) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << setw(4) << a[row][col];
        }
        cout << endl;
    }
}

void SeparateArraysIterative(int** a, const int n, int* aboveDiagonal, int* belowDiagonal) {
    int aboveIndex = 0;
    int belowIndex = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row + col < n - 1) {
                aboveDiagonal[aboveIndex++] = a[row][col];
            } else if (row + col > n - 1) {
                belowDiagonal[belowIndex++] = a[row][col];
            }
        }
    }
}

void MinIterative(int* array, const int size, int& min) {
    for (int index = 0; index < size; index++) {
        if (array[index] < min)
            min = array[index];
    }
}

void SwapMinMaxAndSumIterative(int** a, const int n) {
    int minAboveDiagonal = INT_MAX;
    int maxBelowDiagonal = INT_MIN;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int element = a[row][col];
            if (row + col < n - 1)
                minAboveDiagonal = min(minAboveDiagonal, element);
            else if (row + col > n - 1)
                maxBelowDiagonal = max(maxBelowDiagonal, element);
        }
    }

    if (minAboveDiagonal != maxBelowDiagonal) {
        SwapElementsIterative(a, n, minAboveDiagonal, maxBelowDiagonal);
    }


    int sum = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            sum += a[row][col];
        }
    }

    cout << "Sum of min above diagonal and max below diagonal elements: " << sum << endl;
}


void SwapElementsIterative(int** a, const int n, const int minAboveDiagonal, const int maxBelowDiagonal) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < n - 1 && a[i][j] == minAboveDiagonal)
                a[i][j] = maxBelowDiagonal;
            else if (i + j > n - 1 && a[i][j] == maxBelowDiagonal)
                a[i][j] = minAboveDiagonal;
        }
    }
}
