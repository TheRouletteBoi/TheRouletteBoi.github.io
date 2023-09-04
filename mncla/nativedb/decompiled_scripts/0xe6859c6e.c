void main()
{
    unknown uVar2;
    string sVar3;
    unknown[20] uVar4;
    unknown[20] uVar25;
    int I;
    int iVar47;
    int iVar48;
    int iVar49;
    boolean bVar50;
    boolean bVar51;
    boolean bVar52;

    uVar2._fU0 = l_U0._fU0;
    sVar3 = "CSCamera";
    array(ref uVar4, 20);
    array(ref uVar25, 20);
    for ( I = 0; I < l_U0._fU16; I++ )
    {
        iVar47 = l_U0._fU20[I]._fU20;
        if ((iVar47 < 0) || (NOT (CineScript_Characters_GetSlotToUseUnscaledCharacter( I ))))
        {
            PRINTSTRING( "Remapping the character " );
            PRINTSTRING( l_U0._fU20[I]._fU4 );
            iVar48 = 0;
            uVar4[I] = CineScript_Characters_LookupDriverToCutscenePath( l_U0._fU20[I]._fU4, iVar48 );
            uVar25[I] = CineScript_Characters_LookupDriverToCutsceneName( l_U0._fU20[I]._fU4, iVar48 );
            PRINTSTRING( "to " );
            PRINTSTRING( uVar25[I] );
            PRINTSTRING( uVar4[I] );
            PRINTSTRING( "\n" );
        }
        else
        {
            PRINTSTRING( "NOT remapping character\n" );
        }
        if ((StringCompare( uVar4[I], "" )) || (StringCompare( uVar25[I], "" )))
        {
            uVar4[I] = l_U0._fU20[I]._fU0;
            uVar25[I] = l_U0._fU20[I]._fU4;
        }
    }
    iVar49 = 1;
    bVar50 = false;
    bVar51 = CineScript_DoesCutsceneAnimPackExist();
    if (bVar51)
    {
        CineScript_StartLoadCutsceneAnimPack();
    }
    else
    {
        for ( I = 0; I < l_U0._fU16; I++ )
        {
            bVar50 = CineScript_Characters_LoadAnimationWithFace( l_U0._fU20[I]._fU8, l_U0._fU20[I]._fU12, l_U0._fU20[I]._fU16 );
            iVar49 = (iVar49) AND (bVar50);
            if (NOT bVar50)
            {
                PRINTSTRING( "Trying to load " );
                PRINTSTRING( l_U0._fU20[I]._fU12 );
                PRINTSTRING( "\n" );
            }
        }
        for ( I = 0; I < l_U0._fU504; I++ )
        {
            if ((l_U0._fU508[I]._fU8) AND (NOT l_U0._fU1288))
            {
                bVar50 = CineScript_Cars_LoadMoverAnimation( l_U0._fU508[I]._fU12, l_U0._fU508[I]._fU16 );
                iVar49 = (iVar49) AND (bVar50);
            }
            if (NOT bVar50)
            {
                PRINTSTRING( "Trying to load " );
                PRINTSTRING( l_U0._fU508[I]._fU16 );
                PRINTSTRING( "\n" );
            }
        }
        iVar49 = (iVar49) AND (CineScript_Camera_LoadAnimation( l_U0._fU4, sVar3 ));
    }
    bVar52 = false;
    while ((NOT bVar52) AND (iVar49))
    {
        bVar52 = true;
        if (bVar51)
        {
            bVar50 = CineScript_IsLoadedCutsceneAnimPack();
            bVar52 = (bVar52) AND (bVar50);
            if (NOT bVar50)
            {
                PRINTSTRING( "Trying to load Cutscene animpack " );
                PRINTSTRING( "\n" );
            }
        }
        for ( I = 0; I < l_U0._fU16; I++ )
        {
            bVar50 = CineScript_Characters_LoadType( uVar4[I], uVar25[I] );
            bVar52 = (bVar52) AND (bVar50);
            if (NOT bVar50)
            {
                PRINTSTRING( "Trying to load " );
                PRINTSTRING( uVar25[I] );
                PRINTSTRING( "\n" );
            }
        }
        if (NOT (StringCompare( l_U0._fU12, "" )))
        {
            bVar50 = CineScript_Prop_LoadSetDressing( l_U0._fU12, 1 );
            bVar52 = (bVar52) AND (bVar50);
            if (NOT bVar50)
            {
                PRINTSTRING( "CineScript_Prop_LoadSetDressing() is not done\n" );
            }
        }
        if (CineScript_Prop_IsSetDressingLoading( l_U0._fU12 ))
        {
            PRINTSTRING( "CineScript_Prop_IsSetDressingLoading is true\n" );
            bVar52 = false;
        }
        if (NOT bVar52)
        {
            WAITUNWARPED( 10 );
        }
    }
    return;
}
