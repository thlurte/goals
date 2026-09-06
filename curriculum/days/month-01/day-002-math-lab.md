# 📐 Day 002 Math Lab: Proof Defense & Complete Live Q&A Session

**Date**: Sunday, September 6, 2026  
**Curriculum Module**: Block I (Vector Search Engine) · Week 01  
**Textbook Reference**: *Calculus* — Gilbert Strang (§2.1–§2.5)  
**Parent Daily Schedule**: [[day-002-2026-09-06|Day 002 Schedule]]

---

## 🧭 The Conceptual Roadmap

```text
1. LIMITS & ALGEBRAIC CANCELLATIONS (0/0)
   ├── Factoring & Canceling (Polynomials)
   ├── Conjugate Multiplications (Square Roots)
   └── Common Denominators (Fractions)
        │
        ▼
2. FIRST PRINCIPLES DERIVATIVE DEFINITION
   f'(x) = lim_{h -> 0} [f(x+h) - f(x)] / h
        │
        ▼
3. SHORTCUT DIFFERENTIATION RULES
   ├── Power Rule: d/dx [x^n] = n x^(n-1)
   ├── Product Rule: (u · v)' = u'v + uv'
   ├── Quotient Rule: (u / v)' = (u'v - uv') / v^2
   └── Chain Rule (Preview): d/dx [f(g(x))] = f'(g(x)) · g'(x)
```

---

## 🔹 Part 1: Official Proof Defenses (§2.1–§2.3)

### Proof 1: Power Rule for Cubics

**Theorem**: Prove $\frac{d}{dx}(x^3) = 3x^2$ directly using the limit of the difference quotient.

**Proof**:

$$f'(x) = \lim_{h \to 0} \frac{(x+h)^3 - x^3}{h}$$

Using the binomial expansion $(x+h)^3 = x^3 + 3x^2h + 3xh^2 + h^3$:

$$\begin{aligned}
f'(x) &= \lim_{h \to 0} \frac{(x^3 + 3x^2h + 3xh^2 + h^3) - x^3}{h} \\
      &= \lim_{h \to 0} \frac{3x^2h + 3xh^2 + h^3}{h} \\
      &= \lim_{h \to 0} \frac{h(3x^2 + 3xh + h^2)}{h} \\
      &= \lim_{h \to 0} (3x^2 + 3xh + h^2) \\
      &= 3x^2 + 3x(0) + (0)^2 = 3x^2 \quad \blacksquare
\end{aligned}$$

---

### Proof 2: Reciprocal Function Derivative

**Theorem**: Prove $\frac{d}{dx}\left(\frac{1}{x}\right) = -\frac{1}{x^2}$ for $x \ne 0$ from first principles.

**Proof**:

$$f'(x) = \lim_{h \to 0} \frac{\frac{1}{x+h} - \frac{1}{x}}{h}$$

Combine the numerator over the common denominator $x(x+h)$:

$$\text{Numerator} = \frac{x - (x+h)}{x(x+h)} = \frac{-h}{x(x+h)}$$

$$\begin{aligned}
f'(x) &= \lim_{h \to 0} \frac{\frac{-h}{x(x+h)}}{h} = \lim_{h \to 0} \frac{-1}{x(x+h)} = \frac{-1}{x(x+0)} = -\frac{1}{x^2} \quad \blacksquare
\end{aligned}$$

---

### Problem 3: Exact Tangent Line Calculation

**Problem**: Find the exact equation of the tangent line to $f(x) = x^4 - 2x^2 + 3$ at $x = -1$.

**Solution**:

1. **Point $(x_0, y_0)$**: $f(-1) = (-1)^4 - 2(-1)^2 + 3 = 1 - 2 + 3 = 2 \implies (-1, 2)$
2. **Slope $m = f'(-1)$**:

$$f'(x) = 4x^3 - 4x \implies f'(-1) = 4(-1)^3 - 4(-1) = -4 + 4 = 0$$

3. **Tangent Line Equation**:

$$y - y_0 = m(x - x_0) \implies y - 2 = 0(x - (-1)) \implies y = 2$$

---

## 🔹 Part 2: Product, Quotient & Radical Derivations (§2.4–§2.5)

### Proof 1: Product Rule from First Principles

**Theorem**: Prove $\frac{d}{dx}\left[u(x)v(x)\right] = u'(x)v(x) + u(x)v'(x)$.

