#include <iostream>
using namespace std;

class BST
{
private:
    struct node
    {
        int data;
        node *left;
        node *right;
    };
    node *root;
    void addLeafPrivate(int key, node *Ptr)
    {
        if (root == nullptr)
        {
            root = createLeaf(key);
        }
        else if (key < Ptr->data)
        {
            if (Ptr->left != nullptr)
            {
                addLeafPrivate(key, Ptr->left);
            }
            else
            {
                Ptr->left = createLeaf(key);
            }
        }
        else if (key > Ptr->data)
        {
            if (Ptr->right != nullptr)
            {
                addLeafPrivate(key, Ptr->right);
            }
            else
            {
                Ptr->right = createLeaf(key);
            }
        }
        else
        {
            cout << endl
                 << key << " zaten düğüme eklenmiş!\n";
        }
    }
    void printInOrderPrivate(node *Root)
    {
        if (Root != nullptr)
        {
            if (Root->left != nullptr)
            {
                printInOrderPrivate(Root->left);
            }
            cout << Root->data << " ";
            if (Root->right != nullptr)
            {
                printInOrderPrivate(Root->right);
            }
        }
        else
        {
            cout << endl
                 << "Ağaca henüz veri eklenmemiş!\n";
        }
    }

public:
    BST()
    {
        root = nullptr;
    }
    void addLeaf(int key)
    {
        addLeafPrivate(key, root);
    }
    node *createLeaf(int key)
    {
        node *n = new node;
        n->data = key;
        n->left = nullptr;
        n->right = nullptr;
        cout << endl
             << key << " düğüme eklendi!\n";
        return n;
    }
    void printInOrder()
    {
        printInOrderPrivate(root);
    }
};

int main(int argc, char const *argv[])
{
    BST myTree;
    bool _bool = true;
    int secim, num;
    while (_bool)
    {
        cout << "\n1.\tEkle\n2.\tListele\n3.\tÇık\nSeçiminiz: ";
        cin >> secim;
        switch (secim)
        {
        case 1:
            cout << "Eklenecek Sayıyı Giriniz: ";
            cin >> num;
            myTree.addLeaf(num);
            break;
        case 2:
            myTree.printInOrder();
            break;
        case 3:
            _bool = false;
            break;
        default:
            cout << "\nHatali Seçim Yaptınız!\n";
            break;
        }
    }

    return 0;
}
