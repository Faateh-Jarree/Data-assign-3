#pragma once
#include <iostream>
#include "Tree_class.h"
using namespace std;

struct Node {
	bin_tree record;
	Node *next;

	Node () :record (), next ( NULL ) {}
};

struct linked_list {
	Node *head;

	linked_list () :head ( NULL ) {}

	bool is_empty () {
		if ( head == NULL ) { return true; }
		else { return false; }
	}

	void add_tree ( bin_tree tree_sent ) {

		if ( is_empty () ) {
			//			cout<<"yy";
			head = new Node;
			head->record = tree_sent;
			head->next = NULL;
		}
		else {
			//			cout<<"xx\n";
			Node *temp_Node = new Node;
			temp_Node->record = tree_sent;
			temp_Node->next = NULL;

			Node* _last = head;
			while ( _last->next != NULL ) {
				_last = _last->next;
			}
			_last->next = temp_Node;
		}
	}

	void sort_list () {
		
		Node *temp = head;

		int counter = 0;
		int temp_freq;
		char temp_char;

		while ( temp ) {
			temp = temp->next;
			counter++;
		}
		temp = head;

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
			temp = head;
		}
	}

	void print () {
	
		if ( is_empty () ) {
			cout << "list is empty. cant print.\n";
		}
	
		else {
			Node* printer = head;
			for ( ; printer != NULL;) {
				cout << "Alphabet = " << printer->record.get_alpha ();
				cout << "\tFrequency =  " << printer->record.get_freq() << endl;
				printer = printer->next;
			}
		}
	}
};

//Node* find_tree ( bin_tree& tree_sent ) {

//	bool is_found = false;
//	Node *finder = head;
	//	if ( finder->record.get_alp() == tree_sent.get_alp() ) {
	//		return finder;
	//	}
	//	else {
	//		for ( ; finder->next != NULL;) {
	//			finder = finder->next;
	//			if ( finder->record.id == id_sent ) {
	//				is_found = true;
	//				break;
	//			}
	//		}
	//		if ( is_found ) {
	//			return finder;
	//		}
	//		else {
	//			return NULL;
	//		}
	//	}
	//}

//	void del_employee ( string x ) {
//
//		if ( is_empty () ) {
//			cout << "LIST IS ALREADY EMPTY.\n";
//			return;
//		}
//
//		else {
//
//			Node *del = find_employee ( x );
//			if ( del != NULL ) {
//
//				Node *prev = NULL;
//				Node *curr = head;
//
//				while ( curr->record.id != x ) {
//					prev = curr;
//					curr = curr->next;
//				}
//
//				if ( curr ) {
//
//					if ( prev ) {
//						prev->next = curr->next;
//					}
//
//					else {
//						head = curr->next;
//						delete curr;
//					}
//				}
//			}
//
//			else {
//				cout << "Employee record does not exist for the provided ID.\n";
//			}
//		}
//	}
