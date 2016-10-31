#pragma once
#include <iostream>
using namespace std;

struct array_freq{
	char alp;
	string bin_val;

	array_freq ( ) {
		bin_val = "";
		alp = NULL;
	}

	array_freq ( string ss, char al ) {
		bin_val = ss;
		alp = al;
	}

	void print () {
		cout << "alphabet = " << alp<<'\t';
		cout << "binary = " << bin_val << endl;
	}
};