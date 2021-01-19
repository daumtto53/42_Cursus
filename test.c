#include <stdio.h>
#include <stdlib.h>

int		main()
{

	/* ############# wrong type matching argument ########
	 *
	 * NO NEED TO CONSIDER
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
	printf("\n");
	printf("\n");
	printf("9-------------precision w/ string\n");
	printf("- str + width 10\n");
	printf("[%10.3s]\n", "string is best");
	printf("precision 0\n");
	printf("[%10.s]\n", "string is best");
	printf("precision 0\n");
	printf("[%10.*s]\n", 0, "string is best");
	printf("precision ignored. When precision < 0\n"); 
	printf("[%20.*s]\n", -1, "string is best");
	printf("\n");
	 
	printf("precision checked in advance when * used\n");
	printf("[%-20.*s]\n", -4, "string is best");
	printf("precision unchecked => \n");
	printf("[%-20.-s]\n", "string is best");
	printf("precision unchecked => interpreted as - (< 0) => strlen <= 0 => 4 interpreted as width\n");
	printf("[%-20.-4s]\n", "string is best");
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
	
	/*################### precision + 0 flag combined ################
	 * 
	 * - precision + 0 flag == 0 flag ignored.
	 * printf("[%09.4d]\n", 20); 
	 * printf("[%020.0d]\n", 20); 
	 *
	 *################################################################*/

	// string with 0 flag == UNDEFINED BEHAVIOR
	// printf("[%020s]\n", "This");
	
	printf("[%+.d]\n", 1234);
	printf("[%+.2d]\n", 1234);
	printf("[%+.4d]\n", 1234);
	printf("[%+.6d]\n", 1234);

	printf("----------------\n");

	printf("10---------- p type specifier w/ 0, +, wid, prec ------\n");
	int		i;
	printf("[%+p]\n", (void *)&i);
	printf("[%0p]\n", (void *)&i);
	printf("[%15p]\n", (void *)&i);
	printf("[%30.15p]\n", (void *)&i);
	printf("10----------\n");
	// - precision = 4 -> left-justtify -> width remaining
	//printf("[%-20.4s]\n", "string is best");

	//precision
	printf("%.1.2f\n", 1.2);
	printf("%.d\n", 0);

}

