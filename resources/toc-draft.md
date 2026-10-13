# TOC draft

Working notes. Not part of `systems_canon.md`. Headings below were copied from a publisher contents page, a library contents record, or a local PDF contents page in this session. Where a section title was not opened, it is marked **not yet copied** rather than filled in.

Sources named inline. Page numbers are the printed pages on that source.

## Numbering traps

These are places where the list in the request, or a day file, does not match the contents page.

1. **Strang, Calculus (Wellesley-Cambridge, 1991).** Author TOC at <https://math.mit.edu/~gs/books/calc_toc.html>. There is no §13.8. Lagrange multipliers are **§13.7 Constraints and Lagrange Multipliers**. Tangent planes are **§13.3**, not §13.4. §13.4 is Directional Derivatives and Gradients. §13.5 is The Chain Rule. The Jacobian of a coordinate change is inside **§14.2 Changing to Better Coordinates**, which is not titled Jacobians. §14.1 is Double Integrals. §14.3 is Triple Integrals. §14.4 is Cylindrical and Spherical Coordinates. Day 029's pair "§13.4 tangent planes, §13.5 chain rule/Jacobians" is off by one on the tangent-plane section, and it folds the Jacobian into §13.5.
2. **Vershynin.** The canon and the request cite the **2018** CUP book (ISBN 978-1-108-41519-4). In that printing the finite Johnson–Lindenstrauss lemma is **§5.3** (p. 110). A second JL statement, for infinite sets, is **§9.3** (p. 225). A **second edition** was published 19 February 2026 (CUP; free PDF at <https://www.math.uci.edu/~rvershyn/papers/HDP-book/HDP-2.pdf>, file dated 22 July 2026). The second edition drops standalone chapters 10 and 11 and moves JL into **§9.2**. Do not read a 2018 citation against the 2026 section numbers. The free PDF he labels "First Edition" (20 May 2024) is also not the 2018 pagination: its chapter 4 starts on p. 75, while the 2018 book starts chapter 4 on p. 70.
3. **Cover & Thomas, 2nd ed. (Wiley, 2006).** Rate distortion is **Chapter 10**. Quantization is §10.1, the definition of R(D) is §10.2, the Gaussian source is §10.3.2. The 1991 first edition, and the February 1992 solutions manual, use a different chapter order in which rate distortion sits later. A first-edition section number is not a second-edition section number.
4. **Horn & Johnson, Matrix Analysis, 2nd ed. (CUP, 2012).** The spectral theorem, the Courant–Fischer theorem, and the Rayleigh quotient are not their own section headings. Courant–Fischer and the Rayleigh quotient are inside **§4.2 Variational characterizations and subspace intersections** (p. 234). The spectral theorem for normal matrices is inside **§2.5 Normal matrices** (p. 131). Positive semidefinite matrices are **Chapter 7**. The SVD is **§2.6**. The CS decomposition is **§2.7**. Both were added in the second edition.
5. **Golub & Van Loan, 4th ed. (Johns Hopkins, 2013).** There is no section titled "Block GEMM". Block matrix multiplication is **§1.3 Block Matrices and Algorithms** (p. 22). Householder and Givens are **§5.1** (p. 234). The QR factorization is **§5.2** (p. 246).
6. **Nocedal & Wright, 2nd ed. (Springer, 2006).** KKT conditions are not a chapter title. They are inside **Chapter 12, Theory of Constrained Optimization** (pp. 304–354), principally the first-order optimality section. Quadratic programming is **Chapter 16** (p. 448). The Week 21 note that cites Chapters 12 and 16 matches this contents page.
7. **Pikus.** The book is **The Art of Writing Efficient Programs** (Packt, October 2021, ISBN 978-1-800-20811-7), not "The Art of Writing Efficient C++". Twelve chapters. Chapter 9 is **High-Performance C++**. Chapter 10 is **Compiler Optimizations in C++**. Chapter 11 is **Undefined Behavior and Performance**. Those titles are not "move semantics", `std::span`, or LTO. Chapter 1 is Introduction to Performance and Concurrency. Chapter 2 is Performance Measurements.
8. **Agner Fog, Optimizing software in C++.** Local PDF, last updated **2023-07-01**, 180 pages. Chapter 7 is **The efficiency of different C++ constructs**. §7.2 Integers variables and operators is pp. 29–30, which matches the Week 05 assignment. It is not an SIMD chapter. Chapter 8 is compiler optimizations. **Chapter 11 is Out of order execution, pp. 113–114, with no subsections in the contents.** Chapter 12, Using vector operations, starts on p. 115 (AVX, AVX-512, intrinsics). `_mm256_subs_epu8`, port 0/1/5, and instruction latencies are not section titles of this manual. **Instruction tables** is a separate PDF, organized by microarchitecture, not by chapters 7, 8, 11, 12. The assembly manual is a third PDF.
9. **Hennessy & Patterson.** The request says **6th ed.** `resources/systems_canon.md` cites the **7th ed. (Elsevier, 2024)**. They are not the same contents. The 7th-edition chapter list was not copied in this pass.
10. **Gelfand & Saul, Trigonometry (Birkhäuser, 2001).** Ten body chapters, Springer DOI 10.1007/978-1-4612-0149-6. The opening chapter is titled Trigonometry (pp. 1–20). Law of sines is inside Chapter 3 (the front-matter contents puts it at p. 71). Law of cosines is the same chapter (p. 78). Addition formulas are **Chapter 6** (pp. 123–137). Identities, including double-angle material, are **Chapter 7** (pp. 139–171). No contents line is titled "double-angle" or "unit circle" by those words. Unit-circle material is Chapter 4, Angles and Rotations, and Chapter 5, Radian Measure.
11. **Granlund & Montgomery.** The printed title is **Division by Invariant Integers using Multiplication**. The canon title "Fast Integer Division by Constants Using Multiplication" is not on the PDF. No PLDI banner is on the copy that was opened.
12. **Chou, Fahs, Abraham, MLP.** The opened PDF prints the third author as **Santosh Abraham** (Sun Microsystems). The canon says Sanjay J. Patel.
13. **DiskANN.** The NeurIPS 2019 PDF title is **Billion-point**, not the canon's "Billion-Scale".
14. **RaBitQ.** The printed title continues past "with a Bit": **RaBitQ: Quantizing High-Dimensional Vectors with a Theoretical Error Bound for Approximate Nearest Neighbor Search** (SIGMOD 2024).
15. **CAGRA.** The arXiv title is **CAGRA: Highly Parallel Graph Construction and Approximate Nearest Neighbor Search for GPUs**. The canon's "Highly Efficient GPU Graph-Based Approximate Nearest Neighbors Search" is not the printed title.
16. **Roofline.** The opened document is Berkeley tech report UCB/EECS-2008-134 (17 October 2008), not the CACM 2009 typesetting. Its title adds **for Floating-Point Programs and**.
17. **HNSW.** The opened arXiv PDF is a manuscript whose footnote says it has been submitted to IEEE. It is not the typeset TPAMI 2018 issue. The 2006 TAGE paper already contains its own **§5 ITTAGE** and **§6 COTTAGE**. The 2011 CBP note is a separate 64 KB ITTAGE submission.
18. **ScaNN.** "ScaNN" is not in the printed title. The title is **Accelerating Large-Scale Inference with Anisotropic Vector Quantization**.
19. **Linux NUMA page.** The opened page is titled **NUMA Memory Performance**, with three headings: NUMA Locality, NUMA Performance, NUMA Cache. The canon title "NUMA Memory Management in Linux" is not the page title.
20. **ViT and BERT dates.** The request dates ViT 2020 and BERT 2018. Those are the arXiv years (2010.11929 and 1810.04805). The conference versions are ICLR 2021 and NAACL 2019. Those venue lines were not in the ar5iv title blocks that were read.

## Books in `systems_canon.md` that the request did not list

- Knuth, *The Art of Computer Programming*, Vol. 3, *Sorting and Searching*, 2nd ed. (1998).
- Jaynes, *Probability Theory: The Logic of Science* (CUP, 2003).
- Kirk & Hwu, *Programming Massively Parallel Processors*, 4th ed. (Morgan Kaufmann, 2022).
- NVIDIA CUDA C++ Programming Guide, and CUTLASS (a library, not a book).
- FlashAttention-2 (Dao, ICLR 2024), which the canon files under GPU systems rather than under the vector-search paper list.
- The microarchitecture papers in canon sections 2–5 (TAGE, Tomasulo, store sets, Yasin's top-down method, and the rest). Those are papers, listed at the end.

Papers named in the request that are **not** in canon section 8: Vaswani et al. 2017, Dosovitskiy et al. 2020, Devlin et al. 2018. Roofline is in canon section 4, not only in the request's paper list.

---

## 1. Gilbert Strang — Calculus

Wellesley-Cambridge Press, 1991. Source: <https://math.mit.edu/~gs/books/calc_toc.html>. Also: answers to odd-numbered problems, index, table of integrals.

1. Introduction to Calculus — 1.1 Velocity and Distance; 1.2 Calculus Without Limits; 1.3 The Velocity at an Instant; 1.4 Circular Motion; 1.5 A Review of Trigonometry; 1.6 A Thousand Points of Light; 1.7 Computing in Calculus
2. Derivatives — 2.1 The Derivative of a Function; 2.2 Powers and Polynomials; 2.3 The Slope and the Tangent Line; 2.4 Derivative of the Sine and Cosine; 2.5 The Product and Quotient and Power Rules; 2.6 Limits; 2.7 Continuous Functions
3. Applications of the Derivative — 3.1 Linear Approximation; 3.2 Maximum and Minimum Problems; 3.3 Second Derivatives: Minimum vs Maximum; 3.4 Graphs; 3.5 Ellipses, Parabolas and Hyperbolas; 3.6 Iterations; 3.7 Newton's Method and Chaos; 3.8 The Mean Value Theorem and l'Hôpital's Rule
4. The Chain Rule — 4.1 Derivatives by the Chain Rule; 4.2 Implicit Differentiation and Related Rates; 4.3 Inverse Functions and Their Derivatives; 4.4 Inverses of Trigonometric Functions
5. Integrals — 5.1 The Idea of the Integral; 5.2 Antiderivatives; 5.3 Summation vs Integration; 5.4 Indefinite Integrals and Substitutions; 5.5 The Definite Integral; 5.6 Properties of the Integral and the Average Value; 5.7 The Fundamental Theorem; 5.8 Numerical Integration
6. Exponentials and Logarithms — 6.1 An Overview; 6.2 The Exponential e^x; 6.3 Growth and Decay in Science and Economics; 6.4 Logarithms; 6.5 Separable Equations Including the Logistic Equation; 6.6 Powers Instead of Exponentials; 6.7 Hyperbolic Functions
7. Techniques of Integration — 7.1 Integration by Parts; 7.2 Trigonometric Integrals; 7.3 Trigonometric Substitutions; 7.4 Partial Fractions; 7.5 Improper Integrals
8. Applications of the Integral — 8.1 Areas and Volumes by Slices; 8.2 Length of a Plane Curve; 8.3 Area of a Surface of Revolution; 8.4 Probability and Calculus; 8.5 Masses and Moments; 8.6 Force, Work, and Energy
9. Polar Coordinates and Complex Numbers — 9.1 Polar Coordinates; 9.2 Polar Equations and Graphs; 9.3 Slope, Length, and Area for Polar Curves; 9.4 Complex Numbers
10. Infinite Series — 10.1 The Geometric Series; 10.2 Convergence Tests: Positive Series; 10.3 Convergence Tests: All Series; 10.4 Taylor Series for e^x, sin x, and cos x; 10.5 Power Series
11. Vectors and Matrices — 11.1 Vectors and Dot Products; 11.2 Planes and Projections; 11.3 Cross Products and Determinants; 11.4 Matrices and Linear Equations; 11.5 Linear Algebra in Three Dimensions
12. Motion Along a Curve — 12.1 The Position Vector; 12.2 Plane Motion: Projectiles and Cycloids; 12.3 Tangent Vector and Normal Vector; 12.4 Polar Coordinates and Planetary Motion
13. Partial Derivatives — 13.1 Surfaces and Level Curves; 13.2 Partial Derivatives; 13.3 Tangent Planes and Linear Approximations; 13.4 Directional Derivatives and Gradients; 13.5 The Chain Rule; 13.6 Maxima, Minima, and Saddle Points; 13.7 Constraints and Lagrange Multipliers
14. Multiple Integrals — 14.1 Double Integrals; 14.2 Changing to Better Coordinates; 14.3 Triple Integrals; 14.4 Cylindrical and Spherical Coordinates
15. Vector Calculus — 15.1 Vector Fields; 15.2 Line Integrals; 15.3 Green's Theorem; 15.4 Surface Integrals; 15.5 The Divergence Theorem; 15.6 Stokes' Theorem and the Curl of F
16. Mathematics After Calculus — 16.1 Linear Algebra; 16.2 Differential Equations; 16.3 Discrete Mathematics

## 2. Gelfand & Saul — Trigonometry

Birkhäuser, 2001. x+229 pages. Springer contents: <https://link.springer.com/book/10.1007/978-1-4612-0149-6>. Section titles below are the ones visible in the front-matter PDF `bfm:978-1-4612-0149-6/1`. Later sections of chapters 6–9 were cut off on that fetch and are **not yet copied**.

- Preface
- Ch. Trigonometry (pp. 1–20): What is new about trigonometry?; Right triangles; The Pythagorean theorem; Our best friends (among right triangles); Our next best friends (among right triangles); Some standard notation
- Ch. Trigonometric Ratios in a Triangle (pp. 21–39): Definition of sin α; Find the hidden sine; The cosine ratio; A relation between the sine and the cosine; A bit of notation; Another relation between the sine and the cosine; Our next best friends (and the sine ratio); further sections through "Another approach to the sine ratio" (p. 57) were only partly visible
- Ch. Relations among Trigonometric Ratios (pp. 41–66). Section titles **not yet copied**.
- Ch. Relationships in a Triangle (pp. 67–90): Geometry of the triangle; The congruence theorems and trigonometry; Sines and altitudes; Obtuse triangles; The Law of Sines (p. 71); The circumradius (p. 74); Area of a triangle (p. 75); Two remarks (p. 78); Law of cosines (p. 78)
- Ch. Angles and Rotations (pp. 91–102): Measuring rotations; Rotation and angles; Trigonometric functions for all angles; Calculations with angles of rotations; Odd and even functions
- Ch. Radian Measure (pp. 103–122): Radian measure for angles and rotations; Radian measure and distance; Interlude: How to explain radian measure to your brother and sister; Radian measure and calculators. Further sections **not yet copied**.
- Ch. The Addition Formulas (pp. 123–137). Section titles **not yet copied**.
- Ch. Trigonometric Identities (pp. 139–171). Section titles **not yet copied**.
- Ch. Graphs of Trigonometric Functions (pp. 173–206). Section titles **not yet copied**.
- Ch. Inverse Functions and Trigonometric Equations (pp. 207–229). Section titles **not yet copied**.

## 3. Horn & Johnson — Matrix Analysis, 2nd ed.

CUP, October 2012. ISBN 978-0-521-83940-2. Section list from the contents pages reproduced by the German National Library record and the second-edition front matter. Preface to the second edition, p. xi. Preface to the first edition, p. xv. Appendix F is on the CUP contents page and in the front-matter dump (Canonical pairs, p. 567).

- 0 Review and Miscellanea (1): 0.0 Introduction; 0.1 Vector spaces; 0.2 Matrices; 0.3 Determinants; 0.4 Rank; 0.5 Nonsingularity; 0.6 The Euclidean inner product and norm; 0.7 Partitioned sets and matrices; 0.8 Determinants again; 0.9 Special types of matrices; 0.10 Change of basis; 0.11 Equivalence relations
- 1 Eigenvalues, Eigenvectors, and Similarity (43): 1.0 Introduction; 1.1 The eigenvalue–eigenvector equation; 1.2 The characteristic polynomial and algebraic multiplicity; 1.3 Similarity; 1.4 Left and right eigenvectors and geometric multiplicity
- 2 Unitary Similarity and Unitary Equivalence (83): 2.0 Introduction; 2.1 Unitary matrices and the QR factorization; 2.2 Unitary similarity; 2.3 Unitary and real orthogonal triangularizations; 2.4 Consequences of Schur's triangularization theorem; 2.5 Normal matrices (131); 2.6 Unitary equivalence and the singular value decomposition (149); 2.7 The CS decomposition (159)
- 3 Canonical Forms for Similarity and Triangular Factorizations (163): 3.0 Introduction; 3.1 The Jordan canonical form theorem; 3.2 Consequences of the Jordan canonical form; 3.3 The minimal polynomial and the companion matrix; 3.4 The real Jordan and Weyr canonical forms; 3.5 Triangular factorizations and canonical forms
- 4 Hermitian Matrices, Symmetric Matrices, and Congruences (225): 4.0 Introduction; 4.1 Properties and characterizations of Hermitian matrices (227); 4.2 Variational characterizations and subspace intersections (234); 4.3 Eigenvalue inequalities for Hermitian matrices (239); 4.4 Unitary congruence and complex symmetric matrices; 4.5 Congruences and diagonalizations; 4.6 Consimilarity and condiagonalization
- 5 Norms for Vectors and Matrices (313): 5.0 Introduction; 5.1 Definitions of norms and inner products; 5.2 Examples of norms and inner products; 5.3 Algebraic properties of norms; 5.4 Analytic properties of norms; 5.5 Duality and geometric properties of norms; 5.6 Matrix norms; 5.7 Vector norms on matrices; 5.8 Condition numbers: inverses and linear systems
- 6 Location and Perturbation of Eigenvalues (387): 6.0 Introduction; 6.1 Geršgorin discs; 6.2 Geršgorin discs — a closer look; 6.3 Eigenvalue perturbation theorems; 6.4 Other eigenvalue inclusion sets
- 7 Positive Definite and Semidefinite Matrices (425): 7.0 Introduction; 7.1 Definitions and properties (429); 7.2 Characterizations and properties (438); 7.3 The polar and singular value decompositions (448); 7.4 Consequences of the polar and singular value decompositions; 7.5 The Schur product theorem; 7.6 Simultaneous diagonalizations, products, and convexity; 7.7 The Loewner partial order and block matrices; 7.8 Inequalities involving positive definite matrices
- 8 Positive and Nonnegative Matrices (517): 8.0 Introduction; 8.1 Inequalities and generalities; 8.2 Positive matrices; 8.3 Nonnegative matrices; 8.4 Irreducible nonnegative matrices; 8.5 Primitive matrices; 8.6 A general limit theorem; 8.7 Stochastic and doubly stochastic matrices
- Appendix A Complex Numbers (555)
- Appendix B Convex Sets and Functions (557)
- Appendix C The Fundamental Theorem of Algebra (561)
- Appendix D Continuity of Polynomial Zeroes and Matrix Eigenvalues (563). The CUP website shortens this title to "Continuous dependence of the zeroes of a polynomial on its coefficients."
- Appendix E Continuity, Compactness, and Weierstrass's Theorem (565)
- Appendix F Canonical Pairs (567)
- References, notation, hints, index follow.

Separate book, not this TOC: Horn & Johnson, *Topics in Matrix Analysis* (CUP, 1991/1994). Field of values, stable matrices, singular-value inequalities, Kronecker products, Hadamard products.

## 4. Golub & Van Loan — Matrix Computations, 4th ed.

Johns Hopkins University Press, 2013. xxi+756 pages. ISBN 978-1-4214-0794-4. Section titles from the Johns Hopkins contents page and the ETH Zurich contents PDF. Front matter: Preface; Global References; Other Books; Useful URLs; Common Notation.

- 1 Matrix Multiplication (1): 1.1 Basic Algorithms and Notation (2); 1.2 Structure and Efficiency (14); 1.3 Block Matrices and Algorithms (22); 1.4 Fast Matrix-Vector Products (33); 1.5 Vectorization and Locality (43); 1.6 Parallel Matrix Multiplication (49)
- 2 Matrix Analysis (63): 2.1 Basic Ideas from Linear Algebra (64); 2.2 Vector Norms (68); 2.3 Matrix Norms (71); 2.4 The Singular Value Decomposition (76); 2.5 Subspace Metrics (81); 2.6 The Sensitivity of Square Systems (87); 2.7 Finite Precision Matrix Computations (93)
- 3 General Linear Systems (105): 3.1 Triangular Systems (106); 3.2 The LU Factorization (111); 3.3 Roundoff Error in Gaussian Elimination (122); 3.4 Pivoting (125); 3.5 Improving and Estimating Accuracy (137); 3.6 Parallel LU (144)
- 4 Special Linear Systems (153): 4.1 Diagonal Dominance and Symmetry (154); 4.2 Positive Definite Systems (159); 4.3 Banded Systems (176); 4.4 Symmetric Indefinite Systems (186); 4.5 Block Tridiagonal Systems (196); 4.6 Vandermonde Systems (203); 4.7 Classical Methods for Toeplitz Systems (208); 4.8 Circulant and Discrete Poisson Systems (219)
- 5 Orthogonalization and Least Squares (233): 5.1 Householder and Givens Transformations (234); 5.2 The QR Factorization (246); 5.3 The Full-Rank Least Squares Problem (260); 5.4 Other Orthogonal Factorizations (274); 5.5 The Rank-Deficient Least Squares Problem (288); 5.6 Square and Underdetermined Systems (298)
- 6 Modified Least Squares Problems and Methods (303): 6.1 Weighting and Regularization (304); 6.2 Constrained Least Squares (313); 6.3 Total Least Squares (320); 6.4 Subspace Computations with the SVD (327); 6.5 Updating Matrix Factorizations (334)
- 7 Unsymmetric Eigenvalue Problems (347): 7.1 Properties and Decompositions (348); 7.2 Perturbation Theory (357); 7.3 Power Iterations (365); 7.4 The Hessenberg and Real Schur Forms (376); 7.5 The Practical QR Algorithm (385); 7.6 Invariant Subspace Computations (394); 7.7 The Generalized Eigenvalue Problem (405); 7.8 Hamiltonian and Product Eigenvalue Problems (420); 7.9 Pseudospectra (426)
- 8 Symmetric Eigenvalue Problems (439): 8.1 Properties and Decompositions (440); 8.2 Power Iterations (450); 8.3 The Symmetric QR Algorithm (458); 8.4 More Methods for Tridiagonal Problems (467); 8.5 Jacobi Methods (476); 8.6 Computing the SVD (486); 8.7 Generalized Eigenvalue Problems with Symmetry (497)
- 9 Functions of Matrices (513): 9.1 Eigenvalue Methods (514); 9.2 Approximation Methods (522); 9.3 The Matrix Exponential (530); 9.4 The Sign, Square Root, and Log of a Matrix (536)
- 10 Large Sparse Eigenvalue Problems (545): 10.1 The Symmetric Lanczos Process (546); 10.2 Lanczos, Quadrature, and Approximation (556); 10.3 Practical Lanczos Procedures (562); 10.4 Large Sparse SVD Frameworks (571); 10.5 Krylov Methods for Unsymmetric Problems (579); 10.6 Jacobi-Davidson and Related Methods (589)
- 11 Large Sparse Linear System Problems (597): 11.1 Direct Methods (598); 11.2 The Classical Iterations (611); 11.3 The Conjugate Gradient Method (625); 11.4 Other Krylov Methods (639); 11.5 Preconditioning (650); 11.6 The Multigrid Framework (670)
- 12 Special Topics (681): 12.1 Linear Systems with Displacement Structure (681); 12.2 Structured-Rank Problems (691); 12.3 Kronecker Product Computations (707); 12.4 Tensor Unfoldings and Contractions (719); 12.5 Tensor Decompositions and Iterations (731)
- Index (747)

## 5. Nocedal & Wright — Numerical Optimization, 2nd ed.

Springer, 2006. ISBN 978-0-387-30303-1. Chapter list from the Springer page and the Library of Congress contents. New in the second edition, by the publisher's note: derivative-free optimization, and interior-point methods for nonlinear programming. Section titles were opened for Chapters 1–3 and 18–19 only (CERN contents PDF). The other chapters are chapter-level here.

- Preface; Preface to the Second Edition
- 1 Introduction (1). Unnumbered subsections: Mathematical Formulation (2); Example: A Transportation Problem (4); Continuous versus Discrete Optimization (5); Constrained and Unconstrained Optimization (6); Global and Local Optimization (6); Stochastic and Deterministic Optimization (7); Convexity (7); Optimization Algorithms (8); Notes and References (9)
- 2 Fundamentals of Unconstrained Optimization (10): 2.1 What Is a Solution? (12), including Recognizing a Local Minimum (14) and Nonsmooth Problems (17); 2.2 Overview of Algorithms (18), including line search vs trust region, search directions, trust-region models, scaling
- 3 Line Search Methods (30): 3.1 Step Length (Wolfe, Goldstein, sufficient decrease and backtracking); 3.2 Convergence of Line Search Methods; 3.3 Rate of Convergence (steepest descent, Newton, quasi-Newton); 3.4 Newton's Method with Hessian Modification
- 4 Trust-Region Methods (66)
- 5 Conjugate Gradient Methods (101)
- 6 Quasi-Newton Methods (135)
- 7 Large-Scale Unconstrained Optimization (164). Opened subsections: 7.1 Inexact Newton Methods; 7.2 Limited-Memory Quasi-Newton Methods (L-BFGS)
- 8 Calculating Derivatives (193)
- 9 Derivative-Free Optimization (220)
- 10 Least-Squares Problems (245)
- 11 Nonlinear Equations (270)
- 12 Theory of Constrained Optimization (304). This is the KKT chapter. A Chinese translation's subsection list (examples, tangent cone and constraint qualifications, first-order conditions, second-order conditions, other constraint qualifications, geometry, multipliers and sensitivity, duality) was not checked against the English contents and is **not copied here**.
- 13 Linear Programming: The Simplex Method (355)
- 14 Linear Programming: Interior-Point Methods (392)
- 15 Fundamentals of Algorithms for Nonlinear Constrained Optimization (421)
- 16 Quadratic Programming (448)
- 17 Penalty and Augmented Lagrangian Methods (497)
- 18 Sequential Quadratic Programming (529): 18.1 Local SQP Method; 18.2 Preview of Practical SQP Methods; 18.3 Algorithmic Development; 18.4 A Practical Line Search SQP Method; 18.5 Trust-Region SQP Methods; 18.6 Nonlinear Gradient Projection; 18.7 Convergence Analysis; 18.8 Perspectives and Software
- 19 Interior-Point Methods for Nonlinear Programming (563): 19.1 Two Interpretations; 19.2 A Basic Interior-Point Algorithm; 19.3 Algorithmic Development; 19.4 A Line Search Interior-Point Method; 19.5 A Trust-Region Interior-Point Method
- Appendix A Background Material (598): A.1 Elements of Linear Algebra; A.2 Elements of Analysis, Geometry, Topology
- Appendix B A Regularization Procedure (635)

## 6. Vershynin — High-Dimensional Probability

### 2018 first edition, the one the canon cites

CUP, 2018. ISBN 978-1-108-41519-4. 284 pages of front matter through the index in one Google Books record; the contents run to an index on p. 281. Source: CUP front matter and the ETH Zurich contents PDF `e01_978-1-108-41519-4_01.pdf`. One gap: sections 4.3 through 4.8 were on a contents page that this fetch truncated after 4.2. They are marked below.

- Foreword; Preface
- Appetizer: Using Probability to Cover a Geometric Set (1); 0.1 Notes (4)
- 1 Preliminaries on Random Variables (5): 1.1 Basic Quantities Associated with Random Variables; 1.2 Some Classical Inequalities; 1.3 Limit Theorems; 1.4 Notes
- 2 Concentration of Sums of Independent Random Variables (11): 2.1 Why Concentration Inequalities?; 2.2 Hoeffding's Inequality (13); 2.3 Chernoff's Inequality (17); 2.4 Application: Degrees of Random Graphs (19); 2.5 Sub-Gaussian Distributions (21); 2.6 General Hoeffding and Khintchine Inequalities (26); 2.7 Sub-Exponential Distributions (28); 2.8 Bernstein's Inequality (33); 2.9 Notes (36)
- 3 Random Vectors in High Dimensions (38): 3.1 Concentration of the Norm (39); 3.2 Covariance Matrices and Principal Component Analysis (41); 3.3 Examples of High-Dimensional Distributions (45); 3.4 Sub-Gaussian Distributions in Higher Dimensions (51); 3.5 Application: Grothendieck's Inequality and Semidefinite Programming (55); 3.6 Application: Maximum Cut for Graphs (60); 3.7 Kernel Trick, and Tightening of Grothendieck's Inequality (64); 3.8 Notes (68)
- 4 Random Matrices (70): 4.1 Preliminaries on Matrices (70); 4.2 Nets, Covering Numbers, and Packing Numbers. **4.3–4.8 not yet copied from the 2018 contents.** Do not substitute the 2024 free-PDF titles; that file inserts "Application: error correcting codes" as 4.3 and shifts the later numbers.
- 5 Concentration Without Independence (98): 5.1 Concentration of Lipschitz Functions for the Sphere (98); 5.2 Concentration for Other Metric Measure Spaces (104); 5.3 Application: Johnson–Lindenstrauss Lemma (110); 5.4 Matrix Bernstein Inequality (113); 5.5 Application: Community Detection in Sparse Networks (121); 5.6 Application: Covariance Estimation for General Distributions (122); 5.7 Notes (125)
- 6 Quadratic Forms, Symmetrization, and Contraction (127): 6.1 Decoupling (127); 6.2 Hanson–Wright Inequality (130); 6.3 Concentration for Anisotropic Random Vectors (134); 6.4 Symmetrization (136); 6.5 Random Matrices With Non-I.I.D. Entries (138); 6.6 Application: Matrix Completion (140); 6.7 Contraction Principle (143); 6.8 Notes (145)
- 7 Random Processes (147): 7.1 Basic Concepts and Examples; 7.2 Slepian's Inequality (151); 7.3 Sharp Bounds on Gaussian Matrices (157); 7.4 Sudakov's Minoration Inequality (160); 7.5 Gaussian Width (162); 7.6 Stable Dimension, Stable Rank, and Gaussian Complexity (167); 7.7 Random Projections of Sets (170); 7.8 Notes (174)
- 8 Chaining (176): 8.1 Dudley's Inequality; 8.2 Application: Empirical Processes (183); 8.3 VC Dimension (188); 8.4 Application: Statistical Learning Theory (200); 8.5 Generic Chaining (206); 8.6 Talagrand's Majorizing Measure and Comparison Theorems (210); 8.7 Chevet's Inequality (212); 8.8 Notes (214)
- 9 Deviations of Random Matrices and Geometric Consequences (216): 9.1 Matrix Deviation Inequality (216); 9.2 Random Matrices, Random Projections, and Covariance Estimation (222); 9.3 The Johnson–Lindenstrauss Lemma for Infinite Sets (225); 9.4 Random Sections: M* Bound and Escape Theorem (227); 9.5 Notes (231)
- 10 Sparse Recovery (232): 10.1 High-Dimensional Signal Recovery Problems; 10.2 Signal Recovery Based on M* Bound (234); 10.3 Recovery of Sparse Signals (236); 10.4 Low-Rank Matrix Recovery (239); 10.5 Exact Recovery and the Restricted Isometry Property (241); 10.6 Lasso Algorithm for Sparse Regression (247); 10.7 Notes (252)
- 11 Dvoretzky–Milman Theorem (254): 11.1 Deviations of Random Matrices with respect to General Norms; 11.2 Johnson–Lindenstrauss Embeddings and Sharper Chevet Inequality (257); 11.3 Dvoretzky–Milman Theorem (259); 11.4 Notes (264)
- Hints for Exercises (265); References (272); Index (281)

### 2026 second edition, different book

CUP, 2026. ISBN 978-1-009-49064-1. Free PDF contents, file dated 22 July 2026. Chapters 10 and 11 of the 2018 book are folded into chapter 9. Exercises are now inside each chapter.

- Preface to the Second Edition
- Appetizer: Using Probability to Cover a Set (1)
- 1 A Quick Refresher on Analysis and Probability (8): 1.1 Convex sets and functions; 1.2 Norms and inner products; 1.3 Random variables and random vectors; 1.4 Union bound; 1.5 Conditioning; 1.6 Probabilistic inequalities; 1.7 Limit theorems; 1.8 Notes; exercises
- 2 Concentration of Sums of Independent Random Variables (25): 2.1 Why concentration inequalities?; 2.2 Hoeffding inequality; 2.3 Chernoff inequality; 2.4 Application: median-of-means estimator; 2.5 Application: degrees of random graphs; 2.6 Subgaussian distributions; 2.7 Subgaussian Hoeffding and Khintchine inequalities; 2.8 Subexponential distributions; 2.9 Bernstein inequality; 2.10 Notes; exercises
- 3 Random Vectors in High Dimensions (59): 3.1 Concentration of the norm; 3.2 Covariance matrices and principal component analysis; 3.3 Examples of high-dimensional distributions; 3.4 Subgaussian distributions in higher dimensions; 3.5 Grothendieck inequality and semidefinite programming; 3.6 Maximum cut; 3.7 Kernel trick; 3.8 Notes; exercises
- 4 Random Matrices (101): 4.1 A quick refresher on linear algebra; 4.2 Nets, covering and packing; 4.3 Application: error correcting codes; 4.4 Upper bounds on subgaussian random matrices; 4.5 Community detection; 4.6 Two-sided bounds; 4.7 Covariance estimation and clustering; 4.8 Notes; exercises
- 5 Concentration without independence. **Section titles of chapter 5 in the 2026 PDF were not in the fetched contents window.**
- 6 Quadratic Forms, Symmetrization and Contraction (172): 6.1 Decoupling; 6.2 Hanson–Wright inequality; 6.3 Symmetrization; 6.4 Random matrices with non-i.i.d. entries; 6.5 Matrix completion; 6.6 Contraction principle; 6.7 Notes; exercises. The 2018 §6.3 on anisotropic random vectors is not a separate 2026 heading.
- 7 Random Processes (195): 7.1 Basic concepts and examples; 7.2 Slepian, Sudakov–Fernique, and Gordon inequalities; 7.3 Sharp bounds for Gaussian matrices; 7.4 Sudakov inequality; 7.5 Gaussian width; 7.6 Random projections of sets; 7.7 Notes; exercises. The 2018 §7.6 on stable dimension is not a separate 2026 heading.
- 8 Chaining (222): 8.1 Dudley inequality; 8.2 Empirical processes; 8.3 VC dimension; 8.4 Statistical learning theory; 8.5 Generic chaining; 8.6 Chevet inequality; 8.7 Notes; exercises. Talagrand's majorizing-measure section from 2018 §8.6 is not a separate 2026 heading.
- 9 Deviations of Random Matrices on Sets (262): 9.1 Matrix deviation inequality; 9.2 Random matrices, covariance estimation, and the Johnson–Lindenstrauss lemma; 9.3 Random sections: the M* bound and escape theorem; 9.4 High-dimensional linear models; 9.5 Exact sparse recovery; 9.6 Deviations for general norms; 9.7 Two-sided Chevet inequality and Dvoretzky–Milman theorem; 9.8 Notes; exercises
- Hints; References; Index. No chapters 10 or 11.

## 7. Cover & Thomas — Elements of Information Theory, 2nd ed.

Wiley-Interscience, 2006. ISBN 978-0-471-24195-9. Chapter list from the Wiley contents. Section titles from the Wiley excerpt PDF `0471241954-29.pdf` and the Utah bibliography dump of the same contents. Chapters 5–7 and 12–17 are chapter-level only; their section titles were not on the pages opened.

- Preface to the Second Edition; Preface to the First Edition; acknowledgments
- 1 Introduction and Preview (1): 1.1 Preview of the Book (5)
- 2 Entropy, Relative Entropy, and Mutual Information (13): 2.1 Entropy; 2.2 Joint Entropy and Conditional Entropy; 2.3 Relative Entropy and Mutual Information; 2.4 Relationship Between Entropy and Mutual Information; 2.5 Chain Rules; 2.6 Jensen's Inequality and Its Consequences; 2.7 Log Sum Inequality and Its Applications; 2.8 Data-Processing Inequality; 2.9 Sufficient Statistics; 2.10 Fano's Inequality; Summary; Problems; Historical Notes
- 3 Asymptotic Equipartition Property (57): 3.1 The AEP Theorem; 3.2 Consequences of the AEP: Data Compression; 3.3 High-Probability Sets and the Typical Set
- 4 Entropy Rates of a Stochastic Process (71): 4.1 Markov Chains; 4.2 Entropy Rate; 4.3 Example: Entropy Rate of a Random Walk on a Weighted Graph; 4.4 Second Law of Thermodynamics; 4.5 Functions of Markov Chains
- 5 Data Compression (103). Sections **not yet copied**.
- 6 Gambling and Data Compression (159). Sections **not yet copied**.
- 7 Channel Capacity (183). Sections **not yet copied**.
- 8 Differential Entropy (243). The Utah dump shows, among others, joint and conditional differential entropy, and relative entropy and mutual information, before the summary on p. 256. Full 8.x list **not yet copied**.
- 9 Gaussian Channel (261): 9.1 Gaussian Channel: Definitions (263); 9.2 Converse to the Coding Theorem for Gaussian Channels (268); 9.3 Bandlimited Channels (270); 9.4 Parallel Gaussian Channels (274); 9.5 Channels with Colored Gaussian Noise (277); 9.6 Gaussian Channels with Feedback (280)
- 10 Rate Distortion Theory (301): 10.1 Quantization; 10.2 Definitions (303); 10.3 Calculation of the Rate Distortion Function (307), with 10.3.1 Binary Source, 10.3.2 Gaussian Source (310), 10.3.3 Simultaneous Description of Independent Gaussian Random Variables (312); 10.4 Converse (315); 10.5 Achievability (318); 10.6 Strongly Typical Sequences and Rate Distortion (325); 10.7 Characterization of the Rate Distortion Function (329); 10.8 Computation of Channel Capacity and the Rate Distortion Function (332)
- 11 Information Theory and Statistics (347): 11.1 Method of Types; 11.2 Law of Large Numbers; 11.3 Universal Source Coding; 11.4 Large Deviation Theory; 11.5 Examples of Sanov's Theorem; 11.6 Conditional Limit Theorem; 11.7 Hypothesis Testing; 11.8 Chernoff–Stein Lemma; 11.9 Chernoff Information; 11.10 Fisher Information and the Cramér–Rao Inequality
- 12 Maximum Entropy (409)
- 13 Universal Source Coding (427)
- 14 Kolmogorov Complexity (463)
- 15 Network Information Theory (509)
- 16 Information Theory and Portfolio Theory (613)
- 17 Inequalities in Information Theory (657)
- Bibliography (689); List of Symbols; Index

## 8. Penrose — The Road to Reality

Local PDF contents. The file is the Jonathan Cape text (London, 2004); a library record of the Knopf printing (ISBN 0679454438) gives the same chapter titles. OCR on the contents pages turned "field" into "Weld" and "finite" into "Wnite"; those are corrected below. Printed page numbers are kept.

Preface                                                      xv
Acknowledgements                                           xxiii
Notation                                                   xxvi
Prologue                                                      1
1 The roots of science                                        7
1.1    The quest for the forces that shape the world       7
1.2    Mathematical truth                                  9
1.3    Is Plato’s mathematical world ‘real’?              12
1.4    Three worlds and three deep mysteries              17
1.5    The Good, the True, and the Beautiful              22
2 An ancient theorem and a modern question                   25
2.1    The Pythagorean theorem                            25
2.2    Euclid’s postulates                                28
2.3    Similar-areas proof of the Pythagorean theorem     31
2.4    Hyperbolic geometry: conformal picture             33
2.5    Other representations of hyperbolic geometry       37
2.6    Historical aspects of hyperbolic geometry          42
2.7    Relation to physical space                         46
3 Kinds of number in the physical world                      51
3.1    A Pythagorean catastrophe?                         51
3.2    The real-number system                             54
3.3    Real numbers in the physical world                 59
3.4    Do natural numbers need the physical world?        63
3.5    Discrete numbers in the physical world             65
4 Magical complex numbers                                    71
4.1    The magic number ‘i’                               71
4.2    Solving equations with complex numbers             74
4.3   Convergence of power series                       76
4.4   Caspar Wessel’s complex plane                     81
4.5   How to construct the Mandelbrot set               83
5 Geometry of logarithms, powers, and roots                 86
5.1   Geometry of complex algebra                       86
5.2   The idea of the complex logarithm                 90
5.3   Multiple valuedness, natural logarithms           92
5.4   Complex powers                                    96
5.5   Some relations to modern particle physics        100
6 Real-number calculus                                      103
6.1   What makes an honest function?                   103
6.2   Slopes of functions                              105
6.3   Higher derivatives; C1 -smooth functions         107
6.4   The ‘Eulerian’ notion of a function?             112
6.5   The rules of differentiation                      114
6.6   Integration                                      116
7 Complex-number calculus                                   122
7.1   Complex smoothness; holomorphic functions        122
7.2   Contour integration                              123
7.3   Power series from complex smoothness             127
7.4   Analytic continuation                            129
8 Riemann surfaces and complex mappings                     135
8.1   The idea of a Riemann surface                    135
8.2   Conformal mappings                               138
8.3   The Riemann sphere                               142
8.4   The genus of a compact Riemann surface           145
8.5   The Riemann mapping theorem                      148
9 Fourier decomposition and hyperfunctions                  153
9.1   Fourier series                                   153
9.2   Functions on a circle                            157
9.3   Frequency splitting on the Riemann sphere        161
9.4   The Fourier transform                            164
9.5   Frequency splitting from the Fourier transform   166
9.6   What kind of function is appropriate?            168
9.7   Hyperfunctions                                   172
10 Surfaces                                                         179
10.1    Complex dimensions and real dimensions                  179
10.2    Smoothness, partial derivatives                         181
10.3    Vector fields and 1-forms                                185
10.4    Components, scalar products                             190
10.5    The Cauchy–Riemann equations                            193
11 Hypercomplex numbers                                             198
11.1    The algebra of quaternions                              198
11.2    The physical role of quaternions?                       200
11.3    Geometry of quaternions                                 203
11.4    How to compose rotations                                206
11.5    Clifford algebras                                        208
11.6    Grassmann algebras                                      211
12 Manifolds of n dimensions                                        217
12.1    Why study higher-dimensional manifolds?                 217
12.2    Manifolds and coordinate patches                        221
12.3    Scalars, vectors, and covectors                         223
12.4    Grassmann products                                      227
12.5    Integrals of forms                                      229
12.6    Exterior derivative                                     231
12.7    Volume element; summation convention                    237
12.8    Tensors; abstract-index and diagrammatic notation       239
12.9    Complex manifolds                                       243
13 Symmetry groups                                                  247
13.1    Groups of transformations                               247
13.2    Subgroups and simple groups                             250
13.3    Linear transformations and matrices                     254
13.4    Determinants and traces                                 260
13.5    Eigenvalues and eigenvectors                            263
13.6    Representation theory and Lie algebras                  266
13.7    Tensor representation spaces; reducibility              270
13.8    Orthogonal groups                                       275
13.9    Unitary groups                                          281
13.10   Symplectic groups                                       286
14 Calculus on manifolds                                            292
14.1    Differentiation on a manifold?                           292
14.2    Parallel transport                                      294
14.3    Covariant derivative                                    298
14.4    Curvature and torsion                                   301
14.5   Geodesics, parallelograms, and curvature          303
14.6   Lie derivative                                    309
14.7   What a metric can do for you                      317
14.8   Symplectic manifolds                              321
15 Fibre bundles and gauge connections                          325
15.1   Some physical motivations for Wbre bundles        325
15.2   The mathematical idea of a bundle                 328
15.3   Cross-sections of bundles                         331
15.4   The Clifford bundle                                334
15.5   Complex vector bundles, (co)tangent bundles       338
15.6   Projective spaces                                 341
15.7   Non-triviality in a bundle connection             345
15.8   Bundle curvature                                  349
16 The ladder of inWnity                                        357
16.1   Finite fields                                      357
16.2   A finite or infinite geometry for physics?          359
16.3   DiVerent sizes of inWnity                         364
16.4   Cantor’s diagonal slash                           367
16.5   Puzzles in the foundations of mathematics         371
16.6   Turing machines and Gödel’s theorem              374
16.7   Sizes of inWnity in physics                       378
17 Spacetime                                                    383
17.1   The spacetime of Aristotelian physics             383
17.2   Spacetime for Galilean relativity                 385
17.3   Newtonian dynamics in spacetime terms             388
17.4   The principle of equivalence                      390
17.5   Cartan’s ‘Newtonian spacetime’                    394
17.6   The Wxed finite speed of light                     399
17.7   Light cones                                       401
17.8   The abandonment of absolute time                  404
17.9   The spacetime for Einstein’s general relativity   408
18 Minkowskian geometry                                         412
18.1   Euclidean and Minkowskian 4-space                 412
18.2   The symmetry groups of Minkowski space            415
18.3   Lorentzian orthogonality; the ‘clock paradox’     417
18.4   Hyperbolic geometry in Minkowski space            422
18.5   The celestial sphere as a Riemann sphere          428
18.6   Newtonian energy and (angular) momentum           431
18.7   Relativistic energy and (angular) momentum        434
19 The classical fields of Maxwell and Einstein                       440
19.1    Evolution away from Newtonian dynamics                   440
19.2    Maxwell’s electromagnetic theory                         442
19.3    Conservation and flux laws in Maxwell theory              446
19.4    The Maxwell field as gauge curvature                      449
19.5    The energy–momentum tensor                               455
19.6    Einstein’s field equation                                 458
19.7    Further issues: cosmological constant; Weyl tensor       462
19.8    Gravitational field energy                                464
20 Lagrangians and Hamiltonians                                      471
20.1    The magical Lagrangian formalism                         471
20.2    The more symmetrical Hamiltonian picture                 475
20.3    Small oscillations                                       478
20.4    Hamiltonian dynamics as symplectic geometry              483
20.5    Lagrangian treatment of fields                            486
20.6    How Lagrangians drive modern theory                      489
21 The quantum particle                                              493
21.1    Non-commuting variables                                  493
21.2    Quantum Hamiltonians                                     496
21.3    Schrödinger’s equation                                  498
21.4    Quantum theory’s experimental background                 500
21.5    Understanding wave–particle duality                      505
21.6    What is quantum ‘reality’?                               507
21.7    The ‘holistic’ nature of a wavefunction                  511
21.8    The mysterious ‘quantum jumps’                           516
21.9    Probability distribution in a wavefunction               517
21.10   Position states                                          520
21.11   Momentum-space description                               521
22 Quantum algebra, geometry, and spin                               527
22.1    The quantum procedures U and R                           527
22.2    The linearity of U and its problems for R                530
22.3    Unitary structure, Hilbert space, Dirac notation         533
22.4    Unitary evolution: Schrödinger and Heisenberg           535
22.5    Quantum ‘observables’                                    538
22.6    yes/no measurements; projectors                          542
22.7    Null measurements; helicity                              544
22.8    Spin and spinors                                         549
22.9    The Riemann sphere of two-state systems                  553
22.10   Higher spin: Majorana picture                            559
22.11   Spherical harmonics                                      562
22.12   Relativistic quantum angular momentum             566
22.13   The general isolated quantum object               570
23 The entangled quantum world                                578
23.1    Quantum mechanics of many-particle systems        578
23.2    Hugeness of many-particle state space             580
23.3    Quantum entanglement; Bell inequalities           582
23.4    Bohm-type EPR experiments                         585
23.5    Hardy’s EPR example: almost probability-free      589
23.6    Two mysteries of quantum entanglement             591
23.7    Bosons and fermions                               594
23.8    The quantum states of bosons and fermions         596
23.9    Quantum teleportation                             598
23.10   Quanglement                                       603
24 Dirac’s electron and antiparticles                         609
24.1    Tension between quantum theory and relativity     609
24.2    Why do antiparticles imply quantum fields?         610
24.3    Energy positivity in quantum mechanics            612
24.4    Difficulties with the relativistic energy formula   614
24.5    The non-invariance of ]=]t                        616
24.6    Clifford–Dirac square root of wave operator        618
24.7    The Dirac equation                                620
24.8    Dirac’s route to the positron                     622
25 The standard model of particle physics                     627
25.1    The origins of modern particle physics            627
25.2    The zigzag picture of the electron                628
25.3    Electroweak interactions; reflection asymmetry     632
25.4    Charge conjugation, parity, and time reversal     638
25.5    The electroweak symmetry group                    640
25.6    Strongly interacting particles                    645
25.7    ‘Coloured quarks’                                 648
25.8    Beyond the standard model?                        651
26 Quantum field theory                                        655
26.1    Fundamental status of QFT in modern theory        655
26.2    Creation and annihilation operators               657
26.3    Infinite-dimensional algebras                      660
26.4    Antiparticles in QFT                              662
26.5    Alternative vacua                                 664
26.6    Interactions: Lagrangians and path integrals      665
26.7    Divergent path integrals: Feynman’s response      670
26.8    Constructing Feynman graphs; the S-matrix         672
26.9    Renormalization                                   675
26.10   Feynman graphs from Lagrangians                            680
26.11   Feynman graphs and the choice of vacuum                    681
27 The Big Bang and its thermodynamic legacy                           686
27.1    Time symmetry in dynamical evolution                       686
27.2    Submicroscopic ingredients                                 688
27.3    Entropy                                                    690
27.4    The robustness of the entropy concept                      692
27.5    Derivation of the second law—or not?                       696
27.6    Is the whole universe an ‘isolated system’?                699
27.7    The role of the Big Bang                                   702
27.8    Black holes                                                707
27.9    Event horizons and spacetime singularities                 712
27.10   Black-hole entropy                                         714
27.11   Cosmology                                                  717
27.12   Conformal diagrams                                         723
27.13   Our extraordinarily special Big Bang                       726
28 Speculative theories of the early universe                          735
28.1    Early-universe spontaneous symmetry breaking               735
28.2    Cosmic topological defects                                 739
28.3    Problems for early-universe symmetry breaking              742
28.4    InXationary cosmology                                      746
28.5    Are the motivations for inXation valid?                    753
28.6    The anthropic principle                                    757
28.7    The Big Bang’s special nature: an anthropic key?           762
28.8    The Weyl curvature hypothesis                              765
28.9    The Hartle–Hawking ‘no-boundary’ proposal                  769
28.10   Cosmological parameters: observational status?             772
29 The measurement paradox                                             782
29.1    The conventional ontologies of quantum theory              782
29.2    Unconventional ontologies for quantum theory               785
29.3    The density matrix                                         791
29.4    Density matrices for spin 12: the Bloch sphere             793
29.5    The density matrix in EPR situations                       797
29.6    FAPP philosophy of environmental decoherence               802
29.7    Schrödinger’s cat with ‘Copenhagen’ ontology              804
29.8    Can other conventional ontologies resolve the ‘cat’?       806
29.9    Which unconventional ontologies may help?                  810
30 Gravity’s role in quantum state reduction                           816
30.1    Is today’s quantum theory here to stay?                    816
30.2    Clues from cosmological time asymmetry                     817
30.3    Time-asymmetry in quantum state reduction          819
30.4    Hawking’s black-hole temperature                   823
30.5    Black-hole temperature from complex periodicity    827
30.6    Killing vectors, energy flow—and time travel!       833
30.7    Energy outflow from negative-energy orbits          836
30.8    Hawking explosions                                 838
30.9    A more radical perspective                         842
30.10   Schrödinger’s lump                                846
30.11   Fundamental conflict with Einstein’s principles     849
30.12   Preferred Schrödinger–Newton states?              853
30.13   FELIX and related proposals                        856
30.14   Origin of fluctuations in the early universe        861
31 Supersymmetry, supra-dimensionality, and strings              869
31.1    Unexplained parameters                             869
31.2    Supersymmetry                                      873
31.3    The algebra and geometry of supersymmetry          877
31.4    Higher-dimensional spacetime                       880
31.5    The original hadronic string theory                884
31.6    Towards a string theory of the world               887
31.7    String motivation for extra spacetime dimensions   890
31.8    String theory as quantum gravity?                  892
31.9    String dynamics                                    895
31.10   Why don’t we see the extra space dimensions?       897
31.11   Should we accept the quantum-stability argument?   902
31.12   Classical instability of extra dimensions          905
31.13   Is string QFT finite?                               907
31.14   The magical Calabi–Yau spaces; M-theory            910
31.15   Strings and black-hole entropy                     916
31.16   The ‘holographic principle’                        920
31.17   The D-brane perspective                            923
31.18   The physical status of string theory?              926
32 Einstein’s narrower path; loop variables                      934
32.1    Canonical quantum gravity                          934
32.2    The chiral input to Ashtekar’s variables           935
32.3    The form of Ashtekar’s variables                   938
32.4    Loop variables                                     941
32.5    The mathematics of knots and links                 943
32.6    Spin networks                                      946
32.7    Status of loop quantum gravity?                    952
33 More radical perspectives; twistor theory                     958
33.1    Theories where geometry has discrete elements      958
33.2    Twistors as light rays                             962
33.3    Conformal group; compactified Minkowski space              968
33.4    Twistors as higher-dimensional spinors                    972
33.5    Basic twistor geometry and coordinates                    974
33.6    Geometry of twistors as spinning massless particles       978
33.7    Twistor quantum theory                                    982
33.8    Twistor description of massless fields                     985
33.9    Twistor sheaf cohomology                                  987
33.10   Twistors and positive/negative frequency splitting        993
33.11   The non-linear graviton                                   995
33.12   Twistors and general relativity                          1000
33.13   Towards a twistor theory of particle physics             1001
33.14   The future of twistor theory?                            1003
34 Where lies the road to reality?                                   1010
34.1    Great theories of 20th century physics—and beyond?       1010
34.2    Mathematically driven fundamental physics                1014
34.3    The role of fashion in physical theory                   1017
34.4    Can a wrong theory be experimentally refuted?            1020
34.5    Whence may we expect our next physical revolution?       1024
34.6    What is reality?                                         1027
34.7    The roles of mentality in physical theory                1030
34.8    Our long mathematical road to reality                    1033
34.9    Beauty and miracles                                      1038
34.10   Deep questions answered, deeper questions posed          1043
Epilogue                                                             1048
Bibliography                                                         1050
Index                                                                1081


