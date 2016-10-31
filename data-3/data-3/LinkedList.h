#pragma once
#include <iostream>
#include "Tree_class.h"
#include "array_frequency.h"
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
	bin_tree dequeue () {

		bin_tree temp;
		bin_tree temp2;

		if ( is_empty () ) {
			front = rear = NULL;
			cout << "The Queue is empty, so there's nothong to dequeue. :)\n";
		}

		else {

			temp = this->front->record;
			this->front = this->front->next;
			temp2 = temp;
		}
		//cout<<"LOOOL = "<<temp2->frq<< endl;
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
		bin_tree temp2;
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
	
					temp2 = temp->record;
					temp->record = temp->next->record;
					temp->next->record = temp2;
				}
	
				else {
					temp = temp->next;
				}
			}
			temp = front;
		}
	}

	int get_size () {
		Node* temp_ptr = front;
		int counter;
		while ( temp_ptr ) {
			counter++;
			temp_ptr = temp_ptr->next;
		}
		return counter;
	}

	//Implementing Part 3 and 4
	void part_3 () {

		Node* temp_ptr = front;
		int counter;
		bin_tree temp;
		bin_tree temp_left;
		bin_tree temp_right;

		while ( temp_ptr ) {
			counter++;
			temp_ptr = temp_ptr->next;
		}
	
		for ( int i = 1; i < counter; i++ ) {
			temp_left = this->dequeue ();
			temp_right = this->dequeue ();
			temp.create_new ( temp_left.get_root (), temp_right.get_root () );
			this->enqueue ( temp );
			this->sort_queue ();
		}
	}

	//Implementing Part 5
	void part_5 (array_freq ar[]) {
	
		string ss="";
		node* j = this->front->record.get_root ();
		this->front->record.assign_traversal_values ( j, ss ,ar);
	}
};