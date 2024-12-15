#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

/**
* @brief Checks a string against an email regular expression pattern
*
* This function determines if a string input has a valid email format.
* It expects the string to have any characters, as long as it contains an @ symbol. 
*
* @param[in] input The string input
*
* @return 1 if email is valid. 0 if not.
 */
int validate_email_format(const char *input) 
{
    regex_t regex;
    const char *pattern = ".*@.*";  //accepts an email address format (too generously), expecting an @ symbol

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) 
    {
        printf("The input could not be processed.\n");
        return 0;
    }

    if (regexec(&regex, input, 0, NULL, 0) == 0) //returns 1 if the string matches the pattern
    {
        return 1;
    } 
    else 
    {
        printf("The entered email does not match the required format.\n");
        return 0;
    }
    regfree(&regex);
}

/**
* @brief Main function of the program
*
* This function receives a user input for an email and validates it.
* If the email is valid, it adds it to a text file containing other emails.
*
* @return Returns 0
 */
int main() 
{
    char *email = NULL;
    size_t len = 0;
    char shellCommand[1024];

    printf("Enter your email address to be added to our newsletter:\n");
    getline(&email, &len, stdin);  // Read input from stdin

    if(validate_email_format(email))
    {
        snprintf(shellCommand, sizeof(shellCommand), "echo \"%s\" >> newsletterSubscribers.txt", email);
        system(shellCommand); //enter email into list of users
        printf("\nYou've successfully been added to our list to receive weekly updates!\n"); 
    }

    free(email);
    return 0;
}
