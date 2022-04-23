## Formatting

### Indentation
* Tabs are 8 characters, and thus indentations are also 8 characters. 
* ...if you need more than 3 levels of indentation, you’re screwed anyway, and should fix your program.
* The preferred way to ease multiple indentation levels in a switch statement is to align the switch and its subordinate case labels in the same column instead of double-indenting the case labels.

```c
switch (suffix) {
case 'G':
case 'g':
        mem <<= 30;
        break;
case 'M':
case 'm':
        mem <<= 20;
        break;
case 'K':
case 'k':
        mem <<= 10;
        /* fall through */
default:
        break;
}
```

* Don’t put multiple statements on a single line unless you have something to hide:
* Don’t put multiple assignments on a single line either.

```c
if (condition) do_this;
  do_something_everytime;
```
* Outside of comments, documentation and except in Kconfig, spaces are never used for indentation, and the above example is deliberately broken.
 

### Breaking long lines and strings
* The limit on the length of lines is 80 columns and this is a strongly preferred limit.

### Placing Braces and Spaces
* The preferred way, as shown to us by the prophets Kernighan and Ritchie, is to put the opening brace last on the line, and put the closing brace first, thusly:

```c
if (x is true) {
        we do y
}
```

* This applies to all non-function statement blocks (if, switch, for, while, do). E.g.:

```c
switch (action) {
case KOBJ_ADD:
        return "add";
case KOBJ_REMOVE:
        return "remove";
case KOBJ_CHANGE:
        return "change";
default:
        return NULL;
}
```

* However, there is one special case, namely functions: they have the opening brace at the beginning of the next line, thus:

```c
int function(int x)
{
        body of function
}
```

* Note that the closing brace is empty on a line of its own, except in the cases where it is followed by a continuation of the same statement, ie a while in a do-statement or an else in an if-statement, like this:

```c
do {
        body of do-loop
} while (condition);

// AND 

if (x == y) {
        ..
} else if (x > y) {
        ...
} else {
        ....
}
```

* Do not unnecessarily use braces where a single statement will do.

```c
if (condition)
        action();
// AND

if (condition)
        do_this();
else
        do_that();
```

* This does not apply if only one branch of a conditional statement is a single statement; in the latter case use braces in both branches:

```c
if (condition) {
        do_this();
        do_that();
} else {
        otherwise();
}
```

### Spaces

* Linux kernel style for use of spaces depends (mostly) on function-versus-keyword usage. Use a space after (most) keywords. The notable exceptions are sizeof, typeof, alignof, and __attribute__, which look somewhat like functions (and are usually used with parentheses in Linux, although they are not required in the language, as in: sizeof info after struct fileinfo info; is declared).

* So use a space after these keywords:
```c
if, switch, case, for, do, while
```

* but not with sizeof, typeof, alignof, or __attribute__. E.g.,

```c
s = sizeof(struct file);
```

* Do not add spaces around (inside) parenthesized expressions. This example is bad:

```c
// BAD
s = sizeof( struct file );
```

* When declaring pointer data or a function that returns a pointer type, the preferred use of * is adjacent to the data name or function name and not adjacent to the type name. Examples:

```c
char *linux_banner;
unsigned long long memparse(char *ptr, char **retptr);
char *match_strdup(substring_t *s);
```

* Use one space around (on each side of) most binary and ternary operators, such as any of these:

```c
=  +  -  <  >  *  /  %  |  &  ^  <=  >=  ==  !=  ?  :
```

* but no space after unary operators:

```c
&  *  +  -  ~  !  sizeof  typeof  alignof  __attribute__  defined
```

* no space before the postfix increment & decrement unary operators:

```c
++  --
```

* and no space around the . and -> structure member operators.


### Naming

* While mixed-case names are frowned upon, descriptive names for global variables are a must. To call a global function foo is a shooting offense.

* GLOBAL variables (to be used only if you really need them) need to have descriptive names, as do global functions. If you have a function that counts the number of active users, you should call that count_active_users() or similar, you should not call it cntusr(). 

* LOCAL variable names should be short, and to the point. If you have some random integer loop counter, it should probably be called i. Calling it loop_counter is non-productive, if there is no chance of it being mis-understood. Similarly, tmp can be just about any type of variable that is used to hold a temporary value.


### Typedefs

* Please don’t use things like vps_t. It’s a mistake to use typedef for structures and pointers. When you see a "vps_t a;" in the source, what does it mean?

* In contrast:

```c
struct virtual_container *a;
```

* Lots of people think that typedefs help readability. Not so. They are useful only for:
	1. Totally opaque objects (where the typedef is actively used to hide what the object is).
	2. Clear integer types, where the abstraction helps avoid confusion whether it is int or long.
		* u8/u16/u32 are perfectly fine typedefs, although they fit into category (4) better than here.
	3. when you use sparse to literally create a new type for type-checking.
	4. New types which are identical to standard C99 types, in certain exceptional circumstances. Therefore, the Linux-specific u8/u16/u32/u64 types and their signed equivalents which are identical to standard types are permitted – although they are not mandatory in new code of your own.
	5. Types safe for use in userspace.  In certain structures which are visible to userspace, we cannot require C99 types and cannot use the u32 form above. Thus, we use __u32 and similar types in all structures which are shared with userspace.


### Functions

### Commenting

### Macros, Enums and RTL

### Allocating Memory

