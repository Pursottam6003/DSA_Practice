// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
int intersectPoint(Node* headA, Node* headB)
{
    Node *p1 = headA;
    Node *p2 = headB;
        
    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {

        if (p1 == p2) return p1->data;
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        p1 = p1->next;
        p2 = p2->next;

        if(p1 == NULL && p2 == NULL) return -1;
        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
        
    return p1->data;
}