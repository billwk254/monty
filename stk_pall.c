#include "monty.h"
/**
 * stk_pall - prints the stack
 * @head: stack head
 * @counter: unused
 * Return: nothing
 */
void stk_pall(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;

h = *head;
if (h == NULL)
return;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
