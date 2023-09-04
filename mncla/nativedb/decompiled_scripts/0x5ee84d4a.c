void main()
{
    string[20] sVar2;
    string[20] sVar23;
    string sVar44;
    string[1] sVar45;
    boolean bVar47;
    int I;
    unknown uVar49;
    unknown uVar50;
    unknown uVar51;
    unknown uVar52;
    vector vVar53;
    unknown uVar56;

    array(ref sVar2, 20);
    sVar2[0] = "character/drv_ma_03_set";
    sVar2[1] = "character/drv_mb_02_set";
    sVar2[2] = "character/drv_mb_03_set";
    sVar2[3] = "character/drv_mb_04_set";
    sVar2[4] = "character/drv_mb_05_set";
    sVar2[5] = "character/drv_mc_02_set";
    sVar2[6] = "character/drv_mc_06_set";
    sVar2[7] = "character/drv_mc_07_set";
    sVar2[8] = "character/drv_mh_01_set";
    sVar2[9] = "character/drv_mh_02_set";
    sVar2[10] = "character/drv_mp_01_set_blendshapes";
    sVar2[11] = "character/mec_mc_01_set";
    sVar2[12] = "character/drv_fb_01_set";
    sVar2[13] = "character/ped_ma_001_set";
    sVar2[14] = "character/ped_mb_001_set";
    sVar2[15] = "character/ped_mc_001_set";
    sVar2[16] = "character/ped_mh_001_set";
    sVar2[17] = "character/ped_fb_001_set";
    sVar2[18] = "character/ped_fc_001_set";
    sVar2[19] = "character/ped_fh_001_set";
    array(ref sVar23, 20);
    sVar23[0] = "drv_ma_03_set";
    sVar23[1] = "drv_mb_02_set";
    sVar23[2] = "drv_mb_03_set";
    sVar23[3] = "drv_mb_04_set";
    sVar23[4] = "drv_mb_05_set";
    sVar23[5] = "drv_mc_02_set";
    sVar23[6] = "drv_mc_06_set";
    sVar23[7] = "drv_mc_07_set";
    sVar23[8] = "drv_mh_01_set";
    sVar23[9] = "drv_mh_02_set";
    sVar23[10] = "drv_mp_01_set_blendshapes";
    sVar23[11] = "mec_mc_01_set";
    sVar23[12] = "drv_fb_01_set";
    sVar23[13] = "ped_ma_001_set";
    sVar23[14] = "ped_mb_001_set";
    sVar23[15] = "ped_mc_001_set";
    sVar23[16] = "ped_mh_001_set";
    sVar23[17] = "ped_fb_001_set";
    sVar23[18] = "ped_fc_001_set";
    sVar23[19] = "ped_fh_001_set";
    sVar44 = "anim";
    array(ref sVar45, 1);
    sVar45[0] = "BlendShape_test2";
    bVar47 = false;
    I = 0;
    while (NOT bVar47)
    {
        bVar47 = true;
        for ( I = 0; I < 1; I++ )
        {
            bVar47 = (bVar47) AND (CineScript_Characters_LoadType( sVar2[10 + I], sVar23[10 + I] ));
        }
        WAITUNWARPED( 100 );
    }
    for ( I = 0; I < 1; I++ )
    {
        bVar47 = (bVar47) AND (CineScript_Characters_LoadAnimation( sVar44, sVar45[I] ));
    }
    if (NOT bVar47)
    {
        PRINTSTRING( "Script 'test_blendshapes.sc' failed to load\n" );
        BREAKPOINT();
    }
    vVar53 = {464.80000000, 24.00000000, -884.10000000};
    uVar49._fU0 = {vVar53.x, vVar53.y, vVar53.z};
    uVar49._fU12 = 0.00000000;
    for ( I = 0; I < 1; I++ )
    {
        uVar56 = CineScript_Characters_LaunchAnimAt( sVar2[10 + I], sVar23[10 + I], sVar44, sVar45[(10 + I) mod 1], ref uVar49, -1 );
        uVar49._fU0._fU0 += 1.00000000;
        CineScript_PushKillBuffer( uVar56, 0 );
    }
    sub_1623( l_U0 );
    return;
}

void sub_1623(unknown uParam0)
{
    uParam0._fU0 = 3;
    return;
}
