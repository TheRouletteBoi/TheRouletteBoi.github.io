void main()
{
    vector[1] vVar2;
    unknown uVar4;
    unknown uVar5;
    float[1] fVar6;
    vector[2] vVar8;
    unknown uVar11;
    unknown uVar12;
    unknown uVar13;
    unknown uVar14;
    float[2] fVar15;
    float[2] fVar18;
    unknown uVar21;
    int I;
    unknown uVar23;
    int J;
    unknown uVar25;

    array(ref vVar2, 1);
    vVar2[0] = {0, 0, 0};
    array(ref fVar6, 1);
    fVar6[0] = 165;
    array(ref vVar8, 2);
    vVar8[0] = {-12.70000000, 0, 69.20000000};
    vVar8[1] = {-17.70000000, 0, 125.00000000};
    array(ref fVar15, 2);
    fVar15[0] = 10;
    fVar15[1] = 10;
    array(ref fVar18, 2);
    fVar18[0] = 10;
    fVar18[1] = 10;
    uVar21 = Race_GetCheckpointList( l_U0._fU12 );
    CheckpointList_Reset( uVar21 );
    CheckpointList_ResizeAltPaths( uVar21, 0, 0 );
    I = 0;
    uVar23 = nil;
    CheckpointList_ResizeList( uVar21, 2 );
    for ( I = 0; I < 2; I++ )
    {
        uVar23 = CheckpointList_GetCheckpoint( uVar21, I );
        Checkpoint_SetPosition( uVar23, ref vVar8[I] );
        Checkpoint_SetHeight( uVar23, fVar18[I] );
        Checkpoint_SetActivationRadius( uVar23, fVar15[I] );
    }
    J = 0;
    uVar25 = Race_GetRaceGrid( l_U0._fU12, 0 );
    for ( J = 0; J < 1; J++ )
    {
        RaceGrid_SetPosition( uVar25, J, ref vVar2[J], fVar6[J] );
    }
    sub_353( ref l_U0 );
    return;
}

void sub_353(int iParam0)
{
    int I;
    vector vVar4;
    unknown uVar7;
    vector vVar8;
    vector vVar11;
    int iVar14;
    unknown uVar15;

    PRINTSTRING( "LOADING RACE with " );
    PRINTINT( ref iParam0->_fU16->_fU3080 );
    PRINTSTRING( " racers\n" );
    vVar8 = {0, 1, 0};
    vVar11 = {0, 0, -1};
    RaceGrid_GetPosition( Race_GetRaceGrid( iParam0->_fU12, 0 ), 0, ref vVar4, ref uVar7 );
    Math_VecRotateY( ref vVar11, ref vVar11, uVar7 );
    vVar11 = {vVar11 + vVar4};
    vVar8 = {vVar8 + vVar4};
    UILogic_LockStreaming( ref vVar4, ref vVar8, ref vVar11 );
    for ( I = 0; I < (ref iParam0->_fU16->_fU3080); I++ )
    {
        PRINTSTRING( "Racer - " );
        PRINTINT( I );
        PRINTSTRING( "\n" );
        Racer_SetStreamingLockedIn( ref iParam0->_fU16->_fU4[I]._fU0 );
    }
    iVar14 = 1;
    while (iVar14 > 0)
    {
        iVar14 = ref iParam0->_fU16->_fU3080;
        for ( I = 0; I < (ref iParam0->_fU16->_fU3080); I++ )
        {
            if (Racer_IsCarStreamed( ref iParam0->_fU16->_fU4[I]._fU0 ))
            {
                iVar14--;
            }
        }
        if (iVar14 > 0)
        {
            WAITUNWARPED( 30 );
        }
    }
    while (NOT PoliceManager_IsAllStreamedIn())
    {
        WAITUNWARPED( 30 );
    }
    while (OpponentManager_StillStreamingOut())
    {
        WAITUNWARPED( 30 );
    }
    for ( I = 0; I < (ref iParam0->_fU16->_fU3080); I++ )
    {
        if ((ref iParam0->_fU16->_fU4[I]._fU8) == 2)
        {
            PRINTSTRING( " BRAIN CREATED! \n" );
            ref iParam0->_fU16->_fU4[I]._fU12 = BrainFactory_CreateBrainRacing( ref iParam0->_fU16->_fU4[I]._fU0 );
        }
    }
    uVar15 = START_NEW_SCRIPT_WITH_ARGS( "Game/RaceTypes/OrderedCheckpointCore", iParam0, 802, 3800 );
    while (NOT (IsChildFinished( uVar15 )))
    {
        WAITUNWARPED( 30 );
    }
    for ( I = 0; I < (ref iParam0->_fU16->_fU3080); I++ )
    {
        if ((ref iParam0->_fU16->_fU4[I]._fU8) == 2)
        {
            BrainFactory_DeleteBrain( ref iParam0->_fU16->_fU4[I]._fU0 );
        }
    }
    return;
}
