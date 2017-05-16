All-in-one lib

to use it
```
git clone --recursive https://mongit.mesamis.org/cbcercas/libcbc.git
```
and make with libs options like:
```
make WITH_LIBFT=yes \
WITH_FTPRINTF=yes \
WITH_LOGGER=yes
```

add include in your compilation command like:
```
LIB_CBC_DIR := libcbc
```

for libft:
```
INC += -I $(LIB_CBC_DIR)/libft_cbc/includes
```

for printf:
```
INC += -I $(LIB_CBC_DIR)/libftprintfcbc/includes
```

for logger:
```
INC += -I $(LIB_CBC_DIR)/lib_logger_cbc/includes
```

and finaly link the lib to your executable
```
LIB_LINK += -L $(LIB_CBC_DIR) -lcbc
```
