#pragma once
#include <iostream>
using namespace std;

struct node
{
	char alphabet;	//Alphabet
	int frq;		//Frequency of Aplhabet

	//Children
	node *left;
	node *right;

	node (char alpha = NULL,int freq = 0) :alphabet ( alpha ),frq ( freq ),left ( NULL ), right ( NULL ){}
};

class bin_tree
{
	node *root;

public:

	//default constructor
	bin_tree () :root ( NULL ) {}

	//copy constructor
	bin_tree ( char alpha_sent, int freq_sent ) {
		root = new node;
		root->alphabet = alpha_sent;
		root->frq = freq_sent;
		root->left = NULL;
		root->right = NULL;
	}

	//Operator overload for 'bin tree 1 = bin tree 2'
	bin_tree& operator=(node*& root_sent) {

		this->root->alphabet = root_sent->alphabet;
		this->root->frq = root_sent->frq;
		this->root->left->alphabet = root_sent->left->alphabet;
		this->root->right->alphabet = root_sent->right->alphabet;
		this->root->left->frq = root_sent->left->frq;
		this->root->right->frq = root_sent->right->frq;
		return *this;

	}

	//Forming a tree of two trees
	void create_new ( node *lft, node *rht ) {
		
		int k = 0;
		int j = 0;
		root = new node;

		root->alphabet = NULL;		
		k = lft->frq;
		j = rht->frq;
		root->frq = k + j;
		root->left = lft;
		root->right = rht;
		root->left->left = NULL;
		root->left->right = NULL;
		root->right->right = NULL;
		root->right->right = NULL;
	}

	void print () {
		if ( root == NULL ) {
			cout << "Tree is empty. cant print.\n";
		}
				
		else {
			
			if ( root->alphabet == NULL ) {
				cout << "Root char = NULL";
				cout << "\tRoot frq =  " << root->frq << endl;

				if ( root->left != NULL ) {
					if ( root->left->alphabet == NULL ) {
						cout << "Left char = NULL";
						cout << "\tLeft frq =  " << root->left->frq;
					}
					else {
						cout << "Left char = " << root->left->alphabet;
						cout << "\tLeft frq =  " << root->left->frq;
					}
				}

				if ( root->right != NULL ) {
					if ( root->right->alphabet == NULL ) {
						cout << "\t\tRight char = NULL";
						cout << "\tRight frq =  " << root->right->frq;
					}
					else {
						cout << "\t\tRight char = " << root->right->alphabet;
						cout << "\tRight frq =  " << root->right->frq;
					}
				}
				cout << endl << endl;
			}

			else {
				cout << "Root char = " << root->alphabet;
				cout << "\tRoot frq =  " << root->frq << endl;

				if ( root->left != NULL ) {
					cout << "Left char = " << root->left->alphabet;
					cout << "\tLeft frq =  " << root->left->frq;
				}

				if ( root->right != NULL ) {
					cout << "\tRight char = " << root->right->alphabet;
					cout << "\tRight frq =  " << root->right->frq;
				}
				cout << endl;
			}
		}
	}

	void assign_traversal_values ( node* root_sent, string to_assign ) {

		string sss;
		if ( root_sent != NULL ) {
			assign_traversal_values ( root_sent->left, to_assign += "0" );
			assign_traversal_values ( root_sent->right, to_assign += "1" );
		}

		else {
			//to_assign = to_assign.substr ( 0, to_assign.size () - 1 );
			sss += to_assign;
			cout << sss<<endl;
			return;
		}
	}

	node* get_root () {
		return this->root;
	}

	char get_alpha () {
		return this->root->alphabet;
	}

	int get_freq () {
		return this->root->frq;
	}

	void set_freq ( int sent ) {
		this->root->frq = sent;
	}

	void set_alpha ( char sent ) {
		this->root->alphabet = sent;
	}

	void set_left_freq ( int sent ) {
		this->root->left->frq = sent;
	}

	void set_left_alpha ( char sent ) {
		this->root->left->alphabet = sent;
	}

	void set_right_freq ( int sent ) {
		this->root->right->frq = sent;
	}

	void set_right_alpha ( char sent ) {
		this->root->right->alphabet = sent;
	}

	node* get_left () {
		return this->root->left;
	}
	
	node* get_right () {
		return this->root->right;
	}

	char get_left_char () {
		return this->root->left->alphabet;
	}

	char get_right_char () {
		return this->root->right->alphabet;
	}
};

//INSERTION OF A NODE IN A TREE
//void insert ( char alph_sent, int freq_sent,node *root_sent) {

//	if ( root != NULL )
//	{
//		if ( freq_sent< root->frq )
//		{
//			if ( root->left != NULL )
//				insert ( alph_sent, freq_sent, root_sent->left );
//			else
//			{
//				root->left = new node;
//				root->left->frq = freq_sent;
//				root->left->alphabet = alph_sent;
//				root->left->left = NULL;
//				root->left->right = NULL;
//			}
//		}

//		else if ( freq_sent >= root->frq )
//		{
//			if ( root->right != NULL )
//				insert ( alph_sent, freq_sent, root_sent->right );
//			else
//			{
//				root->right = new node;
//				root->right->frq = freq_sent;
//				root->right->alphabet = alph_sent;
//				root->right->left = NULL;
//				root->right->right = NULL;
//			}
//		}
//	}

//	else
//	{
//		root = new node;
//		root->frq = freq_sent;
//		root->alphabet = alph_sent;
//		root->left = NULL;
//		root->right = NULL;
//	}
//}

//node* search ( int freq_sent, node *root ) {

//	if ( root != NULL )
//	{
//		if ( freq_sent == root->frq )
//			return root;
//		else if ( freq_sent<root->frq )
//			return search ( freq_sent, root->left );
//		else
//			return search ( freq_sent, root->right );
//	}
//	else return NULL;
//}
//
//void delete_tree ( node *root ) {
//	
//	if ( root != NULL )
//	{
//		delete_tree ( root->left );
//		delete_tree ( root->right );
//		delete root;
//	}
//}