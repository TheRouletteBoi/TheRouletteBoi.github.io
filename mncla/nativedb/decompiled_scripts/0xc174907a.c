void main()
{
    string[21] sVar2;
    string[21] sVar24;
    string sVar46;
    string[1] sVar47;
    string sVar49;
    string sVar50;
    boolean bVar51;
    int I;
    unknown uVar53;
    unknown uVar54;
    unknown uVar55;
    unknown uVar56;
    vector vVar57;
    vector vVar60;
    unknown uVar63;

    array(ref sVar2, 21);
    sVar2[0] = "character/ped_ma_001_set";
    sVar2[1] = "character/ped_ma_002_set";
    sVar2[2] = "character/ped_ma_003_set";
    sVar2[3] = "character/ped_ma_004_set";
    sVar2[4] = "character/ped_mb_001_set";
    sVar2[5] = "character/ped_mb_002_set";
    sVar2[6] = "character/ped_mb_003_set";
    sVar2[7] = "character/ped_mb_004_set";
    sVar2[8] = "character/ped_mb_005_set";
    sVar2[9] = "character/ped_mc_001_set";
    sVar2[10] = "character/ped_mc_002_set";
    sVar2[11] = "character/ped_mc_003_set";
    sVar2[12] = "character/ped_mc_004_set";
    sVar2[13] = "character/ped_mc_005_set";
    sVar2[14] = "character/ped_mc_006_set";
    sVar2[15] = "character/ped_mc_007_set";
    sVar2[16] = "character/ped_mc_008_set";
    sVar2[17] = "character/ped_mh_001_set";
    sVar2[18] = "character/ped_mh_002_set";
    sVar2[19] = "character/ped_mh_004_set";
    sVar2[20] = "character/";
    array(ref sVar24, 21);
    sVar24[0] = "ped_ma_001_set";
    sVar24[1] = "ped_ma_002_set";
    sVar24[2] = "ped_ma_003_set";
    sVar24[3] = "ped_ma_004_set";
    sVar24[4] = "ped_mb_001_set";
    sVar24[5] = "ped_mb_002_set";
    sVar24[6] = "ped_mb_003_set";
    sVar24[7] = "ped_mb_004_set";
    sVar24[8] = "ped_mb_005_set";
    sVar24[9] = "ped_mc_001_set";
    sVar24[10] = "ped_mc_002_set";
    sVar24[11] = "ped_mc_003_set";
    sVar24[12] = "ped_mc_004_set";
    sVar24[13] = "ped_mc_005_set";
    sVar24[14] = "ped_mc_006_set";
    sVar24[15] = "ped_mc_007_set";
    sVar24[16] = "ped_mc_008_set";
    sVar24[17] = "ped_mh_001_set";
    sVar24[18] = "ped_mh_002_set";
    sVar24[19] = "ped_mh_004_set";
    sVar24[20] = "";
    sVar46 = "anim/Extras/male";
    array(ref sVar47, 1);
    sVar47[0] = "Mped_Idle";
    sVar49 = "anim/Extras/female";
    sVar50 = "FPed_Idle";
    bVar51 = false;
    I = 0;
    while (NOT bVar51)
    {
        bVar51 = true;
        for ( I = 0; I < 20; I++ )
        {
            bVar51 = (bVar51) AND (CineScript_Characters_LoadType( sVar2[0 + I], sVar24[0 + I] ));
        }
        WAITUNWARPED( 100 );
    }
    for ( I = 0; I < 1; I++ )
    {
        bVar51 = (bVar51) AND (CineScript_Characters_LoadAnimation( sVar46, sVar47[I] ));
    }
    bVar51 = (bVar51) AND (CineScript_Characters_LoadAnimation( sVar49, sVar50 ));
    if (NOT bVar51)
    {
        PRINTSTRING( "Script 'test_lineup.sc' failed to load\n" );
        BREAKPOINT();
    }
    vVar57 = {464.80000000, 24.00000000, -884.10000000};
    vVar60 = {1.00000000, 0.00000000, 0.00000000};
    Math_VecRotateY( ref vVar60, ref vVar60, -140.00000000 * 0.01745329 );
    uVar53._fU0 = {vVar57.x, vVar57.y, vVar57.z};
    uVar53._fU12 = -140.00000000;
    for ( I = 0; I < 20; I++ )
    {
        uVar63 = CineScript_Characters_LaunchAnimAt( sVar2[0 + I], sVar24[0 + I], sVar46, sVar47[(0 + I) mod 1], ref uVar53, -1 );
        uVar53._fU0 = {uVar53._fU0 + vVar60};
        CineScript_PushKillBuffer( uVar63, 0 );
    }
    sub_1769( l_U0 );
    return;
}

void sub_1769(unknown uParam0)
{
    uParam0._fU0 = 3;
    return;
}
