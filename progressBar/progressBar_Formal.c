#include<stdio.h>
#include<windows.h>

/*Sample:
100% |********************************| Status: OK.
 "*" here would be replaced by ascii 219(a char seems like a square),
 and it's amount is 32 totaly.*/

void hideCursor();
void progressBar(int b, int c);
void backToHead(int c);

void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};	// the last '0' represents invisible
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void progressBar(int b, int c) {
	int i = 0;
	int j = 0;
	for (; i < b; i++) {
		printf("%c", 219);
//		if the Ascii 219 not available on this OS,
//		use the sentence below and annotate the "printf" above.
//		printf("*");
	}
	for(; j < c - b; j++) {
		printf(" ");	// fill the blank
	}
}
void backToHead(int c) {
	int i = 1;
	for (; i < c; i++) {
		printf("\b");
	}
}

int main() {
	int num = 32;
	int i;
	int count;

//	if Ascii 219 available on this OS (default),
//	use:
	system("chcp 437");
	system("cls");
//	if not, annotate the 2 sentences above.
	hideCursor();

	for (i = 0; i < num + 1; i++) {
		count = 100 * i / num;	
		backToHead(39);
		printf("%3d%c", count, 37);	// percentage
		printf("|");
		progressBar(i, num);
		printf("|");
		Sleep(50);
	}

	Sleep(100);
	printf(" Status: Compeleted.\n");

	return 0;
}