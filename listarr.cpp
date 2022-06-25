//--------------------------------------------------------------------
//  ��ǻ�Ͱ��а� 2021111954 ������
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//  Hellloooooooooo
//--------------------------------------------------------------------

#include "listarr.h"
#include <iostream>
#include <windows.h>

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).
	:maxSize(maxNumber), size(0), cursor(-1)
{
	dataItems = new DataType[maxSize]; // ��ü ����Ʈ �޸� �Ҵ�
	// pre-lab

}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	delete[] dataItems;
	// pre-lab

}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem) 

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	if (isFull()) cout << "Full List " << endl; // ����Ʈ�� ���� ���

	else if (isEmpty()) {//����Ʈ�� �� ���
		dataItems[size] = newDataItem;
		size++;
		cursor++;
	}
	else { //������ ���
		dataItems[size] = newDataItem;
		for (int i = 0; i < size; i++){
			for (int i = 0; i < size; i++) {
				if (dataItems[i] > dataItems[i + 1]){
					DataType* memory;
					int a = 1;
					int b = 2;
					memory = new DataType[maxSize]; //����Ʈ �޸� �Ҵ�
					memory[a] = dataItems[i];
					memory[b] = dataItems[i + 1];
					dataItems[i] = memory[b];
					dataItems[i + 1] = memory[a];
				}
			}
		}
		size++;
		cursor++;
	}
}

//--------------------------------------------------------------------

void List::remove() 

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	if(isEmpty()) cout << "Empty List " << endl; // ����Ʈ�� �� ���
	else {
		dataItems[cursor] = NULL;
		for (int i = cursor; i < maxSize; i++) {
			if (cursor == maxSize) dataItems[cursor] = NULL;
			else {
				dataItems[i] = NULL;
				dataItems[i] = dataItems[i + 1];
			}
		}
	}
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem) 

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	if (isEmpty()) cout << "Empty List " << endl; // ����Ʈ�� �� ���
	// Requires that the list is not empty
	else {
		dataItems[cursor] = NULL;
		dataItems[cursor] = newDataItem;
		for (int i = 0; i <= size - 1; i++) {
			for (int i = 0; i <= size - 1; i++) {
				if (dataItems[i] > dataItems[i + 1])
				{
					DataType* memory;
					int a = 1;
					int b = 2;
					memory = new DataType[maxSize];
					memory[a] = dataItems[i];
					memory[b] = dataItems[i + 1];
					dataItems[i] = memory[b];
					dataItems[i + 1] = memory[a];
				}
			}
		}
	}
	if (cursor == maxSize) cursor = 0;
	else cursor++;
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	for (int i = 0; i < maxSize; i++) {
		dataItems[i] = NULL;
		size = NULL;
	}
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns true if a list is empty. Otherwise, returns false.
{
	if (size == 0) return 1;
	else return 0;
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns true if a list is full. Otherwise, returns false.
{
	if (size == maxSize) return 1;
	else return 0;
}

//--------------------------------------------------------------------

bool List::gotoBeginning() 
// Moves the cursor to the beginning of the list.
{
	cursor = 0;
	return cursor;
}

//--------------------------------------------------------------------

bool List::gotoEnd()

// Moves the cursor to the end of the list.

{
	cursor = size;
	return cursor;
}

//--------------------------------------------------------------------

bool List::gotoNext() 

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	if (cursor == maxSize) return false;
	else cursor++;
}

//--------------------------------------------------------------------

bool List::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	if (cursor == -1) return false;
	else cursor--;
}

//--------------------------------------------------------------------

DataType List::getCursor() const 

// Returns the item marked by the cursor.
{
	return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	cout << "size = " << size << "\t" << "cursor = " << cursor << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cout << "[ " << i << " ]\t";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << dataItems[i] << "  \t";
	}
	cout << endl;
}

//--------------------------------------------------------------------

//in-lab
void List::moveToNth(int n)
{
	DataType* memory;
	int a = 1;
	int b = 2;
	memory = new DataType[maxSize];
	memory[a] = dataItems[cursor];
	for (int i = 0; i < n; i++) {
		memory[b] = dataItems[i];
		dataItems[i] = dataItems[i + 1];
	}
	dataItems[n] = memory[a];
}

bool List::find(const DataType& searchdataitem)
{
	for (int i = cursor; i < maxSize; i++) {
		if (dataItems[i] == searchdataitem) return true;
	}
	return false;
}