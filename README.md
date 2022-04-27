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

