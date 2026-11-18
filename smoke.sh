#!/usr/bin/env bash
set -euo pipefail
make
out=$(printf '22\n0\n0123\n509\n170\n0\n' | ./cryptolab)
grep -qi 'f40b' <<<"$out"
out=$(printf '23\n010204\n509\n0\n0\n' | ./cryptolab)
grep -qi '384f32' <<<"$out"
out=$(printf '24\n0\n' | ./cryptolab)
grep -q '3031' <<<"$out"
echo "Smoke tests passed."
