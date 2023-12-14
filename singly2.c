#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start = NULL;
int n = 0;
void main()
{
    int ch = 0, p, d;
    while (ch != 8)
    {
        printf("\n 1.Create list");
        printf("\n 2.Display list");
        printf("\n 3.Insert element");
        printf("\n 4.Delete element");
        printf("\n 5.Search list");
        printf("\n 6.Print reverse");
        printf("\n 7.Count number of elements in the list");
        printf("\n 8.exit");
        printf("\n");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (start == NULL)
                createlist();
            else
                printf("\n List already exist");
            break;
        case 2:
            if (start != NULL)
                printlist();
            break;
        case 3:
            if (start != NULL)
            {
                printf("\n Enter position:");
                scanf("%d", &p);
                if ((p > 0) && (p <= n + 1))
                    addnode(p);
                else
                    printf("\n invalid position");
            }
            break;
        case 4:
            if (start != NULL)
            {
                printf("\n Enter position:");
                scanf("%d", &p);
                if ((p > 0) && (p <= n))
                    deletenode(p);
                else
                    printf("\n invalid position");
            }
            break;
        case 5:
            if (start != NULL)
            {
                printf("\n Enter data to search:");
                scanf("%d", &d);
                p = searchlist(d);
                if (p == 0)
                    printf("\n data not found");
                else
                    printf("\n Data found at pointer %d", p);
            }
            break;
        case 6:
            if (start != NULL)
                printreverse(start);
            break;
        case 7:
            if (start != NULL)
                printf("Elements are: %d", count(start));
            break;
        case 8:
            break;
        }
    }
}
void createlist()
{
    int k;
    struct node *temp, *last;
    printf("\n How many elements to create:");
    scanf("%d", &k);
    n = k;
    while (k > 0)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("\n Enter data:");
        scanf("%d", &temp->data);
        if (start == NULL)
        {
            start = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
        k--;
        last->next = NULL;
    }
}
void printlist()
{
    struct node *temp;
    for (temp = start; temp != NULL; temp = temp->next)
        printf("%4d", temp->data);
}
void addnode(int p)
{
    struct node *temp, *t1;
    int i;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &temp->data);
    if (p == 1)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        for (i = 1, t1 = start; i < p - 1; t1 = t1->next, i++)
            ;
        temp->next = t1->next;
        t1->next = temp;
    }
    n++;
}
void deletenode(int p)
{
    struct node *temp, *t1;
    int i;
    if (p == 1)
    {
        temp = start;
        start = start->next;
    }
    else
    {
        for (i = 1, t1 = start; i < p - 1; t1 = t1->next, i++)
            ;
        temp = t1->next;
        t1->next = temp->next;
    }
    free(temp);
    n--;
}
int searchlist(int d)
{
    struct node *t1;
    int i = 1;
    t1 = start;
    while (t1 != NULL)
    {
        if (t1->data == d)
            return i;
        i++;
        t1 = t1->next;
    }
    return 0;
}
int printreverse(struct node *t1)
{
    if (t1 != NULL)
    {
        printreverse(t1->next);
        printf("%d", t1->data);
    }
    return 0;
}
int count(struct node *head)
{
    int count = 0;
    struct node *current = start;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

