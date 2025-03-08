 void insert_at_sp(int element, int pos) {
    // Create a new node
    struct DLL* NewNode = create_node(element);
    if (NewNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // If inserting at the first position
    if (pos == 1) {
        NewNode->next = first;
        if (first != NULL) {
            first->prev = NewNode;
        }
        first = NewNode;
        printf("%d was inserted at position %d\n", element, pos);
        return;
    }

    // Traverse the list to find the position
    struct DLL* temp = first;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {  // Check for position out of bounds
            printf("Position %d is out of bounds\n", pos);
            free(NewNode);
            return;
        }
        temp = temp->next;
    }

    // Insert the new node at the desired position
    struct DLL* tempp = (temp != NULL) ? temp->next : NULL;
    NewNode->next = tempp;
    NewNode->prev = temp;
    if (temp != NULL) {
        temp->next = NewNode;
    }
    if (tempp != NULL) {
        tempp->prev = NewNode;
    }

    printf("%d was inserted at position %d\n", element, pos);
}
