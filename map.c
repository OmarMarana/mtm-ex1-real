#include "map.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

#define ITERATOR_UNDEFINED NULL
#define MAP_ERROR -1

 MapDataElement f1(MapDataElement a);
 MapKeyElement f2(MapKeyElement a);
 void f3(MapDataElement a);
 void f4(MapKeyElement a);
 int f5(MapKeyElement a, MapKeyElement b);

struct Map_t
{
    Node elements_pair;
    Node iterator;

    copyMapDataElements copyDataFucntion;
    copyMapKeyElements copyKeyFucntion;
    freeMapKeyElements freeKeyFucntion;
    freeMapDataElements freeDataFucntion;
    compareMapKeyElements compareFunction;

};

MapResult mapPut(Map map, MapKeyElement keyElement, MapDataElement dataElement)
{
    if(map == NULL || keyElement == NULL || dataElement == NULL)
    {
        return MAP_NULL_ARGUMENT;
    }

    map->iterator = ITERATOR_UNDEFINED;

    Node new_node = nodeCreate();
    if(new_node == NULL)
    {
        return MAP_OUT_OF_MEMORY;
    }

    nodeSetData(new_node, dataElement);
    nodeSetKey(new_node, keyElement);
    if(nodeAddOrEdit(map->elements_pair, new_node, map->compareFunction) == NODE_SUCCESS)
    {
        return MAP_SUCCESS;
    }
    
    return MAP_ERROR;
}

MapKeyElement mapGetFirst(Map map)
{
    map->iterator = (map->elements_pair);
    return mapGetNext(map);
}


MapKeyElement mapGetNext(Map map)
{
    if(listGetNext(map->iterator) == NULL || map == NULL)
    {
        return NULL;
    }

    //TODO : check if iterator is in invalid state.
    // if is in-valid state, return NULL.

    map->iterator = nodeGetNext(map->iterator);

    return (nodeGetKey(map->iterator));
}



// Map mapCreate(copyMapDataElements copyDataElement, copyMapKeyElements copyKeyElement,
//               freeMapDataElements freeDataElement,freeMapKeyElements freeKeyElement,
//               compareMapKeyElements compareKeyElements)
// {
//     if(copyDataElement == NULL || copyKeyElement == NULL || freeDataElement == NULL || freeKeyElement == NULL
//     || compareKeyElements == NULL)
//     {
//         return NULL;
//     }
    
//     Map map_to_create = malloc(sizeof(*map_to_create));
//     if(map_to_create == NULL)
//     {
//         return NULL;
//     }
   
//     map_to_create->key_elements = malloc(sizeof(*(map_to_create->key_elements))*INITIAL_SIZE);
//     if(map_to_create->key_elements == NULL)
//     {
//         return NULL;
//     }
   
//     map_to_create->data_elements = malloc(sizeof(*(map_to_create->data_elements))*INITIAL_SIZE);
//     if(map_to_create->data_elements == NULL)
//     {
//         return NULL;
//     }
//     map_to_create->active_size =0;
//     map_to_create->allocated_size =INITIAL_SIZE;

//     map_to_create->copyDataFucntion = copyDataElement;
//     map_to_create->copyKeyFucntion = copyKeyElement;

//     map_to_create->freeDataFucntion = freeDataElement;
//     map_to_create->freeKeyFucntion = freeKeyElement;

//     map_to_create->compareFunction = compareKeyElements;
    
    
//     return map_to_create;

// }


// int main()
// {

//     Map map = mapCreate(f1,f2,f3,f4,f5);
//     printf("%d", map->allocated_size);
    
//     return 0;
// }

//  MapDataElement f1(MapDataElement a)
// {
//     return NULL;

// }
//  MapKeyElement f2(MapKeyElement a)
// {
//     return NULL;

// }


//  void f3(MapDataElement a)
// {
    
// }

//  void f4(MapKeyElement a)
// {
    
// }

//  int f5(MapKeyElement a, MapKeyElement b)
// {
//     return 0;
// }



