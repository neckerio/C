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

## GDB
* info all-registers
* info registers
* display $esp
* layout regs
* x/s $rsp (hex)


---

## GCC

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

