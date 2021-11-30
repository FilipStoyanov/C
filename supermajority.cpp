#include <iostream>
using namespace std;
unsigned find_majority(unsigned n)
{
      unsigned supermajority;
      unsigned number;
      unsigned counter{0};
      for (unsigned i{0}; i < n; ++i)
      {
            std::cin >> number;
            if (counter == 0)
            {
                  supermajority = number;
                  ++counter;
            }
            else
            {
                  supermajority == number ? ++counter : --counter;
            }
      }
       return supermajority;
}
int main()
{
      unsigned n;
      std::cin >> n;
      std::cout << find_majority(n) << std::endl;
      return 0;
}
