// PEMANGGILAN LIBRARY
#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<windows.h>
using namespace std;
// PEMANGGILAN LIBRARY

// PEMANGGILAN FILE HEADER
#include "program.h"
#include "input.h"
// PEMANGGILAN FILE HEADER - END

// DEKLARASI
#define ROWS 5
#define COLS 100

char screen[ROWS][COLS+1];
int penambah_kolom;
char nama_file[30];
// DEKLARASI - END



int main_input() {
	int d; // UNTUK INPUTAN DALAM BENTUK ASCII
	int cr = 0; // ROW / BARIS 
	int cc = 0; // COLOUM  / KOLOM
	// char input[ROWS][COLS];
	// char ch;

	tambah_kolom(0); // SET KOLOM MENJADI 0 AGAR NORMAL

	while (cr < ROWS) {
		if(cc < COLS + penambah_kolom){
			if (kbhit()) { // SEPERTI ON KEY PRESS
				d = getch();
				
				if(d == 19){ // CTRL + S
					cr = ROWS;
				}

				if(d == 27){ // ESC
					cr = ROWS;
					main(); // REDIRECT TO MAIN MENU
				}

				if(d == 15){ // CTRL + O
					open(cr,cc);
				}

				if (d == 224) { // 256 + (- 32)
					d = getch();

					if (d == 72){ // PANAH ATAS
						tambah_kolom(0); // SET KOLOM MENJADI 0 AGAR NORMAL

						int temp_1 = 0;
						int temp_2 = 0;
						for(int a = 0; a < COLS; a++){
							if(cr != ROWS-1){
								if (screen[cr-1][a] != 0) // UNTUK CEK SAMPAI SEPANJANG APA ARRAY PADA BARIS INI
								{
									temp_1 = a+1;

									if (temp_1 == COLS){ // JIKA BARIS SEBELUMNYA PENUH MAKA DIA AKAN MELAKUKAN LOGIK INI
										temp_1 = a;									
									}
								}

								if (screen[cr][a] != 0) // UNTUK CEK SAMPAI SEPANJANG APA ARRAY PADA BARIS INI
								{
									temp_2 = a+1;
								}
							}
						}

						cr--;
						
						if((temp_1 < temp_2) && (cc > temp_1)){ // LOJIK JIKA temp_1 < temp_2 DAN JUGA POSISI KOLOM cc > temp_1 MAKA AKAN MELAKUKAN FUNGSI INI
							cc = temp_1;
						}
					}

					else if (d == 80) { // PANAH BAWAH
						tambah_kolom(0); // SET KOLOM MENJADI 0 AGAR NORMAL

						int temp_1 = 0;
						int temp_2 = 0;
						for(int a = 0; a < COLS; a++){
							if(cr != ROWS-1){
								if (screen[cr+1][a] != 0) // UNTUK CEK SAMPAI SEPANJANG APA ARRAY PADA BARIS INI
								{
									temp_1 = a+1;

									if (temp_1 == COLS){ // JIKA BARIS SEBELUMNYA PENUH MAKA DIA AKAN MELAKUKAN LOGIK INI
										temp_1 = a;									
									}
								}

								if (screen[cr][a] != 0) // UNTUK CEK SAMPAI SEPANJANG APA ARRAY PADA BARIS INI
								{
									temp_2 = a+1;
								}
							}
						}

						if(temp_1 != 0){ // CEK APAKAH BARIS SELANJUTNYA SUDAH ADA VALUE ATAU BELUM, JIKA 0 BERARTI BELUM ADA VALUE
							cr++;
							if((temp_1 < temp_2) && (cc > temp_1)){ // LOJIK JIKA temp_1 < temp_2 DAN JUGA POSISI KOLOM cc > temp_1 MAKA AKAN MELAKUKAN FUNGSI INI
								cc = temp_1;
							}
						}
						

					}

					else if (d == 77) { // PANAH KANAN
						tambah_kolom(0); // SET KOLOM MENJADI 0 AGAR NORMAL

						if (screen[cr][cc+1] != 0) // UNTUK CEK APAKAH BERIKUTNYA 0 ATAU TIDAK
						{
							cc++;	
						}	
						else if((screen[cr][cc] != 0) && (screen[cr][cc+1] == 0)){ // CEK APAKAH POSISI SEKARANG 0 ATAU TIDAK, DAN CEK APAKAH POSISI SELANJUTNYA 0 ATAU TIDAK
							cc++;
						}	
						else if((screen[cr+1][0] != 0) && (screen[cr][cc+1] == 0)){ // CEK APAKAH POSISI BARIS SELANJUTNYA 0 ATAU TIDAK, DAN CEK APAKAH POSISI SELANJUTNYA 0 ATAU TIDAK
							cr++;
							cc = 0;
						}				

					}

					else if (d == 75) { // PANAH KIRI
						tambah_kolom(0); // SET KOLOM MENJADI 0 AGAR NORMAL

						cc--;

						int temp;
						for(int a = 0; a < COLS; a++){
							if(cr != 0){
								if (screen[cr-1][a] != 0) // UNTUK CEK SAMPAI SEPANJANG APA ARRAY PADA BARIS INI
								{
									temp = a+1;

									if (temp == COLS){ // JIKA BARIS SEBELUMNYA PENUH MAKA DIA AKAN MELAKUKAN LOGIK INI
										temp = a;									
									}
								}
							}
						}

						if ((cc < 0 ) && (cr > 0)){
							cr--;
							// cc = COLS;
							cc = temp;
						}
					}

					else if(d == 71){ // HOME
						cc = 0;
					}

					else if(d == 79){ // END
						int temp = 0;
						for(int a = 0; a < COLS; a++){
							if (screen[cr][a] != 0) // UNTUK CEK SAMPAI SEPANJANG APA ARRAY PADA BARIS INI
							{
								temp = a+1;

								if (temp == COLS){ // JIKA BARIS SEBELUMNYA PENUH MAKA DIA AKAN MELAKUKAN LOGIK INI
									temp = a;									
								}
							}
						}

						if (cc >= 0 && cc < COLS){
							cc = temp;
						}
					}
				}

				else if (d == 13){ // ENTER
					cr++;
					cc = 0;
					tambah_kolom(1); // SET KOLOM MENJADI 0 AGAR NORMAL
				}

				else if (d == 8){ // BACKSPACE
					if(cc <= 0 || cc == 1){
						tambah_kolom(1); // SET KOLOM DITAMBAH 1 AGAR BISA MENGHAPUS YANG AKHIR
					}
					else {
						tambah_kolom(0); // SET KOLOM MENJADI 0 AGAR NORMAL
					}

					int temp = 0;
					for(int a = 0; a < COLS; a++){
						if(cr != 0){
							if (screen[cr-1][a] != 0) // UNTUK CEK SAMPAI SEPANJANG APA ARRAY PADA BARIS INI
							{
								temp = a+1;

								if (temp == COLS){ // JIKA BARIS SEBELUMNYA PENUH MAKA DIA AKAN MELAKUKAN LOGIK INI
									tambah_kolom(1); // SET KOLOM DITAMBAH 1 AGAR BISA MENGHAPUS YANG AKHIR
									screen[cr-1][temp-1] = 0; // UNTUK HAPUS VALUE PALING AKHIR DI ARRAY									
									temp = a+1;
								}
							}
						}
					}


					if(cc > 0){
						tambah_kolom(0); // SET KOLOM MENJADI 0 AGAR NORMAL
						cc--;
					}

					if ((cc == 0 ) && (cr > 0)){
						tambah_kolom(1); // SET KOLOM DITAMBAH 1 AGAR BISA MENGHAPUS YANG AKHIR
						screen[cr][cc] = 0; // UNTUK HAPUS VALUE DI ARRAY PADA POSISI SEKARANG DIKARENAKAN POINTER LANGSUNG DI LEMPAR KE ATAS
						cr--;
						cc = temp;

						// printf("\n\n\n jml temp : %d",temp);
					} 

					printf("\b");
					printf(" ");

					for(int j=cc; j<COLS; j++){	
						screen[cr][j] = screen[cr][j+1]; // UNTUK GESER ARRAY
					}
				}

				else if (d == 9){ // TAB
					tambah_kolom(0); // SET KOLOM MENJADI 0 AGAR NORMAL

					cc+=4;
					printf("\t");
					// printf("	");
					printf("    ");
				}

				else{
					tambah_kolom(0); // SET KOLOM MENJADI 0 AGAR NORMAL

					cout << char(d);
					screen[cr][cc] = char(d); // PROSES INPUT DATA KE ARRAY 2 DIMENSI
					// printf("%d",d);
					cc++;	
				}

				gotoRowCol(cr, cc);
			}
		}
		else{
			cr++;  // BARIS
			cc = 0; // KOLOM
			gotoRowCol(cr, cc);
		}
	}

	simpan();
	tombol_selanjutnya();
	main();
	return 0;
}

