#include <cstddef>
#include <cstring>
#include <iostream>

class ArrayContainer {
  public:
      ArrayContainer() : arr_size(2), quantity_elem(0) {
          array = new int[arr_size];
      }

      ~ArrayContainer() { delete[] array; }
        
      void push_back(int value) {
          if (quantity_elem == arr_size) increase_size_array();
          array[quantity_elem] = value;
          ++quantity_elem;    
      }
            
      void insert(int value, size_t index) {
          if (index == 1) push_front(value, index);
          else {
              arr_size = quantity_elem += 1;
              int *new_array = new int[quantity_elem];
              for (size_t i = 0; i < index; ++i) {
                  if (i == index - 1) {
                      new_array[i] = value;
                      break;
                  }
                  new_array[i] = array[i];
              }
              memcpy(index + new_array, index - 1 + array, (quantity_elem - index) * sizeof(array[0]));
              delete[] array;
              array = new_array;
          }
      }
      
      void size() const { std::cout << quantity_elem << '\n'; }
      
      void erase(size_t a, size_t b, size_t c) {
          arr_size = quantity_elem - 3;
          int *new_array = new int[arr_size];
          for (size_t i = 0, j = 0; i < quantity_elem; ++i) {
              if (i == a - 1 || i == b-1 || i == c - 1) continue;
              new_array[j] = array[i];
              ++j;
          }
          quantity_elem = arr_size;
          delete[] array;
          array = new_array;
      }
      
      int& operator[](int index) { return array[index]; }  
      
      friend std::ostream &operator<<(std::ostream &os, const ArrayContainer &item) {
          for (size_t i = 0; i < item.quantity_elem; ++i) {
              os << item.array[i]; 
              if (i < item.quantity_elem - 1) os << ", " ;        
          }
          return os;
      } 

  private:
      int *array;                   
      size_t arr_size;              
      size_t quantity_elem;            
      void increase_size_array() {
          arr_size *= 1.6;
          int *new_array = new int[arr_size];
          memcpy(new_array, array, quantity_elem * sizeof(array[0]));
          delete[] array;
          array = new_array;
      }
      void push_front(int value, size_t index) {
          quantity_elem = arr_size = quantity_elem + 1;
          int *new_array = new int[quantity_elem];
          for (size_t i = 0; i < quantity_elem; ++i) {
              if (i == index - 1) new_array[i] = value;
              new_array[i + 1] = array[i];
          }
          delete[] array;
          array = new_array;
      }
};
