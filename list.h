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
        int nodes=0; // Para que está nodes?
    public:
        List(){
            start = nullptr;
        };

        T front(){
            if(start)
                return start->data;
            throw (exception_ptr());
        };

        T back(){
            if(start)
                return start->prev->data;
            else
                throw(exception_ptr());
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
                nodes++;
//                cout<<"Pushed in non empty list\n";
            }
            else{
                node->prev = node;
                node->next = node;
                this->start = node;
                nodes++;
//                cout<<"Pushed in empty list\n";
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
                nodes++;
//                cout<<"Pushed in non empty list\n";
            }
            else{
                node->prev = node;
                node->next = node;
                this->start = node; 
                nodes++;
//                cout<<"Pushed in empty list\n";
            }
        };
        void pop_front(){ // No estás actualizando nodes
            if(!start)
                return;

            auto* tmp = this->start;
            if(this->size()==1){
                delete tmp;
                this->start = nullptr;
            }

            else {
                this->start->prev->next = this->start->next;
                this->start->next->prev = this->start->prev;
                this->start = this->start->next;
                delete tmp;
            }
        };

        void pop_back(){ // No estás actualizando nodes
            if(!start)
                return;

            auto* tmp = this->start->prev;
            cout << "Size: " << size() << endl;
            if(this->size()==1){
                delete tmp;
                this->start = nullptr;
            }

            else{
                this->start->prev = tmp->prev;
                tmp->prev->next = this->start; // Esto está mal, deberías hacerlo como el pop anterior
                delete tmp;
            }
        };

        T get(int position){
            if(start) {
                auto *tmp = this->start;
                for (int i = 0; i < position; i++) { // Podrías usar módulo
                    tmp = tmp->next;
                }
                return tmp->data;
            }
            throw(exception_ptr());

        };

        void concat(List<T> &other){
            this->start->prev->next = other.start;
            this->start->prev = other.start->prev; // Falta actualizar Other
        };

        bool empty(){
            return (bool)!(this->start); // No es necesario el cast
        };

        int size(){
            int n=1;
            if(this->start){
            auto* tmp = this->start;

            while(tmp->next != this->start){
                tmp = tmp->next;
                n++;
                }
            }
            else
                n--;
            return n;
        };

        void clear(){
            auto* tmp = this->start;
            while(this->size()){
                auto* tmp_aux = tmp;
                tmp = tmp->next;
                delete tmp_aux;
            }
            delete tmp;
            this->start = nullptr;
        };

        Iterator<T> begin(){
            return Iterator<T>(this->start);
        };
        Iterator<T> end(){
            return Iterator<T>(this->start->prev);
        };

        ~List(){
            auto* tmp = this->start;
            for(int i=0;i<this->size();i++){
                if(tmp->next!= this->start){
                    tmp =tmp->next;
                    delete tmp->prev;
                }
            }
            delete tmp;
        };
};

#endif