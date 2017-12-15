All-in-one lib

```
add include in your compilation command like:
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
