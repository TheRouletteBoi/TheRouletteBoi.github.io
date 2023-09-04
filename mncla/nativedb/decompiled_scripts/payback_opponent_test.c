void main()
{
    string[3] sVar2;
    unknown[3] uVar6;
    vector[3] vVar10;
    unknown uVar14;
    unknown uVar15;
    unknown uVar16;
    unknown uVar17;
    unknown uVar18;
    unknown uVar19;
    float[3] fVar20;
    vector[3] vVar24;
    unknown uVar28;
    unknown uVar29;
    unknown uVar30;
    unknown uVar31;
    unknown uVar32;
    unknown uVar33;
    int[3] iVar34;
    unknown[3] uVar38;
    int I;
    unknown uVar43;
    int iVar44;

    l_U0 = "drv_mp_01_set";
    l_U1 = "drv_mp_01_lod02_set";
    l_U2 = "drv_ma_03_set";
    l_U3 = "drv_ma_02_set";
    l_U4 = "drv_ma_001_set";
    l_U5 = "drv_fa_001_set";
    l_U6 = "drv_mb_02_set";
    l_U7 = "drv_mb_03_set";
    l_U8 = "drv_mb_04_set";
    l_U9 = "drv_mb_05_set";
    l_U10 = "drv_mb_007_set";
    l_U11 = "drv_mb_008_set";
    l_U12 = "drv_mb_010_set";
    l_U13 = "drv_mb_001_set";
    l_U14 = "drv_mb_009_set";
    l_U15 = "drv_mb_06_set";
    l_U16 = "drv_fb_01_set";
    l_U17 = "drv_mc_02_set";
    l_U18 = "drv_mc_06_set";
    l_U19 = "drv_mc_07_set";
    l_U20 = "drv_mc_003_set";
    l_U21 = "drv_mc_05_set";
    l_U22 = "drv_mc_001_set";
    l_U23 = "drv_fc_002_set";
    l_U24 = "drv_mh_01_set";
    l_U25 = "drv_mh_02_set";
    l_U26 = "drv_mh_003_set";
    l_U27 = "drv_mh_005_set";
    l_U28 = "drv_mh_04_set";
    l_U29 = "drv_mh_006_set";
    l_U30 = "drv_fh_001_set";
    l_U31 = "mec_mc_01_set";
    l_U32 = "ped_ma_001_set";
    l_U33 = "ped_mb_001_set";
    l_U34 = "ped_mc_001_set";
    l_U35 = "ped_mh_001_set";
    l_U36 = "pol_mc_01_set";
    array(ref sVar2, 3);
    array(ref uVar6, 3);
    array(ref vVar10, 3);
    array(ref fVar20, 3);
    array(ref vVar24, 3);
    array(ref iVar34, 3);
    sVar2[0] = "pyback_gn_vp_dge_challenger_70";
    uVar6[0] = l_U14;
    vVar10[0] = {434.10000000, 24.20000000, -887.40000000};
    fVar20[0] = 180;
    vVar24[0] = {-470.00000000, 9.50000000, -390.00000000};
    iVar34[0] = 450;
    sVar2[1] = "pyback_gn_vp_dge_charger_06";
    uVar6[1] = l_U13;
    vVar10[1] = {116.10000000, 23.60000000, -885.20000000};
    fVar20[1] = 0.00000000;
    vVar24[1] = {-490.00000000, 9.50000000, -390.00000000};
    iVar34[1] = 451;
    sVar2[2] = "pyback_gn_vp_pon_transam_79";
    uVar6[2] = l_U7;
    vVar10[2] = {551.70000000, 23.30000000, -869.30000000};
    fVar20[2] = 0.00000000;
    vVar24[2] = {-520.00000000, 9.50000000, -390.00000000};
    iVar34[2] = 452;
    array(ref uVar38, 3);
    uVar43 = nil;
    for ( I = 0; I < 3; I++ )
    {
        uVar38[I] = PoliceManager_CreatePolice( sVar2[I], 0, ref vVar10[I], fVar20[I], ref vVar24[I], 400 + I );
        uVar43 = PoliceManager_GetRacer( uVar38[I] );
        Racer_SetIconType( uVar43, 13 );
        Racer_SetCharacterName( uVar43, uVar6[I] );
        Racer_SetUIDAndCharacterName( uVar43, iVar34[I], uVar6[I] );
        Racer_HideIcon( uVar43, 0 );
    }
    PoliceManager_SetAllPoliceUnderground( 1, 0 );
    iVar44 = 0;
    Registry_SetValueInt( "Shutdown_PaybackOpponents", iVar44 );
    while (iVar44 == 0)
    {
        Registry_GetValueInt( "Shutdown_PaybackOpponents", ref iVar44 );
        WAITUNWARPED( 100 );
    }
    PRINTSTRING( "Payback opponent shutdown\n" );
    for ( I = 0; I < 3; I++ )
    {
        PoliceManager_DestroyPolice( uVar38[I] );
    }
    return;
}
