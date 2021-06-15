# printf 제작

<br/>

## 주제 : printf와 유사한 코드 제작.

<br/>

## 소요시간 : 약 1주일 + 4일 (1월 17일 ~ 1월 20일, 1월 25일 ~ 1월 31일)

계획한 소요시간 : 약 1주일

초과시간 : 약 4일

<br/>

## 프로그램 소개  :

BSD의 libc `printf(3)`와 유사한  `my_printf()`를 만들기.

<br/>

## 요구사항 분석  / printf 동작 정리

<br/>

#### `printf()` 는 *Variadic Function* (가변 인자 함수) 이다.

```c
 int printf(const char * restrict format, ...);
```

* 1번째 인자로 *format String*을 받는다.

* 2번째 인자부터는 [0, N] 범위의 인자 개수를 받을 수 있다.

* `printf("Groot\n");` 와, `printf("Num1 : %d, Num2 : %d\n", n1, n2);` 를 생각해보면, 

  `printf()`가 받는 인자의 개수가 [0, N]까지인 것을 떠올릴 수 있다.

* 가변인자의 사용은

  `va_start()`, `va_arg()`, `va_end()`,` va_list`  이 4개로 사용이 가능하다.

  <br/>

### `printf()`의 Formatting 

`printf()`는 `printf("GROOT\n");`처럼 ***String을 String 그대로*** STDIN에 출력해주기 위한 함수가 아니다.

`printf`의 **f**는 **format**의 약자다. ***string을 목적에 맞게 format 하기 위해*** 사용하는 함수다.

<br/>

`printf`는 

1번째 argument 인 String의  **directives**를 특정 형식/규칙에 맞추어 변환 후 출력해준다.

formatting 해야 할 **directive는** ***conversion specifier***를 보고 해석이 가능하며,

**conversion specifier**는 `%` 로 시작하기에 `%` 뒤에 오는 문자를 보고 **directive**를 해석한다.

<br/>

아래는 BSD의 `printf` 매뉴얼이다.

> ```markdown
>      The format	string is composed of zero or more directives: ordinary	char-
>      acters (not %), which are copied unchanged	to the output stream; and con-
>      version specifications, each of which results in fetching zero or more
>      subsequent	arguments.  Each conversion specification is introduced	by the
>      % character.  The arguments must correspond properly (after type promo-
>      tion) with	the conversion specifier.  After the %,	the following appear
>      in	sequence:
> ```

* Format string은 0개 ~ n개의 directive로 이루어져있다.
* ( %를 제외한 ) Ordinary Character들은 바뀌지 않고 output stream으로 직행한다.
* ( % )conversion specification들은, 주어진 0개부터 n개의 argument를 통해 해석한다.
* 각 argument들은 conversion specifier에 맞게 해석되어야한다.
* ( % ) 뒤에는 다음과 같은 문자(**conversion option**)들이 올 수 있다.

<br/><br/>

### Conversion option - FLAG

Basic subject에서 다루는 printf의 옵션은 다음과 같다.

`-` `0` `*` `.`

<br/>

#### Padding :

> String padding refers to adding, usually, non-informative characters to a string to one or both ends of it.

Padding은  String의 왼쪽, 오른쪽 또는 양쪽에 *정보와는 무관한 문자들*을 붙이는 것을 말한다.

<br/>

`Groot`의 왼쪽에 '#'로 5만큼 padding한다면 ? 

`#####Groot` 

<br/>

#### `0`  : ZERO PADDING

* converted value들이 `' '`보다는 `0`으로 채워진다.

* Padding 되지 않는다면(채워질 자리가 존재하지 않는다면), 채우지 않는다.
* 만약, `.`옵션이 `d i o u i x` 와 같은 *numeric conversion*과 함께 주어졌을 때, `0`옵션은 무시된다.

<br/>

#### `-` : NEGATIVE FIELD WIDTH FLAG

* converted value들이 *Left adjusted*되며, `' '`으로 오른쪽 padding 한다.
* 만약, `0`옵션과 `-`옵션이 동시에 사용되면, `0`옵션은 무시된다.

<br/>

#### `' '` : SPACE

* (signed conversion일 때 적용)
  * Signed conversion : `a A d i e E f F g G`
* 양수일 때, 왼쪽 한 칸을 space 한칸으로 padding한다.

<br/>

####  `+`  : 

* (signed conversion일 때 적용)
  *  ""
* signed conversion 이후에 오는 숫자들에 항상 sign( `+`, `-`이 붙어야한다.)

<br/>

#### `#` : ALTERNATE FORM CONVERSION

* `c, d, i, n, p, s, u` 는 별 효과가 없다.

