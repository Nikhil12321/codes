class String{


    int s;
    int c;
    char *str;

    void resize(){


            if(c==0){
                c=1;
                str = new char[c];
            }
            else{
                c = 2*s;
                char *temp = new char[s];

                for(int i=0;str[i]!='\0';i++){

                    temp[i] = str[i];
                }
                delete[] str;
                
                str = new char[c];
                for(int i = 0;temp[i]!='\0';i++){

                    str[i] = temp[i];
                }
            }



        }

    public:

        String(){

            s = 0;
            c = 0;
            str = 0;
        }

        String(char *d){

            s = 0;
            for(int i=0;d[i]!='\0';i++)
                s++;

            c = s;
            str = new char[s];
            for(int i=0;d[i]!='\0';i++)
                str[i] = d[i];

        }

        char &operator[](int pos) const{


            if(pos>s)
                throw "invalid access";

            else{

                return str[pos];
            }
        }

        char at(int pos) const{


            if(pos>s)
                throw "invalid access";

            else{

                return str[pos];
            }
        }

        String &operator+=(const String &b){

            
            for(int i=0;b.str[i]!='\0';i++){

                push_back(b.str[i]);
            }
            return *this;
            
        }

        String &operator+=(const char ch){

            push_back(ch);
            return *this;
        }


        String &operator=(const String &b){

            
            s = b.s;
            c = b.c;

            delete str;

            str = new char[c];

            for(int i=0;b.str[i]!='\0';i++){
                str[i] = b.str[i];
            }

            return *this;
        }


        const String operator+(const String &b){

            String temp = *this;

            for(int i=0;b.str[i]!='\0';i++)
                temp.push_back(b.str[i]);

            return temp;
        }

        void insertAtK(int k, char ch){


            if(s==c)
                resize();

            for(int i=s;i<=k;i++){

                str[i+1] = str[i];

            }

            str[k] =ch;
        }



        void swap(String &b){


            String temp;

        }

        void clear(){

            delete[] str;
            s = 0;
            c = 0;

        }

        void push_back(char ch){


            if(s==c)
                resize();

            str[s++] = ch; 
        }

        void pop_back(){

            str[s] = '0';
            s--;
        }

        char *getString(){

            return str;
        }
    friend ostream &operator<<(ostream &, const String &);


};


ostream & operator<<(ostream & out, const String & b){

        for(int i=0;i<=b.s;i++){

            out<<b.str[i]<<" ";

        }
        return out;
    }