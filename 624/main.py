#!/usr/bin/env python3

import sys

while int(next(sys.stdin).strip()) != 0:
  m, t = 0, set()
  for n in map(int, next(sys.stdin).strip().split()):
    t.remove(n) if n in t else t.add(n)
    m = max(m, len(t))
  print(m)
