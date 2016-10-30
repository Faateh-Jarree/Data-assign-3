#pragma once
#include <iostream>
#include "Tree_class.h"
using namespace std;

struct Node {
	bin_tree record;
	Node *next;

	Node () :record (), next ( NULL ) {}
};

class Queue {

private:
	Node *rear;
	Node *front;

public:

	//Constructor for queue class
	Queue () :rear ( NULL ), front ( NULL ) {}

	//If queue is empty
	bool is_empty () {
		return front == NULL;
	}

	//Enqueue Function which adds a tree
	void enqueue ( bin_tree tree_sent ) {

		Node *temp = new Node;

		temp->record = tree_sent;
		temp->next = NULL;

		if ( is_empty () ) {
			this->front = this->rear = temp;
		}

		else {
			this->rear->next = temp;
			this->rear = temp;
		}

		this->rear->next = NULL;
	}

	//The dequeue function. Will return the dequeued node. (if required later)
	Node* dequeue () {

		Node *temp = new Node;
		Node *temp2 = new Node;

		if ( is_empty () ) {
			front = rear = NULL;
			cout << "The Queue is empty, so there's nothong to dequeue. :)\n";
		}

		else {

			temp->record = this->front->record;
			this->front = this->front->next;
			temp2 = temp;

			delete temp;//ss
		}

		return temp2;
	}

	void display () {

		Node *displayer = front;

		if ( is_empty () ) {

			cout << "The Queue is empty, so there's nothing to display. :)\n";
		}

		else {

			while ( displayer != NULL ) {
				displayer->record.print ();
				displayer = displayer->next;
			}
		}
	}

	void sort_queue () {
			
		Node *temp = front;
	
		int counter = 0;
		int temp_freq;
		char temp_char;
	
		while ( temp ) {
			temp = temp->next;
			counter++;
		}
		temp = front;
	
		for ( int i = 0; i < counter; i++ ) {
	
			while ( temp->next ) {
	
				if ( temp->record.get_freq() > temp->next->record.get_freq() ) {
	
					temp_freq = temp->record.get_freq ();
					temp_char = temp->record.get_alpha ();
						
					temp->record.set_freq ( temp->next->record.get_freq () );
					temp->record.set_alpha ( temp->next->record.get_alpha () );
	
					temp->next->record.set_freq ( temp_freq );
					temp->next->record.set_alpha ( temp_char );
						
				}
	
				else {
					temp = temp->next;
				}
			}
			temp = front;
		}
	}
};
//struct linked_list {
//	Node *head;
//
//	linked_list () :head ( NULL ) {}
//
//	bool is_empty () {
//		if ( head == NULL ) { return true; }
//		else { return false; }
//	}
//
//	void add_tree ( bin_tree tree_sent ) {
//
//		if ( is_empty () ) {
//			//			cout<<"yy";
//			head = new Node;
//			head->record = tree_sent;
//			head->next = NULL;
//		}
//		else {
//			//			cout<<"xx\n";
//			Node *temp_Node = new Node;
//			temp_Node->record = tree_sent;
//			temp_Node->next = NULL;
//
//			Node* _last = head;
//			while ( _last->next != NULL ) {
//				_last = _last->next;
//			}
//			_last->next = temp_Node;
//		}
//	}
//
//	void sort_list () {
//		
//		Node *temp = head;
//
//		int counter = 0;
//		int temp_freq;
//		char temp_char;
//
//		while ( temp ) {
//			temp = temp->next;
//			counter++;
//		}
//		temp = head;
//
//		for ( int i = 0; i < counter; i++ ) {
//
//			while ( temp->next ) {
//
//				if ( temp->record.get_freq() > temp->next->record.get_freq() ) {
//
//					temp_freq = temp->record.get_freq ();
//					temp_char = temp->record.get_alpha ();
//					
//					temp->record.set_freq ( temp->next->record.get_freq () );
//					temp->record.set_alpha ( temp->next->record.get_alpha () );
//
//					temp->next->record.set_freq ( temp_freq );
//					temp->next->record.set_alpha ( temp_char );
//					
//				}
//
//				else {
//					temp = temp->next;
//				}
//			}
//			temp = head;
//		}
//	}
//
//	void print () {
//	
//		if ( is_empty () ) {
//			cout << "list is empty. cant print.\n";
//		}
//	
//		else {
//			Node* printer = head;
//			for ( ; printer != NULL;) {
//				cout << "Alphabet = " << printer->record.get_alpha ();
//				cout << "\tFrequency =  " << printer->record.get_freq() << endl;
//				printer = printer->next;
//			}
//		}
//	}
//
//	//Implementing Part 3
//	void part_3 () {
//
//		bin_tree temp;
//		Node *temp_ptr = head;
//		node *temp_left;
//		node *temp_right;
//
//		while ( temp_ptr->next != NULL ) {
//
//			temp_left = temp_ptr->record.get_root();
//			temp_left = temp_ptr->next->record.get_root ();
//			temp.create_new ( temp_left, temp_right );
//
//			this->add_tree ( temp );
//			
//			for ( int i = 0; i < 2; i++ ) {
//				temp_ptr = temp_ptr->next;
//			}
//			
//			this->head = temp_ptr;
//			this->sort_list ();
//		}
//	}
//};