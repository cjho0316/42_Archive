<a name="readme-top"></a>

<div align="center">
  <img width="826" alt="스크린샷 2024-02-09 오후 5 37 26" src="https://github.com/cjho0316/42_Archive/assets/83046766/c34af896-c7a7-4382-a472-60d922d37f92">
</div>

<!-- TABLE OF CONTENTS -->

# 📗 Table of Contents

- [📖 Libft](#libft)
- [〰️ get_next_line](#get_next_line)
- [🖨️ ft_printf](#printf)
- [🖥️ born2beroot](#born2beroot)
- [🗣️ minitalk](#minitalk)
- [👋 so_long](#so_long)
- [🥞 push_swap](#push_swap)
- [🐚 minishell](#minishell)
- [🤔 philosopher](#philosopher)
- [🎲 cub3d](#cub3d)
- [🎱 cpp_module](#cpp_module)
- [🕸️ webserv](#webserv)
- [🔝 inception](#inception)
- [🎉 ft_transcendence](#ft_transcendence)

    
</br></br></br>

# Libft <a name="libft"> 📖 </a>
##### Duration: 2022.07.04 ~ 2022.07.17

다양한 C언어 내장 함수들을 직접 구현해보는 프로젝트, 나만의 함수 라이브러리 만들기 <br>
**허용된 함수 : malloc, write, free** <br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

[Libft link](https://github.com/cjho0316/42_Archive/tree/main/libft)

<!-- Features -->

### Key Features <a name="key-features"></a>

- 최소한의 시스템콜 함수로 나만의 C library 만들기
- 표준 library에 있는 함수 원형을 보면서 각 함수의 목적은 무엇이고, 어떻게 구현해야할지 파악하기
- 공식 Reference를 찾아보고 구현하는 역량 기르기
- C언어와 더 친숙해지기 (const, sizt_t, 연결리스트, 함수포인터)
- Makefile 활용하기
</br></br></br>


# get_next_line <a name="get_next_line"> 〰️ </a>
##### Duration: 2022.07.17 ~ 2022.08.12

fd를 읽으면서 개행(\n) 단위로 char *로 리턴해주는 함수 만들기 <br>
파일의 문자를 읽을 때 한번에 읽어오지 않으며, 함수를 여러번 호출해도 잃어버리는 문자가 없어야 하고, 여러 fd를 번갈아 읽어도 잃어버리는 문자가 없어야 함<br>
**허용된 함수 : read, malloc, free** <br>
전역변수 사용 금지, static 변수 1개 사용 가능 <br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

[get next line](https://github.com/cjho0316/42_Archive/tree/main/gnl)

<!-- Features -->

### Key Features <a name="key-features"></a>

- 파일디스크립터(fd) 이해 및 사용
- read함수 사용
- 연결리스트 활용
- lldb를 사용한 디버깅
- C 컴파일 옵션 -g3 -fasnitize=address를 사용한 메모리 참조 오류 검사
- 연결리스트의 개념을 확실히 익히고 자유롭게 사용할 수 있게 됨 (2중 연결리스트를 사용하여 구현함)
</br></br></br>



# ft_printf <a name="printf"> 🖨️ </a>
##### Duration: 2022.08.10 ~ 2022.08.12
<stdio.h> 에 있는 printf 함수 구현하기 <br>
기본 구현 : c s p d i u x X o O % 의 형식에 대해 구현하기 <br>
**허용함수 : malloc, free, write, va_start, va_arg, va_copy, va_end** <br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

[ft_printf link](https://github.com/cjho0316/42_Archive/tree/main/printf)

<!-- Features -->

### Key Features <a name="key-features"></a>

- 가변인자가 무엇이고, 메모리상에서 어떻게 값을 읽는 것인지
- 경우를 따져가며 프로그래밍하기(flag와 서식에 맞게 출력하기)

</br></br></br>

# born2beroot <a name="born2beroot"> 🖥️ </a>
##### Duration: 2022.08.10 ~ 2022.08.12
VM 사용해보기 (virtual Box)<br>
VM 운영체제 설치해보고 각종 설정 해보기<br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

<!-- Features -->

### Key Features <a name="key-features"></a>
- VM(virtual machine)이란?
- debian, centOS 운영체제 특성 파악 및 vm에 CLI 버전 설치해보기 (+ 운영체제란? 리눅스란? 커널이란?)
- LVM(Logical Volume Manager) 개념 알고 이것으로 vm 설치하기
- 패키지 관리 시스템 사용해보고 패키기 설치해보기
- AppAmor(debian) 설치 및 실행해보기
- sudo가 무엇인지 알고 설치 및 사용해보기
- debian의 사용자 및 그룹 설정하기, 비밀번호 정책 설정
- SSH 설치 및 원격 접속 해보기(ssh, port forwarding)
- UFW 패키지 설치 및 설정 (방화벽, 방화벽 설정 패키지)
- CRON 사용하여 컴퓨터 시스템 상황 띄우기

</br></br></br>

# minitalk <a name="minitalk"> 🗣️ </a>

##### Duration: 2022.08.12 ~ 2022.10.05
UNIX signal (소켓통신)을 활용한 서버-클라이언트 메세지 보내기<br>
SIGUSR1, SIGUSR2 의 두가지 신호를 통해서 메세지 보내고 받는 프로그램 만들기<br>
보너스파트 : 유니코드 지원, 서버에서 받은 signal개수 확인하는 작업 추가<br>
**허용함수 : write, signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit**<br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

[minitalk link](https://github.com/cjho0316/42_Archive/tree/main/minitalk)

<!-- Features -->

### Key Features <a name="key-features"></a>

- UNIX signal을 통한 통신, 커널(시스템콜)을 통해 프로세스간 통신
- signal 관련 함수
- PID, 유니코드, UTF-8 인코딩 형식
- Process에 대한 개념
- signal을 다루는 함수들에 대한 이해
- UFT-8 형식에 대한 이해. write함수로 출력시해당 바이크 단위로 출력하지 않아도, 터미널이 UTF-8 형식이라면 알아서 바이트단위로 묶어서 출력해줌
</br></br></br>



# so_long <a name="so_long"> 👋 </a>
##### Duration: 2022.10.05 ~ 2022.10.10
mlx 라이브러리로 만들어보는 간단한 2D 게임<br>

<br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

[so_long link](https://github.com/cjho0316/42_Archive/tree/main/so_long)

<!-- Features -->

### Key Features <a name="key-features"></a>

- **간단한 WSAD 방향키로 진행할 수 있는 간단한 2D 게임 제공**
</br></br></br>


# push swap <a name="push_swap"> 🥞 </a>

##### Duration: 2022.10.12 ~ 2022.12.25
프로그램에 들어오는 인자를 스택에 쌓고, 빈 스택 하나를 이용하여 정렬하기<br>
스택안에서 요소들을 옮기는 명령어가 주어지고, 명령어 최소사용으로 정렬하기<br>
보너스파트 : checker program 만들기(정렬 여부 확인)<br>
**허용함수 : read, write, malloc, free, exit**<br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

[push_swap link](https://github.com/cjho0316/42_Archive/tree/main/push_swap)

<!-- Features -->

### Key Features <a name="key-features"></a>
- 스택의 의미, 스택 구현 방법(배열, 연결리스트)
- 다양한 정렬 알고리즘과 알고리즘에 따른 시간 복잡도
- 시간 복잡도(big-O)를 따지는 방법
- 파이프라인 사용시 앞 프로그램의 fd 1이 뒷 프로그램의 fd 0으로 이어짐
</br></br></br>

# minishell <a name="minishell"> 🐚 </a>
##### Duration: 2022.12.25 ~ 2023.01.17
bash shell 만들기 (bash manual)<br>
몇몇 명령어는 built-in 함수로 만들고, 나머지는 execve로 실행<br>
환경변수도 세팅해줄 수 있어야 함<br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

[minishell link](https://github.com/cjho0316/42_Archive/tree/main/minishell)

<!-- Features -->

### Key Features <a name="key-features"></a>
- 부모-자식 process
- pipe 통신
- tree 구조 재귀하향파싱
- 설계의 중요성...
</br></br></br>

# philosopher <a name="philosopher"> 🤔 </a>
##### Duration: 2023.01.17 ~ 2023.02.12
다익스트라의 식사하는 철학자 문제<br>
철학자에게 주어진 fork가 공유자원이기에, 공유자원 접근에 대해 data race가 발생하지 않도록 해야 함<br>
철학자를 멀티 쓰레드로 구현하고, 공유자원을 mutex 제어하기<br>
철학자를 멀티 프로세스로 구현하고, 공유자원을 semaphore로 제어하기(보너스)<br>
어떤 종류의 data race도 발생하지 않아야 함<br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

[philosopher link](https://github.com/cjho0316/42_Archive/tree/main/Philosopher)

<!-- Features -->

### Key Features <a name="key-features"></a>
- 모든 data race 에 대해 제어해주기
- 철학자가 죽었는지는 자기 자신이 판단할 수 없음. 모니터 쓰레드가 철학자의 죽음 유무 확인하기
- thread leak 체크하기
- 한 쓰레드는 공유영역을 읽기만하고, 한 쓰레드는 공유영역에 읽고/쓰기를 하는 것도 data race이며 제어해줘야함.
- 철학자는 스스로 죽은지 판단할 수 없으며, 모니터 쓰레드가 철학자의 죽음을 판단해야 함
</br></br></br>

# cub3d <a name="cub3d"> 🎲 </a>
##### Duration: 2023.01.25 ~ 2023.03.31
2D의 맵파일을 읽고 파싱하여 3D 게임 구현하기
mlx graphic library를 사용하여 raycasting 하기

<br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/></span>&nbsp;

[cub3D link](https://github.com/cjho0316/42_Archive/tree/main/cub3D)

<!-- Features -->

### Key Features <a name="key-features"></a>
- 맵 파싱
- 벽 충돌 감지
- mouse, key 입력 받아서 처리하기
- ray casting
</br></br></br>

# cpp_module(s) <a name="cpp_module"> 🎱 </a>
##### Duration: 2023.04.14 ~ 2023.06.07

**C++을 통한 객체지향 프로그래밍**

|Module Number|Key Word|
|------|--------|
|[CPP Module 00](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP00)|C++ Style, Class, Method, I/O, Static, Const, Basic ...|
|[CPP Module 01](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP01)|Memory Allocation, Pointer, Reference, Switch|
|[CPP Module 02](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP02)|Orthodox Canonical Form, Operator Overloading, Fixed point|
|[CPP Module 03](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP03)|Inheritance, Overide, Diamond Inheritance|
|[CPP Module 04](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP04)|Polymorphism, Abstract Class, Interface|
|[CPP Module 05](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP05)|Exception, try-catch, Repetition|
|[CPP Module 06](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP06)|C++ cast(static_, dynamic_, reinterpret_)|
|[CPP Module 07](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP07)|C++ Template, .tpp|
|[CPP Module 08](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP08)|Tmplated containers, iterator, algorithm|
|[CPP Module 09](https://github.com/cjho0316/42_Archive/tree/main/CPP/CPP09)|STL(containers, iterator)|
<br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"></span>&nbsp;

<!-- Features -->

### Key Features <a name="key-features"></a>

- **전체적인 C++ 이론을 요구사항 구현을 통해 학습**
</br></br></br>


# webserv <a name="webserv"> 🕸️ </a>
##### Duration: 2023.04.14 ~ 2023.06.07
**C++을 통해 구현하는 웹서버**
http web server 구현 (**like NGINX**)<br>
socket programming(**w/kqueue**)<br>
I/O multi plexing<br>
event-driven I/O (Non-block)<br>
cookie & session<br>
CGI(Common Gateway Interface)<br>

### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"></span>&nbsp;

[MyLittleWebServer link](https://github.com/MyLittleWebServer/webserv)

<!-- Features -->

### Key Features <a name="key-features"></a>

- **RFC7230, 7231 MUST를 준수하는 웹서버를 C++로 구현하기**
</br></br></br>

# inception <a name="inception"> 🔝 </a>
##### Duration: 2023.06.07 ~ 2023.11.20


### Tech Stack <a name="tech-stack"></a>

> Language
&nbsp;&nbsp;<span><img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"></span>&nbsp;

[inception link](https://github.com/cjho0316/42_Archive/tree/main/inception)

<!-- Features -->

### Key Features <a name="key-features"></a>

- **Docker 위에서 MySQL, Nginx, Wordpress를 상용이미지가 아닌 커스텀 이미지로 올리기**
</br></br></br>


# ft_transcendence <a name="ft_transcendence"></a>
##### Duration: 2023.10.30 ~ 2023.12.30
**NestJS, TypeScript, PostgreSQL 기술을 사용하여 소켓통신의 기능을 통합한 Pong 게임용 종합 웹 애플리케이션을 개발**
<br>

### Tech Stack <a name="tech-stack"></a>

> Stacks
&nbsp;&nbsp;<span>
> <img src="https://img.shields.io/badge/TypeScript-007ACC?style=for-the-badge&logo=typescript&logoColor=white" />
    <img src="https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white" />
    <img src="https://img.shields.io/badge/Socket.io-black?style=for-the-badge&logo=socket.io&badgeColor=010101" />
    <img src="https://img.shields.io/badge/nestjs-%23E0234E.svg?style=for-the-badge&logo=nestjs&logoColor=white" />
    <img src="https://img.shields.io/badge/PostgreSQL-316192?style=for-the-badge&logo=postgresql&logoColor=white" />
    <img src="https://img.shields.io/badge/redis-%23DD0031.svg?style=for-the-badge&logo=redis&logoColor=white" /></span>&nbsp;

[tscenping link](https://github.com/tscenping)

<!-- Features -->

### Key Features <a name="key-features"></a>
- **OAuth 사용자 인증, 채팅 시스템, 라이브 게임 스트리밍, 보안 사용자 데이터 관리**
</br></br></br>




<!-- LICENSE -->

## 📝 License <a name="license"></a>

This project is [MIT](./LICENSE) licensed.
