#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "array_frequency.h"

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
		//stored_file += '\n';			//new line after every line read
	}
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
	int size = 0;
	size = Queue_of_trees.get_size ();

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

	array_freq *arr = new array_freq[size];
	Queue_of_trees.part_5 (arr);
	arr[0].print ();
	system ( "pause" );
	return 0;
}