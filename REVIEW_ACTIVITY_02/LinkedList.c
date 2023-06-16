#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initList(List *list) {
    *list = NULL;
}

List newList() {
    List new_list = (List)malloc(sizeof(NodeType));
    new_list->next = NULL;
    return new_list;
}

NodeType createNode(DATA data) {
    NodePtr new_node = (NodePtr)malloc(sizeof(NodeType));
    new_node->data = data;
    new_node->next = NULL;
    return *new_node;
}

void displayList(List list) {
    NodePtr current = list;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool insertFront(List *list, DATA item) {
    NodePtr new_node = (NodePtr)malloc(sizeof(NodeType));
    if (new_node == NULL) {
        return false;
    }
    new_node->data = item;
    new_node->next = *list;
    *list = new_node;
    return true;
}

bool insertRear(List *list, DATA item) {
    NodePtr new_node = (NodePtr)malloc(sizeof(NodeType));
    if (new_node == NULL) {
        return false;
    }
    new_node->data = item;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        NodePtr current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return true;
}

bool insertAt(List *list, DATA item, int loc) {
    if(loc < 0) {
        return false;
    }
    if(loc == 0) {
        return insertFront(list, item);
    }
    NodePtr current = *list;
    for(int i = 0; i < loc - 1; i++) {
        if(current == NULL) {
            return false;
        }
        current = current->next;
    }
    if(current == NULL) {
        return false;
    }
    NodePtr new_node = (NodePtr)malloc(sizeof(NodeType));
    if(new_node == NULL) {
        return false;
    }
    new_node->data = item;
    new_node->next = current->next;
    current->next = new_node;
    return true;
}

bool insertSorted(List *list, DATA data) {
    NodePtr new_node = (NodePtr)malloc(sizeof(NodeType));
    if (new_node == NULL) {
        return false;
    }
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty or the new node should be inserted before the first node of the list
    if (*list == NULL || (*list)->data >= data) {
        new_node->next = *list;
        *list = new_node;
    } else {
        NodePtr current = *list;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return true;
}

bool searchItem(List list, DATA key) {
    NodePtr current = list;
    while(current != NULL) {
        if(current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int getItem(List list, DATA key) {
    NodePtr current = list;
    int loc = 0;
    while(current != NULL) {
        if(current->data == key) {
            return loc;
        }
        current = current->next;
        loc++;
    }
    return -1;
}

bool deleteFront(List *list) {
    if(*list == NULL) {
        return false;
    }
    NodePtr to_delete = *list;
    *list = (*list)->next;
    free(to_delete);
    return true;
}

bool deleteRear(List *list) {
    if(*list == NULL) {
        return false;
    }
    if((*list)->next == NULL) {
        free(*list);
        *list = NULL;
        return true;
    }
    NodePtr current = *list;
    while(current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return true;
}

int deleteAt(List *list, int loc) {
    if(loc < 0) {
        return false;
    }
    if(loc == 0) {
        return deleteFront(list);
    }
    NodePtr current = *list;
    for(int i = 0; i < loc - 1; i++) {
        if(current == NULL) {
            return false;
        }
        current = current->next;
    }
    if(current == NULL || current->next == NULL) {
        return false;
    }
    NodePtr to_delete = current->next;
    current->next = to_delete->next;
    free(to_delete);
    return true;
}

bool deleteItem(List *list, DATA key) {
    if(*list == NULL) {
        return false;
    }
    if((*list)->data == key) {
        return deleteFront(list);
    }
    NodePtr current = *list;
    while(current->next != NULL && current->next->data != key) {
        current = current->next;
    }
    if(current->next == NULL) {
        return false;
    }
    NodePtr to_delete = current->next;
    current->next = to_delete->next;
    free(to_delete);
    return true;
}

int deleteAllItem(List *list, DATA key) {
    int delete_count = 0;
    while(deleteItem(list, key)) {
        delete_count++;
    }
    return delete_count;
}

void clearList(List *list) {
    NodePtr current = *list;
    NodePtr next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *list = NULL;  // Ensure the list pointer points to NULL after clearing
}
