#include <iostream>
#include <list>
#include <vector>

template <class T>
class Buffer1 {
 private:
  std::vector<T> buffer_;
  long long head_index_;
  long long tail_index_;
  long long capacity_;

 public:
  Buffer1(long long capacity)
      : head_index_(0), tail_index_(0), capacity_(capacity) {
    buffer_.resize(capacity);
  }
  void push(const T& x) {
    buffer_[head_index_] = x;
    head_index_ = (head_index_ + 1) % capacity_;
    if (head_index_ == tail_index_) {
      tail_index_ = (tail_index_ + 1) % capacity_;
    }
  }
  bool is_empty() const { return head_index_ == tail_index_; }
  T& pop() {
    if (is_empty()) {
      throw std::out_of_range("Empty!");
    }
    T out = buffer_[tail_index_];
    tail_index_ = (tail_index_ + 1) % capacity_;
    return out;
  }
  long long size() const {
    if (head_index_ >= tail_index_) {
      return head_index_ - tail_index_;
    }
    return capacity_ - (tail_index_ - head_index_);
  }
};

template <class T>
class Buffer2 {
 private:
  std::list<T> buffer_;
  long long capacity_;

 public:
  Buffer2(long long capacity) : capacity_(capacity) {}
  void push(const T& x) {
    if (buffer_.size() < capacity_) {
      buffer_.push_back(x);
    } else {
      buffer_.pop_front();
      buffer_.push_back(x);
    }
  }

  T& pop(long long index) const {
    if (index >= buffer_.size()) {
      throw std::out_of_range("Index out of range");
    }
    auto it = buffer_.begin();
    std::advance(it, index);
    return *it;
  }
  long long size() const { return buffer_.size(); }
};

/* Первый буффер использует внутри себя std::vector. Так как его размер ограничен capacity_, то у него никогда не будет вызываться аллоцирование новой памяти.
 Но проблемы начинаются при маленьком значении capacity_. Также аллоцированнная память может никогда не пригодиться. 
 
  Второй буффер использует внутри себя std::list. У него нет проблем с аллоцированием и использованием памяти. Но у него есть проблема с доступом к элементам. Если требуется 
  получить элемент по индексу, то нужно пройтись по всему list, чтобы его найти (O(n)), в то время как первый буффер сделал это сразу (O(1)).
 */