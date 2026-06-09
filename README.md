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
$ zatanna Hello, World!
,olleH !dlroW

# Preserve punctuation order and normalize casing
$ zatanna -p -c Hello, World!
Olleh, Dlrow!

# multi-byte characters are supported
$ zatanna "こんにちは"
はちにんこ
```

## Installation

### Unix

This will request and run a script that clones this repository to a temporary directory and runs
`make install`.

```shell
curl -fsSL https://github.com/spenserblack/zatanna/raw/refs/heads/main/scripts/install.sh | sh
```

[dc-zatanna]: https://en.wikipedia.org/wiki/Zatanna

