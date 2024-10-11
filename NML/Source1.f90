subroutine namelistRead(TEND, ZEX, NE, NZ, Q1, Q2, Q3, I1, I2, TH1, TH2, A1, A2, DR1, DR2, &
		DTR1, DTR2, R1, R2, F10, F20, F30, P10, P20, P30, DT, DZ, INHER) bind(c,name='namelistRead')

    use,intrinsic :: iso_c_binding,only:c_double,c_int
    implicit none
    
    integer(c_int)NE
	real(c_double) TEND
	real(c_double) ZEX
	real(c_double) Q1
	real(c_double) Q2
	real(c_double) Q3
	real(c_double) I1
	real(c_double) I2
	real(c_double) TH1
	real(c_double) TH2
	real(c_double) A1
	real(c_double) A2
	real(c_double) DR1
	real(c_double) DR2
	real(c_double) R1
	real(c_double) R2
	real(c_double) F10
	real(c_double) F20
	real(c_double) F30
	real(c_double) P10
	real(c_double) P20
	real(c_double) P30
	real(c_double) DT
	real(c_double) DZ
	real(c_double) DTR1
	real(c_double) DTR2
	integer(c_int) INHER
	integer(c_int) NZ
    
    namelist /inputDataList/ TEND, ZEX, NE, NZ, Q1, Q2, Q3, I1, I2, TH1, TH2, A1, A2, DR1, DR2, &
		DTR1, DTR2, R1, R2, F10, F20, F30, P10, P20, P30, DT, DZ, INHER

    open(unit=100,file='input.txt',status='old')
    read(unit=100,nml=inputDataList)
    close(unit=100)

    write(*,nml=inputDataList)

endsubroutine namelistRead