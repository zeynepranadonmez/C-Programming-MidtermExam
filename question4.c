#include <stdio.h>
#include <stdlib.h>
void sort(int dizi1[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (dizi1[j] > dizi1[j + 1]) {
                temp = dizi1[j];
                dizi1[j] = dizi1[j + 1];
                dizi1[j + 1] = temp;
            }
        }
    }
    return;
}

  void diziyiDuzenle(int dizi1[], int n) {
    sort(dizi1, n);
    int tempDizi[n];
    int DiziIndex = 0;
    for (int i = 0, j = n - 1; i <= n / 2 || j > n / 2; i++, j--) {
        tempDizi[DiziIndex] = dizi1[i];
        DiziIndex++;
        tempDizi[DiziIndex] = dizi1[j];
        DiziIndex++;
    }
    for (int i = 0; i < n; i++) { dizi1[i] = tempDizi[i]; }
}

int main() {
    int dizi1[] = {6, 8, 4, 1, 3, 7, 9, 2, 5};
    int n = sizeof(dizi1) / sizeof(dizi1[0]);
    int i = 0;
    //------------- orjinal diziyi yazdiralim ------------------
    printf("Verilen dizi :  \n");
    for (i = 0; i < n; i++) {
        printf("%d  ",dizi1[i]);
    }
    printf("\n");
//-----------------------------------------------------------
    printf("Yeni dizi:  \n");
    diziyiDuzenle(dizi1, n);
    for (int i = 0; i < n; i++)
        printf("%d ", dizi1[i]);
    return 0;
}