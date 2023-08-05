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

    void updateVector(vector<int> new_vector){
            this->v=new_vector;
            sort(v.begin(), v.end());

    } 

    vector<int> returnVector(){
        return v;
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

};

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

};

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

void Union(int b,int c){
    if(database.size()<b){
        createAndPush(b);
    }
    if(database.size()<c){
        createAndPush(c);
    }

    vector<int> set1= database[b-1].returnVector();
    vector<int> set2= database[c-1].returnVector();

    for(int i=0;i<set2.size();i++){
        if(database[b-1].elementExist(set2[i])){

        }else{
            set1.push_back(set2[i]);
        }
        
    }

    database[b-1].updateVector(set1);
    



};

void Intersection(int b,int c){
    if(database.size()<b){
        createAndPush(b);
    }
    if(database.size()<c){
        createAndPush(c);
    }

    vector<int> set1= database[b-1].returnVector();
    vector<int> set2= database[c-1].returnVector();
    vector<int> intersectionSet;

    for(int i=0;i<set1.size();i++){
        for(int j=0;j<set2.size();j++){
            if(set1[i]==set2[j]){
                intersectionSet.push_back(set1[i]);
            }
        }
    }
    database[b-1].updateVector(intersectionSet);

};

vector<int> returnIntersection(int b,int c){
    if(database.size()<b){
        createAndPush(b);
    }
    if(database.size()<c){
        createAndPush(c);
    }

    vector<int> set1= database[b-1].returnVector();
    vector<int> set2= database[c-1].returnVector();
    vector<int> intersectionSet;

    for(int i=0;i<set1.size();i++){
        for(int j=0;j<set2.size();j++){
            if(set1[i]==set2[j]){
                intersectionSet.push_back(set1[i]);
            }
        }
    }

    return intersectionSet;
}

int Size(int b){
    if(database.size()<b){
        createAndPush(b);
    }

    return database[b-1].setSize();

};

void Difference(int b,int c){

    if(database.size()<b){
        createAndPush(b);
    }
    if(database.size()<c){
        createAndPush(c);
    }

    vector<int> intersection = returnIntersection(b,c);
    for(int i=0;i<intersection.size();i++){
        database[b-1].deleteElement(intersection[i]);
    }
    


};

int main(){

    Insert(1,2);
    Insert(1,5);
    Insert(1,3);
    Insert(1,0);
    // cout<< Size(1)<< endl;

    Insert(2,2);
    Insert(2,5);
    Insert(2,0);
    // cout<< Size(2)<< endl;

    
    Insert(3,6);
    Insert(3,9);
    // cout<< Size(3)<< endl;

    
    // Intersection(1,2);
    // cout<< Size(1)<< endl;
    // Intersection(2,3);
    // Intersection(4,3);

    
    Difference(1,2);
    Difference(2,3);
    Difference(3,4);


    database[0].printSet();
    database[1].printSet();
    database[2].printSet();
    database[3].printSet();

    
    
    





};
