/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:47:20 by mchun             #+#    #+#             */
/*   Updated: 2021/08/31 18:43:58 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char **argv, char **envp)
{
	t_llist		*list;
	char		*line_read;

	list = init_list();
	line_read = readline('$');
	/*
		line을 quote와 double quote를 신경써서 parsing하여 크게 (command, redirection, pipe)로 나누어 linked_list에 enum과 함께 저장.
		중첩된 quote, double quote는 처리했지만

		redirection 중 <<의 parsing, 2>의 parsing은 아직 해주지 않음.
		command의 유효성 검사 필요함. ex) <<< 가 들어오면 입력을 받지 않아야 한다. -- 이건 split 후에 생각해봐도 될 것 같다.
	*/
	arg_split(line_read, list);
	argv_split(list);
	/*
		1. list 안의 arg_string 에 대해서 variable expansion을 진행한다. 단, single quote 안의 $는 해석하지 않는다.
			1-1 variable expansion을 진행할 때, 가장 바깥의 quote를 기준으로 expansion을 진행해주며, node->arg_string의 문자열을 교체한다.
			1-2 variable expansion을 진행할 때, 최종적으로 expansion 작업이 끝난 문자열은 가장 바깥의 quote를 없앤 상태의 문자열로 교체해준다.
		2. list 안의 arg_string을 quote를 신경써서 char **arg로 나눈다.
		3. list의 enum 변수 type이 COMMAND 인 것을 찾은 뒤 (연결리스트 traverse)
			1. 해당 command가 built-in이라면 enum 변수 = type을 BUILT_IN이라고 바꿔주고, char **args의 인자를 검사한다.
			2. 해당 commamd가 external이라면 enum 변수 = type을 EXTERNAL이라고 바꿔준다.
		4. list의 enum 변수 type이 BUILT_IN 인것을 찾은 뒤 (연결리스트 traverse)
			1. 해당 node의 문자열 arg[0]이 유효한 command인지 확인한다.
				유효한 command인지 확인하는 방법은 : env와 built-in을 반복해서 돌린 뒤, strcat으로 합치고, stat으로 존재하는 파일인지 확인한다.
				env_path/arg[0] 또는 arg[0]
				1. 유효한 commmand라면, (path에 존재하는 ) 해당 절대경로를 node에 저장한다.
				2. 반복문으로 확인한 command가 유효하지 않은 command라면 오류처리를 하고 exit한다.
		Parsing 끝
	*/

	/* 반복문으로 연결리스트 list가 NULL일 때 까지 연결리스트의 node를 탐색한다.
		1. 만약 현재 node의 type이 BUILT-IN 이다 : BUILT-IN 함수 실행.
		2. 만약 현재 node의 type이 EXTERNAL 이다 : execve()에  node의 command_path, args, envp를 넣어줌으로써 실행시킨다.
		3. 만약 현재 node의 type이 PIPE 이다 : Pipe 연결하는 함수를 call한다.
		4. 만약 현재 node의 type이 REDIRECTION 이다 : REDIRECTION을 해준다.
	*/
}

int		main_1(int argc, char **argv)
{
	char	**splited_arg;
	char	*line_read;
	t_llist	*list;

	list = init_list();

	line_read = readline("$");
	// arg_split(line_read);
	arg_split_4(line_read, list);
	argv_split(list);
	return (0);
}
