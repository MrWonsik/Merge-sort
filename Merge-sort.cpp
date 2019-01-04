//============================================================================
// Name        : Merge-sort.cpp
// Author      : Tomasz Wasacz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(int *table, int left, int p, int right)
{
	int size_left=p+1-left;
	int size_right=right-p;

	int *table_left=new int[size_left];
	int *table_right=new int[size_right];

	for(int i=0;i<size_left;i++)
	{
		table_left[i]=table[i+left];
	}
	for(int i=0;i<size_right;i++)
	{
		table_right[i]=table[i+p+1];
	}

	int index_left=0;
	int index_right=0;
	int index_main_table=left;

	while(index_left<size_left and index_right<size_right)
	{
		if(table_left[index_left]>table_right[index_right])
			table[index_main_table++]=table_right[index_right++];
		else
			table[index_main_table++]=table_left[index_left++];
	}

	if(index_left==size_left)
	{
		while(index_right<size_right)
			table[index_main_table++]=table_right[index_right++];
	}

	if(index_right==size_right)
	{
		while(index_left<size_left)
			table[index_main_table++]=table_left[index_left++];
	}
}


void merge_sort(int *table, int left, int right)
{
	if(left<right)
	{
		int p=(left+right)/2;
		merge_sort(table, left, p);
		merge_sort(table, p+1, right);
		merge(table, left, p, right);
	}
}



void show_table(int *table, int table_size)
{
	for(int i=0;i<table_size;i++)
		cout << table[i] << ' ';
}

int main() {
	srand(time(NULL));
	int table_size=10;
	int *table = new int[table_size];

	for(int i=0; i<table_size; i++)
		table[i]=rand() % table_size;

	cout << "Before sort: " << endl;
	show_table(table, table_size);

	merge_sort(table, 0, table_size-1);

	cout << "After sort: " << endl;
	show_table(table, table_size);
	return 0;
}
