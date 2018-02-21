#ifndef MEMESET_H
#define MEMESET_H

#if !defined(ARRAY_SIZE)
    #define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

#include <stdint.h>
#include <string.h>

const char *memes[] = {
    "i use arch btw",
    "I'd just like to interject for a moment...",
    "What you're refering to as Linux, is in fact GNU/Linux",
    "Or as I've recently taken to calling it, GNU Plus Linux",
    "systemd/linux",
    "GNU's Not Usable",
    ">tfw it's been 5 minutes and you haven't told everyone you use Arch Linux"
};

void *memeset(void *dst, size_t n) {
    char *dst_p = dst;
    int m_p, m_inner_p;
    m_p = 0; m_inner_p = 0;

    while (n--) {
        *dst_p++ = memes[m_p][m_inner_p++];
        if (m_inner_p >= strlen(memes[m_p])) {
            m_p++;
            m_inner_p = 0;
            if (n--)
                *dst_p++ = ' ';
        }
        if (m_p >= ARRAY_SIZE(memes)) {
            m_p = 0;
        }
    }
}

#endif