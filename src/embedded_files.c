#include "embedded_files.h"
#include "web_server.h"
#include <stdio.h>

// Create an array of embedded files
EmbeddedFile embedded_files[] = {
    {"/", index_html, index_html_len, "text/html"},
    {"/assets/favicon.ico", favicon_ico, favicon_ico_len, "image/vnd.microsoft.icon"},
    {NULL, NULL, 0, NULL}  // Sentinel value to mark the end of the array
};