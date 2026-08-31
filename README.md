# CSF-debuglab
# Due: September 6 by 23:59:59



# TOP SECRET — EYES ONLY

## INTERNATIONAL COUNTER-EVIL AGENCY

### BEGIN: Intelligence Briefing

**CLASSIFICATION:** ULTRA SECRET  
**OPERATION:** DEBUG LAB  
**THREAT LEVEL:** ONE... MILLION

---

## Intercepted Intelligence

Agents of the **International Counter-Evil Agency (ICEA)** have successfully infiltrated the computer network of Dr. Evil's secret organization.

During the operation, our agents intercepted a collection of source files belonging to an experimental software project known internally as:

> **PROJECT: THE BOMB**

Intelligence indicates that Dr. Evil intends to use this software as part of yet another unnecessarily complicated scheme to **TAKE OVER THE WORLD**.

Fortunately, the intercepted files appear to contain only an early prototype of the system.

Unfortunately, we do not know how it works.

Our field agents are excellent at espionage, surveillance, disguises, high-speed chases, and escaping from elaborate death traps.

Reading C programs?

Not so much.

That is why this assignment has been given to **you**.

---

## Your Role

You have been recruited as a **technical analyst for ICEA**.

Your mission is to examine the intercepted source code and determine how to defeat Dr. Evil's prototype.

Intelligence analysis has revealed that the program contains **SEVEN PHASES**. Each phase requires a specific input to continue safely.

Somewhere in the source code are all of the clues necessary to determine those inputs.

You must carefully analyze the program, trace its execution, understand its data structures, and determine the correct input for every phase.

There is one important restriction.

Because this software was obtained through a highly classified intelligence operation, agency policy prohibits running it under a debugger.

**You must analyze the source code manually.**

- Read the code.
- Follow the variables.
- Trace the functions.
- Understand the logic.

Then determine the seven inputs required to defuse the prototype.

---

## A Warning from Intelligence

Our analysts have discovered references to a second project currently under development inside Dr. Evil's organization.

Details are limited.

We know only that it is considerably more sophisticated than the prototype you are examining today.

Dr. Evil's engineers appear to have learned from their mistakes.

**The source code will not be available.**

**The program will be harder to analyze.**

And intelligence reports repeatedly mention one ominous name:

# THE BOMB LAB

For now, concentrate on the intercepted prototype.

If you can defeat it, perhaps there is still hope when the real bomb appears.

---

## Your Mission

> **ANALYZE THE CODE.**  
> **FIND THE INPUTS.**  
> **DEFUSE THE PROTOTYPE.**  
> **STOP DR. EVIL.**

The fate of the world may depend upon your ability to read C.

**No pressure.**

### END: Intelligence Briefing



# Introduction
The purpose of this assignment is to improve ability to read C programs and improve your debugging skills.  This will be accomplished by running a program that prompts the user to enter a series of strings from the command line.  It is your task to figure out what the strings are.

# Logistics
1. This is an individual project.
2. There are many correct answers.  I expect to see many different correct answers.
3. All handins are electronic via git and GitHub.
4. Clarifications and corrections will be sent to the class via TCU email.
5. This project is worth 70 points (10 points for each phase).
6. You must do your work on `babbage.cs.tcu.edu`.
7. Your program will be tested on `babbage.cs.tcu.edu`.
8. When you have figured out each input string, enter it in a file named `psol.txt`.  Place each string on a separate line.


# Instructions
If you are reading this you have successfully cloned your repository.  Make sure your repository is on `babbage.cs.tcu.edu`.  Build your program by typing  `make`.  This will create an executable called `thebomb`.  

Please do not modify any of the C code.  You can add debugging statements to help you with this project, but they must be removed or commented out for your final submission.

# Source Code
Take a look at the file `thebomb.c`.  Again, do not modify this program.  This program contains 7 C functions (among other functions) that require you to enter input strings from the command line that will cause the function to exit normally and without calling the `explode()` function.  

# Instructions
Your task is to have this program run to completion without *"exploding"*.  This can be accomplished by entering strings from the command line that will *"defuse"* each phase.  When you enter the correct string, your program will prompt you to enter the next string or exit normally.  If you enter an incorrect string, the program will display an error message and exit.  You can press CTRL-c to abnormally exit the program at any time.  

Each time you determine the correct input string, store the string in a file named `psol.txt`, one per line.

# Evaluation
This is an individual assignment.  Do not share your answers with any of your classmates.  You may not use AI assistance for this assignment.  Period!  Doing so will be grounds for academic misconduct.  Your score will be computed out of a maximum of 70 points; 10 points for each phase solved.  

__Note: there are many correct answers__.  I will be expecting that every student will have a different solution.


# Handin Instructions
There is no program to turn in.  Copy your input strings into a text file named `psol.txt` and upload the file to your GitHub repo.  The program will be tested using the following command.
```text
prompt> ./thebomb < psol.txt
```

# Tips
1. Work on this project one phase at a time.
2. Carefully analyze the program.  Some phases can be solved by just reading the source code (not even running the program).
3. Use two terminals connected to `babbage.cs.tcu.edu`.  One terminal will be used to run and debug the program.  The other terminal will be used to edit the file `psol.txt`.
4. When you find a correct input string, store the string in the file `psol.txt`.  The next time you run the program you can copy-paste the string from the file into the other terminal where your program is running.  This helps prevent typos while re-entering the input strings each time you run the program.
5. When you solve each phase, be sure to save your work and update your git repo.  Be sure to `git add .`, `git commit -m "phase [1..7] complete"`, `git push`
   