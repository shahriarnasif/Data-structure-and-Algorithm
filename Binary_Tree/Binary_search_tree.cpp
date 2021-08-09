#include<bits/stdc++.h>
using namespace std;

class binary_search_tree
{
private:
    struct Node
{
    int val;
    Node *left;
    Node *right;
};
Node *root;
 Node* delete_all(Node* t)
 {
        if(t == NULL)
            return NULL;
        {
            delete_all(t->left);
            delete_all(t->right);
            delete t;
        }
        return NULL;
    }
void insert_node(int x)
{
    Node* temp = root;
    Node* r=new Node;
    r->val =x;
    r->left=NULL;
    r->right=NULL;

    if(temp==NULL)
    {

        root =r;
        return;
    }
    else
    {
        Node* previous;
        while(temp!=NULL)
        {
            if(temp->val>x)
            {
                previous=temp;
                temp=temp->left;

            }
            else
            {
                previous=temp;
                temp=temp->right;

            }
        }
        temp=r;

        if(previous->val<temp->val)
            previous->right=temp;
        else
            previous->left=temp;


    }

}
Node* Sucessor(Node* node)
{
Node* temp=node;
if(temp->right!=NULL)
{
    temp=temp->right;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
}
Node* remove_node(int x,Node* temp)
{
if(temp==NULL)
    return NULL;
else if(temp->val>x) temp->left=remove_node(x,temp->left);
else if(temp->val<x) temp->right=remove_node(x,temp->right);
else
{
if (temp->left==NULL and temp->right==NULL)
            return NULL;
 else if(temp->left==NULL)
{
     Node* t = temp;

     temp=temp->right;

     delete(t);
     cout<<temp->val<<"temp"<<endl;
     return temp;
}
else if(temp->right==NULL)
{

     Node* t = temp;
     temp=temp->left;
     delete(t);
       cout<<temp->val<<"temp"<<endl;
     return temp;
}
else
{
Node* s=Sucessor(temp);
temp->val=s->val;
temp->right = remove_node(temp->val,temp->right);



}




}
}
void inorder(Node* temp)
{
    if(temp==NULL)
        return;
    inorder(temp->left);
    cout<<temp->val<<" ";
    inorder(temp->right);
}
bool find(int x,Node* temp)
{
   if(temp==NULL)
   {
       return false;
   }
   else if(temp->val>x)
   {
       find(x,temp->left);
   }
   else if(temp->val<x)
   {
       find(x,temp->right);
   }
   else
   {
       return true;
   }
}
int left_tree(Node* node)
{
    if(node==NULL)
        return -1;
    else if(node->left==NULL)
          return node->val;
    else
    left_tree(node->left);
}
int right_tree(Node* node)
{
    if(node==NULL)
        return -1;
    else if(node->right==NULL)
          return node->val;
    else
    right_tree(node->right);
}
int level(Node* node)
{
    if(node==NULL)
        return 0;
    else{
    int left = level(node->left);
    int right =level(node->right);
    return max(left,right)+1;
    }
}
public:
    binary_search_tree()
    {
        root = NULL;

    }
    ~binary_search_tree()
    {

        delete_all(root);
    }
    void insert(int x)
    {
        insert_node(x);

    }
    void remove(int x)
    {
       remove_node(x,root);
        //cout<<root->right->val<<"root"<<endl;

    }
    void display()
    {
        inorder(root);
        cout<<endl;
    }
    void search(int x)
    {
        cout<<find(x,root)<<endl;

    }
     void mini()
     {
        cout<<left_tree(root)<<endl;

     }
    void maxi()
     {
         cout<<right_tree(root)<<endl;
     }
     void height()
     {
         cout<<level(root)<<endl;

     }
     void levelorder_Print()
     {
         if(root==NULL)
            return;
         queue<Node*>q;
         q.push(root);
         while(!q.empty())
         {
             int c =q.size();


             while(c>0)
             {
                  Node* curr =q.front();
                  cout<<curr->val<<" ";
                  q.pop();
                  if(curr->left!=NULL){

                    q.push(curr->left);

                  }
                  if(curr->right!=NULL){
                    q.push(curr->right);

                  }
                   c--;

             }
             cout<<endl;

         }


     }


};
int main()
{
binary_search_tree t;
t.remove(20);
     t.insert(20);
     t.insert(25);
     t.insert(10);
     t.insert(40);
     t.insert(12);

     t.display();
     t.levelorder_Print();
    cout<<"height"<<" ";
     t.height();
     t.maxi();
     t.mini();
     t.search(20);

     //t.remove(20);

    t.levelorder_Print();


}
