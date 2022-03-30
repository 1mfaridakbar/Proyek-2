// PEMANGGILAN LIBRARY
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
#include <iostream>
// PEMANGGILAN LIBRARY - END



// PEMANGGILAN FILE HEADER
#include "program.h"
#include "input.h"
#include "sys_time.h"
// PEMANGGILAN FILE HEADER - END

// DEKLARASI UNTUK WAKTU
	int tahun = year();		// FILE : sys_time.h --> system_time.cpp
	int bulan = month();	// FILE : sys_time.h --> system_time.cpp
	int tanggal = date();	// FILE : sys_time.h --> system_time.cpp
	int jam = hour();		// FILE : sys_time.h --> system_time.cpp
	int menit = minute();	// FILE : sys_time.h --> system_time.cpp
	int detik = second();	// FILE : sys_time.h --> system_time.cpp
// DEKLARASI UNTUK WAKTU

int homepage(){
	system("cls");
	// printf("selamat datang");
	main_input();
	return 0;
}


// FUNCTION UNTUK MENAMPILKAN HEADER APLIKASI
void header_aplikasi(){
	printf("|======================================================================================================================|\n");
	printf("|                                                                                                                      |\n");
	printf("|                                                      CB-LANG                                                         |\n");
	printf("|                                                  %d-%d-%d %d:%d                                                    |\n", tahun, bulan, tanggal, jam, menit);
	printf("|                                                                                                                      |\n");
	printf("|======================================================================================================================|\n");
}
// FUNCTION UNTUK MENAMPILKAN HEADER APLIKASI - END


// FUNCTION UNTUK MENAMPILKAN FOOTER APLIKASI
void footer_aplikasi(){
	printf("|======================================================================================================================|\n");
	printf("|                                               Copyright 2022 - CB-Lang                                               |\n");
	printf("|======================================================================================================================|\n");
}
// FUNCTION UNTUK MENAMPILKAN FOOTER APLIKASI - END


// FUNCTION UNTUK KELUAR DARI APLIKASI
int exit_aplikasi(){
	char pil_out;
	printf("Anda Yakin Akan Keluar Dari Aplikasi BradaSteam? (Y/N) : "); 
	pil_out = getche(); 

	system("cls");

    printf("\n"); 
    if ((pil_out == 'Y') || (pil_out == 'y'))
    {
    	// BYPASS TO EXIT APPLICATION
    	system("cls");
    	exit(1);
	}
	else{
		system("cls");
		main();
	}
}
// FUNCTION UNTUK KELUAR DARI APLIKASI - END

// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU
int salah_input_menu(){
	printf("Maaf Inputan Salah!\n");
	printf("Silahkan Tekan Apapun Untuk Melanjutkan...");
	getchar();

	system("cls");
}
// FUNCTION UNTUK ERROR HANDLING PADA INPUTAN PEMILIHAN MENU - END