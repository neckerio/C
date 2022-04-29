# C notes

---

## Objective
* learn C basics

## Implementation
* [LPI](LPI)
* [Formatting](Formatting)

## Primary Resources
* The Linux Programming Interface: A Linux and UNIX System Programming Handbook [^lpi]
* kernel.org [^kernel]

---

### Base
* executable = causes a computer "to perform indicated tasks according to encoded instructions"
* object code = machine code output of an assembler or compiler
	* .o in Linux
	* ELF format
		* Each ELF file is made up of one ELF header, followed by file data. The data can include: 
		* Program header table, describing zero or more memory segments
			* The segments contain information that is needed for run time execution of the file
		* Section header table, describing zero or more sections
			* sections contain important data for linking and relocation
		* Data referred to by entries in the program header table or section header table
		* The ELF header defines whether to use 32- or 64-bit addresses. The header contains three fields that are affected by this setting and offset other fields that follow them. The ELF header is 52 or 64 bytes long for 32-bit and 64-bit binaries respectively.


* VIRTUAL MEMORY:
* Memory Paging: is a memory management scheme by which a computer stores and retrieves data from secondary storage[a] for use in main memory.[citation needed] In this scheme, the operating system retrieves data from secondary storage in same-size blocks called pages [^paging]
	* Page: a fixed-length contiguous block of virtual memory, described by a single entry in the page table. It is the smallest unit of data for memory management in a virtual memory operating system. Similarly, a page frame is the smallest fixed-length contiguous block of physical memory into which memory pages are mapped by the operating system [^page]
	* Page Table: A page table is the data structure used by a virtual memory system in a computer operating system to store the mapping between virtual addresses and physical addresses. Virtual addresses are used by the program executed by the accessing process, while physical addresses are used by the hardware, or more specifically, by the random-access memory (RAM) subsystem. The page table is a key component of virtual address translation that is necessary to access data in memory. [^pagetable]



* Memory Segments [^memseg]
	*  The Von Neumann architecture is defined by the fact that both the machine instructions and data are stored in the same memory space. This fact necessitates dividing memory into text and data segments. In modern operating systems, there are more than just these two segments. Most systems use a single text segment, but actually use up to three data segments, depending on the storage class of the data being stored there. The four segments can be described as follows:
		* **code segment**, also known as text segment contains the machine instructions of the program. The code can be thought of like the text of a novel: It tells the story of what the program does.
		* **data segment** contains the static data of the program, i.e. the variables that exist throughout program execution. Global variables in a C or C++ program are static, as are variables declared as static in C, C++
		* **stack segment** contains the system stack, which is used as temporary storage. The stack is a simple data structure with a LIFO (last-in first-out) access policy. Items are only added to or removed from the "top" of the stack. Implementing a stack requires only a block of memory (e.g. an array in a HLL) and a stack pointer which tells us where the top of the stack is. Adding an element to the top of the stack is known as a push, and retrieving an item from the top is known as a pop.
		* **heap segment** is a pool of memory used for dynamically allocated memory, such as with malloc() in C or new in C++ 

* The size of the text and data segments are known as soon as compilation or assembly is completed. The stack and heap segments, on the other hand, grow and shrink during program execution. For this reason, they tend to be configured such that they grow toward each other. This way, they each have a fixed starting point (one adjacent to the text and data segments, and the other at one end of the entire memory space), and the boundary between them is flexible. Both can grow until all available memory is used


* .code [^.code]
	* also known as a text segment or simply as text, is a portion of an object file or the corresponding section of the program's virtual address space that contains executable instructions.
	* When a program is stored in an object file, the code segment is a part of this file; when the loader places a program into memory so that it may be executed, various memory regions are allocated (in particular, as pages), corresponding to both the segments in the object files and to segments only needed at run time.
	* The code segment in memory is typically read-only and has a fixed size
	* As a memory region, the code segment may be placed below the heap or stack in order to prevent heap and stack overflows from overwriting it.


* .data [^.data]
	* a portion of an object file or the corresponding address space of a program that contains initialized static variables, that is, global variables and static local variables. The size of this segment is determined by the size of the values in the program's source code, and does not change at run time. 
	* a static variable is a variable that has been allocated "statically", meaning that its lifetime (or "extent") is the entire run of the program
	* In general, static memory allocation is the allocation of memory at compile time, before the associated program is executed
	* The data segment is read/write, since the values of variables can be altered at run time.
	* A static local variable is different from a local variable as a static local variable is initialized only once no matter how many times the function in which it resides is called and its value is retained and accessible through many calls to the function in which it is declared, e.g. to be used as a count variable


* .bss [^.bss]
	* the block starting symbol is the portion of an object file, executable, or assembly language code that contains statically allocated variables that are declared but have not been assigned a value yet. It is often referred to as the "bss section" or "bss segment". 
	* Typically only the length of the bss section, but no data, is stored in the object file, and the size is reduced
	* In C, statically allocated objects without an explicit initializer are initialized to zero (for arithmetic types) or a null pointer (for pointer types).
	* the BSS segment typically includes all uninitialized objects (both variables and constants) declared at file scope (i.e., outside any function) as well as uninitialized static local variables (local variables declared with the static keyword)


