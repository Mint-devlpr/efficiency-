# Efficiency
### *named after Mint. built on nothing but numbers.*

> "12345678 is a valid program. it breaks syntax. but it follows it."

---

## what is this

Efficiency is a parasitic, architecture-agnostic esoteric programming language built on 8 instructions and pure numbers.

no symbols. no english. no language barrier. just numbers that mean the same thing whether you're in tokyo, dublin, or on a piece of paper with a pencil.

it doesn't have a fixed architecture. it borrows whatever the host is running on. 32 bit host? Efficiency is 32 bit. 4 bit chip? Efficiency is 4 bit. 64 bit machine? Efficiency is already running 64 bit code. quantum computer? sure. it lives there now.

it started as a 64-bit CPU built inside Scrap Mechanic. before college. without studying computer science.

---

## instruction set

| number | instruction |
|--------|-------------|
| `1` | pointer up one |
| `2` | pointer down one |
| `3` | increase pointer value |
| `4` | decrease pointer value |
| `5` | start of loop |
| `6` | end of loop |
| `7` | jump to (pointer read value) |
| `8` | if (pointer value) == (next value) → jump to (2nd value) else → jump to (memory value based on 3rd value from pointer) |

8 instructions. instruction 8 is doing the work of an entire CPU feature and calling it normal.

---

## architecture

Efficiency is a **parasitic runtime**. it does not own an architecture. it inherits one.

- running on a 4 bit machine? Efficiency counts to 15 with you.
- running on a 32 bit machine? Efficiency counts to 4,294,967,295 with you.
- running on a 64 bit machine? Efficiency counts to 18,446,744,073,709,551,615 with you.
- running on whatever comes after that? Efficiency is already waiting.

write once. run on anything that has ever existed or will ever exist.

this is not a goal. this is already true.

---

## relation to brainfuck

Efficiency is brainfuck's estranged cousin.

brainfuck uses `>`, `<`, `+`, `-`, `[`, `]` and two I/O instructions with symbols.  
Efficiency uses `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8` with numbers.

the difference: numbers are universal. symbols are not. a number means the same thing in every language on earth. Efficiency code is readable by anyone who can count.

also instruction `8` exists. brainfuck doesn't have that. that's the efficiency part.

---

## bit width

Efficiency does not have opinions about bit width. the host has opinions about bit width. Efficiency simply agrees and gets on with it.

want to run 64 bit code? run Efficiency on a 64 bit machine. it's already done. you didn't have to do anything.

---

## goals

- [ ] ACE (Arbitrary Code Execution) in Scrap Mechanic without Lua
- [ ] run on a Casio ClassWiz
- [ ] full interpreter
- [ ] prove turing completeness formally (already obvious but still)
- [ ] run on a quantum computer just to say we did

---

## name

Efficiency is named after Mint, an OC. she is also parasitic. this is intentional.

the language is called Efficiency. the name on the tin is accurate.

---

## origin

> Axolot Games spent years unable to optimise underground mining physics in Scrap Mechanic.  
> while waiting, someone built a 64-bit CPU in the game instead.  
> then wrote an esoteric language to run on it.  
> then realised it could run on anything, at any bit width, on any architecture, ever.  
> this is that language.

---

*built before college. without computer science. on purpose.*
