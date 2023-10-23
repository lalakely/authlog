#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char dateStr[11] , cmonth[11]; 
    strcpy(dateStr , "2022-01-21");

    int year, month, day;
    sscanf(dateStr, "%d-%d-%d", &year, &month, &day);

    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    mktime(&date);

    char joursSemaine[7][20] = {"Alahady", "Alatsinainy", "Talata", "Alarobia", "Alakamisy", "Zoma", "Sabotsy"};
    
    switch (month) {
        case 1:  strcpy(cmonth,"Janoary");   break;
        case 2:  strcpy(cmonth,"Febroary");   break;
        case 3:  strcpy(cmonth,"Martsa");      break;
        case 4:  strcpy(cmonth,"Aprily");     break;
        case 5:  strcpy(cmonth,"May");       break;
        case 6:  strcpy(cmonth,"Jiona");      break;
        case 7:  strcpy(cmonth,"Jolay");   break;
        case 8:  strcpy(cmonth,"Aogositra");      break;
        case 9:  strcpy(cmonth,"Septambra"); break;
        case 10: strcpy(cmonth,"Octobra");   break;
        case 11: strcpy(cmonth,"Novambra");  break;
        case 12: strcpy(cmonth,"Desambra");  break;
    }

    printf("%s %d %s %d\n", joursSemaine[date.tm_wday], day , cmonth , year);

    return 0;
}
