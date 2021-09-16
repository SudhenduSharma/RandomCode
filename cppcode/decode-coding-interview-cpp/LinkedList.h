#include<iostream>
#include<vector>
#include<random>

class LinkedListNode {
    public: 
        int key;
        int data;
        LinkedListNode* next;
        LinkedListNode* arbitraryPointer;

        LinkedListNode(int data) {
            this->data = data;
            this->next = nullptr;
        }

        LinkedListNode(int key, int data) {
            this->key = key;
            this->data = data;
            this->next = nullptr;
        }

        LinkedListNode(int data, LinkedListNode* next) {
            this->data = data;
            this->next = next;
        }

        LinkedListNode(int data, LinkedListNode* next, LinkedListNode* arbitraryPointer) {
            this->data = data;
            this->next = next;
            this->arbitraryPointer = arbitraryPointer;
        }

        ~LinkedListNode(){
            delete this->next;
            delete this->arbitraryPointer;
        }
};



class LinkedList { 

    public:
        static LinkedListNode* insertAtHead(LinkedListNode* head, int data) {
            LinkedListNode* newNode = new LinkedListNode(data);
            newNode->next = head;
            return newNode;
        }

        static LinkedListNode* insertAtTail(LinkedListNode* head, int data) {
            LinkedListNode* newNode = new LinkedListNode(data);
            if (head == nullptr) {
                return newNode;
            }
            LinkedListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            return head;
        }

        static LinkedListNode* insertAtTail(LinkedListNode* head, LinkedListNode* node)
        {
            if (head == nullptr) {
                return node;
            }
            LinkedListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
            return head;
        }

        static LinkedListNode* createLinkedList(std::vector<int> lst) {
            LinkedListNode* head = nullptr;
            LinkedListNode* tail = nullptr;
            for (auto x : lst) {
                LinkedListNode* newNode = new LinkedListNode(x);
                if (head == nullptr) {
                    head = newNode;
                } else {
                    tail->next = newNode;
                }
                tail = newNode;
            }
            return head;
        }

        static LinkedListNode* createRandomList(int length) {
            LinkedListNode* listHead = nullptr;
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(1, 100);
            for(int i = 0; i < length; ++i) {
                listHead = insertAtHead(listHead, dist(mt));
            }
            return listHead;
        }

        static void toList(LinkedListNode* head, std::vector<int>& lst) {
            LinkedListNode* temp = head;
            while (temp != nullptr) {
                lst.push_back(temp->data);
                temp = temp->next;
            }
        }

        static void display(LinkedListNode* head) {
            LinkedListNode* temp = head;
            while (temp != nullptr) {
                std::cout << temp->data;
                temp = temp->next;
                if (temp != nullptr) {
                    std::cout << ", ";
                }
            }
            std::cout << "\n";
        }  
    

        static LinkedListNode* mergeAlternating(LinkedListNode* list1, LinkedListNode* list2) {
            if (list1 == nullptr) {
                return list2;
            }

            if (list2 == nullptr) {
                return list1;
            }

            LinkedListNode* head = list1;

            while (list1->next != nullptr && list2 != nullptr) {
                LinkedListNode* temp = list2;
                list2 = list2->next;

                temp->next = list1->next;
                list1->next = temp;
                list1 = temp->next;
            }

            if (list1->next == nullptr) {
                list1->next = list2;
            }

            return head;
        }

        static bool isEqual(LinkedListNode* list1, LinkedListNode* list2) {
            if (list1 == list2) {
                return true;
            }

            while (list1 != nullptr && list2 != nullptr) {
                if (list1->data != list2->data) {
                    return false;
                }

                list1 = list1->next;
                list2 = list2->next;
            }

            return (list1 == list2);
        }
};
