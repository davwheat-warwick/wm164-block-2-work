# Live Coding 15 - Recursion

## Recursion

> File encryption is the science of writing the contents of a file in a secret code. Your encryption program should work like a filter, reading the contents of one file, modifying the information into a code, and then writing the coded contents out to a second file. The second file will be a version of the first file but written in a secret code.
>
> Although there are complex encryption techniques, you should come up with a simple one of your own. For example, you could read the first file one character at a time and add 10 to the ASCII code of each character before it is written to the second file.

I implemented this with a Caesar Cipher. By default, this is set to an offset of 1, meaning it adds `1` to the ASCII value of every character. This can be configured at the top of `main.cpp`.
