#include "uls.h"

//void mx_print_acl(t_main *m_ls, int i) {
//    acl_t acl;
//    ssize_t xattr;
//    char chr;
//    char *file = m_ls->pointer[i].file_name;
//    acl_entry_t dummy;
//
//    acl = acl_get_link_np(file, ACL_TYPE_EXTENDED);
//    if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1) {
//        acl_free(acl);
//        acl = NULL;
//    }
//    xattr = listxattr(file, NULL, 0, XATTR_NOFOLLOW);
//    if (xattr > 0)
//        chr = '@';
//    else if (acl != NULL)
//        chr = '+';
//    else
//        chr = ' ';
//    acl_free(acl);
//    mx_printchar(chr);
//}

void mx_print_acl(char *file) {
    char character;
    ssize_t xattr;
    acl_t acl;
    xattr = listxattr(file, NULL, 0, XATTR_NOFOLLOW);
    acl = acl_get_file(file, ACL_TYPE_EXTENDED);
    if (xattr > 0)
        character = '@';
    else if (acl == NULL)
        character = ' ';
    else
        character = '+';
    acl_free(acl);
    mx_printchar(character);
}
