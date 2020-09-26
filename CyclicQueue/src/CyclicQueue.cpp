#include <stdexcept>

#include <CyclicQueue.h>

CyclicQueue::CyclicQueue() : CyclicQueue(100) {}

CyclicQueue::CyclicQueue(int capacity) {
    this->capacity_ = capacity;
    this->arr_ = new int[this->capacity_];
    this->size_ = 0;
    this->left_ = 0;
    this->right_ = 0;
}

CyclicQueue::~CyclicQueue() {
    delete[] this->arr_;
}

CyclicQueue::CyclicQueue(const CyclicQueue &other) : CyclicQueue(other.capacity_) {
    this->size_ = other.size_;
    this->left_ = other.left_;
    this->right_ = other.right_;
    this->arr_ = new int[this->capacity_];
    std::copy(other.arr_, other.arr_ + other.capacity_, this->arr_);
}

CyclicQueue &CyclicQueue::operator=(const CyclicQueue &other) {
    CyclicQueue tmp(other);
    std::swap(*this, tmp);
    return *this;
}

void CyclicQueue::push(int item) {
    if (size_ == capacity_)
        throw std::runtime_error("Queue full!");
    this->arr_[right_] = item;
    this->right_ = (this->right_ + 1) % this->capacity_;
    this->size_++;
}

int CyclicQueue::size() const {
    return this->size_;
}

int CyclicQueue::pop() {
    if (this->size_ > 0) {
        this->size_--;
        int result = this->arr_[left_];
        this->left_ = (this->left_ + 1) % this->capacity_;
        return result;
    }
    throw std::runtime_error("Empty queue!");
}

int CyclicQueue::front() const {
    if (size_ > 0)
        return this->arr_[left_];
    throw std::runtime_error("Empty queue!");
}

void CyclicQueue::clear() {
    size_ = 0;
    left_ = 0;
    right_ = 0;
}

