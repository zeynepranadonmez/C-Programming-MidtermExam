 void main()
{
    int dizi1[100], dizi2[100], dizi3[200];
    int s1, s2, s3;
    int i, j, k;


    /* printf("\n\Ayni boyuttaki iki matrisi birlestiren ve  buyukten kucuge siralayan program \n"); */

    printf("ilk dizide saklanacak sayilarin sayisini girin. :");
    scanf("%d",&s1);

    printf("dizideki sayilari girin:\n",s1);
    for(i=0;i<s1;i++)
    {
        printf("sayi - %d : ",i);
        scanf("%d",&dizi1[i]);
    }


    printf("ikinci dizide saklanacak sayilarin sayisini girin :");
    scanf("%d",&s2);

    printf("dizideki sayilari girin  :\n",s2);
    for(i=0;i<s2;i++)
    {
        printf("sayi - %d : ",i);
        scanf("%d",&dizi2[i]);
    }

     /* birleştirilmiş dizinin boyutu, ilk dizinin boyutu ve ikinci dizinin boyutudur */
    s3 = s1 + s2;
/*----------------- üçüncü diziye Ekle------------------------------------*/
    for(i=0;i<s1; i++)
    {
        dizi3[i] = dizi1[i];
    }
    for(j=0;j<s2; j++)
    {
        dizi3[i] = dizi2[j];
        i++;
    }
/*----------------- diziyi büyükten küçüğe sırala ---------------------------*/
    for(i=0;i<s3; i++)
    {
        for(k=0;k<s3-1;k++)
        {

            if(dizi3[k]<=dizi3[k+1])
            {
                j=dizi3[k+1];
                dizi3[k+1]=dizi3[k];
                dizi3[k]=j;
            }
        }
    }

/*--------------- birlesen diziyi (matrisi) yazdırır ------------------------------------*/
    printf("\n buyukten kucuge siralanmis dizi :\n");
    for(i=0; i<s3; i++)
    {
        printf("%d   ", dizi3[i]);
    }
    printf("\n\n");
}
