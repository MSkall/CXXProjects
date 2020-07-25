#include <iomanip>
#include <iostream>
#include "linked_list_template.h"

int main()
{
    LinkedList<int> linkedList;
    linkedList.InsertNode(1);
    linkedList.InsertNode(10);
    linkedList.InsertNode(16);
    linkedList.InsertNode(3);
    
    std::cout << "Original list:" << std::endl;
    linkedList.PrintLinkedList(linkedList.GetHead());

    linkedList.DeleteNode(10);

    std::cout << "List after deletion:" << std::endl;
    linkedList.PrintLinkedList(linkedList.GetHead());

    int searchID = 16; 
    std::cout << "Searching for Node " << searchID << "..." << std::endl;
    LinkedList<int>::Node* search = linkedList.search(searchID);
    if(search == nullptr)
    {
        std::cout << "Could not find Node " << searchID << std::endl;
    }
    else
    {
        std::cout << "Found Node " << searchID << std::endl;
    }

    return 0;
}