## 9. Agner Fog — Optimizing software in C++

Local PDF. Copyright 2004–2023. Last updated 2023-07-01. 180 A4 pages. This is the manual. It is not the instruction tables, and it is not *Optimizing subroutines in assembly language*.

- 1 Introduction (3): 1.1 Why software is often slow; 1.2 The costs of optimizing
- 2 Choosing the optimal platform (5): 2.1 hardware; 2.2 microprocessor; 2.3 operating system; 2.4 programming language; 2.5 compiler; 2.6 function libraries; 2.7 user interface framework; 2.8 Overcoming the drawbacks of the C++ language
- 3 Finding the biggest time consumers (15): 3.1 How much is a clock cycle?; 3.2 Use a profiler; 3.3 installation; 3.4 automatic updates; 3.5 program loading; 3.6 Dynamic linking and position-independent code; 3.7 file access; 3.8 system database; 3.9 other databases; 3.10 graphics; 3.11 other system resources; 3.12 network; 3.13 memory access; 3.14 context switches; 3.15 dependency chains; 3.16 execution unit throughput
- 4 Performance and usability (22)
- 5 Choosing the optimal algorithm (24)
- 6 Development process (24)
- 7 The efficiency of different C++ constructs (25): 7.1 Different kinds of variable storage (25); 7.2 Integers variables and operators (29); 7.3 Floating point variables and operators (31); 7.4 Enums; 7.5 Booleans; 7.6 Pointers and references; 7.7 Function pointers; 7.8 Member pointers; 7.9 Smart pointers; 7.10 Arrays; 7.11 Type conversions; 7.12 Branches and switch statements; 7.13 Loops; 7.14 Functions; 7.15 Function parameters; 7.16 Function return types; 7.17 Function tail calls; 7.18 Recursive functions; 7.19 Structures and classes; 7.20 Class data members; 7.21 Class member functions; 7.22 Virtual member functions; 7.23 RTTI; 7.24 Inheritance; 7.25 Constructors and destructors; 7.26 Unions; 7.27 Bitfields; 7.28 Overloaded functions; 7.29 Overloaded operators; 7.30 Templates; 7.31 Threads; 7.32 Exceptions and error handling; 7.33 Other cases of stack unwinding; 7.34 Propagation of NAN and INF; 7.35 Preprocessing directives; 7.36 Namespaces
- 8 Optimizations in the compiler (67): 8.1 How compilers optimize; 8.2 Comparison of different compilers; 8.3 Obstacles to optimization by compiler; 8.4 Obstacles to optimization by CPU; 8.5 Compiler optimization options; 8.6 Optimization directives; 8.7 Checking what the compiler does
- 9 Optimizing memory access (91): 9.1 Caching of code and data; 9.2 Cache organization; 9.3 Functions that are used together should be stored together; 9.4 Variables that are used together should be stored together; 9.5 Alignment of data; 9.6 Dynamic memory allocation; 9.7 Data structures and container classes; 9.8 Strings; 9.9 Access data sequentially; 9.10 Cache contentions in large data structures; 9.11 Explicit cache control
- 10 Multithreading (110): 10.1 Simultaneous multithreading
- 11 Out of order execution (113). No subsections.
- 12 Using vector operations (115): 12.1 AVX instruction set and YMM registers (117); 12.2 AVX512 instruction set and ZMM registers (117); 12.3 Automatic vectorization; 12.4 Using intrinsic functions (121); 12.5 Using vector classes; 12.6 Transforming serial code for vectorization; 12.7 Mathematical functions for vectors; 12.8 Aligning dynamically allocated memory; 12.9 Aligning RGB video or 3-dimensional vectors; 12.10 Conclusion
- 13 Making critical code in multiple versions for different instruction sets (135): 13.1 CPU dispatch strategies; 13.2 Model-specific dispatching; 13.3 Difficult cases; 13.4 Test and maintenance; 13.5 Implementation; 13.6 CPU dispatching at load time in Linux; 13.7 CPU dispatching in Intel compiler
- 14 Specific optimization topics (144): 14.1 Use lookup tables; 14.2 Bounds checking; 14.3 Use bitwise operators for checking multiple values at once; 14.4 Integer multiplication; 14.5 Integer division; 14.6 Floating point division; 14.7 Do not mix float and double; 14.8 Conversions between floating point numbers and integers; 14.9 Using integer operations for manipulating floating point variables; 14.10 Mathematical functions; 14.11 Static versus dynamic libraries; 14.12 Position-independent code; 14.13 System programming
- 15 Metaprogramming (163): 15.1 Template metaprogramming; 15.2 constexpr branches; 15.3 constexpr functions
- 16 Testing speed (167): 16.1 Using performance monitor counters (169); 16.2 The pitfalls of unit-testing; 16.3 Worst-case testing
- 17 Optimization in embedded systems (173)
- 18 Overview of compiler options (175)
- 19 Literature (179)
- 20 Copyright notice (180)

