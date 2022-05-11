// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct ITEM {
        T num;
        ITEM* next;
        ITEM* prev;
    };
  ITEM* head;
  ITEM* tail;

    ITEM* create(T num) {
    ITEM* item = new ITEM;
    item->num = num;
    item->next = nullptr;
    item->prev = nullptr;
    return item;
}


 public:

    void push(const T& value) {
        ITEM* num = head;
        ITEM* item = create(value);
        while (num && num->value.prior >= value.prior)
            num = num->next;
        if (!num && head) {
            tail->next = item;
            tail->next->prev = tail;
            tail = item;
        } else if (!num && !head) {
            head = tail = item;
        } else if (!num->prev) {
            num->prev = item;
            item->next = num;
            head = item;
        } else {
            num->prev->next = item;
            item->prev = num->prev;
            item->next = num;
            num->prev = item;
        }
    }

        T pop() {
        if (head) {
            ITEM* num = head->next;
            if (num)
                num->prev = nullptr;
            T value = head->value;
            delete head;
            head = num;
            return value;
        } else {
            throw std::string("Empty!");
        }
    }
};



struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
