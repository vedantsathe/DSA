#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[50];
    float percentage;
};

int compareStudents(const void *a, const void *b)
{
    return ((struct Student *)a)->rollNo - ((struct Student *)b)->rollNo;
}

int binarySearch(struct Student students[], int left, int right, int targetRollNo)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (students[mid].rollNo == targetRollNo)
            return mid;

        if (students[mid].rollNo < targetRollNo)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    int i;
    for (i = 0; i < n; ++i)
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);

        printf("Name: ");
        // Use %49[^\n] to read up to 49 characters until a newline is encountered
        scanf(" %49[^\n]", students[i].name);

        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    qsort(students, n, sizeof(struct Student), compareStudents);

    int targetRollNo;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &targetRollNo);

    int result = binarySearch(students, 0, n - 1, targetRollNo);

    if (result != -1)
    {
        printf("Student found!\n");
        printf("Roll No: %d\n", students[result].rollNo);
        printf("Name: %s\n", students[result].name);
        printf("Percentage: %.2f\n", students[result].percentage);
    }
    else
    {
        printf("Student not found.\n");
    }

    return 0;
}
