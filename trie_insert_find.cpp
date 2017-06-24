#include<iostream>
#include<string>

using namespace std;

struct trienode{

    bool is_word;
    trienode * alphabet[26];

    trienode(){

        is_word = false;
        for(int i=0; i<26; i++)
            alphabet[i] = NULL;
    }
};


int to_int(char c){

    return int(c)-int('a');
}
void insert(trienode * root, string word){


    int i=0; 
    while(i < word.size() && root->alphabet[to_int(word[i])] != NULL){

        i++;
        root = root->alphabet[to_int(word[i])];
    }

    if(i == word.size() && root->is_word)
        return;
    else if(i == word.size() && !root->is_word){
        root->is_word = true;
        return;
    }
    else{

        while(i < word.size()){

            trienode * tmp = new trienode();
            root->alphabet[to_int(word[i])] = tmp;
            root = root->alphabet[to_int(word[i])];
            i++;
        }
        root->is_word = true;
    }
}

bool find(trienode * root, string word){


    int i=0;
    while(i < word.size() && root->alphabet[to_int(word[i])] != NULL){
        root = root->alphabet[to_int(word[i])];
        i++;
        
    }
    if(i == word.size() && root->is_word)
        return true;
    return false;
}

int main(){


    trienode * root = new trienode();
    insert(root, "nikhil");
    insert(root, "bhatia");
    cout<<find(root, "ni");
}

