#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <thread>
// a non-optimized way of checking for prime numbers:
bool is_prime (int x) {
  std::thread::id th = std::this_thread::get_id();
  std::cout << "The thread is " << th << std::endl;
  std::cout << "Calculating. Please, wait...\n";
  for (int i=2; i<x; ++i) if (x%i==0) return false;
  return true;
}

int main ()
{
//  std::thread t(is_prime, 2);
  std::thread::id th = std::this_thread::get_id();
  std::cout << "The thread is " << th << std::endl;
  // call is_prime(313222313) asynchronously:
  std::future<bool> fut = std::async (is_prime,313222313);

  std::cout << "Checking whether 313222313 is prime.\n";
  // ...

  bool ret = fut.get();      // waits for is_prime to return

  if (ret) std::cout << "It is prime!\n";
  else std::cout << "It is not prime.\n";

  return 0;
}
