void main()
{
    unknown uVar2;

    PRINTSTRING( "Script: Starting an EditorRace...\n" );
    PRINTSTRING( "Script: Assuming type is Ordered Ordered (Traditional) for EditorRace...\n" );
    l_U0._fU16._fU3088 = 1;
    l_U0._fU16._fU3092 = 1;
    l_U0._fU16._fU3096 = 1;
    l_U0._fU16._fU3140 = 1;
    l_U0._fU3196 = "Game/RaceTypes/generic_countdown";
    PRINTSTRING( "Script: Populating checkpoint list...\n" );
    Net_EditorRaceCreateCheckpoints( l_U0._fU12 );
    PRINTSTRING( "Script: Populating checkpoint list...\n" );
    Net_EditorPopulateGrid( l_U0._fU12, 0 );
    Race_SetRaceData( l_U0._fU12, ref l_U0._fU16 );
    uVar2 = START_NEW_SCRIPT_WITH_ARGS( "game/racetypes/OrderedCheckpointCore", ref l_U0, 802, 0 );
    while (NOT (IsChildFinished( uVar2 )))
    {
        WAIT( 100 );
    }
    PRINTSTRING( "Script: Finished an EditorRace...\n" );
    return;
}
