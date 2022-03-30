// PEMANGGILAN LIBRARY
#include <stdio.h>
#include <time.h>
// PEMANGGILAN LIBRARY - END

// DEKLARASI VARIABEL GLOBAL
time_t t;
struct tm now;
// DEKLARASI VARIABEL GLOBAL - END

// FUNCTION UNTUK TAHUN
int year(){
    t = time(NULL);
    now = *localtime(&t);
    int x;
    x = now.tm_year + 1900;
    return x;
}
// FUNCTION UNTUK TAHUN - END

// FUNCTION UNTUK BULAN
int month(){
    t = time(NULL);
    now = *localtime(&t);
    int x;
    x = now.tm_mon + 1;
    return x;
}
// FUNCTION UNTUK BULAN - END

// FUNCTION UNTUK TANGGAL
int date(){
    t = time(NULL);
    now = *localtime(&t);
    int x;
    x = now.tm_mday;
    return x;
}
// FUNCTION UNTUK TANGGAL - END

// FUNCTION UNTUK JAM
int hour(){
    t = time(NULL);
    now = *localtime(&t);
    int x;
    x = now.tm_hour;
    return x;
}
// FUNCTION UNTUK JAM - END

// FUNCTION UNTUK MENIT
int minute(){
    t = time(NULL);
    now = *localtime(&t);
    int x;
    x = now.tm_min;
    return x;
}
// FUNCTION UNTUK MENIT - END

// FUNCTION UNTUK DETIK
int second(){
    t = time(NULL);
    now = *localtime(&t);
    int x;
    x = now.tm_sec;
    return x;
}
// FUNCTION UNTUK DETIK - END

