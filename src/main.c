//
//   rhubarb_compiler
//
//   August 6, 2025 at 09:43:18 AM
//
//   Ruben Salazar
//

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  SEMI,
  OPEN_PAREN,
  CLOSED_PAREN,
} TypeSeparator;

typedef enum
{
  EXIT,
} TypeKeyword;

typedef enum
{
  INT,
} TypeLiteral;

typedef struct
{
    TypeSeparator type;
} TokenSeparator;

typedef struct
{
    TypeKeyword type;
} TokenKeyword;

typedef struct
{
    TypeLiteral type;
    int value;
} TokenLiteral;

void lexer(FILE *file)
{
    char current = fgetc(file);
    while (current != EOF)
    {
        if (current == ';')
        {
            printf("FOUND SEMICOLON\n");
        }
        else if (current == '(')
        {
            printf("FOUND OPEN PAREN\n");
        }
        else if (current == ')')
        {
            printf("FOUND CLOSED PAREN\n");
        }
        current = fgetc(file);
    }
}

int main()
{
    FILE *file;
    file = fopen("test.rhu", "r");

    lexer(file);

    return 0;
}
