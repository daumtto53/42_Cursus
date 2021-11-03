# cpp02

1. ad-hoc polymorphism
2. operators overload
3. Orthodox canonical classes



## Orthodox Canonical Form

1. default constructor
2. copy constructor
3. assignation operator overload
4. destructor





## default constructor

* 생성자를 정의하면 명시 디폴트 생성자를 다시 정의하지 않을 경우 디폴트 생성자로 객체를 만드는 것이 불가능하다.
* 디폴트 생성자 선언 방식 : 
  * 생성자 매개변수를 주지 않고 `Class:Class constructor();` 과 같이 선언
  * 매개변수에 default 한 인수를 주는 방식.



## copy constructor

* 객체를 만들 때 불려짐.

  * 기존에 생성된 객체를 이용해서 새로운 객체를 초기화 하는 경우

  * ```c++
    func(Class a)
    ```

    와 같이 Call-by-value 형식의 매개변수에서 객체를 인자로 주었을 때

  * ```c++
    Class func () 
    {
      Class a;
      return a;
    }
    ```

    와 같이 객체를 참조형이 아닌 스택영역에서 리턴하는 경우 nvo에 의해 객체가 복사되어 리턴된다.



* 임시객체를 사용하여 값을 전달하는 방식을 선호 ( 동적 메모리 할당 후 누수 문제가 있어서...)



### 복사생성자와 임시객체

아래의 경우, "초기화"이기 떄문에 내부에서 복사생성자가 1번 불린다.

```c++
A a1 = retObject(); // 1번
```



## assignment operator

예시 : 

```c++
A& operator = (const A & iToAssign)
{
  if (this == & iToAssign)  // Check for self assignment
    return *this;
  else
  {
    this->_A = itoAssign.s; ..
     ...
      ...
  }
  return *this;   // Return the reference to object for chaining(a = b = c)
}
```





### 할당연산자와 임시객체

아래의 경우, a2에 대해서 기본생성자가 불려지고, retobject()는 임시객체를 만들어 복사생성자를 부르고, 이후 그 임시객체를 매개로 하여 a2가 할당연산을 한다.

```c++
A a2;
a2 = retObject();   // 2번
```



## copy constructor vs assignment operator

* 복사 생성자는 객체를 만들 때
* 대입 연산자는 이미 존재하는 개체에 대해 적용.



### 초기화와 할당

초기화 : 변수 선언과 동시에 값을 할당

할당 : 변수를 만든 이후, 값을 넣는 행위.





## 임시객체와 Rvo/nrvo



다음과 같이 생성자로, 컴파일러에 의해 복사생성자를 부르지 않고, 할당된다.

컴파일러가 좋아지면서 rvo, nrvo를 

```c++
A retObject()
{
  return A("woohyeon");
}

A a = retObject(); // 1
A a2;
a2 = retObject();  // 2
```

```c++
A retObject()
{
  A a("woohyeon");
  return a;
}
```

와 같이 부를 수 있다.







----

