void main()
{
    unknown uVar2;
    vector vVar3;
    float fVar6;
    unknown uVar7;
    unknown uVar8;

    if (NOT (l_U4._fU0 == 3))
    {
        l_U4._fU0 = 2;
        StrCopy( ref l_U0, "la", 16 );
        PRINTSTRING( "Script: LoadCity LA\n" );
        uVar2 = LookupCity( ref l_U0 );
        LayerCity_LoadCity( ref l_U0 );
        vVar3 = {1000, 50, 1000};
        fVar6 = 0;
        CityDescription_GetDefaultStartPosition( uVar2, ref vVar3, ref fVar6 );
        uVar7 = LocalOptions_GetShowroomProfile( N_3899682874( "vp_nsn_350Z_06" ) );
        LayerPlayer_LoadPlayer( 0, uVar7, ref vVar3, fVar6 );
        uVar8 = Player_FindRacerObject( 0 );
        Racer_InitializeResetPosition( uVar8, ref vVar3, fVar6 );
        Racer_Reset( uVar8 );
        UIManager_LoadMovie( "HUDMAPMOVIE", "hudmap/hudmap.swf", 500, 100, 10000, 0 );
        UIManager_LoadHUD();
        WAIT( 16000 );
        StartLogMemory( "t:/mc4/LeakTestCars-opponent1-vp_mit_3000gt_99.log1", 1 );
        sub_401( ref uVar2, "vp_mit_3000gt_99", "t:/mc4/LeakTestCars-opponent1-vp_mit_3000gt_99.jpg" );
        StopLogMemory( "t:/mc4/LeakTestCars-opponent1-vp_mit_3000gt_99.log2", 1 );
        StartLogMemory( "t:/mc4/LeakTestCars-opponent2-vp_mit_3000gt_99.log1", 1 );
        sub_401( ref uVar2, "vp_mit_3000gt_99", "t:/mc4/LeakTestCars-opponent2-vp_mit_3000gt_99.jpg" );
        StopLogMemory( "t:/mc4/LeakTestCars-opponent2-vp_mit_3000gt_99.log2", 1 );
        StartLogMemory( "t:/mc4/LeakTestCars-opponent3-vp_lam_murcielago_06.log1", 1 );
        sub_401( ref uVar2, "vp_lam_murcielago_06", "t:/mc4/LeakTestCars-opponent3-vp_lam_murcielago_06.jpg" );
        StopLogMemory( "t:/mc4/LeakTestCars-opponent3-vp_lam_murcielago_06.log2", 1 );
        LayerPlayer_KillPlayer( 0 );
        StartLogMemory( "t:/mc4/LeakTestCars-player2-vp_dsn_280z_75.log1", 1 );
        sub_1310( ref uVar2, "vp_dsn_280z_75", "t:/mc4/LeakTestCars-player2-vp_dsn_280z_75.jpg" );
        StopLogMemory( "t:/mc4/LeakTestCars-player2-vp_dsn_280z_75.log2", 1 );
        StartLogMemory( "t:/mc4/testfinished.txt", 1 );
        StopLogMemory( "t:/mc4/testfinished.txt", 1 );
        while (true)
        {
            PRINTSTRING( "Done leak log\n" );
            WAIT( 1000 );
        }
        WAIT( 1000 );
        UIManager_UnloadHUD();
        UIManager_UnloadMovie( "HUDMAPMOVIE" );
        WAIT( 1000 );
        PRINTSTRING( "Script: UnloadCity LA\n" );
        LayerCity_UnloadCity();
    }
    return;
}

void sub_401(unknown uParam0, unknown uParam1, unknown uParam2)
{
    vector vVar5;
    float fVar8;
    unknown uVar9;
    unknown uVar10;

    vVar5 = {1000, 50, 1000};
    fVar8 = 0;
    CityDescription_GetDefaultStartPosition( (uParam0^), ref vVar5, ref fVar8 );
    vVar5.x += 3;
    uVar9 = OpponentManager_CreateOpponent();
    OpponentManager_LoadOpponent( uVar9, uParam1, ref vVar5, 0 );
    OpponentManager_AddOpponentToWorld( uVar9 );
    uVar10 = Opponent_GetRacer( uVar9 );
    while (NOT (Racer_IsSimStreamed( uVar10 )))
    {
        WAIT( 100 );
        PRINTSTRING( "Waiting for Sim to stream in\n" );
    }
    WAIT( 5000 );
    N_2366296418( uParam2 );
    WAIT( 500 );
    PRINTSTRING( "Delete opponent\n" );
    OpponentManager_RemoveOpponentFromWorld( uVar9 );
    OpponentManager_DeleteOpponent( uVar9 );
    PRINTSTRING( "Delete opponent done\n" );
    WAIT( 1000 );
    return;
}

void sub_1310(unknown uParam0, unknown uParam1, unknown uParam2)
{
    vector vVar5;
    float fVar8;
    unknown uVar9;
    unknown uVar10;

    vVar5 = {1000, 50, 1000};
    fVar8 = 0;
    CityDescription_GetDefaultStartPosition( (uParam0^), ref vVar5, ref fVar8 );
    vVar5.x += 3;
    uVar9 = LocalOptions_GetShowroomProfile( N_3899682874( uParam1 ) );
    LayerPlayer_LoadPlayer( 0, uVar9, ref vVar5, fVar8 );
    uVar10 = Player_FindRacerObject( 0 );
    Racer_SetStreamLockState( uVar10, 1 );
    while (NOT (Racer_IsSimStreamed( uVar10 )))
    {
        WAIT( 100 );
    }
    WAIT( 5000 );
    N_2366296418( uParam2 );
    WAIT( 500 );
    LayerPlayer_KillPlayer( 0 );
    WAIT( 1000 );
    return;
}
