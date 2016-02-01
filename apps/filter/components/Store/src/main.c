/*
 * Copyright 2016, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#include <camkes.h>
#include <string.h>

void l__init(void) {
}

static struct {
    const char *key;
    const char *value;
} dict[] = {
    {
        .key = "foo",
        .value = "bar",
    },
    {
        .key = "secret",
        .value = "baz",
    }
};

/* Lookup and return the value associated with 'key' */
char *l_get_value(const char *key) {
    for (unsigned int i = 0; i < sizeof(dict) / sizeof(dict[0]); ++i) {
        if (!strcmp(key, dict[i].key)) {
            return strdup(dict[i].value);
        }
    }
    /* Not found */
    return strdup("");
}
