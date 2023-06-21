#include "monty.h"
/**
 *stk_toprotate- rotates the stack to the top
 *@head: stack head
 *@counter: line_number
 *Return: Nothing
 */
void stk_toprotate(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
stack_t *tmp = *head, *aux;

if (*head == NULL || (*head)->next == NULL)
{
return;
}
aux = (*head)->next;
aux->prev = NULL;
while (tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;
(*head) = aux;
}