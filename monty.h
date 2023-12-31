#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
     /**
      * struct stack_s - doubly linked list representation of a stack (or queue)
      * @n: integer
      * @prev: points to the previous element of the stack (or queue)
      * @next: points to the next element of the stack (or queue)
      *
      * Description: doubly linked list node structure
      * for stack, queues, LIFO, FIFO Holberton project
      */
typedef struct stack_s
	{
	  int n;
	  struct stack_s *prev;
	  struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
  char *arg;
  FILE *file;
  char *content;
  int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void stk_push(stack_t **head, unsigned int counter);
void stk_pall(stack_t **head, unsigned int counter);
void stk_pint(stack_t **head, unsigned int counter);
void stk_stack(stack_t **head, unsigned int counter);
void stk_pop(stack_t **head, unsigned int counter);
void stk_swap(stack_t **head, unsigned int counter);
void stk_nothing(stack_t **head, unsigned int counter);
void stk_subtraction(stack_t **head, unsigned int counter);
void stk_division(stack_t **head, unsigned int counter);
void stk_multiply(stack_t **head, unsigned int counter);
void stk_modulus(stack_t **head, unsigned int counter);
void stk_topchar(stack_t **head, unsigned int counter);
void stk_topstring(stack_t **head, unsigned int counter);
void stk_toprotate(stack_t **head,  __attribute__((unused)) unsigned int counter);
void stk_bottomrotate(stack_t **head, __attribute__((unused)) unsigned int counter);
void free_stack(stack_t *head);
void stk_add(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void stk_queue(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
#endif
