#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;

    public:
        List(){
            start = nullptr;
        };

        T front(){
            return start->data;
        };

        T back(){
            return start->prev->data;
        };

        void push_front(T value){
            auto* node = new Node<T>;
            node->data = value;
            if(start){
                node->next =this->start;
                node->prev = this->start->prev;
                this->start->prev->next = node;
                this->start->prev = node;
                this->start = node;
                cout<<"Pushed in non empty list\n";
            }
            else{
                node->prev = node;
                node->next = node;
                this->start = node;
                cout<<"Pushed in empty list\n";
            }
        };

        void push_back(T value){
            auto node = new Node<T>;
            node->data = value;
            if(start){
                node->next = this->start;
                node->prev = this->start->prev->next;
                this->start->prev->next = node;
                this->start->prev = node;
                cout<<"Pushed in non empty list\n";
            }
            else{
                node->prev = node;
                node->next = node;
                this->start = node;
                cout<<"Pushed in empty list\n";
            }
        };
        void pop_front(){
            if(start){
                auto* tmp = new Node<T>;
                tmp = this->start;
                this->start->prev->next = this->start->next;
                this->start->next->prev = this->start->prev;
                this->start = this->start->next;
                if(this->start == this->start->next)
                    cout<<"One single element in list!\n";
                delete tmp;
            }
            else{
                cout<<"Error: Empty List!\n";
            }
        };
        void pop_back(){

        };

        T get(int position){

        };

        void concat(List<T> &other){
            this->start->prev->next = other.start;
        };

        bool empty(){
            return (bool)!(this->start);
        };

        int size(){
            int n=1;
            auto* temp = this->start;
            while(temp->next!=start){
                temp = temp->next;
                n++;
            }
            return n;
        };

        void clear(){

        };

        Iterator<T> begin();
        Iterator<T> end();

        ~List()= default;
};

#endif