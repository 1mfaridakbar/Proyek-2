// PEMANGGILAN LIBRARY
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
#include <iostream>
// PEMANGGILAN LIBRARY - END

// PEMANGGILAN HEADER FILE
#include "program.h"
// PEMANGGILAN HEADER FILE - END

int main() {
	// DEKLARASI VARIABEL LOKAL
	int menu;

	// LIST MENU APLIKASI
	system("cls");
	header_aplikasi(); // HEADER APLIKASI

	printf("| Silahkan Pilih Menu dibawah ini :                                                                                    |\n");
	printf("|======================================================================================================================|\n");
	printf("| 1. Mulai Aplikasi                                                                                                    |\n");
	printf("| 2. Keluar Aplikasi                                                                                                   |\n");
	printf("|                                                                                                                      |\n");

	footer_aplikasi(); // FOOTER APLIKASI
    
    printf("\n\n");
    printf("Masukkan pilihan : "); // DI ISI DENGAN '1' ATAU '2', SELAIN DARI ITU MAKA PROGRAM AKAN MENGELUARKAN NOTIFIKASI ALERT
	scanf("%d", &menu);

	system("cls");
	
	// SISTEM DIRECT TO PAGE BERKAITAN BERDASARKAN INPUTAN YANG DIPILIH OLEH USER
    switch (menu) { 
        case 1:
			main_loading(); 	// REDIRECT KE main_loading() UNTUK MULAI SISTEM
			break;
		case 2:
		    exit_aplikasi(); 	// REDIRECT KE exit_aplikasi() UNTUK KELUAR DARI APLIKASI
			break;
	 	default:
	 		salah_input_menu(); // REDIRECT KE salah_input_menu() UNTUK HANDLER PADA SAAT SALAH INPUT
	 		main();
			break;
    }
}
