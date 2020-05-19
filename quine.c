#include <stdio.h>

char *escape(char *s, char *b) {
    char *i, *j;

    for (i = s, j = b; i - s < 537; i++, j++)
        switch (*i) {
            case '\n':
                *j = '\\';
                *(++j) = 'n';
                break;
            case '\t':
                *j = '\\';
                *(++j) = 't';
                break;
            case '\\':
                *j = '\\';
                *(++j) = '\\';
                break;
            case '\"':
                *j = '\\';
                *(++j) = '"';
                break;
            case '\0':
                *j = '\\';
                *(++j) = '0';
                break;
            default:
                *j = *i;
        }
    return b;
}

char P[1000] = "#include <stdio.h>\n\nchar *escape(char *s, char *b) {\n\tchar *i, *j;\n\n\tfor (i = s, j = b; i - s < 537; i++, j++)\n\t\tswitch (*i) {\n\t\t\tcase '\\n':\n\t\t\t\t*j = '\\\\';\n\t\t\t\t*(++j) = 'n';\n\t\t\t\tbreak;\n\t\t\tcase '\\t':\n\t\t\t\t*j = '\\\\';\n\t\t\t\t*(++j) = 't';\n\t\t\t\tbreak;\n\t\t\tcase '\\\\':\n\t\t\t\t*j = '\\\\';\n\t\t\t\t*(++j) = '\\\\';\n\t\t\t\tbreak;\n\t\t\tcase '\\\"':\n\t\t\t\t*j = '\\\\';\n\t\t\t\t*(++j) = '\"';\n\t\t\t\tbreak;\n\t\t\tcase '\\0':\n\t\t\t\t*j = '\\\\';\n\t\t\t\t*(++j) = '0';\n\t\t\t\tbreak;\n\t\t\tdefault:\n\t\t\t\t*j = *i;\n\t\t}\n\treturn b;\n}\n\nchar P[1000] = \"%s\";\nchar B[1000];\n\nint main() { printf(P, escape(P, B)); }\n";
char B[1000];


int main() { printf(P, escape(P, B)); }
