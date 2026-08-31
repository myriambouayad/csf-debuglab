//=======================================
// PUT YOUR NAME HERE
// Debug Lab
// Computer System Fundamentals
// Due September 6, 2026 by 23:59:59
//=======================================


/*
 * ============================================================================
 *                     DR. EVIL'S DEBUG LAB
 * ============================================================================
 *
 * CLASSIFIED DOCUMENT
 *
 *              EVIL ORGANIZATION -- RESEARCH & DEVELOPMENT DIVISION
 *
 * WARNING:
 * Unauthorized access to this source code may result in sharks, lasers,
 * sharks with lasers, or other unnecessarily elaborate consequences.
 *
 * ----------------------------------------------------------------------------
 * BACKGROUND
 * ----------------------------------------------------------------------------
 *
 * Once again, Dr. Evil has devised a brilliant plan to TAKE OVER THE WORLD.
 *
 * Unfortunately, there is a small problem.
 *
 * His software doesn't work.
 *
 * After several unfortunate incidents involving malfunctioning satellites,
 * incorrectly targeted lasers, and one particularly embarrassing attempt to
 * hold Luxembourg for ransom, Dr. Evil has concluded that his programmers
 * may not be quite as competent as he had hoped.
 *
 * Therefore, the Evil Organization has begun development of a new software
 * system:
 *
 *                         PROJECT: THE BOMB
 *
 * When completed, THE BOMB will become a critical component of Dr. Evil's
 * latest and most diabolical plan for world domination.
 *
 * But before THE BOMB can be constructed, Dr. Evil must know whether his
 * software -- and his programmers -- can be trusted.
 *
 * That is where you come in.
 *
 * ----------------------------------------------------------------------------
 * THE PROTOTYPE
 * ----------------------------------------------------------------------------
 *
 * The program contained in this file is an early prototype of the software
 * that will eventually become THE BOMB.
 *
 * The prototype consists of SEVEN PHASES.
 *
 * Each phase expects a particular input. If the correct input is supplied,
 * the phase is defused and execution continues.
 *
 * Supply the wrong input, however, and...
 *
 *                              BOOM.
 *
 * Well, not literally.
 *
 * This is only a prototype.
 *
 * Dr. Evil's accounting department refused to authorize actual explosives
 * for undergraduate software testing.
 *
 * The final version may be less forgiving.
 *
 * ----------------------------------------------------------------------------
 * YOUR MISSION
 * ----------------------------------------------------------------------------
 *
 * You have intercepted the source code for Dr. Evil's prototype.
 *
 * Your mission is to determine the correct input for each of its seven
 * phases and completely defuse the program.
 *
 * There is one complication:
 *
 *                         NO DEBUGGER IS ALLOWED.
 *
 * You must analyze the C source code itself.
 *
 * Follow the control flow.
 * Trace the variables.
 * Examine the expressions.
 * Understand the functions.
 * Determine what the program expects.
 *
 * In other words...
 *
 *                         YOU MUST DEBUG IT BY HAND.
 *
 * Successfully defusing all seven phases will prevent Dr. Evil from
 * completing this stage of his plan.
 *
 * But do not become overconfident.
 *
 * Somewhere deep inside the Evil Organization, Dr. Evil and his engineers
 * are already working on a much more sophisticated successor to this
 * prototype.
 *
 * Its code will not be so easy to read.
 *
 * Its secrets will not be so obvious.
 *
 * And when the time comes, simply reading the source code may no longer
 * be enough.
 *
 * They call it...
 *
 *
 *                              THE BOMB LAB
 *
 *
 * Until then, your task is simple:
 *
 *                      FIND THE SEVEN INPUTS.
 *                      DEFUSE THE PROTOTYPE.
 *                      SAVE THE WORLD.
 *
 * And whatever you do...
 *
 *                              DON'T PANIC.
 *
 * ============================================================================
 */



