2021/2022 Compilers Coursework
==============================

There is a single assessed code deliverable, which is due on Tuesday 29 March 2022 at 23:59. This deliverable contains two components:

- [*C-compiler*](c_compiler.md) (90%): a compiler from C to MIPS assembly. The source language is pre-processed C90. The target environment is Ubuntu 20.04, so the lab Ubuntu distribution, or equivalently an Ubuntu 20.04 VM as configured in the attached Vagrantfile.

- [time-tracking/project management component](management.md) (10%), which will be assessed orally at the start of Summer term.


Links
==========

Register structure: http://www.cs.uwm.edu/classes/cs315/Bacon/Lecture/HTML/ch05s03.html

Lexer and Parser Reference:

https://www.lysator.liu.se/c/ANSI-C-grammar-l.html

https://www.lysator.liu.se/c/ANSI-C-grammar-y.html


Goals/Deadlines
==========
25th Feb: Lexer [Charmaine] and Parser [Christina]

Hours Predicted: 3\3
Hours Taken: 3\3 (parser is later modified bit by bit therefore time difficult to estimate)

28th Feb: Completed Parser (Parser was split into statement, expression, declaration and specifier) [Both]

Hours Predicted: 0.5
Hours Taken: 3

8th Mar: Complete the base AST (ast_node)[Charmaine] and start ast_operators [Charmaine] and ast_function [Christina] (we chose these 2 as operators was easy to complete by using the standard MIPs instructions and we believe ast_functions was important because of int main(){})

Hours Predicted: 3
Hours Taken: 3

12th Mar: Complete ast_operator [Charmaine] (done on 11th Mar) and complete ast_functions (was not completed until later stages). On this day we had a meeting where we tried to complete the test_return testcase, this led us to complete the function start in ast_expressions instead of ast_functions

Hours Predicted: 6
Hours Taken: 6

16th Mar: Expand the parser to include param list [Christina] and change the ast_function [Charmaine] (as it was no longer used to start the code). Add to ast_statement [Christina] (was already written as we needed it for the return statement) Also write a bash script to test from the compiler_tests folder [Charmaine] (unable to complete on time as we needed help from TAs on friday)

Hours Predicted: 4
Hours Taken: 4

**At this point, we had a much better grasp on the project, therefore we would split testcases and try to complete them before each friday to make sure that we made the most of the assigned lab sessions.**

18th Mar: Complete integers [Charmaine] and start new AST (ast_declarator and ast_parameter) [Both], these were needed to start testing the functions folder. Also keep adding the ast_statement for if else and while statements [Christina]

Hours Predicted: 3
Hours Taken: 3

25th Mar: Keep doing array [Charmaine] (this was started in the middle of the week after completing the functions). Start switch statments and also break statements [Christina]

Hours Predicted: 3
Hours Taken: 3 encountered problem 

28th Mar: Complete switch statements and break [Christina] (we had a meeting because were having difficulty with switch but it was solved later that night) [Charmaine]

Hours Predicted: 3
Hours Taken: 6

31st Mar: Complete enums [Charmaine] (only able to complete one enum, was aware of issue with second one but was unsure of how to solve. The issue was the printing of the instructions before the function call, since the enum declaration is put before the int f(){})

Hours Predicted: 2
Hours Taken: 3

2nd Apr: Complete the compiler and hand in [Both] (even though we were planning to just give in the compiler on this day we suddenly figured out how to solve an issue we had with enums and also added that which helped us pass one more test before handing it in) [Charmaine]

Hours Predicted: 0.5
Hours Taken: 1



Milestones
==========
28th Feb - Lexer and first parser: Initially the lexer was difficult to verify and it was very difficult to start as we were unable to test whether our parser or lexer was correct.

11th Mar - Decided to change approach to problem from implementing parsing everything before codegen to making mini parser and make specific ASTs to pass base default case and build on the parser, while already building AST for operator and statements

13th Mar - Meeting with a TA which helped us find out what was incorrect (it was due to the parser). Passed first test case Default/test_return 

16th Mar - Passed all tests in Default folder

18th Mar - Passed all tests in Integer folder; wrote bash scripts for testing individual case, folder, and all the test folders 

19th Mar - Passed if else tests, reached 30 successful test cases

22nd Mar - Passed all sizeof tests in types folder 

23rd Mar - Passed all iterative loop (while and for) tests

25th Mar - Passed most of arrays

27th Mar - Solved git merge conflict, cleaned up and updated master branch

28th Mar - Expanded type to string and float, passed float cases

29th Mar - Passed misc/switch test cases and functions, reached 60 successful test cases

2nd Apr - Passed misc/enum test cases and cleaned up the code


Challenges
==========
1. Biggest Challenge was starting the lab, we were unsure where to start
2. Git merge: Gained valuable skills in working in a team when using GitHub
3. Vagrant was unstable for Christina's device which limited the ability to test and edit code efficiently
4. Using Stack Frame as we didn't have infinite registers like we did in the labs
5. Arrays were especially because we were unsure how the stack would work and it was difficult to be able to increment correctly
6. Ran out of time but next steps would have been pointers as that would open lots of doors for strings
7. When doing switch statements we had issues with our return statement, we were reluctant to change the statement as it was working very well for many other tests so we came up with a work around
8. Enums and how to stop printing the declarations before the function start statements


Design Decisions
==========
1. ast_expression was very important as many things called the Variable class
2. Use of enums in ast_node to set different "modes"
3. Seperating "x_list" and "x", was done by using an array of "x" type
4. Lots of MIPs comments to see which parts of the code was executing
5. Context contains not only bindings, but rather works as a package that stores information and controls about the current status of the program in terms of stack information etc. which can be passed down to the next functions/statements throughout the program. 
6. Using std::string to store types, was able to easily use this for typedef as well as operators (when completing floats and double)
7. Making 3 bash files (test a folder, test one test and test all)
8. Return statements were kept normal for all testcases except for switch and break, if switch then a jump instruction would be printed and the label would be the start of a return block placed at the very bottom the code. This return statement was added to the very end of the code gen in ast_node.
9. Bindings in ast_node was used to store the stack offset of the variable, very important for retrieving the value in the function.
 

Submission
==========

Submission will be via GitHub (code) and Teams (commit hash), as in the labs.

All submissions will be tested functionally -- there is no expectation for your compiler to *optimise* its input. Moreover, your compiler will only be tested on *valid* inputs, so you do not need to handle faulty inputs in a graceful way.
