#include "bstdecision.cpp"
#include <iostream>
#include <string>

class TestData
{
public:

	void setKey(int newKey)
	{
		keyField = newKey;
	}   // Set the key

	int key() const
	{
		return keyField;
	}     // Returns the key

private:

	int keyField;                // Key for the data item
};

int main()
{
	BSTree<TestData, int> testTree;
	TestData testData;
	int i=0, iRoot, cnt1=0, cnt2=0;
	char cmd, input;
	char arrLeft[100], arrRight[100];


	do {
		cout << "Enter: ";
		cin >> cmd;
		if (cmd == '(')
		{
			//루트값
			cin >> iRoot;
			//왼쪽 서브트리값
			do {
				cin >> input;
				if (input == '(') cnt1++;
				else if (input == ')') cnt2++;
				arrLeft[i] = input;
				i++;
			} while (cnt1 != cnt2);
			//오른쪽 서브트리값
			do {
				cin >> input;
				if (input == '(') cnt1++;
				else if (input == ')') cnt2++;
				arrRight[i] = input;
				i++;
			} while (cnt1 != cnt2);
			
			if (testTree.isValid())
				cout << "This is a BST." << endl;
			else
				cout << "This is NOT a BST!" << endl;
		}
		cout << endl;
	} while (cmd != 'Q' && cmd != 'q');

	return 0;
}