//=======================================
// includes and defines
//=======================================
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thebomb.h>
#include <unistd.h>


// CSF STUDENTS...Change this string to be
// the last 3 digits of your TCU ID number
#define MY_LAST_3_TCU_DIGITS "..."


//=======================================
// function prototypes
//=======================================
char *pick_string(const char *s);
void explode_bomb(const int code);
void read_input(char buffer[], const int bufferSize);
void phase1();
int  phase2();
void phase3();
void phase4(const int x);
void phase5(char buffer[], const int bufferSize);
void phase6(const char buf1[], const int bufSize);
void phase7(int *x);
void sig_handler(int sig);


//=======================================
// global variables
//=======================================
char phonetic_alphabet[] = 
    "alpha   "
    "bravo   "
    "charlie "
    "delta   "
    "echo    "
    "foxtrot "
    "golf    "
    "hotel   "
    "india   "
    "juliet  "
    "lima    "
    "mike    "
    "november"
    "oscar   "
    "papa    "
    "qubec   "
    "romeo   "
    "sierra  "
    "tango   "
    "uniform "
    "victor  "
    "whiskey "
    "xray    "
    "yankee  "
    "zulu    "
    "01234567";


//=======================================
// main function
//=======================================
int main()
{
    // local variables */
    enum {bufSize = 10};
    char buffer[bufSize];
    int result;

    /* Just for fun, trap Ctrl-C: */
    initialize();
    signal(SIGINT, sig_handler);

    printf(UNDERLINE "Enter the stage 1 password..." RESET); printf("\n");
    phase1();
    printf(GREEN "Stage 1 defused." RESET); printf("\n\n");

    printf(UNDERLINE "Enter the stage 2 password..." RESET); printf("\n");
    result = phase2();
    printf(GREEN "Stage 2 defused." RESET); printf("\n\n");

    printf(UNDERLINE "Enter the stage 3 password..." RESET); printf("\n");
    phase3();
    printf(GREEN "Stage 3 defused." RESET); printf("\n\n");

    printf(UNDERLINE "Enter the stage 4 password..." RESET); printf("\n");
    phase4(result);
    printf(GREEN "Stage 4 defused." RESET); printf("\n\n");

    printf(UNDERLINE "Enter the stage 5 password..." RESET); printf("\n");
    phase5(buffer, bufSize);
    printf(GREEN "Stage 5 defused." RESET); printf("\n\n");

    printf(UNDERLINE "Enter the stage 6 password..." RESET); printf("\n");
    phase6(buffer, bufSize);
    printf(GREEN "Stage 6 defused." RESET); printf("\n\n");

    printf(UNDERLINE "Enter the stage 7 password..." RESET); printf("\n");
    phase7(&result);
    printf(GREEN "Stage 7 defused.\n" RESET); printf("\n\n");

    printf(UNDERLINE "The entire bomb has been defused.\n" RESET);

    return(0);
}