## 10. Pikus — The Art of Writing Efficient Programs

Packt, 22 October 2021. 1st edition. 464 pages. ISBN 978-1-800-20811-7. Chapter list from the publisher contents. Section titles inside the chapters were **not yet copied**.

- Section 1 — Performance Fundamentals
  - 1 Introduction to Performance and Concurrency (p. 3)
  - 2 Performance Measurements (p. 19)
  - 3 CPU Architecture, Resources, and Performance (p. 69)
  - 4 Memory Architecture and Performance (p. 113)
  - 5 Threads, Memory, and Concurrency (p. 159)
- Section 2 — Advanced Concurrency
  - 6 Concurrency and Performance (p. 199)
  - 7 Data Structures for Concurrency (p. 237)
  - 8 Concurrency in C++ (p. 293)
- Section 3 — Designing and Coding High-Performance Programs
  - 9 High-Performance C++ (p. 317)
  - 10 Compiler Optimizations in C++ (p. 347)
  - 11 Undefined Behavior and Performance (p. 371)
  - 12 Design for Performance (p. 393)
- Assessments (425); Other Books You May Enjoy (436); Index (439)

## Still not copied at section level

The contents pages for these were not opened in this pass. They are listed so nothing in the request or in `resources/systems_canon.md` is dropped. Internal section numbers will be filled only from a contents page.

