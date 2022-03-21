/*

Disciplina: AED - Algoritmos e Estruturas de Dados UFPel PPGC 2022/I 21/03 - 15h
Aluno: Raffael Bottoli Schemmer

Enunciado do Problema:

1. Seguindo a notação para lista duplamente encadeada (com cabeça) escreva os seguintes algoritmos:

    1.1. Algoritmo que insere um elemento X no fim da lista
    1.2. Remove um elemento X no início da lista
    1.3. Remover um elemento X do fim da lista
    1.4. Trocar as informações entre dois elementos da lista

2. Escrever um algoritmo (baseado no bubblesort) para:

    2.1 Ordenação das informações dos elementos da lista seja feita (baseado no bubblesort).
    2.2 Inserção seja sempre em ordem crescente.

*/

#include <stdio.h>
#include <stdlib.h>

// Struct that represent the node element
typedef struct node
{

    struct node *left;
    struct node *right;
    int value;

} node;

typedef node list;

/*
    [OK] Start the list
*/
void startList(list *head)
{

    /* ........................... */
    /*       [L][HEAD][R]         */
    /* ......................... */

    head->left = head;
    head->right = NULL;
    head->value = 0;
}

/*
    [OK] Show the list
*/
void showList(list *head)
{

    /* ........................................ */
    /*     [L][HEAD][R] ... [L][END][R]        */
    /* ...................................... */

    list *p = head->right;

    printf("List : ");
    while (p->right != head || p->right != NULL)
    {
        printf(" %d", p->value);
        p = p->right;
    }
}

/*
    [OK] Insert value at end of list
    1.1. Algorith that insert X element in the end of list
*/
void insertValueAtEnd(list *head, int value)
{
    /* ......................................... */
    /* [L][HEAD][R]   [L][NODE][R]   [L][END][R] */
    /* ......................................... */

    /*
        [OK] 1. Create new node
        [OK] 2. Find end of list or last node (head->left)
        [OK] 3. Point right of last node to the newNode (lastNode->right = newNode)
        [OK] 4. Point left of last node to the lastNode (newNode->left = lastNode)
        [OK] 5. Set value of newNode
        [OK] 6. Point right of newNode to the head (newNode->right = head)
        [OK] 7. Point left of head to the newNode (head->left = newNode)
    */

    // [OK] 1. Create new node
    list *newNode;
    newNode = (node *)malloc(sizeof(node));

    // [OK] 2. Find end of list or last node (head->left)
    list *lastNode = (node *)malloc(sizeof(node));
    lastNode = head->left;

    // [OK] 3. Point right of last node to the newNode (lastNode->right = newNode)
    lastNode->right = newNode;

    // [OK] 4. Point left of new node to the lastNode (newNode->left = lastNode)
    newNode->left = lastNode;

    // [OK] 5. Set value of newNode
    newNode->value = value;

    // [OK] 6. Point right of newNode to the head (newNode->right = head)
    newNode->right = head;

    // [OK] 7. Point left of head to the newNode (head->left = newNode)
    head->left = newNode;
}

/*
    [OK] Remove Value at Start of List
    1.2. Remove a X element to the start of list
*/
int removeValueatStart(list *head)
{

    /* ......................................... */
    /* [L][HEAD][R]   [L][NODE][R]   [L][END][R] */
    /* ......................................... */

    /*
        [OK] 1. Make pointer to the first node of list
        [OK] 2. If list is not empty capture first node of list (removeNode = head->right)
        [OK] 3. Capture the new candidate to the first node
        [OK] 4. Make head point to the newFirstNode
        [OK] 5. Make newFirstNode point to the head
    */

    // [OK] 1. Make pointer to the first node of list
    if (head->right != NULL)
    {
        // [OK] 2. If list is not empty capture first node of list (removeNode = head->right)
        list *removeNode = (node *)malloc(sizeof(node));
        removeNode = head->right;

        // [OK] 3. Capture the new candidate to the first node
        list *newFirstNode = (node *)malloc(sizeof(node));
        newFirstNode = removeNode->right;

        // [OK] 4. Make head point to the newFirstNode
        head->right = newFirstNode;

        // [OK] 5. Make newFirstNode point to the head
        newFirstNode->left = head;

        return (1);
    }
    else
    {
        return (0);
    }
}