* stack [^stack] [^stackmem]
	* a call stack is a stack data structure that stores information about the active subroutines of a computer program.
	* the main reason for having one is to keep track of the point to which each active subroutine should return control when it finishes executing. An active subroutine is one that has been called, but is yet to complete execution, after which control should be handed back to the point of call
	* Such activations of subroutines may be nested to any level (recursive as a special case), hence the stack structure.
	* To accomplish this, the address following the instruction that jumps to a subroutine, the return address, is pushed onto the top of the call stack with each call. 
	* In high-level programming languages, the specifics of the call stack are usually hidden from the programmer. They are given access only to a set of functions, and not the memory on the stack itself.
	* The stack is often used to store variables of fixed length local to the currently active functions. Programmers may further choose to explicitly use the stack to store local data of variable length. If a region of memory lies on the thread's stack, that memory is said to have been allocated on the stack, i.e. stack-based memory allocation (SBMA).
	* Because the data is added and removed in a last-in-first-out manner, stack-based memory allocation is very simple and typically much faster than heap-based memory allocation
	* Another feature is that memory on the stack is automatically, and very efficiently, reclaimed when the function exits, which can be convenient for the programmer if the data is no longer required.
	* Therefore, stack based allocation is suitable for temporary data or data which is no longer required after the current function exits. 



* heap [^heap]
	* Memory management is a form of resource management applied to computer memory.
	* The essential requirement of memory management is to provide ways to dynamically allocate portions of memory to programs at their request, and free it for reuse when no longer needed.
	* Several methods have been devised that increase the effectiveness of memory management. Virtual memory systems separate the memory addresses used by a process from actual physical addresses, allowing separation of processes and increasing the size of the virtual address space beyond the available amount of RAM using paging or swapping to secondary storage.
	* manual memory management refers to the usage of manual instructions by the programmer to identify and deallocate unused objects, or garbage
	* The task of fulfilling an allocation request consists of locating a block of unused memory of sufficient size. Memory requests are satisfied by allocating portions from a large pool of memory called the heap or free store.
	* C dynamic memory allocation refers to performing manual memory management for dynamic memory allocation in the C programming language via a group of functions in the C standard library, namely malloc, realloc, calloc and free.

* The C programming language manages memory statically, automatically, or dynamically.
	* Static-duration variables are allocated in main memory, usually along with the executable code of the program, and persist for the lifetime of the program
		* the size of the allocation must be compile-time constant
	* automatic-duration variables are allocated on the stack and come and go as functions are called and return
		* the size of the allocation must be compile-time constant
	* These limitations are avoided by using dynamic memory allocation, in which memory is more explicitly (but more flexibly) managed, typically by allocating it from the free store (informally called the "heap"), an area of memory structured for this purpose
	* The program accesses this block of memory via a pointer that malloc returns. When the memory is no longer needed, the pointer is passed to free which deallocates the memory so that it can be used for other purposes. 

```c
int *array = malloc(10 * sizeof(int));
```
	* The memory set aside by malloc is not initialized and may contain cruft: the remnants of previously used and discarded data. After allocation with malloc, elements of the array are uninitialized variables
	* The major problem with this method is that the heap has only two significant attributes: base, or the beginning of the heap in virtual memory space; and length, or its size. The heap requires enough system memory to fill its entire length, and its base can never change.
	* static variables and automatica variables are in contrast to objects, whose storage is dynamically allocated and deallocated in heap memory. 
	* Dynamic/automatic memory allocation happens at runtime