**Proof**:

$$\frac{d}{dx}\left[u(x)v(x)\right] = \lim_{h \to 0} \frac{u(x+h)v(x+h) - u(x)v(x)}{h}$$

Add and subtract the cross-term $u(x+h)v(x)$ in the numerator:

$$\begin{aligned}
&= \lim_{h \to 0} \frac{u(x+h)v(x+h) - u(x+h)v(x) + u(x+h)v(x) - u(x)v(x)}{h} \\
&= \lim_{h \to 0} \left[ u(x+h) \cdot \frac{v(x+h) - v(x)}{h} \right] + \lim_{h \to 0} \left[ v(x) \cdot \frac{u(x+h) - u(x)}{h} \right] \\
&= u(x)v'(x) + v(x)u'(x) \quad \blacksquare
\end{aligned}$$

---

### Proof 2: Fractional Power Rule for $\sqrt{x}$ via Conjugates

**Theorem**: Derive $\frac{d}{dx}(\sqrt{x}) = \frac{1}{2\sqrt{x}} = \frac{1}{2}x^{-1/2}$ from first principles.

**Proof**:

$$\begin{aligned}
f'(x) &= \lim_{h \to 0} \frac{\sqrt{x+h} - \sqrt{x}}{h} \cdot \frac{\sqrt{x+h} + \sqrt{x}}{\sqrt{x+h} + \sqrt{x}} \\
      &= \lim_{h \to 0} \frac{(x+h) - x}{h(\sqrt{x+h} + \sqrt{x})} \\
      &= \lim_{h \to 0} \frac{h}{h(\sqrt{x+h} + \sqrt{x})} \\
      &= \lim_{h \to 0} \frac{1}{\sqrt{x+h} + \sqrt{x}} = \frac{1}{\sqrt{x} + \sqrt{x}} = \frac{1}{2\sqrt{x}} = \frac{1}{2}x^{-1/2} \quad \blacksquare
\end{aligned}$$

---

### Problem 3: Rational Function Stationary Point Analysis

**Problem**: For $R(x) = \frac{x^2 - 1}{x^2 + 1}$, find $R'(x)$, find horizontal tangent points ($R'(x) = 0$), and evaluate $R'(2)$.

**Solution**:

1. **Quotient Rule**:

$$R'(x) = \frac{(2x)(x^2 + 1) - (x^2 - 1)(2x)}{(x^2 + 1)^2} = \frac{2x^3 + 2x - 2x^3 + 2x}{(x^2 + 1)^2} = \frac{4x}{(x^2 + 1)^2}$$

2. **Horizontal Tangent ($R'(x) = 0$)**: $4x = 0 \implies x = 0$ (Point: $(0, -1)$).
3. **Evaluate $R'(2)$**:

$$R'(2) = \frac{4(2)}{(2^2 + 1)^2} = \frac{8}{25} = 0.32$$

---

## 📝 Section 3: Complete Live Q&A Practice Transcript

### 1. Direct 0/0 Limit via Factoring

* **Question Asked**: Evaluate $\lim_{x \to 3} \frac{x^2 - 9}{x - 3}$
* **Your Response / Working**:
  > *"for the first question i got intill lim x-> 3 x +3 now what"*
* **Solution**:

$$\lim_{x \to 3} (x + 3) = 3 + 3 = 6$$

---

### 2. Limit Definition on Polynomial Function

* **Question Asked**: Using $f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}$, find the derivative of $f(x) = 3x^2 - 4x$.
* **Your Response / Working**:
  > *"for the second i know the answer is 6x-4 but i dont how to get to it becahse i just simplified the question and got -8x+h over h"*
* **Error Diagnosis & Derivation**:
  * Expand: $f(x+h) = 3(x+h)^2 - 4(x+h) = 3x^2 + 6xh + 3h^2 - 4x - 4h$
  * Subtract $f(x)$: $(3x^2 + 6xh + 3h^2 - 4x - 4h) - (3x^2 - 4x) = 6xh + 3h^2 - 4h$  
    *(Sign note: $-4(x+h) - (-4x) = -4h$, eliminating the $-8x$ sign conflict).*
  * Divide by $h$ and take limit:

$$\lim_{h \to 0} (6x + 3h - 4) = 6x - 4$$

---

### 3. Conjugate Limit with Radicals

