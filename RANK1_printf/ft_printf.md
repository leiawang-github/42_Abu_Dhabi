## My solution:
printf原型是：

`int printf(const char *str, ...)`



1、标准的printf返回值是所有参数的总长度，是一个int，包括两部分：一是用双引号包起来的一个字符串，这是一个固定参数，容易得到其长度；二是后面的所有变长参数（variadic para）的值，变长参数的类型、数量均不可知。所以第一个要处理的点就是，如何在不知道参数个数类型的情况下，获取变长参数的值，也就是类似于（变长参数1: int nbr 对应的nbr的值【nbr的长度，因为printf的返回值是int】；或者变长参数2 char *str 中的str的值【长度】）；我们知道，在printf中，实际上双引号后面的参数都是跟双引号参数以某种方式联系的，那就是用双引号中的%标志符联系的，所以意味着，当我们处理第一部分的字符串时，我们处理中遇到了%符号，并根据后面的字符类型（csiduUp等等），连接到第二部分来；在链接到第二部分后，如果或者变长参数的具体值，就涉及到va_arg知识。



2、va_arg可以用来获取对应类型的变长参数的值；语法是这样的：va_arg(args, 想要获取的参数的数据类型）；比如：当变长参数是 char *str = "hello world" 时，我们运行 va_arg（args, char *）的返回结果就相当于返回"hello world"。要用va_args，我们需要用到一系列套装工具；首先要用va_list args 去装住所有变长参数（包括类型和参数名）；比如装住printf原型中的三个省略号可能表示的int nbr，char c， char *str，void *ptr 等等；然后用va_start(args, str) 来初始化用这套工具，注意这里的第二个参数永远是最后一个固定参数（变长参数之前的参数都叫固定参数）；初始化后就可以使用va_arg来获取变长参数的值了；最后，还需要用va_end来进行结束。这些语法都是遵循固定程式的，重点是要理解va_arg是用来获取变长参数的值的。



3、当我们可以获取变长参数的后，我们就是要根据不同数据类型获取其长度





## Solutions：
[https://csnotes.medium.com/ft-printf-tutorial-42project-f09b6dc1cd0e](https://csnotes.medium.com/ft-printf-tutorial-42project-f09b6dc1cd0e)



## Testers：
[https://github.com/gavinfielder/pft](https://github.com/gavinfielder/pft)

[https://github.com/Mazoise/42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)

[https://github.com/cacharle/ft_printf_test](https://github.com/cacharle/ft_printf_test)



## 
