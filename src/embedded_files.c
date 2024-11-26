#include "embedded_files.h"
#include "web_server.h"
#include <stdio.h>

// Files for Basic Web App
// EmbeddedFile embedded_files[] = {
//     {"/", index_html, index_html_len, "text/html"},
//     {"/another-page.html", another_page_html, another_page_html_len, "text/html"},
//     {"/assets/favicon.ico", favicon_ico, favicon_ico_len, "image/vnd.microsoft.icon"},
//     {"/assets/ac_icon.png", ac_icon_png, ac_icon_png_len, "image/png"},
//     {"/assets/ac_icon.svg", ac_icon_svg, ac_icon_svg_len, "image/svg+xml"},
//     {"/css/style.css", style_css, style_css_len, "text/css"},
//     {"/js/main.js", main_js, main_js_len, "application/javascript"},
//     {NULL, NULL, 0, NULL}  // Sentinel value to mark the end of the array
// };

// Files for Vuejs Web App
EmbeddedFile embedded_files[] = {
    {"/", index_html, index_html_len, "text/html"},
    {"/assets/favicon.ico", favicon_ico, favicon_ico_len, "image/vnd.microsoft.icon"},
    {NULL, NULL, 0, NULL}  // Sentinel value to mark the end of the array
};