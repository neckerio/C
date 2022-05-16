# Linkers and Loaders Notes

## Objective 
* Learn how Linkers and Loaders work

---

## Implementation

## Primary Sources
* [Linkers and Loaders by John R. Levine](https://www.johnlevine.com/books.phtml)

---

### Base
* Basic job of any linker or loader: to bind more abstract names to more concrete names, which permits programmers to write code using the more abstract names
	* It takes what the programmer typed and binds it to an address or location
	* The programmer types using symbolic names and the assembler binds the names to the machine addresses
* Linkers - handles address binding and assiging relative addresses in within each program
* Loader - handles the final relocation step to assign actual addresses
 
* Linkders and Loaders perform several related but conecptually separate actions:
	*  **Program loading** - copy program from secondary storage to main storage; sometimes just copying, other times involving allocating storage, setting protection bits or arranging for virtual memory to map virtual addresses to disk pages
	* **Relocation** - Compilers and assemblers generally create each file of object code with the program addresses starting at zero, but few computers let you load your program at location zero. If a program is created from multiple subprograms, all the subprograms have to be loaded at non-overlapping addresses. the process of assigning load addresses to the various parts of the program, adjusting code and data in the program to reflect assigned addresses. It’s quite common for a linker to create a program from multiple subprograms, and create one linked output program that starts at zero, with the various subprograms relocated to locations within the big program. Then when the program is loaded, the system picks the actual load address and the linked program is relocated as a whole to the load address
	* **Symbol Resolution** - When a program is built from multiple subpro- grams, the references from one subprogram to another are made using symbols; a main program might use a square root routine called sqrt, and the math library defines sqrt. A linker resolves the symbol by noting the location assigned to sqrt in the library, and patching the caller’s object code to so the call instruction referes to that location

* The program that does the loading is the LOADER, and the one that does the SYMBOL RESOLUTION is the LINKER.
* Both patch Object Code. 

#### linker
* Fundamentally a two pass process.
	* It takes as its input a set of Input Object Files, Libraries and maybe Command Files. It procudes an output Object File and maybe other information such as a Load Map or a file containing Debugger Symbols
		* each Input File contains a set of SEGMENTS.
		* each Input File contains at least one Symbol Table
* First it scans the Input Files to find the sizes of the segments and to collect the definitions and references to all of the Symbols. It creates a segment table listing all the SEGMENTS defined in the Input Files, and a Symbol Table with all of the SYMBOLS imported or exported
	* the Linker, using this information, assigns numeric locations to symbols, determines the size and location of the SEGEMENTS in the output address space, and places everything in the ouput file.
* The Second pass uses the information from the first pass to control the linking process
	* reads/relocates Object code.
	* substitutes numeric addresses for symbol references
	* adjusts memory addresses, refelcting relocated SEGEMENT addresses
	* writes relocated code to output file, generally with header information, relocated SEGMENTS, and Symbol Table information

 
#### object code libraries
* A library is little more than a set of Object Code Files.
* after the linker processes all the regular input files, if any imported names remain undefined, it runs through a Library/Libraries and links in any of the files in the library that export one or more undefined names


#### relocation and code modification
* The heart of a linker or loader’s actions is relocation and code modifica- tion. When a compiler or assembler generates an object file, it generates the code using the unrelocated addresses of code and data defined within the file, and usually zeros for code and data defined elsewhere. As part of the linking process, the linker modifies the object code to reflect the actual addresses assigned.
	* For example, consider this snippet of x86 code that moves the contents of variable a to variable b using the eax register.
		* mov a,%eax
		* mov %eax,b
	* If a is defined in the same file at location 1234 hex and b is imported from somewhere else, the generated object code will be:
		* A1 34 12 00 00 mov a,%eax
		* A3 00 00 00 00 mov %eax,b
	* Each instruction contains a one-byte operation code followed by a four- byte address. The first instruction has a reference to 1234 (byte reversed, since the x86 uses a right to left byte order) and the second a reference to zero since the location of b is unknown.
	* Now assume that the linker links this code so that the section in which a is located is relocated by hex 10000 bytes, and b turns out to be at hex 9A12.  The linker modifies the code to be:
		* A1 34 12 01 00 mov a,%eax
		* A3 12 9A 00 00 mov %eax,b
	* That is, it adds 10000 to the address in the first instruction so now it refers to a’s relocated address which is 11234, and it patches in the address for b. These adjustments affect instructions, but any pointers in the data part of an object file have to be adjusted as well.


#### compiler drivers
* it compiles each source file to assembler and then object code, and links together the object code, including any routines needed from the system C library
* 


### Architectural Issues
* two aspects of hardware architecture affect linkers: program addressing and instruction formats. 


#### application binary interface (ABI)
*

#### intel x86
* It features an asymmetrical instruction set and segmented addresses. There are six 32 bit general purpose registers named:
	* EAX
	* EBX
	* ECX
	* EDX
	* ESI
	* EDI
* as well as two registers used primarily for addressing:
	* EBP
	* ESP
* and six specialized 16 bit segment registers
	* CS
	* DS
	* ES
	* FS
	* GS
	* SS
* The low half of each of the 32 bit registers can be used as 16 bit registers called
	* AX
	* BX
	* CX
	* DX
	* SI
	* DI
	* BP
	* SP
* and the low and high bytes of each of the AX through DX registers are eight-bit registers called
	* AL
	* AH
	* BL
	* BH
	* CL
	* CH
	* DL
	* DH.
* On the 8086, 186, and 286, many instructions required its operands in specific registers, but on the 386 and later chips, most but not all of the functions that required specific registers have been generalized to use any register. The ESP is the hardware stack pointer, and always contains the address of the current stack. The EBP pointer is usually used as a frame register that points to the base of the current stack frame. (The instruction set encourages but doesn’t require this.)






