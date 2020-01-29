#include "uls.h"

void mx_print_acl(char *file) {
    acl_t acl = NULL;
    ssize_t xattr = 0;
    char chr;

    acl = acl_get_file(file, ACL_TYPE_EXTENDED);
    xattr = listxattr(file, NULL, 0, XATTR_NOFOLLOW);
    if (xattr < 0)
        xattr = 0;
    if (xattr > 0)
        chr = '@';
    else if (acl != NULL)
        chr = '+';
    else
        chr = ' ';
    acl_free(acl);
    mx_printchar(chr);
}
