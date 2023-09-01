// Librerias
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100

// Los tokens que reconoce el lenguaje
typedef enum {
    FIN_DE_ARCHIVO,
    IDENTIFICADOR,
    ENTERO,
    ENTERO_MAL_FORMADO,
    HEXADECIMAL,
    ERROR_GENERAL
} TokenType;

typedef struct {
    TokenType type;
    char lexeme[MAX_TOKEN_LENGTH];
} Token;

// Función que analiza y escanea el archivo para obtener el siguiente token
Token scan(FILE *input) {
    Token token = {ERROR_GENERAL, ""};
    char lexeme[MAX_TOKEN_LENGTH] = "";
    char c = fgetc(input);

    // Saltar espacios en blanco
    while (isspace(c)) {
        c = fgetc(input);
    }

    // Si se alcanza el fin del archivo (EOF)
    if (c == EOF) {
        token.type = FIN_DE_ARCHIVO;
        strcpy(token.lexeme, "EOF");
        return token;
    }

    // Si el primer carácter es una letra, podría ser un identificador
    if (isalpha(c)) {
        int i = 0;
        while (isalnum(c)) {
            lexeme[i++] = c;
            c = fgetc(input);
        }
        lexeme[i] = '\0';
        token.type = IDENTIFICADOR;
    }

    // Si comienza con 0x o 0X, podría ser un valor hexadecimal
    else if (c == '0') {
        int i = 0;
        lexeme[i++] = c;
        c = fgetc(input);
        if (c == 'x' || c == 'X') {
            lexeme[i++] = c;
            c = fgetc(input);
            while (isxdigit(c) || ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
                lexeme[i++] = c;
                c = fgetc(input);
            }
            lexeme[i] = '\0';
            token.type = HEXADECIMAL;
        }
    }

    // Si el primer carácter es un dígito, podria ser un entero o un entero mal formado
    else if (isdigit(c)) {
        int i = 0;
        bool tieneLetra = false;
        while (isxdigit(c) || isalpha(c)) {
            if (isalpha(c)) {
                tieneLetra = true;
            }
            lexeme[i++] = c;
            c = fgetc(input);
        }
        lexeme[i] = '\0';

        if (!tieneLetra) {
            token.type = ENTERO;
        } else {
            token.type = ENTERO_MAL_FORMADO;
        }
    }

    // Si el primer carácter no coincide con ninguna categoría anterior, es un error general
    else {
        lexeme[0] = c;
        lexeme[1] = '\0';
        token.type = ERROR_GENERAL;
    }

    strcpy(token.lexeme, lexeme);
    return token;
}

int main() {
    FILE *inputFile = fopen("entrada.txt", "r");
    FILE *outputFile = fopen("respuesta.txt", "w");
    
    Token token;
    do {
        token = scan(inputFile);
        switch (token.type) {
            case IDENTIFICADOR:
                fprintf(outputFile, "Identificador: '%s'\n", token.lexeme);
                break;
            case ENTERO:
                fprintf(outputFile, "Entero: '%s'\n", token.lexeme);
                break;
            case ENTERO_MAL_FORMADO:
                fprintf(outputFile, "Entero mal formado: '%s'\n", token.lexeme);
                break;
            case HEXADECIMAL:
                fprintf(outputFile, "Hexadecimal: '%s'\n", token.lexeme);
                break;
            case ERROR_GENERAL:
                fprintf(outputFile, "Error general: '%s'\n", token.lexeme);
                break;
        }
    } while (token.type != FIN_DE_ARCHIVO);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}