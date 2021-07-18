/* 4 */
/*
	Descriptions
*/

/* Code by KingNNT */
/*
Author's informations:
	- Email: Dev.KingNNT@gmail.com
	- Skype: live:king.nnt
	- Facebook Profile: https://www.facebook.com/Kinggg.NNT
	- Facebook Page: https://www.facebook.com/Dev.KingNNT
	- Github Profile: https://github.com/KingNNT
	- Gitlap Profile: https://gitlab.com/Dev.KingNNT
	- Bitbucket Profile: https://bitbucket.org/KingNNT/
*/

/* ---------- | ---------- | ---------- | ---------- | ---------- */

/* INCLUDE FILE */
/** Include libraries of CPP */
#include <bits/stdc++.h>
/** Include my libraries */
// #include ""
/* END INCLUDE FILE */

/* ---------- | ---------- | ---------- */
/* DEFINITIONS */
/** Define path file for input and output */
#define pathio "/mnt/LearningAndWorking/Develop/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Develop/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

/** Macro definitions for maximum length of variables */

/* END DEFINITIONS */

/* ---------- | ---------- | ---------- */
/* NAMESPACE */
using namespace std;
/* END NAMESPACE */

/* ---------- | ---------- | ---------- | ---------- | ---------- */

/* DECLARE CLASS */

/* END DECLARE CLASS */

/* ---------- | ---------- | ---------- */
/* DECLARE STRUCT */

/* END DECLARE STRUCT */

/* ---------- | ---------- | ---------- */
/* DECLARE TYPEDEF */

/* END DECLARE TYPEDEF */

/* ---------- | ---------- | ---------- */
/* DECLARE FUNCTIONS HELPER */
/*** Code at "DECLARE FUNCTION HELPER BLOCK" ***/

/* END DECLARE FUNCTIONS HELPER */

/* ---------- | ---------- | ---------- */
/* DECLARE FUNCTIONS HANDLE*/
/*** Code at "DECLARE FUNCTION HANDLE BLOCK" ***/
int recursion(int num);
int loop(int num);

/* END DECLARE FUNCTIONS HANDLE */

/* ---------- | ---------- | ---------- | ---------- | ---------- */

/* SOLVE */
void solve()
{
	int n;
	do
	{
		printf("Nhap N: ");
		scanf("%d", &n);
	} while (n <= 0);
	int resultRecursion = recursion(n);
	int resultLoop = loop(n);
	printf("\nResult with recursion = %d", resultRecursion);
	printf("\nResult with loop = %d", resultLoop);
	return;
}
/* END SOLVE */

/* ---------- | ---------- | ---------- */
/* MAIN */
int main()
{
	freopen(lfi);
	freopen(lfo);
	// ios_base :: sync_with_stdio (0);
	cin.tie(0);

	solve();

	fclose(stdin);
	fclose(stdout);
	return 0;
}
/* END MAIN*/

/* ---------- | ---------- | ---------- | ---------- | ---------- */

/* FUNCTIONS HELPER */
/*** Declare at "DECLARE FUNCTION HELPER BLOCK" ***/

/* END FUNTIONS HELPER */

/* ---------- | ---------- | ---------- */
/* FUNCTIONS HANDLE */
/*** Declare at "DECLARE FUNCTION HANDLE BLOCK" ***/
int recursion(int num)
{
	int result = 0;
	if (num == 1)
	{
		result = -1;
	}
	else
	{
		result = recursion(num - 1) + pow(-1, num) * (num);
	}
	return result;
}

int loop(int num)
{
	int result = 0;
	for (int i = 1; i <= num; i++)
	{
		result += pow(-1, i) * i;
	}
	return result;
}
/* END FUNTIONS HANDLE */
