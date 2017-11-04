#include <iostream>
#include "HashObject.cpp"
using namespace std;

int main() {

    HashTable myHashTable;
    myHashTable.add("asif",15);
    myHashTable.add("orxan",25);
    myHashTable.add("ceyhun",35);
    myHashTable.add("zaur",45);
    myHashTable.add("zaur",75);
    myHashTable.display();

    cout<<myHashTable.exists("ceyhun")<<endl;
    cout<<myHashTable.get("ceyhun")<<endl;

    myHashTable.remove("ceyhun");
    myHashTable.display();
    return 0;
}