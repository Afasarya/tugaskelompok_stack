#ifndef stack_H
#define stack_H

/* Program   : stack.h */
/* Deskripsi : file HEADER modul ADT Stack (character, double, string) */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include "boolean.h"  //salin dari praktikum lalu

#define MAKS_STACK   100   /* kapasitas maksimum stack */
#define MAKS_STR     100   /* panjang maksimum satu string elemen */

/* =======================================================================
1) STACK OF CHARACTER
Dipakai di: Soal 1 (Palindrom), Soal 2 (Cek Kurung),
            Soal 4 (operator & '(' pada Infix->Postfix)
type TStackChar = < wadah: array[1..MAKS_STACK] of character,
                        top  : integer >
asumsi: indeks 0 tidak digunakan, top=0 artinya stack kosong
   ========================================================================= */
typedef struct { char wadah[MAKS_STACK + 1];
                int  top; } TStackChar;

/* KONSTRUKTOR */
/* procedure createStackChar(output S: TStackChar)
	{I.S.: sembarang}
	{F.S.: S terdefinisi sebagai stack kosong (S.top = 0)} */
void createStackChar(TStackChar *S);

/* PREDIKAT */
/* function isEmptyStackChar(S: TStackChar) -> boolean
	{mengembalikan true jika S kosong} */
boolean isEmptyStackChar(TStackChar S);

/* function isFullStackChar(S: TStackChar) -> boolean
	{mengembalikan true jika S penuh} */
boolean isFullStackChar(TStackChar S);

/* MUTATOR */
/* procedure pushChar(input/output S: TStackChar, input elemen: character)
	{I.S.: S terdefinisi}
	{F.S.: jika S belum penuh, elemen menjadi TOP baru dari S}
	{Proses: menambahkan elemen ke S} */
void pushChar(TStackChar *S, char elemen);

/* procedure popChar(input/output S: TStackChar, output elemen: character)
	{I.S.: S terdefinisi}
	{F.S.: jika S tidak kosong, TOP lama terhapus dan nilainya dikeluarkan lewat elemen}
	{Proses: mengambil & menghapus elemen TOP dari S} */
void popChar(TStackChar *S, char *elemen);

/* SELEKTOR */
/* function getTopChar(S: TStackChar) -> integer
	{mengembalikan posisi TOP dari S} */
int getTopChar(TStackChar S);

/* function infoTopChar(S: TStackChar) -> character
	{mengembalikan nilai elemen TOP dari S tanpa menghapusnya} */
char infoTopChar(TStackChar S);


/* =======================================================================
2) STACK OF DOUBLE
Dipakai di: Soal 5 (Evaluasi Postfix Expression -> hasil bilangan real)
type TStackDouble = < wadah: array[1..MAKS_STACK] of real,
                        top  : integer >
asumsi: indeks 0 tidak digunakan, top=0 artinya stack kosong
   ========================================================================= */
typedef struct { double wadah[MAKS_STACK + 1];
                int    top; } TStackDouble;

/* KONSTRUKTOR */
/* procedure createStackDouble(output S: TStackDouble)
	{I.S.: sembarang}
	{F.S.: S terdefinisi sebagai stack kosong (S.top = 0)} */
void createStackDouble(TStackDouble *S);

/* PREDIKAT */
/* function isEmptyStackDouble(S: TStackDouble) -> boolean
	{mengembalikan true jika S kosong} */
boolean isEmptyStackDouble(TStackDouble S);

/* function isFullStackDouble(S: TStackDouble) -> boolean
	{mengembalikan true jika S penuh} */
boolean isFullStackDouble(TStackDouble S);

/* MUTATOR */
/* procedure pushDouble(input/output S: TStackDouble, input elemen: real)
	{I.S.: S terdefinisi}
	{F.S.: jika S belum penuh, elemen menjadi TOP baru dari S}
	{Proses: menambahkan elemen ke S} */
void pushDouble(TStackDouble *S, double elemen);

/* procedure popDouble(input/output S: TStackDouble, output elemen: real)
	{I.S.: S terdefinisi}
	{F.S.: jika S tidak kosong, TOP lama terhapus dan nilainya dikeluarkan lewat elemen}
	{Proses: mengambil & menghapus elemen TOP dari S} */
void popDouble(TStackDouble *S, double *elemen);

/* SELEKTOR */
/* function getTopDouble(S: TStackDouble) -> integer
	{mengembalikan posisi TOP dari S} */
