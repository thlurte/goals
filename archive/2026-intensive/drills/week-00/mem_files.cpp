#include <iostream>

int main() {

  size_t capacity = 1;
  int *val = static_cast<int *>(std::malloc(sizeof(int) * capacity));

  val[0] = 1500;
  val[1] = 51523;
  val[2] = 51554;
  val[3] = 5151;
  val[4] = 51232;
  std::cout << "value" << val[0] << std::endl;
  std::cout << "value" << val[1];
  std::cout << "value" << val[2];
  std::cout << "value" << val[3];
  std::cout << "value" << val[4];

  float *p = new float(5.0f);
  p[2] = 14;
  std::cout << std::endl << *p; // value dereferenced
  std::cout << std::endl << p;  // address
  std::cout << std::endl << &p; // stack address
  std::cout << std::endl
            << *(&p); // finding out where stack address points (its pointing to
                      // heap mem add)
  std::cout << std::endl
            << *(*(&p)); // dereferencing the heap mem add through stack address
  //

  float a = 5;
  std::cout << a << "  <<  " << *(&a);

  return 0;
}
