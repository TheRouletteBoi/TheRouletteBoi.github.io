void main()
{
    unknown uVar2;
    unknown uVar3;

    uVar2 = Player_FindRacerObject( 0 );
    sub_19();
    sub_468();
    PRINTSTRING( "Script: Networking/ResumeCareer.sc: Network players are shutdown, resuming career now.\n" );
    while (NOT (Racer_IsCarStreamed( uVar2 )))
    {
        PRINTSTRING( "\n[SCRIPT] ResumeCareer: Waiting for my car to stream in" );
        WAIT( 500 );
    }
    if (NOT ((GetNoTutorialCommandLine()) || (GetNoCareerCommandLine())))
    {
        uVar3 = mcMissionManager_GetMission( "RACE_GH_06" );
        if ((mcMission_GetState( uVar3 )) == 2)
        {
            mcMission_ChangeState( uVar3, 0, 0 );
            mcMission_ChangeState( uVar3, 2, 0 );
            UIManager_SendEvent( "warpingToRace" );
        }
    }
    sub_1137();
    mcGame_ThrowEvent( "cruising" );
    return;
}

void sub_19()
{
    int iVar2;
    boolean bVar3;
    int I;

    iVar2 = 0;
    bVar3 = false;
    PRINTSTRING( "Script: Networking/ResumeCareer.sc: waiting for remote players to unload...\n" );
    while (NOT bVar3)
    {
        iVar2 = 0;
        for ( I = 0; I < PlayerManager_GetNumPlayers(); I++ )
        {
            if (PlayerManager_IsPlayerValid( I ))
            {
                if (NOT (PlayerManager_IsLocalPlayer( I )))
                {
                    iVar2++;
                }
            }
        }
        if (iVar2 == 0)
        {
            PRINTSTRING( "Script: Networking/ResumeCareer.sc: no more valid remote players remain...\n" );
            bVar3 = true;
        }
        else
        {
            PRINTSTRING( "Script: Networking/ResumeCareer.sc: " );
            PRINTINT( iVar2 );
            PRINTSTRING( " valid remote players remaining. Waiting for remote players to finish unloading...\n" );
            WAIT( 100 );
        }
    }
    return;
}

void sub_468()
{
    int iVar2;
    boolean bVar3;

    iVar2 = 0;
    bVar3 = false;
    PRINTSTRING( "Script: Networking/ResumeCareer.sc: waiting for dead players to be deleted...\n" );
    while (NOT bVar3)
    {
        iVar2 = PlayerManager_GetNumDeadPlayers();
        if (iVar2 == 0)
        {
            PRINTSTRING( "Script: Networking/ResumeCareer.sc: no dead players remaining...\n" );
            bVar3 = true;
        }
        else
        {
            PRINTSTRING( "Script: Networking/ResumeCareer.sc: " );
            PRINTINT( iVar2 );
            PRINTSTRING( " dead players remaining. Waiting for dead players to finish unloading...\n" );
            WAIT( 100 );
        }
    }
    return;
}

void sub_1137()
{
    string[3] sVar2;
    vector[3] vVar6;
    unknown uVar10;
    unknown uVar11;
    unknown uVar12;
    unknown uVar13;
    unknown uVar14;
    unknown uVar15;
    float[3] fVar16;
    vector[3] vVar20;
    unknown uVar24;
    unknown uVar25;
    unknown uVar26;
    unknown uVar27;
    unknown uVar28;
    unknown uVar29;
    unknown[3] uVar30;
    int I;

    array(ref sVar2, 3);
    array(ref vVar6, 3);
    array(ref fVar16, 3);
    array(ref vVar20, 3);
    sVar2[0] = "vp_chv_police_96";
    vVar6[0] = {2030.10000000, 6.80000000, -813.70000000};
    fVar16[0] = 90;
    vVar20[0] = {-510.00000000, 9.50000000, -400.00000000};
    sVar2[1] = "vp_chv_police_96";
    vVar6[1] = {-646.80000000, 18.50000000, -643.80000000};
    fVar16[1] = 90;
    vVar20[1] = {-500.00000000, 9.50000000, -400.00000000};
    sVar2[2] = "vp_chv_police_96";
    vVar6[2] = {-2434.40000000, 1.90000000, -577.90000000};
    fVar16[2] = 84.90000000;
    vVar20[2] = {-490.00000000, 9.50000000, -400.00000000};
    array(ref uVar30, 3);
    for ( I = 0; I < 3; I++ )
    {
        uVar30[I] = PoliceManager_CreatePolice( sVar2[I], 1, ref vVar6[I], fVar16[I], ref vVar20[I], 400 + I );
    }
    return;
}
