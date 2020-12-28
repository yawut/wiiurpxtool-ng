# wiiurpxtool
Rewrite of [wiiurpxtool](https://github.com/0CBH0/wiiurpxtool) that works as a
library, using modern C++. Also allows library users to access the in-memory
representation of the RPX file, allowing it to be read and modified without
writing a decompressed file back to disk first.

# Dependencies
- zlib
- A C++20 capable compiler
- Applications using the library need to be built with C++17 or newer

# Credits
- Hykem (documentation and research of the RPL/RPX format)
- 0CBH0 (original wiiurpxtool)
