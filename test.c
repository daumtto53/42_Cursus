#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int		main()
{

	/* ############# wrong type matching argument ########
	 *
	 * NO NEED TO CONSIDER!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 *
	 * didn't clarify argument == undefined behavior
	 * printf("%s\n");
	 *
	 * wrong type : undefined behavior , sometimes segfault
	 * printf("%s\n", 123);
	 * wrong type == undefined behavior
	 * printf("%d\n", 123.0);
	 * wrong type == undefined behavior
	 * 	printf("%d\n", "wrong type");
	 *
	 *####################################################*/
	
	
	/* ############ - flag and  0 flags combined == 0 flag ignored #########
	 *
	 * - (-) flag and 0 flag combined == 0 flag ignored
	 * printf("[%-05d]\n", 5);
	 * - 0 flag and d i o u x X c precision combined ==> 0 flag ignored.
	 *   
	 *   -0 flag and precision can be used together.
	 * printf("[%020.4d]\n", 12);
	 *
	 * ##########################################################*/
	 

	/* ############## 0 flag + string : works. #############
	 *
	 * - 0 flag / string == works.
	 * printf("[%010s]\n", "GROOT");
	 *
	 * #########################################################*/

	/* ##################### width < 0 ###########################
	 * printf("[%4d]\n", 123);
	 * printf("[%d]\n", 123);
	 * printf("[%0d]\n", 123);
	 * printf("[%-7d]\n", 123);
	 * translated to [%*d] -> [%-3d] 
	 * printf("[%*d]\n", -3, 1);
	 * ##########################################################*/

	/* #################### - flag w/ string ###################
	 *
	 * printf("[%20s]\n", "abcd");
	 * printf("[%-20s]\n", "abcd");
	 *
	 * ########################################################*/

	
	/* ################### precision with string ################
	* $$$ conclusion : 
	*  == precision checked in advance
	*   .-4 == precision unchecked => interpreted as strlen.
	*/

	/* ################ precision not considered ###############
	 *
	 * printf("[%-20.-s]\n", "string is best");
	 * printf("[%-20.-4s]\n", "string is best");
	 *
	 * ######################################################### */
	printf("\n");
	printf("\n");
	printf("9-------------precision w/ string\n");
	printf("- str + width 10\n");
	printf("[%10.3s]\n", "string is best");
	printf("precision 0\n");
	printf("[%%10.s] : [%10.s]\n", "string is best");
	printf("precision 0\n");
	printf("[%%10.*s] : [%10.*s]\n", 0, "string is best");
	printf("precision ignored. When precision < 0\n"); 
	printf("[%%20.(-1)s] : [%20.*s]\n", -1, "string is best");
	printf("\n");
	 
	printf("precision checked in advance when * used\n");
	printf("[%%-20.(-4)s] : [%-20.*s]\n", -4, "string is best");
	printf("9-----------------------------------\n"); 
	printf("\n");
	printf("\n");
	 
	

	/* ################### string precision <= 0, string precision > 0 ############
	 *
	 * - string precision interpreted as string length.
	 * printf("[%20.4s]\n", "string is best");
	 * printf("[%-20.0s]\n", "string is best");
	 * - undefined behavior. NO NEED TO CONSIDER
	 * printf("[%-20.-4s]\n", "string is best");
	 *
	 * ############################################################################*/

	/* ####################### precision ignored when given as * ##################
	 *
	 * printf("WARNING TEST\n");
	 * printf("[%20.*s]\n", 2, "string");
	 * printf("[%20.*s]\n", -5, "stringgggggg");
	 * printf("[%20.*d]\n", 4, 123);
	 * printf("[%20.*d]\n", -4, 123);
	 *
	 * ############################################################################# */
	
	/*################### precision + 0 flag combined ################
	 * 
	 * - precision + 0 flag == 0 flag ignored.
	 * printf("[%09.4d]\n", 20); 
	 * printf("[%020.0d]\n", 20); 
	 *
	 *################################################################*/

	// string with 0 flag == UNDEFINED BEHAVIOR
	// printf("[%020s]\n", "This");
	//
	
	printf("19---------precision when argument == 0--------\n");
	printf("[%20.d]\n", 0);
	printf("[%20.0d]\n", 0);
	printf("[%20.*d]\n",0, 0);
	printf("[%20.*d]\n", -3, 0);
	printf("19---------precision when argument == 0--------\n\n");
	
	printf("12---------d type with 0 precision-------------\n");
	printf("[%%20.d] : [%20.d]\n", 1234);
	printf("[%%20.0d] : [%20.0d]\n", 1234);
	printf("[%%20.1d] : [%20.1d]\n", 1234);
	printf("12--------------------------------------------\n\n");

	printf("[%+.d]\n", 1234);
	printf("[%+.2d]\n", 1234);
	printf("[%+.4d]\n", 1234);
	printf("[%+.6d]\n", 1234);

	printf("----------------\n");
	
	/*#####################################################################
	 *
	 * printf("10---------- p type specifier w/ 0, +, wid, prec ------\n");\
	 * int		i;
	 *
	 * - p type w/ "+" "0" flag and precision = Warning
	 * printf("[%+p]\n", (void *)&i);
	 * printf("[%0p]\n", (void *)&i);
	 * printf("[%15p]\n", (void *)&i);
	 * printf("[%30.15p]\n", (void *)&i);
	 *
	 *#####################################################################*/

	printf("\n\n\n----------01 21 Data Test -------------\n");
	printf("[%020.0d]\n", 12);
	printf("[%030X]\n", 12312321);
	printf("[%10c]\n", 0);
	printf("[%c]\n", 0);
	printf("%%d : don't print when pre=0,arg=0\n");
	printf("[%0.0d]\n",0 );
	printf("[%0.*d]\n",0, 0 );
	printf("[%0.*d]\n",-3, 0);
	printf("[%0.*d]\n", 3, 0);
	
	
	printf("%%x : don't print when pre=0,arg=0\n");
	printf("[%0.0x]\n",0 );
	printf("[%0.*x]\n",0, 0 );
	printf("[%0.*x]\n",-3, 0);
	
	printf("%%u : don't print when pre=0,arg=0\n");
	printf("[%0.7u]\n", 256);
	printf("[%0.0u]\n",0 );
	printf("[%0.*u]\n",0, 0 );
	printf("[%0.*u]\n",-3, 0);

	printf("%%s : don't print when pre=0,arg=0\n");
	printf("[%-20.s]\n", "string");
	printf("[%-20.*s]\n", -2,  "string");
	printf("[%-20.*s]\n",0, "string");

	printf("[%-1c]\n", 'c');
	printf("[%+1d]\n", 1);
	printf("[%-20.0d]\n", 0);
	printf("[%-6.9d]\n", 1);
	printf("[%010d]\n", -20);
	printf("[%10.3d]\n", -20);
	printf("[%7.6d]\n", -10000);


	printf("\n\n");

	printf("[%]");
	printf("[%5]");
	printf("[%05]");
	printf("[%-05]");
	printf("[%-5]");
	
}

