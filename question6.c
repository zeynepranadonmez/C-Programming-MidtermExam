#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct XYZ {
    float a;
    float b;
    float c;
};

int main() {
    struct XYZ p1;
    struct XYZ p2;
    struct XYZ sc;
    double r = 3;

    p1.a = 1;
    p1.b = 1;
    p1.c = -11;
    p2.a = 2;
    p2.b = 2;
    p2.c = 224;
    sc.a = 3;
    sc.b = 3;
    sc.c = 3;
    raySphere(p1, p2, sc, r);
    return 0;
}

void raySphere(struct XYZ p1, struct XYZ p2, struct XYZ sc, double r) {

    double k, l, m; 
    double ll4km;
    struct XYZ dp, t1, t2;
    double mu1 = 0;
    double mu2 = 0;

    dp.a = p2.a - p1.a;
    dp.b = p2.b - p1.b;
    dp.c = p2.c - p1.c;
    k = dp.a * dp.a + dp.b * dp.b + dp.c * dp.c;
    l = 2 * (dp.a * (p1.a - sc.a) + dp.b * (p1.b - sc.b) + dp.c * (p1.c - sc.c));
    m = sc.a * sc.a + sc.b * sc.b + sc.c * sc.c;
    m += p1.a * p1.a + p1.b * p1.b + p1.c * p1.c;
    m -= 2 * (sc.a * p1.a + sc.b * p1.b + sc.c * p1.c);
    m -= r * r;
    ll4km = l * l - 4 * k * m;

    printf("Delta:  %lf", ll4km);
    printf("\n");
    mu1 = (-l + sqrt(ll4km)) / (2 * k);
    mu2 = (-l - sqrt(ll4km)) / (2 * k);


    if (ll4km > 0) {

        t1.a = (p2.a - p1.a) * mu1 + p1.a;
        t1.b = (p2.b - p1.b) * mu1 + p1.b;
        t1.c = (p2.c - p1.c) * mu1 + p1.c;

        t2.a = (p2.a - p1.a) * mu2 + p1.a;
        t2.b = (p2.b - p1.b) * mu2 + p1.b;
        t2.c = (p2.c - p1.c) * mu2 + p1.c;

        printf("\n");
        printf("teget nokta 1 => a: %lf , b:  %lf, c:  %lf", t1.a, t1.b, t1.c);
        printf("\n");
        printf("\n");
        printf("teget nokta 2 => a: %lf , b:  %lf, c:  %lf", t2.a, t2.b, t2.c);
        printf("\n");


    } 
else if (ll4km == 0) {
        printf("daireye teget cizgi");

    } 
else {
        printf("cizgi daire ile kesismiyor");
 } 
}
