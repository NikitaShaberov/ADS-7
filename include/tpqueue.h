// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T data;
    ITEM * next;
    ITEM * prev;
  };
  ITEM* head, * tail;
  TPQueue::ITEM* create(const T& value);

 public:
  TPQueue():head(nullptr), tail(nullptr) {}
  void push(const T&);
  T pop();
};

template<typename T>
typename TPQueue<T>::ITEM * TPQueue<T>::create(const T& data) {
  ITEM * item = new ITEM;
  item -> data = data;
  item -> next = nullptr;
  item -> prev = nullptr;
  return item;
}




template<typename T>
void TPQueue<T>::push(const T& data) {
    if (start == nullptr) {
        start = new ITEM();
        start->data = data;
        start->next = nullptr;
    } else {
        ITEM *startLocal = nullptr;
        ITEM *endLocal = nullptr;
        startLocal = start;
        while (startLocal != nullptr) {
            if (startLocal->data.prior < data.prior) {
                ITEM *temp = new ITEM();
                temp->data = startLocal->data;
                temp->next = startLocal->next;
                startLocal->data = data;
                startLocal->next = temp;
                return;
            }
            endLocal = startLocal;
            startLocal = startLocal->next;
        }
        ITEM *temp = new ITEM();
        temp->data = data;
        temp->next = nullptr;
        endLocal->next = temp;
    }
}


template<typename T>
T TPQueue<T>::pop() {
  ITEM * temp = head -> next;
  if (temp) {
    temp -> prev = nullptr;
  }
  T data = head -> data;
  delete head;
  head = temp;
  return data;
}



struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
