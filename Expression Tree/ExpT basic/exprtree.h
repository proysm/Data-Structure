//--------------------------------------------------------------------
//		lab 12									exprtree.h
//
//  class declarations for the linked implementation of the
//  expression tree adt -- including the recursive partners of the
//  public member functions
//
//--------------------------------------------------------------------

class Exprtree;			   // forward declaration of the exprtree class

class ExprtreeNode         // facilitator class for the exprtree class
{
private:

	// constructor
	ExprtreeNode(char elem,
		ExprtreeNode* leftptr, ExprtreeNode* rightptr);

	// data members
	char dataItem;          // expression tree data item
	ExprtreeNode* left,     // pointer to the left child
		* right;    // pointer to the right child

	friend class exprtree;
};

//--------------------------------------------------------------------

class Exprtree
{
public:

	// constructor
	Exprtree();
	// destructor
	~Exprtree();

	// expression tree manipulation operations
	void build();              // build tree from prefix expression
	void expression() const;   // output expression in infix form
	float evaluate() const;    // evaluate expression
	void clear();              // clear tree

	// output the tree structure -- used in testing/debugging
	void showStructure() const;

	// in-lab operations
	void commute();                          // commute all subexpr

private:

	// recursive partners of the public member functions -- insert
	// prototypes of these functions here.
	void buildSub(ExprtreeNode*& p);
	void exprSub(ExprtreeNode* p) const;
	float evaluateSub(ExprtreeNode* p) const;
	void clearSub(ExprtreeNode* p);
	void showSub(ExprtreeNode* p, int level) const;

	// in-lab operations
	void commuteSub(ExprtreeNode*& p);

	// data member
	ExprtreeNode* root;   // pointer to the root node
};