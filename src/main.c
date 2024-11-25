#include <stdio.h>
#include "mongoose.h"
#include "index_html.h"
#include "favicon_ico.h"

int main() {
   // printf() displays the string inside quotation
   printf("Hello, World!\n");

   printf("Index.html (%d bytes):\n%.*s\n", index_html_len, index_html_len, index_html);
   printf("Favicon.ico size: %d bytes\n", favicon_ico_len);

   return 0;
}