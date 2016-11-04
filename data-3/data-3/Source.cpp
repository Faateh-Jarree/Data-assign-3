#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "Queue_class.h"
#include "code_table.h"
//#include "MyForm.h"

using namespace std;

//CALCULATING FREQUENCY OF ALPHABETS
void calc_freq(int arr_sent[]){
	
	//strings to read line and store all file in one string
	string stored_file,line_reader;
	ifstream myfile;

	myfile.open ( "test.txt" );

	while ( myfile.good () ) {
		getline ( myfile, line_reader );
		stored_file += line_reader;		
	}
	myfile.close ();
	//cout << stored_file << endl;		//check = true for large input

	//char count array (initialized as 0)
	for ( int i = 0; i < 256; i++ ) {
		arr_sent[i] = 0;
	}

	//counting frequency
	for ( unsigned int i = 0; i < stored_file.length (); i++ ) {
			for ( int j = 0; j < 256; j++ ) {
				if ( int ( stored_file[i] ) == j ) {
					arr_sent[j]++;
				}
			}
	}
	//cout << arr_sent[32] << endl;		//check = true for All input
}

void encode ( array_freq *arr,int counter ) {

	//strings to read line and store all file in one string
	string stored_file, line_reader;
	ifstream myfile;

	myfile.open ( "test.txt" );

	while ( myfile.good () ) {
		getline ( myfile, line_reader );
		stored_file += line_reader;
	}
	myfile.close ();

	ofstream myfile1;
	myfile1.open ( "encoded_data.txt", ios::out );
	
	if ( myfile1.is_open () ) {

		for ( int i = 0; i < stored_file.size (); i++ ) {
			for ( int j = 0; j < counter; j++ ) {
				if ( stored_file[i] == arr[j].alp ) {
					myfile1 << arr[j].bin_val;
				}
			}
		}
	}
	myfile1.close ();
}

//void decode ( node* root_sent ) {
//
//	node* root_temp1 = root_sent;
//	node* root_temp2 = root_sent;
//	
//	cout << root_sent->right->left->right->left->right->alphabet << endl;
	/*string stored_file, line_reader;
	ifstream myfile;

	myfile.open ( "encoded_data.txt" );

	while ( myfile.good () ) {
		getline ( myfile, line_reader );
		stored_file += line_reader;
	}*/
//	cout << stored_file << endl;
//	ofstream myfile1;
//	myfile1.open ( "decoded_data.txt", ios::out );		
//	
//	if ( myfile1.is_open () ) {
//		
//		for ( int i = 0; i < stored_file.length ();i++ ) {
//			//while ( root_temp1 != NULL ) {
//				
//				if ( stored_file[i] == '0' ) {
//	
//					root_temp1 = root_temp1->left;
//					if ( root_temp1 == NULL ) {
//						break;
//					}
//					/*else if ( i < stored_file.length () ) {
//						i++;
//					}*/					
//				}
//
//				if ( root_temp1->alphabet != NULL ) {
//					cout << root_temp1->alphabet << endl;
//					root_temp1 = root_temp2;
//				}
//
//				if ( stored_file[i] == '1' ) {
//
//					root_temp1 = root_temp1->right;
//					if ( root_temp1 == NULL ) {
//						break;
//					}
//					/*else if ( i < stored_file.length () ) {
//						i++;
//					}*/
//					
//				}				
//			//}//end ehile
//		}//end FOR
//	}//end if myfile1 is open
//}

void decode ( node* root_sent, int size,array_freq arr[] ) {
	string stored_file, line_reader;
	ifstream myfile;

	myfile.open ( "encoded_data.txt" );

	while ( myfile.good () ) {
		getline ( myfile, line_reader );
		stored_file += line_reader;
	}
	myfile.close ();

	ofstream myfile1;
	myfile1.open ( "decoded_data.txt", ios::out );
	
	if ( myfile1.is_open () ) {
		string temp = "";
		for ( int i = 0; i < stored_file.length (); i++ ) {
			temp += stored_file[i];

			for ( int j = 0; j < size; j++ ) {
				if ( temp == arr[j].bin_val ) {
					myfile1 << arr[j].alp;
					temp = "";
					break;
				}
			}
		}
	}
	myfile1.close ();
}

int main () {

/*//////////////////////////////////////////////////////////////STEP 1///////////////////////////////////////////////////*/

	//Calculating frequency of alphabets int the file
	int freq_array[256];
	calc_freq (freq_array);

/*//////////////////////////////////////////////////////////////STEP 2///////////////////////////////////////////////////*/

	//Creating a linked list to hold the trees formed
	Queue Queue_of_trees;

	//Sending the chars with freqs formed as trees to the list of trees
	for ( int i = 0; i < 256; i++ ) {
		if ( freq_array[i] > 0 ) {
			bin_tree to_send ( char ( i ), freq_array[i] );
			Queue_of_trees.enqueue ( to_send );
		}
	}

	//for part 5
	int table_size = 0;
	table_size = Queue_of_trees.get_size ();

	cout << "--------------------------------------------STEP 1-------------------------------------------\n\n";
	Queue_of_trees.display();
	Queue_of_trees.sort_queue ();
	cout << "--------------------------------SORTED LINKED LIST OF TREES STEP 2---------------------------\n\n";
	Queue_of_trees.display ();

/*//////////////////////////////////////////////////////////////STEP 3 & 4///////////////////////////////////////////////////*/
	
	Queue_of_trees.part_3 ();
	cout << "-----------------------------------------STEPS 3 AND 4---------------------------------------\n\n";
	Queue_of_trees.display ();

/*//////////////////////////////////////////////////////////////STEP 5///////////////////////////////////////////////////*/

	cout << "--------------------------------------------STEP 5-------------------------------------------\n\n";

	array_freq *arr = new array_freq[table_size];

	Queue_of_trees.part_5 (arr);
	for ( int i = 0; i < table_size; i++ ) {
		arr[i].print ();
	}
	
	encode ( arr, table_size );

	decode ( Queue_of_trees.get_front_tree (),table_size,arr );

	system ( "pause" );
	return 0;
}