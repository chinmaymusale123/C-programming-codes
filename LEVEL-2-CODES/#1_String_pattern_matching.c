#include <stdio.h>

/* Function Declarations - telling C these functions exist before we define them */
void readString(char str[]);
void removeNewline(char str[]);
int getLength(char str[]);
int findPattern(char str[], char pat[], int start);
int replacePattern(char str[], char pat[], char rep[], char result[]);
void displayResult(int flag, char result[]);

int main() {
    char str[1000];    /* main string - up to 999 characters */
    char pat[100];     /* pattern to search - up to 99 characters */
    char rep[100];     /* replacement string - up to 99 characters */
    char result[2000]; /* result string - bigger in case replacement is longer */
    int flag;          /* will store 0 (not found) or 1 (found and replaced) */

    printf("Enter the string: ");
    readString(str);
    removeNewline(str);

    printf("Enter the pattern: ");
    readString(pat);
    removeNewline(pat);

    printf("Enter the replacement: ");
    readString(rep);
    removeNewline(rep);

    flag = replacePattern(str, pat, rep, result);
    displayResult(flag, result);

    return 0;
}

/* ---------- FUNCTION 1: readString ----------
   Reads a full line of text from the user (including spaces)
   fgets reads characters until Enter is pressed              */
void readString(char str[]) {
    fgets(str, 1000, stdin); /* read from keyboard, store in str, max 1000 chars */
}

/* ---------- FUNCTION 2: removeNewline ----------
   When fgets reads input, it includes the '\n' (Enter key) at the end.
   This function finds that '\n' and replaces it with '\0' (end of string) */
void removeNewline(char str[]) {
    int i = 0;
    while (str[i] != '\0') {      /* go through each character until end of string */
        if (str[i] == '\n') {     /* if this character is a newline (Enter key) */
            str[i] = '\0';        /* replace it with null terminator (end of string) */
            break;                /* stop looking, job done */
        }
        i++;                      /* move to next character */
    }
}

/* ---------- FUNCTION 3: getLength ----------
   Counts and returns the number of characters in a string
   (just like strlen, but written by us)                    */
int getLength(char str[]) {
    int len = 0;                  /* start counting from 0 */
    while (str[len] != '\0') {    /* keep going until we hit end of string '\0' */
        len++;                    /* count this character, move to next */
    }
    return len;                   /* give back the total count */
}

/* ---------- FUNCTION 4: findPattern ----------
   Checks if pattern 'pat' exists in string 'str' starting at position 'start'
   Returns 1 (true) if found, 0 (false) if not found                          */
int findPattern(char str[], char pat[], int start) {
    int i = 0;                              /* index for pattern */
    int patLen = getLength(pat);            /* how long is the pattern? */

    while (i < patLen) {                    /* check each character of the pattern */
        if (str[start + i] != pat[i]) {  // even if one character also does not macth it will return 0
                                              /* if any character doesn't match */
            return 0;                       /* not a match, return false */
        }
        i++;                               /* characters matched so far, check next */
    }   
    return 1;                               /* all characters matched! return true */
}

/* ---------- FUNCTION 5: replacePattern ----------
   Goes through the main string character by character.
   Whenever the pattern is found, it copies the replacement instead.
   Everything else is copied as-is into result[].
   Returns 1 if at least one replacement was made, 0 if pattern not found. */
   
int replacePattern(char str[], char pat[], char rep[], char result[]) {
    int i = 0;     // for str                /* position in str (main string) */
    int j = 0;    //for result                 /* position in result */
    int k;         // for rep....there is no such variable for pat      /* general counter for inner loops */
    int flag = 0;        /* 0 = pattern never found, 1 = found at least once */
    int strLen = getLength(str);  /* length of main string */
    int patLen = getLength(pat);  /* length of pattern */
    int repLen = getLength(rep);  /* length of replacement */

    while (i < strLen) {                        /* go through every character in str */
        if (findPattern(str, pat, i) == 1) {    /* does pattern start here? */
            for (k = 0; k < repLen; k++) {      /* yes! copy the replacement instead */
                result[j] = rep[k];             /* copy one replacement character */
                j++;                            /* move result forward */
            }
            i += patLen;                        /* skip past the pattern in str */
            flag = 1;                           /* mark that we found the pattern */
        } else {
            result[j] = str[i];                 /* no match here, copy original char */
            j++;                                /* move result forward */
            i++;                                /* move str forward */
        }
    }
    result[j] = '\0';                           /* add end-of-string marker to result */
    return flag;                                /* return 1 if replaced, 0 if not */
}

/* ---------- FUNCTION 6: displayResult ----------
   Prints the result.
   flag = 0 means pattern was never found.
   flag = 1 means replacements were made, print the new string. */
void displayResult(int flag, char result[]) {
    if (flag == 0)
        printf("Pattern does not exist\n");
    else
        printf("The main string after replacement is:\n%s\n", result);
}