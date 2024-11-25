#include "web_server.h"
#include "mongoose.h"

// Declare extern variables for the embedded data and array
extern EmbeddedFile embedded_files[];

// Event handler for serving HTTP requests
void ev_handler(struct mg_connection *c, int ev, void *ev_data) {
    if (ev == MG_EV_HTTP_MSG) {
        struct mg_http_message *hm = (struct mg_http_message *) ev_data;

        // Iterate through the array of embedded files to find a match
        for (EmbeddedFile *file = embedded_files; file->path != NULL; file++) {
            if (mg_match(hm->uri, mg_str(file->path), NULL)) {
                // Create the header string
                char header[MAX_HEADER_SIZE];
                int header_len = snprintf(header, sizeof(header),
                                          "HTTP/1.1 200 OK\r\n"
                                          "Content-Type: %s\r\n"
                                          "Content-Length: %d\r\n"
                                          "Cache-Control: no-store, no-cache, must-revalidate\r\n"
                                          "Pragma: no-cache\r\n"
                                          "Expires: 0\r\n"
                                          "Connection: close\r\n\r\n",
                                          file->content_type, file->length);
                // Send the header
                mg_send(c, header, header_len);
                // Send the body
                mg_send(c, file->data, file->length);
                // Mark the connection as done
                c->is_draining = 1;
                return;
            }
        }

        // If no match is found, respond with 404
        mg_http_reply(c, 404, "Content-Type: text/plain\r\n", "404 Not Found\n");
    }
}