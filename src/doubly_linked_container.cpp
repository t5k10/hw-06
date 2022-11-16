#include <iostream>

struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    int data = 0;   
};

class DoubleListContainer {
    Node *head, *tail;
  public:
      DoubleListContainer() : head(nullptr), tail(nullptr), list_size(0) {}
      
      DoubleListContainer(DoubleListContainer&& container) 
          : head(container.head), tail(container.tail), list_size(container.list_size) {
              container.head = nullptr;
              container.tail = nullptr;
              container.list_size = 0;
          }

      ~DoubleListContainer() { clear(); }

      void push_back(int value) {
          node = new Node;
          node->data = value;
          ++list_size;
          if (is_empty()) {
              head = tail = node;
              return;
          }
          node->prev = tail;
          tail->next = node;
          tail = node;
      }

      void push_front(int value) {
          node = new Node;
          node->data = value;
          ++list_size;
          if (is_empty()) {
              head = tail = node;
              return;
          }
          node->next = head;
          head->prev = node;
          head = node;
      }

      void insert(int number, size_t position) {
          if (position == 1) {push_front(number); return; }
          if (position == list_size + 1) {push_back(number); return; }
          size_t i = 1;
          Node *node = head;
          while (i < position) {
              node = node->next;
              ++i;
          }
          Node *prev_ins = node->prev;
          Node *new_node = new Node;
          new_node->data = number;
          if (prev_ins != nullptr && list_size != 1) prev_ins->next = new_node;
          new_node->next = node;
          new_node->prev = prev_ins;
          node->prev = new_node;
          ++list_size;
      }

      void erase(size_t pos1, size_t pos2, size_t pos3) {
          delete_node(pos1);
          delete_node(pos2 - 1);
          delete_node(pos3 - 2);
      }  
       
      int operator[](const size_t i) {
          if (is_empty() || i == 0) return 0;
          Node *node = head;
          size_t j = 1;
          while (j < i) {
              node = node->next;
              if (!node) return 0;
              ++j;
          }
          return node->data;
      }
      
      friend std::ostream &operator<<(std::ostream &os, DoubleListContainer &item) {
          if (item.is_empty()) return os;
          item.node = item.head;
          while (item.node) {
              os << item.node->data; 
              if(item.node->next) {
                  os << ", ";
              }
              item.node = item.node->next;
          }
          return os;
      }
      
      bool is_empty() {
          return head == nullptr;
      }

      size_t size() { return list_size; }
       
  private:
      size_t list_size;
      Node *node;
      void clear() {
          while (list_size != 0) {
              delete_node(1);
          }
      }
      void delete_node(size_t position) {     
          if (is_empty()) return;
          Node* node = head;
          size_t i = 1;
          while (i < position) {    
              node = node->next;
              ++i;
          }
          Node *prev_del = node->prev;
          Node *after_del = node->next;
          if ((list_size > 1) && (prev_del != nullptr)) prev_del->next = after_del;    
          if ((list_size > 1) && (after_del != nullptr)) after_del->prev = prev_del; 
          if (position == 1) head = after_del;
          if (position == list_size) tail = prev_del;
          delete node;
          --list_size;
      }
};
