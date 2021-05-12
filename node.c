#include "node.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>


//The struct definition:
struct node_t
{
    MapDataElement data;
    MapKeyElement key;
    struct node_t *next;
};

/*Creates empty node
  return NULL if malloc failed.
  else, return the node*/
Node nodeCreate()
{
    Node new_node = malloc(sizeof(*new_node));
    if(new_node == NULL)
    {
        return NULL;   
    }

    new_node->data = NULL;
    new_node->key = NULL;
    new_node->next = NULL;

    return new_node;
}


void nodeDestroy(Node list)
{
    while(list != NULL)
    {
        Node node_to_delete = list;
        list = list->next;
        nodefree(node_to_delete);
    }
}

void nodeFree(Node node)
{
    
    free(node);
}




/*  add element to the map's Node.
    if the element key is already in the list, only change the data.
    the new element will be in-place in LOW to HIGH order by comapre-key.
*/
NodeResult nodeAddOrEdit(Node node_head, Node new_node, compareMapKeyElements compare_key_func)
{
    if(node_head == NULL || new_node == NULL || compare_key_func == NULL)
    {
        return NODE_NULL_ARGUMENT;
    }

    Node temp_previous = node_head;
    Node temp = nodeGetNext(node_head);

    while(temp != NULL)
    {
        int compare_result = compare_key_func(nodeGetKey(new_node), nodeGetKey(temp));
        if( compare_result > 0 )
        {
            temp_previous = temp;
            temp = nodeGetNext(temp);
        }
        else if (compare_result < 0)
        {
            nodeSetNext(temp_previous, new_node);
            nodeSetNext(new_node, temp);
            return NODE_SUCCESS;
        }
        else if (compare_result == 0)
        {
            nodeSetData(temp, nodeGetData(new_node));
            return NODE_SUCCESS;
        }
    }

    nodeSetNext(temp_previous, new_node);

    return NODE_SUCCESS;
}

/* ******************** */
/* ******* GET ******** */
/* ******************** */

/* return the next node */
Node nodeGetNext(Node node)
{
    if(node == NULL)
    {
        return NULL;
    }
    return node->next;
}

/* return the element's KEY. */
MapKeyElement nodeGetKey(Node node)
{
    if(node == NULL)
    {
        return NULL;
    }
    return node->key;
}

/* return the element's DATA. */
MapDataElement nodeGetData(Node node)
{
    if(node == NULL)
    {
        return NULL;
    }
    return node->data;
}

/* ******************** */
/* ******* SET ******** */
/* ******************** */

/* set the element's DATA. */
void nodeSetData(Node node, MapDataElement data)
{
    if(node == NULL || data == NULL)
    {
        return;
    }
    node->data = data;
}

/* set the element's KEY. */
void nodeSetKey(Node node, MapKeyElement key)
{
    if(node == NULL || key == NULL)
    {
        return;
    }
    node->key = key;
}

/* set the element's next node. */
void nodeSetNext(Node node_from, Node node_to)
{
    if(node_from == NULL || node_to == NULL)
    {
        return;
    }
    node_from->next = node_to;
}







