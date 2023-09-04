void main()
{
    string[9] sVar2;
    string[9] sVar12;
    string sVar22;
    string[1] sVar23;
    boolean bVar25;
    int I;
    unknown uVar27;
    unknown uVar28;
    unknown uVar29;
    unknown uVar30;
    vector vVar31;
    vector vVar34;
    unknown uVar37;

    array(ref sVar2, 9);
    sVar2[0] = "character/drv_mp_01_set";
    sVar2[1] = "character/drv_mp_01_set_h";
    sVar2[2] = "character/";
    sVar2[3] = "character/";
    sVar2[4] = "character/";
    sVar2[5] = "character/";
    sVar2[6] = "character/";
    sVar2[7] = "character/";
    sVar2[8] = "character/";
    array(ref sVar12, 9);
    sVar12[0] = "drv_mp_01_set";
    sVar12[1] = "drv_mp_01_set_h";
    sVar12[2] = "";
    sVar12[3] = "";
    sVar12[4] = "";
    sVar12[5] = "";
    sVar12[6] = "";
    sVar12[7] = "";
    sVar12[8] = "";
    sVar22 = "anim/Extras/male";
    array(ref sVar23, 1);
    sVar23[0] = "Mped_Idle";
    bVar25 = false;
    I = 0;
    while (NOT bVar25)
    {
        bVar25 = true;
        for ( I = 0; I < 2; I++ )
        {
            bVar25 = (bVar25) AND (CineScript_Characters_LoadType( sVar2[0 + I], sVar12[0 + I] ));
        }
        WAITUNWARPED( 100 );
    }
    for ( I = 0; I < 1; I++ )
    {
        bVar25 = (bVar25) AND (CineScript_Characters_LoadAnimation( sVar22, sVar23[I] ));
    }
    if (NOT bVar25)
    {
        PRINTSTRING( "Script 'test_lineup9.sc' failed to load\n" );
        BREAKPOINT();
    }
    vVar31 = {464.80000000, 24.00000000, -884.10000000};
    vVar34 = {1.00000000, 0.00000000, 0.00000000};
    Math_VecRotateY( ref vVar34, ref vVar34, -140.00000000 * 0.01745329 );
    uVar27._fU0 = {vVar31.x, vVar31.y, vVar31.z};
    uVar27._fU12 = -140.00000000;
    for ( I = 0; I < 2; I++ )
    {
        uVar37 = CineScript_Characters_LaunchAnimAt( sVar2[0 + I], sVar12[0 + I], sVar22, sVar23[(0 + I) mod 1], ref uVar27, -1 );
        uVar27._fU0 = {uVar27._fU0 + vVar34};
        CineScript_PushKillBuffer( uVar37, 0 );
    }
    sub_785( l_U0 );
    return;
}

void sub_785(unknown uParam0)
{
    uParam0._fU0 = 3;
    return;
}
