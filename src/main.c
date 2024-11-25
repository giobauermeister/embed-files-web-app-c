#include <stdio.h>
#include "mongoose.h"
#include "web_server.h"

int main() {
   // printf() displays the string inside quotation
   printf("Hello, SimpleServer!\n");

   struct mg_mgr mgr;
   // Initialize the Mongoose manager
   mg_mgr_init(&mgr);
   printf("Starting SimpleServer on http://localhost:8000\n");

   // Create an HTTP listener
   mg_http_listen(&mgr, "http://0.0.0.0:8000", ev_handler, NULL);

   // Infinite event loop
   for (;;) mg_mgr_poll(&mgr, 100);

   // Free resources (never reached in this example)
   mg_mgr_free(&mgr);

   return 0;
}