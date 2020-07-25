// create simple linkedlist implementation
template<typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    class Node
    {
        public:
            T data;
            Node* next;
    };

    void InsertNode(T);
    void DeleteNode(T data);
    void PrintLinkedList(Node* head);
    Node* search(T data);
    Node* GetHead() { return head; }

private:
    Node* head;
    Node* tail;

};

template<typename T>
LinkedList<T>::LinkedList() : head(NULL)
{
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node* temp = head;
    while(head)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template<typename T>
void LinkedList<T>::InsertNode(T data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) // if list is empty
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        // find the end of the linked list
        // start at head and traverse until find node that has not yet
        // been assigned a next node and assign newNode as next node
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template<typename T>
void LinkedList<T>::DeleteNode(T data)
{
    // create temporary pointer to next node
    // connect prev node to following node
    // remove node n

    Node* temp = head;
    Node* prev = head;

    // if the data happens to be at head,
    // we need to update the head (to the next node)
    // and free old head
    if(temp != NULL && temp->data == data)
    {
        head = temp->next;
        free(temp);
        return; 
    }

    // otherwise, find the node that has the data
    // store previous node while also advancing to next node
    while(temp->next != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    // if reached end of list and did not find data, then return
    if(temp == NULL)
    {
        return;
    }

    // remove temp
    prev->next = temp->next;

    free(temp);
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::search(T data)
{
    if(head == nullptr || head->data == data)
    {  
        return head;
    }
    Node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
        if(temp->data == data)
        {
            break;
        }
    }
    return temp;
}

template<typename T>
void LinkedList<T>::PrintLinkedList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        std::cout << "Node: " << temp->data;
        if(temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
        std::cout << " (next: " << temp->data << ")";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}