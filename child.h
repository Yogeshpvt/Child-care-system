#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;

void line()
{
cout <<"__________________________________________________________________________________________________";
}
struct kid{
   string kname;
   char gender;
   long k_id;
   int age;
   long phone;
   string email;
};

struct splay
{
    int key;
    kid val;
    splay* left;
    splay* right;
};
 
class SplayTree
{
    public:
        SplayTree()
        {
        }
 
        splay* RR_Rotate(splay* k2)
        {
            splay* k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            return k1;
        }
 
        splay* LL_Rotate(splay* k2)
        {
            splay* k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            return k1;
        }
 
        splay* Splay(int key, splay* root)
        {  
            if (root == NULL || root->key == key)  
                return root;  
       
             
            if (root->key > key)
            {  
               
                if (root->left == NULL) return root;
       
               
                if (root->left->key > key)  
                {  
                   
                    root->left->left = Splay(key , root->left->left);  
       
                    root = RR_Rotate(root);  
                }  
                else if (root->left->key < key)
                {  
 
                    root->left->right = Splay(key , root->left->right);  
       
                    if (root->left->right != NULL)  
                        root->left = LL_Rotate(root->left);  
                }  
       
                return (root->left == NULL)? root: RR_Rotate(root);  
            }  
            else  
            {  
                if (root->right == NULL) return root;  
       
                if (root->right->key > key)  
                {  
                    root->right->left = Splay(key , root->right->left);  
       
                    if (root->right->left != NULL)  
                        root->right = RR_Rotate(root->right);  
                }  
                else if (root->right->key < key)
                {  
                    root->right->right = Splay(key , root->right->right);  
                    root = LL_Rotate(root);  
                }  
       
                return (root->right == NULL)? root: LL_Rotate(root);  
            }  
        }
 
        splay* New_Node(int key,kid h)
        {
            splay* p_node = new splay;
            if (!p_node)
            {
                fprintf(stderr, "ERROR!\n");
                exit(1);
            }
            p_node->key = key;
            p_node->val.kname = h.kname;
            p_node->val.age = h.age;
            p_node->val.phone = h.phone;
            p_node->val.email = h.email;
            p_node->val.gender = h.gender;
            p_node->val.k_id = h.k_id;
            p_node->left = p_node->right = NULL;
            return p_node;
        }
 
        splay* Insert(int key,kid h, splay* root)
        {
            static splay* p_node = NULL;
            if (!p_node)
                p_node = New_Node(key,h);
            else
                p_node->key = key;
            if (!root)
            {
                root = p_node;
                p_node = NULL;
                return root;
            }
            root = Splay(key, root);
            if (key < root->key)
            {
                p_node->left = root->left;
                p_node->right = root;
                root->left = NULL;
                root = p_node;
            }
            else if (key > root->key)
            {
                p_node->right = root->right;
                p_node->left = root;
                root->right = NULL;
                root = p_node;
            }
            else
                return root;
            p_node = NULL;
            return root;
        }
 
        splay* Delete(int key, splay* root)
        {
            splay* temp;
            if (!root)
                return NULL;
            root = Splay(key, root);
            if (key != root->key){
                cout<<"\n"<<key<<" IS NOT IN THE TREE";
                return root;
            }
            else
            {
                if (!root->left)
                {
                    temp = root;
                    root = root->right;
                }
                else
                {
                    temp = root;
                    root = Splay(key, root->left);
                    root->right = temp->right;
                }
                free(temp);
                return root;
            }
        }
 
        splay* Search(int key, splay* root)
        {
            return Splay(key, root);
        }

        void InOrder(splay* root)
        {  
            if (root)
            {
                InOrder(root->left);
                if(root->left)
                    cout<< " - LEFT CHILD : "<< root->left->key<<"\n";
                if(root->right)
                    cout<< " - RIGHT CHILD : " << root->right->key<<"\n";
                cout<< "\n";
                InOrder(root->right);
            }
        }
        void PreOrder(splay *root){
            if(root){
                cout<<setw(15)<<root->key<<setw(15)<<root->val.kname<<setw(15)<<root->val.phone<<setw(30)<<root->val.email<<setw(15)<<root->val.gender;
                cout<<"\n";
                PreOrder(root->left);
                PreOrder(root->right);
            }
        }
};
