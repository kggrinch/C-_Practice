#include <iostream>

int max_leaves(int h, int b)
{
  if(h <= 0 || b <= 0)
  {
    return 0;
  }
  else if(h == 1)
  {
    return 1;
  }
  else
  {
   return b * max_leaves(h - 1, b);
  }
}



// Factorial
// int factorial(int x)
// {
// 	if(x < 0)
// 	{
// 		return -1;
// }	
// if( x == 1 || x == 0)
// {
// 	return 1;
// }
// return x * factorial(x - 1);	
// }


int factorial(int n)
{
  if(n <= 1)
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1);
  }
}



int fib(int x)
{
	if(x <= 0)
	{
		return 0;
	}
	if(x <= 2)
	{
		return 1;
	}
	return fib(x - 2) + fib(x - 1);
}


int catalan(int n)
{
  if(n <= 1)
  {
    return 1;
  }

  int temp = 0;
  for(int i = 0; i < n; i++)
  {
    temp += catalan(i) * catalan(n-i-1);
  }
  return temp;
}


void towerOfHanoi(int disk, char source, char target, char extra)
{
  if(disk == 1)
  {
    std::cout << "Move disk 1 from " << source << " to " << target << "\n";
    return;
  }

  towerOfHanoi(disk - 1, source, extra, target);

  std::cout << "Move disk " << disk << " from " << source << " to " << target << "\n";

  towerOfHanoi(disk - 1, extra, target, source);
}

int kOutOfN(int n, int k)
{
  if(n == 0)
  {
    return 0;
  }
  if(n < k)
  {
    return 0;
  }
  if(n == k)
  {
    return 1;
  }
  if(k == 1)
  {
    return n;
  }
  
  return kOutOfN(n-1, k-1) + kOutOfN(n-1, k);
}

int gcd(int v1, int v2)
{

  if(v2 == 0)
  {
    return v1;
  }

   return gcd(v2, v1 % v2);
}





int main()
{

  // Recursion types:
  // 1. returns value
  // 2. Performs an action (ex: adds to string)
  // 3. Divides in half recursively (binary search)
  // 4. Tail Recursion
  // 5. Backtracking

  // Recursive applications
  // 1. Discreate methemcatics (combinatorics, puzzles, codeing theory) - ex: Tower of Hanoi and Gray Code
  // 2. Divide and Conque - Mergesort, Convet Hall, and Fast Fourirer Transform
  // 3. Backtrack - 8 queens, Maze and classic chess program
  // 4. Fractal Figures - Koch, Sierpinski Allowhead, Gosper, Hilbert, and Dragon curves

  // Practice Problems:
  // 1. Choosing k out of n



  // std::cout << "Input height: ";
  // int height;
  // std::cin >> height;

  // std::cout << "Input branches: ";
  // int branches;
  // std::cin >> branches;

  std::cout << "max_leavs: " << max_leaves(2, 2) << "\n";
  std::cout << "factorial: " <<factorial(3) << "\n";
  std::cout << "fibonicc: " << fib(2) << "\n";
  std::cout << "catalan: " << catalan(3) << "\n";
  towerOfHanoi(4, 'A', 'B', 'C');
  std::cout << "kOutOfN: " << kOutOfN(0, 5) << "\n";
  std::cout << "gcd: " << gcd(3, 9);

  return 0;
}

// passing arguments to main through a file.

// int main(int argc, char* argv[]) // first argument is the console which you are running from the drive.
// {
      // std::cout << argc << "\n";
      // for(int i = 0; i < argc; i++)
      // {
      //   std::cout << argv[i] << "\n";
      // }

// first argument is the console which you are running from the drive.
// When running in linux you must run a txt file instead of bat file and change the mode: chmod + x to make a shell executable.

//   // std::cout << "Input height: ";
//   // int height;
//   // std::cin >> height;

//   // std::cout << "Input branches: ";
//   // int branches;
//   // std::cin >> branches;

//   std::cout << max_leaves(2, 2) << "\n";
//   std::cout << factorial(3) << "\n";
//   std::cout << fibonoicc(2) << "\n";

//   return 0;
// }