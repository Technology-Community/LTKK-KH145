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
	Student(float mathScore, float physicalScore, float chemistryScore)
	{
		_mathScore = mathScore;
		_physicalScore = physicalScore;
		_chemistryScore = chemistryScore;
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
Student maxAgeInArr(Student arrStudent[], int n);
Student maxAvgScoreInArr(Student arrStudent[], int n);
void searchByName(Student arrStudent[], int n, char name[]);
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
	printAStudent(maxAgeInArr(arrStudent, n));

	printf("\nStudent have max avg score: ");
	printAStudent(maxAvgScoreInArr(arrStudent, n));

	fflush(stdin);
	cin.ignore();
	char searchName[MAX_NAME_LENGTH];
	printf("\nFill search name: ");
	fgets(searchName, MAX_NAME_LENGTH, stdin);
	searchByName(arrStudent, n, searchName);

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
void removeNewLine(char *s)
{
	while (*s)
	{
		if (*s == '\n')
		{
			*s = '\0';
		}
		s++;
	}
}
float avgScore(Student obj)
{
	return (obj._mathScore + obj._physicalScore + obj._chemistryScore) / 3;
}

bool scoreNotPoor(Student obj)
{
	int score = 3;
	return obj._mathScore >= score && obj._physicalScore >= score && obj._chemistryScore >= score;
}

Student greaterAvg(Student a, Student b)
{
	if (avgScore(a) > avgScore(b))
	{
		return a;
	}
	else
	{
		return b;
	}
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
	removeNewLine(obj._id);
	printf("Fill Name: ");
	// scanf("%s", &obj._name);
	fgets(obj._name, MAX_NAME_LENGTH, stdin);
	removeNewLine(obj._name);
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
	if (strcmp(obj._id, "") != 0)
	{
		printf("\nID = %s", obj._id);
		printf("\nName = %s", obj._name);
		printf("\nBirthday = ");
		printDate(obj._birthday);
		printf("\nMath Score = %.2f", obj._mathScore);
		printf("\nPhysical Score = %.2f", obj._physicalScore);
		printf("\nChemistry Score = %.2f", obj._chemistryScore);
	}
	else
	{
		printf("\nNo Information's Student");
	}
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

Student maxAgeInArr(Student arrStudent[], int n)
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
Student maxAvgScoreInArr(Student arrStudent[], int n)
{
	if (n == 1)
	{
		return arrStudent[0];
	}
	return greaterAvg(arrStudent[n - 1], maxAvgScoreInArr(arrStudent, n - 1));
}
void searchByName(Student arrStudent[], int n, char name[])
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(arrStudent[i]._name, name) == 0)
		{
			printAStudent(arrStudent[i]);
			flag = true;
		}
	}
	if (flag == false)
	{
		printf("\nDon't have information");
	}
}
/* END FUNTIONS HANDLE */
