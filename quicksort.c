#include <stdio.h>
#include <stdlib.h>


void swap(int v[], int i, int j) {
    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void quicksort(int v[], int n) {
    int i, last;
    if (n <= 1)
        return;
    swap(v, 0, rand() % n);
    last = 1;
    for (i=1; i<n; i++)
        if (v[i] < v[0]) {
            swap(v, last, i);
            last++;
        }
    swap(v, 0, last-1);
    quicksort(v, last);
    quicksort(v+last+1, n-last-1);
}

int main() {
    int myarr[6] = {2, 3, 1, 4, 1, 6};
    int i;
    quicksort(myarr, 6);
    for (i=0; i<6; i++)
        printf("%d\n", myarr[i]);
    return 0;
}
