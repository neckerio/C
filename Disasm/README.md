# Disasm
* The very basics for debugging and GCC/GDB


## Sources
* [swansontec](https://www.swansontec.com/sregisters.html) for register names

---

### Register names
* EAX - Accumulator Register
* EBX - Base Register
* ECX - Counter Register
* EDX - Data Register
* ESI - Source Index
* EDI - Destination Index
* EBP - Base Pointer
* ESP - Stack Pointer


---

## GCC [^gcc]

### Useful Information
* Compilation can involve up to four stages: preprocessing, compilation proper, assembly and linking, always in that order. GCC is capable of preprocessing and compiling several files either into several assembler input files, or into one assembler input file; then each assembler input file produces an object file, and linking combines all the object files (those newly compiled, and those specified as input) into an executable file. 

* For any given input file, the file name suffix determines what kind of compilation is done: 
	* file.c - C source code that must be preprocessed.
	* file.i - C source code that should not be preprocessed.
	* file.h - C header file to be turned into a precompiled header (default), or C header file to be turned into an Ada spec (via the -fdump-ada-spec switch).

* You can specify the input language explicitly with the -x option: 
	* -x language

* If you only want some of the stages of compilation, you can use -x (or filename suffixes) to tell gcc where to start, and one of the options -c, -S, or -E to say where gcc is to stop. Note that some combinations (for example, ‘-x cpp-output -E’) instruct gcc to do nothing at all.
	* -c - Compile or assemble the source files, but do not link. The linking stage simply is not done. The ultimate output is in the form of an object file for each source file. By default, the object file name for a source file is made by replacing the suffix ‘.c’, ‘.i’, ‘.s’, etc., with ‘.o’. 
	* -S - Stop after the stage of compilation proper; do not assemble. The output is in the form of an assembler code file for each non-assembler input file specified. By default, the assembler file name for a source file is made by replacing the suffix ‘.c’, ‘.i’, etc., with ‘.s’. 
	* -E - Stop after the preprocessing stage; do not run the compiler proper. The output is in the form of preprocessed source code, which is sent to the standard output.



### Language Standards 
* -std=c89 -- select 89 standard
* -std=c99 -- select 99 standard
* -std=c11 -- select 2011 standard
* -std=c17 -- select 2017 standard
* -std=c2x -- select ~2022 standard
* -std=gnu90 -- select GNU 90 GCC extensions
* -std=gnu11 -- select GNU 2011 GCC extensions
* -std=gnu17 -- select GNU 2017 GCC extensions, the default
* -pedantic -- obtain all diagnostics required by the standard
* -pednantic-errors -- treat them as errors

* __STDC_HOSTED__ = hosted environment at 1
* -freestanding -- __STDC_HOSTED__ = freestanding environment at 0
* Most GCC routines at **libgcc**

*

---

## GDB [^gdb]
* info all-registers
* info registers
* display $esp
* layout regs
* x/s $rsp (hex)

#### chapter 2: getting in and out of gdb
* gdb PROG
* exit, quit, CTRL-D
* gdb -p 1234 (process)
* gdb -symbols FILE -- read symbols from file (-s)
* gdb -exec FILE -- use FILE as executable and for examining pure data (-e)
* gdb -x FILE -- execute commands from file exactly as source command would
* gdb -ex CMD -- execute a single GDB CMD
* gdb -readnow -- read entire symbol table immediately (-r)
* gdb --args -- args passed after executable are used as args
* gdb -statistics -- return stats about time/mem after each command completion
* gdb -configuration -- return details about buildtime config
* shell COMMAND -- exec commands from inside gdb

#### chapter 3: gdb commands
* step 5 -- sets # of executions
* CTRL-o -- chain command sequences
* RET -- repeat previous command

* INFO - describe state of your program (i)
* SET - assign result of EXPression 
* SHOW - describe state of GDB itself
* RUN - start program under GDB (r)

#### chapter 4: running programs under gdb
* START - run and stop at beginning of main procedure
* ADD-INFERIOR -- add inferior
* CLONE-INFERIOR -- clone
* REMOVE-INFERIOR -- remove
* CHECKPOINT -- save a snapshot of debugged programs current exec state
* RESTART CHECKPOINT ID -- restore previous checkpoint
* DELETE CHECKPOINT ID -- delete

#### chapter 5: stopping and continuing
* info program -- status of program
* BREAK -- stop at this point (b)
	* break LOCATION
	* break CONDITION -- break func if a == 10
	* info breakpoints
* WATCHPOINT -- stops program when value of expression changes
	* watch [-l|-location] expr 
	* rwatch [-l|-location] expr -- when value expr is READ
	* awatch [-l|-location] expr -- when value expr is either READ/WRITTEN
	* info watchpoints
* CATCHPOINT -- stops after certain event
	* catch EVENT
		* throw [regexp]
		* rethrow [regexp]
		* catch [regexp]
		* exception [regexp]
		* exec
		* syscall [name|number|g:groupname]
	* clear -- delete any breaks at instruction to be execed
	* clear LOCATION
	* delete BREAKPOINT -- specific or if empy ALL (d)
	* disable [breakpoints] -- all if empty
	* enable [breakpoints]
* DPRINTF
	* dprintf location,template,expression -- print out this stuff
* PROBES
	* info probes -- traces
	* enable probes
	* disable probes
* CONTINUE
	* continue -- resume program exec until completed normally (c)
	* continue fg -- foreground
* STEP
	* step -- continue program until it reaches a diff source line (s)
* NEXT
	* next -- continue to the next source line in current stack frame (n)
* FINISH
	* finish -- continue until just after func returns (fin)
* UNTIL
	* until -- until a source line passed current line, in current stack (u)
	* until LOCATION
* ADVANCE
	* advance -- similar to until, will NOT skip over recursive func calls and target location doesn't have to be in the same frame as the current one
	* advance LOCATION
* SKIP
	* skip -- skip over something
	* skip FUNC
	* skip RFUNC REGEXP
	* skip FILE
	* info skip
	* skip delete
	* skip enable
	* skip disable
* SIGNALS
	* signal 
	* info signals
	* info handle 
	* handle -- tell gdb what to do when SIG detected
		* nostop
		* stop
		* print
		* noprint
		* pass/noingore
		* nopass/ignore


#### chapter 6: running programs backward
* REVERSE-CONTINUE
	* exec in reverse from last stop (rc)
* REVERSE-STEP
	* run backwards until control reaches start of different source line
	* reverse-stepi -- by i number
* REVERSE-NEXT
	* run bacwards to the beginning of the previous line executed in innermost stack
	* reverse-nexti
* REVERSE-FINISH
	* run to the point of function call

#### chapter 7: recording inferior's executiona and replaying it
* RECORD METHOD
	* This command starts the process record and replay target. The recording method can be specified as parameter. Without a parameter the command uses the full recording method. The following recording methods are available:
		* full -- full record using gdb's software record/replay
		* btrace format -- hardware, intel, supported.
			* bts -- branch trace store
			* pt -- intel processor trace
		* record stop -- stop the process record and replay target
		* record goto -- specific location in exec log
			* record goto begin
			* record goto start
			* record goto end
			* record goto n
		* record save FILENAME
		* record restore FILENAME
		* info record
			* info record full
			* info record btrace
		* show record btrace/full
		* record delete
		* record stop

#### chapter 8: examining the stack
* STACK
* When your program has stopped, the first thing you need to know is where it stopped and
how it got there. Each time your program performs a function call, information about the call is generated. That information includes the location of the call in your program, the arguments of the call, and the local variables of the function being called. The information is saved in a block of data called a stack frame. The stack frames are allocated in a region of memory called the call stack.

* One of the stack frames is selected by gdb and many gdb commands refer implicitly
to the selected frame. In particular, whenever you ask gdb for the value of a variable in
your program, the value is found in the selected frame. There are special gdb commands to
select whichever frame you are interested in.

* The call stack is divided up into contiguous pieces called stack frames, or frames for short; each frame is the data associated with one call to one function. The frame contains the arguments given to the function, the function’s local variables, and the address at which the function is executing.

* When your program is started, the stack has only one frame, that of the function main. This is called the initial frame or the outermost frame. Each time a function is called, a new frame is made. Each time a function returns, the frame for that function invocation is eliminated. If a function is recursive, there can be many frames for the same function. The frame for the function in which execution is actually occurring is called the innermost frame. This is the most recently created of all the stack frames that still exist.

* Inside your program, stack frames are identified by their addresses. A stack frame consists of many bytes, each of which has its own address; each kind of computer has a convention for choosing one byte whose address serves as the address of the frame. Usually this address is kept in a register called the frame pointer register (see Section 10.14 [Registers], page 169) while execution is going on in that frame. gdb labels each existing stack frame with a level, a number that is zero for the innermost

* gdb labels each existing stack frame with a level, a number that is zero for the innermost frame, one for the frame that called it, and so on upward. These level numbers give you a way of designating stack frames in gdb commands. The terms frame number and frame level can be used interchangeably to describe this number.

* BACKTRACE
* A backtrace is a summary of how your program got where it is. It shows one line per frame, for many frames, starting with the currently executing frame (frame zero), followed by its caller (frame one), and on up the stack.  To print a backtrace of the entire stack, use the backtrace command, or its alias bt.  This command will print one line per frame for frames in the stack. By default, all stack frames are printed. You can stop the backtrace at any time by typing the system interrupt character, normally Ctrl-c.
* backtrace (bt)(where)(info stack)
	* backtrace n -- print innermost n frames
	* backgrace -n -- print outermost n frames
	* backtrace -full -- print values of local vars too
	* set print frame-info -- controls what frame information is printed
* FRAME
	* frame -- select stack frame (f)
	* fram n -- frame lvl num
	* frame address STACK-ADRESS
	* info frame -- find stack address etc. of frame
	* frame function FUNCTION -- frame for specific function
	* frame view STACK-ADDRESS
	* up n -- move up by n frames
	* down n
	* info frame
	* info args -- args to selected frame
	* info locals -- local vars in selected frame
	* frame apply [all|count|-count|level LEVEL] COMMAND
		* apply COMMAND to one or more frames
		* all -- apply to all frames
		* count -- command on the innermost count frames 
		* -count -- command on outermost count frames
		* level -- apply command on level list specified
		* -c -- continue, display errors then continues


#### chapter 9: examining source files
* LIST
	* list # -- print lines around point
	* list function -- print lines around a function
	* set listsize count -- set default
	* list LOCATION
	* list FUNCTION NAME
	* list *EXPRESSION -- for address
	* list &FUNCTION
* EDIT
	* edit LOCATION
	* edit NUMBER -- edit current file with NUMBER as active line number)
	* edit FUNCTION -- edit the file containing FUNCTION at the beginning of its definition
