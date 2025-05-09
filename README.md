# perfect_range_hash

We want to the extimate the probability that the function

$$h(x)= \left(Cx \bmod 2^{64}\right)\texttt{ >> } \left(64-m\right) = \left\lfloor\frac{Cx \bmod 2^{64}}{2^{64-m}}\right\rfloor$$

is injective (i.e. a perfect hash function) for a randomly chosen $$0\le C<2^{64}$$ and $$x$$ in a small range $$[a,a+n)$$.
$$h(x)$$ function multiplies its argument by $$C$$ (modulo $$2^{64}$$) and takes the $$m$$ most signficant bits of the result.
An obvious necessary condition for injectivity is that $$n\le 2^m$$, so we will assume this for the remainder
of our discussion. Also, simmetry considerations allows us to assume that the range is simply $$[0,n)$$ (shifting by $$a$$ does
not affect the overall probability (NOT SURE)).

It is trivial to see that $$h(x)$$ can be rewritten as:

$$h(x)=\left\lfloor\frac{Cx}{B}\right\rfloor \bmod 2^m,$$

with $$B=2^{64-m}$$. If we decompose $$C$$ as $$C_qB+C_r$$, then

$$h(x) = \left(C_qx+\left\lfloor\frac{C_rx}{B}\right\rfloor\right)\bmod 2^m,$$

and, listing out the elements in  $$[a,a+n)$$ in the form

$$x_i=a+i, i=0,1,...,n-1,$$

we have

$$ h_i=\left(C_qa+C_qi+\left\lfloor\frac{C_r(a+i)}{B}\right\rfloor\right)\bmod 2^m.$$

The constant term $$C_qa$$ does not affect injectivity, so we can study the sequence

$$ h'_i=\left(C_qi+\left\lfloor\frac{C_r(a+i)}{B}\right\rfloor\right)\bmod 2^m.$$

Now, suppose that $$\left\lfloor\frac{C_r(a+i)}{B}\right\rfloor$$ stays constant for
all $$i=0,1,...,n-1$$. The period of 

$$h''_i=C_qi\bmod 2^m$$

is

$$T=\frac{2^m}{\gcd\left(C_q,2^m\right)}=\frac{2^m}{2^{v_2(C_q)}},$$

where $$v_2(C_q)$$ is the exponent of the maximum power of 2 dividing $$C_q$$.
So, the values $$h''_i$$ for $$i=0,1,...,n-1$$ are all distinct if $$T\le n$$
or $$v_2(C_q)\le m-\left\lceil \log_2 n \right\rceil$$, that is,
at least one of the 
$$m-\left\lceil \log_2 n\right\rceil +1$$ least significant bits of $$C$$ is nonzero, which happens with probability

$$P(T\ge n)=1-0.5^{m-\left\lceil \log_2 n\right\rceil+1}=1-2^{\left\lceil \log_2 n\right\rceil-m-1}.$$

****

The values of $$h\left([a,b)\right)$$ can be written as

$$\left\lfloor\frac{Ca + Ci \bmod 2^{64}}{2^{64-m}}\right\rfloor, i=0,...,n-1.$$

The period of the modular arithmetic progression $$x_i=Ca + Ci \bmod 2^{64}$$ is
(disregarding the case $$C=0$$)

$$T = \frac{2^{64}}{\gcd\left(C,2^{64}\right)}=\frac{2^{64}}{2^{v_2(C)}},$$

where $$v_2(C)$$ is the exponent of the maximum power of 2 dividing $$C$$.
A necessary condition for injectivity is that $$T\ge n$$ or
$$v_2(C)\le 64-\left\lceil \log_2 n \right\rceil$$, that is, 
at least one of the 
the $$64-\left\lceil \log_2 n\right\rceil +1$$ least significant bits of $$C$$ is nonzero, which happens with probability

$$P(T\ge n)=1-0.5^{64-\left\lceil \log_2 n\right\rceil+1}=1-2^{\left\lceil \log_2 n\right\rceil-65}.$$

$$P(T\ge n)$$ is very close to 1 when $$n$$ is small, so almost all random choices of $$C$$
will have a large enough period. Now, $$h(x)$$ flattens the values of $$x_i$$ to

$$h_i=\left\lfloor\frac{x_i}{B}\right\rfloor$$

where $$B=2^{64-m}$$. Now, if $$C\le B$$ we have

$$h_0=\left\lfloor\frac{Ca}{B}\right\rfloor,$$
$$h_1=\left\lfloor\frac{Ca+C}{B}\right\rfloor,$$
