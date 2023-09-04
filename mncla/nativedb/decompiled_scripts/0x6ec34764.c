void main()
{
    string sVar2;
    string sVar3;
    string sVar4;
    string sVar5;
    string sVar6;
    string sVar7;
    string sVar8;
    string sVar9;
    string sVar10;
    string sVar11;
    string sVar12;
    string sVar13;
    string sVar14;
    string sVar15;
    string sVar16;
    string sVar17;
    string sVar18;
    string sVar19;
    string sVar20;
    string sVar21;
    string sVar22;
    string sVar23;
    unknown uVar24;
    unknown uVar25;
    unknown uVar26;
    unknown uVar27;
    unknown uVar28;
    unknown uVar29;
    boolean bVar30;
    boolean bVar31;
    float fVar32;
    unknown uVar33;

    sVar2 = "character/drv_mb_05_set";
    sVar3 = "drv_mb_05_set";
    sVar4 = "cutscene/cut_hw_hk2_4/Entity/Cut_Hk1";
    sVar5 = "Cut_Hk1";
    sVar6 = "character/drv_ma_03_set";
    sVar7 = "drv_ma_03_set";
    sVar8 = "cutscene/cut_hw_hk2_4/Entity/Cut_Hk2";
    sVar9 = "Cut_Hk2";
    sVar10 = "character/drv_mb_04_set";
    sVar11 = "drv_mb_04_set";
    sVar12 = "cutscene/cut_hw_hk2_4/Entity/Cut_Hk3";
    sVar13 = "Cut_Hk3";
    sVar14 = "character/drv_mh_01_set";
    sVar15 = "drv_mh_01_set";
    sVar16 = "cutscene/cut_hw_hk2_4/Entity/Cut_Hk4";
    sVar17 = "Cut_Hk4";
    sVar18 = "cutscene/cut_hw_hk2_4";
    sVar19 = "CUT_HW_HK2_4";
    sVar20 = "OpponentA";
    sVar21 = "OpponentB";
    sVar22 = "OpponentC";
    sVar23 = "CSCamera";
    uVar24._fU8._fU0 = {737.50000000, 7.38000000, -294.00000000};
    uVar24._fU8._fU12 = 180.00000000;
    CineScript_SetGameCoordSysBinding( ref uVar24 );
    CineScript_GetGameCoordSysBinding( ref uVar24 );
    bVar30 = true;
    bVar30 = (bVar30) AND (CineScript_Characters_LoadType( sVar2, sVar3 ));
    bVar30 = (bVar30) AND (CineScript_Characters_LoadType( sVar6, sVar7 ));
    bVar30 = (bVar30) AND (CineScript_Characters_LoadType( sVar10, sVar11 ));
    bVar30 = (bVar30) AND (CineScript_Characters_LoadType( sVar14, sVar15 ));
    bVar30 = (bVar30) AND (CineScript_Characters_LoadAnimation( sVar4, sVar5 ));
    bVar30 = (bVar30) AND (CineScript_Characters_LoadAnimation( sVar8, sVar9 ));
    bVar30 = (bVar30) AND (CineScript_Characters_LoadAnimation( sVar12, sVar13 ));
    bVar30 = (bVar30) AND (CineScript_Characters_LoadAnimation( sVar16, sVar17 ));
    bVar30 = (bVar30) AND (CineScript_Camera_LoadAnimation( sVar18, sVar23 ));
    if (NOT bVar30)
    {
        PRINTSTRING( "Script 'test_cut_hw_hk2_4_standing.cs' failed to load\n" );
        BREAKPOINT();
    }
    bVar31 = false;
    while (NOT bVar31)
    {
        bVar31 = true;
        bVar31 = (bVar31) AND (CineScript_Audio_PrepareStream( sVar19 ));
        if (bVar31)
        {
            CineScript_BeginDescription();
            CineScript_SetSceneCoordSysBinding( ref uVar24 );
            fVar32 = 0.00000000;
            uVar33 = CineScript_Characters_LaunchAnimEvent( sVar2, sVar3, sVar4, sVar5, fVar32, 1 );
            CineScript_PushKillBuffer( uVar33, 1 );
            uVar33 = CineScript_Characters_LaunchAnimEvent( sVar6, sVar7, sVar8, sVar9, fVar32, 1 );
            CineScript_PushKillBuffer( uVar33, 1 );
            uVar33 = CineScript_Characters_LaunchAnimEvent( sVar10, sVar11, sVar12, sVar13, fVar32, 1 );
            CineScript_PushKillBuffer( uVar33, 1 );
            uVar33 = CineScript_Characters_LaunchAnimEvent( sVar14, sVar15, sVar16, sVar17, fVar32, 1 );
            CineScript_PushKillBuffer( uVar33, 1 );
            CineScript_Camera_LaunchEventTrimmed( sVar18, sVar23, fVar32, 2.70000000, 0.00000000 );
            CineScript_EndDescriptionAndStartClock();
            CineScript_Audio_PlayStream();
        }
        WAITUNWARPED( 100 );
    }
    while (CineScript_IsScenePlaying())
    {
        WAITUNWARPED( 10 );
    }
    CineScript_Camera_Kill();
    CineScript_PopKillBuffer( 1 );
    CineScript_FinishScene();
    sub_1173( l_U0 );
    return;
}

void sub_1173(unknown uParam0)
{
    uParam0._fU0 = 3;
    return;
}
