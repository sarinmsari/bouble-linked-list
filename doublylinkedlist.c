#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;

void insertion()
{
    int inneropt = 0, element;

    void beginninginsertion()
    {
        struct node *ptr;
        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == NULL)
        {
            printf("\nOVERFLOW\n");
        }
        else
        {
            printf("\nEnter element to be inserted:");
            scanf("%d", &element);

            if (head == NULL)
            {
                ptr->next = NULL;
                ptr->prev = NULL;
                ptr->data = element;
                head = ptr;
            }
            else
            {
                ptr->data = element;
                ptr->prev = NULL;
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
            }
            printf("\nNode inserted\n");
        }
    }

    void intermediateinsertion()
    {
        struct node *ptr, *temp;
        int loc, i;
        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == NULL)
        {
            printf("\n OVERFLOW\n");
        }
        else
        {
            temp = head;
            printf("Enter the location:");
            scanf("%d", &loc);
            if (loc <= 1)
            {
                printf("\nInvalid position or first position\n");
                return;
            }
            for (i = 0; i < loc; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    printf("\n There are less than %d elements\n", loc);
                    return;
                }
            }
            printf("Enter value");
            scanf("%d", &element);
            ptr->data = element;
            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next = ptr;
            temp->next->prev = ptr;
            printf("\nnode inserted\n");
        }
    }

    void endinsertion()
    {
        struct node *ptr, *temp;
        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == NULL)
        {
            printf("\nOVERFLOW\n");
        }
        else
        {
            printf("\nEnter element to be inserted:");
            scanf("%d", &element);
            ptr->data = element;
            if (head == NULL)
            {
                ptr->next = NULL;
                ptr->prev = NULL;
                head = ptr;
            }
            else
            {
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = ptr;
                ptr->prev = temp;
                ptr->next = NULL;
            }
            printf("\nnode inserted\n");
        }
    }

    while (inneropt != 4)
    {
        printf("\n1.Insert at beginning\n2.Insert at intermediate position\n3.Insert at end\n4.exit\nChoose an option:");
        scanf("%d", &inneropt);
        switch (inneropt)
        {
        case 1:
            beginninginsertion();
            break;
        case 2:
            intermediateinsertion();
            break;
        case 3:
            endinsertion();
            break;
        case 4:
            break;
        default:
            printf("\nEnter a valid number");
        }
    }
}

void deletion()
{
    int inneropt = 0;

    void beginningdeletion()
    {
        struct node *ptr;
        if (head == NULL)
        {
            printf("\n UNDERFLOW\n");
        }
        else if (head->next == NULL)
        {
            head = NULL;
            free(head);
            printf("\nnode deleted\n");
        }
        else
        {
            ptr = head;
            head = head->next;
            head->prev = NULL;
            free(ptr);
            printf("\nnode deleted\n");
        }
    }

    void intermediatedeletion()
    {
        struct node *ptr, *temp;
        int val;
        printf("\n Enter the data after which the node is to be deleted : ");
        scanf("%d", &val);
        ptr = head;
        while (ptr->data != val)
            ptr = ptr->next;
        if (ptr->next == NULL)
        {
            printf("\nCan't find %d\n",val);
        }
        else if (ptr->next->next == NULL)
        {
            ptr->next = NULL;
            printf("\nnode deleted\n");
        }
        else
        {
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            free(temp);
            printf("\nnode deleted\n");
        }
    }

    void enddeletion()
    {
        struct node *ptr;
        if (head == NULL)
        {
            printf("\n UNDERFLOW\n");
        }
        else if (head->next == NULL)
        {
            head = NULL;
            free(head);
            printf("\nnode deleted\n");
        }
        else
        {
            ptr = head;
            if (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->prev->next = NULL;
            free(ptr);
            printf("\nnode deleted\n");
        }
    }

    while (inneropt != 4)
    {
        printf("\n1.Delete from beginning\n2.Delete from intermediate position\n3.Delete from end\n4.exit\nChoose an option:");
        scanf("%d", &inneropt);
        switch (inneropt)
        {
        case 1:
            beginningdeletion();
            break;
        case 2:
            intermediatedeletion();
            break;
        case 3:
            enddeletion();
            break;
        case 4:
            break;
        default:
            printf("\nEnter a valid number");
        }
    }
}

void display()
{
    struct node *ptr;  
    printf("\n printing values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\t",ptr->data);  
        ptr=ptr->next;  
    } 
}

void main()
{
    int opt = 0;
    while (opt != 4)
    {
        printf("1.Insert\n2.Delete\n3.dispaly\n4.exit\nChoose an option:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("\nEnter a valid option");
        }
    }
}
