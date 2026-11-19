#!/usr/bin/env bash
set -euo pipefail
make clean
make all
out=$(printf 'HELLO\n3\n' | ./bin/Q01)
grep -q 'KHOOR' <<<"$out"
out=$(printf '31\n' | ./bin/Q24)
grep -q '3031' <<<"$out"
out=$(printf '133457799BBCDFF1\n0123456789ABCDEF\n' | ./bin/Q33)
grep -q '85E813540F0AB405' <<<"$out"
echo "Build and known-answer smoke tests passed."
