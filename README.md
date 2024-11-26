# Simple C Server

A simple mongoose web server that has web files embedded in its binary file.
Perfect for simple web pages that run on embedded systems to control gpios, make system calls and etc.
This way the embedded systems does not need to have dedicated web servers such as Apache, nginx and etc.

Steps to compile
```
cmake -S . -B build
cmake --build build
./build/SimpleServer
```

One go command
```
cmake -S . -B build && cmake --build build && ./build/SimpleServer
```

## Instructions for basic web app

In the web-app-basic folder, you will find basic web files such as index.html, js and css files.
This basic web app does not need to be compiled.

- Edit CMakeLists.txt and change path to web-app-basic
```
set(WEB_APP_DIR ${CMAKE_SOURCE_DIR}/web-app-basic)
```

- Edit embedded_files.c, enable basic web app files
```
EmbeddedFile embedded_files[] = {
    {"/", index_html, index_html_len, "text/html"},
    {"/another-page.html", another_page_html, another_page_html_len, "text/html"},
    {"/assets/favicon.ico", favicon_ico, favicon_ico_len, "image/vnd.microsoft.icon"},
    {"/assets/ac_icon.png", ac_icon_png, ac_icon_png_len, "image/png"},
    {"/assets/ac_icon.svg", ac_icon_svg, ac_icon_svg_len, "image/svg+xml"},
    {"/css/style.css", style_css, style_css_len, "text/css"},
    {"/js/main.js", main_js, main_js_len, "application/javascript"},
    {NULL, NULL, 0, NULL}  // Sentinel value to mark the end of the array
};
```

- Compile application
```
cmake -S . -B build && cmake --build build && ./build/SimpleServer
```

## Instructions for vuejs web app

In the web-app-vuejs, you will find a full Vuejs web app project.  
You can make use of Vue Router and Pinia Store.  
It is a perfect boiler plate project to build a SPA (Single Page Application).  

- Build web page to a single index.html
```
cd web-app-vuejs
npm install
npm run build
```

Files are generated at dist folder

- Edit CMakeLists.txt and change path to web-app-vuejs
```
set(WEB_APP_DIR ${CMAKE_SOURCE_DIR}/web-app-vuejs/dist)
```

- Edit embedded_files.c, enable vuejs web app files
```
EmbeddedFile embedded_files[] = {
    {"/", index_html, index_html_len, "text/html"},
    {"/favicon.ico", favicon_ico, favicon_ico_len, "image/vnd.microsoft.icon"},
    {NULL, NULL, 0, NULL}  // Sentinel value to mark the end of the array
};
```

- Compile application
```
cmake -S . -B build && cmake --build build && ./build/SimpleServer
```