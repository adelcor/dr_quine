#include <stdio.h>

/*
   Este es un comentario fuera del main
*/

char *fuente()
{
    /*
       Devuelve la cadena que representa
       este mismo programa.
    */
    return "#include <stdio.h>%1$c%1$c/*%1$c   Este es un comentario fuera del main%1$c*/%1$c%1$cchar *fuente()%1$c{%1$c    /*%1$c       Devuelve la cadena que representa%1$c       este mismo programa.%1$c    */%1$c    return %3$c%4$s%3$c;%1$c}%1$c%1$cint main(void)%1$c{%1$c    // Este es un comentario dentro del main%1$c    char *str = fuente();%1$c    printf(str, 10, 9, 34, str);%1$c    return 0;%1$c}%1$c";
}

int main(void)
{
    // Este es un comentario dentro del main
    char *str = fuente();
    printf(str, 10, 9, 34, str);
    return 0;
}
