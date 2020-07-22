/*
    HW8A - Person.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and Banish deep ojha and Mounika.

*/


#include <iostream>
#include <string.h>
using namespace std;

class Person {
private:
    uint32_t len;
    char* name;
public:
    Person(const char n[]) : len(strlen(n)) {
        cout << "Person constructor\n";
        name = new char[len];
        memcpy(name, n, len);
    }
    Person(const Person& orig) : len(strlen(orig.name)){
        cout << "copying Person\n";
        name = new char[len];
        memcpy(name, orig.name, len);
    }
    ~Person() {
        cout << "Destructor\n";
        delete [] name;
    }
};

/*
	You can write your code here
 */
template<typename T>
class GrowArray{
private:
    T* data;
    uint32_t len;

public:
    GrowArray(uint32_t length) : len(length), data((T*)malloc(length*sizeof(T))){}
    ~GrowArray() { delete data; } // ok to delete nullptr

    void add(T obj){
           new(data+len) T(obj);
    }
};

int main() {
    GrowArray<Person> list(1000000); // should not call constructor for Person!
    list.add(Person("Test"));// Should call the constructor once and the copy once
}
