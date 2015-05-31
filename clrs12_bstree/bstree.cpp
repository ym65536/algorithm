#include <iostream>
#include <queue>

using namespace std;

const int NIL = -1;

struct TreeNode
{
    TreeNode(int key): left(NULL), right(NULL), parent(NULL), key(key) {};
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int key;
};

class Tree
{
public:
	Tree(): m_root(NULL) {};
	TreeNode* minimum(TreeNode* );
	TreeNode* maximum(TreeNode* );
	void creat(int keys[], int n);
	int insert(int key);
	int remove(int key);
	TreeNode* search(int key);
	void walk(TreeNode *root);
	TreeNode* get_root() const;

protected:
	inline TreeNode* node_creat(int key);
	void transplant(TreeNode* x, TreeNode *y);

private:
	TreeNode* m_root;
};

TreeNode* Tree::get_root() const
{
	return m_root;
}

TreeNode* Tree::minimum(TreeNode *root)
{
	TreeNode *visit = root;
    if (visit == NULL)
        return NULL;
    while (visit->left != NULL)
        visit = visit->left;
    return visit;
}

TreeNode* Tree::maximum(TreeNode* root)
{
	TreeNode *visit = root;
    if (visit == NULL)
        return NULL;
    while (visit->right != NULL)
        visit = visit->right;
    return visit;
}

inline TreeNode* Tree::node_creat(int key)
{
	return (key == NIL) ? NULL : new TreeNode(key);
};

void Tree::creat(int keys[], int n)
{
    if (n < 1)
        return;
    queue<TreeNode *> qtree;
    TreeNode* visit = NULL;
    int count = 1;
    
	m_root = new TreeNode(keys[0]);

    qtree.push(m_root);
    while (!qtree.empty())
    {
        visit = qtree.front();
        qtree.pop();
        
        // create left node
        if (count >= n) // creat all nodes
            break;
        visit->left = node_creat(keys[count++]);
        if (visit->left)
		{
			visit->left->parent = visit;
            qtree.push(visit->left);
		}
        // create right node
        if (count >= n) // creat all nodes
            break;
        visit->right = node_creat(keys[count++]);
        if (visit->right)
		{
			visit->right->parent = visit;
            qtree.push(visit->right);
		}
    }
}

int Tree::insert(int key)
{
	TreeNode* z = new TreeNode(key);
    TreeNode* x = m_root;
    TreeNode* y = NULL;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL) // tree is empty
        m_root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    
	return 0;
}

TreeNode* Tree::search(int key)
{
    TreeNode* visit = m_root;

    while (visit != NULL)
    {
        if (key == visit->key)
            return visit;
        if (key < visit->key)
            visit = visit->left;
        else
            visit = visit->right;
    }

    return visit;
} 

void Tree::walk(TreeNode *root)
{
    if (root == NULL)
        return;
    walk(root->left);
    cout << root->key << " ";
    walk(root->right);
}

// replace x by node y
void Tree::transplant(TreeNode* x, TreeNode *y)
{
	if (x->parent == NULL) // x is root
		m_root = y;
	else if (x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;

	if (y != NULL)
		y->parent = x->parent;
}

int Tree::remove(int key)
{
	TreeNode* y = NULL;
	TreeNode* z = search(key);
	if (z == NULL)
		return -1;

	if (z->left == NULL)
		transplant(z, z->right);
	else if (z->right == NULL)
		transplant(z, z->left);
	else
	{
		y = minimum(z->right);
		if (y->parent != z)
		{
			transplant(y, y->right); // replace y by right child
			// let y be parent of z->right
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}

	return 0;
}

int main(void)
{
    int keys[] = {12, 5, 18, 2, 9, 15, 19, NIL, NIL, NIL, NIL, NIL, 17};
    Tree T;
    TreeNode* visit = NULL;

    T.creat(keys, sizeof(keys)/sizeof(keys[0]));
    T.walk(T.get_root());
    cout << endl;

    visit = T.search(16);
    if (visit == NULL)
        cout << "FAIL: cannot find 16" << endl;
    else
        cout << "SUCC: find 16" << endl;

    T.insert(13);
    T.walk(T.get_root());
    cout << endl;
    
	visit = T.search(13);
    if (visit == NULL)
        cout << "FAIL: cannot find 13" << endl;
    else
        cout << "SUCC: find 13" << endl;

	T.remove(12);
    T.walk(T.get_root());
    cout << endl;

    return 0;
}

