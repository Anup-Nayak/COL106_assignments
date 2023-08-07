#include <iostream>
#include <vector>

using namespace std;

//class defined

class SET{ 
    public:
    int number;
    vector<int> v;

    SET(){}

    SET(int setNumber){
        this->number = setNumber;
        // cout<<"constructor called and set "<<setNumber<<" is created."<<endl;
    }

    int setSize(){
        return v.size();
    }

    void Sort(){
        for (int i = 0; i < v.size(); i++) {
            for (int j = i; j < (v.size()); j++) {
                if (v[i] > v[j]) {
                    swap(v[i], v[j]);
                }
            }
        }
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
        Sort();
        if (v.size()==0){
            cout<<endl;
        }else{
            int i=0;
            while (i<v.size()-1){
                cout<<v[i]<<",";
                i+=1;
            }
            cout<<v[i];
            cout<<endl;
    }
        }
        

    void insertSet(int c){
        if (elementExist(c)==false){
            this->v.push_back(c);
            Sort();
        }
        
        
    }

    void deleteElement(int c){
        int i=0;
        vector<int>::iterator it;
        while(i<v.size()){
            if (v[i]==c){
                break;
            }else{
                i+=1;
            }
        

        }
        it=v.begin();
        v.erase(it+i);
        
        Sort();



}

    void updateVector(vector<int> new_vector){
            this->v=new_vector;
            Sort();
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
    if(database.size()<b+1){
        createAndPush(b);
    }

    database[b].insertSet(c);
    cout<<database[b].setSize()<< endl;

};

void Delete(int b,int c){
    if(database.size()<b+1){
        cout<< -1<< endl;
    }else{
        if(database[b].elementExist(c)==false){
            cout<< database[b].setSize()<< endl;
        }else{
            database[b].deleteElement(c);
            cout<< database[b].setSize()<< endl;
        }
    }

};

void BelongsTo(int b, int c){
    if(database.size()<b+1){
        cout<< -1<< endl;
    }else{
        if(database[b].elementExist(c)==true){
            cout<< 1<< endl;
        }else{
            
            cout<< 0<< endl;
        }
    }
};

void Union(int b,int c){
    if(database.size()<b+1){
        createAndPush(b);
    }
    if(database.size()<c+1){
        createAndPush(c);
    }

    vector<int> set1= database[b].returnVector();
    vector<int> set2= database[c].returnVector();

    for(int i=0;i<set2.size();i++){
        if(database[b].elementExist(set2[i])){

        }else{
            set1.push_back(set2[i]);
        }
        
    }

    database[b].updateVector(set1);
    cout<< database[b].setSize()<< endl;
    



};

vector<int> returnUnion(int b,int c){
    if(database.size()<b+1){
        createAndPush(b);
    }
    if(database.size()<c+1){
        createAndPush(c);
    }

    vector<int> set1= database[b].returnVector();
    vector<int> set2= database[c].returnVector();

    for(int i=0;i<set2.size();i++){
        if(database[b].elementExist(set2[i])){

        }else{
            set1.push_back(set2[i]);
        }
        
    }

    return set1;
}

void Intersection(int b,int c){
    if(database.size()<b+1){
        createAndPush(b);
    }
    if(database.size()<c+1){
        createAndPush(c);
    }

    vector<int> set1= database[b].returnVector();
    vector<int> set2= database[c].returnVector();
    vector<int> intersectionSet;

    for(int i=0;i<set1.size();i++){
        for(int j=0;j<set2.size();j++){
            if(set1[i]==set2[j]){
                intersectionSet.push_back(set1[i]);
            }
        }
    }
    database[b].updateVector(intersectionSet);
    cout<< database[b].setSize()<< endl;

};

vector<int> returnIntersection(int b,int c){
    if(database.size()<b+1){
        createAndPush(b);
    }
    if(database.size()<c+1){
        createAndPush(c);
    }

    vector<int> set1= database[b].returnVector();
    vector<int> set2= database[c].returnVector();
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

void Size(int b){
    if(database.size()<b+1){
        createAndPush(b);
    }

    cout<< database[b].setSize()<< endl;

};

void Difference(int b,int c){

    if(database.size()<b+1){
        createAndPush(b);
    }
    if(database.size()<c+1){
        createAndPush(c);
    }

    vector<int> intersection = returnIntersection(b,c);
    for(int i=0;i<intersection.size();i++){
        database[b].deleteElement(intersection[i]);
    }
    cout<< database[b].setSize()<< endl;



};

void SymmetricDifference(int b,int c){

    if(database.size()<b+1){
        createAndPush(b);
    }
    if(database.size()<c+1){
        createAndPush(c);
    }

    vector<int> intersection= returnIntersection(b,c);

    vector<int> set1= database[b].returnVector();
    vector<int> set2= database[c].returnVector();

    for(int i=0;i<set2.size();i++){
        if(database[b].elementExist(set2[i])){

        }else{
            set1.push_back(set2[i]);
        }
        
    }

    database[b].updateVector(set1);
    
    for(int i=0;i<intersection.size();i++){
        // Delete(b,intersection[i]);
        database[b].deleteElement(intersection[i]);

    }
    cout<< database[b].setSize()<< endl;

};   

void Print(int b){
    if(database.size()<b+1){
        cout<<endl;
    }else{
        database[b].printSet();
    }
};

int main(){
    int a,b,c;
    // int temp;

    // vector<int> v;
    // while(cin>>temp){
    //     v.push_back(temp);
    // }

    while(cin>>a){
        if(a==6 || a==9) cin>>b;
        else cin>>b>>c;
        
        
        switch (a)
        {
        case 1:
            Insert(b,c);
            break;
        case 2:
            Delete(b,c);
            break;
        case 3:
            BelongsTo(b,c);
            break;
        case 4:
            Union(b,c);
            break;
        case 5:
            Intersection(b,c);
            break;
        case 6:
            Size(b);
            break;
        case 7:
            Difference(b,c);
            break;
        case 8:
            SymmetricDifference(b,c);
            break;
        case 9:
            Print(b);
            break;
        
        default:
            break;
        }
    }

    // Insert(0,2);
    // Insert(0,5);
    // Insert(0,3);
    // Insert(0,0);
    // Insert(0,45);
    // Print(0);
    // database[0].printSet();

    // Delete(0,45);
    // database[0].printSet();
    // Delete(0,3);
    // database[0].printSet();


    // Insert(1,2);
    // Insert(1,5);
    // Insert(1,8);
    // Print(1);
    // cout<< Size(1)<< endl;

    
    // Insert(2,33);
    // Insert(2,9);
    // Insert(2,9);
    // Print(2);
    // cout<< Size(2)<< endl;

    
    // Intersection(0,1);
    // cout<< Size(0)<< endl;
    // Intersection(1,2);
    // Intersection(2,3);

    
    // SymmetricDifference(0,1);
    // SymmetricDifference(1,2);
    // SymmetricDifference(2,3);

    // cout<< Size(1)<< endl;
    // Print(0);
    // Print(1);
    // Print(2);
    // Print(3);
    


};
