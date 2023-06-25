#include "monty.h"
/**
 * push - inserts a stack element in linked list
 * @n: the integer to be added to the stack element (node)
 * Return: void
 */
void push(int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		printf("overflow\n");
		exit(EXIT_FAILURE);
	}
	if (temp == NULL)
	{
		node->n = n;
		node->next = NULL;
		node->prev = NULL;
		temp = node;
	}
	else
	{
		node->n = n;
		node->next = temp;
		node->prev = NULL;
		temp->prev = node;
		temp = node;
	}
}
/**
 * pall - prints all the existing elements on stack
 * Return: void
 */
void pall(void)
{
	stack_t *ptr = temp;

	if (ptr == NULL)
	{
		printf("Empty stack\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}