### Request, architecture and C++

- Bryant & O'Hallaron, *Computer Systems: A Programmer's Perspective*, 3rd ed. (Pearson, 2015).
- Hennessy & Patterson, *Computer Architecture: A Quantitative Approach*. Request: 6th ed. (2017). Canon: 7th ed. (Elsevier, 2024, ISBN 978-0-443-15406-5).
- Bakhvalov, *Performance Analysis and Tuning on Modern CPUs*, 2nd ed. (2024).
- Gregg, *Systems Performance*, 2nd ed. (Addison-Wesley, 2020).
- Drepper, *What Every Programmer Should Know About Memory* (2007).
- Intel 64 and IA-32 Architectures Optimization Reference Manual. Volume and order number not copied.
- AMD Software Optimization Guide, Family 19h / 1Ah. Chapter list not copied.
- Fog, *Instruction tables*, and Fog, *Optimizing subroutines in assembly language*. Separate manuals. Structure not copied.
- Meyers, *Effective Modern C++* (O'Reilly, 2014). Items 1–42.
- Alexandrescu, *Modern C++ Design* (Addison-Wesley, 2001).
- Kerrisk, *The Linux Programming Interface* (No Starch, 2010).
- Love, *Linux System Programming*, 2nd ed. (O'Reilly, 2013).
- Williams, *C++ Concurrency in Action*, 2nd ed. (Manning, 2019).
- McKenney, *Is Parallel Programming Hard, And, If So, What Can You Do About It?* Current online edition.
- Warren, *Hacker's Delight*, 2nd ed. (Addison-Wesley, 2013).

### Request, retrieval, databases, literature

- Zezula, Amato, Dohnal, Batko, *Similarity Search: The Metric Space Approach* (Springer, 2006).
- Manning, Raghavan, Schütze, *Introduction to Information Retrieval* (CUP, 2008).
- Kleppmann, *Designing Data-Intensive Applications* (O'Reilly, 2017).
- Petrov, *Database Internals* (O'Reilly, 2019).
- Hamming, *The Art of Doing Science and Engineering* (Stripe Press reprint of the 1996 lectures).
- Hofstadter, *Gödel, Escher, Bach* (Basic Books, 1979; 20th-anniversary edition 1999).
- Pirsig, *Zen and the Art of Motorcycle Maintenance* (1974).
- Simon, *The Sciences of the Artificial*. Edition not confirmed against a contents page. The usual citation is the 3rd ed. (MIT Press, 1996).
- Wiener, *Cybernetics*. Edition not confirmed. The usual citation is the 2nd ed. (1961).

### Canon only

- Knuth, TAOCP Volume 3, 2nd ed. (1998).
- Jaynes, *Probability Theory: The Logic of Science* (2003).
- Kirk & Hwu, *Programming Massively Parallel Processors*, 4th ed. (2022).
- NVIDIA CUDA C++ Programming Guide. Chapter titles of the current guide not copied.

## Research papers

Section headings below were copied from a PDF or HTML page that was opened. Items marked UNVERIFIED were not opened as full text. Headings are the paper's own, including printed typos.

### Fetch Directed Instruction Prefetching

Glenn Reinman, Brad Calder, Todd Austin. MICRO-32, November 1999. Opened: the UCSD PDF.

1. Introduction
2. Methodology — 2.1 Metrics; 2.2 Baseline Architecture; 2.3 Memory Hierarchy
3. Using Idle Cache Ports to Filter Instruction Prefetch Requests — 3.1 Cache Probe Filtering; 3.2 Prior Cache Probe Filtering Research
4. Decoupled Front-End — 4.1 Baseline Branch Prediction Architecture
5. Fetch Directed Prefetching — 5.1 Architecture; 5.2 Filter Based on Number of FTQ Entries; 5.3 Cache Probe Filtering; 5.4 Cache Miss Filtering; 5.5 Fetch Block Evicted Prefetching; 5.6 Results
6. Next Line Prefetching and Streaming Buffers — 6.1 Tagged Next Line Prefetching; 6.2 Target and Wrong Path Prefetching; 6.3 Streaming Buffers; 6.4 Performance of Prior Work
7. Performance Tradeoffs — 7.1 Combination Approaches; 7.2 Port Comparison; 7.3 Cache Configurations; 7.4 Cache Miss Rates
8. Related Work — 8.1 Fetch Directed Prefetching Research; 8.2 Out of Order Instruction Fetching; 8.3 Code Placement
9. Summary

### Micro-operation cache

UNVERIFIED. IEEE 945363 was not opened. No section headings copied.

### TAGE

Printed title: A case for (partially) TAgged GEometric history length branch prediction. André Seznec, Pierre Michaud. JILP 8 (2006) 1–23. Headings from the HAL deposit of the same article. The JILP PDF font did not extract.

1. Introduction
2. Evaluation framework — 2.1 Simulation traces and evaluation metric; 2.2 Predictor initialization; 2.3 Information used for indexing the branch predictor; Branch history management (unnumbered)
3. The TAGE conditional branch predictor — 3.1 GEometric history length prediction; 3.2 The TAGE predictor (definitions, updating the useful counter u, update on a correct prediction, the overall prediction is incorrect); 3.3 Related work on tagged predictors; 3.4 Performance evaluation; 3.5 Partial tagging versus adder tree; 3.6 Useful and Prediction Counter widths; 3.7 Associativity on predictor tables; 3.8 Implementation issues
4. Evaluating the TAGE predictor in the context of the CBP rules
5. The ITTAGE indirect jump target predictor — 5.1 principles; 5.2 performance evaluation
6. COTTAGE: putting the ITTAGE predictor and the TAGE predictor together
7. Conclusion

### ITTAGE, CBP submission

Printed title: A 64-Kbytes ITTAGE indirect branch predictor. André Seznec. The PDF does not print "CBP-3 2011". "Miscelleanous" is printed that way.

1. The ITTAGE indirect jump target predictor — 1.1 principles; 1.1.1 Prediction computation; 1.1.2 Updating the ITTAGE predictor
2. A few optimizations — 2.1 The global history vector; 2.2 Leveraging target locality; 2.3 Miscelleanous optimizations (2.3.1 Sharing storage space between predictor tables; 2.3.2 Dealing with delayed updates: The immediate update mimicker)
3. The submitted predictor characteristics
4. Options of the submitted ITTAGE predictor

### Tomasulo, 1967

Printed running author: R. M. Tomasulo. IBM Journal, January 1967. Headings from a scanned copy; they are unnumbered.

Abstract. Introduction. Definitions and data paths. Preservation of precedence. The Common Data Bus. Conclusions. Acknowledgments. References.

### Critical-path prediction

UNVERIFIED. ACM 10.1145/379240.379253 was not opened. No headings copied.

### Measuring Reorder Buffer Capacity

Henry Wong, 14 May 2013. stuffedcow.net. Blog headings, not a numbered paper.

Measuring Instruction Window Size. Reorder Buffer Capacity (Hyper-Threading). Physical Register File Size. x86 Zeroing Idiom and MOV Optimization. Unresolved Puzzle. Conclusion. Code. Cite.

### Store sets

Printed title: Memory Dependence Prediction using Store Sets. George Z. Chrysos and Joel S. Emer. The copy thanks the ISCA-25 reviewers. Canon capitalizes "Using".

1. Introduction
2. Simulation Environment
3. Motivation — 3.1 No Speculation; 3.2 Naive speculation; 3.3 Perfect Memory Dependence Prediction
4. Related Work
5. Store Sets — 5.1 Concept; 5.2 Performance
6. Store Set Implementation — 6.1 Components; 6.2 Store Set Assignment; 6.3 Prediction Feedback; 6.4 Table Sizes
7. Analysis
8. Conclusion
9. Acknowledgments

### Store-to-load forwarding

Henry Wong, 9 January 2014. stuffedcow.net. No numbered top-level sections.

Store-to-Load Forwarding. Memory Dependence Speculation. Methodology (Hardware). Results (Memory dependence speculation: Fast address vs. fast data; Store-to-Load Forwarding Latency (Fast Address)). Conclusions. Outstanding Questions. Code. Cite.

### Memory-level parallelism

Printed authors: Yuan Chou, Brian Fahs, and Santosh Abraham. The canon's third author, Sanjay J. Patel, is not on this PDF.

1. Introduction
2. MLP and Overall Performance — 2.1 Definition; 2.2 Relating MLP to Overall Performance; 2.3 Clustering of Off-Chip Accesses
3. Microarchitecture Impact on MLP — 3.1 Epoch Model; 3.2 Primary Limiters (3.2.1 Issue Window Size and ROB Size; 3.2.2 Serializing Instructions; 3.2.3 Instruction Fetch Misses; 3.2.4 Unresolvable Branch Mispredictions); 3.3 In-order Processors; 3.4 Issue policies and MLP (3.4.1 Load Issue Policy; 3.4.2 Branch Issue Policy); 3.5 Runahead Execution; 3.6 Value Prediction
4. Experimental Methodology — 4.1 MLPsim; 4.2 Benchmarks
5. Experimental Results — 5.1 Default Processor Configuration; 5.2 MLPsim Validation; 5.3 Traditional Microarchitecture Features; 5.4 New Microarchitecture Features; 5.5 Value Prediction; 5.6 Limit Study; 5.7 MLP and Overall Performance
6. Related Work
7. Conclusion and Future Work

### Precise interrupts

UNVERIFIED. Smith and Pleszkun, IEEE Transactions on Computers, 1988. No public PDF was opened.

### Memory barriers

Printed title: Memory Barriers: a Hardware View for Software Hackers. Paul E. McKenney, 23 July 2010.

1. Cache Structure
2. Cache-Coherence Protocols — 2.1 MESI States; 2.2 MESI Protocol Messages; 2.3 MESI State Diagram; 2.4 MESI Protocol Example
3. Stores Result in Unnecessary Stalls — 3.1 Store Buffers; 3.2 Store Forwarding; 3.3 Store Buffers and Memory Barriers
4. Store Sequences Result in Unnecessary Stalls — 4.1 Invalidate Queues; 4.2 Invalidate Queues and Invalidate Acknowledge; 4.3 Invalidate Queues and Memory Barriers
5. Read and Write Memory Barriers
6. Example Memory-Barrier Sequences — 6.1 Ordering-Hostile Architecture; 6.2 Example 1; 6.3 Example 2; 6.4 Example 3
7. Memory-Barrier Instructions For Specific CPUs — 7.1 Alpha; 7.2 AMD64; 7.3 ARMv7-A/R; 7.4 IA64; 7.5 PA-RISC; 7.6 POWER / Power PC; 7.7 SPARC RMO, PSO, and TSO; 7.8 x86; 7.9 zSeries
8. Are Memory Barriers Forever?
9. Advice to Hardware Designers
10. Answers to Quick Quizzes

### Cache-oblivious algorithms

Printed title: Cache-Oblivious Algorithms, extended abstract. Matteo Frigo, Charles E. Leiserson, Harald Prokop, Sridhar Ramachandran. The opened copy does not print "FOCS 1999".

1. Introduction
2. Matrix multiplication
3. Matrix transposition and FFT
4. Funnelsort
5. Distribution sort
6. Theoretical justifications for the ideal-cache model
7. Related work
8. Conclusion

### NUMA

Page title: NUMA Memory Performance. Headings: NUMA Locality; NUMA Performance; NUMA Cache.

### Roofline

Opened document: UCB/EECS-2008-134, 17 October 2008. Samuel Webb Williams, Andrew Waterman, David A. Patterson. Printed title adds "for Floating-Point Programs and". This is not the CACM 2009 typesetting.

1. Introduction
2. Performance Models
3. The Roofline Model
4. Adding Ceilings to the Model
5. Tying the 3Cs to Operational Intensity
6. Demonstration of the Model — 6.1 Four Diverse Multicore Computers; 6.2 Four Diverse Floating-Point Kernels; 6.3 Roofline Models and Results (6.3.1 SpMV; 6.3.2 LBMHD; 6.3.3 Stencil; 6.3.4 3-D FFT; 6.3.5 Productivity vs. Performance; 6.3.6 Summary)
7. Fallacies about Roofline
8. Conclusions
Appendix A — A.1 Finding Operational Intensity, Rooflines, and Ceilings; A.2 Load Balance and Roofline; A.3 Interaction with Performance Counters

### Yasin, top-down analysis

UNVERIFIED. The ISPASS 2014 paper PDF was not opened. A slide deck was found and not used.

### Paoloni, Intel timing note

UNVERIFIED. The Intel PDF URLs returned 404.

### Mytkowicz et al., ASPLOS 2009

UNVERIFIED. Producing Wrong Data Without Doing Anything Wrong! No PDF was opened.

### Granlund and Montgomery

Printed title: Division by Invariant Integers using Multiplication. Torbjörn Granlund, Peter L. Montgomery. The opened copy has no PLDI line.

1. Introduction
2. Mathematical notations
3. Assumed instructions
4. Unsigned division
5. Signed division, quotient rounded towards 0
6. Signed division, quotient rounded towards −∞
7. Use of floating point
8. Dividing udword by uword
9. Exact division by constants
10. Implementation in GCC
11. Results

### AVX2 population count

Wojciech Muła, Nathan Kurz, Daniel Lemire. arXiv:1611.07612. "The Computer Journal 2018" was not in the ar5iv title block.

1. Introduction
2. Existing Algorithms and Related Work — 2.1 Existing Vectorized Algorithms
3. Novel Vectorized Algorithms
4. Beyond population counts
5. Experimental Results
6. Conclusion
Appendix A. Population Counts in AVX-512

### FlashAttention-2

Tri Dao. arXiv:2307.08691. ICLR 2024 was not in the HTML title block.

1. Introduction
2. Background — 2.1 Hardware characteristics; 2.2 Standard Attention Implementation; 2.3 FlashAttention (2.3.1 Forward pass; 2.3.2 Backward pass)
3. FlashAttention-2: Algorithm, Parallelism, and Work Partitioning — 3.1 Algorithm (3.1.1 Forward; 3.1.2 Backward); 3.2 Parallelism; 3.3 Work Partitioning Between Warps
4. Empirical Validation — 4.1 Benchmarking Attention; 4.2 End-to-end Performance
5. Discussion and Future Directions

### Product quantization

Article title line: Product quantization for nearest neighbor search. Hervé Jégou, Matthijs Douze, Cordelia Schmid. HAL cover: IEEE TPAMI, 2011, 33 (1), pp. 117–128.

I. Introduction
II. Background: quantization, product quantizer — A. Vector quantization; B. Product quantizers
III. Searching with quantization — A. Computing distances using quantized codes; B. Analysis of the distance error; C. Estimator of the squared distance
IV. Non exhaustive search — A. Coarse quantizer, locally defined product quantizer; B. Indexing structure; C. Search algorithm
V. Evaluation of NN search — A. Datasets; B. Memory vs search accuracy; C. Impact of the component grouping; D. Comparison with the state of the art; E. Complexity and speed; F. Large-scale experiments; G. Image search
VI. Conclusion

Asymmetric distance computation is inside III.A. It is not its own section heading. The inverted-file coarse quantizer is IV.A.

### HNSW

Printed title: Efficient and robust approximate nearest neighbor search using Hierarchical Navigable Small World graphs. Yu. A. Malkov, D. A. Yashunin. The opened PDF is the arXiv manuscript (1603.09320), marked as submitted to IEEE, not the typeset TPAMI 2018 issue.

1. Introduction
2. Related works — 2.1 Proximity graph techniques; 2.2 Navigable small world models
3. Motivation
4. Algorithm description — 4.1 Influence of the construction parameters; 4.2 Complexity analysis (4.2.1 Search; 4.2.2 Construction; 4.2.3 Memory cost)
5. Performance evaluation — 5.1 Comparison with baseline NSW; 5.2 Comparison in Euclid spaces; 5.3 Comparison in general spaces; 5.4 Comparison with product quantization based algorithms
6. Discussion
7. Acknowledgements
8. References

### Anisotropic vector quantization

Printed title: Accelerating Large-Scale Inference with Anisotropic Vector Quantization. Ruiqi Guo, Philip Sun, Erik Lindgren, Quan Geng, David Simcha, Felix Chern, Sanjiv Kumar. arXiv:1908.10396. "ScaNN" is not in the title. Top-level heads are unnumbered.

Introduction. Background and Related Works (Inference as Maximum Inner Product Search; Methods for accelerating MIPS: Reducing the Number of Evaluations, Quantization). Problem Formulation (Analyzing Score-Aware Quantization Loss; Special case of w(t)=I(t≥T)). Application to Quantization Techniques (Product Quantization). Experiments (Direct comparison with reconstruction loss; Maximum inner product search retrieval; Recall-Speed benchmark). Conclusion. Appendix: proofs of Theorems 3.2, 3.3, and 4.2; the indicator-weight case; codebook optimization; Amazon-670k; binary quantization; dataset selection.

### Billion-scale similarity search with GPUs

Printed title uses a lowercase s in "scale". Jeff Johnson, Matthijs Douze, Hervé Jégou. arXiv:1702.08734. "(FAISS)" and IEEE Transactions on Big Data 2019 are not in the HTML title block.

1. Introduction
2. Problem statement (run-in heads: Batching; Exact search; Compressed-domain search; The quantizers; Product quantizer)
3. GPU: overview and k-selection — 3.1 Architecture; 3.2 GPU register file usage; 3.3 k-selection on CPU versus GPU
4. Fast k-selection on the GPU — 4.1 In-register sorting; 4.2 WarpSelect; 4.3 Complexity and parameter selection
5. Computation layout — 5.1 Exact search; 5.2 IVFADC indexing; 5.3 GPU implementation; 5.4 Multi-GPU parallelism
6. Experiments and Applications — 6.1 k-selection; 6.2 k-means; 6.3 Exact nearest neighbor search; 6.4 Billion-scale approximate search (SIFT1M, SIFT1B, DEEP1B); 6.5 The k-NN graph; 6.6 Using the k-NN graph
7. Conclusion
Appendix: Complexity analysis of WarpSelect

### DiskANN

Printed title: DiskANN: Fast Accurate Billion-point Nearest Neighbor Search on a Single Node. Suhas Jayaram Subramanya, Devvrit, Rohan Kadekodi, Ravishankar Krishaswamy, Harsha Vardhan Simhadri. NeurIPS 2019.

1. Introduction — 1.1 Our technical contribution; 1.2 Notation; 1.3 Paper Outline
2. The Vamana Graph Construction Algorithm — 2.1 Relative Neighborhood Graphs and the GreedySearch algorithm; 2.2 The Robust Pruning Procedure; 2.3 The Vamana Indexing Algorithm; 2.4 Comparison of Vamana with HNSW and NSG
3. DiskANN: Constructing SSD-Resident Indices — 3.1 Index Design; 3.2 Index Layout; 3.3 Beam Search; 3.4 Caching Frequently Visited Vertices; 3.5 Implicit Re-Ranking Using Full-Precision Vectors
4. Evaluation — 4.1 In-memory search; 4.2 Number of hops; 4.3 One-shot Vamana vs merged Vamana; 4.4 DiskANN vs IVF-based methods
5. Conclusion

### RaBitQ

Printed title: RaBitQ: Quantizing High-Dimensional Vectors with a Theoretical Error Bound for Approximate Nearest Neighbor Search. Jianyang Gao, Cheng Long. SIGMOD 2024. arXiv:2405.12497. Sections 5, 6, 7, and the first appendix head are lowercase as printed.

1. Introduction
2. ANN Query and Quantization
3. The RaBitQ Method — 3.1 Quantizing the Data Vectors (3.1.1 normalization to unit vectors; 3.1.2 codebook; 3.1.3 quantized codes); 3.2 Constructing an Unbiased Estimator; 3.3 Computing the Estimator Efficiently; 3.4 Summary
4. RaBitQ for In-Memory ANN Search
5. experiments — 5.1 setup; 5.2 results (5.2.1 through 5.2.6)
6. related work
7. conclusion
Appendices A–F: geometric lemma, concentration, estimator proof, analysis of Bq, normalization, ablation

### ColBERT

Omar Khattab, Matei Zaharia. SIGIR, 25–30 July 2020. arXiv:2004.12832.

1. Introduction
2. Related Work
3. ColBERT — 3.1 Architecture; 3.2 Query and Document Encoders; 3.3 Late Interaction; 3.4 Offline Indexing; 3.5 Top-k Re-ranking; 3.6 End-to-end Top-k Retrieval
4. Experimental Evaluation — 4.1 Methodology; 4.2 Quality–Cost Tradeoff: Top-k Re-ranking; 4.3 End-to-end Top-k Retrieval; 4.4 Ablation Studies; 4.5 Indexing Throughput and Footprint
5. Conclusions

MaxSim is the late-interaction score inside §3.3. It is not its own section heading.

### CAGRA

Printed title: CAGRA: Highly Parallel Graph Construction and Approximate Nearest Neighbor Search for GPUs. Hiroyuki Ootomo, Akira Naruse, Corey Nolet, Ray Wang, Tamas Feher, Yong Wang. arXiv:2308.15136. "Seach" in III-C3 is printed that way.

I. Introduction
II. Background — II-A ANN search; II-B CUDA (thread hierarchy, memory hierarchy); II-C Related work (SONG, GGNN, GANNS)
III. CAGRA graph — III-A Graph optimization; III-B Construction (initial graph, graph optimization); III-C Evaluation
IV. CAGRA Search — IV-A Algorithm; IV-B Elemental technologies (warp splitting, top-M, hash table, 1-bit parented node); IV-C Implementation (single-CTA, multi-CTA); IV-D Evaluation
V. Experiments — V-A construction time; V-B search quality; V-C large-batch; V-D single-query; V-E large dataset
VI. Conclusion

### Attention Is All You Need

Ashish Vaswani, Noam Shazeer, Niki Parmar, Jakob Uszkoreit, Llion Jones, Aidan N. Gomez, Łukasz Kaiser, Illia Polosukhin. arXiv:1706.03762. NeurIPS 2017 was not in the HTML title block.

1. Introduction
2. Background
3. Model Architecture — 3.1 Encoder and Decoder Stacks; 3.2 Attention (3.2.1 Scaled Dot-Product Attention; 3.2.2 Multi-Head Attention; 3.2.3 Applications of Attention in our Model); 3.3 Position-wise Feed-Forward Networks; 3.4 Embeddings and Softmax; 3.5 Positional Encoding
4. Why Self-Attention
5. Training — 5.1 Training Data and Batching; 5.2 Hardware and Schedule; 5.3 Optimizer; 5.4 Regularization
6. Results — 6.1 Machine Translation; 6.2 Model Variations; 6.3 English Constituency Parsing
7. Conclusion
Attention Visualizations

### ViT

Printed title: An Image is Worth 16x16 Words: Transformers for Image Recognition at Scale. Alexey Dosovitskiy and twelve coauthors, Google Research, Brain Team. arXiv:2010.11929. ICLR 2021 was not in the HTML title block.

1. Introduction
2. Related Work
3. Method — 3.1 Vision Transformer (ViT); 3.2 Fine-tuning and Higher Resolution
4. Experiments — 4.1 Setup; 4.2 Comparison to State of the Art; 4.3 Pre-training Data Requirements; 4.4 Scaling Study; 4.5 Inspecting Vision Transformer; 4.6 Self-supervision
5. Conclusion
Appendix A. Multihead Self-attention
Appendix B. Experiment details
Appendix C. Additional Results
Appendix D. Additional Analyses — D.1 SGD vs. Adam; D.2 Transformer shape; D.3 Head Type and class token; D.4 Positional Embedding; D.5 Empirical Computational Costs; D.6 Axial Attention; D.7 Attention Distance; D.8 Attention Maps; D.9 ObjectNet; D.10 VTAB Breakdown

### BERT

Jacob Devlin, Ming-Wei Chang, Kenton Lee, Kristina Toutanova. arXiv:1810.04805. NAACL 2019 was not in the HTML title block. Appendix A.4 is printed "ELMo ,and".

1. Introduction
2. Related Work — 2.1 Unsupervised Feature-based Approaches; 2.2 Unsupervised Fine-tuning Approaches; 2.3 Transfer Learning from Supervised Data
3. BERT — Model Architecture; Input/Output Representations; 3.1 Pre-training (Task 1 Masked LM; Task 2 Next Sentence Prediction); 3.2 Fine-tuning
4. Experiments — 4.1 GLUE; 4.2 SQuAD v1.1; 4.3 SQuAD v2.0; 4.4 SWAG
5. Ablation Studies — 5.1 Effect of Pre-training Tasks; 5.2 Effect of Model Size; 5.3 Feature-based Approach with BERT
6. Conclusion
Appendix A. Additional Details — A.1 Pre-training tasks; A.2 Pre-training Procedure; A.3 Fine-tuning Procedure; A.4 Comparison of BERT, ELMo, and OpenAI GPT; A.5 Fine-tuning illustrations
Appendix B. GLUE task notes (MNLI, QQP, QNLI, SST-2, CoLA, STS-B, MRPC, RTE, WNLI)
Appendix C. Additional Ablations — C.1 Number of Training Steps; C.2 Masking Procedures

### Still not opened

Fog, Optimizing Subroutines in Assembly Language, is a manual, not one of the papers above. Its contents were not copied. Drepper's memory monograph was skipped in the paper pass. Its section list is still open, with the book list above.