void gotoRowCol(int posisi_baris, int posisi_kolom)
{
	// HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // HANDLE OUTPUT STANDAR
	
	// DEKLARASI VARIBEL LOKAL
	int posisi_x = posisi_kolom;
	int posisi_y = posisi_baris;
	COORD posisi_screen;

	HANDLE hasil_output = GetStdHandle(STD_OUTPUT_HANDLE); // HANDLE OUTPUT STANDAR
	
	posisi_screen.X = posisi_x; // REPRESENTASI POSISI X
	posisi_screen.Y = posisi_y; // REPRESENTASI POSISI X
	
	SetConsoleCursorPosition(hasil_output, posisi_screen); // SET KORDINAT DARI POSISI CURSOR (POINTER)
}


void simpan(){
	FILE *f_golang;
	
	int temp = 0;
	for(int a = 0; a < ROWS; a++){
		if (screen[a][0] != 0) // UNTUK CEK SAMPAI SEPANJANG APA ARRAY PADA KOLOM INI
		{
			temp = a+1;
		}
	}
	
	if ((f_golang = fopen(nama_file, "w")) == 0){
		system("cls");
		
		fflush(stdin);
		printf("Masukkan Nama File yang akan disimpan : ");
		scanf("%[^\n]", &nama_file);
		fflush(stdin);
		// gets(nama_file);
		
		f_golang = fopen(nama_file, "w");
		
		for(int i = 0; i < temp; i++){
			if(i < temp - 1){
				fprintf(f_golang,"%s\n",screen[i]);
			}
			else{
				fprintf(f_golang,"%s",screen[i]);
			}
		}

		fclose(f_golang);	
	}
	
	for(int  i= 0; i < temp; i++){
		
		if(i < temp - 1){
			fprintf(f_golang,"%s\n",screen[i]);
		}
		else{
			fprintf(f_golang,"%s",screen[i]);
		}
	}


	fclose(f_golang);
	memset(nama_file, 0, sizeof nama_file); // UNTUK RESET VARIABEL ARRAY OF CHAR
	memset(screen, 0, sizeof screen); // UNTUK RESET VARIABEL ARRAY OF CHAR
}

