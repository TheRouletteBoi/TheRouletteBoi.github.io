void main()
{
    string[10] sVar2;
    string[10] sVar13;
    string sVar24;
    string[1] sVar25;
    boolean bVar27;
    int I;
    unknown uVar29;
    unknown uVar30;
    unknown uVar31;
    unknown uVar32;
    vector vVar33;
    vector vVar36;
    unknown uVar39;

    array(ref sVar2, 10);
    sVar2[0] = "character/Drv_mh_01_set";
    sVar2[1] = "character/drv_mc_02_set";
    sVar2[2] = "character/Drv_ma_001_set";
    sVar2[3] = "character/Drv_ma_02_set";
    sVar2[4] = "character/Drv_mb_001_set";
    sVar2[5] = "character/Drv_mb_06_set";
    sVar2[6] = "character/Drv_mb_007_set";
    sVar2[7] = "character/drv_mc_05_set";
    sVar2[8] = "character/drv_fb_01_set";
    sVar2[9] = "character/drv_mh_006_set";
    array(ref sVar13, 10);
    sVar13[0] = "Drv_mh_01_set";
    sVar13[1] = "drv_mc_02_set";
    sVar13[2] = "Drv_ma_001_set";
    sVar13[3] = "Drv_ma_02_set";
    sVar13[4] = "Drv_mb_001_set";
    sVar13[5] = "Drv_mb_06_set";
    sVar13[6] = "Drv_mb_007_set";
    sVar13[7] = "drv_mc_05_set";
    sVar13[8] = "drv_fb_01_set";
    sVar13[9] = "drv_mh_006_set";
    sVar24 = "anim/Extras/male";
    array(ref sVar25, 1);
    sVar25[0] = "Mped_Idle";
    bVar27 = false;
    I = 0;
    while (NOT bVar27)
    {
        bVar27 = true;
        for ( I = 0; I < 10; I++ )
        {
            bVar27 = (bVar27) AND (CineScript_Characters_LoadType( sVar2[0 + I], sVar13[0 + I] ));
        }
        WAITUNWARPED( 100 );
    }
    for ( I = 0; I < 1; I++ )
    {
        bVar27 = (bVar27) AND (CineScript_Characters_LoadAnimation( sVar24, sVar25[I] ));
    }
    if (NOT bVar27)
    {
        PRINTSTRING( "Script 'test_lineup.sc' failed to load\n" );
        BREAKPOINT();
    }
    vVar33 = {464.80000000, 24.00000000, -884.10000000};
    vVar36 = {1.00000000, 0.00000000, 0.00000000};
    Math_VecRotateY( ref vVar36, ref vVar36, -140.00000000 * 0.01745329 );
    uVar29._fU0 = {vVar33.x, vVar33.y, vVar33.z};
    uVar29._fU12 = -140.00000000;
    for ( I = 0; I < 10; I++ )
    {
        uVar39 = CineScript_Characters_LaunchAnimAt( sVar2[0 + I], sVar13[0 + I], sVar24, sVar25[(0 + I) mod 1], ref uVar29, -1 );
        uVar29._fU0 = {uVar29._fU0 + vVar36};
        CineScript_PushKillBuffer( uVar39, 0 );
    }
    sub_1031( l_U0 );
    return;
}

void sub_1031(unknown uParam0)
{
    uParam0._fU0 = 3;
    return;
}
