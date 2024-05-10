//
// Created by Maja on 1/17/2024.
//

#ifndef B7727F46_GR05_REPO_LISTLOGIC_H
#define B7727F46_GR05_REPO_LISTLOGIC_H


#include <stdio.h>
#include <iostream>
#include <memory>
#include <algorithm>

template <typename T>
class List {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;

        Node(T val) : data(val), next(nullptr), prev() {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    class iterator {
    public:
        std::shared_ptr<Node> current;
    public:
        iterator(std::shared_ptr<Node> current) : current(current) {}
        iterator& operator++ () {
            current = current->next;
            return *this;
        }
        bool operator!= (const iterator& other) {
            return current != other.current;
        }
        T& operator* () {
            return current->data;
        }
    };


public:
    List():head(nullptr), tail(nullptr) {};
    ~List(){
        while (this->head) {
            auto temp = head->next;
            head->next = nullptr;
            head->prev.reset();
            head = temp;
        }
        this->tail = nullptr;
    }
    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }

    void remove(const iterator& itToRemove) {
        auto nodeToRemove = itToRemove.current;

        if (head == tail){
            head = nullptr;
            tail = nullptr;
        } else if (nodeToRemove == head) {

            head = head->next;
            head->prev.reset();
        } else if (nodeToRemove == tail) {

            tail = tail->prev.lock();
            tail->next.reset();
        } else {

            auto nextNode = nodeToRemove->next;
            auto prevNode = nodeToRemove->prev.lock();
            nextNode->prev = prevNode;
            prevNode->next = nextNode;
        }
        nodeToRemove->next.reset();
        nodeToRemove->prev.reset();
    }

    void add(T newData){
        auto newNode = std::make_shared<Node>(newData);
        if (tail == nullptr) { // If the list is empty
            head = tail = newNode; // The new node is now the head and tail
        }
        else {
            tail->next = newNode; // Make the current tail point to the new node
            tail = newNode; // Make the new node the tail of the list
        }
    }
    //  Konstruktor kopiujący
    List(const List& other) : head(nullptr), tail(nullptr) {
        auto current = other.head;
        while (current) {
            this->add(current->data);
            current = current->next;
        }
    }
    // Konstruktor przenoszący
    List(List&& other) noexcept : head(std::move(other.head)), tail(std::move(other.tail)) {
        other.head = nullptr;
        other.tail = nullptr;
    }
// Operator przypisania kopiującego
    List& operator=(const List& other){
        if (this != &other) {
            head = nullptr;
            tail = nullptr;

            auto current = other.head;
            while (current) {
                this->add(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push_back(const T& value){
        auto newNode = std::make_shared<Node>(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void push_front(const T& value) {
        auto newNode = std::make_shared<Node>(value);
        newNode->next = head;

        if (head) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    };

    std::shared_ptr<Node> find(const T& value) const{
        auto current = head;
        while (current) {
            if (current->data == value) return current;
            current = current->next;
        }
        return nullptr;
    };

    void clear(){
        while (this->head) {
            auto temp = head->next;
            head->next = nullptr;
            head->prev.reset();
            head = temp;
        }
        this->tail = nullptr;
    }
    ;
    void print() const{
        auto current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    };


};



#endif //B7727F46_GR05_REPO_LISTLOGIC_H
