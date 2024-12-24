#include <stdio.h>
#define TEXT "#include <stdio.h>%c#define TEXT %c%s%c%c#define EXIT_OK return(0);%c#define EXEC()int main(void){ FILE *fp = fopen(%cGrace_kid.c%c, %cw%c); if (fp == NULL) return (1); fprintf(fp, TEXT, 10, 34, TEXT, 34, 10, 10, 34, 34, 34, 34, 10, 10, 10, 10, 10); fclose(fp); EXIT_OK}%c%c/* This is a single comment. */%c%cEXEC()%c"
#define EXIT_OK return(0);
#define EXEC()int main(void){ FILE *fp = fopen("Grace_kid.c", "w"); if (fp == NULL) return (1); fprintf(fp, TEXT, 10, 34, TEXT, 34, 10, 10, 34, 34, 34, 34, 10, 10, 10, 10, 10); fclose(fp); EXIT_OK}

/* This is a single comment. */

EXEC()
