# t9-spelling
  _______ ___     _____            _ _ _
 |__   __/ _ \   / ____|          | | (_)
    | | | (_) | | (___  _ __   ___| | |_ _ __   __ _
    | |  \__, |  \___ \| '_ \ / _ \ | | | '_ \ / _` |
    | |    / /   ____) | |_) |  __/ | | | | | | (_| |
    |_|   /_/   |_____/| .__/ \___|_|_|_|_| |_|\__, |
                       | |                      __/ |
                       |_|                     |___/

This is a test application that translates a string of text into a sequence of numbers for input through T9. Now support only English, but you can add your dictionary ;)

Using is very simple:

```
$ t9-spelling "<message>"
```

This command will output digits sequence into console. 

Notes:
* The space symbol means a delay in entering.
* Punctuation marks are not supported.

## Dependencies

[Catch2](https://github.com/catchorg/Catch2) — header-only unit testing library. They add as git submodule to `${PROJECT_DIR}/third_party/`.

## Build

This project uses a CMake, so the build is very simple:

```
mkdir build && cd build
cmake ..
cmake --build .
cd ..
```

Binaries will be placed in `${PROJECT_DIR}/bin/`.

## Examples

```
$ t9-spelling "hello world"
  _______ ___     _____            _ _ _
 |__   __/ _ \   / ____|          | | (_)
    | | | (_) | | (___  _ __   ___| | |_ _ __   __ _
    | |  \__, |  \___ \| '_ \ / _ \ | | | '_ \ / _` |
    | |    / /   ____) | |_) |  __/ | | | | | | (_| |
    |_|   /_/   |_____/| .__/ \___|_|_|_|_| |_|\__, |
                       | |                      __/ |
                       |_|                     |___/

Input string is "hello world"
Result T9 sequence: 4433555 555666096667775553
```

```
  _______ ___     _____            _ _ _
 |__   __/ _ \   / ____|          | | (_)
    | | | (_) | | (___  _ __   ___| | |_ _ __   __ _
    | |  \__, |  \___ \| '_ \ / _ \ | | | '_ \ / _` |
    | |    / /   ____) | |_) |  __/ | | | | | | (_| |
    |_|   /_/   |_____/| .__/ \___|_|_|_|_| |_|\__, |
                       | |                      __/ |
                       |_|                     |___/

Oh no! We catch exception:
  "No expected symbol in dictionary 'number by symbol'. By first, check language of input message.".
Input string is "hello, world"
```

## Testing

For testing build the application and run command:

```
$ t9-spelling-test
```

Now I provide 9 test cases.

## License

MIT License

Copyright (c) 2018 Richard Elert

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