### extra reading
* [static vars and objects](https://en.wikipedia.org/wiki/Static_variable)
* [c syntax](https://en.wikipedia.org/wiki/C_syntax#Storage_class_specifiers)



## C Syntax [^reference]
* A C program is a sequence of text files (typically header and source files) that contain declarations. They undergo translation to become an executable program, which is executed when the OS calls its main function (unless it is itself the OS or another freestanding program, in which case the entry point is implementation-defined).
Certain words in a C program have special meaning, they are keywords. Others can be used as identifiers, which may be used to identify objects, functions, struct, union, or enumeration tags, their members, typedef names, labels, or macros.

* Each identifier (other than macro) is only valid within a part of the program called its scope and belongs to one of four kinds of name spaces. Some identifiers have linkage which makes them refer to the same entities when they appear in different scopes or translation units.

* Definitions of functions include sequences of statements and declarations, some of which include expressions, which specify the computations to be performed by the program.

* Declarations and expressions create, destroy, access, and manipulate objects. Each object, function, and expression in C is associated with a type. 

### Phases of Translation
* Translation Unit
* later


### Keywords

### Identifiers
* An identifier is an arbitrarily long sequence of digits, underscores, lowercase and uppercase Latin letters. Not a keyword or other reserved identifier.
* Identifiers can denote the following types of entities: 
	* objects
    	* functions
    	* tags (struct, union, or enumerations)
    	* structure or union members
    	* enumeration constants
    	* typedef names
    	* label names
    	* macro names
    	* macro parameter names 
* Every identifier other than macro names or macro parameter names has scope, belongs to a name space, and may have linkage. The same identifier can denote different entities at different points in the program, or may denote different entities at the same point if the entities are in different name spaces. 



### Storage-class Specifiers
* Storage-class specifiers, specify storage duration and linkage of objects and functions: 
	* auto - automatic duration and no linkage
	* register - automatic duration and no linkage; address of this variable cannot be taken
	* static - static duration and internal linkage (unless at block scope)
	* extern - static duration and external linkage (unless already declared internal) 
* Storage-class specifiers appear in declarations. At most one specifier may be used
* The storage-class specifiers determine two independent properties of the names they declare: storage duration and linkage.

1. The **Auto Specifier** is only allowed for objects declared at block scope (except function parameter lists). It indicates automatic storage duration and no linkage, which are the defaults for these kinds of declarations.

2. The register specifier is only allowed for objects declared at block scope, including function parameter lists. It indicates automatic storage duration and no linkage (which is the default for these kinds of declarations), but additionally hints the optimizer to store the value of this variable in a CPU register if possible.

3. The static specifier specifies both static storage duration It can be used with functions at file scope and with variables at both file and block scope, but not in function parameter lists.

4. The extern specifier specifies static storage duration and external linkage. It can be used with function and object declarations in both file and block scope (excluding function parameter lists).

* If no storage-class specifier is provided, the defaults are:
	* extern for all functions 
	* extern for objects at file scope 
	* auto for objects at block scope 
* For any struct or union declared with a storage-class specifier, the storage duration (but not linkage) applies to their members, recursively. 
* Function declarations at block scope can use extern or none at all. Function declarations at file scope can use extern or static. 

#### storage duration
* Every object has a property called storage duration, which limits the object lifetime. There are four kinds of storage duration in C: 
	* **Automatic Storage** Duration. The storage is allocated when the block in which the object was declared is entered and deallocated when it is exited by any means
	* **Static Storage** duration. The storage duration is the entire execution of the program, and the value stored in the object is initialized only once, prior to main function. All objects declared static and all objects with either internal or external linkage have this storage duration
	* **Thread Storage** duration.
	* **Allocated Storage** duration. The storage is allocated and deallocated on request, using dynamic memory allocation functions. 

#### linkage
* Linkage refers to the ability of an identifier (variable or function) to be referred to in other scopes. If a variable or function with the same identifier is declared in several scopes, but cannot be referred to from all of them, then several instances of the variable are generated. The following linkages are recognized:
	* **No Linkage**. The identifier can be referred to only from the scope it is in. All function parameters and all non-extern block-scope variables (including the ones declared static) have this linkage.
	* **Internal Linkage**. The identifier can be referred to from all scopes in the current translation unit. All static file-scope identifiers (both functions and variables) have this linkage. 
	* **External Linkage**. The identifier can be referred to from any other translation units in the entire program. All non-static functions, all extern variables (unless earlier declared static), and all file-scope non-static variables have this linkage.


### External and Tentative definitions
* At the top level of a translation unit (that is, a source file with all the #includes after the preprocessor), every C program is a sequence of declarations, which declare functions and objects with external or internal linkage. These declarations are known as external declarations because they appear outside of any function.
* Objects declared with an external declaration have static storage duration, and as such cannot use auto or register specifiers. The identifiers introduced by external declarations have file scope. 

#### tentative definitions
* A **Tentative Definition** is an external declaration without an initializer, and either without a storage-class specifier or with the specifier static. 
* A **Tentative Definition** is a declaration that may or may not act as a definition. If an actual external definition is found earlier or later in the same translation unit, then the tentative definition just acts as a declaration. 
* If there are no definitions in the same translation unit, then the tentative definition acts as an actual definition that zero-initializes the object. 
* + more
* Think about Translation Units all at the top with these there above the main function
	* THE ONE DIFINITION RULE:
		* Each translation unit may have zero or one external definition of every identifier with internal linkage (a static global). 
		* The entire program may have zero or one external definition of every identifier with external linkage. 


### Scope
* Each identifier that appears in a C program is visible (that is, may be used) only in some possibly discontiguous portion of the source code called its scope.
* Within a scope, an identifier may designate more than one entity only if the entities are in different name spaces.
* C has four kinds of scopes: 
	* block scope
	* file scope
	* function scope
	* function prototype scope 
* If two different entities named by the same identifier are in scope at the same time, and they belong to the same name space, the scopes are nested (no other form of scope overlap is allowed), and the declaration that appears in the inner scope hides the declaration that appears in the outer scope:

1. **Block Scope**. The scope of any identifier declared inside a compound statement, including function bodies, or in any expression, declaration, or statement appearing in if, switch, for, while, or do-while statement (since C99), or within the parameter list of a function definition begins at the point of declaration and ends at the end of the block or statement in which it was declared. 
* Block-scope variables have no linkage and automatic storage duration by default. Note that storage duration for non-VLA local variables begins when the block is entered, but until the declaration is seen, the variable is not in scope and cannot be accessed. 

2. **File Scope**. The scope of any identifier declared outside of any block or parameter list begins at the point of declaration and ends at the end of the translation unit. 
* File-scope identifiers have external linkage and static storage duration by default. 

3. **Function Scope**. A label (and only a label) declared inside a function is in scope everywhere in that function, in all nested blocks, before and after its own declaration. Note: a label is declared implicitly, by using an otherwise unused identifier before the colon character before any statement. 

4. **Function Prototype Scope**. The scope of a name introduced in the parameter list of a function declaration that is not a definition ends at the end of the function declarator. 

* Point of declaration
	* The scope of structure, union, and enumeration tags begins immediately after the appearance of the tag in a type specifier that declares the tag. 
	* The scope of enumeration constant begins immediately after the appearance of its defining enumerator in an enumerator list. 
	* The scope of any other identifier begins just after the end of its declarator and before the initializer, if any: 


### Lookup and Namespaces
* When an identifier is encountered in a C program, a lookup is performed to locate the declaration that introduced that identifier and that is currently in scope. C allows more than one declaration for the same identifier to be in scope simultaneously if these identifiers belong to different categories, called name spaces:
	* **Label Name Space**: all identifiers declared as labels.
	* **Tag Names**: all identifiers declared as names of structs, unions and enumerated types. Note that all three kinds of tags share one name space.
	* **Member Names**: all identifiers declared as members of any one struct or union. Every struct and union introduces its own name space of this kind.
	* **All Other Identifiers**, called ordinary identifiers to distinguish from (1-5) (function names, object names, typedef names, enumeration constants).
* At the point of lookup, the name space of an identifier is determined by the manner in which it is used: 
	* identifier appearing as the operand of a goto statement is looked up in the label name space.
	* identifier that follows the keyword struct, union, or enum is looked up in the tag name space.
	* identifier that follows the member access or member access through pointer operator is looked up in the name space of members of the type determined by the left-hand operand of the member access operator.
	* all other identifiers are looked up in the name space of ordinary identifiers.



### Functions
* Function is a C language construct that associates a compound statement (the function body) with an identifier (the function name). Every C program begins execution from the main function, which either terminates, or invokes other, user-defined or library functions.
* Functions may accept zero or more parameters, which are initialized from the arguments of a function call operator, and may return a value to its caller by means of the return statement. 
* The body of a function is provided in a function definition. Each function that is actually called must be defined only once in a program, unless the function is inline
* There are no nested functions, each function definition must appear at file scope, and functions have no access to the local variables from the caller
* CAN NOT define a function inside another function. It can be Declared though.


### Struct
* A struct is a type consisting of a sequence of members whose storage is allocated in an ordered sequence (as opposed to union, which is a type consisting of a sequence of members whose storage overlaps)

1. Struct definition: introduces the new type struct name and defines its meaning
	* struct attr-spec-seq(optional) name(optional) { struct-declaration-list }
2. If used on a line of its own, as in struct name ;, declares but doesn't define the struct name (see forward declaration below). In other contexts, names the previously-declared struct, and attr-spec-seq is not allowed.
	* struct attr-spec-seq(optional) name

* Within a struct object, addresses of its elements (and the addresses of the bit field allocation units) increase in order in which the members were defined. A pointer to a struct can be cast to a pointer to its first member (or, if the member is a bit field, to its allocation unit).
* Likewise, a pointer to the first member of a struct can be cast to a pointer to the enclosing struct
* There may be unnamed padding between any two members of a struct or after the last member, but not before the first member
* The size of a struct is at least as large as the sum of the sizes of its members
* Similar to union, an unnamed member of a struct whose type is a struct without name is known as anonymous struct.

* Forward declaration, A declaration of the following form hides any previously declared meaning for the name name in the tag name space and declares name as a new struct name in current scope, which will be defined later. Until the definition appears, this struct name has incomplete type. This allows structs that refer to each other: 
	*  struct attr-spec-seq(optional) name ; 

#### struct initialization
* When initializing an object of struct or union type, the initializer must be a non-empty, brace-enclosed, comma-separated list of initializers for the members:
	*  = { expression , ... } 
	* = { designator expression , ... }
* where the designator is a sequence (whitespace-separated or adjacent) of individual member designators of the form . member and array designators of the form [ index ].
* All members that are not initialized explicitly are zero-initialized. 

* When initializing a struct, the first initializer in the list initializes the first declared member (unless a designator is specified) (since C99), and all subsequent initializers without designators (since C99)initialize the struct members declared after the one initialized by the previous expression.
	* struct point {double x,y,z;} p = {1.2, 1.3}; // p.x=1.2, p.y=1.3, p.z=0.0


### Union
* A union is a type consisting of a sequence of members whose storage overlaps (as opposed to struct, which is a type consisting of a sequence of members whose storage is allocated in an ordered sequence). The value of at most one of the members can be stored in a union at any one time.
* The type specifier for a union is identical to the struct type specifier except for the keyword used: 
	* union attr-spec-seq(optional) name(optional) { struct-declaration-list }
	* union attr-spec-seq(optional) name
* The union is only as big as necessary to hold its largest member (additional unnamed trailing padding may also be added). The other members are allocated in the same bytes as part of that largest member. 

#### union intialization
* When initializing an object of struct or union type, the initializer must be a non-empty, brace-enclosed, comma-separated list of initializers for the members: 
	* = { expression , ... }
	* = { designator expression , ... } 	
* where the designator is a sequence (whitespace-separated or adjacent) of individual member designators of the form . member and array designators of the form [ index ]. 
* All members that are not initialized explicitly are zero-initialized. 
* When initializing a union, the initializer list must have only one member, which initializes the first member of the union unless a designated initializer is used (since C99). 
	* union { int x; char c[4]; }
	* u = {1},           // makes u.x active with value 1



### Enumerations
* An enumerated type is a distinct type whose value is a value of its underlying type (see below), which includes the values of explicitly named constants (enumeration constants). 
* Enumerated type is declared using the following enumeration specifier as the type-specifier in the declaration grammar: 
	* enum attr-spec-seq(optional) identifier(optional) { enumerator-list }
* where enumerator-list is a comma-separated list (with trailing comma permitted) (since C99) of enumerator, each of which has the form: 
	* enumeration-constant attr-spec-seq(optional)
	* numeration-constant attr-spec-seq(optional) = constant-expression
* As with struct or union, a declaration that introduced an enumerated type and one or more enumeration constants may also declare one or more objects of that type or type derived from it. 
	* enum color { RED, GREEN, BLUE } c = RED, *cp = &c;
* Each enumeration-constant that appears in the body of an enumeration specifier becomes an integer constant with type int in the enclosing scope and can be used whenever integer constants are required (e.g. as a case label or as a non-VLA array size). 
* If enumeration-constant is followed by = constant-expression, its value is the value of that constant expression. If enumeration-constant is not followed by = constant-expression, its value is the value one greater than the value of the previous enumerator in the same enumeration. The value of the first enumerator (if it does not use = constant-expression) is zero. 

* Each enumerated type is compatible with one of: char, a signed integer type, or an unsigned integer type. It is implementation-defined which type is compatible with any given enumerated type, but whatever it is, it must be capable of representing all enumerator values of that enumeration. 
* Enumerated types are integer types, and as such can be used anywhere other integer types can, including in implicit conversions and arithmetic operators. 

* Unlike struct or union, there are no forward-declared enums in C



### Typedef
* The typedef declaration provides a way to declare an identifier as a type alias, to be used to replace a possibly complex type name
* The keyword typedef is used in a declaration, in the grammatical position of a storage-class specifier, except that it does not affect storage or linkage: 
* If a declaration uses typedef as storage-class specifier, every declarator in it defines an identifier as an alias to the type specified. Since only one storage-class specifier is permitted in a declaration, typedef declaration cannot be static or extern. 
* typedef declaration does not introduce a distinct type, it only establishes a synonym for an existing type, thus typedef names are compatible with the types they alias. Typedef names share the name space with ordinary identifiers such as enumerators, variables and function.



### Macros
* The preprocessor supports text macro replacement and function-like text macro replacement. 
	* #define identifier replacement-list(optional)
	* #define identifier( parameters ) replacement-list 
	* #define identifier( parameters, ... ) replacement-list 
	* #define identifier( ... ) replacement-list 
	* #undef identifier 
* The #define directives define the identifier as a macro, that is they instruct the compiler to replace all successive occurrences of identifier with replacement-list, which can be optionally additionally processed. If the identifier is already defined as any type of macro, the program is ill-formed unless the definitions are identical. 
* The #undef directive undefines the identifier, that is it cancels the previous definition of the identifier by #define directive. If the identifier does not have an associated macro, the directive is ignored. 

#### object-like macros

#### function-like macros

#### # and ## operators




### Type
* Objects, functions, and expressions have a property called type, which determines the interpretation of the binary value stored in an object or evaluated by the expression. 

* Type Classification:
	* the type void 
	* Basic Types
		* the type char 
		* signed integer types (standard)
			* signed char
			* short
			* int
			* long
			* long long
		* unsigned integer types (standard)
			* _Bool
			* unsigned char
			* unsigned short
			* unsigned int
			* unsigned long
			* unsigned long long
		* floating-point types (real)
			* float
			* double
			* long double
		* enumerated types 
		* Derived Types
			* array types
			* structure types 
			* union types 
			* function types 
			* pointer types 
#### type groups
*  object types: all types that aren't function types 
*  character types: char, signed char, unsigned char
*  integer types: char, signed integer types, unsigned integer types, enumerated types 
*  real types: integer types and real floating types 
*  arithmetic types: integer types and floating types 
*  scalar types: arithmetic types and pointer types 
*  aggregate types: array types and structure types 
*  derived declarator types: array types, function types, and pointer types 

#### compatible types
* In a C program, the declarations referring to the same object or function in different translation units do not have to use the same type. They only have to use sufficiently similar types, formally known as compatible types. Same applies to function calls and lvalue accesses; argument types must be compatible with parameter types and lvalue expression type must be compatible with the object type that is accessed. 
* If two declarations refer to the same object or function and do not use compatible types, the behavior of the program is undefined. 


#### composite types
* A composite type can be constructed from two types that are compatible; it is a type that is compatible with both of the two types and satisfies the following conditions: 


#### incomplete types
* An incomplete type is an object type that lacks sufficient information to determine the size of the objects of that type. An incomplete type may be completed at some point in the translation unit. 
	* the type void. This type cannot be completed. 
	* array type of unknown size. It can be completed by a later declaration that specifies the size. 
	* structure or union type of unknown content. It can be completed by a declaration of the same structure or union that defines its content later in the same scope. 

#### type names
* A type may have to be named in context other than the declaration. In these situations, type name is used, which is, grammatically, exactly the same as a list of type-specifiers and type-qualifiers, followed by the declarator (see declarations) as would be used to declare a single object or function of this type, except that the identifier is omitted: 
	* cast
	* sizeof


### Main Function
* Every C program coded to run in a hosted execution environment contains the definition (not the prototype) of a function called main, which is the designated start of the program. 
* Parameters:
	* argc
	* argv
		* int main (void) { body } 
		* int main (int argc, char *argv[]) { body } 
		* int main(int argc, char *argv[], char *envp[])
* If the return statement is used, the return value is used as the argument to the implicit call to exit(). The values zero and EXIT_SUCCESS indicate successful termination, the value EXIT_FAILURE indicates unsuccessful termination. 

* The main function is called at program startup, after all objects with static storage duration are initialized. It is the designated entry point to a program that is executed in hosted environment (that is, with an operating system). The name and type of the entry point to any freestanding program (boot loaders, OS kernels, etc) are implementation-defined. 
* The parameters of the two-parameter form of the main function allow arbitrary multibyte character strings to be passed from the execution environment (these are typically known as command line arguments). The pointers argv[1] .. argv[argc-1] point at the first characters in each of these strings. argv[0] (if non-null) is the pointer to the initial character of a null-terminated multibyte strings that represents the name used to invoke the program itself (or, if this is not supported by the host environment, argv[0][0] is guaranteed to be zero). 
* The main function has several special properties: 
	* A prototype for this function cannot be supplied by the program
	* If the return type of the main function is compatible with int, then the return from the initial call to main (but not the return from any subsequent, recursive, call) is equivalent to executing the exit function,with the value that the main function is returning passed as the argument (which then calls the functions registered with atexit, flushes and closes all streams, and deletes the files created with tmpfile, and returns control to the execution environment).



### Objects and Alignment
* C programs create, destroy, access, and manipulate objects. 
* An object, in C, is region of data storage in the execution environment, the contents of which can represent values (a value is the meaning of the contents of an object, when interpreted as having a specific type).
* Every object has:
	*  size (can be determined with sizeof) 
	*  alignment requirement (can be determined by _Alignof) (since C11) 
	*  storage duration (automatic, static, allocated, thread-local) 
	*  lifetime (equal to storage duration or temporary) 
	*  effective type (see below) 
	*  value (which may be indeterminate) 
	*  optionally, an identifier that denotes this object 
* Objects are created by declarations, allocation functions(malloc etc), string literals, compound literals, and by non-lvalue expressions that return structures or unions with array members. 

#### alignment
* Every complete object type has a property called alignment requirement, which is an integer value of type size_t representing the number of bytes between successive addresses at which objects of this type can be allocated. The valid alignment values are non-negative integral powers of two.
* The alignment requirement of a type can be queried with _Alignof. 
* Each object type imposes its alignment requirement on every object of that type. The strictest (largest) fundamental alignment of any type is the alignment of max_align_t. The weakest (smallest) alignment is the alignment of the types char, signed char, and unsigned char, and equals 1.

#### lifetime
* Every object in C exists, has a constant address, retains its last-stored value (except when the value is indeterminate), and, for VLA, retains its size (since C99) over a portion of program execution known as this object's lifetime. 
* For the objects that are declared with automatic, static, and thread storage duration, lifetime equals their storage duration (note the difference between non-VLA and VLA automatic storage duration).
* For the objects with allocated storage duration, the lifetime begins when the allocation function returns and ends when the realloc or deallocation function is called.
* Note that since allocated objects have no declared type, the type of the lvalue expression first used to access this object becomes its effective type.
* A pointer to an object (or one past the object) whose lifetime ended has indeterminate value. 
* Struct and union objects with array members (either direct or members of nested struct/union members) that are designated by non-lvalue expressions, have temporary lifetime.
* Temporary lifetime begins when the expression that refers to such object is evaluated and ends at the next sequence point (until C11)when the containing full expression or full declarator ends (since C11). 
* Any attempt to modify an object with temporary lifetime results in undefined behavior. 

#### effective type
* Every object has an effective type, which determines which lvalue accesses are valid and which violate the strict aliasing rules. 
* If the object was created by a declaration, the declared type of that object is the object's effective type. 
* If the object was created by an allocation function (including realloc), it has no declared type. Such object acquires an effective type as follows: 
	*  The first write to that object through an lvalue that has a type other than character type, at which time the type of that lvalue becomes this object's effective type for that write and all subsequent reads. 
	*  memcpy or memmove copy another object into that object, at which time the effective type of the source object (if it had one) becomes the effective type of this object for that write and all subsequent reads.
	*  Any other access to the object with no declared type, the effective type is the type of the lvalue used for the access. 

#### strict aliasing
* Aliasing: Aliasing refers to the situation where the same memory location can be accessed using different names. For Example, if a function takes two pointers A and B which have the same value, then the name A[0] aliases the name B[0] i.e., we say the pointers A and B alias each other.  [^geek]
* Given an object with effective type T1, using an lvalue expression (typically, dereferencing a pointer) of a different type T2 is undefined behavior, unless: 
	* T2 and T1 are compatible types.
	* T2 is cvr-qualified version of a type that is compatible with T1.
	* T2 is a signed or unsigned version of a type that is compatible with T1.
	* T2 is an aggregate type or union type type that includes one of the aforementioned types among its members (including, recursively, a member of a subaggregate or contained union).
	* T2 is a character type (char, signed char, or unsigned char). 



#### object representation
* Except for bit fields, objects are composed of contiguous sequences of one or more bytes, each consisting of CHAR_BIT bits, and can be copied with memcpy into an object of type unsigned char[n], where n is the size of the object. The contents of the resulting array are known as object representation.

* If two objects have the same object representation, they compare equal (except if they are floating-point NaNs). The opposite is not true: two objects that compare equal may have different object representations because not every bit of the object representation needs to participate in the value. Such bits may be used for padding to satisfy alignment requirement, for parity checks, to indicate trap representations, etc. 
 
* If an object representation does not represent any value of the object type, it is known as trap representation

* For the objects of type char, signed char, and unsigned char, every bit of the object representation is required to participate in the value representation and each possible bit pattern represents a distinct value (no padding, trap bits, or multiple representations allowed). 

* When objects of integer types (short, int, long, long long) occupy multiple bytes, the use of those bytes is implementation-defined, but the two dominant implementations are big-endian and little-endian.







### Declaration/Defintion
* A **declaration** is a C language construct that introduces one or more identifiers into the program and specifies their meaning and properties. 

* A definition is a declaration that provides all information about the identifiers it declares.
	* Every declaration of an enum or a typedef is a definition.

	* For objects, a declaration that allocates storage (automatic or static, but not extern) is a definition, while a declaration that does not allocate storage (external declaration) is not.
	* For structs and unions, declarations that specify the list of members are definitions:
	 
#### functions
	* For functions, a declaration that includes the function body is a function definition: 
	* A function definition associates the function body (a sequence of declarations and statements) with the function name and parameter list. Unlike function declaration, function definitions are allowed at file scope only (there are no nested functions).
	* A function declaration introduces an identifier that designates a function and, optionally, specifies the types of the function parameters (the prototype). Function declarations (unlike definitions) may appear at block scope as well as file scope. 

### Initialization
* A declaration of an object may provide its initial value through the process known as initialization.  For each declarator, the initializer, if not omitted, may be one of the following: 
	*  = expression 
	*  = { initializer-list } 
		* expression
		*  { initializer-list } 
		*  designator-list = initializer 
* The initializer specifies the initial value stored in an object. 
	* explicit initialization
		* scalar initialization
		* array intitialization
		* struct initialization
	* implicit initialization
	* zero intialization


### Statement
* Statements are fragments of the C program that are executed in sequence. The body of any function is a compound statement, which, in turn is a sequence of statements and declarations. There are 5 types of statements:
	* compound statements:
	* expression statements
	* selection statements
	* iteration statements
	* jump statements
* LABELS:
	* Any statement can be labeled, by providing a name followed by a colon before the statement itself. 
		* identifier :			- target for goto
		* case constant-expression :	- case label in switch statement
		* default :			- default label in a switch statement

1. A **compound statement**, or block, is a brace-enclosed sequence of statements and declarations. Each compound statement introduces its own block scope. The initializers of the variables with automatic storage duration declared inside a block and the VLA declarators are executed when flow of control passes over these declarations in order, as if they were statements: 
	* { statement | declaration...(optional) } 
2. An **expression statement**, an expression followed by a semicolon is a statement. Most statements in a typical C program are expression statements, such as assignments or function calls. An expression statement without an expression is called a null statement. It is often used to provide an empty body to a for or while loop.
	* expression(optional) ; 
3. The **selection statements** choose between one of several statements depending on the value of an expression. 
	* if ( expression ) statement
	* if ( expression ) statement else statement
	* switch ( expression ) statement
4. The **iteration statements** repeatedly execute a statement. 
	* while ( expression ) statement
	* do statement while ( expression ) ;
	* for ( init-clause ; expression(optional) ; expression(optional) ) statement
5. The **jump statements** unconditionally transfer flow control. 
	
	
	
	1. break ;
		* Appears only within the statement of a loop body (while, do-while, for) or within the statement of a switch. 
		* Causes the enclosing for, while or do-while loop or switch statement to terminate. 
		* After this statement the control is transferred to the statement or declaration immediately following the enclosing loop or switch, as if by goto.



	2. continue ;
		* causes the remaining portion of the enclosing for, while or do-while loop body to be skipped. 
		* The continue statement causes a jump, as if by goto, to the end of the loop body (it may only appear within the loop body of for, while, and do-while loops). 



	3. return expression(optional) ; 	
		* Terminates current function and returns specified value to the caller function. 
		* Evaluates the expression, terminates the current function and returns the result of the expression to the caller (the value returned becomes the value of the function call expression). Only valid if the function return type is not void.
		* (no exression after return;) Terminates the current function. Only valid if the function return type is void.



	4. goto identifier ;
		* Transfers control unconditionally to the desired location. 
		* The goto statement causes an unconditional jump (transfer of control) to the statement prefixed by the named label (which must appear in the same function as the goto statement)




### Expression
* An expression is a sequence of operators and their operands, that specifies a computation.
* Expression evaluation may produce a result (e.g., evaluation of 2+2 produces the result 4), may generate side-effects (e.g. evaluation of printf("%d",4) sends the character '4' to the standard output stream), and may designate objects or functions.
* Overview
	* General:
		* Value Categories
		* Order of Evaluation
		* Operator Precedence
		* Alternative Representation
	* Conversions:
		* Implicit Conversion
		* Casts
	* Other:
		* Constant Expressions
		* Generic Sections
		* Floating-point Expressions
		* The Standard #Pragma
* Primary Expressions:
The operands of any operator may be other expressions or they may be primary expressions (e.g. in 1+2*3, the operands of operator+ are the subexpression 2*3 and the primary expression 1). 
	* Constants and literals (e.g. 2 or "Hello, world")
	* Suitably declared identifiers (e.g. n or printf)
	* Generic Selections
	* Any Expression in Parenthesis
* Constants and Literals
* Constant values of certain types may be embedded in the source code of a C program using specialized expressions known as literals (for lvalue expressions) and constants (for non-lvalue expressions) 
	* integer constants are decimal, octal, or hexadecimal numbers of integer type.
	* character constants are individual characters of type int suitable for conversion to a character type or of type char16_t, char32_t, or (since C11)wchar_t
	* floating constants are values of type float, double, or long double
	* string literals are sequences of characters of type char[], char16_t[] char32_t[], (since C11) or wchar_t[] that represent null-terminated strings
	* compound literals are values of struct, union, or array type directly embedded in program code 
* Unevaluated Expressions
* The operands of the sizeof operator are expressions that are not evaluated, Thus, size_t n = sizeof(printf("%d", 4)); does not perform console output. 






### Value Categories
* Each expression in C (an operator with its arguments, a function call, a constant, a variable name, etc) is characterized by two independent properties: a type and a value category. 
* Every expression belongs to one of three value categories:
	* lvalue
	* non-lvalue object (rvalue)
	* function designator. 

1. Lvalue expression is any expression with object type other than the type void, which potentially designates an object (the behavior is undefined if an lvalue does not actually designate an object when it is evaluated). In other words, lvalue expression evaluates to the object identity.
 
 
* Lvalue expressions can be used in the following lvalue contexts: 
	* as the operand of the address-of operator (except if the lvalue designates a bit field or was declared register).
	* as the operand of the pre/post increment and decrement operators.
	* as the left-hand operand of the member access (dot) operator.
	* as the left-hand operand of the assignment and compound assignment operators. 


* The following expressions are lvalues: 
	* identifiers, including function named parameters, provided they were declared as designating objects (not functions or enumeration constants)
	* string literals
	* (C99) compound literals
	* parenthesized expression if the unparenthesized expression is an lvalue
	* the result of a member access (dot) operator if its left-hand argument is lvalue
	* the result of a member access through pointer -> operator
	* the result of the indirection (unary *) operator applied to a pointer to object
	* the result of the subscription operator ([]) 


* A modifiable lvalue is any lvalue expression of complete, non-array type which is not const-qualified, and, if it's a struct/union, has no members that are const-qualified, recursively. Only modifiable lvalue expressions may be used as arguments to increment/decrement, and as left-hand arguments of assignment and compound assignment operators. 




2. Non-lvalue object expressions
Colloquially known as rvalues, non-lvalue object expressions are the expressions of object types that do not designate objects, but rather values that have no object identity or storage location. The address of a non-lvalue object expression cannot be taken. 

* The following expressions are non-lvalue object expressions: 
	* integer, character, and floating constants
	* all operators not specified to return lvalues, including 
		* any function call expression
		* any cast expression (note that compound literals, which look similar, are lvalues)
		* member access operator (dot) applied to a non-lvalue structure/union, f().x, (x,s1).a, (s1=s2).m
		* all arithmetic, relational, logical, and bitwise operators
		* increment and decrement operators
		* assignment and compound assignment operators
		* the conditional operator
		* the comma operator
		* the address-of operator, even it if is neutralized by being applied to the result of the unary * operator 
			  



3. Function designator expression
A function designator (the identifier introduced by a function declaration) is an expression of function type. When used in any context other than the address-of operator, sizeof, and _Alignof, the function designator is always converted to a non-lvalue pointer to function. Note that the function-call operator is defined for pointers to functions and not for function designators themselves. 
			  



### Operators
* assignment
* increment/decrement
* arithmetic
* logical
* comparison


### Member Access Operator
* Member access operators allow access to the members of their operands.
	* **Array Subscript** (a[b] - access the bth element of array a)
		* pointer-expression [ integer-expression ] 
		* integer-expression [ pointer-expression ] 
	* The **Dereference** or indirection expression (a* -  dereference the pointer a to access the object or function it refers to)
		*  * pointer-expression 
	* The **Address-of** expression (&a -  create a pointer that refers to the object or function a)
		*  & function
		*  & lvalue-expression 
	* The **Member Access** expression (a.b -  access member b of struct or union a)
		*  expression . member-name 
	* The member access expression (a->b -  access member b of struct or union pointed to by a)
		*  expression -> member-name 

 
 
### Other Operators
* function call:
	* f(...)
* comma operator:
	* a, b
* type cast:
	*  (type)a 
* conditional operator:
	*  a ? b : c 
* sizeof operator:
	*  sizeof a 
* _Alignof operator:
	*  _Alignof(type) 
 
 
 

---
[^lpi]: Written by [Michael Kerrisk](https://en.wikipedia.org/wiki/The_Linux_Programming_Interface)

[^kernel]: for [formatting](https://www.kernel.org/doc/html/v4.10/process/coding-style.html)
[^paging]: from [wikipedia](https://en.wikipedia.org/wiki/Memory_paging)
[^page]: from [wikipedia](https://en.wikipedia.org/wiki/Page_(computer_memory)
[^pagetable]: from [wikipedia](https://en.wikipedia.org/wiki/Page_table)
[^memseg]: taken from [uwm.edu](http://www.cs.uwm.edu/classes/cs315/Bacon/Lecture/HTML/ch10s04.html)
[^.code]: taken from [wikiepdia](https://en.wikipedia.org/wiki/Code_segment)
[^.data]: taken from [wikiepdia](https://en.wikipedia.org/wiki/Data_segment)
[^.bss]: taken from [wikipedia](https://en.wikipedia.org/wiki/.bss)
[^stack]: taken from [wikipedia](https://en.wikipedia.org/wiki/Call_stack) and [here](https://en.wikipedia.org/wiki/Stack-based_memory_allocation)
[^heap]: taken from [wikipedia](https://en.wikipedia.org/wiki/Memory_management) and [here](https://en.wikipedia.org/wiki/C_dynamic_memory_allocation)

[^reference]: [reference](https://en.cppreference.com/w/c/language/declarations)
[^geek]: taken from [geekforgeeks.org](https://www.geeksforgeeks.org/strict-aliasing-rule-in-c-with-examples/)