//=======================================
// pick string function
//=======================================
char* pick_string(const char *s)
{
    return(phonetic_alphabet+((s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0'))%26*8);
}


//=======================================
// explode bomb function
//=======================================
void explode_bomb(const int code)
{
  printf(RED "If this had been a real software bomb, you would have lost 5 points from your total score." RESET); printf("\n");
  exit(code);
}

//=======================================
// read_input function
//=======================================
void read_input(char buffer[], const int bufferSize)
{
    int i;
    int c;
    for(i=0; i<=bufferSize; ++i) {
        c = getchar();

        if(c == '\n') {
            break;
        }
        else if(i<bufferSize) {
            buffer[i] = (char)c;
        }
    }

}


//=======================================
// phase1 function
//=======================================
void phase1()
{
    enum {bufferSize = 12};
    char buffer[bufferSize];
    char *target = pick_string(MY_LAST_3_TCU_DIGITS);
    int i;
    //    const int n = strlen(target);

    read_input(buffer, bufferSize);

    for(i=0; i<bufferSize; i++) {
        if(buffer[i] != target[i]) {
            explode_bomb(10);
        }
    }
}


//=======================================
// phase2 function
//=======================================
int phase2()
{
    int z;

    enum {bufferSize = 12};
    char buffer[bufferSize];

    read_input(buffer, bufferSize);

    /* atoi takes a string representation of a number (e.g. "1234") */
    /* and converts it to an int representation of the number (e.g. 1234) */
    z = atoi(buffer);
    if(!z)
        explode_bomb(20);

    z += 22;

    if(z != 53)
        explode_bomb(21);

    return z / 2;
}

//=======================================
// phase3 function
//=======================================
void phase3()
{
    int i;

    enum {bufferSize = 12};
    char buffer[bufferSize];


    read_input(buffer, bufferSize);

    i=0;
    while(i < bufferSize && (buffer[i] == 'C' || buffer[i] == 'S' || buffer[i] == 'F' )) {
        i++;
    }

    if(i != 4)
        explode_bomb(30);
}

//=======================================
// phase4 function
//=======================================
void phase4(const int x)
{
    int i,y,z;
    enum {bufferSize = 12};
    char buffer[bufferSize];

    read_input(buffer, bufferSize);

    /* atoi takes a string representation of a number (e.g. "1234") */
    /* and converts it to an int representation of the number (e.g. 1234) */
    z = atoi(buffer);
    if(!z)
        explode_bomb(40);

    y = z;
    for(i=0; i<50; i++) {
        y += z * i * y;
    }

    if(z + 12 != x) {
        explode_bomb(41);
    }
}


//=======================================
// phase5 function
//=======================================
void phase5(char buffer[], const int bufferSize)
{
    const char allowed[] = "thequickbrownfoxjumpsoverthelazydog";
    int i, j, x;

    for(i=0; i<bufferSize; ++i) {
        char c;

        x = getchar();
        if(x == EOF)
            explode_bomb(50);
        else if(x == '\n')
            explode_bomb(51);

        c = (char)x;
        for(j=2; j<10; ++j) {
            if(c == allowed[j]) {
                buffer[i] = c + 1;
                break;
            }
        }
        if(j == 10) {
            explode_bomb(52);
        }

    }

    j = 0;
    for(i=1; i<bufferSize; ++i) {
        if(buffer[i] != buffer[i-1]) {
            j = 1;
            break;
        }
    }
    if(j == 0)
        explode_bomb(53);


    /* Windows encodes an end-of-line as two characters: \r\n */
    /* Linux just uses \n */
    /* This will accept either version */
    x = getchar();
    if(x == '\r')
        x = getchar();
    if(x != '\n')
        explode_bomb(54);
}


//=======================================
// phase6 function
//=======================================
void phase6(const char buf1[], const int bufSize)
{
    char buf2[bufSize];
    int i;

    read_input(buf2, bufSize);
    for(i=0; i<bufSize; ++i) {
        if(buf1[i] != buf2[bufSize - 1 - i])
            explode_bomb(60);
    }

}

//=======================================
// phase7 function
//=======================================
void phase7(int *x)
{
    int y = 19;
    int *z = &y;
    int k;

    enum {bufSize = 12};
    char buffer[bufSize];

    *z -= 3;

    read_input(buffer, bufSize);

    /* atoi takes a string representation of a number (e.g. "1234") */
    /* and converts it to an int representation of the number (e.g. 1234) */
    k = atoi(buffer);

    if(k + *x != y)
        explode_bomb(70);

}


//=======================================
// ctrl-c signal handler
//=======================================
void sig_handler(int sig)
{
    printf(YELLOW"So you think you can stop the bomb with ctrl-c, do you?\n"RESET);
    sleep(3);
    printf(YELLOW"Well..."RESET);
    fflush(stdout);
    sleep(1);
    printf(GREEN"OK. :-)\n"RESET);
    exit(16);
}