/*
    [OK] Remove Value at End of List
    1.3. Remove a X element to the end of list
*/
int removeValueatEnd(list *head)
{

    /* ......................................... */
    /* [L][HEAD][R]   [L][NODE][R]   [L][END][R] */
    /* ......................................... */

    /*
        [OK] 1. Make pointer to the end node of list
        [OK] 2. If list is not empty capture last node of list (removeNode = head->left)
        [OK] 3. Capture the new candidate to the last node
        [OK] 4. Make head point to the newLastNode
        [OK] 5. Make newLastNode point to the head
    */

    // [OK] 1. Make pointer to the first node of list
    if (head->right != NULL)
    {
        // [OK] 2. If list is not empty capture first node of list (removeNode = head->right)
        list *removeNode = (node *)malloc(sizeof(node));
        removeNode = head->left;

        // [OK] 3. Capture the new candidate to the last node
        list *newLastNode = (node *)malloc(sizeof(node));
        newLastNode = removeNode->left;

        // [OK] 4. Make head point to the newLastNode
        head->left = newLastNode;

        // [] 5. Make newLastNode point to the head
        newLastNode->right = head;

        return (1);
    }
    else
    {
        return (0);
    }
}

/*
    [OK] Change Values of Positions in List
    1.4. Exchange information between two list elements
*/
int changeValues(list *head, int p1, int p2)
{

    /* ......................................... */
    /* [L][HEAD][R]   [L][NODE][R]   [L][END][R] */
    /* ......................................... */

    /*
        [OK] 1. Make pointer to the end node of list
        [OK] 2. Make a Loop that find P1 position and capture the pointer of node
        [OK] 3. Make a Loop that find P2 position and capture the pointer of node
        [OK] 4. If two position were found change values
    */

    int size = 0;
    // [OK] 1. Make pointer to the first node of list
    if (head->right != NULL)
    {

        // [OK] 2. Make a Loop that find P1 position and capture the pointer of node
        list *nodep1 = NULL;

        list *tmpNode = (node *)malloc(sizeof(node));
        tmpNode = head;
        size = 0;
        while (head->left != tmpNode->right)
        {
            if (p1 == size)
            {
                nodep1 = (node *)malloc(sizeof(node));
                nodep1 = tmpNode;
                break;
            }

            size++;
            tmpNode = tmpNode->right;
        }

        // [OK] 3. Make a Loop that find P2 position and capture the pointer of node
        list *nodep2 = NULL;

        tmpNode = head;
        size = 0;
        while (head->left != tmpNode->right)
        {
            if (p2 == size)
            {
                nodep2 = (node *)malloc(sizeof(node));
                nodep2 = tmpNode;
                break;
            }

            size++;
            tmpNode = tmpNode->right;
        }

        // [OK] 4. If two position were found change values
        if (nodep1 != NULL && nodep2 != NULL)
        {
            int tmpValue = 0;
            tmpValue = nodep1->value;
            nodep1->value = nodep2->value;
            nodep2->value = tmpValue;
            return (1);
        }
        else
        {
            return (0);
        }
    }
    else
    {
        return (0);
    }
}

/*
    [OK] Sort List Using BubbleSort
    2.1. Ordering of list elements information is done (based on bubblesort)
*/
int sortListBubble(list *head)
{
    /* ......................................... */
    /* [L][HEAD][R]   [L][NODE][R]   [L][END][R] */
    /* ......................................... */

    /*
        [OK] 1. Capture the head node in temp variable
        [OK] 2. Cycles through all positions in the list starting from the head
        [OK] 3. Compare the current tmp Node position with all positions to the end of the tmpNext list
        [OK] 4. Swap values to sort positions ascending
    */

    if (head->right != NULL)
    {

        // [OK] 1. Capture the head node in temp variable
        list *tmpNode = (node *)malloc(sizeof(node));
        tmpNode = head;
        int taux;

        // [OK] 2. Cycles through all positions in the list starting from the head
        while (head->left != tmpNode->right)
        {
            list *tmpNext = (node *)malloc(sizeof(node));
            tmpNext = tmpNode->right;
            // [OK] 3. Compare the current tmp Node position with all positions to the end of the tmpNext list
            while (head->left != tmpNext->right)
            {
                // [OK] 4. Swap values to sort positions ascending
                if (tmpNode->value > tmpNext->value)
                {
                    taux = tmpNode->value;
                    tmpNode->value = tmpNext->value;
                    tmpNext->value = taux;
                }
                tmpNext = tmpNext->right;
            }
            tmpNode = tmpNode->right;
        }

        return (1);
    }
    else
    {
        return (0);
    }
}

