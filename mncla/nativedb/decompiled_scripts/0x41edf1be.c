void main()
{
    unknown uVar2;
    unknown uVar3;
    unknown uVar4;
    unknown uVar5;
    unknown uVar6;
    unknown uVar7;
    unknown uVar8;
    unknown uVar9;

    if (NOT (l_U4._fU0 == 3))
    {
        l_U4._fU0 = 2;
        StrCopy( ref l_U0, "la", 16 );
        PRINTSTRING( "Script: LoadLoadMenu\n" );
        UIManager_LoadMovie( "Menu", "FE/FE.swf", 500, 100, 10000, 0 );
        WAIT( 200 );
        N_2366296418( "t:/mc4/selftest1.jpg" );
        WAIT( 200 );
        PRINTSTRING( "Script: DestroyLoadMenu\n" );
        UIManager_UnloadMovie( "Menu" );
        PRINTSTRING( "Script: LoadCity LA\n" );
        uVar2 = LookupCity( ref l_U0 );
        LayerCity_LoadCity( ref l_U0 );
        WAIT( 500 );
        N_2366296418( "t:/mc4/selftest2.jpg" );
        WAIT( 200 );
        CityDescription_GetDefaultStartPosition( uVar2, ref uVar3, ref uVar6 );
        uVar7 = LocalOptions_GetShowroomProfile( N_3899682874( "vp_pon_solstice_06" ) );
        LayerPlayer_LoadPlayer( 0, uVar7, ref uVar3, uVar6 );
        uVar8 = Player_FindRacerObject( 0 );
        Racer_InitializeResetPosition( uVar8, ref uVar3, uVar6 );
        Racer_Reset( uVar8 );
        uVar9 = UIManager_LoadMovie( "HUDMAPMOVIE", "hudmap/hudmap.swf", 500, 100, 10000, 0 );
        UIManager_LoadHUD();
        WAIT( 2000 );
        N_2366296418( "t:/mc4/selftest3.jpg" );
        WAIT( 200 );
        CityDescription_GetDefaultStartPosition( uVar2, ref uVar3, ref uVar6 );
        uVar3._fU0 += 3;
        uVar7 = LocalOptions_GetShowroomProfile( N_3899682874( "vp_pon_solstice_06" ) );
        LayerPlayer_LoadPlayer( 1, uVar7, ref uVar3, uVar6 );
        WAIT( 2000 );
        N_2366296418( "t:/mc4/selftest4.jpg" );
        WAIT( 200 );
        LayerPlayer_KillPlayer( 0 );
        WAIT( 200 );
        N_2366296418( "t:/mc4/selftest5.jpg" );
        WAIT( 200 );
        LayerPlayer_KillPlayer( 1 );
        WAIT( 200 );
        N_2366296418( "t:/mc4/selftest6.jpg" );
        WAIT( 200 );
        UIManager_UnloadHUD();
        UIManager_UnloadMovie( "HUDMAPMOVIE" );
        PRINTSTRING( "Script: UnloadCity LA\n" );
        LayerCity_UnloadCity();
        WAIT( 200 );
        N_2366296418( "t:/mc4/selftest7.jpg" );
        WAIT( 200 );
    }
    return;
}
