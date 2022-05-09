#include <stdio.h>
#include <stdlib.h>
 int SinirlayiciKutudakiNokta(float x1, float y1, float x2, float y2, float px, float py) {

    float sol, ust, sag, alt; // dogru segmenti icin sinirlayici kutu

    // sinirlayici kutu icin

    if (x1 < x2) {

        sol = x1;

        sag = x2;

    } else {

        sol = x2;

        sag = x1;

    }

    if (y1 < y2) {

        ust = y1;

        alt = y2;

    } else {

        ust = y1;

        alt = y2;

    }


    if ((px + 0.01) >= sol && (px - 0.01) <= sag &&

        (py + 0.01) >= ust && (py - 0.01) <= alt) {

        return 1;

    } else

        return 0;

}


int DogruKesisimi(float l1x1, float l1y1, float l1x2, float l1y2,

                     float l2x1, float l2y1, float l2x2, float l2y2,

                     float *m1, float *c1, float *m2, float *c2,

                     float *kesisim_X, float *kesisim_X_Y) {

    float dx, dy;


    dx = l1x2 - l1x1;

    dy = l1y2 - l1y1;


    *m1 = dy / dx;

    // y = mx + c

    // tuttuk c = y - mx

    *c1 = l1y1 - *m1 * l1x1; //  y2 ile ayni olan -  egim * x2



    dx = l2x2 - l2x1;

    dy = l2y2 - l2y1;


    *m2 = dy / dx;

    // y = mx + c

    // kesim c = y - mx

    *c2 = l2y1 - *m2 * l2x1; //  y2 ile ayni olan -egim * x2



    if ((*m1 - *m2) == 0)

        return 0;

    else {

        *kesisim_X = (*c2 - *c1) / (*m1 - *m2);

        *kesisim_X_Y = *m1 * *kesisim_X + *c1;

    }

}


int DogruSegmentKesisimi(float l1x1, float l1y1, float l1x2, float l1y2,

                            float l2x1, float l2y1, float l2x2, float l2y2,

                            float *m1, float *c1, float *m2, float *c2,

                            float *kesisim_X, float *kesisim_Y) {

    float dx, dy;


    dx = l1x2 - l1x1;

    dy = l1y2 - l1y1;


    *m1 = dy / dx;

    // y = mx + c

    // tuttuk c = y - mx

    *c1 = l1y1 - *m1 * l1x1; //  y2 ile ayni olan - egim * x2



    dx = l2x2 - l2x1;

    dy = l2y2 - l2y1;


    *m2 = dy / dx;

    // y = mx + c

    // tuttuk c = y - mx

    *c2 = l2y1 - *m2 * l2x1; // y2 ile ayni olan - egim* x2



    if ((*m1 - *m2) == 0)

        return 0;

    else {

        *kesisim_X = (*c2 - *c1) / (*m1 - *m2);

        *kesisim_Y = *m1 * *kesisim_X + *c1;

    }

    if (SinirlayiciKutudakiNokta(l1x1, l1y1, l1x2, l1y2, *kesisim_X, *kesisim_Y) == 1 &&

        SinirlayiciKutudakiNokta(l2x1, l2y1, l2x2, l2y2, *kesisim_X, *kesisim_Y) == 1)

        return 1;

    else

        return 0;

}


void main() {

    float m1, c1, m2, c2;

    float l1x1, l1y1, l1x2, l1y2;

    float l2x1, l2y1, l2x2, l2y2;

    float kesisim_X, kesisim_Y;

    int nRet;


    printf("iki dogru parcasinin kesisme noktasini bulmak icin program:\n");


    printf("1.dogrudaki x1 degerini girin - X1: ");

    scanf("%f", &l1x1);


    printf("1.dogrudaki y1 degerini girin - Y1: ");

    scanf("%f", &l1y1);


    printf("1.dogrudaki x2 degerini girin - X2: ");

    scanf("%f", &l1x2);


    printf("1.dogrudaki y2 degerini girin - Y2: ");

    scanf("%f", &l1y2);


    printf("2.dogrudaki x1 degerini girin - X1: ");

    scanf("%f", &l2x1);


    printf("2.dogrudaki y1 degerini girin - Y1: ");

    scanf("%f", &l2y1);


    printf("2.dogrudaki x2 degerini girin - X2: ");

    scanf("%f", &l2x2);


    printf("2.dogrudaki y2 degerini girin- Y2: ");

    scanf("%f", &l2y2);


    nRet = DogruSegmentKesisimi(l1x1, l1y1, l1x2, l1y2,

                                   l2x1, l2y1, l2x2, l2y2,

                                   &m1, &c1, &m2, &c2, &kesisim_X, &kesisim_Y);


    printf("Dogru 1 denklemi: Y = %.2fX %c %.2f\n", m1, (c1 < 0) ? ' ' : '+', c1);

    printf("Dogru 2 denklemi: Y = %.2fX %c %.2f\n", m2, (c2 < 0) ? ' ' : '+', c2);


    if (nRet == 0)

        printf("iki dogru parcasi birbiriyle kesismiyor");

    else

        printf("İki cizgi parcasi birbiriyle kesisiyor %.2f, %.2f", kesisim_X, kesisim_Y);


}
