/* Program   : mstack.c */
/* Deskripsi : driver ADT stack (soal 1-5: palindrom, cek kurung, undo/redo,
                infix->postfix, evaluasi postfix) */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "stack.h"

int main() {
	/*kamus*/
	char kata[MAKS_STR]; 
	boolean hasil;        
 
	/*algoritma*/
	printf("Masukkan ekspresi: ");
	fgets(kata, sizeof(kata), stdin);
	kata[strcspn(kata, "\n")] = '\0';
 
	hasil = isValidParentheses(kata);
 
	if (hasil) {
		printf("Ekspresi VALID (pasangan kurung sesuai)\n");
	} else {
		printf("Ekspresi TIDAK VALID (pasangan kurung tidak sesuai)\n");
	}
 
	return 0;
}