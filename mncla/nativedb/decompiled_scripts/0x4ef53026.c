void main()
{
    vector vVar2;
    vector vVar5;
    vector vVar8;
    unknown uVar11;
    int I;
    unknown[7] uVar13;
    unknown[7] uVar21;
    unknown[7] uVar29;

    if (NOT (l_U0._fU0 == 3))
    {
        l_U0._fU0 = 2;
        vVar2 = {-5, 0, 0};
        vVar5 = {65517, 0, 65428};
        vVar8 = {5, 0, 65436};
        uVar11 = Player_FindRacerObject( 0 );
        Racer_InitializeResetPosition( uVar11, ref vVar2, 0 );
        array(ref uVar13, 7);
        array(ref uVar21, 7);
        array(ref uVar29, 7);
        for ( I = 0; I < 7; I++ )
        {
            vVar5.z += 5;
            uVar13[I] = OpponentManager_CreateOpponent();
            OpponentManager_LoadOpponent( uVar13[I], "vp_mit_3000gt_99", ref vVar5, 0 );
            uVar21[I] = sub_185( uVar13[I] );
            OpponentManager_AddOpponentToWorld( uVar13[I] );
            uVar29[I] = Opponent_GetRacer( uVar13[I] );
            Racer_InitializeResetPosition( uVar29[I], ref vVar5, 0 );
        }
        while (true)
        {
            for ( I = 0; I < 7; I++ )
            {
                Racer_GetPosition( uVar11, ref vVar8 );
                BrainRacing_Reset( uVar21[I] );
                BrainRacing_AppendGoal( uVar21[I], ref vVar8, 1 );
                WAIT( 1000 );
            }
        }
    }
    sub_392( l_U0 );
    return;
}

void sub_185(unknown uParam0)
{
    return BrainFactory_CreateBrainRacing( Opponent_GetRacer( uParam0 ) );
}

void sub_392(unknown uParam0)
{
    uParam0._fU0 = 3;
    PRINTSTRING( "Script: finished section\n" );
    return;
}
