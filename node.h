#ifndef NODE_H_
#define NODE_H_

typedef struct node_t *Node;

/** Type used for returning error codes from node functions */
typedef enum NodeResult_t {
    NODE_SUCCESS = 1,
    NODE_OUT_OF_MEMORY,
    NODE_NULL_ARGUMENT
} NodeResult;

Node nodeCreate();
NodeResult nodeAddOrEdit(Node node_head, Node new_node, compareMapKeyElements compare_key_func);

/* get */
Node nodeGetNext(Node node);
MapKeyElement nodeGetKey(Node node);
MapDataElement nodeGetData(Node node);

/* set */
void nodeSetNext(Node node_from, Node node_to);
void nodeSetKey(Node node, MapKeyElement key);
void nodeSetData(Node node, MapDataElement data);

#endif /* NODE_H_ */