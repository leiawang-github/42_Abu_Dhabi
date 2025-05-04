

# 分步骤说明如何解决pushswap项目

1. 第一步读取并存储用户输入的参数，这个参数就是栈a中的元素，也就是我们需要sort的数字，涉及的函数：
   - 用户输入非整数： 1 2 3 9 8.7 abc ——> "Error"  【int is_integer】
   - 用户输入重复的数字 ：1 2 3 4 4 6 ->“Error”     [int is_duplicate]
   - 用户输入超出计算机最大可接受整数范围的数字：如果用户输入 123456234342514125325345 ->“Error” [int within_limits]
   - 用户输入奇葩但是可以接受的数字 “    +9” 32 “   -78” -> 需要调用另外的函数来处理这种输入 [ft_atoi] [ft_split]
   - 即使在处理完以上输入后，因为栈a最初是一个空栈（也是我们申明的），将读取到的数字存进去本身也涉及到一个入栈函数push()，push到栈a，push的内容是av[i]，push没有返回值 【void push（char **av，t_stack* stack_a）】

2. 