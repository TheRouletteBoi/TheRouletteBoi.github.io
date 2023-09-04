void main()
{
    sub_17( 0, 1, l_U0._fU20, 0 );
    l_U0._fU0 = 3;
    return;
}

void sub_17(boolean bParam0, boolean bParam1, unknown uParam2, unknown uParam3)
{
    int iVar6;
    int iVar7;
    int iVar8;
    int iVar9;

    iVar6 = nil;
    while (iVar6 == nil)
    {
        iVar6 = UIManager_FindMovie( "TRANSITIONMOVIE" );
        if (iVar6 == nil)
        {
            PRINTSTRING( "SCRIPT: waiting for transition movie to stream in...\n" );
            WAITUNWARPED( 10 );
        }
    }
    iVar7 = 0;
    iVar8 = 0;
    iVar9 = 0;
    FlashHelper_GetGlobalInt( iVar6, "StartOfTransitionout", ref iVar7 );
    FlashHelper_GetGlobalInt( iVar6, "StartOfTransitionin", ref iVar8 );
    FlashHelper_GetGlobalInt( iVar6, "TransitionOutisReady", ref iVar9 );
    PRINTSTRING( "FADE DOWN REPORT\n" );
    PRINTSTRING( "================\n" );
    PRINTSTRING( "TransitionOut: " );
    PRINTINT( iVar7 );
    PRINTSTRING( "\nTransitionIn: " );
    PRINTINT( iVar8 );
    PRINTSTRING( "\nnTransitionReady: " );
    PRINTINT( iVar9 );
    PRINTSTRING( "\n" );
    if ((iVar8 == 0) AND ((iVar9 == 0) || ((iVar7 == 1) AND (iVar9 == 2))))
    {
        FlashHelper_SetMovieEnabled( iVar6, 1 );
        FlashHelper_SetGlobalInt( iVar6, "cur_visibility", 1 );
        FlashHelper_SetGlobalInt( iVar6, "mask_color", uParam3 );
        if (bParam1)
        {
            FlashHelper_SetGlobalInt( iVar6, "transition_type", 0 );
        }
        else
        {
            FlashHelper_SetGlobalInt( iVar6, "transition_type", 1 );
        }
        FlashHelper_SetGlobalFloat( iVar6, "fade_speed_in", uParam2 );
        FlashHelper_SetGlobalFloat( iVar6, "fade_speed_out", 0.01000000 );
        FlashHelper_SetGlobalInt( iVar6, "StartOfTransitionout", 0 );
        FlashHelper_SetGlobalInt( iVar6, "TransitionOutisReady", 0 );
        FlashHelper_SetGlobalInt( iVar6, "StartOfTransitionin", 1 );
        if (bParam0)
        {
            iVar8 = 1;
            while (iVar8 == 1)
            {
                FlashHelper_GetGlobalInt( iVar6, "StartOfTransitionin", ref iVar8 );
                if (iVar8 == 1)
                {
                    WAITUNWARPED( 10 );
                }
            }
        }
    }
    return;
}
