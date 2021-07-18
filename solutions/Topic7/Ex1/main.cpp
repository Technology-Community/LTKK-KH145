/*  Title Project */
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
#define MAX_ID_LENGTH 10
#define MAX_NAME_LENGTH 30
#define MAX_STUDENT_ARRAY 100
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
struct Date
{
	int _day;
	int _month;
	int _year;
	Date()
	{
		_day = 1;
		_month = 1;
		_year = 1;
	}
	Date(int day, int month, int year)
	{
		_day = day;
		_month = month;
		_year = year;
	}
};
typedef struct Date Date;
struct Student
{
	// char *_id = (char *)malloc(sizeof(char) * MAX_ID_LENGTH);
	// char *_name = (char *)malloc(sizeof(char) * MAX_NAME_LENGTH);
	char _id[MAX_ID_LENGTH];
	char _name[MAX_NAME_LENGTH];
	Date _birthday;
	float _mathScore;
	float _physicalScore;
	float _chemistryScore;
	Student()
	{
		_mathScore = 0;
		_physicalScore = 0;
		_chemistryScore = 0;
	}
};
typedef struct Student Student;
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
void printAStudent(Student obj);
void fillArrayStudent(Student arrStudent[], int n);
void printArrayStudent(Student arrStudent[], int n);
int countAverage(Student arrStudent[], int n);
Student maxAge(Student arrStudent[], int n);

/* END DECLARE FUNCTIONS HANDLE */

/* ---------- | ---------- | ---------- | ---------- | ---------- */

/* SOLVE */
void solve()
{
	int n;
	Student arrStudent[MAX_STUDENT_ARRAY];
	do
	{
		printf("Enter N:");
		scanf("%d", &n);
	} while (n <= 0);

	fillArrayStudent(arrStudent, n);
	printArrayStudent(arrStudent, n);
	printf("\nCount Avg Student: %d", countAverage(arrStudent, n));
	printf("\nStudent have max age: ");
	printAStudent(maxAge(arrStudent, n));
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
int avgScore(Student obj)
{
	return (obj._mathScore + obj._physicalScore + obj._chemistryScore) / 3;
}

bool scoreNotPoor(Student obj)
{
	int score = 3;
	return obj._mathScore >= score && obj._physicalScore >= score && obj._chemistryScore >= score;
}
/* END FUNTIONS HELPER */
bool operator<(Date a, Date b)
{
	if (a._year < b._year)
	{
		return true;
	}
	else if (a._year == b._year)
	{
		if (a._month < b._month)
		{
			return true;
		}
		else if (a._month == b._month)
		{
			if (a._day < b._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
/* ---------- | ---------- | ---------- */
/* FUNCTIONS HANDLE */
/*** Declare at "DECLARE FUNCTION HANDLE BLOCK" ***/
void fillDate(Date &obj)
{
	printf("Fill Day: ");
	scanf("%d", &obj._day);
	printf("Fill Month: ");
	scanf("%d", &obj._month);
	printf("Fill Year: ");
	scanf("%d", &obj._year);
}

void printDate(Date obj)
{
	printf("%d / %d / %d", obj._day, obj._month, obj._year);
}

void fillAStudent(Student &obj)
{
	// fflush(stdin);
	cin.ignore();
	printf("Fill ID: ");
	// scanf("%s", &obj._id);
	fgets(obj._id, MAX_ID_LENGTH, stdin);
	printf("Fill Name: ");
	// scanf("%s", &obj._name);
	fgets(obj._name, MAX_NAME_LENGTH, stdin);
	printf("Fill Birthday: ");
	fillDate(obj._birthday);
	printf("Fill Math Score: ");
	scanf("%f", &obj._mathScore);
	printf("Fill Physical Score: ");
	scanf("%f", &obj._physicalScore);
	printf("Fill Chemistry Score: ");
	scanf("%f", &obj._chemistryScore);
}

void printAStudent(Student obj)
{
	printf("\nID = %s", obj._id);
	printf("Name = %s", obj._name);
	printf("Birthday = ");
	printDate(obj._birthday);
	printf("\nMath Score = %f", obj._mathScore);
	printf("\nPhysical Score = %f", obj._physicalScore);
	printf("\nChemistry Score = %f", obj._chemistryScore);
}

void fillArrayStudent(Student arrStudent[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nFill information's student %d", i + 1);
		fillAStudent(arrStudent[i]);
	}
}

void printArrayStudent(Student arrStudent[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n\nInformation's student %d", i + 1);
		printAStudent(arrStudent[i]);
	}
}

int countAverage(Student arrStudent[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (avgScore(arrStudent[i]) > 5 && scoreNotPoor(arrStudent[i]))
		{
			count++;
		}
	}
	return count;
}

Student maxAge(Student arrStudent[], int n)
{
	Student max = arrStudent[0];
	for (int i = 1; i < n; i++)
	{
		if (max._birthday < arrStudent[i]._birthday)
		{
			max = arrStudent[i];
		}
	}
	return max;
}
/* END FUNTIONS HANDLE */
