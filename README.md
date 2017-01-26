# MemDumpPlugin for x64dbg
## Installation
Copy bin/{x32, x64}/MemDumpPlugin.{dp32, dp64} to $x64dbg/{32,64}/Plugins/

## Usage
MemDumpPlugin address, length
e.g.
```
MemDumpPlugin rdx, r8
0000 08 02 00 00 10 66 00 00 20 00 00 00 9a 68 82 f6 
0010 af a1 4d 42 43 00 7b 9e b8 c8 99 db 7e a6 ac eb 
0020 38 74 d5 5c 15 05 f5 91 9e 29 be 50 
```
