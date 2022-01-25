# Memory
Data, or the whole bunch of 0's and 1's to process, are temporarily stored in some parts of RAM  
There is an agreed order of which types of data are stored in which parts of RAM  
<br/>

    Machine Code : complied codes by clang
    - - -
    Global variables or data
    - - -
    Heap: data allocated by malloc
    ...
    Stack: Local variables - main "Stack Frame" at the bottom

<br/>

### Call by Value
default function call type  
cannot affect data in main stack frame
<br/><br/>

### Call by Reference
function call by pointers
can affect data in main stack fram with pointers