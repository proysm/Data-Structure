//--------------------------------------------------------------------
//		Lab 12									exprtree.cpp
//
//--------------------------------------------------------------------

#include "exprtree.h"
#include <iostream>

using namespace std;
//--------------------------------------------------------------------

ExprtreeNode::ExprtreeNode(char elem, ExprtreeNode* leftPtr, ExprtreeNode* rightPtr)
    :dataItem(elem), left(leftPtr), right(rightPtr)
{

}

//--------------------------------------------------------------------

Exprtree::Exprtree()
    :root(0)
{

}

Exprtree::~Exprtree()
{
    delete root;
}

//--------------------------------------------------------------------

void Exprtree::build()
{
    buildSub(root);
}

void Exprtree::buildSub(ExprtreeNode*& p)
{
    char c;
    cin >> c;
    p = new ExprtreeNode(c, NULL, NULL);
    if (p->dataItem == '+' || p->dataItem == '-' || p->dataItem == '*' || p->dataItem == '/')
    {
        buildSub(p->left);
        buildSub(p->right);
        return;
    }
    else
    {
        return;
    }
}

//--------------------------------------------------------------------

void Exprtree::expression() const
{
    exprSub(root);
}

void Exprtree::exprSub(ExprtreeNode* p) const
{
    if (p != NULL) {
        if (p->dataItem == '+' || p->dataItem == '-' || p->dataItem == '*' || p->dataItem == '/')
        {
            cout << '(';
            exprSub(p->left);
            cout << p->dataItem;
            exprSub(p->right);
            cout << ')';
        }
        else
        {
            cout << p->dataItem;
        }
    }
}

//--------------------------------------------------------------------

float Exprtree::evaluate() const
{
    return evaluateSub(root);
}

float ExprTree::evaluateSub(ExprtreeNode* p) const
{
    switch (p->dataItem) {
    case '+': return (evaluateSub(p->left) + evaluateSub(p->right));
        break;
    case '-': return (evaluateSub(p->left) - evaluateSub(p->right));
        break;
    case '*': return (evaluateSub(p->left) * evaluateSub(p->right));
        break;
    case '/': return (evaluateSub(p->left) / evaluateSub(p->right));
        break;
    default: return (p->dataItem - 48);
    }
}

//--------------------------------------------------------------------

void Exprtree::clear()
{
    if (root == NULL) cout << "Tree is empty" << endl;
    else clearSub(root);
}

void Exprtree::clearSub(ExprtreeNode* p)
{
    if (p != NULL) {
        clearSub(p->left);
        clearSub(p->right);
        delete p;
        root = NULL;
    }
}

//--------------------------------------------------------------------

void Exprtree::showStructure() const
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

void ExprTree::showSub(ExprtreeNode* p, int level) const
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

//--------------------------------------------------------------------
void Exprtree::commute()
{
    commuteSub(root);
}
 

void Exprtree::commuteSub(ExprtreeNode*& p)
{
    ExprTreeNode* temp;
    if (p != NULL) {
        commuteSub(p->left);
        temp = p->left;
        p->left = p->right;
        p->right = temp;// 노드의 left와 right를 바꿔준다.
        commuteSub(p->left); //left와 right가 바뀐 상태이기 때문
    }
}