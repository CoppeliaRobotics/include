#!/usr/bin/env python3

import sys
import re


def normalize_flags(s):
    s = s.strip()
    if s[0] == ',': s = s[1:]
    if s[-1] == ',': s = s[:-1]
    s = s.strip()
    r = ' | '.join(sorted([flag.strip() for flag in s.split('|')]))
    return r


def normalize_line(line):
    # Remove PropertyInfo({...})
    line = re.sub(r'PropertyInfo\(\{.*?\}\)', 'PropertyInfo(...)', line)

    line = re.sub(r', *sim_propertyinfo_\w+ *(\| *sim_propertyinfo_\w+ *)*,', lambda m: f', {normalize_flags(m.group(0))},', line)

    # Normalize whitespace
    line = re.sub(r'\s+', ' ', line).strip()

    return line


def line_key(line):
    """Return prefix up to the second comma."""
    parts = line.split(',', 2)
    if len(parts) >= 2:
        return ','.join(parts[:2]).strip()
    return line


def load_lines(filename):
    result = {}

    with open(filename, 'r', encoding='utf-8') as f:
        for raw in f:
            line = normalize_line(raw)
            if not line:
                continue

            key = line_key(line)

            # In case multiple lines have the same key, keep all
            result.setdefault(key, set()).add(line)

    return result


def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} file1 file2")
        sys.exit(1)

    file1, file2 = sys.argv[1], sys.argv[2]

    a = load_lines(file1)
    b = load_lines(file2)

    print("Differences:")

    for key in sorted(set(a) & set(b)):
        if a[key] != b[key]:
            print(f"\nKey: {key}")
            print(f"  {file1}:")
            for line in sorted(a[key]):
                print(f"    {line}")
            print(f"  {file2}:")
            for line in sorted(b[key]):
                print(f"    {line}")

    only_a = set(a) - set(b)
    only_b = set(b) - set(a)

    if only_a:
        print(f"\nOnly in {file1}:")
        for key in sorted(only_a):
            for line in sorted(a[key]):
                print(f"  {line}")

    if only_b:
        print(f"\nOnly in {file2}:")
        for key in sorted(only_b):
            for line in sorted(b[key]):
                print(f"  {line}")


if __name__ == "__main__":
    main()
