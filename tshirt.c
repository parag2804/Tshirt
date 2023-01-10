#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tshirt.h"
#include "readline.h"

void help()
{
    printf("List of operation codes:\n");
    printf("\t'a' for adding a t-shirt to the inventory;\n");
    printf("\t'h' for help;\n");
    printf("\t'o' for searching t-shirts by organization;\n");
    printf("\t's' for searching t-shirts by size;\n");
    printf("\t'p' for printing the inventory;\n");
    printf("\t'q' for quit.\n");
}

//this function adds tshirt to the inventory
struct tshirt * add_to_inventory(struct tshirt *inventory)
{
    char input_org_name[ORG_NAME_LEN + 1];              //string for org name
    char input_tshirt_size[SIZE_LEN + 1];               //string for tshirt size
    double input_price;                                 //double for price
    int input_quantity;                                 //int for quantity
    struct tshirt *temp = inventory;

    if(inventory == NULL)                               //if inventory has nothing
    {
     	printf("\nEnter organization name: ");
        read_line(input_org_name, ORG_NAME_LEN);        //using read_line function to read strin

        printf("\nEnter size of tshirt: ");
        read_line(input_tshirt_size, SIZE_LEN);         //using read_line function to read string

        printf("\nEnter price of tshirt: ");
        scanf("%lf", &input_price);

        printf("\nEnter quantity of tshirt: ");
        scanf("%d", &input_quantity);



        struct tshirt *new_node = malloc(sizeof(struct tshirt));        //linked list new_node
        strcpy(new_node->org_name, input_org_name);                     //copying input_org_name to org_name
        strcpy(new_node->size, input_tshirt_size);
        new_node->price = input_price;
        new_node->quantity = input_quantity;

        inventory = new_node;
        return inventory;
    }

    printf("\nEnter organization name: ");
    read_line(input_org_name, ORG_NAME_LEN);

    printf("\nEnter size of tshirt: ");
    read_line(input_tshirt_size, SIZE_LEN);

    for(temp = inventory; temp->next != NULL; temp = temp -> next)	//for loop if the tshirt already exists
        {
            if(!strcmp(temp->org_name,input_org_name))
            {
                if(!strcmp(temp->size,input_tshirt_size))
                {
                    printf("\nTshirt already exists");
                    return inventory;
                }

                else
                {
                    continue;
                }
            }
        }


    printf("\nEnter price of tshirt: ");
    scanf("%lf", &input_price);

    printf("\nEnter quantity of tshirt: ");
    scanf("%d", &input_quantity);

    struct tshirt *new_node = malloc(sizeof(struct tshirt));

    strcpy(new_node->org_name, input_org_name);
    strcpy(new_node->size, input_tshirt_size);
    new_node->price = input_price;
    new_node->quantity = input_quantity;

    struct tshirt *a, *b;

    for(a = inventory, b = NULL;  a != NULL; b=a, a = a->next)          //for loop to arrange tshirt alphabetically
    {
     	if (strcmp(new_node->org_name,a->org_name)<0)                   //ascending order through org_name
        {
            if (b == NULL)
            {
               new_node->next = a;
               return new_node;
            }

            b->next = new_node;
            new_node->next = a;
            return inventory;
        }

	if(strcmp(new_node->org_name, a->org_name) == 0)
        {
            if(strcmp(new_node->size, a->size) < 0)                 //ascending order through tshirt size if org name same
            {
             	if (b == NULL)
                {
                    new_node->next = a;
                    return new_node;
                }

                b->next = new_node;
                new_node->next = a;
                return inventory;
            }
	}
    }

    b->next = new_node;
    return inventory;
}


//function to search tshirt of a particular organization
void search_by_organization(struct tshirt *inventory)
{
    char input_org_name[ORG_NAME_LEN + 1];
    struct tshirt *temp = inventory;

    printf("\nEnter organization name: ");
    read_line(input_org_name, ORG_NAME_LEN);

    if(temp == NULL)
    {
     	printf("\nno tshirt found!");
        return;
    }

    for(temp = inventory; temp != NULL; temp = temp->next)	//for loop to see if there is a tshirt matching in the inventory
    {
     	if(strcmp(temp->org_name, input_org_name) == 0)
        {
            printf("\n|----------------------------------------------------|-----|-------|------|\n");
            printf("| Student organization                               | Sz. | Price | Qty. |\n");
            printf("|----------------------------------------------------|-----|-------|------|\n");
            printf("| %-50s | %-3s | %5.2f | %4d |\n", temp->org_name, temp->size, temp->price, temp->quantity);
            printf("|----------------------------------------------------|-----|-------|------|\n");
        }
	else
	{
            printf("\nno tshirt found!");
        }
    }
}

//function to search tshirt of a particular size
void search_by_size(struct tshirt *inventory)
{
    struct tshirt *temp;
    char input_tshirt_size[SIZE_LEN + 1];

    printf("\nEnter tshirt size: ");
    read_line(input_tshirt_size, SIZE_LEN);

    if(inventory == NULL)
    {
     	printf("\nno tshirt found!");
        return;
    }

    for(temp = inventory; temp != NULL; temp = temp->next)     //for loop to see if there is a tshirt matching in the inventory
    {
        if(strcmp(temp->size, input_tshirt_size) == 0)
        {
            printf("\n|----------------------------------------------------|-----|-------|------|\n");
            printf("| Student organization                               | Sz. | Price | Qty. |\n");
            printf("|----------------------------------------------------|-----|-------|------|\n");
            printf("| %-50s | %-3s | %5.2f | %4d |\n", temp->org_name, temp->size, temp->price, temp->quantity);
            printf("|----------------------------------------------------|-----|-------|------|\n");
        }
	else
	{
            printf("\nno tshirt found!");
        }
    }
}

//function to print everything there in the inventory
void print_inventory(struct tshirt *inventory)
{
    if(inventory == NULL)
    {
     	printf("\nNo t-shirt found!");
        return;
    }
    printf("\n");
    struct tshirt *temp;
    printf("|----------------------------------------------------|-----|-------|------|\n");
    printf("| Student organization                               | Sz. | Price | Qty. |\n");
    printf("|----------------------------------------------------|-----|-------|------|\n");
    for (temp = inventory; temp != NULL; temp = temp -> next)
    {
     	printf("| %-50s | %-3s | %5.2f | %4d |\n", temp->org_name, temp->size, temp->price, temp->quantity);
        printf("|----------------------------------------------------|-----|-------|------|\n");
    }
}

//function to clear up everything in inventory
void clear_inventory(struct tshirt *inventory)
{
    struct tshirt *temp;
    while(inventory != NULL)
    {
     	temp = inventory;
        inventory = inventory -> next;

        if(temp != NULL)
        {
            free(temp);
        }
    }
}