* `o, x, X, a, e, E, f, F, g, G` conversion만 효과있다.

  * `o` : 숫자 앞에 `0`을 붙여주기 위해서 precision을 하나 강제로 증가시킨다.

  * `x, X` : **0이 아닌 수에 대해서 ** , `0x` 또는 `0X`를 앞에 붙인다.

  * `a A e E f F g G` :   

    모든 경우에 소수점을 padding한다. 

    일반적인 경우에는 소수가 붙을 때만, .이 padding된다.

    > ```markdown
    > 	the result	will always contain a decimal
    > 	point, even if no	digits follow it (normally, a decimal
    > 	point appears in the results of those conversions	only
    > 	if a digit follows).
    > ```
    >
    > ```markdown
    > 	For	g and G	conversions, trailing
    > 	zeros are	not removed from the result as they would oth-erwise be.
    > ```

    * `G g`  의 경우 : 0이 잘리는것을 방지한다.

<br/>

### Conversion Option : FIELD WIDTH

​	최소한의 width를 나타낸다.

* **LENGTH(converted value)가** width보다 작을 경우, 적용되는 FLAG에 따라서 Padding된다.

  * (의문 : width와 #가 함께 쓰인다면, prepending 되는 0, 0x는 width에 포함이 되는가?)

  *  == prepending 되는 0x까지 고려해서 width를 적용시킨다.

    ```c
    printf("[%#08x]\n", 30); //[0x00001e] => 0x + 0000 + 1e => 8
    ```

<br/>

### Conversion option : PRECISION

​	***conversion type*** 에 따라서 의미가 달라진다.

* `s` : 최대로 뽑아줄 character의 개수를 명시한다.

* `dioux` : 최소한의 **digit(숫자의 자리 수)**를 명시한다.

* `aAeEfF` : 소수점 뒤에 나올 숫자의 **digit**을 명시한다.

  > ```markdown
  > 	the number of digits to appear
  > 	 after the decimal-point for a,	A, e, E, f, and	F conversions
  > ```

* `g, G` : 최대롤 뽑아줄 **(유효 숫자)significant digit**를 명시한다.

<br/>

### Conversion Option : LENGTH MODIFIER

* argument의 size를 명시.

  > ```markdown
  > 	  Modifier	   d, i		  			o, u,	x, X				n
  > 	 hh		   		signed char	 	 unsigned char			signed char *
  > 	 h		   		short	 	 	unsigned short			short *
  > 	 l (ell)	  	 long		  	unsigned long			long *
  > 	 ll (ell ell)	   long	long	  unsigned long	long	long long *
  > ```

  > ```markdown
  > 	 Modifier    a,	A, e, E, f, F, g, G
  > 	 l (ell)     double (ignored, same behavior as without it)
  > 	 L	     long double
  > ```

  > ```markdown
  > 	 Modifier    c	       s
  > 	 l (ell)     wint_t    wchar_t *
  > ```

<br/>

#### wint_t, wchar_t * : 







### Double, float의 동작 방식



### double, float, 그리고 유효숫자.







<br/><br/>

## 설계 과정 : 

> 설계 이전에 코딩하지 말자.

<br/>

#### Format string 출력과정에 대한 고민

가장 처음에는 Format string의 출력 과정에서 고민했었다.

생각난 방법은 두 가지였다.

1. 모든 문자들을 하나의 Buffer에서 관리하여
   Ordinary Character도 버퍼에 넣고, Directive에 의해서 Converted 된 Character들도 Buffer에 넣은 뒤,
   한번에 write로 출력하기.
2. 일반 문자열이 나오면 `write`로 일일이 출력해주다가 `%`가 나오면, 그걸 파싱한 뒤에 `write`로 출력해주면서
   위 과정을 반복하기.

<br/>

1번 방법을 사용한다면 `write`에 의한 overhead가 줄어들어 I/O 횟수가 줄어들것이라 생각해서 

좋은 방법이라고 생각했으나, 

정작, Buffer의 크기를 정할 수 없을 뿐더러 Buffer의 크기를 늘려주면서 Dynamical Array를 만들고, copy하는 overhead가 I/O overhead보다 더 클 수 있다.

내부적으로 String을 위한 공간을 allocate하던, 아니면 Buffer에 바로 넣어주던 간에,

어쨌든 Buffer에 copy를 해야되는 overhead가 발생하기 때문에 2번 방법과 효율의 차이를 느끼지 못했다.

<br/>

따라서, 1번 방법과 2번 방법을 혼용해서 

Ordinary Character들은 한번의 `write` 호출로 STDIN에 출력해주고,

Conversion이 필요한 directive들은 한번의 `write`호출로 출력해주기로 했었다. 

<br/>

> **Conversion이 필요한 directive들은 한번의 `write`호출로 출력해주기로 했었다.** 

Conversion 한 것을 한번의 `write` 호출로 뽑아내겠다는 생각은 **정말, 100%, 오만한 생각이었다.**

적어도 *nminette*가 존재하는 한, 정말 오만했다. 

<br/>

한번의 `write` 호출로 conversion한 것을 뽑아내기 위해서는 다시 방법이 두가지로 나뉘는데,

1. 여러번의 `strjoin`으로 필요한 문자들(Padding이 되었던, sign이 되었던)을 붙여가면서

   마지막에 완성된 *completed string*을 `write `로 출력해주는 방법

2. parsed info를 한번에 해석한 뒤, 한번의 allocation을 하여 Buffer를 만든 뒤

   정보를 해석하여, 각종 정보를 Buffer에 때려넣는 방법

   <br/>

위 두가지 방법 중 1번 방법을 택하고 약 4일간 코딩을 하다,

**nmin**과 **NULL guard**에 머리가 깨졌다.

<br/>

`strjoin` 사용 시, 공간의 alloaction 실패로 NULL값이 반환되는 경우가 있기 때문에

특별히 **Null guard**에 신경을 많이 써야한다.

**NULL guard**하는데 코드 4줄 5줄을 사용하며, allocation을 여러번 해주다 보니, 

코드 길이가 매우 길어졌으며, 원하는 대로 모듈화가 이루어지지 않았다.

또, `strjoin`을 수많이 호출하다 보니,  최소한 3개의 `char *` 변수를 만들고, 그 안에서 변수를 돌려써야 했기 때문에 쓸데없는 함수를 만들어야 했다.

이는 좋지 않은 모듈화를 낳았다.

예를 들어, 

```c
void	free_all(void *a, void *b, void *c, void *d)
{
	free(a);
	free(b);
	free(c);
	free(d);
}

char	*printer_width_helper(t_info *p_info, int len, char *sub)
{
	char	*front;
	char	*back;
	char	*temp;
	char	*join;

	front = sub;
	back = sub;
	if ((temp = (char *)calloc(len + 1, 1)) == NULL)
		return (NULL);
	temp[len] = '\0';
	ft_strfill(temp, 0, len - 1, ' ');
	if (p_info->flag & F_LEFT_JUSTIFY)
		back = temp;
	else
		front = temp;
	if ((join = ft_strjoin(front, back)) == NULL)
		return (NULL);
	free_all(front, back, NULL, NULL);
	return (join);
}
```

code line 을 줄이기 위해 `free_all`이라는 함수를 만들었으며, 

또, 단순히 함수 길이를 줄이기 위한 함수인  `printer_width_helper()` 함수를 만들었다.

원하는 대로 코드가 나오지 않아 짜면서도 굉장히 불안했다.

<br/>

이대로는 안되겠다 싶어서 아예 한번의 `write`호출로 conversion한 값을 뽑아내는 것을 포기하고,

```c
	if (info->flag & F_LJUST)
	{
		if (sign)
			ft_putchar_fd('-', 1);
		while (info->prec-- > 0)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(str, 1);
		while (blank_num-- > 0)
			ft_putchar_fd(fill, 1);
	}
```

와 같이 여러번의 `write`를 사용하는 방법으로 바꾸었다. 

차라리 2번 방법을 사용했었더라면 리팩토링을 하지 않았어도 되었을지도 모른다.

<br/>

결국,` my_printf()`는 한번의 리팩토링을 걸쳐서 여러번의 `write`를 사용하도록 바꾸었다. 

<br/><br/>

#### 갖가지 TestCase를 만들어본 것.

gcc의  `Warning` 플래그를 사용하여 컴파일하기 때문에, 

공식 테스터기 ***M***에서 잡지 않는 플래그를 분석하기 위해서 모든 TestCase를 만들어 보았다.

일일히 코드를 손으로 작성해나가면서 

*M이 잡지 않는 플래그는 작성안해도 되니까, 피해가도 되니까 이렇게 하면 시간 단축이 되지 않을까?* 생각했지만,

정작 manual을 소홀히 했기 때문에 오히려 시간이 오래 걸리는 결과를 낳았다.

> RTFM!

manual 대로 작성했다면, Testcase를 일일히 만들어도 되지 않았기 때문에, 시간단축이 되었을지도 모른다.

Testcase를 테스트하느라 약 이틀정도를 소비한 것을 생각하면, 

manual을 소홀히 한 내 잘못이 크다.

**manual을 잘 읽어보라는 교훈을 얻었다...**

<br/><br/><br/>

### 설계 1단게: 틀 구상

0. Parsing한 정보를 담고 있는 구조체 `t_info`를 정의한다.

   ```c
   typedef struct	s_info
   {
   	int		flag;
   	int		width;
   	int		prec;
   	char	type;
   }				t_info;
   ```

   <br/>

1. `%`전까지 출력

2. `%`를 만났다면, Parsing 함수로 Directive/Conversion specifier의 정보를 parsing한다.

   정보는 `t_info` 구조체에 담는다.

3. Parsing한 정보(t_info의 각각의 element들)를 바탕으로 `print_handler_xxxxxx`로 direct한다.

4. Parsing한 정보를 바탕으로 가변인자 리스트에서 formatting 하면서 출력한다.

5. format string이 NULL일때까지 ***1 - 4*** 과정을 반복한다.

<br/>

### 설계 2단계 : submodule 제작.

​	구상한 함수에서 사용하기 위한 submodule을 library에 추가했다. 

예를 들어, 기존에 존재했던 `itoa` 로는 `unsigned int`의 음수의 언더플로우를 해결할 수가 없었기 때문에

  `utoa`나, `utox`같은 submodule이 필요하게 되었다.

기존 함수를 약간만 고치긴 했지만, 꼭 필요한 작업이었다. 

<br/>

### 설계 3단계 : 설계 검증.

​	설계한 pseudo code를 검증하는 시간을 가졌다.

<br/><br/>

### 구현 : 

​	구현하는 과정에서 어려움을 겪었던 부분은, 

`d u i x X c s p ` type들을 플래그를 고려하면서 출력해주는 부분의 알고리즘을 짜는 것이 제일 어려웠다.

`c s p`같은 경우는, 사용되는 플래그들이 적기 때문에 신경써야할 부분이 많지 않았기 때문에 괜찮았지만, 

`i u x X d`는, `-` `0` 플래그들을 고려해주어야했기 때문에 출력 순서에 신경을 써야했다.

<br/>

`0`플래그가 있을 경우, 

`( "[%010d]", -12345 )  // -000012345`처럼 음수가 앞으로 온다.

따라서, 0플래그가 있을 땐, 음수를 먼저 뽑아주도록 했다.

<br/>

`-`플래그가 있을 경우, 

Padding character( `' '`, `0` )의 출력 순서가 `-`플래그가 존재하는 경우와는 달라지기 때문에, 

`-`플래그가 존재하는 경우를 따로 빼서 출력순서를 달리했다. 

<br/>

**manual**을 읽지 않았기 때문에, 어느 부분에서 무시가 되는지 알 수 없었고,

결국 헤메는 결과를 낳았다.

<br/>

초기에 line 제한 을 신경쓰면서 코딩했기에 코드의 구조가 바뀌면 코드의 길이를 줄여주면서 코딩했어야 했다.

이런 강박적 습관에서 오류를 겪었다.

이제는 초기 코드를 짤 때, line제한을 신경쓰지 않도록 한다. 

<br/><br/>



## 오류

<br/>

+ 미리 만들어놓은 라이브러리의 함수에서 

  한 경우는 stack에 있는 데이터를 반환하고 `return ("")`

  또 한 경우는 heap에 있는 데이터를 반환했기 때문에 `return (malloced data)`

  free() 시 stack에 있는 데이터를 반환하는 경우가 발생했다. 

  해당 경우를 수정하기 위해 모든 경우에 heap에 있는 데이터를 반환하여 오류를 해결했다.

  <br/>

+ `va_arg`를 사용할 때, n byte 자료형을 m byte 자료형으로 읽었기 때문에, trash value가 나왔었다. 

  따라서, n byte value를 n byte 자료형으로 읽음으로써 해결했다. 

  * 해당 내용은 아래 링크에서 자세히 알 수 있다. 
    https://stackoverflow.com/questions/32261736/variadic-function-passing-long-but-reading-as-va-argarglist-int?rq=1

  * > Running this when compiled with GCC 64 bit results in:
    >
    > ```c
    > Got [TestInt] with value [0]
    > Got [TestIntNegative] with value [4294967295]
    > Got [TestLong] with value [0]
    > Got [TestLongNegative] with value [-1]
    > ```
    >
    > Which makes sense because I'm guessing this is getting interpreted as:
    >
    > ```c
    > 0000 0000 0000 0000 0000 0000 0000 0000 1111 1111 1111 1111 1111 1111 1111 1111
    > ```
    >
    > So padding an additional 32 bits to represent the long and we get 2^32 - 1 instead of a negative number. What I'm wondering however is if I change the va_arg read to read the value as an int this appears to work regardless of whether an int or long is passed e.g

<br/>

* 짜잘한 구현 오류들이 좀 많았다. 더 자세한 설계를 하고 코딩에 들어가야했지 않았나 싶다.

<br/><br/>



## 느낀점 

많이 아쉬웠다.

**Manual**을 보지 않아 시간을 날린 게 정말 아쉬웠으며, 

원치 않았던 리팩토링까지 하게 되어 아쉬웠다. 

<br/><br/>

***고칠 점  :***

1. 코드를 짬에 있어서 **line**제한을 신경쓰지 말 것 .
2. **Manual을 읽을 것 .**
3. Tester를 적극 활용할 것.

