void YenidenSiralama (int A[], int n)
{
	// k sonraki uygun olan pozisyonun dizinini saklar
	int k = 0;

	// her unsur (oge) icin yap
	for (int i = 0; i < n; i++)
	{
		// mevcut oge sifir degilse,ogeyi su konuma yerlestirin
		// dizideki bir sonraki bos olan konum
		if (A[i] != 0)
			A[k++] = A[i];
	}

	// tum 0’lari dizinin sonuna tasi (kalan endeksler,dizinler)
	for (int i = k; i < n; i++)
		A[i] = 0;
}

// dizide bulunan tüm o'lari dizinin sonuna tasi
int main(void)
{
	int A[] = { 8, 0, 9, 0, 0, 2, 5, 1, 4 };
	int n = sizeof(A) / sizeof(A[0]);

	yeniden_siralama(A, n);

	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);

	return 0;
}