int getTopDouble(TStackDouble S);

/* function infoTopDouble(S: TStackDouble) -> real
	{mengembalikan nilai elemen TOP dari S tanpa menghapusnya} */
double infoTopDouble(TStackDouble S);


/* =======================================================================
3) STACK OF STRING
Dipakai di: Soal 3 (Undo/Redo Text Editor -> elemen berupa perintah)
type TStackString = < wadah: array[1..MAKS_STACK] of string,
					top  : integer >
asumsi: indeks 0 tidak digunakan, top=0 artinya stack kosong
   ========================================================================= */
typedef struct { char wadah[MAKS_STACK + 1][MAKS_STR];
                int  top; } TStackString;

/* KONSTRUKTOR */
/* procedure createStackString(output S: TStackString)
	{I.S.: sembarang}
	{F.S.: S terdefinisi sebagai stack kosong (S.top = 0)} */
void createStackString(TStackString *S);

/* PREDIKAT */
/* function isEmptyStackString(S: TStackString) -> boolean
	{mengembalikan true jika S kosong} */
boolean isEmptyStackString(TStackString S);

/* function isFullStackString(S: TStackString) -> boolean
	{mengembalikan true jika S penuh} */
boolean isFullStackString(TStackString S);

/* MUTATOR */
/* procedure pushString(input/output S: TStackString, input elemen: string)
	{I.S.: S terdefinisi}
	{F.S.: jika S belum penuh, elemen menjadi TOP baru dari S}
	{Proses: menambahkan elemen ke S} */
void pushString(TStackString *S, char elemen[]);

/* procedure popString(input/output S: TStackString, output elemen: string)
	{I.S.: S terdefinisi}
	{F.S.: jika S tidak kosong, TOP lama terhapus dan nilainya dikeluarkan lewat elemen}
	{Proses: mengambil & menghapus elemen TOP dari S} */
void popString(TStackString *S, char elemen[]);

/* SELEKTOR */
/* function getTopString(S: TStackString) -> integer
	{mengembalikan posisi TOP dari S} */
int getTopString(TStackString S);

/* procedure infoTopString(input S: TStackString, output elemen: string)
	{mengembalikan nilai elemen TOP dari S tanpa menghapusnya, lewat parameter elemen} */
void infoTopString(TStackString S, char elemen[]);


/* =======================================================================
FUNGSI APLIKASI (SOAL 1-5)
========================================================================= */

/* function isPalindrome(kata: string) -> boolean
	{menggunakan TStackChar. Mengembalikan true jika kata adalah palindrom} */
boolean isPalindrome(char kata[]);

/* function isValidParentheses(kata: string) -> boolean
	{menggunakan TStackChar. Mengembalikan true jika pasangan kurung buka/tutup
	 dalam kata sudah sesuai} */
boolean isValidParentheses(char kata[]);

/* procedure executeCommand(input/output undoStack, redoStack: TStackString, input perintah: string)
	{I.S.: undoStack & redoStack terdefinisi}
	{F.S.: perintah tersimpan di undoStack, redoStack dikosongkan kembali} */
void executeCommand(TStackString *undoStack, TStackString *redoStack, char perintah[]);

/* procedure undoCommand(input/output undoStack, redoStack: TStackString)
	{I.S.: undoStack & redoStack terdefinisi}
	{F.S.: jika undoStack tidak kosong, TOP undoStack berpindah ke redoStack} */
void undoCommand(TStackString *undoStack, TStackString *redoStack);

/* procedure redoCommand(input/output undoStack, redoStack: TStackString)
	{I.S.: undoStack & redoStack terdefinisi}
	{F.S.: jika redoStack tidak kosong, TOP redoStack berpindah ke undoStack} */
void redoCommand(TStackString *undoStack, TStackString *redoStack);

/* procedure infixToPostfix(input infix: string, output postfix: string)
	{I.S.: infix terdefinisi & valid, operand 1 digit (0-9)}
	{F.S.: postfix berisi hasil konversi infix ke bentuk postfix}
	{menggunakan TStackChar untuk menampung operator & '('} */
void infixToPostfix(char infix[], char postfix[]);

/* function evaluatePostfix(postfix: string) -> real
	{menggunakan TStackDouble. Mengembalikan hasil evaluasi ekspresi postfix} */
double evaluatePostfix(char postfix[]);

#endif