void main()
{
    unknown uVar2;

    uVar2 = UIManager_LoadMovie( "TESTMOVIE", "testmovie/testmovie.swf", 1500, 1500, 10000, 0 );
    while (true)
    {
        WAIT( 10000 );
    }
    return;
}
