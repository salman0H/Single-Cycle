# MIPS Instruction Simulator

## Overview

This C++ application is a comprehensive MIPS instruction simulator that can parse and execute different types of machine code instructions (R-type, I-type, and J-type). The simulator allows users to input a 32-bit machine code instruction and simulates its execution by manipulating a simulated register file.

## Features

- Supports three instruction types:
  - R-type (Register-type) instructions
  - I-type (Immediate-type) instructions
  - J-type (Jump-type) instructions
- Simulates various MIPS operations:
  - Arithmetic: ADD, SUB
  - Logical: AND, OR
  - Comparison: SLT (Set Less Than)
  - Memory: Load Word (LW), Store Word (SW)
  - Branch: BEQ, BNE
  - Immediate operations: ADDI, SLTI, ANDI, ORI
- Interactive machine code input
- Detailed output of register and operation details

## Supported Instructions

### R-type Instructions
- `add`: Addition
- `sub`: Subtraction
- `and`: Bitwise AND
- `or`: Bitwise OR
- `slt`: Set Less Than

### I-type Instructions
- `addi`: Add Immediate
- `slti`: Set Less Than Immediate
- `andi`: Bitwise AND Immediate
- `ori`: Bitwise OR Immediate
- `lw`: Load Word
- `sw`: Store Word
- `beq`: Branch if Equal
- `bne`: Branch if Not Equal

### J-type Instructions
- `jump`: Unconditional Jump

## Prerequisites

- C++ Compiler (g++)
- Standard C++ Libraries

## Compilation

```bash
g++ -o mips_simulator mips_simulator.cpp
```

## Usage

1. Compile the program
2. Run the executable
3. Enter a 32-bit machine code instruction when prompted
   - Use 0 and 1 to represent the binary instruction
   - Example: `00000010001100101000100000100000`

## Example Input Scenarios

- R-type ADD: `00000010001100101000100000100000`
- I-type ADDI: `00100010001100010000000000010100`
- J-type Jump: `00001000000000000000000000001010`

## Limitations

- Simulates a fixed set of MIPS instructions
- Uses a simplified register file initialization
- Does not support full MIPS instruction set
- Primarily for educational and demonstration purposes

## Learning Resources

- MIPS Instruction Set Architecture
- Computer Organization and Design
- Fundamentals of Computer Architecture

## Contributing

Contributions are welcome! Please submit pull requests or open issues.


## Author

Salman Hashemi
