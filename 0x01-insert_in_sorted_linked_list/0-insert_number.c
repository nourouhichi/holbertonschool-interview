#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a node in a sorted one
 * @head: the head
 * @number: data in the node
 * Return: an address to the inserted node
 */
 
 listint_t *insert_node(listint_t **head, int number)
 {
     listint_t *road_runner, *new_node;
     new_node = malloc(sizeof(listint_t));
     road_runner = *head;
     if (new_node == NULL)
        return (NULL);
    new_node->n = number;
    if (!(*head) || (*head)->n > number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }
    while (road_runner->next)
    {
        if (road_runner->next->n > number)
        {
            new_node->next = road_runner->next;
            road_runner->next = new_node;
            return (new_node);
        }
        road_runner = road_runner->next;
    }
    new_node->next = road_runner->next;
    road_runner->next = new_node;
    return (new_node);
 }