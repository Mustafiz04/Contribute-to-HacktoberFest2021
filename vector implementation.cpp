#include <iostream>
using namespace std;
class vectorClass
{ 
//private members cannot be accessed by funcions outside the class;
private:
    int *arr;
    int capacity;
    int current;

public:
    //constructor;
    vectorClass()
    {
        arr = new int[1];
        capacity = 1;
        current = 0;
    }
    //for pushing new values even when the memory exceeds;
    void push(int data)
    {
        if (current == capacity)
        {
            int *temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
                temp[i] = arr[i];
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }
    //function overload when the length of array is sufficient;
    void push(int data, int index)
    {
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }
    //to get the values from a certain index;
    int get(int index)
    {
        if (index < current)
            return arr[index];
    }
//to delete one element from the end.
    void pop()
    {
        current--;
    }
    int size()
    {
        return current;
    }
    int getcapacity()
    {
        return capacity;
    }
    void print()
    {
        for (int i = 0; i < current; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
int main() 
{ 
    vectorClass v; 
    v.push(10); 
    v.push(20); 
    v.push(30); 
    v.push(40); 
    v.push(50); 

    cout << "Vector size : "<< v.size() << endl; 
    cout << "Vector capacity : "
        << v.getcapacity() << endl; 

    cout << "Vector elements : "; 
    v.print(); 

    v.push(100, 1); 

    cout << "\nAfter updating 1st index"
        << endl; 

    cout << "Vector elements : "; 
    v.print(); 

    cout << "Element at 1st index : "
        << v.get(1) << endl; 

    v.pop(); 

    cout << "\nAfter deleting last element"
        << endl; 
    cout << "Vector size : "
        << v.size() << endl; 
    cout << "Vector capacity : "
        << v.getcapacity() << endl; 
    cout << "Vector elements : "; 
    v.print();
    v.push(59);
    v.push(12);
    v.push(13);
    v.push(14);
    v.push(15);
    v.push(16);
    v.push(17);
    v.push(18);
    cout << "Vector capacity : " << v.getcapacity() << endl;
    cout << "Vector Elements : ";
    v.print();
    cout << v.size() << endl;
    return 0; 
} 