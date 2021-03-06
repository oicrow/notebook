# Asympototic Notation
used to describe the running time of an algorithm (efficiency, time complexity)


## Big O notation
*O*: on the order of

maximum running time in the worst case of an algorithm

upper bound



> *O*(*n^2*)            bubble sort, selection sort
>
> *O*(*n* log *n*)      merge sort
>
> *O*(*n*)              linear search
>
> *O*(log *n*)          binary search
>
> *O*(1)


## Omega notation
Ω: omega of

minimum running time in the best case of an algorithm

lower bound



> Ω(*n^2*)              selection sort
>
> Ω(*n* log *n*)        merge sort
>
> Ω(*n*)                bubble sort
>
> Ω(log *n*)
>
> Ω(1)                  linear search, binary search


## Theta Notation
Θ: theta of

use when big O and omega is identical

upper bound == lower bound


> Θ(*n^2*)              selection sort
>
> Θ(*n* log *n*)        merge sort
>
> Θ(*n*)                
>
> Θ(log *n*)
>
> Θ(1)                  
