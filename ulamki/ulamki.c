#include <stdio.h>
#include <stdlib.h>
#include "ulamki.h"

int nwd(int a, int b){
    if(a<0)
        a*=-1;
    if(b<0)
        b*=-1;
    if(a>b){
        int c=a;
        a=b;
        b=c;
    }
    while(b>0){
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}

ulamek nowy_ulamek(int a, int b){
    ulamek c;
    if(b==0){
        printf("DZIELENIE PRZEZ ZERO!\n");
        b++;
    }
    if(b<0){
        a*=-1;
        b*=-1;
    }
    c.l=a;
    c.m=b;
    int x=nwd(c.l,c.m);
    c.l/=x;
    c.m/=x;
    return c;
}

ulamek dodaj_ulamek(ulamek a, ulamek b){
    ulamek c;
    c.l=a.l*b.m + a.m*b.l;
    c.m=a.m*b.m;
    int x=nwd(c.l,c.m);
    c.l/=x;
    c.m/=x;
    return c;
}

ulamek odejmij_ulamek(ulamek a, ulamek b){
    ulamek c;
    c.l=b.l*-1;
    c.m=b.m;
    return dodaj_ulamek(a,c);
}

ulamek pomnoz_ulamek(ulamek a, ulamek b){
    ulamek c;
    c.l=a.l*b.l;
    c.m=a.m*b.m;
    int x=nwd(c.l,c.m);
    c.l/=x;
    c.m/=x;
    return c;
}

ulamek podziel_ulamek(ulamek a, ulamek b){
    ulamek c;
    c.l=b.m;
    c.m=b.l;
    return pomnoz_ulamek(a,c);
}

void wypisz_ulamek(ulamek a){
    printf("%d/%d\n",a.l,a.m);
}

