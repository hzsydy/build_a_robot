

void pwm(int port, int hghtime, int tottime) {
	while (True) {
		motor[port] = 127;
		wait1MSec(hghtime);
		motor[port] = -127;
		wait1MSec(tottime-hghtime);
	}
}



task main()
{
	printf()


}
