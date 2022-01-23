# Debug
fixing the errors of the code

## Syntax Error
errors due to grammartical error of the language

> ex) printf("hello, world\n")
> ---> omitted semicolon(;)

can debug by:
* looking at the error message

## Logical Error
errors due to logic of the code

> ex) for (int i = 0; i <=5; i++)
>     {
>         printf("#\n");
>     }
> ---> intended 5 hashes but prints 6 hashes

can debug by:
* using printf to see what's happening
* using debugger of IDE to use break points and to manually step through the code
* rubber duck debugging