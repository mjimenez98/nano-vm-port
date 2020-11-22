Task 0

Testing the aunit has been completed.

1) unit_tester.c //Demo program created to test the unit tester
2) unit_tester //Compiled code
3) unit_tester.txt //Output that has been redirected to a textfile that will be run against the aunit code.
4) aunit //The compiled code of the teachers unit tester. 

I have purposely made the Demo program return a wrong answer which is why running the aunit at the current state will return false.
I have also tested with the correct output and it works fine.

I had to make a slight change in the teacher aunit code (SOEN422_F2020 Project doc6 - AUnit_v1.0.9e.c) so it compiles. There was a return statment in the main function that had no return, I added the 0 at the end. 

