#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    char *itemName;
    float price;
    int quantity;
    float amount;
};
void printItem(struct Item *item);
void readItem(struct Item *item);
_Bool wantToContinue();

int main(int argc, char *argv[])
{
    int itemCount = 0;
    struct Item *items = NULL;
    items = malloc(3 * sizeof(struct Item));

    do
    {
        if (itemCount != 0 && itemCount % 3 == 0)
        {
            items = realloc(items, (itemCount * 2) * sizeof(struct Item));
        }

        struct Item item;
        struct Item *pItem = NULL;
        pItem = &item;

        pItem->itemName = (char *)malloc(100 * sizeof(char));
        if (pItem == NULL)
            return -1;

        readItem(pItem);
        *(items + itemCount) = item;
        itemCount++;
    } while (wantToContinue());

    printf("\n***** Item Details *****\n");
    for (int i = 0; i < itemCount; i++)
    {
        printItem((items + i));
        free((items + i)->itemName);
        (items + i)->itemName = NULL;
    }

    free(items);
    items = NULL;
    return 0;
}

void printItem(struct Item *item)
{
    printf("Name:\t\t%s\n", item->itemName);
    printf("Price:\t\t$%.2f\n", item->price);
    printf("Quantity:\t%d\n", item->quantity);
    printf("Amount:\t\t$%.2f\n\n", item->amount);
}

void readItem(struct Item *item)
{
    printf("\nEnter the items name: ");
    scanf("%s", item->itemName);
    printf("Enter the items price: ");
    scanf("%f", &item->price);
    printf("Enter the items quantity: ");
    scanf("%d", &item->quantity);

    item->amount = (float)item->price * item->quantity;
}

_Bool wantToContinue()
{
    int answer;
    printf("\nDo you want to continue? No(0) Yes(1): ");
    scanf("%d", &answer);

    if (answer)
        return 1;

    return 0;
}