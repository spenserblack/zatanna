#!/bin/sh
# This script clones this repository and runs `make install`
TEMP_DIR="$(mktemp -d)"
git clone https://github.com/spenserblack/zatanna.git "$TEMP_DIR"
cd "$TEMP_DIR"
make install
echo "Installed"
rm -rf "$TEMP_DIR"
