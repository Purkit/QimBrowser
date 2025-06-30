#ifndef EFFARRAY_HPP
#define EFFARRAY_HPP

#include <cstring>
#include <print>

template <typename T, size_t N> class Stack {
public:
    Stack() : arr{0}, top(-1) {}
    inline bool isEmpty() { return top == -1; }
    inline bool isFull() { return top == N - 1; }
    inline void clear() {
        memset(&arr[0], 0, N);
        top = -1;
    }
    void push(T data) {
        if (this->isFull())
            std::println("stack overflow!");
        else
            arr[++top] = data;
    }
    T pop() {
        if (this->isEmpty()) {
            std::println("stack underflow!");
            return -2;
        } else
            return arr[top--];
    }

private:
    T arr[N];
    int top;
};

template <typename T, size_t N> class EffArray {
public:
    EffArray() : mArray{0}, ci(0), fragment_count(0), m_count(0) {}

    inline constexpr size_t size() const { return N; }
    inline int count() const { return m_count; }
    inline void clear() {
        memset(&mArray[0], 0, N);
        ci             = 0;
        fragment_count = 0;
        fragmented_position.clear();
    }

    int storeData(T data) {
        if (ci >= 0 && ci < 10) {
            if (fragment_count) {
                int index     = fragmented_position.pop();
                mArray[index] = data;
                fragment_count--;
                m_count++;
                return index;
            }
            int index  = ci;
            mArray[ci] = data;
            ci++;
            m_count++;
            return index;
        } else {
            // through runtime error
            std::println("array full!");
        }
    }

    void removeAt(int index) {
        if (this->isPositionFree(index)) {
            return;
        }
        if (index >= 0 && index < 10) {
            if (index != ci - 1) { // deleting from middle
                fragmented_position.push(index);
                fragment_count++;
            } else if (index == ci - 1) {
                ci--;
            }
            mArray[index] = nullptr;
            m_count--;
        } else {
            std::println("Invalid index!");
        }
    }

    T dataAt(int index) const { return mArray[index]; }

private:
    inline bool doesElementExistsAt(int index) const {
        return mArray[index] != nullptr;
    }
    inline bool isPositionFree(int index) const {
        return mArray[index] == nullptr;
    }

private:
    T mArray[N];
    Stack<int, N> fragmented_position;
    int fragment_count;
    int ci;

    int m_count;
};

#endif // EFFARRAY_HPP