/*
    [OK] Insert Value using BubbleSort Sorting
    2.2. Insertion always in ascending order
*/
int insertValueSort(list *head, int value)
{
    /* ......................................... */
    /* [L][HEAD][R]   [L][NODE][R]   [L][END][R] */
    /* ......................................... */

    /*
        [OK] 1. Create a temporary node to loop through the list
        [OK] 2. Walks through the list looking for the position that should receive the value
        [OK] 3. Create a new node that will receive the new value
        [OK] 4. Capture the next value in the list
        [OK] 5. Makes the current position point to newNode
        [OK] 6. Makes the new position point to current and next
        [OK] 7. Makes the position of the next one point to the current one
    */

    if (head->right != NULL)
    {

        // [OK] 1. Create a temporary node to loop through the list
        list *tmpNode = (node *)malloc(sizeof(node));
        tmpNode = head;

        // [OK] 2. Walks through the list looking for the position that should receive the value
        while (head->left != tmpNode->right)
        {
            if (tmpNode->value <= value)
            {

                // [OK] 3. Create a new node that will receive the new value
                list *newNode = (node *)malloc(sizeof(node));
                list *nextNode = (node *)malloc(sizeof(node));

                // [OK] 4. Capture the next value in the list
                nextNode = tmpNode->right;

                // [OK] 5. Makes the current position point to newNode
                tmpNode->right = newNode;

                // [OK] 6. Makes the new position point to current and next
                newNode->left = tmpNode;
                newNode->value = value;
                newNode->right = nextNode;

                // [OK] 7. Makes the position of the next one point to the current one
                nextNode->left = newNode;

                break;
            }
        }

        return (1);
    }
    else
    {
        return (0);
    }
}

/* [OK] Graphic Interface of Application */
int main()
{

    list *head;
    head = (list *)malloc(sizeof(list));
    startList(head);

    int opt = 0, value;
    int p1, p2;
    system("cls");
    do
    {
        printf("\n\n| -- Doubly Chained List With Ording -- ||\n");
        printf("  1 - Insert element X in the last of list\n");
        printf("  2 - Remove element to the start of list\n");
        printf("  3 - Remove elemento to the end of list\n");
        printf("  4 - Exchanges information between two list elements\n");
        printf("  5 - Sort elements based on BubbleSort\n");
        printf("  6 - Insert element in the list in an ordered way\n");
        printf("  0 - Out\n");
        printf("Opcao : ");
        scanf("%d", &opt);
        fflush(stdin);
        switch (opt)
        {

        case (0):
            system("cls");
            break;

        // 1.1. Algorith that insert X element in the end of list
        case (1):

            system("cls");
            printf("Enter the value to be inserted at the end of the list: ");
            scanf("%d", &value);
            insertValueAtEnd(head, value);
            showList(head);
            system("pause");
            system("cls");
            break;

        //  1.2. Remove a X element to the start of list
        case (2):

            system("cls");
            value = removeValueatStart(head);

            if (value == 1)
                printf("Removed node from the beginning of the list\n", value);
            else
                printf("No elements have been removed because list is empty\n", value);

            showList(head);
            system("pause");
            system("cls");

            break;

        //  1.3. Remove a X element to the end of list
        case (3):

            system("cls");
            value = removeValueatEnd(head);

            if (value == 1)
                printf("Removed node from the end of the list\n", value);
            else
                printf("No elements have been removed because list is empty\n", value);

            showList(head);
            system("pause");
            system("cls");

            break;

        // 1.4. Exchange information between two list elements
        case (4):

            system("cls");
            printf("Enter the position of the first value: ");
            scanf("%d", &p1);

            printf("Enter the position of the second value: ");
            scanf("%d", &p2);

            value = changeValues(head, p1, p2);

            if (value == 1)
                printf("Exchanged information between two list elements\n", value);
            else
                printf("The enter positions were not found in the list or list is empty\n", value);

            showList(head);
            system("pause");
            system("cls");

            break;

        // 2.1. Ordering of list elements information is done (based on bubblesort)
        case (5):

            system("cls");
            sortListBubble(head);

            if (value == 1)
                printf("Ascending value entered\n", value);
            else
                printf("The list is empty\n", value);

            showList(head);
            system("pause");
            system("cls");

            break;

        // 2.2. Insertion always in ascending order
        case (6):

            system("cls");
            printf("Enter the value to be inserted (in order): ");
            scanf("%d", &value);
            insertValueSort(head, value);

            if (value == 1)
                printf("\n", value);
            else
                printf("The list is empty\n", value);

            showList(head);
            system("pause");
            system("cls");

            break;

        // Default option of menu
        default:

            system("cls");
            printf("Invalid Option!\n");
            system("pause");
            system("cls");

            continue;
        }
    } while (opt != 0);
    return 0;
}
