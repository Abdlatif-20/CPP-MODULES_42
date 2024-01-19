













#include <iostream>
#include <string>


// class A
// {
// 	int a;
// 	std::string str;
// 	public:
// 		A(int a) {a = a;}
// 		~A() {}
// };

// int main()
// {
// 	// char *str = "Hello World!";
// 	char *str = "Hello World!";
// 	int a = (int)str;
// 	// int c = 100;
// 	// void *p = &a;
// 	std::cout << a << std::endl;
// 	return (0);
// }


#include <iostream>
using namespace std;
class Base 
{public:int a;};
class Derived : public Base 
{public:int b;};
 
// Driver code
int main()
{
	// Base b;
	// Derived d1;
   
  // // Implicit cast allowed
  // Base* b1 = (Base*)(&d1);
  // b = (Derived)d1;

  // b = static_cast<Derived>(d1);
  //  b.a = 10;
  // cout << b.a << endl;
  // // upcasting using static_cast
  // Base* b2 = static_cast<Base*>(&d1);


  // char c = 'a';

  // int *p = (int*)&c;

  // cout << *p << endl;


  // int *p2 = static_cast<int*>(&c);

  char c1 = 'a';

  // std::cout<<"size char *: "<<sizeof(c1)<<std::endl;
  // int *b = reinterpret_cast<int*>(&c1);
  // int *b2 = static_cast<int*>(c1);
  // int b3 = (int)c1;
  // int b4 = dynamic_cast<int>(c1);

   int a = 70; // ASCII value of F = 70
   int *int_pointer = &a;
   char* char_pointer = reinterpret_cast<char *>(int_pointer);
   cout<<*char_pointer<<endl;

  return 0;
}