* **Question Asked**: Evaluate $\lim_{h \to 0} \frac{\sqrt{9 + h} - 3}{h}$
* **Your Response**:
  > *"is the answe 1/6"*
* **Verification**:

$$\lim_{h \to 0} \frac{(\sqrt{9+h}-3)(\sqrt{9+h}+3)}{h(\sqrt{9+h}+3)} = \lim_{h \to 0} \frac{h}{h(\sqrt{9+h}+3)} = \frac{1}{\sqrt{9}+3} = \frac{1}{6}$$

*(Verified Correct!)*

---

### 4. Common Denominators Limit

* **Question Asked**: Using the limit definition, find $f'(x)$ for $f(x) = \frac{1}{x + 1}$.
* **Solution**:

$$\lim_{h \to 0} \frac{\frac{1}{x+h+1} - \frac{1}{x+1}}{h} = \lim_{h \to 0} \frac{\frac{(x+1)-(x+h+1)}{(x+h+1)(x+1)}}{h} = \lim_{h \to 0} \frac{-1}{(x+h+1)(x+1)} = -\frac{1}{(x+1)^2}$$

---

### 5. Power Rule Practice (Negative & Fractional Exponents)

* **Problem A**: Differentiate $g(x) = 2x^5 + \frac{3}{x} - 4\sqrt{x} = 2x^5 + 3x^{-1} - 4x^{1/2}$
  * **Your Answer**: `10x^4 + 3x^-2 - 4x^-3/2`
  * **Corrections**:
    * $3x^{-1} \to 3(-1)x^{-2} = -3x^{-2}$
    * $-4x^{1/2} \to -4(1/2)x^{-1/2} = -2x^{-1/2}$
    * **Final Derivative**: $10x^4 - 3x^{-2} - 2x^{-1/2}$

* **Problem B**: Differentiate $h(x) = \frac{5}{x^3} + 6x^{1/3} = 5x^{-3} + 6x^{1/3}$
  * **Your Answer**: `15x^-4 + 18x^-2`
  * **Corrections**:
    * $5x^{-3} \to 5(-3)x^{-4} = -15x^{-4}$
    * $6x^{1/3} \to 6(1/3)x^{-2/3} = 2x^{-2/3}$
    * **Final Derivative**: $-15x^{-4} + 2x^{-2/3}$

* **Problem C**: Differentiate $y = 8x^{-2} + 12x^{1/4}$
  * **Your Answer**: `16x^-3 + 3x^3/4`
  * **Corrections**:
    * $8x^{-2} \to 8(-2)x^{-3} = -16x^{-3}$
    * $12x^{1/4} \to 12(1/4)x^{-3/4} = 3x^{-3/4}$
    * **Final Derivative**: $-16x^{-3} + 3x^{-3/4}$

---

### 6. Product Rule Practice

* **Question Asked**: Find the derivative of $g(x) = (3x^2 + 1)(4x - 2)$
* **Your Answer**:
  > `36x^2-12x+4`
* **Verification**:

$$(6x)(4x-2) + (3x^2+1)(4) = (24x^2-12x) + (12x^2+4) = 36x^2-12x+4$$

*(Status: 100% Correct!)*

---

### 7. Quotient Rule Practice

* **Question Asked**: Differentiate $f(x) = \frac{3x^2}{2x + 1}$
* **Your Answer**:
  > `6x^2+6x / ((2x+1)^2)`
* **Verification**:

$$\frac{(6x)(2x+1) - (3x^2)(2)}{(2x+1)^2} = \frac{6x^2+6x}{(2x+1)^2}$$

*(Status: 100% Correct!)*

---

### 8. Chain Rule Practice (Advanced Preview)

* **Problem A**: Differentiate $y = (4x^2 + 1)^3$
  * **Your Answer**: `24x(4x^2+1)^2`
  * **Verification**:

$$3(4x^2+1)^2 \cdot (8x) = 24x(4x^2+1)^2$$

*(Status: 100% Correct!)*

* **Problem B**: Differentiate $y = \sqrt{3x^2 + 4} = (3x^2 + 4)^{1/2}$
  * **Your Answer**: `3x(3x^2+4)^(-1/2)`
  * **Verification**:

$$\frac{1}{2}(3x^2+4)^{-1/2} \cdot (6x) = 3x(3x^2+4)^{-1/2}$$

*(Status: 100% Correct!)*
