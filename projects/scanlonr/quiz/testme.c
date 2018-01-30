#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    int n = -1;

    while (n < 32) {
        n = rand() % 127;
    }

    return (char)n;
}

void inputString(char *str)
{
    // TODO: rewrite this function
    for (int i = 0; i < 5; i++) {
        int n = -1;
        while (n < 97) {
            n = rand() % 123;
            str[i] = (char)n;
        }
    }

    str[5] = '\0';
}

void testme()
{
  int tcCount = 0;
  char s[6];
  char c;
  int state = 0;

  while (1) {
    tcCount++;
    c = inputChar();
    inputString(s);
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) {
        state = 1;
    }
    if (c == '(' && state == 1) {
        state = 2;
    }
    if (c == '{' && state == 2) {
        state = 3;
    }
    if (c == ' '&& state == 3) {
        state = 4;
    }
    if (c == 'a' && state == 4) {
        state = 5;
    }
    if (c == 'x' && state == 5)  {
        state = 6;
    }
    if (c == '}' && state == 6) {
        state = 7;
    }
    if (c == ')' && state == 7) {
        state = 8;
    }
    if (c == ']' && state == 8) {
        state = 9;
    }
    if (s[0] == 'r' && s[1] == 'e'  &&
        s[2] == 's' && s[3] == 'e'  &&
        s[4] == 't' && s[5] == '\0' &&
        state == 9) {
        printf("error ");
        exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}

//int main()
//{
//    srand(time(NULL));
//    char s[6];
//    for (int i = 0; i < 10; i++) {
//        printf("%c\n", inputChar());
//        inputString(s);
//        printf("%s\n", s);
//    }
//    return 0;
//}
