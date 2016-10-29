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
	void insert ( node *lft, node *rht ) {
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

	char get_alpha () {
		return this->root->alphabet;
	}

	int get_freq () {
		return this->root->frq;
	}
};