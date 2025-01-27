#include <iostream>

int main()
{

  // Coverage: 
  //    Object LifeTime
  //    C++ program lifeCycle
  //    NUll vs nullptr
  //    Insertion sort vs Bubble sort 
  //    Copy vs Assignment operator
  //    Computer Scientist of the week.




  // [Object LifeTime]    

  // List: 
  // 1. dynamic - must be deleted manually
  // 1. global
  // 2. static
  // 3. main 
  // 4. main2 - created most recent, after main
  // 5. in block or function

  // Destroyed from first to last
  // 1. in block or function
  // 2. main2
  // 3. main
  // 4. static
  // 5. global
  // 6. dynamic - will never get destroyed unless deleted manually.



  // [C++ program lifeCycle]

  // List:
  // 1. Source Code - your code
  // 2. Preprocessing - cleans up your code like remove comments ect
  // 3. Compiliation -  checks your code for syntax and compiles into the assemby
  // 4. Assembly - converts the compiled code into machine code
  // 5. Linking - links nessacesrry additional files and libraries.
  // 6. Loading - loads the machine code file into memory
  // 7. Execution - file is executed and is not in run time
  // 8. Termination - program terminates
  // 9. Post-Execution - end of program


  // Explanations:
  // 1. SOURCE CODE - the programmer writes the c++ cource code 
  
  // 2. PREPROCESSING - The prerpocessor processes the source code bore  
  //                    compiliation. This step includes: 
  //    a) Handingling the directives (like #include and #define)
  //    b) Expanding macros
  //    c) Removing comments  
  //    d) the result is a modified source code file, often referred to as the
  //       preprocessed source

  // 3. Compilation - The compiler translates the preprocessed source code into 
  //                  assembly code. This code is specific to the machine
  //                  architecture and is not yet machince code. The compiler checks
  //                  for syntax errors and may perform optimizations at this
  //                  stage.

  // 4. Assembly - The assember converts the assembly code into machine code, producing
  //               an object file with a .o or .obj extension. This file contains
  //               binary code but is not yet a complete program

  // 5. Linking - The linker combines one or more object files, along with any
  //              necessary libraries, into a single executable file. This step
  //              resolves references to external symbols and libraries

  // 6. Loading - The operating system loads the executable file into memory. This
  //              step prepares the program for execution by allocating memory
  //              for variables and stack.

  // 7. Execution - The cpu executes the program instructions. This invloves fetching 
  //                instructions from memory, decoding them, and executing them 
  //                sequentially or as dictaed by control flow(llops, condiitonals, ect)
  //                At this point the program is in runtime execution, processing 
  //                instruction, hanlding input/output, and performing computations 

  // 8. Termination - Once the program has completed its execution, it may return a 
  //                  value to the operating system (usally and integer). The OS then
  //                  cleans up resources allocated to the program.           


  // [Insertion sort vs Bubble sort] 
  // 1. Insertion is better beacuse it minizmizes swaps and shifts elemenets directly to the correct position
  // 2. Insertion sort has a best case of O(n) because if the list is partially sorted then the insertion sort will end once the list is sorted. Unlike, insertion sort bubble
  // sorts best case is O(n^2) because regardless of if the list is partially sorted the bubble sort will only end after completing all iterations
  // 3. 


  // [NUll vs nullptr]
  // nullptr is a specfic type used to indicate that a pointer is null, but Null has multiple meansings and types and can represent not only nullptr but also 0 in the case of ints..
  // So it is more better to use nullptr because it is clearer for its use and it wont cause issues if you pass it into functions.


  // [Copy vs Assignment operator]
  // Copy is invocted:
  // 1. MyObj o1 = o2;
  // 2. MyObj o1(o2);
  // 3. Pass my value
  // 4. Return by value

  // default = 1
  // copy = 3 
  // assignment = 1

  // [Computer Scientists of the week]

  // John Von Neumann - Invented merge sort
  //  • Innovations in Set theory, Geometry, Quantum Mechanics,
  //    Economics, Statistics
  //  • Founded Game Theory
  //  • Monte Carlo Method
  //  • EDVAC: data and program both in same address space
  //  • ENIAC: First computer to use a stored program
  //  • Von Neumann Architecture!
  //  • Manhattan Project
  //  • MAD: Mutually Assured Destruction
  //  • Merge Sort Algorithm

  // Grace Hopper - Invented first compiler
  // • Invented the first compiler
  // • United States Navy Rear Admiral
  // • Promoted the idea of machine independent languages
  // • Key inventor of COBOL
  // • Popularized the term debugging
  // • Advocated for Navy to move from centralized computers to
  //   distributed computers in the 1970s

  // Ada Lovelace - first programmer
  // • Aka, Augustus Ada Byron, aka Augustus Ada Lovelace, aka the Countess
  //   of Lovelace
  // • Daughter of the famous Poet, Lord Byron
  // • Partnered with Charles Babbage on Analytical Engine
  // • Devised / Imagined first computer program!
  // • Algorithm to be executed by the analytical machine
  // • Computer Bernoulli numbers
  // • First Computer programmer
  // • Also contributed to mathematics and phrenology

  // Alan Turing - father of ai
  // • Turing Machine
  // • Code Breaking in WWII for England 
  // • Broke German Enigma coding machine
  // • Winston Churchill: Turing made the single biggest
  //  contribution to Allied victory in the war against Nazi Germany
  // • Father of Artificial Intelligence
  // • Turing Test
  // • Chemical Basis of Morphogenesis -> mathematical biology ->
  //   how cat’s get their stripes.


  // Test 2
  
  // Charles Babbage - invented first mechanical computer
  // • Mathematician, Philosopher, Mechanical Engineer
  // • Invented the first mechanical computer
  // • Difference Engine: Computed values of polynomial functions
  // • If completed at the time would have had 25000 parts
  // • Finished in 1991
  // • Analytical Engine
  // • Punch card based
  // • Branching and looping supported
  // • Currently being built: 7Hz and 675 Bytes

  // Margaret Hamilton - first reliability engineer | apollo 8 space program | apollo 11 space program landing 
  // • Developed on-board flight software for Apollo space program
  // • Director of MIT Instruments Lab
  // • 2016: awarded Presidential Medal of Freedom
  // • First Site Reliability Engineer (SRE)
  // • Contributions to async software, priority scheduling and priority Display
  // • Foundations for ultra-reliable software design
  // • Apollo 8:
  // • P01 Key selection issue illustrates reliability thinking
  // • Apollo 11 Landing: design helped to successfully land ship amidst Overloading

  // Barbara Simons - Changed leagure of womens voter stance on electical voting to paper
  // • Focus: Scheduling and Compiler Optimizations
  // • IBM
  // • Past President of ACM 
  // • Premier critic of electronic voting
  // • Changed League of Women’s Voter stance on electronic voting
  // • Answer: Paper

  // Philip Agre - Computer Scientist / Philosopher predicted and warned against misuse of Internet
  // Computer Scientist / Philosopher predicted and warned against misuse of Internet
  // • Foresaw:
  // • Massive personal data collection tolerated by individuals as “‘not so bad’ simply for lacking the overt horrors of Orwell’s dystopia”
  // • Misuse of facial recognition by totalitarian states
  // • Susceptibility of people to be persuaded by AI-guided disinformation
  // • Stats:
  // • Childhood math prodigy
  // • 1989: MIT PhD
  // • Blogger/Wired Contributer
  // • UCLA CS Professor
  // • 2009: Dropped off face of planet and went off-the-grid completely. "I'm ok leave me alone."

  // Test3
  // Sir Charles Antony Richard Hoare “Tony” Hoare - Developed QuickSort | Invented the NULL Reference
  // Developed QuickSort
  // • Dining Philosopher’s problem
  // • ALGOL 60 
  // • 1980 Turing award
  // • Invented the NULL Reference

  // Robert Sedgewick - Determined the best gap for shell sort
  // • Studied under Donald Knuth, Professor at Princeton
  // • Much work in sorting:
  // • Thesis on Quick Sort
  // • Determining ideal Gap for Shell Sort
  // • Derived the red-black tree from the symmetric binary B-tree
  // • Wrote the series entitled, Algorithms
  // • You can take his courses on Coursera
  // • Algorithms Part I and Part II,
  // • Analysis of Algorithms
  // • Analytic Combinatorics

  // Aaron Swartz - key activist stopping SOPA and released millions of court documets from PACER
  // • Born in Chicago!
  // • Developed RSS as a teenager
  // • Developed Markdown: markup standard derived from HTML
  // • Early version of Reddit; joined Wired and quit
  // • Wrote Guerilla Open Access Manifesto
  // • Key activist in stopping SOPA (Stop Online Privacy Act)
  // • Legally released millions of court documents from PACER
  // • JSTOR controversy lead to overzealous prosecution
  // • For more info watch: “The Internet’s own Boy”

  // DONALD KNUTH - Father of Analysis of Algorithms
  // - Born in Milwaukee, WI 1938
  // - prof Emeritus at Stanford
  // - Father of Analysis of Algorithms
  // - Formalization of mathematical study of complexity of programs
  // - Wrote “Art of Computer Programming”
  // - Creator of TeX
  // - Won Grace Hopper Award, Turing Award, John von neumann Medal
  // - Opposed to granting computer patents

  /*
  GEORGE BOOLE - Founder of Boolean Algebra, the Algebra of logic
- English Mathematician, Philosopher and Logician
- Founder of Boolean Algebra, the Algebra of logic
- bool keyword named after him
- died by fever started by walking to class in rain to lecture

  BETTY SNYDER HOLBERTON - Created the breakpoint | Moore School of Engineering as Human Computer to determine Ballistic trajectories
- Moore School of Engineering as Human Computer to determine Ballistic trajectories
- one of the first programmers of the ENIAC
- Chief of programming research branch, applied math lab at the David Taylor Model Basin
- Helped develop UNIVAC with John Mauchly
- Created the breakpoint
- Worked with Grace Hopper on COLBOL and FORTRON
- Credited with making the computer beige
*/









  return 0;
}