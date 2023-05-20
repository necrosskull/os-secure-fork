#ifndef _MSG_H
#define _MSG_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _msg {
    unsigned char len;
    unsigned char type; // 0 - request, 1 - response
    char body;
} MESSAGE, *PMESSAGE;

#ifdef __cplusplus
}
#endif

#endif
