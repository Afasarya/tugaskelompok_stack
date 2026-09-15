/* Program   : stack.c */
/* Deskripsi : file BODY modul ADT Stack (character, double, string) */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "stack.h"
/* boolean.h sudah ter-include lewat stack.h */

/* =======================================================================
1) STACK OF CHARACTER
========================================================================= */

/* KONSTRUKTOR */
void createStackChar(TStackChar *S)
{
	S->top = 0;
}

/* PREDIKAT */
boolean isEmptyStackChar(TStackChar S)
{
	return (S.top == 0);
}

boolean isFullStackChar(TStackChar S)
{
	return (S.top == MAKS_STACK);
}

/* MUTATOR */
void pushChar(TStackChar *S, char elemen)
{
	if (isFullStackChar(*S))
	{
		printf("Error: StackChar penuh, push gagal.\n");
		return;
	}
	S->top++;
	S->wadah[S->top] = elemen;
}

void popChar(TStackChar *S, char *elemen)
{
	if (isEmptyStackChar(*S))
	{
		printf("Error: StackChar kosong, pop gagal.\n");
		return;
	}
	*elemen = S->wadah[S->top];
	S->top--;
}

/* SELEKTOR */
int getTopChar(TStackChar S)
{
	return S.top;
}

char infoTopChar(TStackChar S)
{
	if (isEmptyStackChar(S))
	{
		printf("Error: StackChar kosong, tidak ada TOP.\n");
		return '\0';
	}
	return S.wadah[S.top];
}

/* =======================================================================
2) STACK OF DOUBLE
========================================================================= */

/* KONSTRUKTOR */
void createStackDouble(TStackDouble *S)
{
	S->top = 0;
}

/* PREDIKAT */
boolean isEmptyStackDouble(TStackDouble S)
{
	return (S.top == 0);
}

boolean isFullStackDouble(TStackDouble S)
{
	return (S.top == MAKS_STACK);
}

/* MUTATOR */
void pushDouble(TStackDouble *S, double elemen)
{
	if (isFullStackDouble(*S))
	{
		printf("Error: StackDouble penuh, push gagal.\n");
		return;
	}
	S->top++;
	S->wadah[S->top] = elemen;
}

void popDouble(TStackDouble *S, double *elemen)
{
	if (isEmptyStackDouble(*S))
	{
		printf("Error: StackDouble kosong, pop gagal.\n");
		return;
	}
	*elemen = S->wadah[S->top];
	S->top--;
}

/* SELEKTOR */
int getTopDouble(TStackDouble S)
{
	return S.top;
}

double infoTopDouble(TStackDouble S)
{
	if (isEmptyStackDouble(S))
	{
		printf("Error: StackDouble kosong, tidak ada TOP.\n");
		return 0.0;
	}
	return S.wadah[S.top];
}

/* =======================================================================
3) STACK OF STRING
========================================================================= */

/* KONSTRUKTOR */
void createStackString(TStackString *S)
{
	S->top = 0;
}

/* PREDIKAT */
boolean isEmptyStackString(TStackString S)
{
	return (S.top == 0);
}

boolean isFullStackString(TStackString S)
{
	return (S.top == MAKS_STACK);
}

/* MUTATOR */
void pushString(TStackString *S, char elemen[])
{
	if (isFullStackString(*S))
	{
		printf("Error: StackString penuh, push gagal.\n");
		return;
	}
	S->top++;
	strcpy(S->wadah[S->top], elemen);
}

void popString(TStackString *S, char elemen[])
{
	if (isEmptyStackString(*S))
	{
		printf("Error: StackString kosong, pop gagal.\n");
		elemen[0] = '\0';
		return;
	}
	strcpy(elemen, S->wadah[S->top]);
	S->top--;
}

/* SELEKTOR */
int getTopString(TStackString S)
{
	return S.top;
}

void infoTopString(TStackString S, char elemen[])
{
	if (isEmptyStackString(S))
	{
		printf("Error: StackString kosong, tidak ada TOP.\n");
		elemen[0] = '\0';
		return;
	}
	strcpy(elemen, S.wadah[S.top]);
}

/* =======================================================================
FUNGSI APLIKASI (SOAL 1-5)
========================================================================= */

