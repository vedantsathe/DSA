#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct car
{
    char model[50];
    int price;
    char manuname[50];
    int engine;
    struct car *prev;
    struct car *next;
};
struct car *head = NULL;
int n = 0, p;
void createcar()
{
    int k;
    struct car *newcar;
    printf("\n How many cars to create:");
    scanf("%d", &k);
    n = k;
    while (k > 0)
    {
        newcar = (struct car *)malloc(sizeof(struct car));
        printf("\n Enter car model:");
        scanf("%s", &newcar->model);
        printf("\nEnter car price:");
        scanf("%d", &newcar->price);
        printf("\nEnter car manufacture name:");
        scanf("%s", &newcar->manuname);
        printf("\nEnter engine Capacity:");
        scanf("%d", &newcar->engine);
        newcar->next = NULL;
        newcar->prev = NULL;
        if (head == NULL)
        {
            head = newcar;
        }
        else
        {
            struct car *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newcar;
            newcar->prev = curr;
        }
        k--;
    }
}
void display()
{
    struct car *temp;
    printf("\n Car List:");
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("\nmodel of car:%s", temp->model);
        printf("\nPrice of car:%d", temp->price);
        printf("\nManufacture name of car:%s", temp->manuname);
        printf("\nEngine capacity of car:%d", temp->engine);
    }
}
void deletecar()
{
    struct car *curr = head;
    char model[50];
    printf("\n Enter a car model to delete:");
    scanf("%s", model);
    while (curr != NULL)
    {
        if (strcmp(curr->model, model) == 0)
        {
            if (curr->prev != NULL)
            {
                curr->prev->next = curr->next;
            }
            else
            {
                head = curr->next;
            }
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }
            free(curr);
            printf("car deleted sucessfully");
        }
        curr = curr->next;
    }
    printf("\n Data not found..");
}
void listcarswithrange()
{
    struct car *curr = head;
    float min, max;
    printf("\n Enter minimum price:");
    scanf("%d", &min);
    printf("\n Enter maxmimum price:");
    scanf("%d", &max);
    while (curr != NULL)
    {
        if (curr->price >= min && curr->price <= max)
        {
	printf("model:%s,price:%d,manufacture name:%s,Engine Capacity:%d",curr->model,curr->price,curr->manuname,curr->engine);
        }
        curr = curr->next;
    }
    printf("Car not found");
}
void insertcar(int p)
{
    struct car *newcar, *t1, *end;
    int i;
    newcar = (struct car *)malloc(sizeof(struct car));
    printf("\n Enter car model:");
    scanf("%s", &newcar->model);
    printf("\nEnter car price:");
    scanf("%d", &newcar->price);
    printf("\nEnter car manufacture name:");
    scanf("%s", &newcar->manuname);
    printf("\nEnter engine Capacity:");
    scanf("%d", &newcar->engine);
    newcar->next = NULL;
    newcar->prev = NULL;
    if (p == 1)
    {
        newcar->next = head;
        head->prev = newcar;
        head = newcar;
    }
    else if (p == n + 1)
    {
        for (i = 1, end = head; i < p - 1; end = end->next, i++)
            ;
        end->next = newcar;
        newcar->prev = end;
        end = newcar;
        end->next = NULL;
    }
    else
    {
        for (i = 1, t1 = head; i < p - 1; t1 = t1->next, i++)
            ;
        newcar->next = t1->next;
        t1->next->prev = newcar;
        t1->next = newcar;
        newcar->prev = t1;
    }
    n++;
}
void main()
{
    int choice;
    while (1)
    {
        printf("\n1.Create car");
        printf("\n2.Display car");
        printf("\n3.Delete car");
        printf("\n4.Find Car");
        printf("\n5.Insert new car");
        printf("\n6.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createcar();
            break;
        case 2:
            display();
            break;
        case 3:
            deletecar();
            break;
        case 4:
            listcarswithrange();
            break;
        case 5:
            if (head != NULL)
            {
                printf("\n enter position:");
                scanf("%d", &p);
                if ((p > 0) && (p <= n + 1))
                    insertcar(p);
                else
                    printf("\n invalid position");
            }
            break;
        case 6:
            break;
        }
    }
}

