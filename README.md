if p is a prime of the form 12*x+5

then this writing

36*m^2+18*m+4*n^2+2*n+3=(p+1)/2

is unique with n and m in Z

and I have the proof


Conjecture

if 12*x+5 is not prime

or there are no solutions

or has more than one solution

or if it has one gcd(4*n+1.4*m+1)!=1




I think the best possible implementation is:

- I take two numbers min and max as input (which are the ends of the interval I where I want to search for primes)

- I create a matrix M[(max-min)/12][3] and initialize it to 0

- I calculate the interval of m and for each m I calculate the interval of n

 - therefore for each pair (m,n) in the respective ranges I calculate P=2*d-1=2*(36*m^2+18*m+4*n^2+2*n+3)-1
 
 - I'm going to increase M[(P-min)/12][0] by 1,
 
      -if it's the first time I store m in M[(P-min)/12][1], I store n in M[(P-min)/12][2]

- when I'm done I'll scroll through the matrix and if this value M[i][0] == 1 I'll do GCD(4*(M[i][1])+1,4*(M[i][2])+ 1) and if GCD ==1 I will print P=min+12*i



I implemented it in C with the gmp-6.3.0 library like this:

instead of the matrix M I created three arrays

I called

M[][0] -> occurrences[]

M[][1] -> m[]

M[][2] -> n[]

takes a number from input.txt

which is the minimum of the range defined by

#define interval_size 100 (i.e. see if 100 elements of the form 12*x+5 are prime [interval_size can also be increased])

and returns all primes of the form 12*x+5 in that range

I apologize if I didn't use dynamic memory allocation

