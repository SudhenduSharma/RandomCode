#include "LinkedList.h"

/*LinkedListNode* merge2Country(LinkedListNode* l1, LinkedListNode* l2) {
    LinkedListNode* dummy = new LinkedListNode(-1);

    LinkedListNode* prev = dummy;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    
    if (l1 == nullptr)
      prev->next = l2;
    else
      prev->next = l1;

    return dummy->next;
}*/

LinkedListNode* merge2Country(LinkedListNode* l1, LinkedListNode* l2) 
{
    if(l1 == nullptr || l2 == nullptr) 
        return (l1 != nullptr)?l1:l2;

    LinkedListNode* head = nullptr;
    if(l1->data < l2->data)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    LinkedListNode* prev = head;
    head->next = nullptr;
    while (l1 != nullptr && l2 != nullptr) 
    {
        if(l1->data <l2->data)
        {
            prev->next = l1;
            l1 = l1->next;
        }
        else
        {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = (l1!=nullptr)?l1:l2;
    return head;
}

LinkedListNode* mergeKCounty(std::vector<LinkedListNode*> lists) {

  if (lists.size() > 0){
    LinkedListNode* res = lists[0];

    for (int i = 1; i < lists.size(); i++)
      res = merge2Country(res, lists[i]);

    return res;
  }
  return new LinkedListNode(-1);
}

int main() {

    LinkedListNode* a = LinkedList::createLinkedList({11,41,51});

    LinkedListNode* b = LinkedList::createLinkedList({21,23,42});

    LinkedListNode* c = LinkedList::createLinkedList({25,56,66,72});
    
    std::vector<LinkedListNode*> list1;
    list1.push_back(a);
    list1.push_back(b);
    list1.push_back(c);

    LinkedList::display(mergeKCounty(list1));
    return 0;
}
