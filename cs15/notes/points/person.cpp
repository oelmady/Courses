// Demonstrate using the heap.
// Includes functions that return pointers,
// structs that point to other structs,
// and calling delete.

#include <iostream>

using namespace std;

struct Person {
  string name;
  int age;
  Person* spouse;
};

Person* create_person(string name, int age);
void marry(Person* p1, Person* p2);
void print_people(Person* people[], int size);
void delete_people(Person* people[], int size);

const int NUM_PEOPLE = 3;

int main()
{
  // Create array of Person pointers on the heap.
  Person** people = new Person*[NUM_PEOPLE];

  // create some people, store them in array.
  people[0] = create_person("alice", 27);
  people[1] = create_person("bob", 30);
  people[2] = create_person("carol", 33);

  // Marry alice and carol.
  marry(people[0], people[2]);

  // Print list of people.
  print_people(people, NUM_PEOPLE);

  delete_people(people, NUM_PEOPLE);

  return 0;
}


/* Create a Person on the heap, return pointer.
 * Inputs: string name and int age of Person.
 * Output: pointer to heap-allocated Person.
 */
Person* create_person(string name, int age){
  // create new person
  Person* pperson = new Person;

  // initialize fields to given inputs.
  pperson->name = name;
  pperson->age = age;

  // set spouse pointer initially to NULL.
  pperson->spouse = NULL;

  return pperson;
}


/* Marries two people by having their
 * "spouse" fields point to one another.
 * Inputs: Person pointers p1 and p2 to marry.
 */
void marry(Person* p1, Person* p2)
{
  p1->spouse = p2;
  p2->spouse = p1;
}

void print_people(Person* people[], int size)
{
  for (int i = 0; i < size; i++) {
    cout << people[i]->name << " is " << people[i]->age << " years old." << endl;
    if (people[i]->spouse == NULL) {
      cout << people[i]->name << " is not married." << "." << endl;
    }
    else {
      cout << people[i]->name << " is married to " << people[i]->spouse->name << "." << endl;
    }
  }
}

void delete_people(Person* people[], int size)
{
  for (int i = 0; i < size; i++){
    // people[i] is just a memory address to a Person.
    // Calling delete on it will recycle that heap memory.
    delete people[i];
    people[i] = NULL;
  }
}
