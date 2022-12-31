#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cut (char* zaklad, char* zbytek, int min, int max) {
    int sum = 0;
    int zacatekPoslednihoCisla = 0, cislo = 0, pridani = 0;
    char* zacatky = (char*) calloc(sizeof(char), strlen(zaklad) + strlen(zbytek) + 1);
    strcpy(zacatky, zaklad);
    int delka = strlen(zaklad);
    printf("délka: %d\n", delka);
    zacatekPoslednihoCisla = delka;
    for(; zacatekPoslednihoCisla > 0 && zacatky[zacatekPoslednihoCisla] != ' '; zacatekPoslednihoCisla--); //najdu první mezeru odzadu

    cislo=atoi(zacatky+zacatekPoslednihoCisla);
    if(delka > 0 && (cislo < min || cislo > max)) {
        free(zacatky);
        return 0;
    }

    if(delka>0) {
        zacatky[delka] = ' ';
        delka++;
    }
    zacatekPoslednihoCisla = delka;
    for(; zacatekPoslednihoCisla > 0 && zacatky[zacatekPoslednihoCisla] != ' '; zacatekPoslednihoCisla--); //najdu první mezeru odzadu


    for (int i = 0; i < strlen(zbytek); i++) {
        printf("%d\n", strlen(zbytek));
        zacatky[i+delka] = zbytek[i];
        cislo = atoi(zacatky+zacatekPoslednihoCisla);
        if(strlen(zbytek+i)<2 && cislo >= min && cislo <= max) {
            printf("%s\n", zacatky);
            sum++;
        }
        sum += cut(zacatky, zbytek+i+1, min, max);

    }
    free(zacatky);
    return sum;
}
int main() {
    int n, vysledek;
    char zaklad[1] = {0};
    char text[102] = {0};
    int min, max;
    fgets(text, sizeof(text), stdin);
    n = strlen(text);
    if(text[n-1] == '\n') {
        text[n-1] = 0;
        n--;
    }
    //printf("%d",n);
    if (n < 2 || n > 100) {
        printf("Nespravny vstup.");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (!(text[i] >='0' && text[i] <='9')) {
            printf("Nespravny vstup.");
            return 0;
        }
    }
    printf("Min max\n");
    if(scanf(" %d %d", &min, &max) != 2 || min < 0 || max < min ) {
        printf("Nespravny vstup\n");
    }
    vysledek = cut(zaklad, text, min, max);
    printf("Pocet kombinaci: %d\n", vysledek);
    strstr
    return 0;
}
