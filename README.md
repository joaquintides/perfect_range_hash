# perfect_range_hash

We want to study the conditions under which

$$h(x)= \left(Cx \bmod 2^{64}\right)\texttt{ >> } \left(64-m\right) = \left\lfloor\frac{Cx \bmod 2^{64}}{2^{64-m}}\right\rfloor$$

is injective (i.e. a perfect hash function) for a randomly chosen $$0\le C<2^{64}$$ and $$x$$ in a small range $$[a,a+n)$$.
$$h(x)$$ function multiplies its argument by $$C$$ and takes the $$m$$ most signficant bits of the result.
An obvious necessary condition for injectivity is that $$n\le 2^m$$, so we will assume this for the remainder
of our discussion.
The values of $$h\left([a,b)\right)$$ can be written as

$$\left\lfloor\frac{Ca + Ci \bmod 2^{64}}{2^{64-m}}\right\rfloor, i=0,...,n-1.$$

The period of the modular arithmetic progression $$x_i=Ca + Ci \bmod 2^{64}$$ is

$$T = \frac{2^{64}}{\gcd\left(C,2^{64}\right)}=\frac{2^{64}}{2^{v_2(C)}},$$

where $$v_2(C)$$ is the exponent of the maximum power of 2 dividing $$C$$.
A necessary condition for injectivity is that $$T\ge n$$ or
$$v_2(C)\le 64-\left\lceil \log_2 n \right\rceil$$, that is, 
at least one of the 
the $$64-\left\lceil \log_2 n\right\rceil +1$$ least significant bits of $$C$$ is nonzero
(disregarding the case $$C=0$$), which happens with probability

$$P(T\ge n)=1-0.5^{64-\left\lceil \log_2 n\right\rceil+1}=1-2^{\left\lceil \log_2 n\right\rceil-65}.$$

$$P(T\ge n)$$ is very close to 1 when $$n$$ is small, so almost all random choices of $$C$$
will have a large enough period. Now, $$h(x)$$ flattens the values of $$x_i$$ to

$$h_i=\left\lfloor\frac{x_i}{2^{64-m}}\right\rfloor.$$

Two consecutive values $$h_i$$, $$h_{i+1}$$ will we distinct if

$$\left\lfloor\frac{x_i}{2^{64-m}}\right\rfloor\ne$$
