void main()
{
    if (NOT (l_U0._fU0 == 3))
    {
        l_U0._fU0 = 2;
        PRINTSTRING( "Script: LoadCity LA\n" );
        LayerCity_LoadCity( "LA" );
        WAIT( 1000 );
        PRINTSTRING( "Script: UnloadCity LA\n" );
        LayerCity_UnloadCity();
    }
    return;
}
