# `zatanna`

[![CI](https://github.com/spenserblack/zatanna/actions/workflows/ci.yml/badge.svg)](https://github.com/spenserblack/zatanna/actions/workflows/ci.yml)

## Description

A utility executable that prints the text of each
positional argument in reverse. Named after
[the DC character who speaks in reverse][dc-zatanna].

By default, each positional argument is printed
in reverse, but *order is maintained.* You can
reverse the order with `-O` or `--reverse-order`.

Multi-byte characters characters are supported, and should still display properly when
reversed.

## Example

```console
$ zatanna HELLO WORLD
OLLEH DLROW

$ zatanna -O HELLO WORLD
DLROW OLLEH

# multi-byte characters are supported
$ zatanna "こんにちは"
はちにんこ
```

## Installation

1. Clone this repository
2. `cd` into the clone
3. `make install` or `sudo make install`

[dc-zatanna]: https://en.wikipedia.org/wiki/Zatanna

