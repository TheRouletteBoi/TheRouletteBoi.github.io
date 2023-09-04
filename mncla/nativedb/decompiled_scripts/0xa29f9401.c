void main()
{
    string[10] sVar2;
    string[10] sVar13;
    string[1] sVar24;
    string[1] sVar26;
    string sVar28;
    string sVar29;
    boolean bVar30;
    int I;
    unknown uVar32;
    unknown uVar33;
    unknown uVar34;
    unknown uVar35;
    vector vVar36;
    vector vVar39;
    int iVar42;
    unknown uVar43;

    array(ref sVar2, 10);
    sVar2[0] = "character/drv_ma_03_set_HackedScale";
    sVar2[1] = "character/";
    sVar2[2] = "character/";
    sVar2[3] = "character/";
    sVar2[4] = "character/";
    sVar2[5] = "character/";
    sVar2[6] = "character/";
    sVar2[7] = "character/";
    sVar2[8] = "character/";
    array(ref sVar13, 10);
    sVar13[0] = "drv_ma_03_set_HackedScale";
    sVar13[1] = "";
    sVar13[2] = "";
    sVar13[3] = "";
    sVar13[4] = "";
    sVar13[5] = "";
    sVar13[6] = "";
    sVar13[7] = "";
    sVar13[8] = "";
    array(ref sVar24, 1);
    array(ref sVar26, 1);
    sVar28 = "cutscene/story/cut_story_motorcycle_rep_B/Entity/andrew_drv01_name_drv_ma_03_set";
    sVar29 = "cutscene/story/cut_story_motorcycle_rep_IM/entity/andrew_drv01_name_drv_ma_03_set";
    sVar24[0] = "andrew_drv01_name_drv_ma_03_set";
    sVar26[0] = "andrew_drv01_name_drv_ma_03_set";
    while (true)
    {
        bVar30 = false;
        I = 0;
        while (NOT bVar30)
        {
            bVar30 = true;
            for ( I = 0; I < 1; I++ )
            {
                bVar30 = (bVar30) AND (CineScript_Characters_LoadType( sVar2[0 + I], sVar13[0 + I] ));
            }
            WAITUNWARPED( 100 );
        }
        for ( I = 0; I < 1; I++ )
        {
            bVar30 = (bVar30) AND (CineScript_Characters_LoadAnimationWithFaceXX( sVar28, sVar24[I], sVar29, sVar26[I] ));
        }
        if (NOT bVar30)
        {
            PRINTSTRING( "Script 'test_face_on_base_standing_in_place_Andrew.sc' failed to load\n" );
            BREAKPOINT();
        }
        vVar36 = {464.80000000, 24.00000000, -884.10000000};
        vVar39 = {1.00000000, 0.00000000, 0.00000000};
        Math_VecRotateY( ref vVar39, ref vVar39, -140.00000000 * 0.01745329 );
        uVar32._fU0 = {vVar36.x, vVar36.y, vVar36.z};
        uVar32._fU12 = -140.00000000;
        iVar42 = 0;
        for ( I = 0; I < 1; I++ )
        {
            if (I == 0)
            {
                uVar43 = CineScript_Characters_LaunchAnimWithFaceAtXX( sVar2[0 + I], sVar13[0 + I], sVar28, sVar24[(0 + I) mod 1], sVar29, sVar26[(0 + I) mod 1], ref uVar32, 1 );
                iVar42 = uVar43;
            }
            else
            {
                uVar43 = CineScript_Characters_LaunchAnimAt( sVar2[0 + I], sVar13[0 + I], sVar28, sVar24[(0 + I) mod 1], ref uVar32, 1 );
            }
            uVar32._fU0 = {uVar32._fU0 + vVar39};
            CineScript_PushKillBuffer( uVar43, 0 );
        }
        while ((CineScript_Characters_GetTimeRemainingForId( iVar42 )) > 0.00000000)
        {
            WAITUNWARPED( 100 );
        }
        CineScript_PopKillBuffer( 0 );
    }
    sub_1210( l_U0 );
    return;
}

void sub_1210(unknown uParam0)
{
    uParam0._fU0 = 3;
    return;
}
