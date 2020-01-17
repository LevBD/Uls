#include "uls.h"

int main(int argc, char **argv) {
    if (argc != 2)
        err_quit("Использование: a.out <имя_файла>"); if (access(argv[1], R_OK) < 0)
        err_ret("ошибка вызова функции access для файла %s", argv[1]);
    else
        printf("доступ для чтения разрешен\n");
    if (open(argv[1], O_RDONLY) < 0)
        err_ret("ошибка вызова функции open для файла %s", argv[1]);
    else
        printf("файл благополучно открыт для чтения\n");
    exit(0);
}
