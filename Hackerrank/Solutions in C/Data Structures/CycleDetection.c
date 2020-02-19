

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    
    SinglyLinkedListNode *p1 = malloc(sizeof(SinglyLinkedListNode));
    SinglyLinkedListNode *p2 = malloc(sizeof(SinglyLinkedListNode));
    p1 = head;
    p2 = head;
    while(p2 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
        if(p2 != NULL)
            p2 = p2->next;
        else
            return false;
        if(p1 == p2)
            return true;
    }
    return false;


}


