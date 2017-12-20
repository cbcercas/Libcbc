#All-in-one lib


add include in your compilation command like:

###Makefile:

```
LIBCBC_DIR := libcbc
```
for libft:
```
INC += -I $(LIBCBC_DIR)/libft/includes
```
for printf:
```
INC += -I $(LIBCBC_DIR)/libftprintf/includes
```
for logger:
```
INC += -I $(LIBCBC_DIR)/liblogger/includes
```
for logger:
```
INC += -I $(LIBCBC_DIR)/libtcaps/includes
```
and finaly link the lib to your executable
```
LIB_LINK += -L $(LIB_CBC_DIR) -lcbc
```

###CMakelists.txt:
```
#Libcbc
add_subdirectory(libcbc)
include_directories(
    libcbc/libft/includes
    libcbc/libftprintf/includes
    libcbc/liblogger/includes
    libcbc/libtcaps/includes
    )

target_link_libraries(your_app cbc)
```