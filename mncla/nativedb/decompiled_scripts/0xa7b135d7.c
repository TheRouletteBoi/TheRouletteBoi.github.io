void main()
{
    WAIT( 2000 );
    StartLogMemory( "t:/mc4/LeakTest-StartRace.log1", 1 );
    sub_60();
    N_2366296418( "t:/mc4/LeakTest-StartRace1.jpg" );
    WAIT( 20000 );
    sub_247();
    WAIT( 2000 );
    StopLogMemory( "t:/mc4/LeakTest-StartRace.log2", 1 );
    N_2366296418( "t:/mc4/LeakTest-StartRace3.jpg" );
    WAIT( 2000 );
    StartLogMemory( "t:/mc4/LeakTest-RestartRace.tmp.log", 0 );
    StartLogMemory( "t:/mc4/LeakTest-RestartRace.log1", 1 );
    sub_614();
    WAIT( 20000 );
    sub_614();
    WAIT( 20000 );
    sub_614();
    WAIT( 20000 );
    StopLogMemory( "t:/mc4/LeakTest-RestartRace.tmp.log", 1 );
    sub_614();
    WAIT( 20000 );
    StopLogMemory( "t:/mc4/LeakTest-RestartRace.log2", 0 );
    return;
}

void sub_60()
{
    N_3987653805( 2048 );
    WAIT( 1000 );
    N_3987653805( 8192 );
    WAIT( 1000 );
    N_3987653805( 64 );
    WAIT( 8000 );
    N_3987653805( 64 );
    WAIT( 500 );
    N_3987653805( 64 );
    WAIT( 500 );
    N_3987653805( 64 );
    WAIT( 500 );
    return;
}

void sub_247()
{
    N_3987653805( 2048 );
    WAIT( 1000 );
    N_3987653805( 16384 );
    WAIT( 1000 );
    N_3987653805( 16384 );
    WAIT( 1000 );
    N_3987653805( 64 );
    WAIT( 1000 );
    N_2366296418( "t:/mc4/LeakTest-StartRace2.jpg" );
    WAIT( 500 );
    N_3987653805( 16384 );
    WAIT( 500 );
    N_3987653805( 64 );
    return;
}

void sub_614()
{
    N_3987653805( 2048 );
    WAIT( 1000 );
    N_3987653805( 16384 );
    WAIT( 1000 );
    N_3987653805( 16384 );
    WAIT( 1000 );
    N_3987653805( 16384 );
    N_2366296418( "t:/mc4/LeakTest-RestartRace1.jpg" );
    WAIT( 1000 );
    N_3987653805( 64 );
    WAIT( 1000 );
    N_2366296418( "t:/mc4/LeakTest-RestartRace2.jpg" );
    WAIT( 1000 );
    N_3987653805( 16384 );
    N_2366296418( "t:/mc4/LeakTest-RestartRace3.jpg" );
    WAIT( 1000 );
    N_3987653805( 64 );
    return;
}
