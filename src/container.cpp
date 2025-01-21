#include "container.hpp"

using namespace std;

int main(){
// Seq Cont begin
//1
    SeqCont<int> test{};
//2
    cout << "Make Seq Contaner" << endl;   
    for(int i = 0; i < 10; i++){
        test.push_back(i);
    }
//3  
    test.printall();
//4
    cout << "Size of Cont: "<< test.size() << endl;
//5
    cout << "Remove N 3,5,7 elements: " << endl;
    test.erase(3);
    test.erase(4);
    test.erase(5);
//6
    test.printall();
//7
    cout << "Add 10 in begin: " << endl;
    test.insert(10,1);
//8
    test.printall();
//9
    cout << "Add 20 in middle : " << endl;
    test.insert(20,5);
//10
    test.printall();
//11
    cout << "Add 30 in end : " << endl;
    test.push_back(30);
//12
    test.printall();    


//?operator[]
    cout << "Return by id 5: ";
    cout << test[5] << endl;

//update value
    cout << "Update id 5 to 100: " << endl;
    test.update(100,5);
    test.printall();

    cout << "End of Seq Container\n\n\n" << endl;
//seq cont end

// List Cont begin
//1
    ListCont<int> test2{};
//2
    cout << "Make List Contaner" << endl;
    for(int i = 0; i < 10; i++){
        test2.push_back(i);
    }
//3
    test2.printall(); 
//4
    cout << "Size of Cont: "<< test2.size() << endl;
//5
    cout << "Remove N 3,5,7 elements: " << endl;
    test2.erase(3);
    test2.erase(4);
    test2.erase(5);
//6
    test2.printall();

//7
    cout << "Add 10 in begin: " << endl;
    test2.insert(10,1);
//8
    test2.printall();
//9
    cout << "Add 20 in middle : " << endl;
    test2.insert(20,5);
//10
    test2.printall();
//11
    cout << "Add 30 in end : " << endl;
    test2.push_back(30);
//12
    test2.printall();

//?operator[]
    cout << "Return by id 5: ";
    cout << test2[5] << endl;

//update value
    cout << "Update id 5 to 100: " << endl;
    test2.update(100,5);
    test2.printall();

    cout << "End of List Container\n\n\n" << endl;
//List cont end
}