/* Soal 1 - Pengecekan Kata Palindrom */
boolean isPalindrome(char kata[])
{
	// Kamus Lokal
	int n, i;
	char x;
	TStackChar T;

	// Algoritma
	n = strlen(kata);
	createStackChar(&T);
	for (int i = 0; i < n / 2; i++)
	{
		pushChar(&T, kata[i]);
	}
	if (n % 2 == 0)
	{
		for (int i = (n / 2); i < n; i++)
		{
			popChar(&T, &x);
			if (kata[i] != x)
			{
				return false;
			}
		}
		if (!isEmptyStackChar(T))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		for (int i = (n / 2) + 1; i < n; i++)
		{
			popChar(&T, &x);
			if (kata[i] != x)
			{
				return false;
			}
		}
		if (!isEmptyStackChar(T))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

/* Soal 2 - Parentheses Checker */
boolean isValidParentheses(char kata[])
{
	TStackChar S;
	char kurungBuka;
	int i, panjang;
	boolean valid = true;
	createStackChar(&S);
	panjang = strlen(kata);

	for (i = 0; i < panjang && valid; i++)
	{
		char c = kata[i];

		if (c == '(' || c == '[' || c == '{')
		{
			pushChar(&S, c);
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			if (isEmptyStackChar(S))
			{
				valid = false;
			}
			else
			{
				popChar(&S, &kurungBuka);
				if ((c == ')' && kurungBuka != '(') ||
						(c == ']' && kurungBuka != '[') ||
						(c == '}' && kurungBuka != '{'))
				{
					valid = false;
				}
			}
		}
	}

	if (valid && !isEmptyStackChar(S))
	{
		valid = false;
	}

	return valid;
}

/* Soal 3 - Undo/Redo Text Editor */
void executeCommand(TStackString *undoStack, TStackString *redoStack, char perintah[])
{
	pushString(undoStack, perintah);
	createStackString(redoStack);
}

void undoCommand(TStackString *undoStack, TStackString *redoStack)
{
	char temp[MAKS_STR];
	if (!isEmptyStackString(*undoStack))
	{
		popString(undoStack, temp);
		pushString(redoStack, temp);
	}
	else
	{
		printf("Tidak ada perintah untuk di-undo.\n");
	}
}

void redoCommand(TStackString *undoStack, TStackString *redoStack)
{
	char temp[MAKS_STR];
	if (!isEmptyStackString(*redoStack))
	{
		popString(redoStack, temp);
		pushString(undoStack, temp);
	}
	else
	{
		printf("Tidak ada perintah untuk di-redo.\n");
	}
}

/* Soal 4 - Konversi Infix ke Postfix */
int precedence(char op){
	if (op == '+' || op == '-'){
		return 1;
	}
	else if (op == '*' || op == '/'){
		return 2;
	}

	return 0;
}

void infixToPostfix(char infix[], char postfix[]){
	TStackChar S;
	int j;
	char c;
	char temp;

	createStackChar(&S);
	j = 0;

	for (int i = 0; infix[i] != '\0'; i++){
		c = infix[i];

		if (c >= '0' && c <= '9'){
			postfix[j] = c;
			j++;
		}
		else if (c == '('){
			pushChar(&S, c);
		}
		else if (c == ')'){
			while (!isEmptyStackChar(S) &&
			infoTopChar(S) != '('){
				popChar(&S, &temp);
				postfix[j] = temp;
				j++;
			}

			if (!isEmptyStackChar(S) &&
			infoTopChar(S) == '('){
				popChar(&S, &temp);
			}
		}
		else if (c == '+' || c == '-' ||
			c == '*' || c == '/'){
			while (!isEmptyStackChar(S) && 
			infoTopChar(S) != '(' && 
			precedence(infoTopChar(S)) >= precedence(c)){
				popChar(&S, &temp);
				postfix[j] = temp;
				j++;
			}
			pushChar(&S, c);
		}
	}

	while (!isEmptyStackChar(S)){
		popChar(&S, &temp);
		postfix[j] = temp;
		j++;
	}

	postfix[j] = '\0';
}

/* Soal 5 - Evaluasi Postfix Expression */

// Fungsi bantuan mengubah string menjadi double
double stringToDouble(char token[])
{
	// Kamus Lokal
	double hasil = 0;
	double pecahan = 0.1;
	int i = 0;

	// Algoritma
	while (token[i] >= '0' && token[i] <= '9')
	{
		hasil = hasil * 10 + (token[i] - '0');
		i++;
	}

	if (token[i] == '.')
	{
		i++;

		while (token[i] >= '0' && token[i] <= '9')
		{
			hasil = hasil + (token[i] - '0') * pecahan;
			pecahan = pecahan * 0.1;
			i++;
		}
	}

	return hasil;
}

double evaluatePostfix(char postfix[])
{
	// Kamus Lokal
	TStackDouble S;
	char token[50];
	char operator;
	double operand1, operand2, operasi;
	int i, j;

	// Algoritma
	createStackDouble(&S);

	i = 0;

	while (postfix[i] != '\0')
	{
		if (postfix[i] == ' ')
		{
			i++;
		}

		else if ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.')
		{

			j = 0;

			while ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.')
			{
				token[j] = postfix[i];
				j++;
				i++;
			}

			token[j] = '\0';

			pushDouble(&S, stringToDouble(token));
		}

		else
		{
			operator = postfix[i];

			popDouble(&S, &operand2);
			popDouble(&S, &operand1);

			if (operator == '+')
			{
				operasi = operand1 + operand2;
			}
			else if (operator == '-')
			{
				operasi = operand1 - operand2;
			}
			else if (operator == '*')
			{
				operasi = operand1 * operand2;
			}
			else if (operator == '/')
			{
				operasi = operand1 / operand2;
			}

			pushDouble(&S, operasi);
			i++;
		}
	}
	return infoTopDouble(S);
}