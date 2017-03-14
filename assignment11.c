/*******************************/
/* Programmer: Nathan Woodward */
/* Program: assignment11.c     */
/* Approximate time: 3 hours  */
/*******************************/

/* 
   This program manipulates a linked list
   given options through a menu and can print
   the linked list backwards recursively and
   iteratively
*/

#include <stdio.h>
#include <stdlib.h>
 
/* declaration of structure */
typedef struct node{
  int data;
  struct node *next;
} NODE;
 
/* declaration of template functions */
NODE* insert_node(NODE *ptr, NODE *new);
NODE* find_node(NODE *ptr, int n);
NODE* delete_node(NODE *ptr, int n, int *success_flag_ptr);
void print_backward_iteration(NODE *ptr);
void print_backward_recursion(NODE *ptr);
 
/* declaration of user functions */
int menu();
 
int main(int argc, char *argv[])
{
  int start, n;
  NODE* list;
  NODE* new_node;
  list = NULL;
  int success_flag;
  int *success_flag_ptr;
  success_flag_ptr = &success_flag;
  do
  {
    start = menu();
   
    switch(start)
    {
      case 6:
              printf("Thank you!\n");
              return 0;
              break;
             
      case 5:
              print_backward_recursion(list);
              printf("\n");
              break;
             
      case 4:
              print_backward_iteration(list);
              printf("\n");
              break;
             
      case 3:
              printf("Please enter a number to delete: ");
              scanf("%d", &n);
              list = delete_node(list, n, success_flag_ptr);
              if(*success_flag_ptr == 0)
                printf("No nodes deleted.\n");
              else if(*success_flag_ptr == 1)
                printf("Deleted %d integer from the list.\n", n);
              break;
             
      case 2:
              printf("Please enter a number: ");
              scanf("%d", &n);
              if(NULL == find_node(list, n))
                printf("Did not find integer.\n");
              else
                printf("Found the integer %d in the list.\n", n);
              break;
             
      case 1:
              printf("Please enter a number: ");
              scanf("%d", &n);
              new_node = (NODE *)malloc((sizeof(NODE)));
              new_node->data = n;
              list = insert_node(list, new_node);
              printf("\n");
              break;
 
      default:
              printf("Invalid choice, try again.\n");
        break;
    }
  }while( start != 6 );
  return 0;
}
 
NODE* insert_node(NODE *ptr, NODE *new)
{
  if (new == NULL)
    return ptr;
  new->next = ptr;
  ptr = new;
  return ptr;
}
 
NODE* find_node(NODE *ptr, int n)
{
 
  NODE* search;
  search = ptr;

  while(search != NULL)
  {
    if(n == search->data)
      return search;
    else
      search = search->next;
  }
  return NULL;
}
 
NODE* delete_node(NODE *ptr, int n, int *success_flag_ptr)
{
  NODE* previous, *current;
 
  if(ptr == NULL)
  {
    *success_flag_ptr = 0;
    return ptr;
  }
 
  previous = ptr;
  current = ptr;
 
  while(current != NULL)
  {
    if(n == current->data)
    {
      previous->next = current->next;
      free(current);
      *success_flag_ptr = 1;
      return ptr;
    }
    previous = current;
    current = current->next;
  }
 
  *success_flag_ptr = 0;
  return ptr;
}
 
void print_backward_iteration(NODE *ptr)
{
  NODE *last, *current;
  last = NULL;

  printf("\n");

  while (ptr != last)
    {
      current = ptr;

      while (current -> next != last)
    {
      current= current -> next;
    }

      printf("%d  ", current -> data);
      last = current;
    }
    printf("\n");
}
 
void print_backward_recursion(NODE *ptr)
{
  if(ptr == NULL){
	  return;
  }
  
  print_backward_recursion(ptr->next);
  printf("%d\n", ptr->data);
}
 
int menu()
{
  int n;
 
  printf("1   Insert integer into linked list\n");
  printf("2   Find integer in linked list\n");
  printf("3   Delete integer from linked list\n");
  printf("4   Print out integers backward using the iterative strategy\n");
  printf("5   Print out integers backward using the recursive strategy\n");
  printf("6   Quit\n\n");
  printf("Enter 1, 2, 3, 4, 5, or 6: ");
 
  scanf("%d", &n);
 
  return n;
}
