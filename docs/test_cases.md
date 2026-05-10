# Expression Spec — 30 Test Cases

## Basic Arithmetic
```
01. 1 + 1                  → 2
02. 2 * (3 + 4)            → 14
03. 2^10                   → 1024
04. 10 / 4                 → 2.5
```

## Unit Conversion to SI
```
05. 1 km + 500 m           → 1500 m
06. 1 m + 100 cm           → 1.1 m
07. 1 kg + 500 g           → 1.5 kg
08. 1 h + 30 min           → 5400 s
09. 1 in + 1 cm            → 0.0354 m
10. 1e3 m + 1 km           → 2000 m
```

## Derived SI Units
```
11. 5 kg * 9.8 m/s^2       → 49 N
12. 10 N * 5 m             → 50 J
13. 100 J / 10 s           → 10 W
14. 50 N / 2 m^2           → 25 Pa
15. 1 / 0.5 s              → 2 Hz
16. 1 kg * m / s^2         → 1 N
```

## Equivalent Notation
```
17. 1 N + 1 kg*m/s^2       → 2 N
```

## Compound & Physics Expressions
```
18. (3 m/s)^2              → 9 m^2/s^2
19. 0.5 * 2 kg * (3 m/s)^2 → 9 J
20. 9.8 m/s^2 * 10 kg * 5 m → 490 J
21. 100 Pa * 2 m^2         → 200 N
```

## Math Functions
```
22. sin(pi / 2)            → 1
23. sin(0)                 → 0
```

## Edge Cases
```
24. -5 m + 10 m            → 5 m
25. 0 kg + 1 kg            → 1 kg
26. 1e-3 kg + 1 g          → 0.002 kg
27. 1e-9 m + 1 nm          → 2e-9 m
```

## Failures
```
28. 1 m + 1 s              → ERROR: dimension mismatch — cannot add [L] and [T]
29. 1 kg + 1 N             → ERROR: dimension mismatch — cannot add [M] and [M¹L¹T⁻²]
30. 1 / 0                  → ERROR: division by zero
31. 1 xyz                  → ERROR: unknown unit 'xyz'
32. sin(5 m)               → ERROR: argument to sin() must be dimensionless, got [L]
```
