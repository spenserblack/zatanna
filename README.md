# `zatanna`

## Description

A utility executable that prints the text of each
positional argument in reverse. Named after
[the DC character who speaks in reverse][dc-zatanna].

By default, each positional argument is printed
in reverse, but *order is maintained.* You can
reverse the order with `-O` or `--reverse-order`.

## Example

```console
$ zatanna HELLO WORLD
OLLEH DLROW

$ zatanna -O HELLO WORLD
DLROW OLLEH
```

[dc-zatanna]: https://en.wikipedia.org/wiki/Zatanna

