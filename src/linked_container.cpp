#include <iostream>

struct Node2 {
    Node2 *next = nullptr;
    int data = 0;   
};

class LinkedListContainer {
    Node2 *head;
    Node2 *tail;
  public:
      LinkedListContainer() : head(nullptr), tail(nullptr), list_size(0) {}

      ~LinkedListContainer() { clear(); }

      void push_back(int value) {
          node = new Node2;
          node->data = value;
          ++list_size;
          if (is_empty()) {
              head = node;
              tail = node;
              return;
          }
          tail->next = node;
          tail = node;
      }

      void push_front(int value) {
          node = new Node2;
          node->data = value;
          ++list_size;
          if (is_empty()) {
              head = tail = node;
              return;
          }
          node->next = head;
          head = node;
      }

      void insert(int number, size_t position) {
          if (position == 1 || is_empty()) {push_front(number); return; }
          if (position == list_size + 1) {push_back(number); return; }
          size_t i = 1;
          Node2 *prev_node = head;
          while (i < position - 1) {
              prev_node = prev_node->next;
              ++i;
          }
          Node2 *new_node = new Node2;  
          new_node->data = number;
          new_node->next = prev_node->next;
          if (prev_node != nullptr && list_size != 1) prev_node->next = new_node;
          ++list_size;
      }
      
      void erase(size_t pos1, size_t pos2, size_t pos3) {
          delete_node(pos1);
          delete_node(pos2 - 1);
          delete_node(pos3 - 2);
      }  
       
      int operator[](const size_t i) {
          if (is_empty() || i == 0) return 0;
          Node2 *node = head;
          size_t j = 1;
          while (j < i) {
              node = node->next;
              if (!node) return 0;
              ++j;
          }
          return node->data;
      }
      
      friend std::ostream &operator<<(std::ostream &os, LinkedListContainer &item) {
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
      Node2 *node;
      void clear() {
          while (list_size != 0) {
              delete_node(1);
          }
      }
      void delete_node(size_t position) {     
          if (is_empty()) return;
          Node2 *current_node = head;
          Node2 *prev_node = nullptr;
          size_t i = 1;
          while (i < position) {    
              prev_node = current_node;
              current_node = current_node->next;
              ++i;
          }
          Node2 *next_node = current_node->next;
          if ((list_size > 1) && (prev_node != nullptr)) prev_node->next = next_node; 
          if (position == 1) head = next_node;                                       
          if (position == list_size) tail = current_node;                            
          delete current_node; 
          --list_size;
      }
      
};
