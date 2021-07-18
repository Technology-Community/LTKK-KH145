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
	int _id;
	char _name[MAX_NAME_LENGTH];
	Date _birthday;
	float _mathScore;
	float _physicalScore;
	float _chemistryScore;
	Student()
	{
		_id = 0;
		_mathScore = 0;
		_physicalScore = 0;
		_chemistryScore = 0;
	}
	Student(int id, float mathScore, float physicalScore, float chemistryScore)
	{
		_id = id;
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
void removeNewLine(char *s);

/* END DECLARE FUNCTIONS HELPER */

/* ---------- | ---------- | ---------- */
/* DECLARE FUNCTIONS HANDLE*/
/*** Code at "DECLARE FUNCTION HANDLE BLOCK" ***/
void fillAStudent(Student &obj);
void printAStudent(Student obj);
void fillArrayStudent(Student arrStudent[], int n);
void printArrayStudent(Student arrStudent[], int n);
int countAverage(Student arrStudent[], int n);
Student maxAgeInArr(Student arrStudent[], int n);
Student maxAvgScoreInArr(Student arrStudent[], int n);
void searchByName(Student arrStudent[], int n, char name[]);
void insertionSort(Student arrStudent[], int n);
void insertNewStudent(Student arrStudent[], int &n, Student newStudent);

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

	printf("\n\t-----\t\n");
	printf("\nCount Avg Student: %d", countAverage(arrStudent, n));

	printf("\n\t-----\t\n");
	printf("\nStudent have max age: ");
	printAStudent(maxAgeInArr(arrStudent, n));

	printf("\n\t-----\t\n");
	printf("\nStudent have max avg score: ");
	printAStudent(maxAvgScoreInArr(arrStudent, n));

	printf("\n\t-----\t\n");
	fflush(stdin);
	cin.ignore();
	char searchName[MAX_NAME_LENGTH];
	printf("\nFill search name: ");
	fgets(searchName, MAX_NAME_LENGTH, stdin);
	removeNewLine(searchName);
	searchByName(arrStudent, n, searchName);

	printf("\n\t-----\t\n");
	insertionSort(arrStudent, n);
	printf("\nAfter Sort: ");
	printArrayStudent(arrStudent, n);

	printf("\n\t-----\t\n");
	Student newStudent;
	printf("\nFill informations's student: ");
	fillAStudent(newStudent);
	insertNewStudent(arrStudent, n, newStudent);
	printf("\nAfter insert: ");
	printArrayStudent(arrStudent, n);

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

int getPositionInsert(Student arrStudent[], int n, Student newStudent)
{
	for (int i = 0; i < n; i++)
	{
		if (avgScore(newStudent) < avgScore(arrStudent[i]))
		{
			return i;
		}
	}
	return n;
}

void insertToArrByPosition(Student arrStudent[], int &n, int pos, Student x)
{
	n++;
	for (int i = n - 1; i >= pos; i--)
		arrStudent[i] = arrStudent[i - 1];
	arrStudent[pos - 1] = x;
}
/* END FUNTIONS HELPER */
bool operator<(Date a, Date b)
{
	if (a._year > b._year)
	{
		return true;
	}
	else if (a._year == b._year)
	{
		if (a._month > b._month)
		{
			return true;
		}
		else if (a._month == b._month)
		{
			if (a._day > b._day)
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
	printf("Fill ID: ");
	scanf("%d", &obj._id);
	printf("Fill Name: ");
	fflush(stdin);
	cin.ignore();
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
	if (obj._id != 0)
	{
		printf("\nID = %d", obj._id);
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
void insertionSort(Student arrStudent[], int n)
{
	Student key;
	int i, j;
	for (i = 1; i < n; i++)
	{
		key = arrStudent[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
		while (j >= 0 && avgScore(arrStudent[j]) > avgScore(key))
		{
			arrStudent[j + 1] = arrStudent[j];
			j = j - 1;
		}
		arrStudent[j + 1] = key;
	}
}

void insertNewStudent(Student arrStudent[], int &n, Student newStudent)
{
	printAStudent(newStudent);
	int pos = getPositionInsert(arrStudent, n, newStudent);
	insertToArrByPosition(arrStudent, n, pos + 1, newStudent);
}
/* END FUNTIONS HANDLE */
