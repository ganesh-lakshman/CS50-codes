#include<stdio.h>
#include<stdlib.h>

int main(void)
{
   /* int *list;
    list=malloc(3 * sizeof(int));
    if (list==NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = malloc(4 * sizeof(int));
    if (tmp==NULL)
    {
        return 1;
    }
    for(int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;
    int *tmp = realloc(list,4 * sizeof(int));
    if (tmp==NULL)
    {
        return 1;
    }
    tmp[3] = 4;
  //  free(list);
    list=tmp;
   // free(tmp);only malloc we have to use free

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    free(list);*/
    typedef struct nodes
    {
        int number;
        struct nodes *next;//pointer to next node we need a structure pointer and that we call as node
    }
    node;
    node *list=NULL;//initially the list is empty pointer to a node
    node *n1 = malloc(sizeof(node));//space for node and n is node structure
    if(n1 != NULL)
    {
        n1->number = 2;//(*n).number=2
        n1->next=NULL;//no next node yet adress of the next node
    }
    list = n1;//arrow to node
    node *tmp = list;
   /* printf("n1 number %i\n",n1->number);//n1 number 2
    printf("adress %p",n1);//adress 0x1ad4260list

    printf("list numbre %i\n",list->number);//numbre 2
    printf("list next pointer %p",list->next);//list next pointer (nil)*/
    //list has n1 adress , list's next field is empty so as n1's next field.
    //so tmp has list adress which is n1's adress of which next field is empty

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    //it goes to list struct and watches next field which has 2's node pointing
    //and tmp node has 2's node since 2's next is NULL
    node *n2 = malloc(sizeof(node));//space for node and n is node structure
    //we ca use same n1 but thanks to malloc this time its givs different block of memory
    //n1 2 n3 n4 n5 can be n but we shouldnt redclare
    if(n2 != NULL)
    {
        n2->number = 4;//(*n).number=2
        n2->next=NULL;//no next node yet
    }
    tmp->next=n2; //n->next = n;this line changes the 2's next arrow to 4's node
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    //updating tmp node which is 2 n1's adress in previous block to 4's n2's node adress
    //now tmp has 4's node n2's adress
    node *n3 = malloc(sizeof(node));//space for node and n is node structure
    if(n3 != NULL)
    {
        n3->number = 5;//(*n).number=2
        n3->next=NULL;//no next node yet
    }
    tmp->next = n3;//updateing 4's next node to 5
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }//udating tmp to 5 node

    node *n4 = malloc(sizeof(node));//space for node and n is node structure
    if(n4 != NULL)
    {
        n4->number = 1;//(*n).number=2
        n4->next=NULL;//no next node yet
    }
    n4->next = list;//list pointing at 2 and now 1 also pointing at 2
    list = n4;//now updating list to point to 1
    for (node *tmpr = list; tmpr != NULL; tmpr = tmpr->next)
    {
        printf("%i\n",tmpr->number);
    }
    while (list != NULL)
    {
        node *tmp1 = list->next;//free behind memory not infront once freed we shouldnt touch it
        free(list);
        list = tmp1;
    }
    node *n5 = malloc(sizeof(node));//space for node and n is node structure
    if(n5 != NULL)
    {
        n5->number = 3;//(*n).number=2
        n5->next=NULL;//no next node yet
    }//to update 3 in the list in a sorted order its tough cause we have to iterate along the code

}