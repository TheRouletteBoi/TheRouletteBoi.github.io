void main()
{
    unknown uVar2;
    string sVar3;
    string sVar4;
    string sVar5;
    string sVar6;
    string sVar7;
    string sVar8;
    boolean bVar9;
    unknown uVar10;
    unknown uVar11;
    unknown uVar12;
    unknown uVar13;
    unknown uVar14;

    if (NOT (l_U4._fU0 == 3))
    {
        l_U4._fU0 = 2;
        StrCopy( ref l_U0, "la", 16 );
        PRINTSTRING( "Script: LoadCity LA\n" );
        uVar2 = LookupCity( ref l_U0 );
        LayerCity_LoadCity( ref l_U0 );
        StartLogMemory( "t:/mc4/LeakTestCharacters-test1.log1", 1 );
        sVar3 = "character/drv_mc_02_set";
        sVar4 = "drv_mc_02_set";
        sVar5 = "cutscene/cut_hw_hk1_1/Entity/Cut_drv01";
        sVar6 = "Cut_drv01";
        sVar7 = "cutscene/cut_hw_hk1_1";
        sVar8 = "CSCamera";
        bVar9 = true;
        bVar9 = (bVar9) AND (CineScript_Characters_LoadType( sVar3, sVar4 ));
        bVar9 = (bVar9) AND (CineScript_Characters_LoadAnimation( sVar5, sVar6 ));
        bVar9 = (bVar9) AND (CineScript_Camera_LoadAnimation( sVar7, sVar8 ));
        if (NOT bVar9)
        {
            PRINTSTRING( "Script 'LeakTestCharacters.cs' failed to load assets\n" );
            BREAKPOINT();
        }
        uVar14 = CineScript_Characters_LaunchAnimAt( sVar3, sVar4, sVar5, sVar6, ref uVar10, -1 );
        CineScript_PushKillBuffer( uVar14, 0 );
        CineScript_Camera_Launch( sVar7, sVar8 );
        WAITUNWARPED( 1000 );
        N_2366296418( "t:/mc4/LeakTestCharacters-test1.jpg" );
        WAITUNWARPED( 10000 );
        CineScript_PopKillBuffer( 0 );
        CineScript_Camera_Kill();
        WAITUNWARPED( 1000 );
        StopLogMemory( "t:/mc4/LeakTestCharacters-test1.log2", 1 );
        StartLogMemory( "t:/mc4/testfinished.txt", 1 );
        StopLogMemory( "t:/mc4/testfinished.txt", 1 );
        while (true)
        {
            PRINTSTRING( "Done leak log- run ParseLeakTestCharacters.bat\n" );
            WAIT( 1000 );
        }
        LayerPlayer_KillPlayer( 0 );
        WAIT( 1000 );
        UIManager_UnloadHUD();
        UIManager_UnloadMovie( "HUDMAPMOVIE" );
        WAIT( 1000 );
        PRINTSTRING( "Script: UnloadCity LA\n" );
        LayerCity_UnloadCity();
    }
    return;
}
