#include "monty.h"
/**
 * stk_topstring - Prints the string at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: Nothing
 */
void stk_topstring(stack_t **head, unsigned int counter)
{
stack_t *h;
(void)counter;

h = *head;
while (h)
{
if (h->n > 127 || h->n <= 0)
{
break;
}
printf("%c", h->n);
h = h->next;
}
printf("\n");
}
