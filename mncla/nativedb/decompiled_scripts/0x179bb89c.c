void main()
{
    int I;

    while (NOT (N_2319813463( sub_10( 0 ) )))
    {
        WAITUNWARPED( 10 );
    }
    for ( I = 0; I < 70; I++ )
    {
        START_NEW_SCRIPT_WITH_ARGS( "tools/SelfTests/AICrashTest", ref l_U0, 1, 0 );
    }
    return;
}

void sub_10(unknown uParam0)
{
    int Result;

    Result = Player_FindRacerObject( uParam0 );
    while (Result == nil)
    {
        Result = Player_FindRacerObject( uParam0 );
        WAITUNWARPED( 10 );
    }
    return Result;
}
