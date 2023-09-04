void main()
{
    StrCopy( ref l_U0, "la", 16 );
    PRINTSTRING( "Script: LoadCity LA\n" );
    LayerCity_LoadCity( ref l_U0 );
    WAIT( 16000 );
    StartLogMemory( "t:/mc4/LeakTestFlash-pausemovie.log1", 1 );
    UIManager_LoadMovie( "PAUSEMOVIE", "pause/pause.swf", 2000, 1500, 10000, 0 );
    while ((UIManager_FindMovie( "PAUSEMOVIE" )) == nil)
    {
        WAITUNWARPED( 100 );
    }
    WAITUNWARPED( 100 );
    PRINTSTRING( "SCRIPT: Unload pause movie" );
    UIManager_UnloadMovie( "PAUSEMOVIE" );
    WAIT( 1000 );
    StopLogMemory( "t:/mc4/LeakTestFlash-pausemovie.log2", 1 );
    StartLogMemory( "t:/mc4/LeakTestFlash-garagemovie.log1", 1 );
    UIManager_StreamMovie( "GARAGEMOVIE", "garage/garage.swf", 5100, 5100, 10000, 0, 0 );
    while ((UIManager_FindMovie( "GARAGEMOVIE" )) == nil)
    {
        WAITUNWARPED( 100 );
    }
    WAITUNWARPED( 100 );
    PRINTSTRING( "SCRIPT: Unload garage movie" );
    UIManager_UnloadMovie( "GARAGEMOVIE" );
    WAIT( 1000 );
    StopLogMemory( "t:/mc4/LeakTestFlash-garagemovie.log2", 1 );
    StartLogMemory( "t:/mc4/testfinished.txt", 1 );
    StopLogMemory( "t:/mc4/testfinished.txt", 1 );
    PRINTSTRING( "Done leak log\n" );
    PRINTSTRING( "To view leaks, run:\n" );
    PRINTSTRING( "   T:\mc4\tools\code\leaklogparse.py t:\mc4\LeakTestFlash-pausemovie.log2 t:\mc4\LeakTestFlash-pausem\novie.log1 > t:\mc4\LeakTestFlash-pausemovie.log\n" );
    PRINTSTRING( "   notepad t:\mc4\LeakTestFlash-pausemovie.log\n" );
    PRINTSTRING( "   T:\mc4\tools\code\leaklogparse.py t:\mc4\LeakTestFlash-garagemovie.log2 t:\mc4\LeakTestFlash-garagem\novie.log1 > t:\mc4\LeakTestFlash-garagemovie.log\n" );
    PRINTSTRING( "   notepad t:\mc4\LeakTestFlash-garagemovie.log\n" );
    while (true)
    {
        WAIT( 1000 );
    }
    UIManager_UnloadHUD();
    UIManager_UnloadMovie( "HUDMAPMOVIE" );
    WAIT( 1000 );
    PRINTSTRING( "Script: UnloadCity LA\n" );
    LayerCity_UnloadCity();
    return;
}
