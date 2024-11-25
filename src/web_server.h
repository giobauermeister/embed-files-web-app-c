#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "mongoose.h"

// Maximum header size
#define MAX_HEADER_SIZE 512

// Declare a structure for embedded files
typedef struct {
    const char *path;               // Path (e.g., "/favicon.ico")
    const unsigned char *data;      // Pointer to file data
    unsigned int length;            // Length of the file data
    const char *content_type;       // Content type (e.g., "text/html")
} EmbeddedFile;

// Extern declaration for the embedded files array
extern EmbeddedFile embedded_files[];

void ev_handler(struct mg_connection *c, int ev, void *ev_data);

#endif // WEB_SERVER_H