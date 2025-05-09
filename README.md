# perfect_range_hash

We want to the estimate the probability that the function

$$h(x)= \left(Cx \bmod 2^{64}\right)\texttt{ >> } \left(64-m\right) = \left\lfloor\frac{Cx \bmod 2^{64}}{2^{64-m}}\right\rfloor$$

is injective (i.e. a perfect hash function) for a randomly chosen $$0\le C<2^{64}$$ and $$x$$ in a small range $$[a,a+n)$$.
$$h(x)$$ function multiplies its argument by $$C$$ (modulo $$2^{64}$$) and takes the $$m$$ most signficant bits of the result.
An obvious necessary condition for injectivity is that $$n\le 2^m$$, so we will assume this for the remainder
of our discussion.

It is trivial to see that $$h(x)$$ can be rewritten as:

$$h(x)=\left\lfloor\frac{Cx}{B}\right\rfloor \bmod 2^m,$$

with $$B=2^{64-m}$$. If we decompose $$C$$ as $$C_qB+C_r$$, then

$$h(x) = \left(C_qx+\left\lfloor\frac{C_rx}{B}\right\rfloor\right)\bmod 2^m,$$

and, listing out the elements in  $$[a,a+n)$$ in the form

$$x_i=a+i, i=0,1,...,n-1,$$

we have

$$ h_i=\left(C_qa+C_qi+\left\lfloor\frac{C_r(a+i)}{B}\right\rfloor\right)\bmod 2^m.$$

The constant term $$C_qa$$ does not affect injectivity, so we can study the sequence

$$h'_i=\left(C_qi+\left\lfloor\frac{C_r(a+i)}{B}\right\rfloor\right)\bmod 2^m$$

and disregard the small-probability case $$C_q=0$$. Now, suppose for the moment being that
$$\left\lfloor\frac{C_r(a+i)}{B}\right\rfloor$$ stays constant for
all $$i=0,1,...,n-1$$; the period of 

$$h''_i=C_qi\bmod 2^m$$

is

$$T=\frac{2^m}{\gcd\left(C_q,2^m\right)}=\frac{2^m}{2^{v_2(C_q)}},$$

where $$v_2(C_q)$$ is the exponent of the maximum power of 2 dividing $$C_q$$.
So, the values $$h''_i$$ for $$i=0,1,...,n-1$$ are all distinct if $$T\ge n$$
or $$v_2(C_q)\le m-\left\lceil \log_2 n \right\rceil$$, that is,
at least one of the 
$$m-\left\lceil \log_2 n\right\rceil +1$$ least significant bits of $$C_q$$ is nonzero, which happens with probability

$$P(T\ge n)=1-0.5^{m-\left\lceil \log_2 n\right\rceil+1}=1-2^{\left\lceil \log_2 n\right\rceil-m-1}.$$

This does not complete the analysis, as we have to take into accout the
perturbation introduced by $$\left\lfloor\frac{C_r(a+i)}{B}\right\rfloor$$.
The number of times the value of this term changes for the range considered is

$$\left\lfloor\frac{C_r(a+n-1)}{B}\right\rfloor- \left\lfloor\frac{C_ra}{B}\right\rfloor \ge \left\lfloor\frac{C_r(n-1)}{B}\right\rfloor,$$

which, considering that $$C_r$$ is uniformly distributed in $$[0,B)$$, we can approximate
in the average case by

$$\frac{(B-1)(n-1)}{2B}.$$

Each value change introduces a possibility of a collision with a probability that
we estimate, without formal justification, as $$n/2^m$$.
Wrapping it all together, we have

$$P(h(x)\text{ is injective}) \approxeq \left(1-2^{\left\lceil \log_2 n\right\rceil-m-1}\right) \left( 1- \frac{n}{2^m}\right)^{\frac{(B-1)(n-1)}{2B}}.$$