* SEARCH
	* forward-search REGEXP
	* reverse-search REGEXP
	
* INFO
	* info line LOCATION/NAME -- find location of OBJECT CODE)
	* info line *ADDR  -- to get the address *0x63ff)
	* diassemble (disas)  -- dump a range of memory as machine instructions
		* /m -- mixed source and disassembly
		* /s -- raw instructions in HEX
		* /r -- symbolic form

#### chapter 10: examining data
* PRINT (inspect)
	* print EXPRESSION
	* print /F -- print in F type format
	* PRINT CAN TAKE OPTION (--) MUST BE THERE
	* print -address -- STRCMP
	* print *array@LEN -- print contiguous memory of the same type LEN
	* set $i = 0
	* p/x -- binary representation of the value in hex
	* p/d -- binary representation of the value in decimal
	* p/u -- binary representation of the value in decimal as if unsigned
	* p/o -- binary representation of the value in octal
	* p/t -- binary representation of the value in binary (stands for 'two')
	* p/a -- binary representation of the value as an address:
		* absolute in hex AND
		* as an offset from nearest preceding symbol
	* p/c -- cast value to an INT
	* p/f -- regard bits as floating points and print them
	* p/s -- regard as a string if possible
	* p/z -- hex like 'x' but leading zeros are printed to pad the value size
