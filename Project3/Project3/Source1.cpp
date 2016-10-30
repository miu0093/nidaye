# include < list >
# include < memory >
# include <iostream>
using namespace std;

int main() {

	int a;

	int* b;

	a = 100;

	b = new int;

	cout << "The pointer b points to the memory address " << b << " located on the heap\n";
	cout << "The value in memory location b is " << *b << "\n";

	*b = a;

	cout << "The value of stack variable a is " << a << "\n";
	cout << "The 'heap' memory pointed to by b contains " << *b << "\n";

	delete b;
	b = NULL;

	return 0;
}


 {
	std::list < std::shared_ptr <int > > intList;
	for (int i = 0; i < 100; i++) {
		intList.push_back(std::make_shared <int >(i));
	
	}
 }// no memory leaks ! struct A;
 struct B;
 struct C;
 
	 
	  struct A {
	  std::shared_ptr <B > bPtr;
	  std::shared_ptr <C > cPtr;
	  ~A() { std::cout << "A is deleted " << std::endl; }
	 
 };
 
	  struct B {
	  std::shared_ptr <A > aPtr;
	  ~B() { std::cout << "B is deleted " << std::endl; }
	 
 };
 
	  struct C {
	  std::weak_ptr <A > aptr;
	  ~C() { std::cout << "C is being deleted " << std::endl; }
	 
 };
 
	  int main(int argc, char * argv[]) {
	  {
		  std::shared_ptr <A > ap(new A);
		  std::shared_ptr <B > bp(new B);
		
		  ap - > bPtr = bp;
		  bp - > aPtr = ap;
		  }// objects should be destroyed but aren ’t
	 
		 {
		  std::shared_ptr <A > ap(new A);
		  std::shared_ptr <C > cp(new C);
		 
		  ap - > cPtr = cp;
		  cp - > aptr = ap;
		  }// weak pointer solve the problem
	  return 0;
	 }