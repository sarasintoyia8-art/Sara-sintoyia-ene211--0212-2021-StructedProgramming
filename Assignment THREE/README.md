Function returns NULL in error cases

Memory allocation fails and returns NULL

Buffer Overflows: When pointers are used to write beyond allocated memory boundaries, corrupting adjacent memory. This can:
Crash the program

Create security vulnerabilities

Cause unpredictable behavior

Pointer Arithmetic Errors: Incorrect calculations with pointer arithmetic can lead to accessing wrong memory locations, especially dangerous with array boundaries.
Mitigation Strategies: Always initialize pointers to NULL

Check for NULL before dereferencing

Use const qualifiers where appropriate

Implement comprehensive error checking

Follow consistent memory management patterns

Call by Value vs Call by Reference Comparison Call by Value: In this method, a copy of the argument's value is passed to the function. The function works with this local copy, and any modifications affect only the copy, not the original variable.
Characteristics:

Original data remains unchanged

Memory overhead from copying

Safer - no unintended side effects

Simpler to reason about

Example: Mathematical functions like sqrt(), sin() where inputs shouldn't be modified.

Call by Reference: In this method, the memory address of the argument is passed to the function. The function accesses the original variable through this pointer, allowing direct modification.

Characteristics:

Original data can be modified

Memory efficient - only address passed

Allows multiple "return" values via parameters

Risk of unintended modifications

Example: Functions that need to modify parameters like swap(), array sorting functions.

Data Passing Mechanism: Call by Value: Data is copied to function's parameter variables

Call by Reference: Address is copied, original data accessed indirectly

Performance Consideration: For small data types (int, char, float), call by value is efficient. For large structures or arrays, call by reference is significantly more efficient.

Practical Application Scenarios A. When Call by Value is Preferred:

Data Integrity Scenarios: When the original data must remain unchanged for consistency. For example, in financial calculations or database operations where accidental modification could cause serious issues.

Concurrent Programming: In multithreaded applications, call by value provides thread safety by giving each thread its own copy of data, preventing race conditions.

Simple Utility Functions: For small, self-contained operations like mathematical calculations (calculateArea(), convertTemperature()) where inputs are small and outputs are single values.

Read-Only Operations: When functions only need to examine data without modification, such as validation functions or data formatting routines.

B. When Call by Reference is Preferred:

Data Modification Requirements: When functions need to alter their parameters, such as sorting algorithms, data transformation functions, or initialization routines.

Large Data Structures: When passing structures containing hundreds of bytes or arrays with many elements, avoiding expensive copying operations.

Multiple Return Values: When a function needs to return more than one value, using pointer parameters as output arguments, common in operations that return both a result and status code.

Resource Management Functions: For functions that allocate, resize, or deallocate memory, where pointers to pointers are often needed to modify allocation pointers themselves.

Object-Oriented Style Operations: When implementing ADTs (Abstract Data Types) where functions act as methods operating on structured data.

Decision Framework: Use call by value when: data is small, no modification needed, safety is critical

Use call by reference when: data is large, modification needed, efficiency required

Hybrid Approach: Use const pointers for call by reference when you need efficiency but want to prevent modification, providing both performance and safety.