void open(int baris,int kolom)
{
	FILE *f_golang;
	char cho;
	int i,j;
	
	
	system("cls");
	
	if (screen[baris][kolom-1] != 0)
	{
		printf("Masih terdapat progress saat ini /n Apakah anda akan menyimpan file? (y/n): ");
		cho = getche();
		if ((cho == 'Y') || (cho == 'y')){
			simpan();
			// free(nama_file);	
			// nama_file = 0;
		}
		else{
			open_file();
		}
	}
	
	
	else
	{
		open_file();
	}	
}

void open_file(){
	FILE *f_golang;

	system("cls");

	// printf("Masukkan Nama File yang akan dibuka : ");
	// gets(nama_file);
	fflush(stdin);
	printf("Masukkan Nama File yang akan dibuka : ");
	scanf("%[^\n]", &nama_file);
	fflush(stdin);

	f_golang = fopen(nama_file, "a+");
	system("cls");
	
	for(int i=0; i<ROWS; i++){
		for(int j=0; j<COLS; j++){
			fscanf(f_golang,"%c", &screen[i][j]);
			printf("%c", screen[i][j]);	
		}
	}
	fclose(f_golang);
}

void tambah_kolom(int nilai){
	penambah_kolom = nilai;
}

// FUNCTION UNTUK MENAMPILKAN ALERT
void tombol_selanjutnya(){
	printf("\n");
	printf("Tekan Apapun Untuk Melanjutkan!");
	getch();
}
// FUNCTION UNTUK MENAMPILKAN ALERT