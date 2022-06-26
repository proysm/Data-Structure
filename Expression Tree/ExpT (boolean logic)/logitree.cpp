//--------------------------------------------------------------------
//		Lab 12									logitree.cpp
//
//--------------------------------------------------------------------

#include "logitree.h"
#include <iostream>

using namespace std;
//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode* leftPtr, ExprTreeNode* rightPtr)
    :dataItem(elem), left(leftPtr), right(rightPtr)
{

}

//--------------------------------------------------------------------

ExprTree::ExprTree()
    : root(0)
{

}

ExprTree::~ExprTree()
{
    delete root;
}

//--------------------------------------------------------------------

void ExprTree::build()
{
    buildSub(root);
}

void ExprTree::buildSub(ExprTreeNode*& p)
{
    char c;
    cin >> c;
    p = new ExprTreeNode(c, NULL, NULL);
    if (p->dataItem == '+' || p->dataItem == '*' )
    {
        buildSub(p->left);
        buildSub(p->right);
        return;
    }
    else if (p->dataItem == '-')
    {
        buildSub(p->right);
        return;
    }
    else
    {
        return;
    }
    
}

//--------------------------------------------------------------------

void ExprTree::expression() const
{
    exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const
{
    if (p != NULL) {
        
        if (p->dataItem == '+' || p->dataItem == '*' || p->dataItem == '/')
        {
            cout << '(';
            exprSub(p->left);
            cout << p->dataItem;
            exprSub(p->right);
            cout << ')';
        }
        else if (p->dataItem == '-')
        {
            cout << '(';
            cout << p->dataItem;
            exprSub(p->right);
        }
        else
        { 
            cout << p->dataItem;
        }

    }
}

//--------------------------------------------------------------------

int ExprTree::evaluate() const
{
    return evaluateSub(root);
}

int ExprTree::evaluateSub(ExprTreeNode* p) const
{
    switch (p->dataItem) {
    case '+': return (evaluateSub(p->left) + evaluateSub(p->right));
        break;
    case '-': return (!evaluateSub(p->right));
        break;
    case '*': return (evaluateSub(p->left) * evaluateSub(p->right));
        break;
    case '/': return (evaluateSub(p->left) / evaluateSub(p->right));
        break;
    default: return (p->dataItem - 48);
    }
}

//--------------------------------------------------------------------

void ExprTree::clear()
{
    if (root == NULL) cout << "Tree is empty" << endl;
    else clearSub(root);
}

void ExprTree::clearSub(ExprTreeNode* p)
{
    if (p != NULL) {
        clearSub(p->left);
        clearSub(p->right);
        delete p;
        root = NULL;
    }
}

//--------------------------------------------------------------------

void ExprTree::showStructure() const

// Outputs an expression tree. The tree is output rotated counter-
// clockwise 90 degrees from its conventional orientation using a
// "reverse" inorder traversal. This operation is intended for testing
// and debugging purposes only.

{
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void ExprTree::showSub(ExprTreeNode* p, int level) const

// Recursive partner of the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the expression tree.

{
    int j;

    if (p != 0)
    {
        showSub(p->right, level + 1);
        for (j = 0; j < level; j++)
            cout << "\t";
        cout << " " << p->dataItem;
        if ((p->left != 0) &&
            (p->right != 0))
            cout << "<";
        else if (p->right != 0)
            cout << "/";
        else if (p->left != 0)
            cout << "\\";
        cout << endl;
        showSub(p->left, level + 1);
    }
}