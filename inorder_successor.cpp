BinaryTreeNode * inorder_successor(BinaryTreeNode * ptr,  BinaryTreeNode * parent){

    if(!ptr->left && !ptr->right){


        if(parent == NULL)
            return ptr;

        else{

            parent->next = ptr;
            return ptr;
        }


        if(ptr->left){

            BinaryTreeNode * d = inorder_successor(ptr->left, parent);
            d->next = ptr;
        }

        if(ptr->right){

            BinaryTreeNode * e = inorder_successor(ptr->right, ptr);
            return e;
        }

        return ptr;
    }



}



int main(){



    root = inorder_successor(root, NULL);
}