// if pipe check -> fork and find pipe

/* 

<built - in>

- env(ok) : 옵션이 따로 필요하지 않음 (어떻게 데이터를 관리할지 고민(연결리스트, 이중포인터)) (ok)

- export: key=val 형식으로 들어오는지 체크한다. (인자에 공백 들어가면 안됨 -> 하나의 문자열로 체크하고 '=' 기준으로 파싱해주면 될듯)
	ex> 
		key = 123 -> '=' is not valid identifier, '123' is not valid identifier

		key값은 무조건 문자열로만 이루어져야 한다. '=' 또는 숫자가 처음 들어가는 경우는 오류
		인자가 여러개 들어가도 형식만 맞춰지면 환경변수로 설정이된다. (unset 도 마찬가지임)
		val 값이 '=' 로 끝나는건 됨 (아마 자연스럽게 구동되지않을까 생각함)

- unset : 인자로 숫자가 들어오면 'bash: unset: `인자': not a valid identifier' 출력
		 
- pwd(ok) : getcwd 명령어 사용해서 간단히 구현 

- cd(ok) : 인자준다음에 없는 경로로 이동하려고 하면 'bash: cd: 인자: No such file or directory' 오류출력
		cd ~ : home 경로로 이동함 (환경변수로 따로설정?), unset home 하면, bash: cd: HOME not set 나올 수 있도록 한다.
		cd 작업이 정상적으로 되면 pwd, oldpwd(이건 환경변수에 없는데..?) 변경이 됨 

- exit : 인자 없어도 되는데 
		인자가 있다면 부모 프로세스에 값을 넘겨주고 프로세스 종료시킨다.
	
	ex>
		bash-3.2$ exit 123 123
		exit
		bash: exit: too many arguments (종료 x)

		bash-3.2$ exit 1zz
		exit
		bash: exit: 1zz: numeric argument required (종료 o, echo $? => 255)

	미니쉘 안에서 미니쉘 실행하고 exit 123 하면 부모 미니쉘에 123을 넘겨주고 종료가 됨. -> 부모 미니쉘에서 echo $? 하면 123이 출력이 된다. 


	// 참고> (구현안할거임)
	// 	echo$! : 마지막으로 백그라운드에서 실행된 명령어의 PID 값을 출력한다.
	// 	echo$? : 마지막으로 종료된 명령어의 종료 상태를 말해주는데, 종료상태란 정상적인 종료0 과 비정상적 종료인 0을 제외한 다른 값을 의미한다.
	// 	echo$$ : 현재 쉘의 PID값을 출력한다.

- echo(ok) : 인자 받아온거를 출력해주면됨 (ok)
		-n 옵션이 존재한다면 마지막에 개행만 안나오게 하면됨 (같은 옵션이 몇개 들어가도 상관 없고 n도 여러개 들어가도 노상관)
		-n 옵션이 나오기 전에 문자열이 들어가면 -n은 문자열로 취급된다.

- 리디렉션(>) : 
		리디렉션은 dup2로 파일 디스크립터를 복제해야하기 때문에 fork를 쓰거나 기존 표준 입출력을 백업시키거나 해야한다.

	<실행과정>
	1. 먼저 인자가 있는지 확인을 한다.
	1-1. 인자가 없으면 bash: syntax error near unexpected token `newline' 메시지 출력
	1-2. 인자가 있으면 리다이렉션 이후에 오는 명령어를 찾고 그 후 fork()
	2. 해당 리다이렉션 기호에 맞춰서 리다이렉션 함수로 이동
	3. 파일을 open하고 dup2로 fd복제
	4. 다음 명령어 실행
	5. exit로 부모프로세스에 상태 반환

- 그 외:
	fork 로 자식 프로세스 실행하고 execve로 외부 프로그램 실행시킨다.
	stat으로 해당 경로에 파일이 있는지 확인하고 있으면 실행시킨다.
	없으면 command not found 출력
 */