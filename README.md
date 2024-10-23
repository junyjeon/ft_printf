<div align="center">
  <h1>🖨️ ft_printf</h1>
  <p>42Seoul의 네 번째 프로젝트: 나만의 printf 함수 만들기</p>

  <img src="assets/04_ft_printf_review.jpg" alt="ft_printf Evaluation" width="800">

  [![42 Score](https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge&logo=42)](https://github.com/your-username/ft_printf)
  [![Norminette](https://img.shields.io/badge/Norminette-passing-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)
</div>

## 📋 목차
1. [프로젝트 소개](#-프로젝트-소개)
2. [필수 요구사항](#-필수-요구사항)
3. [구현 가이드](#-구현-가이드)
4. [상세 구현 가이드](#-상세-구현-가이드)
5. [테스트 방법](#-테스트-방법)
6. [참고 자료](#-참고-자료)

## 🎯 프로젝트 소개
ft_printf는 C 표준 라이브러리의 printf 함수를 재구현하는 프로젝트입니다. 가변 인자를 처리하고 다양한 서식 지정자를 지원하는 함수를 만듭니다.

### 주요 학습 목표
- 가변 인자 함수 구현 방법
- 문자열 파싱과 처리
- 메모리 관리와 최적화
- 복잡한 함수의 모듈화

## 📃 필수 요구사항

1. **함수 프로토타입**
   ```c
   int ft_printf(const char *format, ...);
   ```

2. **필수 서식 지정자**
   - `%c`: 단일 문자 출력
   - `%s`: 문자열 출력
   - `%p`: void * 포인터 인자를 16진수로 출력
   - `%d`: 10진수 정수 출력
   - `%i`: 10진수 정수 출력
   - `%u`: 부호 없는 10진수 출력
   - `%x`: 16진수 소문자로 출력
   - `%X`: 16진수 대문자로 출력
   - `%%`: % 문자 출력

3. **반환값**
   - 출력된 문자의 개수를 반환
   - 오류 발생 시 음수 반환

## 🛠 구현 가이드

### 1. 기본 구조
```c
int ft_printf(const char *format, ...)
{
    va_list args;
    int     count;
    
    if (!format)
        return (-1);
    va_start(args, format);
    count = parse_and_print(format, args);
    va_end(args);
    return (count);
}
```


### 2. 서식 지정자 처리
```c
static int handle_format(char specifier, va_list args)
{
    if (specifier == 'c')
        return (print_char(va_arg(args, int)));
    if (specifier == 's')
        return (print_string(va_arg(args, char *)));
    if (specifier == 'p')
        return (print_pointer(va_arg(args, void *)));
    if (specifier == 'd' || specifier == 'i')
        return (print_integer(va_arg(args, int)));
    if (specifier == 'u')
        return (print_unsigned(va_arg(args, unsigned int)));
    if (specifier == 'x' || specifier == 'X')
        return (print_hex(va_arg(args, unsigned int), specifier));
    if (specifier == '%')
        return (print_char('%'));
    return (0);
}
```


## 📝 상세 구현 가이드

### 서식 지정자 상세 설명

1. **문자와 문자열 (%c, %s)**
   ```c
   // 문자 출력
   static int print_char(char c)
   {
       return (write(1, &c, 1));
   }

   // 문자열 출력
   static int print_string(char *str)
   {
       if (!str)
           return (write(1, "(null)", 6));
       return (write(1, str, ft_strlen(str)));
   }
   ```

2. **숫자 관련 (%d, %i, %u)**
   ```c
   // 정수 출력
   static int print_number(int n)
   {
       char    digit;
       int     count;
       
       count = 0;
       if (n == -2147483648)
           return (write(1, "-2147483648", 11));
       if (n < 0)
       {
           count += write(1, "-", 1);
           n = -n;
       }
       if (n >= 10)
           count += print_number(n / 10);
       digit = n % 10 + '0';
       count += write(1, &digit, 1);
       return (count);
   }
   ```

### Makefile 구조
```makefile
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

## 🧪 테스트 방법

1. **기본 테스트**
   ```c
   int main(void)
   {
       // 기본 서식 지정자 테스트
       ft_printf("Character: %c\n", 'A');
       ft_printf("String: %s\n", "Hello");
       ft_printf("Number: %d\n", 42);
       ft_printf("Hexadecimal: %x\n", 255);
       
       // 에러 케이스 테스트
       ft_printf("Null string: %s\n", NULL);
       ft_printf("Zero pointer: %p\n", NULL);
       
       return (0);
   }
   ```

2. **컴파일 및 실행**
   ```bash
   make
   gcc -Wall -Wextra -Werror main.c libftprintf.a
   ./a.out
   ```

## 📚 참고 자료
- [printf 함수 매뉴얼](https://man7.org/linux/man-pages/man3/printf.3.html)
- [가변 인자 함수 설명](https://en.cppreference.com/w/c/variadic)
- [IEEE-754 부동 소수점](https://en.wikipedia.org/wiki/IEEE_754)