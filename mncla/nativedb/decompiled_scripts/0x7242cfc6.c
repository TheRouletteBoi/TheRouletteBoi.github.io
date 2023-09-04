void main()
{
    vector vVar2;
    vector vVar5;
    unknown uVar8;
    int I;
    unknown uVar10;
    unknown uVar11;
    unknown uVar12;

    if (NOT (l_U0._fU0 == 3))
    {
        l_U0._fU0 = 2;
        vVar2 = {-5, 0, 0};
        vVar5 = {65517, -1.50000000, 65428};
        uVar8 = Player_FindRacerObject( 0 );
        Racer_InitializeResetPosition( uVar8, ref vVar2, 0 );
        for ( I = 0; I < 6; I++ )
        {
            uVar10 = OpponentManager_CreateOpponent();
            OpponentManager_LoadOpponent( uVar10, "vp_mit_3000gt_99", ref vVar5, 0 );
            OpponentManager_AddOpponentToWorld( uVar10 );
            uVar11 = Opponent_GetRacer( uVar10 );
            Racer_SetStreamingLockedIn( uVar11 );
            while (NOT (Racer_IsSimStreamed( uVar11 )))
            {
                WAIT( 100 );
            }
            Racer_InitializeResetPosition( uVar11, ref vVar5, 0 );
            uVar12 = BrainFactory_CreateBrainCruising( uVar11 );
            BrainCruising_DriveToNearestRail( uVar12 );
            WAITUNWARPED( 2000 );
        }
    }
    sub_259( l_U0 );
    return;
}

void sub_259(unknown uParam0)
{
    uParam0._fU0 = 3;
    PRINTSTRING( "Script: finished section\n" );
    return;
}
