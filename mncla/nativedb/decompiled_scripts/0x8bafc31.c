void main()
{
    string[10] sVar2;
    string[10] sVar13;
    string sVar24;
    string[1] sVar25;
    string sVar27;
    string sVar28;
    boolean bVar29;
    int I;
    unknown uVar31;
    unknown uVar32;
    unknown uVar33;
    unknown uVar34;
    vector vVar35;
    vector vVar38;
    unknown uVar41;

    array(ref sVar2, 10);
    sVar2[0] = "character/Drv_mp_01_set";
    sVar2[1] = "character/Mec_mc_01_set";
    sVar2[2] = "character/Drv_ma_03_set";
    sVar2[3] = "character/Drv_mb_02_set";
    sVar2[4] = "character/drv_mh_02_set";
    sVar2[5] = "character/drv_mb_04_set";
    sVar2[6] = "character/drv_mb_008_set";
    sVar2[7] = "character/Drv_mb_010_set";
    sVar2[8] = "character/drv_fc_002_set";
    sVar2[9] = "character/";
    array(ref sVar13, 10);
    sVar13[0] = "Drv_mp_01_set";
    sVar13[1] = "Mec_mc_01_set";
    sVar13[2] = "Drv_ma_03_set";
    sVar13[3] = "Drv_mb_02_set";
    sVar13[4] = "drv_mh_02_set";
    sVar13[5] = "drv_mb_04_set";
    sVar13[6] = "drv_mb_008_set";
    sVar13[7] = "Drv_mb_010_set";
    sVar13[8] = "drv_fc_002_set";
    sVar13[9] = "";
    sVar24 = "anim/Extras/male";
    array(ref sVar25, 1);
    sVar25[0] = "Mped_Idle";
    sVar27 = "anim/Extras/female";
    sVar28 = "FPed_Idle";
    bVar29 = false;
    I = 0;
    while (NOT bVar29)
    {
        bVar29 = true;
        for ( I = 0; I < 9; I++ )
        {
            bVar29 = (bVar29) AND (CineScript_Characters_LoadType( sVar2[0 + I], sVar13[0 + I] ));
        }
        WAITUNWARPED( 100 );
    }
    for ( I = 0; I < 1; I++ )
    {
        bVar29 = (bVar29) AND (CineScript_Characters_LoadAnimation( sVar24, sVar25[I] ));
    }
    bVar29 = (bVar29) AND (CineScript_Characters_LoadAnimation( sVar27, sVar28 ));
    if (NOT bVar29)
    {
        PRINTSTRING( "Script 'test_lineup.sc' failed to load\n" );
        BREAKPOINT();
    }
    vVar35 = {464.80000000, 24.00000000, -884.10000000};
    vVar38 = {1.00000000, 0.00000000, 0.00000000};
    Math_VecRotateY( ref vVar38, ref vVar38, -140.00000000 * 0.01745329 );
    uVar31._fU0 = {vVar35.x, vVar35.y, vVar35.z};
    uVar31._fU12 = -140.00000000;
    for ( I = 0; I < 9; I++ )
    {
        uVar41 = CineScript_Characters_LaunchAnimAt( sVar2[0 + I], sVar13[0 + I], sVar24, sVar25[(0 + I) mod 1], ref uVar31, -1 );
        uVar31._fU0 = {uVar31._fU0 + vVar38};
        CineScript_PushKillBuffer( uVar41, 0 );
    }
    sub_1062( l_U0 );
    return;
}

void sub_1062(unknown uParam0)
{
    uParam0._fU0 = 3;
    return;
}
