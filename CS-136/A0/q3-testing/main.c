//SEASHELL_READONLY

#include "add1.h"

// This is the "main" file.

// This exercise demonstrates the differences between running a program
// interactively [RUN (>)] and using the Seashell [I/O TEST] feature.

// (1) You should first click [SET AS (>) FILE] for this file (main.c)
//
// (2) To run this program *INTERACTIVELY*, click [RUN (>)].
//   (a) This program reads integers as INPUT.
//   (b) The OUTPUT is each integer (read from input) plus one. For example,
//       if you INPUT 41, it will OUTPUT 42.
//   (c) IMPORTANT! In *INTERACTIVE* mode, the console (typically on the right
//       half or at the bottom of your screen) displays *BOTH* input *AND*
//       output. In other words, it will "echo" or "re-display" your input
//       after you type your input and press [Enter].
//   (d) Try inputting more than one number at once by separating the numbers
//       with a space, for example: 1 2 3 4 5 6 [Enter]. This will "echo" all
//       of your input to the console, and then produce the output for each
//       input integer on a separate line
//   (e) To stop inputting, press CTRL + D, CMD + D, or press the [EOF] button
//       (EOF stands for End Of File, or in this case end of the input).
//   (f) If you wait too long to enter your input, it will "timeout" and stop
//       running your program.
//   (g) This program will also end if you enter any non-integer input, for
//       example, "hello".
//   (h) This *INTERACTIVE* mode is well suited to *informally* test your code.
//
// (2) The BETTER way to test your code is to use the [I/O TEST] feature of
//     Seashell.
//   (a) When you click on the [I/O TEST] button, it does not allow you
//       interactively type in input via the console. Instead, it reads the
//       INPUT from your .in file(s).
//   (b) Look at the contents of the simple.in file.
//   (c) When you click the [I/O TEST] button (go ahead -- do it now), it will
//       say that your test failed, but ignore that for now.
//   (d) Instead, let us look at the output it produced:
//       It produced output as if you had typed in the values from the
//       simple.in file directly into the console.
//   (e) Now, let us pass this test by modifying the simple.expect file to
//       contain the output we *expect* given the input contained in the
//       simple.in file. (We previously failed the test because simple.expect
//       was empty.) Our simple.in file has these four integers:
//         12345677
//         1336
//         -1
//         4069
//       So, our simple.expect file should have the following four integers:
//         12345678
//         1337
//         0
//         4070
//       IMPORTANT! Make sure you press [Enter] after the last number.
//       See the ASSIGNMENT RULES for more information on LINE FEEDS
//   (f) Now, click on [I/O TEST] to see if your simple.expect file is
//       correct: it should display that you passed the simple test.
//   (g) You can have more than one pair of .in and .expect files. In this
//       case, Seashell will run each test independently. This ability to
//       automate your input and output testing is a powerful feature of
//       Seashell, and mastering it will contribute to your success in this
//       course!
//
// Return to the instructions on the assignment

// This is the actual program, which you should ignore for now:

int main (void) {
  add1();
}
