#include<stdio.h>
#include<windows.h>

/*Sample:
100% |********************************| Status: OK.
 "*" here would be replaced by ascii 219(a char seems like a square),
 and it's amount is 32 totally.*/

void hideCursor();
void showCursor();
void progressBar(int b, int c);

void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};	// the last '0' represents invisible
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void showCursor() {
	CONSOLE_CURSOR_INFO cursor_info = {1, 1};	// the last '0' represents invisible
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
		printf("  ");	// fill the blank
	}
}

int main() {
	int num = 32;
	int i;
	int count;

//	if Ascii 219 available on this OS (default),
//	use:
	SetConsoleOutputCP(437);
//	if not, annotate the sentences above.
	
	hideCursor();
	for (i = 0; i < num + 1; i++) {
		count = 100 * i / num;	
		printf("\r");
		printf("%3d%%", count);	// percentage
		printf("|");
		progressBar(i, num);
		printf("|");
		Sleep(100);
	}

	Sleep(100);
	printf(" Status: Compeleted.\n");
	showCursor();

	return 0;
}

/*
When print ASCII no.219, it takes up 2 times as much as a space do.
But I haven't found the explanation yet.
*/