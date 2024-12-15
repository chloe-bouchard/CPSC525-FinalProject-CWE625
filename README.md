# CPSC525-FinalProject-CWE625
Vulnerable and exploit code demonstrating CWE 625

addEmail.c:
    This simple c code retrieves an email address for the purpose of adding the email
    to the list of subscribers for a newsletter (which is in a text file called newsletterSubscribers.txt). It passes the input to the function validate_email_format to validate the input's format using a regex pattern. This pattern is intentionally flawed to demonstrate a vulnerability. If the email input has an unexpected format, it will output a message and return 0. If the email passes the check, the function will return 1. If the email input is in an accepted format, it will append the string to the newsletter text file. 

exploit.sh:
    If newsletterSubscribers.txt does not exist, this script creates the file.
    This program takes advantage of addEmail.c's vulnerable regex pattern and injects shell code into the input. Because the regex isn't restrictive enough, it will accept any characters before the @ symbol. This script injects shell code into the email input, which will result in newsletterSubscribers.txt being deleted.


To run in a non-malicious way:

```
$ make
```
```
$ ./addEmail
```

To run in a malicious way:

```
$ make
```
```
$ sh exploit.sh
```
