//--------------------------------------------------------------------
//
//  Laboratory 12, In-lab Exercise 1                      logitree.h
//
//  Class declarations for the linked implementation of the Logic
//  Expression Tree ADT -- including the recursive partners of the
//  public member functions
//
//--------------------------------------------------------------------

class ExprTree;           // Forward declaration of the ExprTree class

class ExprTreeNode        // Facilitator class for the ExprTree class
{
private:

    // Constructor
    ExprTreeNode(char elem,
        ExprTreeNode* leftPtr, ExprTreeNode* rightPtr);

    // Data members
    char dataItem;          // Expression tree data item
    ExprTreeNode* left,     // Pointer to the left child
        * right;    // Pointer to the right child

    friend class ExprTree;
};

//--------------------------------------------------------------------

class ExprTree
{
public:

    // Constructor
    ExprTree();

    // Destructor
    ~ExprTree();

    // Expression tree manipulation operations
    void build();                // Build tree from prefix expression
    void expression() const;     // Output expression in infix form
    int evaluate() const;        // Evaluate expression
    void clear();                // Clear tree

    // Output the tree structure -- used in testing/debugging
    void showStructure() const;

private:

    // Recursive partners of the public member functions
    void buildSub(ExprTreeNode*& p);
    void exprSub(ExprTreeNode* p) const;
    int evaluateSub(ExprTreeNode* p) const;
    void clearSub(ExprTreeNode* p);
    void showSub(ExprTreeNode* p, int level) const;

    // Data member
    ExprTreeNode* root;   // Pointer to the root node
};
