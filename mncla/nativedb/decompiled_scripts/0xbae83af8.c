void main()
{
    string[17] sVar2;
    string[17] sVar20;
    string sVar38;
    string[1] sVar39;
    string sVar41;
    string sVar42;
    int I;
    unknown uVar44;
    unknown uVar45;
    boolean bVar46;
    unknown uVar47;
    unknown uVar48;
    unknown uVar49;
    unknown uVar50;
    vector vVar51;
    vector vVar54;
    unknown uVar57;

    array(ref sVar2, 17);
    sVar2[0] = "character/Drv_mp_01_set";
    sVar2[1] = "character/Drv_mp_01_lod02_set";
    sVar2[2] = "character/Mec_mc_01_set";
    sVar2[3] = "character/Mec_mc_01_lod02_set";
    sVar2[4] = "character/Drv_ma_03_set";
    sVar2[5] = "character/Drv_ma_03_lod02_set";
    sVar2[6] = "character/Drv_mb_02_set";
    sVar2[7] = "character/drv_mb_02_lod02_set";
    sVar2[8] = "character/drv_mh_02_set";
    sVar2[9] = "character/drv_mh_02_lod02_set";
    sVar2[10] = "character/drv_mb_04_set";
    sVar2[11] = "character/drv_mb_04_lod02_set";
    sVar2[12] = "character/drv_mb_008_set";
    sVar2[13] = "character/drv_mb_008_lod02_set";
    sVar2[14] = "character/Drv_mb_010_set";
    sVar2[15] = "character/drv_mb_010_lod02_set";
    sVar2[16] = "character/drv_fc_002_set";
    array(ref sVar20, 17);
    sVar20[0] = "Drv_mp_01_set";
    sVar20[1] = "Drv_mp_01_lod02_set";
    sVar20[2] = "Mec_mc_01_set";
    sVar20[3] = "Mec_mc_01_lod02_set";
    sVar20[4] = "Drv_ma_03_set";
    sVar20[5] = "Drv_ma_03_lod02_set";
    sVar20[6] = "Drv_mb_02_set";
    sVar20[7] = "drv_mb_02_lod02_set";
    sVar20[8] = "drv_mh_02_set";
    sVar20[9] = "drv_mh_02_lod02_set";
    sVar20[10] = "drv_mb_04_set";
    sVar20[11] = "drv_mb_04_lod02_set";
    sVar20[12] = "drv_mb_008_set";
    sVar20[13] = "drv_mb_008_lod02_set";
    sVar20[14] = "Drv_mb_010_set";
    sVar20[15] = "drv_mb_010_lod02_set";
    sVar20[16] = "drv_fc_002_set";
    sVar38 = "anim/Extras/male";
    array(ref sVar39, 1);
    sVar39[0] = "Mped_Idle";
    sVar41 = "anim/Extras/female";
    sVar42 = "FPed_Idle";
    I = 0;
    for ( I = 0; I < 17; I++ )
    {
        uVar44 = CineScript_Characters_LookupDriverToCutscenePath( sVar20[0 + I], 0 );
        uVar45 = CineScript_Characters_LookupDriverToCutsceneName( sVar20[0 + I], 0 );
        if ((NOT (StringCompare( uVar44, "" ))) AND (NOT (StringCompare( uVar45, "" ))))
        {
            sVar2[0 + I] = uVar44;
            sVar20[0 + I] = uVar45;
            PRINTSTRING( "Remapped " );
            PRINTSTRING( sVar20[0 + I] );
            PRINTSTRING( " to " );
            PRINTSTRING( uVar44 );
            PRINTSTRING( "/" );
            PRINTSTRING( uVar45 );
            PRINTSTRING( "\n" );
        }
    }
    bVar46 = false;
    while (NOT bVar46)
    {
        bVar46 = true;
        for ( I = 0; I < 17; I++ )
        {
            bVar46 = (bVar46) AND (CineScript_Characters_LoadType( sVar2[0 + I], sVar20[0 + I] ));
        }
        WAITUNWARPED( 100 );
    }
    for ( I = 0; I < 1; I++ )
    {
        bVar46 = (bVar46) AND (CineScript_Characters_LoadAnimation( sVar38, sVar39[I] ));
    }
    bVar46 = (bVar46) AND (CineScript_Characters_LoadAnimation( sVar41, sVar42 ));
    if (NOT bVar46)
    {
        PRINTSTRING( "Script 'test_lineup.sc' failed to load\n" );
        BREAKPOINT();
    }
    vVar51 = {464.80000000, 24.00000000, -884.10000000};
    vVar54 = {0.30000000, 0.00000000, 0.00000000};
    Math_VecRotateY( ref vVar54, ref vVar54, -140.00000000 * 0.01745329 );
    uVar47._fU0 = {vVar51.x, vVar51.y, vVar51.z};
    uVar47._fU12 = -140.00000000;
    for ( I = 0; I < 17; I++ )
    {
        uVar57 = CineScript_Characters_LaunchAnimAt( sVar2[0 + I], sVar20[0 + I], sVar38, sVar39[(0 + I) mod 1], ref uVar47, -1 );
        uVar47._fU0 = {uVar47._fU0 + vVar54};
        CineScript_PushKillBuffer( uVar57, 0 );
    }
    sub_1903( l_U0 );
    return;
}

void sub_1903(unknown uParam0)
{
    uParam0._fU0 = 3;
    return;
}
