// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct ITEM {
        T val;
        ITEM* next;
        ITEM* prev;
    };
  ITEM* head;
  ITEM* tail;

    ITEM* create(T val) {
    ITEM* item = new ITEM;
    item->val = val;
    item->next = nullptr;
    item->prev = nullptr;
    return item;
}




template<typename T>
void TPQueue <T>::push(const T& data) {
  ITEM * temp = head;
  ITEM * item = create(data);
  while (temp && temp -> data.prior >= data.prior)
    temp = temp -> next;
  if (!temp && head) {
    tail -> next = item;
    tail -> next -> prev = tail;
    tail = item;
  } else if (!(temp || head)) {
    head = tail = item;
  } else if (!temp -> prev) {
    temp -> prev = item;
    item -> next = temp;
    head = item;
  } else {
    temp -> prev -> next = item;
    item -> prev = temp -> prev;
    item -> next = temp;
    temp -> prev = item;
  }
}


  T pop() {
    ITEM* cur = head->next;
    if (cur) {
      cur->prev = nullptr;
    }
    T val = head->val;
    delete head;
    head = cur;
    return val;
  }




struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