* X (EXAMINE)
	* x -- examine memory in several different formats
	* x/nfu ADDER -- nfu are optional parameters. Defaults don't require /
		* n -- repeat count as a decimal int. Default 1
		* f -- display format. Same format specifiers as print AND
			* i -- machine instruction
			* m -- memory tags
		* u -- unit size:
			* b -- bytes
			* h -- halfwords 2 bytes
			* w -- words 4 bytes (initial default)
			* g -- giant words 8 bytes
		* ADDER -- usually just after last address examined
* AUTOMATIC DISPLAY
	* automatic display -- gdb prints expression each time the program stops
	* display EXPRESSION
	* display/fmt EXPRESSION -- output formats above
	* display/fm ADDR -- as a memory address
		* display/i $pc
	* undisplay DNUMS (delete display dnums)
	* display -- show current values in list
	* info display
* PRINT SETTINGS
	* set print address ON
		* prints memory addresses
	* and many other show/sets 
	* info pretty-printer
* VALUE HISTORY
	* values printed by PRINT command are saved in GDB value history
	* use '$' followed by values history number
	* show values
* CONVENIENCE VARIABLES
	* convenience variable, unless it is one of the predefined machine-specific 9). (Value history references, in contrast, are numbers preceded by ‘$’.
	* set $foo = *object_ptr
	* Using a convenience variable for the first time creates it, but its value is void until you assign a new value. You can alter the value with another assignment at any time.
	* show convenience
	* p $_siginfo -- extra signal information
	* p $_inferior -- number of current inferior
* CONVENIENCE FUNCTION
	* $_isvoid (EXPR) -- return 1 if expression is void
	* $_memeq (buff1,buff2,len) -- return 1 if LEN of bytes returned by buffs is ==
	* $_streq (str1,str2) -- return 1 if strings are equal
	* $_strlen(str) -- reutnr length of string
* REGISTERS
	* info registers -- print names/values of registers in stack frame
	* info all-registers -- same as above but INCLUDE vectors/floating-point regs
	* STANDARD REGISTER NAMES FOR GDB when available
		* $pc -- program counter
		* $sp -- stack pointer
		* $fp -- pointer to current stack frame
* FLOATING POINT HW/VECTOR UNIT and OS AUXILIARY INFORMATION
	* info float -- display hardware dependent info about the floating point unit
	* info vector -- display information about vector unit
	* info auxv -- display auxiliary vector of the inferior 
	* info os
		* cpus
		* files -- open file descriptors on the target
		* modules -- loaded by kernel
		* processes
		* procgroups -- process groups on traget
		* sockets -- internet-domain sockets on target
		* threads -- threads running on the target
* COPY BETWEEN MEMORY AND FILE
	* dump, append, restore copy between mem and file
* SEARCH MEMORY
	* find [/sn] start_addr, +len, val1 [, val2, ...]
	* find [/sn] start_addr, end_addr, val1 [, val2, ...]
	* start_addr, end_addr, val1 [, val2, ...] Search memory for the sequence of bytes specified by val1, val2, etc. The search begins at address start addr and continues for either len bytes or through to end addr inclusive.
	* /sn optional parameters
	* s, search query size 
		* b -- bytes
		* h -- halfwords (2 bytes)
		* w -- words (4 bytes)
		* g -- giantwords (8 bytes)
	* n, maximum number of fields to print(?)
	* EXAMPLES:
		* (gdb) find &hello[0], +sizeof(hello), "hello"
		* (gdb) find &hello[0], +sizeof(hello), ’h’, ’e’, ’l’, ’l’, ’o’
		* (gdb) find &hello[0], +sizeof(hello), {char[5]}"hello"
		* (gdb) find /b1 &hello[0], +sizeof(hello), ’h’, 0x65, ’l’
		
	


---

## Linking and Loading [^linkers]

### Useful Information



---
[^gcc]: provided by [GNU](https://gcc.gnu.org/onlinedocs/)
[^gdb]: provided by [GNU](https://www.sourceware.org/gdb/documentation/)
[^linkers]: Notes from [Linkers and Loaders by John R. Levine](https://www.johnlevine.com/books.phtml)
