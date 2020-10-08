Node *insertAtBegining(Node *head, int newData)
{
    Node *temp = new Node(newData);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        temp->next = head;
        head = temp;
        return head;
    }
}

Node *insertAtEnd(Node *head, int newData)
{
    Node *temp = new Node(newData);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;

        return head;
    }
}