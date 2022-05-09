#include <stdio.h>

int main()
{
    int x,a1,a2,c1,c2,s1,s2;
    
    printf("Birinci denklemi giriniz y1 = a1 * x + c1 \n"); //birinci dereceden denklem aldık
    printf("a1 degerini giriniz:\n");
    scanf("%d",&a1);
    printf("c1 degerini giriniz:\n");
    scanf("%d",&c1);
    
    printf("İkinci denklemi giriniz y2 = a2 * x + c2 \n");
    printf("a2 degerini giriniz:\n");
    scanf("%d",&a2);
    printf("c2 degerini giriniz:\n");
    scanf("%d",&c2);

    s1 = a1 - a2;
    s2 = c1 - c2;
    
    x = abs(s2) / abs(s1); // abs içerisindeki değerin mutlak değerini alır
    
    printf("iki dogrunun kesim noktası : %d 'dir.",x);
}
