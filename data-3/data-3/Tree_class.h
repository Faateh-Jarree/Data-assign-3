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

	node (char alpha = '\n',int freq = 0) :alphabet ( alpha ),frq ( freq ),left ( NULL ), right ( NULL ){}
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

	//Forming a tree of two trees
	void create_new ( node *lft, node *rht ) {
		
		int k = 0;
		int j = 0;
		root = new node;
		
		if ( root->left != NULL ) {
			k = lft->frq;
		}
		
		if ( root->right != NULL ) {
			j = rht->frq;
		}
		
		root->alphabet = NULL;
		root->frq = k + j;
		root->left = lft;
		root->right = rht;
	}

	//INSERTION OF A NODE IN A TREE
	void insert ( char alph_sent, int freq_sent,node *root_sent) {

		if ( root != NULL )
		{
			if ( freq_sent< root->frq )
			{
				if ( root->left != NULL )
					insert ( alph_sent, freq_sent, root_sent->left );
				else
				{
					root->left = new node;
					root->left->frq = freq_sent;
					root->left->alphabet = alph_sent;
					root->left->left = NULL;
					root->left->right = NULL;
				}
			}

			else if ( freq_sent >= root->frq )
			{
				if ( root->right != NULL )
					insert ( alph_sent, freq_sent, root_sent->right );
				else
				{
					root->right = new node;
					root->right->frq = freq_sent;
					root->right->alphabet = alph_sent;
					root->right->left = NULL;
					root->right->right = NULL;
				}
			}
		}

		else
		{
			root = new node;
			root->frq = freq_sent;
			root->alphabet = alph_sent;
			root->left = NULL;
			root->right = NULL;
		}
	}
	
	node* search ( int freq_sent, node *root ) {

		if ( root != NULL )
		{
			if ( freq_sent == root->frq )
				return root;
			else if ( freq_sent<root->frq )
				return search ( freq_sent, root->left );
			else
				return search ( freq_sent, root->right );
		}
		else return NULL;
	}
	
	void delete_tree ( node *root ) {
		
		if ( root != NULL )
		{
			delete_tree ( root->left );
			delete_tree ( root->right );
			delete root;
		}
	}

	void print () {
		if ( root == NULL ) {
			cout << "Tree is empty. cant print.\n";
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
				cout << "\tRight frq =  " << root->left->frq;
			}
			cout << endl;
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
};