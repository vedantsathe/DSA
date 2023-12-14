#include<stdio.h> 
struct student
{
    int roll, per;
    char name[100];
};
int main()
{
    int i, search,
        array[100], q, n, a, b;
    struct student
        stu[100],
        temp;
printf("Enter number ofStudents:\n");
scanf("%d",&n);
for (i=0; i<n; i++)
{
printf("\nEnter the rollnumber:");
scanf("%d",&stu[i].roll);
printf("\nEnter the name:");
scanf("%s",stu[i].name);
printf("\nEnter the percentage:");
scanf("%d",&stu[i].per);
}
printf("\nThe entered details are:");
for (i = 0; i < n; i++)
{
        printf("\nRoll No is :%d", stu[i].roll);
        printf("\t\tName is : %s", stu[i].name);
printf("\t\tPercentage is : %d",stu[i].per);
}
for (a=0 ; a<n-1; a++)
{
        for (b = 0; b < n - 1; b++)
        {
            if (stu[b].per > stu[b + 1].per) /* For decreasing order use '<' instead of '>' */
            {
                temp = stu[b];
                stu[b] = stu[b + 1];
                stu[b + 1] = temp;
            }
        }
}
printf("\nAfter Sorting the details are:");
for (i = 0; i < n; i++)
{
        printf("\nRoll No is : %d", stu[i].roll);
        printf("\t\tName is : %s", stu[i].name);
printf("\t\tPercentage is : %d",stu[i].per);
}
return 0;
}

