#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//class defined

class SET{
    public:
    int number;
    vector<int> v;

    SET(){}

    SET(int setNumber){
        this->number = setNumber;
        cout<<"constructor called and set "<<setNumber<<" is created."<<endl;
    }

    int setSize(){
        return v.size();
    }

    bool elementExist(int c){
        for(int i=0;i<v.size();i++){
            if (v[i]==c){
                return true;
            }
        }
        return false;
    }

    void printSet(){
        for(int i=0;i<v.size();i++){
            cout<< v[i]<<" ";
        }
        cout<<endl;
    }

    void insertSet(int c){
        if (elementExist(c)==false){
            this->v.push_back(c);
            sort(v.begin(), v.end());
        }
        
        
    }
    

    void deleteElement(int c){
        for(int i=0;i<v.size();i++){
            if (v[i]==c){
                v[i]=v[-1];
            }

        }
        v.pop_back();
        sort(v.begin(), v.end());

    }
};

// class ends

// database initialized

vector<SET> database;

// helper functions

void createAndPush(int n){
    
    SET a(n);
    database.push_back(a);
};


// functions

void Insert(int b,int c){
    if(database.size()<b){
        createAndPush(b);
    }

    database[b-1].insertSet(c);

}

int Delete(int b,int c){
    if(database.size()<b){
        return -1;
    }else{
        if(database[b-1].elementExist(c)==false){
            return database[b-1].setSize();
        }else{
            database[b-1].deleteElement(c);
            return 0;
        }
    }

}


int BelongsTo(int b, int c){
    if(database.size()<b){
        return -1;
    }else{
        if(database[b-1].elementExist(c)==true){
            return 1;
        }else{
            
            return 0;
        }
    }
};




int main(){

    Insert(1,2);
    Insert(1,5);
    Insert(1,3);

    Insert(2,2);
    Insert(2,5);

    Insert(3,3);

    int a=Delete(1,5);
    int b=Delete(2,1);
    int c=Delete(3,3);
    int d=Delete(4,5);

    database[0].printSet();
    database[1].printSet();
    database[2].printSet();

    int e=BelongsTo(1,3);
    int f=BelongsTo(3,3);
    int g=BelongsTo(4,3);
    
    cout << e <<" " << f << " "<< g << endl;





};
