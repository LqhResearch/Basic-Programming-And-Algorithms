/**************************************************************
 * Author: QHung
 * Created at: 30/05/2021
 * Updated at: 00/00/0000
 * Topic: Nha hien triet an toi
 **************************************************************/
#include <stdio.h>
#define n 4

int compltedPhilo = 0, i;

struct fork {
    int taken;
}
ForkAvil[n];

struct philosp
{
    int left;
    int right;
}
Philostatus[n];

void goForDinner(int philID)
{
    if (Philostatus[philID].left == 10 && Philostatus[philID].right == 10)
        printf("Nha hien triet thu %d hoan thanh bua an toi.\n", philID + 1);
    else if (Philostatus[philID].left == 1 && Philostatus[philID].right == 1)
    {
        printf("Nha hien triet thu %d hoan thanh bua an toi.\n", philID + 1);
        Philostatus[philID].left = Philostatus[philID].right = 10;
        int otherFork = philID - 1;
        if (otherFork == -1)
            otherFork = (n - 1);
        ForkAvil[philID].taken = ForkAvil[otherFork].taken = 0;
        printf("Nha hien triet thu %d dua %d va dua %d\n", philID + 1, philID + 1, otherFork + 1);
        compltedPhilo++;
    }
    else if (Philostatus[philID].left == 1 && Philostatus[philID].right == 0)
    {
        if (philID == (n - 1))
        {
            if (ForkAvil[philID].taken == 0)
            {
                ForkAvil[philID].taken = Philostatus[philID].right = 1;
                printf("Dua %d duoc lay boi nha hien triet %d\n", philID + 1, philID + 1);
            }
            else
            {
                printf("Nha hien triet %d dang doi dua %d\n", philID + 1, philID + 1);
            }
        }
        else
        {
            int dupphilID = philID;
            philID -= 1;
            if (philID == -1)
                philID = (n - 1);
            if (ForkAvil[philID].taken == 0)
            {
                ForkAvil[philID].taken = Philostatus[dupphilID].right = 1;
                printf("Dua %d duoc lay boi nha hien triet %d\n", philID + 1, dupphilID + 1);
            }
            else
                printf("Nha hien triet %d dang doi dua %d\n", dupphilID + 1, philID + 1);
        }
    }
    else if (Philostatus[philID].left == 0)
    {
        if (philID == (n - 1))
        {
            if (ForkAvil[philID - 1].taken == 0)
            {
                ForkAvil[philID - 1].taken = Philostatus[philID].left = 1;
                printf("Dua %d duoc lay boi nha hien triet %d\n", philID, philID + 1);
            }
            else
                printf("Nha hien triet %d dang doi dua %d\n", philID + 1, philID);
        }
        else
        {
            if (ForkAvil[philID].taken == 0)
            {
                ForkAvil[philID].taken = Philostatus[philID].left = 1;
                printf("Dua %d duoc lay boi nha hien triet %d\n", philID + 1, philID + 1);
            }
            else
                printf("Nha hien triet %d dang doi dua %d\n", philID + 1, philID + 1);
        }
    }
    else { }
}

int main()
{
    for (i = 0; i < n; i++)
        ForkAvil[i].taken = Philostatus[i].left = Philostatus[i].right = 0;
    while (compltedPhilo < n)
    {
        for (i = 0; i < n; i++)
            goForDinner(i);
        printf("\nSo nha hien triet da hoan thanh bua an toi la %d\n\n", compltedPhilo);
    }
    return 0;
}

