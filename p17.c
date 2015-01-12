char  * ONE_TO_NINE[9]={"one","two","three","four","five", "six", "seven", "eight", "nine"};
char * ELEVEN_TO_NINETEEN[9]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char * TEN_TO_NINETY[9]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char * HUNDRED="hundred";
char * AND= "and";
char * THOUSAND="thousand";

int main()
{
	//1 to 99
	int count_1_99=0;
	int count_20_90=0;
	int count_1_9=0;
	for(int i=0;i<9;i++)
	{
		count_1_9+=strlen(ONE_TO_NINE[i]);
		count_1_99+=strlen(ELEVEN_TO_NINETEEN[i]);
		count_20_90+=strlen(TEN_TO_NINETY[i]);
	}
	count_20_90-=3;
	count_1_99+=count_1_9+count_20_90+3;
	//21 to 99
	count_1_99+=9*count_20_90+8*count_1_9;
	printf("(1,9)=%d,(20,90)=%d,(1,99)=%d\n",count_1_9,count_20_90,count_1_99);
	
	//101 to 999
	int count_100_999=count_1_9+9*strlen(HUNDRED)+
			  99*count_1_9+99*9*(strlen(HUNDRED)+strlen(AND))+9*count_1_99;
	printf("(1,1000)=%d\n",count_100_999+count_1_99+strlen(ONE_TO_NINE[0])+strlen(THOUSAND));
	
}

