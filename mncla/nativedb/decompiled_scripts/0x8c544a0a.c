void main()
{
    string[12] sVar2;
    string[12] sVar15;
    string sVar28;
    string[1] sVar29;
    string sVar31;
    string sVar32;
    boolean bVar33;
    int I;
    unknown uVar35;
    unknown uVar36;
    unknown uVar37;
    unknown uVar38;
    vector vVar39;
    vector vVar42;
    unknown uVar45;

    array(ref sVar2, 12);
    sVar2[0] = "character/prp_bat_001_set";
    sVar2[1] = "character/prp_buffer_001_set";
    sVar2[2] = "character/prp_glass_001_set";
    sVar2[3] = "character/prp_handgun_001_set";
    sVar2[4] = "character/prp_mercedesKeys_001_set";
    sVar2[5] = "character/prp_moneyBag_001_set";
    sVar2[6] = "character/prp_paperCup_001_set";
    sVar2[7] = "character/prp_paybackKeys_001_set";
    sVar2[8] = "character/prp_platter_001_set";
    sVar2[9] = "character/prp_shoppingBag_001_set";
    sVar2[10] = "character/prp_shotgun_001_set";
    sVar2[11] = "character/";
    array(ref sVar15, 12);
    sVar15[0] = "prp_bat_001_set";
    sVar15[1] = "prp_buffer_001_set";
    sVar15[2] = "prp_glass_001_set";
    sVar15[3] = "prp_handgun_001_set";
    sVar15[4] = "prp_mercedesKeys_001_set";
    sVar15[5] = "prp_moneyBag_001_set";
    sVar15[6] = "prp_paperCup_001_set";
    sVar15[7] = "prp_paybackKeys_001_set";
    sVar15[8] = "prp_platter_001_set";
    sVar15[9] = "prp_shoppingBag_001_set";
    sVar15[10] = "prp_shotgun_001_set";
    sVar15[11] = "prp_sidekick_001_set";
    sVar28 = "anim/Extras/male";
    array(ref sVar29, 1);
    sVar29[0] = "Mped_Idle";
    sVar31 = "anim/Extras/female";
    sVar32 = "FPed_Idle";
    bVar33 = false;
    I = 0;
    while (NOT bVar33)
    {
        bVar33 = true;
        for ( I = 0; I < 6; I++ )
        {
            bVar33 = (bVar33) AND (CineScript_Characters_LoadType( sVar2[0 + I], sVar15[0 + I] ));
        }
        WAITUNWARPED( 100 );
    }
    for ( I = 0; I < 1; I++ )
    {
        bVar33 = (bVar33) AND (CineScript_Characters_LoadAnimation( sVar28, sVar29[I] ));
    }
    bVar33 = (bVar33) AND (CineScript_Characters_LoadAnimation( sVar31, sVar32 ));
    if (NOT bVar33)
    {
        PRINTSTRING( "Script 'test_lineup.sc' failed to load\n" );
        BREAKPOINT();
    }
    vVar39 = {464.80000000, 24.00000000, -884.10000000};
    vVar42 = {1.00000000, 0.00000000, 0.00000000};
    Math_VecRotateY( ref vVar42, ref vVar42, -140.00000000 * 0.01745329 );
    uVar35._fU0 = {vVar39.x, vVar39.y, vVar39.z};
    uVar35._fU12 = -140.00000000;
    for ( I = 0; I < 6; I++ )
    {
        uVar45 = CineScript_Characters_LaunchAnimAt( sVar2[0 + I], sVar15[0 + I], sVar28, sVar29[(0 + I) mod 1], ref uVar35, -1 );
        uVar35._fU0 = {uVar35._fU0 + vVar42};
        CineScript_PushKillBuffer( uVar45, 0 );
    }
    sub_1402( l_U0 );
    return;
}

void sub_1402(unknown uParam0)
{
    uParam0._fU0 = 3;
    return;
}
