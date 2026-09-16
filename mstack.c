/* Program   : mstack.c */
/* Deskripsi : driver ADT stack (soal 1-5: palindrom, cek kurung, undo/redo,
                infix->postfix, evaluasi postfix) */
/* NIM/Nama  : 	- Vito Aliffiano Royyandinova (24060125130069)
								- Ilhami Rizqy Romadzoni Astiko (24060125140199)
								- M. Naufal Syuja Kurniawan (24060125140233)
								- Arya Fathdillah Adi Saputra (24060125120039)
								- Davin Ihza Pramudya (24060125120017) */
/* Tanggal   : 15 September 2026*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "stack.h"

int main() {
	/*kamus*/
	char kata[MAKS_STR];
	char infix[] = "3+(4*3)/4";
	boolean hasil, palindrome;        

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

	palindrome = isPalindrome(kata);
	if (palindrome){
		printf("Kata Palindrom");
	}else{
		printf("Kata tidak palindrom");
	}

	printf("\n\n=== TEST UNDO/REDO ===\n");
	TStackString undoStack, redoStack;
	createStackString(&undoStack);
	createStackString(&redoStack);

	executeCommand(&undoStack, &redoStack, "ketik A");
	executeCommand(&undoStack, &redoStack, "ketik B");
	executeCommand(&undoStack, &redoStack, "ketik C");
	printf("\nKONDISI AWAL%s\n");
	printf("Undo top sekarang: %s\n", undoStack.wadah[undoStack.top]);  // harus "ketik C"
	printf("Redo top sekarang: %s\n", redoStack.wadah[redoStack.top]);  // harus "ketik C"

	undoCommand(&undoStack, &redoStack);
	printf("\nUNDO%s\n");
	printf("Undo top sekarang: %s\n", undoStack.wadah[undoStack.top]);  // harus "ketik B"
	printf("Redo top sekarang: %s\n", redoStack.wadah[redoStack.top]);  // harus "ketik C"
	
	redoCommand(&undoStack, &redoStack);
	printf("\nREDO%s\n");
	printf("Undo top sekarang: %s\n", undoStack.wadah[undoStack.top]);  // harus "ketik B"
	printf("Redo top sekarang: %s\n", redoStack.wadah[redoStack.top]);  // harus "ketik C"
	
	undoCommand(&undoStack, &redoStack);
	printf("\nUNDO%s\n");
	printf("Undo top sekarang: %s\n", undoStack.wadah[undoStack.top]);  // harus "ketik B"
	printf("Redo top sekarang: %s\n", redoStack.wadah[redoStack.top]);  // harus "ketik C"
	undoCommand(&undoStack, &redoStack);
	printf("\nUNDO%s\n");
	printf("Undo top sekarang: %s\n", undoStack.wadah[undoStack.top]);  // harus "ketik B"
	printf("Redo top sekarang: %s\n", redoStack.wadah[redoStack.top]);  // harus "ketik C"


  infixToPostfix(infix, kata);
  printf("Infix   : %s\n", infix);
  printf("Postfix : %s\n", kata);
	
	printf("\n=== TEST EVALUASI POSTFIX ===\n");
	// Kamus Lokal
    char postfix[MAKS_STR];
    double hasil_postfix;

    // Algoritma
    printf("Masukkan postfix: ");
    scanf("%[^\n]", postfix);

    hasil_postfix = evaluatePostfix(postfix);

    printf("Hasil = %.2f\n", hasil_postfix);
	return 0;
}