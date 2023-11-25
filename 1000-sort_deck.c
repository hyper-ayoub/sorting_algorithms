#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* get_card - Gets the relative value of a card from its string representation
* @str: Value of the card
*
* Return: Relative value of the card (0 through 12)
*/
int get_card(const char *str)
{
	int i;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, array[i]) == 0)
		{
			return (i);
		}
	}
	exit(1);
}

/**
* swap_deck_node - Swaps a node within a doubly linked list
* @list: Double pointer to the list
* @node: Node to be swapped
*
* Return: void
*/
void swap_deck_node(deck_node_t **list, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
* sort_deck - Sorts a linked list deck of cards using the Bubble Sort algorithm
* @deck: Double pointer to the deck to sort
*
* Return: void
*/
void sort_deck(deck_node_t **deck)
{
	char swapped = 1, ck, ca;
	deck_node_t *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	current = *deck;
	while (swapped != 0)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			ck = get_card(current->card->value) + 13 * current->card->kind;
			ca = get_card(current->next->card->value) + 13 * current->next->card->kind;
			if (ck > ca)
			{
				swap_deck_node(deck, current);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			ck = get_card(current->card->value) + 13 * current->card->kind;
			ca = get_card(current->prev->card->value) + 13 * current->prev->card->kind;
			if (ck < ca)
			{
				swap_deck_node(deck, current->prev);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}

