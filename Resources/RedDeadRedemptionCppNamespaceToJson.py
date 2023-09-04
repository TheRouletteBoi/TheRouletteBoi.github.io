import json

code = """
namespace SYSTEM
{
	static int TIMERA() { return invoke<int>(0x45C8C188); }
	static int TIMERB() { return invoke<int>(0x330A9C0C); }
	static void SETTIMERA(int value) { invoke<Void>(0x35785333, value); }
	static void SETTIMERB(int value) { invoke<Void>(0x27C1B7C6, value); }
	static float TIMESTEP() { return invoke<float>(0x50597EE2); }
	static float TIMESTEPUNWARPED() { return invoke<float>(0x99B02B53); }
	static void WAIT(int time) { invoke<Void>(0x7715C03B, time); }
	static void WAITUNWARPED(int time) { invoke<Void>(0x01185F9B, time); }
	static void WAITUNPAUSED(int time) { invoke<Void>(0x7C496803, time); }
	static void PRINTSTRING(const char* str) { invoke<Void>(0xECF8EB5F, str); }
	static void PRINTFLOAT(float value) { invoke<Void>(0xD48B90B6, 1, value); }
	static void PRINTFLOAT2(int num, int dec, float value) { invoke<Void>(0x3983593A, num, dec, value); }
	static void PRINTINT(int value) { invoke<Void>(0x63651F03, value); }
	static void PRINTINT2(int places, int value) { invoke<Void>(0x83B2E331, places, value); }
	static void PRINTNL() { invoke<Void>(0x868997DA, 0); }
	static void PRINTVECTOR(float x, float y, float z) { invoke<Void>(0x085F31FB, x, y, z); }
	static void BREAKPOINT() { invoke<Void>(0xEFEAFB91); }
	static float SIN(float value) { return invoke<float>(0xBF987F58, value); }
	static float COS(float value) { return invoke<float>(0x00238FE9, value); }
	static float SQRT(float value) { return invoke<float>(0x145C7701, value); }
	static float POW(float base, float power) { return invoke<float>(0x85D134F8, base, power); }
	static float EXP(float exponent) { return invoke<float>(0xE2313450, exponent); }
	static float VMAG(float x, float y, float z) { return invoke<float>(0x1FCF1ECD, x, y, z); }
	static float VMAG2(float x, float y, float z) { return invoke<float>(0xE796E629, x, y, z); }
	static float VDIST(float x0, float y0, float z0, float x1, float y1, float z1) { return invoke<float>(0x3C08ECB7, x0, y0, z0, x1, y1, z1); }
	static float VDIST2(float x0, float y0, float z0, float x1, float y1, float z1) { return invoke<float>(0xC85DEF1F, x0, y0, z0, x1, y1, z1); }
	static int SHIFT_LEFT(int value, int bitShift) { return invoke<int>(0x314CC6CD, value, bitShift); }
	static int SHIFT_RIGHT(int value, int bitShift) { return invoke<int>(0x352633CA, value, bitShift); }
	static int START_NEW_SCRIPT(char* ScriptName, int StackSize) { return invoke<int>(0x3F166D0E, ScriptName, StackSize); }
	static int START_NEW_SCRIPT_WITH_ARGS(char* ScriptName, Any* Args, int Count, int Stacksize) { return invoke<int>(0x4A2100E4, ScriptName, Args, Count, Stacksize); }
	static int FLOOR(float value) { return invoke<int>(0x32E9BE04, value); }
	static int CEIL(float value) { return invoke<int>(0xD536A1DF, value); }
	static int ROUND(float value) { return invoke<int>(0x323B0E24, value); }
	static float TO_FLOAT(int value) { return invoke<float>(0x67116627, value); }
	static void CLEAR_TEXT_LABEL(const char* Textlabel) { invoke<Void>(0xA66AAE8F, Textlabel); }
	static int GET_LATEST_CONSOLE_COMMAND() { return invoke<int>(0x2B547FE6); }
	static void RESET_LATEST_CONSOLE_COMMAND() { invoke<Void>(0xAA3EC981); }
	static int GET_CONSOLE_COMMAND_TOKEN() { return invoke<int>(0x9DE3DE24); }
	static int GET_NUM_CONSOLE_COMMAND_TOKENS() { return invoke<int>(0x608F5BC6); }
	static void Notify(int p0) { invoke<Void>(0xEE803A6E, p0); }
	static void RAND_RESET() { invoke<Void>(0xABCF1D9C); }
	static void RAND_SET_SEED(int seed) { invoke<Void>(0xC0C6245E, seed); }
	static int RAND_INT_RANGE(int min, int max) { return invoke<int>(0xF8D0D165, min, max); }
	static float RAND_FLOAT_RANGE(float min, float max) { return invoke<float>(0xCA6229BF, min, max); }
	static int RAND_INT_RANGE_DIFFERENT(int p0, int p1, int p2) { return invoke<int>(0x1D69F321, p0, p1, p2); }
	static float RAND_FLOAT_GAUSSIAN(float p0, float p1) { return invoke<float>(0x5D934CCB, p0, p1); }
	static float SubtractAngleShorter(float p0, float p1) { return invoke<float>(0x245F4332, p0, p1); }
	static float VFlatDist(Vector3* vec0, Vector3* vec1) { return invoke<float>(0xF502A252, vec0, vec1); }
	static BOOL StringCompare(char* str1, const char* str2) { return invoke<BOOL>(0xCF05DDAF, str1, str2); }
	static BOOL StringCaseCompare(char* str1, char* str2) { return invoke<BOOL>(0x12BB5DA8, str1, str2); }
	static BOOL StringCaseContains(char* str1, char* str2) { return invoke<BOOL>(0x3820B540, str1, str2); }
	static void StringCat(char* str1, char* str2) { invoke<Void>(0x20FE66C8, str1, str2); }
	static void SetPlayerControlType(int p0, int p1) { invoke<Void>(0x3F954124, p0, p1); }
	static void SetPlayerPadIndex(int p0, int p1) { invoke<Void>(0x3E64BED1, p0, p1); }
}

namespace LocalOptions
{
	static Vehicle LocalOptions_LookupVehicleProfile(char* p0) { return invoke<Vehicle>(0x470CA20A, p0); }
	static Vehicle LocalOptions_AddVehicleToPlayer(Vehicle vehicle) { return invoke<Vehicle>(0xA175BE28, vehicle); }
	static Vehicle LocalOptions_AddConfigToPlayer(Vehicle config) { return invoke<Vehicle>(0xEF54A955, config); }
	static void LocalOptions_RemoveVehicleFromPlayer(Vehicle vehicle) { invoke<Void>(0xE51CA4DB, vehicle); }
	static Vehicle LocalOptions_GetCurrentVehicleProfileIndex() { return invoke<Vehicle>(0xA3AE91DB); }
	static void LocalOptions_SetCurrentVehicleProfileIndex(Vehicle p0) { invoke<Void>(0x8C3F56C3, p0); }
	static Vehicle LocalOptions_GetVehicleProfile(int p0) { return invoke<Vehicle>(0xF53A8E33, p0); }
	static void LocalOptions_SetVehicleProfile(int p0, Vehicle p1) { invoke<Void>(0x089AAE68, p0, p1); }
	static void LocalOptions_GetShowroomProfile(int p0, Vehicle p1) { invoke<Void>(0xAB5460FA, p0, p1); }
	static Vehicle LocalOptions_GetNumValidVehicleProfiles() { return invoke<Vehicle>(0x39F02868); }
	static int LocalOptions_LookupGarageCar(char* p0) { return invoke<int>(0xCB3A9615, p0); }
	static BOOL LocalOptions_IsCheating() { return invoke<BOOL>(0x7C0C908F); }
	static int LocalOptions_SaveCollectables(int p0) { return invoke<int>(0x34CACCD6, p0); }
	static Vehicle LocalOptions_IsCollected(int p0) { return invoke<Vehicle>(0xC465EC5D, p0); }
}

namespace CarConfig
{
	static char* CarConfig_GetVehicleTypeName(int p0) { return invoke<char*>(0x2EE52E35, p0); }
}

namespace Throw
{
	static BOOL IsChildFinished(int scriptid) { return invoke<BOOL>(0x6BB1FE2B, scriptid); }
	static void ThrowRecursiveScript(int scriptid, int p0) { invoke<Void>(0x6A9979B6, scriptid, p0); }
	static void ThrowRecursive(int p0) { invoke<Void>(0xED93B5A8, p0); }
	static void SetExceptionMask(int p0) { invoke<Void>(0xB2334049, p0); }
	static void SetExceptionPassthroughMask(int p0) { invoke<Void>(0x9BC0A6D7, p0); }
	static BOOL IsExitFlagSet() { return invoke<BOOL>(0x3C61D5E2); }
	static void SetExitFlag(int scriptid) { invoke<Void>(0x9D3C5F7E, scriptid); }
	static int GetChildThread() { return invoke<int>(0xAFBFAE92); }
	static int GetNextChildThread(int scriptid) { return invoke<int>(0xCC5B5594, scriptid); }
}

namespace LayerPlayer
{
	static void LayerPlayer_LoadPlayer(Player p0, Player p1, Player p2, float p3) { invoke<Void>(0xD3A67715, p0, p1, p2, p3); }
	static void LayerPlayer_KillPlayer(int player) { invoke<Void>(0xBAA55950, player); }
	static void LayerPlayer_LoadRemotePlayer(Player p0, Player p1, Player p2, float p3, Player p4, Player p5) { invoke<Void>(0xBCA71135, p0, p1, p2, p3, p4, p5); }
}

namespace LayerCity
{
	static void LayerCity_LoadCity(int p0) { invoke<Void>(0x80636579, p0); }
	static void LayerCity_UnloadCity() { invoke<Void>(0x5C0FD146); }
}

namespace Ambients
{
	static void LayerAmbients_LoadAmbients(int p0) { invoke<Void>(0x41034270, p0); }
	static void LayerAmbients_UnloadAmbients() { invoke<Void>(0x1BA8E77B); }
}

namespace City
{
	static void City_SetFixedStreamingCam(Vector3* p0, BOOL p1, BOOL p2) { invoke<Void>(0xCDCECBE5, p0, p1, p2); }
	static void City_SetFixedStreamingCamLookat(Vector3* p0, Vector3* p1, BOOL p2, BOOL p3) { invoke<Void>(0x7F93BFCB, p0, p1, p2, p3); }
	static float City_SetMaxStreamingDistance(float p0) { return invoke<float>(0x966B46E8, p0); }
	static float City_SetMaxHilodDrawDistance(float p0) { return invoke<float>(0xDB998D2C, p0); }
	static void City_SetHighLodEnable(BOOL enable) { invoke<Void>(0x1AF28137, enable); }
	static void City_SetCrossFadeEnabled(BOOL enable) { invoke<Void>(0x1A263ADD, enable); }
	static BOOL City_DoneStreaming(float p0) { return invoke<BOOL>(0xBA101117, p0); }
	static void City_SetSnapLODFade() { invoke<Void>(0xAC6FF8C7); }
}

namespace Game
{
	static void Game_SetCamera(Vector3* p0, Vector3* p1, Camera p2, BOOL p3, Camera p4, Camera p5) { invoke<Void>(0x97656595, p0, p1, p2, p3, p4, p5); }
	static BOOL Game_IsPaused() { return invoke<BOOL>(0xE840E97F); }
	static void Game_SetLoadingDone() { invoke<Void>(0x1FA00A63); }
	static void Game_FadeLoadscreenLogo(BOOL p0) { invoke<Void>(0xBCF875D4, p0); }
	static BOOL Game_GetLoadingDone() { return invoke<BOOL>(0xDD661A76); }
	static void Game_LoadScreenShutdown() { invoke<Void>(0xEC5B6C21); }
}

namespace Control
{
	static BOOL IS_BUTTON_DOWN(int PadIndex, int Button) { return invoke<BOOL>(0xC3297B50, PadIndex, Button); }
	static BOOL IS_PAD_BUTTON_DOWN(int Index, int Button) { return invoke<BOOL>(0x8A879CE0, Index, Button); }
	static float GET_CONTROLLER_LEFTX(int PadIndex) { return invoke<float>(0x8114E64A, PadIndex); }
}

namespace Garage
{
	static void Garage_TransitionIntoRateMyRide() { invoke<Void>(0x39149253); }
	static void Garage_TransitionOutOfRateMyRide() { invoke<Void>(0x2BD79BDA); }
	static void Garage_TransitionIntoGarage() { invoke<Void>(0xC792E74F); }
	static void Garage_TransitionOutOfGarage() { invoke<Void>(0x41267557); }
	static void Garage_TransitionToTestDrive() { invoke<Void>(0x30110DEF); }
	static void Garage_TransitionOutOfTestDrive() { invoke<Void>(0x89DF63F2); }
	static void Garage_TransitionOutOfTestDriveShort() { invoke<Void>(0xD93AF389); }
	static void Garage_SetDebugPlayerRelativeCamera(int p0, Camera p1, Camera p2, Camera p3, Camera p4, Camera p5) { invoke<Void>(0xB3B0809C, p0, p1, p2, p3, p4, p5); }
	static BOOL Garage_IsTestDriving() { return invoke<BOOL>(0xD942763C); }
	static void Garage_WarpTo() { invoke<Void>(0x9DDFACE1); }
}

namespace Lookup
{
	static char* GetCurrentCity() { return invoke<char*>(0xC6FACDFF); }
	static int LookupCity(const char* p0) { return invoke<int>(0x3551249C, p0); }
	static int LookupCar(char* p0) { return invoke<int>(0x5397AD5F, p0); }
	static char* LookupCarName(char* p0) { return invoke<char*>(0x2386A437, p0); }
}

namespace CityDescription
{
	static void CityDescription_GetDefaultStartPosition(int p0, Vector3* p1, float* p2) { invoke<Void>(0xBEFE0AB1, p0, p1, p2); }
	static int CityDescription_LookupRace(int p0, char* p1) { return invoke<int>(0x728FD6C4, p0, p1); }
	static int CityDescription_LookupRaceByIndex(int p0, int p1) { return invoke<int>(0x164D4728, p0, p1); }
	static int CityDescription_FindRaceByRacerPosition(int p0, int p1, float p2) { return invoke<int>(0x14B4C564, p0, p1, p2); }
	static int CityDescription_GetRaceIndexByName(int p0, char* p1) { return invoke<int>(0x3F4D6F71, p0, p1); }
	static char* CityDescription_GetRaceNameByIndex(int p0, int p1) { return invoke<char*>(0x1F1D003C, p0, p1); }
}

namespace RaceDescription
{
	static short RaceDescription_GetNumGridPositions(Race p0) { return invoke<short>(0x01007D47, p0); }
	static void RaceDescription_GetGridPosition(Race p0, Race p1, Vector3* position, Race p2) { invoke<Void>(0xE99A12F2, p0, p1, position, p2); }
	static void RaceDescription_GetStartBeaconPosition(Race p0, Vector3* position) { invoke<Void>(0xA97D7FC8, p0, position); }
	static float RaceDescription_GetFFAOuterRadius(Race p0) { return invoke<float>(0xD0B06190, p0); }
	static float RaceDescription_GetFFAInnerRadius(Race p0) { return invoke<float>(0x417ABAEA, p0); }
	static int RaceDescription_GetTargetTime(Race p0, int p1) { return invoke<int>(0xE94407A9, p0, p1); }
	static int RaceDescription_GetTargetDamage(Race p0) { return invoke<int>(0xD704B5D5, p0); }
	static int RaceDescription_GetDefaultNumLaps(Race p0) { return invoke<int>(0xA152C7D6, p0); }
	static int RaceDescription_GetRaceType(Race p0) { return invoke<int>(0x6D37287E, p0); }
	static int RaceDescription_GetRaceSubType(Race p0) { return invoke<int>(0xAA71F501, p0); }
	static int RaceDescription_GetNumCopZones(Race p0) { return invoke<int>(0x292B4950, p0); }
	static int RaceDescription_GetRaceGridType(Race p0) { return invoke<int>(0x1791E39A, p0); }
	static char* RaceDescription_GetCarConfigName(Race p0) { return invoke<char*>(0xE2963CD8, p0); }
	static char* RaceDescription_GetEasyRaceName(Race p0) { return invoke<char*>(0x94EE2327, p0); }
	static BOOL RaceDescription_AllowRaceStarter(Race p0) { return invoke<BOOL>(0xA034792E, p0); }
	static BOOL RaceDescription_UseSafetyCam(Race p0) { return invoke<BOOL>(0x12227DD1, p0); }
}

namespace mcRace
{
	static mcArray* mcRaceArray_Create() { return invoke<mcArray*>(0x3AD82B5F); }
	static void mcRaceArray_Destroy(mcArray* array) { invoke<Void>(0xB76D9C68, array); }
	static short mcRaceArray_Fill(mcArray* array, int p0, int p1, int p2) { return invoke<short>(0xF90985A7, array, p0, p1, p2); }
	static void mcRaceArray_Reset(mcArray* array) { invoke<Void>(0x2B223F86, array); }
	static void mcRaceArray_SortByDistance(mcArray* array, Race any) { invoke<Void>(0x3A52AE53, array, any); }
	static Race mcRaceArray_FindNextRaceIndex(mcArray* array) { return invoke<Race>(0xBEC57120, array); }
	static Race mcRaceArray_FindBeatMeThereRaceIndex(mcArray* array, Race p0, Race p1, float p2) { return invoke<Race>(0x6E6D4EA2, array, p0, p1, p2); }
	static void mcRaceArray_LocalHookmanFilter(mcArray* array, Race p0, int p1) { invoke<Void>(0xB3D3BA6F, array, p0, p1); }
	static Race mcRaceArray_GetRaceIndex(mcArray* array, int index) { return invoke<Race>(0x7EF7D2C5, array, index); }
	static BOOL mcRaceArray_IsUsed(mcArray* array, int index) { return invoke<BOOL>(0xBF75EB71, array, index); }
	static void mcRaceArray_SetUsed(mcArray* array, int index, BOOL used) { invoke<Void>(0x66E6582E, array, index, used); }
	static Race mcRaceArray_GetRandomRaceIndex(mcArray* array) { return invoke<Race>(0x0D748384, array); }
	static short mcRaceArray_GetCount(mcArray* array) { return invoke<short>(0x4AEEBE02, array); }
	static void mcRaceArray_AddRace(mcArray* array, char* race, int index) { invoke<Void>(0x52216FE6, array, race, index); }
}

namespace Commands
{
	static char* GetCityCommandLine(int* p0) { return invoke<char*>(0xBF7051E6, p0); }
	static char* GetCarCommandLine(int* p0) { return invoke<char*>(0x0241D89D, p0); }
	static char* GetExtraCarCommandLine(int* p0) { return invoke<char*>(0x0E041333, p0); }
	static Byte GetNoScriptsCommandLine() { return invoke<Byte>(0xCAAEE6F8); }
	static char* GetScriptCommandLine(int* p0) { return invoke<char*>(0x81C42955, p0); }
	static char* GetRaceNameCommandLine(int* p0) { return invoke<char*>(0x4F32D9CB, p0); }
	static int GetNumOpponentCommandLine() { return invoke<int>(0x3EEFCC7B); }
	static int GetNumLapsCommandLine() { return invoke<int>(0x35F8BCAB); }
	static int GetPowerUpsCommandLine() { return invoke<int>(0xE47488D0); }
	static int GetOpponentCarCommandLine(int* p0, int p1) { return invoke<int>(0x6B93C7FE, p0, p1); }
	static int GetOpponentModValueCommandLine() { return invoke<int>(0x792652DE); }
	static int GetOpponentDifficultyCommandLine() { return invoke<int>(0xFAB49AD0); }
	static int GetOpponentDamageCommandLine() { return invoke<int>(0x9F1715B8); }
	static int GetCutsceneForcedIndex() { return invoke<int>(0x8471A570); }
	static Byte GetCopCommandLine() { return invoke<Byte>(0x31F33A06); }
	static Byte GetRaceCopChaseCommandLine(int p0) { return invoke<Byte>(0x89CDBD0D, p0); }
	static Byte GetDemoCommandLine() { return invoke<Byte>(0xA49F248D); }
	static Byte GetNetDemoCommandLine() { return invoke<Byte>(0x41C17611); }
	static int GetLayoutmodeCommandLine() { return invoke<int>(0xEAA38ECE); }
	static Byte GetNoPropCommandLine() { return invoke<Byte>(0x7C2D0BD7); }
}

namespace Memory
{
	static void StartLogMemory() { invoke<Void>(0x62FC5631); }
	static void StopLogMemory() { invoke<Void>(0x70993692); }
	static void DebugReplay() { invoke<Void>(0x87AA640D); }
}

namespace Particles
{
	static int Particles_CreateParticleEffect(int p0, Vector3* coords) { return invoke<int>(0x6886A9DA, p0, coords); }
	static void Particles_DestroyParticleEffect(int p0) { invoke<Void>(0x6204D9DA, p0); }
}

namespace mcGame
{
	static void mcGame_ThrowEvent(char* p0) { invoke<Void>(0xD4E9439E, p0); }
}

namespace GRAPHICS
{
	static void Graphics_WarpToTimeOfDay(Time p0, Time p1) { invoke<Void>(0x6C077864, p0, p1); }
	static Time Graphics_GetTimeOfDay() { return invoke<Time>(0xB78A6E5C); }
	static BOOL Graphics_GetAndSetAutoUpdateTimeOfDay(BOOL enable) { return invoke<BOOL>(0xD4E822E1, enable); }
	static void Graphics_SetShadowDisable(BOOL disable) { invoke<Void>(0xE4F67062, disable); }
	static void Graphics_SetMainShadowedRenderPass() { invoke<Void>(0x6B009476); }
	static void Graphics_ChangeRenderPassMask(BOOL p0, int p1) { invoke<Void>(0x343AD316, p0, p1); }
	static void Graphics_SetMovieRenderingMode(BOOL p0) { invoke<Void>(0x7530AE61, p0); }
	static void Graphics_PictureInPictureGrabImage(int p0) { invoke<Void>(0xAA720686, p0); }
	static void Graphics_PictureInPictureGrabImageSequence(int p0, int p1) { invoke<Void>(0x674A8840, p0, p1); }
	static void Graphics_SetCopCamera(BOOL enable) { invoke<Void>(0xD5EEDD2E, enable); }
	static void Graphics_GetCopTimeString(char* p0) { invoke<Void>(0x4BB649E0, p0); }
	static void Graphics_UseGarageLighting(BOOL garagelighting) { invoke<Void>(0x697811C7, garagelighting); }

}

namespace AUDIO_MANAGER
{
	static void AudioManager_StartLoadingMusic() { invoke<Void>(0xA22AB130); }
	static void AudioManager_StopLoadingMusic() { invoke<Void>(0xEF5B3493); }
	static void AudioManager_PlayFrontendSound(const char* sound) { invoke<Void>(0x41D3B1BC, sound); }
	static void AudioManager_EnterHangoutState(char* p0) { invoke<Void>(0x98FBFCF0, p0); }
	static void AudioManager_ExitHangoutState() { invoke<Void>(0xB29D11C7); }
	static void AudioManager_InitHangout(char* p0, char* p1, Vector3* p2) { invoke<Void>(0x934A5AE7, p0, p1, p2); }
	static void AudioManager_DestroyHangout(char* p0) { invoke<Void>(0xA56F22CF, p0); }
	static void AudioManager_SuspendHangout(char* p0, BOOL p1) { invoke <Void>(0x9C4954D6, p0, p1); }
	static void AudioManager_SetHangoutHiddenId(int id) { invoke<Void>(0x7D2032A7, id); }
	static void AudioManager_TransitionIntoGarage() { invoke<Void>(0x86E4D1CB); }
	static void AudioManager_TransitionOutOfGarage() { invoke<Void>(0xA9ED87CB); }
	static void AudioManager_SetActiveEndRace(BOOL p0, BOOL p1) { invoke<Void>(0x091E241D, p0, p1); }
	static void AudioManager_SetActiveTimeSlow(BOOL timeslow) { invoke<Void>(0x56D0EA69, timeslow); }
	static void AudioManager_SetActiveSlowMotionForm(BOOL slowmotion) { invoke<Void>(0x7EB238B4, slowmotion); }
	static void AudioManager_SetActivePreRaceRevs(BOOL preracerevs) { invoke<Void>(0xBF086F14, preracerevs); }
	static float AudioManager_GetActualTime() { return invoke<float>(0x71FA6074); }
}

namespace MC_EVENT
{
	static void mcEvent_PostEventStr(char* p0, char* value) { invoke<Void>(0xF0FB95EA, p0, value); }
	static void mcEvent_PostEventInt(char* p0, int value) { invoke<Void>(0xADEFAE9E, p0, value); }
	static void mcEvent_PostEventFloat(char* p0, float value) { invoke<Void>(0x9F6356BA, p0, value); }
	static void mcEvent_PostEventRaceResults(char* p0, int p1) { invoke<Void>(0x68501B53, p0, p1); }
	static void mcEvent_PostEventRaceAbort(char* p0, char* p1) { invoke<Void>(0x87DB783D, p0, p1); }
}

namespace PLAYER
{
	static int Player_FindObject(int player) { return invoke<int>(0xD9D4235B, player); }
	static int Player_FindRacerObject(int racer) { return invoke<int>(0xEB25C7ED, racer); }
	static int Player_GetRacer(int p0) { return invoke<int>(0xB8725894, p0); }
	static void Player_ChangeCameraInterest() { invoke<Void>(0x77D4A9E2); }
	static BOOL Player_FlashingHighbeams(int player) { return invoke<BOOL>(0xD367C998, player); }
	static BOOL Player_IsInIdleCam(int player) { return invoke<BOOL>(0xFAEB369C, player); }
}

namespace PLAYER_MANAGER
{
	static int PlayerManager_GetNumPlayers() { return invoke<int>(0xBAE3DFE4); }
	static int PlayerManager_GetNumDeadPlayers() { return invoke<int>(0x17FACF9F); }
	static BOOL PlayerManager_IsPlayerValid(int player) { return invoke<BOOL>(0x4AD49799, player); }
	static BOOL PlayerManager_IsLocalPlayer(int player) { return invoke<BOOL>(0x41661DD2, player); }
}

namespace OPPONENT
{
	static int Opponent_GetRacer(int p0) { return invoke<int>(0x0D20BDE9, p0); }
	static void Opponent_ToggleDeleteOnEviction(int p0, BOOL toggle) { invoke<Void>(0x70156C62, p0, toggle); }
	static void Opponent_ToggleResetOnEviction(int p0, BOOL toggle) { invoke<Void>(0xF8E52D93, p0, toggle); }
	static BOOL Opponent_ShouldResetOnEviction(int p0) { return invoke<BOOL>(0x27DCA603, p0); }
}

namespace OPPONENT_MANAGER
{
	static int OpponentManager_CreateOpponent() { return invoke<int>(0x14BC38C3); }
	static void OpponentManager_LoadOpponent(int p0, int p1, Vector3* p2, float p3) { invoke<Void>(0x02FFCEC8, p0, p1, p2, p3); }
	static void OpponentManager_LoadOpponentByCarConfig(int p0, int p1, Vector3* p2, float p3) { invoke<Void>(0x43CE1E7E, p0, p1, p2, p3); }
	static void OpponentManager_AddOpponentToWorld(int p0) { invoke<Void>(0x13A907DD, p0); }
	static void OpponentManager_RemoveOpponentFromWorld() { invoke<Void>(0x9A2DA567); }
	static void OpponentManager_DeleteOpponent(int p0) { invoke<Void>(0x2C4CB969, p0); }
	static int OpponentManager_FindFromUID(int p0) { return invoke<int>(0xA0A23142, p0); }
	static void OpponentManager_CleanupOpponentArray() { invoke<Void>(0x3D57C746); }
	static BOOL OpponentManager_StillStreamingOut() { return invoke<BOOL>(0xE5F00AFB); }
	static int OpponentManager_FindCharacterConfigData(int p0) { return invoke<int>(0x96A3D0E9, p0); }
	static int OpponentManager_FindRandomAvailableCharacter() { return invoke<int>(0xC790A60F); }
	static int OpponentManager_FindRandomAvailableCharacterByVehicleName(char* vehicle) { return invoke<int>(0x624115E9, vehicle); }
	static void OpponentManager_MarkCharacterAsUsed(int p0) { invoke<Void>(0x09A736B4, p0); }
	static void OpponentManager_ClearUsedCharacters() { invoke<Void>(0x441A5905); }
	static int OpponentManager_GetCharacterNameParams() { return invoke<int>(0xEB1763B7); }
	static void OpponentManager_HideOpponents() { invoke<Void>(0x9DF6791F); }
	static BOOL OpponentManager_AreDeleteRequestsClean() { return invoke<BOOL>(0xB2117CD9); }
}

namespace RUBBERBAND_MGR
{
	static void RubberBandMgr_SetupRace(int p0, BOOL p1, BOOL p2) { invoke<Void>(0xC206E1A0, p0, p1, p2); }
	static void RubberBandMgr_ShutdownRace() { invoke<Void>(0xFC0A570D); }
	static void RubberBandMgr_EnableRubberBanding(BOOL enable) { invoke<Void>(0x042A1CCA); }
	static void RubberBandMgr_SetDifficulty() { invoke<Void>(0x755B411E); }
	static void RubberBandMgr_LoadTuning() { invoke<Void>(0x7D6DB594); }
}

namespace REPLAY_MGR
{
	static void ReplayMgr_Begin(BOOL p0) { invoke<Void>(0xE8E7D2A4, p0); }
	static void ReplayMgr_End(BOOL p0) { invoke<Void>(0x807703B6, p0); }
	static void ReplayMgr_SetFinishedRace() { invoke<Void>(0x766F3747); }
	static int ReplayMgr_GetFinishedRace() { return invoke<int>(0xD8416815); }
	static int ReplayMgr_GetFinishedWatchingReplay() { return invoke<int>(0xEA2ED54F); }
}

namespace POLICE_MANAGER
{
	static int PoliceManager_CreatePolice(int p0, BOOL p1, Vector3* p2) { return invoke<int>(0x7943D761, p0, p1, p2); }
	static BOOL PoliceManager_DestroyPolice(int p0) { return invoke<BOOL>(0x186BDE76, p0); }
	static BOOL PoliceManager_DestroyAllPolice() { return invoke<BOOL>(0xF6B74454); }
	static void PoliceManager_ResetAllPolice() { invoke<Void>(0xA3B86096); }
	static int PoliceManager_FindFromUID(int p0) { return invoke<int>(0x48F0156F, p0); }
	static int PoliceManager_GetRacer(int p0) { return invoke<int>(0xAC747482, p0); }
	static int PoliceManager_GetLastPullOverPolice() { return invoke<int>(0xEECAA883); }
	static BOOL PoliceManager_IsStreamedIn(int p0) { return invoke<BOOL>(0x3AA542D1, p0); }
	static BOOL PoliceManager_IsAllStreamedIn() { return invoke<BOOL>(0x9575A604); }
	static BOOL PoliceManager_IsStreamedOut(int p0) { return invoke<BOOL>(0x0CC08D78, p0); }
	static BOOL PoliceManager_IsAllStreamedOut() { return invoke<BOOL>(0xA2A82A3B); }
	static void PoliceManager_SetAllPoliceStreamLockedIn() { invoke<Void>(0xF2B4D5DC); }
	static void PoliceManager_SetAllPoliceStreamLockedOut() { invoke<Void>(0x28616193); }
	static void PoliceManager_SetAllPoliceStreamUnlocked() { invoke<Void>(0x322ECD59); }
	static void PoliceManager_SetAllPoliceUnderground(BOOL p0, BOOL p1) { invoke<Void>(0x9DB72D19, p0, p1); }
	static void PoliceManager_SetPoliceActive(int p0, BOOL p1) { invoke<Void>(0xE6DADB0E, p0, p1); }
	static void PoliceManager_SetAllPoliceActive(BOOL p0) { invoke<Void>(0xDC6A276B, p0); }
	static void PoliceManager_SetPoliceAllowToCheckLawBreaking(int p0, BOOL p1) { invoke<Void>(0x16028FF7, p0, p1); }
	static void PoliceManager_SetAllPoliceAllowToCheckLawBreaking(BOOL p0) { invoke<Void>(0xF233516A, p0); }
	static void PoliceManager_SetPoliceAllowToPatrol(int p0, BOOL p1) { invoke<Void>(0xDD448EC8, p0, p1); }
	static void PoliceManager_SetAllPoliceAllowToPatrol(BOOL p0) { invoke<Void>(0xB13C628D, p0); }
	static void PoliceManager_SetChaseProperties(BOOL p0, BOOL p1, BOOL p2) { invoke<Void>(0xFA4C6003, p0, p1, p2); }
	static void PoliceManager_StartPursuit(int p0, int p1, BOOL p2, BOOL p3, BOOL p4) { invoke<Void>(0x99E988DC, p0, p1, p2, p3, p4); }
	static void PoliceManager_SuspectFleeing(int p0) { invoke<Void>(0x85D6B048, p0); }
	static int PoliceManager_GetTacticResult() { return invoke<int>(0x4F81A96F); }
	static int PoliceManager_GetNumCopsInLatestTactic() { return invoke<int>(0x3C9D206A); }
	static void PoliceManager_CreateCopZones(int p0) { invoke<Void>(0x354C8FDF, p0); }
	static void PoliceManager_DestroyCopZones() { invoke<Void>(0xBCD1FEAB); }
	static void PoliceManager_SetCopZone(int p0, Vector3* p1, float p2) { invoke<Void>(0x897FB801, p0, p1, p2); }
	static void PoliceManager_EvaluateCopZones() { invoke<Void>(0x010A7A4E); }
	static void PoliceManager_CurrentRaceLapChanged(int p0) { invoke<Void>(0x44C0BD57, p0); }
	static void PoliceManager_SetRaceChaseTarget(int p0, int p1) { invoke<Void>(0x8145F838, p0, p1); }
	static void PoliceManager_SetCopCamCutSceneOnScreen() { invoke<Void>(0xB68FBAAD); }
	static BOOL PoliceManager_GetCopCamCutSceneOnScreen() { return invoke<BOOL>(0x0885C8E3); }
	static void PoliceManager_SetTicketCutSceneOnScreen() { invoke<Void>(0xFB348ACB); }
	static BOOL PoliceManager_GetTicketCutSceneOnScreen() { return invoke<BOOL>(0x473487FB); }
	static void PoliceManager_SetArrestCutSceneOnScreen() { invoke<Void>(0xB6BF7950); }
	static BOOL PoliceManager_GetArrestCutSceneOnScreen() { return invoke<BOOL>(0x71463ABF); }
	static BOOL PoliceManager_PlayWipedOutBikerScene() { return invoke<BOOL>(0xFE533681); }
	static void PoliceManager_CutSceneDone() { invoke<Void>(0x4ECFB21A); }
	static void PoliceManager_PrepareAudioStreamForTicketForm(int p0) { invoke<Void>(0x7AD6CDD5, p0); }
	static void PoliceManager_PrepareAudioStreamForArrestForm(int p0) { invoke<Void>(0x7A314F57, p0); }
	static void PoliceManager_EndTacticOnPlayer(BOOL p0) { invoke<Void>(0x127E3BB2, p0); }
	static void PoliceManager_StopAllPolice(BOOL p0) { invoke<Void>(0x8BE7C808, p0); }
	static BOOL PoliceManager_IsAnyPoliceCloseToPlayer(float p0) { return invoke<BOOL>(0xBA6A46B8, p0); }
	static BOOL PoliceManager_CanAnyPoliceDetectTarget(int p0) { return invoke<BOOL>(0x5A8DAB0C, p0); }
	static BOOL PoliceManager_IsPullingRacerOver(int p0) { return invoke<BOOL>(0x95862D19, p0); }
	static BOOL PoliceManager_IsRacerPursued(int p0) { return invoke<BOOL>(0xD477052D, p0); }
	static float PoliceManager_SetPullOverFleeDelayTime() { return invoke<float>(0xCAE3DCEC); }
	static int PoliceManager_CheckPoliceActivity(BOOL p0) { return invoke<int>(0x74DC6928, p0); }
}

namespace BRAIN_FRACTORY
{
	static int BrainFactory_CreateBrainAnimated(int p0) { return invoke<int>(0x84B0649B, p0); }
	static int BrainFactory_CreateBrainRacing(int p0) { return invoke<int>(0x97A6055A, p0); }
	static int BrainFactory_CreateBrainCruising(int p0) { return invoke<int>(0x0FECCC6C); }
	static Brain BrainFactory_GetBrainAnimated(int p0) { return invoke<Brain>(0xEA9049B0, p0); }
	static Brain BrainFactory_GetBrainRacing(int p0) { return invoke<Brain>(0xE7742E45, p0); }
	static Brain BrainFactory_GetBrainCruising(int p0) { return invoke<Brain>(0x7CC515F3, p0); }
	static void BrainFactory_DeleteBrain(int p0) { invoke<Void>(0xD9B1E01C, p0); }
}

namespace BRAIN_RACING
{
	static void BrainRacing_Reset(Brain p0) { invoke<Void>(0x529B00E0, p0); }
	static void BrainRacing_AppendGoal(Brain p0, Vector3* coords, float p2) { invoke<Void>(0xF8B443CB, p0, coords, p2); }
	static void BrainRacing_SetupRace(Brain p0, int p1, int p2, int p3, int p4) { invoke<Void>(0x3D492F21, p0, p1, p2, p3, p4); }
	static void BrainRacing_SetFinalHeading(Brain p0, Vector3* p1) { invoke<Void>(0x1FA06A6A, p0, p1); }
	static void BrainRacing_SetFinalHeadingDegrees(Brain p0, float p1) { invoke<Void>(0x43F7470B, p0, p1); }
	static void BrainRacing_SetFinalSpeed(Brain p0, float p1) { invoke<Void>(0xB8A7D245, p0, p1); }
	static void BrainRacing_SetMaxSpeed(Brain p0, float p1) { invoke<Void>(0x28B625EC, p0, p1); }
	static void BrainRacing_SetAllowNitro(Brain p0, BOOL p1) { invoke<Void>(0x19983E25, p0, p1); }
	static BOOL BrainRacing_HasReachedGoal(Brain p0) { return invoke<BOOL>(0xF5D8E5DF, p0); }
	static void BrainRacing_SetDisableNitroTimer(Brain p0, float p1) { invoke<Void>(0xE35A3C83, p0, p1); }
	static void BrainRacing_SetBufferZone(Brain p0, float p1) { invoke<Void>(0xAA003DC4, p0, p1); }
	static void BrainRacing_BeginRace() { invoke<Void>(0x4BC6D8C6); }
	static void BrainRacing_RecordTime() { invoke<Void>(0xF043D110); }
	static void BrainRacing_EndRace() { invoke<Void>(0x77BCCA2E); }
	static void BrainRacing_SetRevvingEnabled(Brain p0, BOOL p1) { invoke<Void>(0xA4D1D572, p0, p1); }
	static void BrainRacing_SetRevvingHandbrake(Brain p0, BOOL p1) { invoke<Void>(0xA7BA805A, p0, p1); }
	static void BrainRacing_SetHoldStill(Brain p0, BOOL p1) { invoke<Void>(0x692808D5, p0, p1); }
	static void BrainRacing_SetLooping(Brain p0, BOOL p1) { invoke<Void>(0x1B175EFF, p0, p1); }
	static void BrainRacing_SetAvoidHandbrakeTurns(Brain p0, BOOL p1) { invoke<Void>(0xB73793AE, p0, p1); }
}

namespace BRAIN_CRUISING
{
	static void BrainCruising_DriveToNearestRail(Brain p0) { invoke<Void>(0xE3BED311, p0); }
	static void BrainCruising_AttachToNearestRail(Brain p0) { invoke<Void>(0x7F0480E9, p0); }
	static void BrainCruising_TeleportToNearestRail(Brain p0) { invoke<Void>(0x72E1824B, p0); }
	static void BrainCruising_RemoveFromTraffic(Brain p0) { invoke<Void>(0x4E29081F, p0); }
	static void BrainCruising_SetCurrentDest(Brain p0, Vector3* p1) { invoke<Void>(0x469D9FA5, p0, p1); }
	static BOOL BrainCruising_HasReachedGoal(Brain p0) { return invoke<BOOL>(0xE1E8FDFA, p0); }
	static void BrainCruising_SetOffset(Brain p0, Vector3* p1) { invoke<Void>(0xA130E68A, p0, p1); }
	static void BrainCruising_SetSpeed(Brain p0, float p1) { invoke<Void>(0xA64B719A, p0, p1); }
	static void BrainCruising_SetDestSpeed(Brain p0, float p1) { invoke<Void>(0x46A638E0, p0, p1); }
	static void BrainCruising_AppendDest(Brain p0, Vector3* p1) { invoke<Void>(0x61D662FF, p0, p1); }
	static void BrainCruising_SetLooping(Brain p0, BOOL p1) { invoke<Void>(0xBDBA5A68, p0, p1); }
	static int BrainCruising_GetCurrentDestinationIndex(Brain p0) { return invoke<int>(0x98805DE3, p0); }
	static void BrainCruising_TeleportToNextDestination(Brain p0) { invoke<Void>(0xD560ACEB, p0); }
}

namespace MC_RACER_MANAGER
{
	static BOOL mcRacerManager_AreStreamStatesResolved() { return invoke<BOOL>(0xCD033E2F); }
	static void mcRacerManager_ToggleRacerFlashedFlag(BOOL p0) { invoke<Void>(0xB4E0FDA1, p0); }
	static BOOL mcRacerManager_HasRacerBeenFlashed() { return invoke<BOOL>(0x2BD02690); }
	static int mcRacerManager_GetNumRacersAllowedForPolice() { return invoke<int>(0x74EAD905); }
}

namespace RACER
{
	static Race Racer_FindObject(int p0) { return invoke<Race>(0x04A0C3F4, p0); }
	static Race Racer_FindFromUID(int p0) { return invoke<Race>(0x0D68D93C, p0); }
	static void Racer_SetUID(Race p0, int p1) { invoke<Void>(0x78BB311B, p0, p1); }
	static int Racer_GetUID(Race p0) { return invoke<int>(0x5FE1235F, p0); }
	static char* Racer_GetName(Race p0) { return invoke<char*>(0xA737601B, p0); }
	static char* Racer_GetVehicleDriverName(Race p0) { return invoke<char*>(0x06C120F0, p0); }
	static void Racer_SetUIDAndCharacterName(Race p0, int p1, char* p2) { invoke<Void>(0x5B10D7E2, p0, p1, p2); }
	static void Racer_SetCharacterName(Race p0, char* p1) { invoke<Void>(0x43F0A63A, p0, p1); }
	static void Racer_SetVehicleDriverEnable(Race p0, BOOL p1) { invoke<Void>(0x6DCEC02E, p0, p1); }
	static void Racer_SetForceHiresTextures(Race p0, BOOL p1) { invoke<Void>(0xD846F1B1, p0, p1); }
	static BOOL Racer_IsSimStreamed(Race p0) { return invoke<BOOL>(0x8FDA4801, p0); }
	static BOOL Racer_IsCarStreamed(Race p0) { return invoke<BOOL>(0x8A458B57, p0); }
	static BOOL Racer_IsVinylStreamed(Race p0) { return invoke<BOOL>(0x2885CB9D, p0); }
	static BOOL Racer_IsMotorcycle(Race p0) { return invoke<BOOL>(0xA06DE9D4, p0); }
	static void Racer_InitializeResetPosition(int p0, short p1, Vector3* p2) { invoke<Void>(0x655713C0, p0, p1, p2); }
	static void Racer_SetResetPositionFromRecoveryMatrix(Race p0) { invoke<Void>(0x94D49FC3, p0); }
	static void Racer_Reset(Race p0) { invoke<Void>(0x7994D0E1, p0); }
	static void Racer_ResetWithDamageIntact(Race p0) { invoke<Void>(0xD3536113, p0); }
	static void Racer_Activate(Race p0) { invoke<Void>(0xA18BBE50, p0); }
	static void Racer_Deactivate(Race p0) { invoke<Void>(0x8620C197, p0); }
	static void Racer_SetCarDrivableState(Race p0, int p1) { invoke<Void>(0x2B5BDF60, p0, p1); }
	static void Racer_ZeroVelocity(Race p0) { invoke<Void>(0xF9F43B80, p0); }
	static void Racer_PreRaceBurnout(Race p0) { invoke<Void>(0x3A325D0C, p0); }
	static BOOL Racer_IsActive(Race p0) { return invoke<BOOL>(0xAD7AD071, p0); }
	static BOOL Racer_IsDriveable(Race p0) { return invoke<BOOL>(0x94A7313A, p0); }
	static BOOL Racer_IsPlayer(Race p0) { return invoke<BOOL>(0xAA9F487E, p0); }
	static BOOL Racer_IsLocalPlayer(Race p0) { return invoke<BOOL>(0x75AA6E0C, p0); }
	static BOOL Racer_IsBurningOut(Race p0) { return invoke<BOOL>(0xFDAB5601, p0); }
	static BOOL Racer_IsAccelerating(Race p0) { return invoke<BOOL>(0x6855458C, p0); }
	static float Racer_GetAngleY(Race p0) { return invoke<float>(0x78DA7F92, p0); }
	static void Racer_GetMatrixC(Race p0, Vector3* p1) { invoke<Void>(0x73A7FCA1, p0, p1); }
	static float Racer_DistanceBetween(Race p0, Vector3* p1, Vector3* p2) { return invoke<float>(0xE501512E, p0, p1, p2); }
	static float Racer_AngleBetweenInDegrees(Race p0, Vector3* p1) { return invoke<float>(0xCBBE64D2, p0, p1); }
	static BOOL Racer_CanFlashHookman(Race p0, int p1, float p2) { return invoke<BOOL>(0xE5BAD76D, p0, p1, p2); }
	static float Racer_DistanceToPoint(Race p0, Vector3* p1) { return invoke<float>(0x514EF4E3, p0, p1); }
	static void Racer_SwapCars(Race p0, int p1) { invoke<Void>(0x1552219B, p0, p1); }
	static void Racer_ApplyGameCamera(Race p0) { invoke<Void>(0x96055929, p0); }
	static void Racer_SetScrambleInputFlags(Race p0, int p1) { invoke<Void>(0xA998BB9A, p0, p1); }
	static void Racer_GetPosition(Race p0, Vector3* p1) { invoke<Void>(0xCD3F168A, p0, p1); }
	static void Racer_SetStreamingLockedIn(Race p0) { invoke<Void>(0x266DBE5B, p0); }
	static void Racer_SetStreamingLockedOut(Race p0) { invoke<Void>(0xB2B0D52A, p0); }
	static void Racer_SetStreamingUnlocked(Race p0) { invoke<Void>(0xDB89552E, p0); }
	static void Racer_SetStreamLockState(Race p0, int p1) { invoke<Void>(0xE7A66957, p0, p1); }
	static int Racer_GetStreamLockState(Race p0) { return invoke<int>(0x8C60E81A, p0); }
	static int Racer_GetLoadState(Race p0) { return invoke<int>(0x742CEE58, p0); }
	static BOOL Racer_IsBrainValid(Race p0) { return invoke<BOOL>(0xF0046272, p0); }
	static void Racer_SetModValue(Race p0, int p1) { invoke<Void>(0x3EFA6900, p0, p1); }
	static int Racer_GetModValue(Race p0) { return invoke<int>(0x09AD4E45, p0); }
	static int Racer_GetEstimatedModValue(Race p0) { return invoke<int>(0x74871C39, p0); }
	static int Racer_GetPerformanceValue(Race p0) { return invoke<int>(0x5F2FA6A0, p0); }
	static int Racer_GetCarTypeIndex(Race p0) { return invoke<int>(0xB1E8F2C1, p0); }
	static void Racer_ChangeCar(Race p0, int p1) { invoke<Void>(0x3BEB345A, p0, p1); }
	static void Racer_ChangeCarByConfig(Race p0, int p1) { invoke<Void>(0x00B4D139, p0, p1); }
	static int Racer_GetCarConfig(Race p0) { return invoke<int>(0xD008BEAC, p0); }
	static int Racer_GetRank(Race p0) { return invoke<int>(0xDCBE8FC1, p0); }
	static int Racer_GetTeam(Race p0) { return invoke<int>(0xFCF26687, p0); }
	static void Racer_ResetNitros(Race p0) { invoke<Void>(0xF97EA7DF, p0); }
	static void Racer_SetHeadlights(Race p0, BOOL p1) { invoke<Void>(0xCEFAE410, p0, p1); }
	static void Racer_SetExhaust(Race p0, BOOL p1) { invoke<Void>(0x630C4026, p0, p1); }
	static float Racer_GetDamageValue(Race p0) { return invoke<float>(0xC589B675, p0); }
	extern float Racer_GetMaxDamageValue(Race p0) { return invoke<float>(0x65B6F59C, p0); }
	static void Racer_SetDamageMultiplierFlag(Race p0, int p1) { invoke<Void>(0x9E4F1843, p0, p1); }
	static void Racer_SetDifficultyDamageFactor(Race p0, float p1) { invoke<Void>(0x181088D6, p0, p1); }
	static void Racer_SetDamageInflictedFactor(Race p0, float p1) { invoke<Void>(0xCEC166B5, p0, p1); }
	static BOOL Racer_IsDamagedOut(Race p0) { return invoke<BOOL>(0x7787636F, p0); }
	static void Racer_SetDamagePercent(Race p0, float p1) { invoke<Void>(0x48BB6340, p0, p1); }
	static BOOL Racer_CheckDamageTimer(Race p0) { return invoke<BOOL>(0x9FE8D1BD, p0); }
	static void Racer_SetInvincible(Race p0, BOOL p1) { invoke<Void>(0xA9D09A46, p0, p1); }
	static void Racer_SetDefaultSteerDirection(Race p0, float p1) { invoke<Void>(0xDE7C4E28, p0, p1); }
	static int Racer_GetCurrentDistrict(Race p0) { return invoke<int>(0xCF05CD19, p0); }
	static float Racer_GetTurboLevel(Race p0) { return invoke<float>(0xC8D52541, p0); }
	static void Racer_LockFeature(Race p0, int p1, BOOL p2) { invoke<Void>(0xAF5D85F0, p0, p1, p2); }
	static int Racer_GetVehicleClass(Race p0) { return invoke<int>(0xD4969C52, p0); }
	static void Racer_SetFatalBlow(Race p0, float p1) { invoke<Void>(0x11608E88, p0, p1); }
	static float Racer_GetFatalBlow(Race p0) { return invoke<float>(0x75394CE7, p0); }
	static float Racer_GetImpactThreshold(Race p0) { return invoke<float>(0xC3DB2357, p0); }
	static int Racer_GetPerformanceClass(Race p0) { return invoke<int>(0x99072016, p0); }
	static void Racer_EvictCar(Race p0) { invoke<Void>(0x8BC2BBA2, p0); }
	static void Racer_ReloadCar(Race p0) { invoke<Void>(0x72A1F45E, p0); }
	static int Racer_GetActiveAbility(Race p0) { return invoke<int>(0x7143C277, p0); }
	static BOOL Racer_AreHydraulicsInstalled(Race p0) { return invoke<BOOL>(0xF17A33AC, p0); }
	static BOOL Racer_IsObserverMode(Race p0) { return invoke<BOOL>(0x1E9EA205, p0); }
	static void Racer_EnterObserverMode(Race p0) { invoke<Void>(0xFA2BBA99, p0); }
	static void Racer_ExitObserverMode(Race p0) { invoke<Void>(0xC381B6FF, p0); }
	static void Racer_ScoreUpdated(Race p0, int p1) { invoke<Void>(0x830DE514, p0, p1); }
	static void Racer_PlayIgnition(Race p0) { invoke<Void>(0x22B6CC13, p0); }
	static void Racer_PlayHorn(Race p0) { invoke<Void>(0x1B41DB22, p0); }
	static void Racer_PlayGestureMild(Race p0) { invoke<Void>(0xDBC62A2C, p0); }
	static void Racer_EnableMusic(Race p0) { invoke<Void>(0x2331C19C, p0); }
	static void Racer_DisableMusic(Race p0) { invoke<Void>(0x6C254AA1, p0); }
	static float Racer_GetSpeed(Race p0) { return invoke<float>(0xEAA44071, p0); }
	static void Racer_SetPreviousRaceTime(Race p0, int p1) { invoke<Void>(0x5B99B737, p0, p1); }
	static int Racer_GetPreviousRaceTime(Race p0) { return invoke<int>(0x65543346, p0); }
	static void Racer_ChangeDriverCharacter(Race p0, int p1) { invoke<Void>(0x495B2EC0, p0, p1); }
	static void Racer_QuickFix(Race p0) { invoke<Void>(0x0930D025, p0); }
	static BOOL Racer_HasFlag(Race p0) { return invoke<BOOL>(0x90D73DD0, p0); }
	static BOOL Racer_HasBomb(Race p0) { return invoke<BOOL>(0xC3A309D9, p0); }
	static int Racer_GetImmuneTimer(Race p0) { return invoke<int>(0x422B3339, p0); }
	static void Racer_Teleport(Race p0, Vector3* p1, float p2, float p3) { invoke<Void>(0x6B16E634, p0, p1, p2, p3); }
	static void Racer_SetIconType(Race p0, int p1) { invoke<Void>(0x8340EA47, p0, p1); }
	static void Racer_SetIconColor(Race p0, FloatRGB* p1) { invoke<Void>(0x688887A1, p0, p1); }
	static void Racer_SetIconColorByDifficulty(Race p0, int p1) { invoke<Void>(0x43EE62F0, p0, p1); }
	static int Racer_SetIconColorByRacer(Race p0) { return invoke<int>(0xC1D48820, p0); }
	static void Racer_HideIcon(Race p0, BOOL p1) { invoke<Void>(0x723B6708, p0, p1); }
	static int Racer_GetIconType(Race p0) { return invoke<int>(0x0510E5EA, p0); }
}

namespace RACE_LAYOUT
{
	static RaceLayout RaceLayout_Create() { return invoke<RaceLayout>(0x2FC90D9E); }
	static void RaceLayout_Mount(RaceLayout Layout, int p1) { invoke<Void>(0x14073C53, Layout, p1); }
	static void RaceLayout_Unmount() { invoke<Void>(0x2C5F5A3D); }
	static BOOL RaceLayout_IsMounted(RaceLayout Layout) { return invoke<BOOL>(0x89F3216D, Layout); }
	static int RaceLayout_Get_CheckpointListData(RaceLayout Layout) { return invoke<int>(0x2D79C3A4, Layout); }
	static int RaceLayout_Get_NumLaps(RaceLayout Layout) { return invoke<int>(0x2D62E055, Layout); }
}

namespace FLASH_HELPER
{
	static BOOL FlashHelper_GetGlobalString(int p0, const char* global, char* value) { return invoke<BOOL>(0x1B384283, p0, global, value); }
	static BOOL FlashHelper_GetGlobalInt(int p0, const char* global, int* value) { return invoke<BOOL>(0x422DF6CB, p0, global, value); }
	static void FlashHelper_SetGlobalString(int p0, const char* global, char* value) { invoke<Void>(0x2BC78B6A, p0, global, value); }
	static void FlashHelper_SetGlobalInt(int p0, const char* global, int value) { invoke<Void>(0x65552629, p0, global, value); }
	static void FlashHelper_SetGlobalStringArray(int p0, int p1, int p2, int p3) { invoke<Void>(0xA61D2611, p0, p1, p2, p3); }
	static void FlashHelper_SetGlobalIntArray(int p0, const char* p1, int p2, int p3) { invoke<Void>(0xA48DACD5, p0, p1, p2, p3); }
	static void FlashHelper_SetMovieEnabled(int p0, BOOL p1) { invoke<Void>(0xCA47ABA6, p0, p1); }
	static void FlashHelper_SetGlobalFloat(int p0, const char* global, float value) { invoke<Void>(0x02E89308, p0, global, value); }
	static void FlashHelper_SetGlobalFloatArray(int p0, int p1, int p2, float p3) { invoke<Void>(0x2F63C485, p0, p1, p2, p3); }
}

namespace UI_MANAGER
{
	static void UIManager_LoadHUD() { invoke<Void>(0x9AC0A846); }
	static void UIManager_UnloadHUD() { invoke<Void>(0x1D12CC7A); }
	static void UIManager_LoadStates() { invoke<Void>(0x7384C4FF); }
	static int UIManager_LoadMovie(int p0, int p1, short p2, short p3, int p4, BOOL p5) { return invoke<int>(0x1627E2DB, p0, p1, p2, p3, p4, p5); }
	static int UIManager_PrependMovie(int p0, int p1, short p2, short p3, int p4, BOOL p5) { return invoke<int>(0x58D66088, p0, p1, p2, p3, p4, p5); }
	static void UIManager_UnloadMovie(int p0) { invoke<Void>(0xDC241A7A, p0); }
	static int UIManager_FindMovie(const char* Movie) { return invoke<int>(0x6CE6702A, Movie); }
	static void UIManager_StreamMovie(int p0, int p1, int p2, int p3, int p4, BOOL p5, BOOL p6) { invoke<Void>(0x35736D69, p0, p1, p2, p3, p4, p5, p6); }
	static BOOL UIManager_IsSaving() { return invoke<BOOL>(0xD14D6765); }
	static char* UIManager_GetStringBuf(int p0) { return invoke<char*>(0xF4C93E71, p0); }
	static void UIManager_AddRaceResult(int p0, int p1, int p2, int p3) { invoke<Void>(0x1855A902, p0, p1, p2, p3); }
	static void UIManager_SendEvent(const char* Event) { invoke<Void>(0x0FFFD1AE, Event); }
	static void UIManager_SendEventTo(int p0, int p1) { invoke<Void>(0x73F7E181, p0, p1); }
	static void UIManager_ReplaceDelayedEvent(int p0, float p1) { invoke<Void>(0x715F73D0, p0, p1); }
	static int UIManager_FindState(int p0) { return invoke<int>(0x37867CB2, p0); }
	static int UIManager_GetState(const char* State) { return invoke<int>(0x808BA9FA, State); }
	static void UIManager_RecycleAllSubstates(int p0) { invoke<Void>(0xB5F009B4, p0); }
	static void UIManager_AddNewRecycledSubstate(int p0, int p1) { invoke<Void>(0x4C19B123, p0, p1); }
	static void UIManager_SortSubstates(int p0, int p1, BOOL p2) { invoke<Void>(0xAFDAAF37, p0, p1, p2); }
	static void UIManager_SetStateDataString(int p0, int p1, char* value) { invoke<Void>(0x4C534259, p0, p1, value); }
	static void UIManager_SetStateDataInt(int p0, int p1, int value) { invoke<Void>(0x91184C78, p0, p1, value); }
	static void UIManager_SetStateDataFloat(int p0, int p1, float value) { invoke<Void>(0xC60ACA6C, p0, p1, value); }
	static void UIManager_FormatRaceClock(int p0, int p1) { invoke<Void>(0x5FAC81AF, p0, p1); }
	static void UIManager_QueueDisplay(const char* p0, float p1) { invoke<Void>(0xCB33B124, p0, p1); }
	static void UIManager_SetCurrentMission(int mission) { invoke<Void>(0x660F62DD, mission); }
	static BOOL UIManager_IsDisplayingMenu() { return invoke<BOOL>(0x062CE6D3); }
	static void UIManager_TransitionFrom(int p0) { invoke<Void>(0x41859829, p0); }
	static void UIManager_TransitionTo(int p0) { invoke<Void>(0x7A282C8F); }
	static int UIManager_GetRebootReason(int p0) { return invoke<int>(0x877BC3CB, p0); }
	static BOOL LoadingScreen_IsDoneLoading() { return invoke<BOOL>(0xF1DF9953); }
	static BOOL FlashNavigator_IsTransitioning() { return invoke<BOOL>(0xE7C764C0); }
}

namespace MC_UI_NAV_MAP
{
	static BOOL mcUINavMap_IsTargetSelected() { return invoke<BOOL>(0xDFEBE05E); }
	static void mcUINavMap_SetTargetByUID(int p0) { invoke<Void>(0xDEBF1602, p0); }
	static void mcUINavMap_DisableExitTransition() { invoke<Void>(0xDC112BA6); }
}

namespace MC_HUD_MAP_SERVER
{
	static Element mcHudMapServer_CreateElement() { return invoke<Element>(0xA0BDC890); }
	static Element mcHudMapServer_CreateElementEx(int p0) { return invoke<Element>(0xBE4D18F2, p0); }
	static void mcHudMapServer_DeleteElement(Element p0) { invoke<Void>(0xDEBD1103, p0); }
	static void mcHudMapServer_AddElement(Element p0) { invoke<Void>(0x38214AC5, p0); }
	static BOOL mcHudMapServer_HasElement(Element p0) { return invoke<BOOL>(0x8B52378D, p0); }
	static void mcHudMapServer_SetElement(Element p0, int p1, int p2, Vector3* p3, float p4) { invoke<Void>(0x62F65908, p0, p1, p2, p3, p4); }
	static void mcHudMapServer_SetVehicleElement(Element p0, int p1, int p2) { invoke<Void>(0xF633C35F, p0, p1, p2); }
	static void mcHudMapServer_SetRacerElement(Element p0, int p1) { invoke<Void>(0x82FF368D, p0, p1); }
	static Element mcHudMapServer_GetVehicleElement(int p0) { return invoke<Element>(0x1DD0745F, p0); }
	static void mcHudMapServer_Clear() { invoke<Void>(0x71448551); }
	static void mcHudMapServer_SetPulsate(int p0, BOOL p1) { invoke<Void>(0xD4FDC7A4, p0, p1); }
	static void mcHudMapServer_SetSubType(int p0, int p1) { invoke<Void>(0x99FBAF3A, p0, p1); }
	static void mcHudMapServer_ClearSubType(int p0, int p1) { invoke<Void>(0x0A7C189D, p0, p1); }
	static void mcHudMapServer_SetMutExSubtype(int p0, int p1) { invoke<Void>(0x2842DDB8, p0, p1); }
	static void mcHudMapServer_SetIconType(int p0, int p1) { invoke<Void>(0xF581B343, p0, p1); }
	static void mcHudMapServer_RemoveElement(Element p0) { invoke<Void>(0x588237D0, p0); }
	static void mcHudMapServer_SetSelected(int p0, BOOL p1) { invoke<Void>(0x0C990503, p0, p1); }
	static void mcHudMapServer_SetIsHideInMap(int p0, BOOL p1) { invoke<Void>(0x008AA656, p0, p1); }
	static void mcHudMapServer_SetColor(int p0, int p1, int p2, int p3, int p4) { invoke<Void>(0x84BF1DB0, p0, p1, p2, p3, p4); }
	static void mcHudMapServer_SetColorByDifficulty(int p0, int p1) { invoke<Void>(0xBEC65A64, p0, p1); }
	static void mcHudMapElement_GetPosition(Element p0, Vector3* p1) { invoke<Void>(0x1903E94F, p0, p1); }
}

namespace SPLASH_MANAGER
{
	static void SplashManager_Splash(int p0, int p1, const char* p2, float p3, BOOL p4, int p5) { invoke<Void>(0xCD526461, p0, p1, p2, p3, p4, p5); }
	static void SplashManager_SplashRaw(int p0, int p1, int p2, float p3, BOOL p4, int p5) { invoke<Void>(0x4336BA29, p0, p1, p2, p3, p4, p5); }
	static void SplashManager_SplashDynamicString(int p0, int p1, int p2, int p3, int p4, float p5, int p6) { invoke<Void>(0x0FCA6146, p0, p1, p2, p3, p4, p5, p6); }
	static void SplashManager_SplashDynamicInt(int p0, int p1, int p2, int p3, int p4, float p5, int p6) { invoke<Void>(0xC2D5326A, p0, p1, p2, p3, p4, p5, p6); }
	static void SplashManager_Cleanup() { invoke<Void>(0x544DE61E); }
	static void SplashManager_DeleteQueuedItems(int p0) { invoke<Void>(0x0078A227, p0); }
}

namespace REGISTRY
{
	static void Registry_SetValueFloat(const char* registry, float value) { invoke<Void>(0x3518B4EA, registry, value); }
	static void Registry_SetValueInt(const char* registry, int value) { invoke<Void>(0x1623E188, registry, value); }
	static void Registry_SetValueString(const char* registry, char* value) { invoke<Void>(0x3F064E6C, registry, value); }
	static void Registry_SetValueBool(const char* registry, BOOL value) { invoke<Void>(0x2CE7DA55, registry, value); }
	static void Registry_GetValueFloat(const char* registry, float* value) { invoke<Void>(0x257CF32F, registry, value); }
	static void Registry_GetValueInt(const char* registry, int* value) { invoke<Void>(0x2CA24DB0, registry, value); }
	static void Registry_GetValueString(const char* registry, char* value) { invoke<Void>(0xE79929B4, registry, value); }
	static const char* Registry_GetValueConstString(const char* registry) { return invoke<const char*>(0x7019657F, registry); }
	static BOOL Registry_GetValueBool(const char* registry) { return invoke<BOOL>(0xCE7B5628, registry); }
}

namespace HUD_CHAT
{
	static void HudChat_Display(int p0, int p1) { invoke<Void>(0xC363E8C6, p0, p1); }
}

namespace UI_LOGIC
{
	static void UILogic_SetGPSDestination(int p0, Vector3* p1) { invoke<Void>(0xDAF233DB, p0, p1); }
	static void UILogic_RemoveGPSDestination(int p0) { invoke<Void>(0x5FDAF11D, p0); }
	static int UILogic_GetNextArcadeRace() { return invoke<int>(0xFCEBF8AE); }
	static void UILogic_SetPrompt(int p0) { invoke<Void>(0xF7897E42, p0); }
	static void UILogic_GetCameraPos(int p0, Vector3* p1) { invoke<Void>(0x9A1ACA36, p0, p1); }
	static void UILogic_GetCameraLookat(int p0, Vector3* p1) { invoke<Void>(0xC6B9BC55, p0, p1); }
	static void UILogic_GetCameraFovy(int p0, float* p1) { invoke<Void>(0xFB41FF13, p0, p1); }
	static void UILogic_SetCameraControl(BOOL p0) { invoke<Void>(0xCDC9570C, p0); }
	static void UILogic_ReleaseCamera() { invoke<Void>(0xEB271031); }
	static void UILogic_SaveCarDamage() { invoke<Void>(0x3DB15288); }
	static void UILogic_RevertCarDamage() { invoke<Void>(0x709F420C); }
	static void Ctrl_SetVisible(int p0, BOOL p1) { invoke<Void>(0xBBB777BB, p0, p1); }
	static void Ctrl_SetText(int p0, char* text) { invoke<Void>(0x080DEEFD, p0, text); }
	static int Ctrl_GetChild(int p0, int p1) { return invoke<int>(0xCDF84069, p0, p1); }
	static int HUD_GetHUDCtrl(int p0) { return invoke<int>(0x6077698E, p0); }
	static int Form_GetForm(short p0) { return invoke<int>(0x07D5E024, p0); }
	static void Form_ShowForm(int p0, int p1) { invoke<Void>(0xF0E9E088, p0, p1); }
	static void Form_CloseForm(int p0) { invoke<Void>(0xB2DBB186, p0); }
	static void Form_SetText(int p0, char* text) { invoke<Void>(0xDE4F6972, p0, text); }
	static void Form_SetTextRaw(int p0, char* text) { invoke<Void>(0xB6A6A906, p0, text); }
	static int Form_GetFormResult(int p0) { return invoke<int>(0xF4096181, p0); }
	static BOOL Form_GetFormVisible(int p0) { return invoke<BOOL>(0x90925407, p0); }
	static int Form_GetTopMost() { return invoke<int>(0x7B6ADEF5); }
	static int Form_ToCtrl(int p0) { return invoke<int>(0x018CF56C, p0); }
	static void SimpleListForm_SetListText(int p0, int p1, int p2, char* text) { invoke<Void>(0xAB801023, p0, p1, p2, text); }
	static int SimpleListForm_GetSelectedIndex(int p0) { return invoke<int>(0x84104977, p0); }
	static void SimpleListForm_SetVisible(int p0, int p1, BOOL visible) { invoke<Void>(0x909931AE, p0, p1, visible); }
	static void SimpleListForm_SetEnabled(int p0, int p1, BOOL enabled) { invoke<Void>(0x85613CC4); }
	static int SimpleListForm_GetItem(int p0, int p1) { return invoke<int>(0x3EF50B4F, p0, p1); }
	static int NumericUpDownItem_GetValue(int item) { return invoke<int>(0xDEC996A8, item); }
	static int ComboBoxItem_GetSelectedIndex(int item) { return invoke<int>(0x1F39DDAB, item); }
	static void PerspectiveForm_SetCameraIndex(int p0, int p1) { invoke<Void>(0x0DFD5AF1, p0, p1); }
	static int PerspectiveForm_GetCameraIndex(int p0) { return invoke<int>(0xDD3F090A, p0); }
	static void PerspectiveForm_SetSlowMotion(int p0, float p1, float p2, BOOL p3, BOOL p4, float p5) { invoke<Void>(0x3FF4AE96, p0, p1, p2, p3, p4, p5); }
	static void PerspectiveForm_SetDescription(int p0, char* p1) { invoke<Void>(0x5A95635A, p0, p1); }
	static void PerspectiveForm_SetDescriptionRaw(int p0, char* p1) { invoke<Void>(0xED11E3B5, p0, p1); }
	static void UILogic_PreLoad() { invoke<Void>(0x689FBF47); }
	static void UILogic_PostLoad() { invoke<Void>(0xBE94D00A); }
	static void UILogic_PauseGame() { invoke<Void>(0xFE547205); }
	static void UILogic_ResumeGame() { invoke<Void>(0xC4506851); }
	static void UILogic_FullFix() { invoke<Void>(0x8BDE94FB); }
	static void MessageBox_ShowMessageBox(int box, int p1, int p2, int p3, BOOL p4) { invoke<Void>(0x524B1A52, box, p1, p2, p3, p4); }
	static BOOL MessageBox_GetMessageBoxVisible() { return invoke<BOOL>(0x060082C3); }
	static int MessageBox_GetMessageBoxResult() { return invoke<int>(0x61C1F4E9); }
	static void MessageBox_ShowLoadingBox(int p0) { invoke<Void>(0xCA303925, p0); }
	static void MessageBox_HideLoadingBox(int p0) { invoke<Void>(0x8A23118B, p0); }
	static BOOL UILogic_GetIsTelephoneChallenge() { return invoke<BOOL>(0xD9AE084F); }
	static BOOL UILogic_IsShowingDialog() { return invoke<BOOL>(0x678DC920); }
	static void PrestreamManager_UnlockAll() { invoke<Void>(0x2DEC3EF6); }
	static BOOL UILogic_IsPressed(int p0, int p1) { return invoke<BOOL>(0xEFECB62D, p0, p1); }
	static void UILogic_FireButtonPressedEvent(int p0) { invoke<Void>(0x36B31204, p0); }
	static void Warper_Warp(const char* p0) { invoke<Void>(0xBBED1C6F, p0); }
	static void Warper_WarpUsing(int p0) { invoke<Void>(0xAF99B4A4, p0); }
	static void Warper_TerminateWarp() { invoke<Void>(0x8044620F); }
	static void Warper_TransitionTo(int p0, int p1, Vector3* p2, Vector3* p3, Vector3* p4) { invoke<Void>(0x2434B2F7, p0, p1, p2, p3, p4); }
	static void Warper_SetDestinationMatrix(Vector3* p0, Vector3* p1, Vector3* p2) { invoke<Void>(0xEDAAD9A5, p0, p1, p2); }
	static BOOL Warper_IsReadyToLoadStuff() { return invoke<BOOL>(0x270581D1); }
	static BOOL Warper_IsWarping() { return invoke<BOOL>(0xF3028A03); }
	static void Warper_SetIsWarpingToCutscene(BOOL p0) { invoke<Void>(0x5506AD4C, p0); }
	static void Warper_SetPauseAtEndOfCut(BOOL p0) { invoke<Void>(0x3B7DC213, p0); }
	static void Warper_UseWarp() { invoke<Void>(0xFCA9914B); }
	static void Warper_SetIsEnterOnly(BOOL p0) { invoke<Void>(0xA99091DE, p0); }
	static void Warper_SetStoryLocationCut(BOOL p0) { invoke<Void>(0x91B02FE3, p0); }
	static void Warper_SetWarping(BOOL p0) { invoke<BOOL>(0xB2262F10, p0); }
	static void Warper_SetUseCinematicWarp(BOOL p0) { invoke<Void>(0x3747EDE2, p0); }
	static void UILogic_PauseCamera() { invoke<Void>(0xCE4936F4); }
	static void UILogic_UnPauseCamera() { invoke<Void>(0x4D2D13D5); }
	static BOOL UILogic_IsCameraPaused() { return invoke<BOOL>(0x4EA6D143); }
	static int UILogic_FindMapElementByUID(int p0) { return invoke<int>(0xE364E4E8, p0); }
	static void Warper_SetPauseCameraAtEndOfWarp() { invoke<Void>(0x761B69CA); }
	static void Navmap_GetCityCenterPoint(Vector3* p0, Vector3* p1) { invoke<Void>(0xAC7A4521, p0, p1); }
	static void Map_SetCheckpointStrobe(BOOL p0) { invoke<Void>(0x3769AC31, p0); }
	static void Map_SetMaxMinimapCheckpoints(int p0) { invoke<Void>(0x7712C7F8, p0); }
	static int Map_GetMaxMinimapCheckpoints() { return invoke<int>(0xE475DE53); }
	static void PropertyCtrl_SetPropertyBool(int p0, int p1, BOOL p2) { invoke<Void>(0xC1410682, p0, p1, p2); }
	static BOOL PropertyCtrl_GetPropertyBool(int p0, int p1) { return invoke<BOOL>(0x27000AA2, p0, p1); }
	static void PropertyCtrl_SetPropertyInt(int p0, int p1, int value) { invoke<Void>(0x403F0DEC, p0, p1, value); }
	static int PropertyCtrl_GetPropertyInt(int p0, int p1) { return invoke<int>(0x934730B4, p0, p1); }
	static void PropertyCtrl_SetPropertyFloat(int p0, int p1, float value) { invoke<Void>(0x78CB5295, p0, p1, value); }
	static float PropertyCtrl_GetPropertyFloat(int p0, int p1) { return invoke<float>(0xD59E2BA4, p0, p1); }
	static void PropertyCtrl_SetPropertyString(int p0, int p1, char* value) { invoke<Void>(0x0F1999BA, p0, p1, value); }
	static void PropertyCtrl_GetPropertyString(int p0, int p1, char* value) { invoke<Void>(0xEF5CAE78, p0, p1, value); }
	static void Sidekick_Interrupt() { invoke<Void>(0x168D5EE7); }
	static void Sidekick_Clean(BOOL clean) { invoke<Void>(0x8B9F7B5F, clean); }
	static void Sidekick_AppendData(int p0, int p1, int p2, int p3, float p4, const char* p5, int p6, const char* p7, int p8, int p9, BOOL p10, int p11, const char* p12, const char* p13) { invoke<Void>(0xBCF67199, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); }
	static void Sidekick_RemoveData(int p0) { invoke<Void>(0x898A1272, p0); }
	static BOOL Sidekick_HasDataBeenAnnounced(int p0) { return invoke<BOOL>(0xFCB87689, p0); }
	static BOOL Sidekick_IsDataBeingAnnounced() { return invoke<BOOL>(0x4293BCD7); }
	static BOOL Sidekick_IsDataDirty(int p0) { return invoke<BOOL>(0x27C5969E, p0); }
	static void Sidekick_Delay(BOOL p0) { invoke<Void>(0xDEAC4874, p0); }
	static void Sidekick_IgnoreSelect(BOOL p0) { invoke<Void>(0x1F5A1241, p0); }
	static BOOL Sidekick_IsVisible() { return invoke<BOOL>(0xF4AA0E67); }
	static int Sidekick_GetTypeCount(int p0) { return invoke<int>(0x209471E2, p0); }
	static BOOL Sidekick_SidekickIsWaitForScriptFlagSet() { return invoke<BOOL>(0xB4BCDC0E); }
	static void Sidekick_SidekickToggleWaitForScriptFlag(BOOL toggle) { invoke<Void>(0xA3C7577A, toggle); }
	static void mcMainState_EnableGpsButton(BOOL p0) { invoke<Void>(0xFD008C6B, p0); }
	static void UILogic_EnableCarInput() { invoke<Void>(0xE95C909B); }
	static void UILogic_DisableCarInput() { invoke<Void>(0x07C48A80); }
	static void UILogic_DisableCameraInput() { invoke<Void>(0x2189B23C); }
	static void UILogic_LockStreaming(Vector3* p0, Vector3* p1, Vector3* p2) { invoke<Void>(0x133829F4, p0, p1, p2); }
	static void UILogic_LockStreamingPosHeading(Vector3* p0, float p1) { invoke<Void>(0x828822E6, p0, p1); }
	static void UILogic_SetIsGPSJumping(BOOL p0) { invoke<Void>(0x1C24A910, p0); }
	static void UILogic_RestartRace() { invoke<Void>(0xC34BCEEF); }
}

namespace STRING_TABLE
{
	static void StringTable_SetString(int p0, char* value) { invoke<Void>(0x521FA0D7, p0, value); }
	static void StringTable_SetInt(int p0, int value) { invoke<Void>(0x873C5B6C, p0, value); }
	static char* StringTable_GetString(int p0) { return invoke<char*>(0x8841214B, p0); }
}

namespace PROP_MANAGER
{
	static int PropManager_InitRaceProps(int p0, int p1) { return invoke<int>(0xC968C8F1, p0, p1); }
	static void PropManager_AddRaceProp(int p0, Vector3* p1, Vector3* p2, int p3, int p4) { invoke<Void>(0x18CFDB60, p0, p1, p2, p3, p4); }
	static void PropManager_RemoveRaceProp(int p0, int p1) { invoke<Void>(0x2C17A008, p0, p1); }
	static int PropManager_CreateRaceProp(int p0, Vector3* p1, Vector3* p2, int p3, int p4) { return invoke<int>(0x86435124, p0, p1, p2, p3, p4); }
	static void PropManager_AttachRaceProp(int p0) { invoke<Void>(0x9E37633D, p0); }
	static void PropManager_DetachRaceProp(int p0) { invoke<Void>(0x7E0888A8, p0); }
	static void PropManager_SetPropPhysicsTypeFlags(int p0, int p1) { invoke<Void>(0x522AD45D, p0, p1); }
	static void PropManager_ShutdownRaceProps(int p0) { invoke<Void>(0x8DE79843, p0); }
	static int PropManager_GetFirstBrokenRaceProp(int p0) { return invoke<int>(0x4825ADF6, p0); }
	static void PropManager_ResetProps() { invoke<Void>(0xD800B2ED); }
	static void PropManager_GetRandomBreakablePropLocation(Vector3* p0) { invoke<Void>(0x166A2413, p0); }
}

namespace INGAME_EDITOR
{
	static void InGameEditor_AddCollectablePosition(Vector3* p0, int p1) { invoke<Void>(0x5ABA5E08, p0, p1); }
	static BOOL InGameEditor_InEditorMode() { return invoke<BOOL>(0x278952E1); }
}

namespace RACE
{
	static Race Race_Create() { return invoke<Race>(0xC34D74E1); }
	static void Race_Destroy(Race p0) { invoke<Void>(0x96124DE2, p0); }
	static void Race_Reset(Race p0) { invoke<Void>(0x2ED14F8B, p0); }
	static void Race_SetCurrentRace(Race p0) { invoke<Void>(0xCD825265, p0); }
	static Race Race_GetCurrentRace() { return invoke<Race>(0x0F902C89); }
	static void Race_ResetCurrentRace() { invoke<Void>(0x41C89F52); }
	static BOOL Race_HasCurrentRace() { return invoke<BOOL>(0x74574858); }
	static BOOL Race_IsTeamGame(Race p0) { return invoke<BOOL>(0xF152E899, p0); }
	static void Race_SetRaceData(Race p0, int p1) { invoke<Void>(0x3F12ED30, p0, p1); }
	static void Race_GetRaceData(Race p0, int* p1) { invoke<Void>(0x9E8B7DFE, p0, p1); }
	static int Race_GetCheckpointList(Race p0) { return invoke<int>(0xF5FFC2C9, p0); }
	static int Race_GetRaceGrid(Race p0, int p1) { return invoke<int>(0xBE61595E, p0, p1); }
	static void Race_LoadAmbientPathArray(Race p0, int p1) { invoke<Void>(0xC5D8329E, p0, p1); }
	static void Race_UnloadAmbientPathArray(Race p0) { invoke<Void>(0xE50AAB40, p0); }
	static void Race_EnableRaceTimer(Race p0, BOOL p1) { invoke<Void>(0xBA6C81F4, p0, p1); }
	static BOOL Race_IsRaceTimerEnabled(Race p0) { return invoke<BOOL>(0xF63E1D64); }
	static void Race_SetTimer(Race p0, int milliseconds) { invoke<Void>(0x66A532AB, p0, milliseconds); }
	static void Race_SetTimerSeconds(Race p0, float seconds) { invoke<Void>(0xB2D4FCFE, p0, seconds); }
	static int Race_GetTimer(Race p0) { return invoke<int>(0x3E85879D, p0); }
	static int Race_GetTimerHuman(Race p0, float p1) { return invoke<int>(0x91B0CD1C, p0, p1); }
	static int Race_GetTimerAI(Race p0, float p1) { return invoke<int>(0xF52CE714, p0, p1); }
	static void Race_SetWinningTime(Race p0, int time) { invoke<Void>(0x4C7F8A9D, p0, time); }
	static int Race_GetWinningTime(Race p0) { return invoke<int>(0x8EAD35B0, p0); }
	static int Race_GetTargetTime(Race p0) { return invoke<int>(0x6247BF91, p0); }
	static int Race_GetRaceType(Race p0) { return invoke<int>(0x96FAEA44, p0); }
	static void Race_SetTargetTime(Race p0, int time) { invoke<Void>(0xEF41FDD4, p0, time); }
	static void Race_ToggleDamagedOut(Race p0, BOOL toggle) { invoke<Void>(0x259738D6, p0, toggle); }
	static BOOL Race_IsDamagedOut(Race p0) { return invoke<BOOL>(0x1532DCDB, p0); }
	static void Race_SetTargetDamage(Race p0, int damage) { invoke<Void>(0xC7EFC56E, p0, damage); }
	static int Race_GetTargetDamage(Race p0) { return invoke<int>(0xC7EFC56E, p0); }
	static void Race_ToggleStarterCinematic(Race p0, BOOL toggle) { invoke<Void>(0x4FFBECA3, p0, toggle); }
	static BOOL Race_ShouldPlayStarterCinematic(Race p0) { return invoke<BOOL>(0x1776387F, p0); }
	static BOOL Race_IsReadyForCountdown(Race p0, float p1) { return invoke<BOOL>(0xC5563839, p0, p1); }
	static BOOL Race_IsFinished(Race p0) { return invoke<BOOL>(0x5473A591, p0); }
	static void Race_Finish(Race p0) { invoke<Void>(0x59AAC3A9, p0); }
	static BOOL Race_HasBeenArrested(Race p0) { return invoke<BOOL>(0x1F238865, p0); }
	static BOOL Race_IsInEditor() { return invoke<BOOL>(0x4608C46B); }
}

namespace CHECKPOINT
{
	static Checkpoint Checkpoint_Create() { return invoke<Checkpoint>(0x0109F710); }
	static void Checkpoint_Destroy(Checkpoint p0) { invoke<Void>(0x01734001, p0); }
	static void Checkpoint_SetPosition(Checkpoint p0, Vector3* p1) { invoke<Void>(0xFF7EA640, p0, p1); }
	static void Checkpoint_SetPositionSecond(Checkpoint p0, Vector3* p1) { invoke<Void>(0xE1BDDCC6, p0, p1); }
	static void Checkpoint_SetHeight(Checkpoint p0, float p1) { invoke<Void>(0xC97F6CB0, p0, p1); }
	static void Checkpoint_SetActivationHeight(Checkpoint p0, float p1) { invoke<Void>(0x044A0A9C, p0, p1); }
	static void Checkpoint_SetActivationRadius(Checkpoint p0, float p1) { invoke<Void>(0x4B93A458, p0, p1); }
	static void Checkpoint_SetMaxSpeed(Checkpoint p0, float p1) { invoke<Void>(0x6EAA4A67, p0, p1); }
	static void Checkpoint_IsLineCheckpoint(Checkpoint p0, BOOL p1) { invoke<Void>(0x4B57D2A0, p0, p1); }
	static void Checkpoint_SetDrawPosLine(Checkpoint p0, float p1) { invoke<Void>(0x3D6619C6, p0, p1); }
	static void Checkpoint_GetPosition(Checkpoint p0, Vector3* p1) { invoke<Void>(0x66976750, p0, p1); }
	static void Checkpoint_SetTypeFlagPickup(Checkpoint p0, int p1) { invoke<Void>(0xCEDD95D2, p0, p1); }
	static void Checkpoint_SetTypeFlagDropoff(Checkpoint p0, int p1) { invoke<Void>(0xEDF52DD4, p0, p1); }
	static void Checkpoint_SetType(Checkpoint p0, int p1, int p2) { invoke<Void>(0xFEFECB35, p0, p1, p2); }
	static BOOL Checkpoint_IsFullyOpen(Checkpoint p0, int p1) { return invoke<BOOL>(0xD802ED4E, p0, p1); }
	static void Checkpoint_SetArrowLookatPosition(Checkpoint p0, float p1, float p2) { invoke<Void>(0x5692227D, p0, p1, p2); }
}

namespace CHECKPOINT_LIST
{
	static int CheckpointList_Create() { return invoke<int>(0xA970114D); }
	static void CheckpointList_Destroy(int p0) { invoke<Void>(0x212C08E7, p0); }
	static void CheckpointManager_SetActiveCheckpointList(int p0) { invoke<Void>(0x44BD2C81, p0); }
	static void CheckpointManager_ClearActiveCheckpointList() { invoke<Void>(0x09F07E8A); }
	static void CheckpointManager_ActivateSingleCheckpoint(int p0, int p1, int p2) { invoke<Void>(0x94A86523, p0, p1, p2); }
	static void CheckpointManager_DeactivateSingleCheckpoint(int p0, int p1) { invoke<Void>(0xE054914A, p0, p1); }
	static Checkpoint CheckpointManager_GetWhichHitCheckpoint(int p0, int p1) { return invoke<Checkpoint>(0xDB98BDED, p0, p1); }
	static BOOL CheckpointManager_HasHitCheckpoint(int p0, int p1, int p2) { return invoke<BOOL>(0xFA1BF10A, p0, p1, p2); }
	static Checkpoint CheckpointManager_GetCheckpoint(int p0) { return invoke<Checkpoint>(0x764B546B, p0); }
	static Checkpoint CheckpointManager_FindClosestOpenCheckpoint(int p0, int p1, int p2) { return invoke<Checkpoint>(0xD3CAD3C4, p0, p1, p2); }
	static int CheckpointManager_CalculateRankOrdered(int p0, int p1, int p2, int p3) { return invoke<int>(0xCD262520, p0, p1, p2, p3); }
	static int CheckpointManager_CalculateRankUnordered(int p0, int p1, int p2, int p3) { return invoke<int>(0x14C1B352, p0, p1, p2, p3); }
	static void CheckpointList_ReserveList(int p0, int p1) { invoke<Void>(0x2EEFEE14, p0, p1); }
	static void CheckpointList_ResizeList(int p0, int p1) { invoke<Void>(0xFE3EC847, p0, p1); }
	static void CheckpointList_ReserveAltPaths(int p0, int p1, int p2) { invoke<Void>(0x571F4E3B, p0, p1, p2); }
	static void CheckpointList_ResizeAltPaths(int p0, int p1, int p2) { invoke<Void>(0xC471EDA4, p0, p1, p2); }
	static void CheckpointList_Reset(int p0) { invoke<Void>(0x6787F453, p0); }
	static int CheckpointList_AppendCheckpoint(int p0) { return invoke<int>(0x6B95737B, p0); }
	static void CheckpointList_DeleteCheckpoint(int p0, int p1) { invoke<Void>(0x72F35727, p0, p1); }
	static int CheckpointList_GetListCount(int p0) { return invoke<int>(0xA9667EBF, p0); }
	static Checkpoint CheckpointList_GetCheckpoint(int p0, int p1) { return invoke<int>(0x52B005AA, p0, p1); }
	static void CheckpointList_SetAltPathBeforeCheckpoint(int p0, int p1, int p2) { invoke<Void>(0xC948485E, p0, p1, p2); }
	static void CheckpointList_SetAltPathWeight(int p0, int p1, float p2) { invoke<Void>(0x13EAFB43, p0, p1, p2); }
	static void CheckpointList_SetAltPathFirstAltCheckpoint(int p0, int p1, int p2) { invoke<Void>(0x9E325F69, p0, p1, p2); }
	static void CheckpointList_SetAltPathNumAltCheckpoints(int p0, int p1, int p2) { invoke<Void>(0x1555CD90, p0, p1, p2); }
	static void CheckpointList_SetAltPathOpponentMask(int p0, int p1, int p2) { invoke<Void>(0x456F9663, p0, p1, p2); }
	static void CheckpointList_SetAltPathUseMask(int p0, int p1, BOOL p2, BOOL p3) { invoke<Void>(0x9F962D63, p0, p1, p2, p3); }
	static int CheckpointList_GetNumberOfAltPaths(int p0) { return invoke<int>(0x5555CA5D, p0); }
	static void CheckpointList_SetAltPathSkipCheckpoints(int p0, int p1, int p2) { invoke<Void>(0x7BC98615, p0, p1, p2); }
	static void CheckpointList_SetAltCPPosition(int p0, int p1, Vector3* p2) { invoke<Void>(0xE0BBDD78, p0, p1, p2); }
	static void CheckpointList_GetAltCPPosition(int p0, int p1, Vector3* p2) { invoke<Void>(0x578BA61D, p0, p1, p2); }
	static void CheckpointList_SetAltCPMaxSpeed(int p0, int p1, float p2) { invoke<Void>(0x121C3922, p0, p1, p2); }
	static float CheckpointList_GetAltCPMaxSpeed(int p0, int p1) { return invoke<float>(0x13955232, p0, p1); }
	static void CheckpointList_SetAltCPActivationRadius(int p0, int p1, float p2) { invoke<Void>(0x5108AD03, p0, p1, p2); }
	static float CheckpointList_GetAltCPActivationRadius(int p0, int p1) { return invoke<float>(0x6A4756D7, p0, p1); }
	static int CheckpointList_GetNumberOfAltCPs(int p0) { return invoke<int>(0xADEBE6DC, p0); }
}

namespace RACE_GRID
{
	static void RaceGrid_SetPosition(int p0, int p1, Vector3* p2, float p3) { invoke<Void>(0x2E41808E, p0, p1, p2, p3); }
	static void RaceGrid_GetPosition(int p0, int p1, Vector3* p2, float p3) { invoke<Void>(0x64835E73, p0, p1, p2, p3); }
}

namespace CINE_SCRIPT
{
	static void CineScript_BeginDescription() { invoke<Void>(0x762DDDD9); }
	static void CineScript_EndDescriptionAndStartClock() { invoke<Void>(0x37B31C19); }
	static void CineScript_SetSceneCoordSysBinding(int p0) { invoke<Void>(0xA427EA1B, p0); }
	static void CineScript_SetSceneReadyForGame() { invoke<Void>(0xB466DE1F); }
	static BOOL CineScript_IsGameReadyForScene() { return invoke<BOOL>(0xDFD7DB12); }
	static BOOL CineScript_IsGameReadyForReplay() { return invoke<BOOL>(0x97CBF468); }
	static BOOL CineScript_IsScenePending() { return invoke<BOOL>(0x6CECB083); }
	static BOOL CineScript_IsScenePlayingNotPending() { return invoke<BOOL>(0x4E426163); }
	static BOOL CineScript_IsScenePlaying() { return invoke<BOOL>(0x92BF7539); }
	static BOOL CineScript_IsSpeechScenarioPending() { return invoke<BOOL>(0x921DC467); }
	static BOOL CineScript_IsSpeechScenarioPrepared() { return invoke<BOOL>(0x42410C9E); }
	static void CineScript_RequestPreraceTauntScenarioAudio(int p0) { invoke<Void>(0xF69210FA, p0); }
	static void CineScript_PrepareSpeechScenarioForNextCutscene(int p0, int p1, int p2, BOOL p3) { invoke<Void>(0xBF266698, p0, p1, p2, p3); }
	static BOOL CineScript_IsEarlyOut() { return invoke<BOOL>(0xF8679EF6); }
	static float CineScript_GetSceneDuration() { return invoke<float>(0x38B6DE31); }
	static float CineScript_GetTimeToRacestart() { return invoke<float>(0x8AE0EF8C); }
	static void CineScript_KillScene() { invoke<Void>(0x97CB590F); }
	static void CineScript_FinishScene() { invoke<Void>(0x784B3018); }
	static void CineScript_SetGameCoordSysBindingCopyRacer(int p0, int p1) { invoke<Void>(0xABE6B7B9, p0, p1); }
	static void CineScript_SetGameCoordSysBinding(int p0) { invoke<Void>(0x909B42A6, p0); }
	static void CineScript_GetGameCoordSysBinding(int p0) { invoke<Void>(0x89F31167, p0); }
	static void CineScript_SetFixedFrameTime(BOOL p0) { invoke<Void>(0xF82A089F, p0); }
	static void CineScript_SetRestartTimeOffset(float p0) { invoke<Void>(0xF82A089F, p0); }
	static void CineScript_SetSceneName(char* name) { invoke<Void>(0x7ACED201, name); }
	static char* CineScript_GetSceneName() { return invoke<char*>(0xFBE4887B); }
	static void CineScript_UseRacerNativeCharacter(int p0) { invoke<Void>(0x106016B0, p0); }
	static void CineScript_PushKillBuffer(int p0, int p1) { invoke<Void>(0x1F8739BB, p0, p1); }
	static void CineScript_PopKillBuffer(int p0) { invoke<Void>(0xCC8537C1, p0); }
	static BOOL CineScript_IsSafeToKillBuffer() { return invoke<BOOL>(0x2C49E226); }
	static int CineScript_GetKillBufferCount(int p0) { return invoke<int>(0x44CF463C, p0); }
	static int CineScript_PickRacestartCutsceneFromGridEnum(int p0) { return invoke<int>(0x2C7A081B, p0); }
	static int CineScript_PickRacestartCutsceneOrTauntFromGridEnum(int p0, BOOL p1, BOOL p2, int p3) { return invoke<int>(0x3E38A896, p0, p1, p2, p3); }
	static int CineScript_PickRacestartSafetyCutscene() { return invoke<int>(0x4B5820CD); }
	static int CineScript_GetFirstRacestartCutsceneFromGridEnum(int p0) { return invoke<int>(0x799082FB, p0); }
	static BOOL CineScript_FindClosestSceneSafezone(int p0, Vector3* p1) { return invoke<BOOL>(0xD0CD4B48, p0, p1); }
	static BOOL CineScript_DoesAnimPackExist(int p0) { return invoke<BOOL>(0xC2452C46, p0); }
	static BOOL CineScript_DoesCutsceneAnimPackExist() { return invoke<BOOL>(0x78C52221); }
	static BOOL CineScript_StartLoadCutsceneAnimPack() { return invoke<BOOL>(0xB2D525D4); }
	static BOOL CineScript_StartLoadHangoutAnimPack(int p0) { return invoke<BOOL>(0xC9CEA61C, p0); }
	static int CineScript_StartLoadAuxiliaryAnimPack(int p0) { return invoke<int>(0x77AB128B, p0); }
	static BOOL CineScript_IsLoadedHangoutAnimPack() { return invoke<BOOL>(0x657B6B17); }
	static BOOL CineScript_IsLoadingHangoutAnimPack() { return invoke<BOOL>(0x8BCCB4FB); }
	static BOOL CineScript_IsLoadedAuxiliaryAnimPack() { return invoke<BOOL>(0x37056BDC); }
	static BOOL CineScript_IsLoadedCutsceneAnimPack() { return invoke<BOOL>(0x439EC6FC); }
	static void CineScript_ReleaseHangoutAnimPack() { invoke<Void>(0x90D4D1D0); }
	static void CineScript_ReleaseAuxiliaryAnimPack() { invoke<Void>(0x5BF64D3B); }
	static BOOL CineScript_Camera_LoadAnimation(int p0, int p1) { return invoke<BOOL>(0x9A7123A7, p0, p1); }
	static void CineScript_Camera_Launch(int p0, int p1) { invoke<Void>(0xA9DC08E3, p0, p1); }
	static void CineScript_Camera_LaunchEvent(int p0, int p1, float p2) { invoke<Void>(0x89CC5970, p0, p1, p2); }
	static void CineScript_Camera_LaunchEventLCS(int p0, int p1, float p2, int p3) { invoke<Void>(0x6C51C18F, p0, p1, p2, p3); }
	static void CineScript_Camera_LaunchEventTrimmed(int p0, int p1, float p2, float p3, float p4) { invoke<Void>(0xED8DADEF, p0, p1, p2, p3, p4); }
	static void CineScript_Camera_LaunchEvent_FixedCam(int p0, float p1, float p2, float p3) { invoke<Void>(0xACC1ADDC, p0, p1, p2, p3); }
	static void CineScript_Camera_Kill() { invoke<Void>(0x295BA07B); }
	static float CineScript_Camera_GetTimeRemaining() { return invoke<float>(0x68DAB300); }
	static float CineScript_Camera_GetTimeElapsed() { return invoke<float>(0x1DC10160); }
	static void CineScript_Camera_GetPosition(float p0, Vector3* p1) { invoke<Void>(0x079422D9, p0, p1); }
	static void CineScript_Camera_BypassCutsceneCameraToGameCamera() { invoke<Void>(0xC069781D); }
	static BOOL CineScript_Characters_LoadType(int p0, int p1, int p2) { return invoke<BOOL>(0x19CA0BE7, p0, p1, p2); }
	static BOOL CineScript_Characters_LoadAnimation(int p0, int p1, int p2) { return invoke<BOOL>(0xD2B27987, p0, p1, p2); }
	static BOOL CineScript_Characters_LoadAnimationWithFace(int p0, int p1, int p2) { return invoke<BOOL>(0xBC22EA21, p0, p1, p2); }
	static BOOL CineScript_Characters_LoadAnimationWithFaceXX(int p0, int p1, int p2) { return invoke<BOOL>(0x18D24E2C, p0, p1, p2); }
	static BOOL CineScript_Characters_LaunchAnimAt(int p0, int p1, int p2) { return invoke<BOOL>(0x8255134E, p0, p1, p2); }
	static int CineScript_Characters_LaunchAnimWithFaceAt(int p0, int p1, int p2, int p3, int p4, int p5) { return invoke<int>(0x8FEE4B3A, p0, p1, p2, p3, p4, p5); }
	static int CineScript_Characters_LaunchAnimWithFaceAtXX(int p0, int p1, int p2, int p3, int p4, int p5, int p6) { return invoke<int>(0x2D9FD5D8, p0, p1, p2, p3, p4, p5, p6); }
	static int CineScript_Characters_LaunchAnimAtLCS(int p0, int p1, int p2, int p3, int p4, int p5) { return invoke<int>(0xBADC594D, p0, p1, p2, p3, p4, p5); }
	static int CineScript_Characters_LaunchAnimEvent(int p0, int p1, int p2, int p3, float p4, int p5) { return invoke<int>(0xD481DC82, p0, p1, p2, p3, p4, p5); }
	static int CineScript_Characters_LaunchAnimEventLCS(int p0, int p1, int p2, int p3, float p4, int p5, int p6) { return invoke<int>(0xF17CB59A, p0, p1, p2, p3, p4, p5, p6); }
	static int CineScript_Characters_LaunchAnimEventWithFace(int p0, int p1, int p2, int p3, int p4, float p5, int p6) { return invoke<int>(0xE63E8A1C, p0, p1, p2, p3, p4, p5, p6); }
	static int CineScript_Characters_LaunchAnimEventWithFaceLCS(int p0, int p1, int p2, int p3, int p4, float p5, int p6, int p7) { return invoke<int>(0xB48004B4, p0, p1, p2, p3, p4, p5, p6, p7); }
	static float CineScript_Characters_GetTimeRemainingForId(int p0) { return invoke<float>(0x1F9DF08E, p0); }
	static BOOL CineScript_Characters_ReAnimateId(int p0, int p1, int p2, int p3) { return invoke<BOOL>(0x29FF5B3D, p0, p1, p2, p3); }
	static BOOL CineScript_Characters_ReAnimateSlot(int p0, int p1, int p2, int p3) { return invoke<BOOL>(0x68F42E7F, p0, p1, p2, p3); }
	static void CineScript_Characters_RegisterDriverMappings(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12) { invoke<Void>(0xD2C0F1BA, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12); }
	static void CineScript_Characters_RegisterDriverMappings2(int p0, int p1, int p2, int p3, int p4) { invoke<Void>(0x632BE7CD, p0, p1, p2, p3, p4); }
	static void CineScript_Characters_AssignBoyToSlot(int p0) { invoke<Void>(0x58FBE44C, p0); }
	static void CineScript_Characters_AssignGirlToSlot(int p0) { invoke<Void>(0x973F4286, p0); }
	static void CineScript_Characters_AssignCopToSlot(int p0) { invoke<Void>(0x506F59FF, p0); }
	static void CineScript_Characters_AssignNameToSlot(int p0, int p1) { invoke<Void>(0x7F91CA51, p0, p1); }
	static void CineScript_Characters_SetSlotToUseUnscaledCharacter(int p0) { invoke<Void>(0x82D31A1C, p0); }
	static int CineScript_Characters_ReadSlotPath(int p0) { return invoke<int>(0x77FADCCA, p0); }
	static int CineScript_Characters_ReadSlotName(int p0) { return invoke<int>(0xD98FBE61, p0); }
	static int CineScript_Characters_GetSlotToUseUnscaledCharacter(int p0) { return invoke<int>(0x4950CEBB, p0); }
	static int CineScript_Characters_LookupDriverToCutscenePath(int p0, int p1) { return invoke<int>(0x89CE4DD0, p0, p1); }
	static int CineScript_Characters_LookupDriverToCutsceneName(int p0, BOOL p1) { return invoke<int>(0x91BAC7C1, p0, p1); }
	static BOOL CineScript_IsCinematicLighting() { return invoke<BOOL>(0x3374CAD2); }
	static int CineScript_SetForceCutsceneLighting(BOOL p0) { return invoke<int>(0xC9B452AC, p0); }
	static void CineScript_SetRaceStarterLighting(BOOL p0) { invoke<Void>(0xA5B20AC7, p0); }
	static BOOL CineScript_Prop_LoadSetDressing(const char* p0, BOOL p1) { return invoke<BOOL>(0xA3442E17, p0, p1); }
	static void CineScript_Prop_UnloadSetDressing() { invoke<Void>(0xE8FAA038); }
	static BOOL CineScript_Prop_IsSetDressingLoading() { return invoke<BOOL>(0x2CB6FBDA); }
	static BOOL CineScript_Cars_RegisterRacer(int p0, int p1) { return invoke<BOOL>(0xB5EFAB8A, p0, p1); }
	static BOOL CineScript_Cars_LoadMoverAnimation(int p0, int p1) { return invoke<BOOL>(0x1AC7146A, p0, p1); }
	static int CineScript_Cars_LaunchEvent(int p0, int p1, int p2, float p3) { return invoke<int>(0xB57B561C, p0, p1, p2, p3); }
	static int CineScript_Cars_LaunchLCS(int p0, int p1) { return invoke<int>(0x9F341954, p0, p1); }
	static int CineScript_Cars_LaunchGameDriven(int p0) { return invoke<int>(0xC5D23FFB, p0); }
	static BOOL CineScript_Cars_RollDriversWindowDown(int p0) { return invoke<BOOL>(0x3FF14150, p0); }
	static BOOL CineScript_Cars_RollDriversWindowUp(int p0) { return invoke<BOOL>(0xB9C72716, p0); }
	static BOOL CineScript_Cars_PlayGestureRight(int p0) { return invoke<BOOL>(0xCEE960FC, p0); }
	static BOOL CineScript_Cars_PlayGestureLeft(int p0) { return invoke<BOOL>(0x2B9D4671, p0); }
	static BOOL CineScript_Cars_PlayGestureNeutral(int p0) { return invoke<BOOL>(0x170CFB29, p0); }
	static BOOL CineScript_Cars_GetCoordSysBinding(int p0, int p1) { return invoke<BOOL>(0x3AC2DDA9, p0, p1); }
	static int CineScript_Cars_GetCoordSysBindingFromRacer(int p0, int p1) { return invoke<int>(0x1EF1F318, p0, p1); }
	static void CineScript_Cars_AssignIdToSlot(int p0, int p1) { invoke<Void>(0xA2420834, p0, p1); }
	static int CineScript_Cars_ReadSlotId(int p0) { return invoke<int>(0xB20E4981, p0); }
	static int CineScript_Cars_GenerateId() { return invoke<int>(0xC3C751F6); }
	static void CineScript_Events_LaunchEvent(int p0, float p1, float p2, float p3) { invoke<Void>(0xE45BD560, p0, p1, p2, p3); }
	static void CineScript_Events_LaunchEventOnRacerName(int p0, int p1, float p2, float p3, float p4) { invoke<Void>(0xDD206A38, p0, p1, p2, p3, p4); }
	static void CineScript_Events_LaunchEventOnRacerSlot(int p0, int p1, float p2, float p3, float p4) { invoke<Void>(0x63BAAD58, p0, p1, p2, p3, p4); }
	static BOOL CineScript_Audio_PrepareStream(int p0) { return invoke<BOOL>(0xF09CA253, p0); }
	static BOOL CineScript_Audio_PrepareStreamSecondary(int p0) { return invoke<BOOL>(0xFFFFB9E1, p0); }
	static BOOL CineScript_Audio_IsStreamPrepared() { return invoke<BOOL>(0x789FA5FF); }
	static BOOL CineScript_Audio_PlayStream() { return invoke<BOOL>(0x9086C110); }
	static BOOL CineScript_Audio_PlayStreamSecondary() { return invoke<BOOL>(0x7C2E2E55); }
	static void CineScript_Audio_StopStreamPrimary() { invoke<Void>(0xA24A0671); }
	static void CineScript_Audio_StopStreamSecondary() { invoke<Void>(0x95878DBE); }
	static void CineScript_SKIPPING_CUTSCENE() { invoke<Void>(0x90837EAD); }
	static void CineScript_HiThere() { invoke<Void>(0xA7255C8F); }
	static BOOL CineScript_Special_GetPlayerCoordSysBinding(int p0) { return invoke<BOOL>(0xDECF6ADB, p0); }
	static BOOL CineScript_Special_GetPlayerCoordSysBindingBaked(int p0) { return invoke<BOOL>(0xDF41A519, p0); }
	static BOOL CineScript_Special_NoHangoutPeds() { return invoke<BOOL>(0xBEDC082B); }
	static void CineScript_GetCoordSysBindingTEST(int p0) { invoke<Void>(0x5A7D2CFD, p0); }
	static void CineScript_SetCoordSysBindingTEST(int p0) { invoke<Void>(0xD6011584, p0); }
	static int CineScript_Next() { return invoke<int>(0xC4EB3F2A); }
	static BOOL GetNoCutscenesCommandLine() { return invoke<BOOL>(0x4F2C931C); }
}

namespace MC_CAREER
{
	static void mcCareer_RegisterHookmanCharacterSet(int p0, int p1, int p2) { invoke<Void>(0x2DFADB6E, p0, p1, p2); }
	static int mcCareer_GetHookmanCharacterSet(char* p0) { return invoke<int>(0x46F1F010, p0); }
	static int mcCareer_GetHookmanFlashId(int p0) { return invoke<int>(0x736D9D16, p0); }
	static int mcCareer_FindAvailableHookman() { return invoke<int>(0x34DF8F82); }
	static int mcCareer_FindHookman(int p0) { return invoke<int>(0x3A49C9D1, p0); }
	static int mcCareer_GetHookman(short p0) { return invoke<int>(0x4137B827, p0); }
	static int mcCareer_StartNewScript(const char* script, int stackSize) { return invoke<int>(0x3406912F, script, stackSize); }
	static int mcCareer_StartNewScript_SC(const char* script, int stackSize) { return invoke<int>(0xBB7BD7DE, script, stackSize); }
	static BOOL GetNoCareerCommandLine() { return invoke<BOOL>(0xFAEA8A85); }
	static int GetMissionCommandLine(int p0) { return invoke<int>(0x8B797758, p0); }
	static BOOL GetNoTutorialCommandLine() { return invoke<BOOL>(0xACCB493E); }
	static BOOL GetUnlockCareerCommandLine() { return invoke<BOOL>(0xCAB07F0D); }
	static BOOL mcCareer_ShouldAutoWin() { return invoke<BOOL>(0xC87AFF65); }
	static void mcCareer_SendEvent(int p0) { invoke<Void>(0xB599500E); }
	static int mcCareer_GetLocationId(int p0) { return invoke<int>(0x237A2277, p0); }
	static int mcCareer_GetDescriptionId(int p0) { return invoke<int>(0x82330C21, p0); }
	static void mcCareer_RegisterLocation(int p0, int p1, int p2, int p3) { invoke<Void>(0x25112B15, p0, p1, p2, p3); }
	static int mcCareer_GetNumPinkSlipProfiles(int p0) { return invoke<int>(0x3C8F083D, p0); }
	static int mcCareer_GetPinkSlipProfile(int p0, int p1) { return invoke<int>(0x67C9B37D, p0, p1); }
	static int mcCareer_AddPinkSlipProfile(int p0, int p1, int p2) { return invoke<int>(0x4CB76FFF, p0, p1, p2); }
	static int mcCareer_LoadPinkSlipProfile(short p0, const char* p1, int p2) { return invoke<int>(0x98B74626, p0, p1, p2); }
	static void mcCareer_RemovePinkSlipProfile(int p0, int p1) { invoke<Void>(0xC36BFCFE, p0, p1); }
	static int mcCareer_GetPinkSlipProfileType(int p0, int p1) { return invoke<int>(0xBD89B254, p0, p1); }
	static int mcCareer_GetPinkSlipUID(int p0, int p1) { return invoke<int>(0xECA0538D, p0, p1); }
	static int mcCareer_GetPinkSlipProfileName(int p0, int p1) { return invoke<int>(0xD332F35F, p0, p1); }
	static void mcCareer_TogglePinkslipHangoutDirty(short p0, BOOL p1) { invoke<BOOL>(0xC64056A8, p0, p1); }
	static int mcCareer_IsPinkslipHangoutDirty(int p0) { return invoke<int>(0xD8A97F8E); }
	static void mcCareer_SetAltHookmanVisibility(short p0, BOOL p1) { invoke<Void>(0x0EF9EDA4, p0, p1); }
	static BOOL mcCareer_GetAltHookmanVisibility(int p0) { return invoke<BOOL>(0xDB222A67, p0); }
	static void mcCareer_SetTournamentWinStatus(int p0, BOOL p1) { invoke<Void>(0x25890558, p0, p1); }
	static void mcCareer_SetTimeTrialWinStatus(int p0, BOOL p1) { invoke<Void>(0x010B794C, p0, p1); }
	static int mcCareer_GetTimeTrialTargetTime(int p0, int p1) { return invoke<int>(0x10AE9E50, p0, p1); }
	static void mcCareer_SetTimeTrialTargetTime(int p0, int p1, int p2, int p3) { invoke<Void>(0x3588D099, p0, p1, p2, p3); }
	static void mcCareer_EvaluateCurrentTargetTime(int p0, int p1, int p2) { invoke<Void>(0x7CF472D4, p0, p1, p2); }
	static void mcCareer_UnlockAbilities() { invoke<Void>(0xE1830E71); }
	static void mcCareer_UnlockRace(Race p0) { invoke<Void>(0x33B856AD); }
	static void mcCareer_UnlockDistrictRaces(int p0, int p1, int p2) { invoke<Void>(0xE2C08CFF, p0, p1, p2); }
	static BOOL mcCareer_IsRaceUnlocked(Race p0) { return invoke<BOOL>(0x74C1EE8A, p0); }
	static BOOL mcCareer_IsTimeTrialUnlocked() { return invoke<BOOL>(0x37B9A1C0); }
	static void mcCareer_UnlockTimeTrial(int p0) { invoke<Void>(0x3586850A, p0); }
	static BOOL mcCareer_IsPoliceUnlocked() { return invoke<BOOL>(0xDC81D0DE); }
	static void mcCareer_UnlockPolice() { invoke<Void>(0xB981B850); }
	static void mcCareer_AddRaceToHistory(Race p0) { invoke<Void>(0x9ADC4D88, p0); }
	static int mcCareer_GetDifficultyPlayerVsRacer(int p0) { return invoke<int>(0x6E1A42DC, p0); }
	static BOOL mcCareer_IsInGasStation() { return invoke<BOOL>(0xC621F68B); }
	static BOOL mcCareer_ActivateGasMenu() { return invoke<BOOL>(0xFFA03F46); }
	static int mcCareer_GetGasStationIDX() { return invoke<int>(0x57AAC86C); }
	static void mcCareer_SetIsInGasStation(BOOL p0) { invoke<Void>(0x06D5D1D8, p0); }
	static void mcCareer_RefillOneNitro() { invoke<Void>(0x9F7D6F40); }
	static int mcCareer_GetCurrentHeapSize() { return invoke<int>(0x71FDD716); }
}

namespace MC_MISSION_MANAGER
{
	static int mcMissionManager_GetMission(const char* mission) { return invoke<int>(0x8749413D, mission); }
	static void mcMissionManager_SetReminderCountdown(Time time) { invoke<Void>(0xB7654460, time); }
	static BOOL mcMissionManager_DoesUIDHaveActiveMission(int p0) { return invoke<BOOL>(0x129A322A, p0); }
	static int mcMissionManager_GetNumMissions(int p0) { return invoke<int>(0xD8666110, p0); }
}

namespace MC_MISSION
{
	static int mcMission_GetState(int p0) { return invoke<int>(0x27E05040); }
	static void mcMission_ChangeState(int p0, int p1, BOOL p2) { invoke<Void>(0x55A29F88, p0, p1, p2); }
	static void mcMission_Ready(int p0, BOOL p1) { invoke<Void>(0x94BA5802, p0, p1); }
	static void mcMission_Start(int p0, BOOL p1) { invoke<Void>(0xB1C6C6C0, p0, p1); }
	static void mcMission_Reset(int p0) { invoke<Void>(0xDAE9E852, p0); }
	static void mcMission_Hide(int p0, BOOL p1) { invoke<Void>(0x4FC3BE2E, p0, p1); }
	static int mcMission_GetPrerequisite(int p0, int p1) { return invoke<int>(0x81828939, p0, p1); }
	static int mcMission_GetObjective(int p0, int p1) { return invoke<int>(0xF039CFD3, p0, p1); }
	static int mcMission_GetDistrict(int p0) { return invoke<int>(0x8A373379, p0); }
	static int mcMission_GetHookmanNameId(int p0) { return invoke<int>(0x90C12AF0, p0); }
	static void mcMission_SetHookmanNameId(int p0, int p1) { invoke<Void>(0x46D12085, p0, p1); }
	static int mcMission_GetId(int p0) { return invoke<int>(0x50C94969, p0); }
}

namespace MC_REQUIREMENT
{
	static void mcRequirement_Satisfy(int p0, BOOL p1) { invoke<Void>(0x4321892C, p0, p1); }
	static void mcRequirement_SetTarget(int p0, int p1) { invoke<Void>(0x2915F5DD, p0, p1); }
	static void mcRequirement_AlwaysHide(int p0, BOOL p1) { invoke<Void>(0xBCC8E17B, p0, p1); }
	static BOOL mcRequirement_IsSatisfied(int p0) { return invoke<BOOL>(0x18B6B313, p0); }
	static int mcRequirement_GetTargetId(int p0) { return invoke<int>(0x24642234, p0); }
	static void mcRequirement_Hide(int p0, BOOL p1) { invoke<Void>(0x9FDE5F5C, p0, p1); }
	static BOOL mcRequirement_IsHidden(int p0) { return invoke<BOOL>(0x0ABE579B, p0); }
}

namespace MC_HOOKMAN
{
	static int mcHookman_SetMission(int p0, const char* p1) { return invoke<int>(0x18637AE4, p0, p1); }
	static int mcHookman_GetMission(int p0) { return invoke<int>(0xA8AC1FDE, p0); }
	static void mcHookman_SetState(int p0, int p1) { invoke<Void>(0x94B73374, p0, p1); }
	static int mcHookman_GetState(int p0) { return invoke<int>(0x21414112, p0); }
	static BOOL mcHookman_IsHidden(int p0) { return invoke<BOOL>(0x5FC99170, p0); }
	static void mcHookman_Hide(int p0, BOOL p1) { invoke<Void>(0xC11C59C8, p0, p1); }
	static void mcHookman_SetName(int p0, char* p1) { invoke<Void>(0xA52805D1, p0, p1); }
	static char* mcHookman_GetName(int p0) { return invoke<char*>(0xFE3A6533, p0); }
	static void mcHookman_SetType(int p0, int p1) { invoke<Void>(0x3B3FA380, p0, p1); }
	static int mcHookman_GetType(int p0) { return invoke<int>(0xDF43EA7F, p0); }
	static void mcHookman_SetDifficulty(int p0, int p1) { invoke<Void>(0x95CACD8B, p0, p1); }
	static int mcHookman_GetDifficulty(int p0) { return invoke<int>(0x4B192B51, p0); }
	static void mcHookman_SetId(int p0, int p1) { invoke<Void>(0x9A1FE2BE, p0, p1); }
	static int mcHookman_GetId(int p0) { return invoke<int>(0x51DD212F, p0); }
	static void mcHookman_SetCarConfigName(int p0, char* p1) { invoke<Void>(0x918C1ED8, p0, p1); }
	static char* mcHookman_GetCarConfigName(int p0) { return invoke<char*>(0x0F2BA242, p0); }
	static void mcHookman_SetModValue(int p0, int p1) { invoke<Void>(0xF7AF4246, p0, p1); }
	static int mcHookman_GetModValue(int p0) { return invoke<int>(0x1CE8F0BE, p0); }
	static char* mcHookman_GetCoreScriptName(int p0) { return invoke<char*>(0x5A781F71, p0); }
	static void mcHookman_Reset(int p0) { invoke<Void>(0x5236FF49, p0); }
	static void mcHookman_SetDistrict(int p0, int p1) { invoke<Void>(0x062E157C, p0, p1); }
	static int mcHookman_GetDistrict(int p0) { return invoke<int>(0x53A9E436, p0); }
}

namespace MC_TARGET_MANAGER
{
	static void mcTargetManager_RegisterPlayer(int p0, int p1) { invoke<Void>(0x0F1A717E, p0, p1); }
	static void mcTargetManager_RegisterRacer(int p0, Race p1) { invoke<Void>(0xFF38CC7C, p0, p1); }
	static void mcTargetManager_RegisterLocation(int p0, Vector3* p1) { invoke<Void>(0xA290243E, p0, p1); }
	static void mcTargetManager_UnRegisterTarget(int p0) { invoke<Void>(0x915A75B6, p0); }
	static void mcTargetManager_HideTarget(int p0, BOOL p1) { invoke<Void>(0x06AFA778, p0, p1); }
	static BOOL mcTargetManager_IsTargetHidden(int p0) { return invoke<BOOL>(0x68E32794, p0); }
	static void mcTargetManager_ToggleMapVisibiliy(int p0, BOOL p1) { invoke<Void>(0x88E1FEA0, p0, p1); }
}

namespace MC_SLOT_SYSTEM
{
	static void mcSlotSystem_HideDistrict(int p0, BOOL p1) { invoke<Void>(0xF0E997EE, p0, p1); }
	static void mcSlotSystem_UnlockDistrict(int p0, BOOL p1) { invoke<Void>(0xF0D91284, p0, p1); }
	static void mcSlotSystem_UnlockSlot(int p0) { invoke<Void>(0xF96CE78A, p0); }
	static void mcSlotSystem_ClearAllDistricts() { invoke<Void>(0xB9ABBAFF); }
	static BOOL mcSlotSystem_AreDistrictsClean() { return invoke<BOOL>(0xEF53A815); }
	static void mcSlotSystem_EvaluateAllDistricts() { invoke<Void>(0x9938FC1B); }
	static int mcSlotSystem_RequestSlot(int p0, const char* p1, int p2, int p3, const char* p4, int p5, BOOL p6, const char* p7) { return invoke<int>(0x7B6080CC, p0, p1, p2, p3, p4, p5, p6, p7); }
	static void mcSlotSystem_RequestSlotRemoval(int p0, BOOL p1) { invoke<Void>(0x017C8913, p0, p1); }
	static int mcSlotSystem_FindRandomAvailableCharacter(int p0) { return invoke<int>(0x867B0685, p0); }
	static int mcSlotSystem_FindCharacterConfigData(int p0, int p1) { return invoke<int>(0xF409483E, p0, p1); }
	static void mcSlotSystem_ToggleCharacterUsed(int p0, int p1, BOOL p2) { invoke<Void>(0x63804A1B, p0, p1, p2); }
	static BOOL mcSlotSystem_IsCharacterUsed(int p0, int p1) { return invoke<BOOL>(0x6A02F12E, p0, p1); }
	static BOOL mcSlotSystem_IsDistrictLocked(int p0) { return invoke<BOOL>(0x5BD54C7D, p0); }
}

namespace MC_EXPERIENCE_MANAGER
{
	static int mcExperienceManager_LookupSystem(int p0) { return invoke<int>(0xA6B9371B, p0); }
	static int mcExperienceManager_LookupSystemIndex(int p0) { return invoke<int>(0x136B6203, p0); }
	static int mcExperienceManager_LookupSystemByName(char* p0) { return invoke<int>(0x540B8DB4, p0); }
	static int mcExperienceManager_LookupLabelSystemByName(char* p0) { return invoke<int>(0xB1186EFE, p0); }
	static int mcExperienceManager_GetMoney() { return invoke<int>(0x657FEE6B); }
	static float mcExperienceManager_CalculateRaceMoney(int p0, int p1, int p2) { return invoke<float>(0xB43A0024, p0, p1, p2); }
	static void mcExperienceManager_AddMoney(float p0) { invoke<Void>(0x46B24E25, p0); }
	static void mcExperienceManager_SpendMoney(int p0) { invoke<Void>(0x53A24E58, p0); }
	static BOOL mcExperienceManager_CanSpendMoney(int p0) { return invoke<BOOL>(0xBD7456DE, p0); }
}

namespace MC_REWARD_MANAGER
{
	static int mcRewardManager_BuildRewardExperience(int p0, int p1, BOOL p2, BOOL p3) { return invoke<int>(0x491FB15D, p0, p1, p2, p3); }
	static int mcRewardManager_BuildRewardPart(int p0, BOOL p1, BOOL p2) { return invoke<int>(0x15944D40, p0, p1, p2); }
	static int mcRewardManager_BuildRewardPartUnlock(int p0, BOOL p1, BOOL p2) { return invoke<int>(0xCEFA74CB, p0, p1, p2); }
	static int mcRewardManager_BuildRewardPartLevel(int p0, BOOL p1, BOOL p2) { return invoke<int>(0xD2606B44, p0, p1, p2); }
	static int mcRewardManager_BuildRewardCarA(int p0, BOOL p1, BOOL p2) { return invoke<int>(0xEE52211D, p0, p1, p2); }
	static int mcRewardManager_BuildRewardCarB(int p0, int p1, BOOL p2, BOOL p3) { return invoke<int>(0x3F8BC39F, p0, p1, p2, p3); }
	static int mcRewardManager_BuildRewardMoney(int p0, BOOL p1, BOOL p2) { return invoke<int>(0xCD86BCE6, p0, p1, p2); }
	static int mcRewardManager_BuildRewardAchievement(int p0, BOOL p1, BOOL p2) { return invoke<int>(0x938CEC46, p0, p1, p2); }
	static int mcRewardManager_BuildRewardMission(int p0, int p1, BOOL p2, BOOL p3, BOOL p4) { return invoke<int>(0x0B724E0E, p0, p1, p2, p3, p4); }
	static int mcRewardManager_BuildRewardScript(int p0, BOOL p1, BOOL p2) { return invoke<int>(0x630F09C6, p0, p1, p2); }
	static int mcRewardManager_BuildRewardAbilityLevel(int p0, int p1, BOOL p2, BOOL p3) { return invoke<int>(0xD17EB886, p0, p1, p2, p3); }
	static int mcRewardManager_BuildRewardPerformanceevel(int p0, BOOL p1, BOOL p2) { return invoke<int>(0xDFD05C77, p0, p1, p2); }
	static int mcRewardManager_BuildRewardDynamicExperience(int p0, BOOL p1, BOOL p2) { return invoke<int>(0x9791D6B7, p0, p1, p2); }
	static int mcRewardManager_BuildRewardDynamicMoney(int p0, BOOL p1, BOOL p2) { return invoke<int>(0xDD0F2F29, p0, p1, p2); }
	static int mcRewardManager_BuildRewardUserInterface(int p0, int p1, BOOL p2, BOOL p3) { return invoke<int>(0x84D8527A, p0, p1, p2, p3); }
	static void mcRewardManager_DeleteReward(int p0) { invoke<Void>(0xEE6AF630, p0); }
	static void mcRewardManager_AddReward() { invoke<Void>(0xDC250C81); }
}

namespace MC_MATH
{
	static void Math_ScalarPrint() { invoke<Void>(0x69B13CAA); }
	static Math Math_Cosine(float value) { return invoke<Math>(0xBA8477A6, value); }
	static Math Math_Sine(float value) { return invoke<Math>(0x725D2623, value); }
	static Math Math_Tangent(float value) { return invoke<Math>(0xEB7AB92D, value); }
	static Math Math_ArcCosine(float value) { return invoke<Math>(0xE8C28E89, value); }
	static Math Math_ArcSine(float value) { return invoke<Math>(0x273ED3B8, value); }
	static Math Math_ArcTangent(float x, float y) { return invoke<Math>(0xD0E67BF5, x, y); }
	static void Math_VectorPrint(Vector3* p0) { invoke<Void>(0x814644B4, p0); }
	static void Math_VecRotateX(Vector3* out, Vector3* in, Math rotate) { invoke<Void>(0xA69EC965, out, in, rotate); }
	static void Math_VecRotateY(Vector3* out, Vector3* in, Math rotate) { invoke<Void>(0x9D45B6B3, out, in, rotate); }
	static void Math_VecRotateZ(Vector3* out, Vector3* in, Math rotate) { invoke<Void>(0x8B181258, out, in, rotate); }
	static Math Math_VecDot(Vector3* p0, Vector3* p1) { return invoke<Math>(0x2B912BB9, p0, p1); }
}

namespace NET
{
	static BOOL Net_RaceRequested(Race p0) { return invoke<BOOL>(0x5C230DFE, p0); }
	static void Net_ClearRaceRequest() { invoke<Void>(0xF7F74D04); }
	static int Net_NumRacers() { return invoke<int>(0xC631348B); }
	static int Net_GetRacerGridIndex(int p0) { return invoke<int>(0xC5A01467, p0); }
	static int Net_GetRacerTeamColor(int p0) { return invoke<int>(0xBA4A7E06, p0); }
	static int Net_GetHostDataAsInt(int p0) { return invoke<int>(0x87ABC916, p0); }
	static BOOL Net_IsHostDataFieldValid(int p0) { return invoke<BOOL>(0x38F460E7, p0); }
	static void Net_ClearRaceResults() { invoke<Void>(0x4E9927F5); }
	static void Net_SetRaceFinishTime(Race p0, int p1) { invoke<Void>(0x0CBE003F, p0, p1); }
	static BOOL Net_GetRaceFinishTime(Race p0, int* p1) { return invoke<BOOL>(0x8060CB28, p0, p1); }
	static void Net_SetRacerTimeout(int p0) { invoke<Void>(0x57833507, p0); }
	static void Net_SetRacerDisconnect(int p0) { invoke<Void>(0xA6B3B748, p0); }
	static void Net_SetRacerFinished(int p0) { invoke<Void>(0xA2E7F44F, p0); }
	static void Net_SetRacerEliminated(int p0) { invoke<Void>(0x8FD7020E, p0); }
	static void Net_LockRacerList() { invoke<Void>(0xB2BBE345); }
	static void Net_UnlockRacerList() { invoke<Void>(0x3206FED6); }
	static int Net_GetRacerFromList(int p0) { return invoke<int>(0x11CBD4E9, p0); }
	static BOOL Net_IsLocalPlayerInRace() { return invoke<BOOL>(0x310D3D7C); }
	static void Net_StartSession() { invoke<Void>(0x110D5704); }
	static BOOL Net_IsSessionStarted() { return invoke<BOOL>(0x22F6F462); }
	static BOOL Net_IsRaceFinished() { return invoke<BOOL>(0xE6595659); }
	static void Net_WriteStats(int p0) { invoke<Void>(0x6F6FE35B, p0); }
	static BOOL Net_EveryoneDoneWritingStats() { return invoke<BOOL>(0xFD258F46); }
	static BOOL Net_IsPostRaceDone() { return invoke<BOOL>(0xF08D2AE9); }
	static void Net_PostRaceCleanup() { invoke<Void>(0x895FA0BF); }
	static void Net_EndSession() { invoke<Void>(0x30AB74AA); }
	static BOOL Net_IsPlayerActiveParticipant(Player player) { return invoke<BOOL>(0xDBD2A62F, player); }
	static BOOL Net_IsDeadGamer(int p0) { return invoke<BOOL>(0xFC7FDD41, p0); }
	static void Net_EditorRaceCreateCheckpoints(int p0) { invoke<Void>(0xD539C0D1, p0); }
	static void Net_EditorPopulateGrid(int p0, int p1) { invoke<Void>(0x8BC77204, p0, p1); }
	static int Net_GetLapCount() { return invoke<int>(0x1E3C9586); }
	static void Net_MovePlayerToLobby(Player player) { invoke<Void>(0xA26DC9C5, player); }
	static void Net_MovePlayerToCar(Player player) { invoke<Void>(0x57A55FB5, player); }
	static int Net_GetParticipantCount() { return invoke<int>(0xF2504071); }
	static BOOL Net_IsArbiterLocal() { return invoke<BOOL>(0x1CCB9020); }
	static BOOL Net_IsHost() { return invoke<BOOL>(0x7B9352C6); }
	static void Net_SetRacerToEliminate(Race racer) { invoke<Void>(0x9508F27E, racer); }
	static int Net_GetRacerToEliminate() { return invoke<int>(0xBBD7904E); }
	static void Net_SendRacerToEliminate(Race racer) { invoke<Void>(0xE97A8FE9, racer); }
	static int Net_CreateOptions() { return invoke<int>(0xF0668A4D); }
	static void Net_SetEliminationTimer(int p0) { invoke<Void>(0xB37F3A90, p0); }
	static int Net_GetEliminationTimer() { return invoke<int>(0xBB539410); }
	static void Net_SendEliminationTimer(int p0) { invoke<Void>(0x137B191F, p0); }
	static void Net_DestroyOptions(int p0) { invoke<Void>(0x6EA4AA74, p0); }
	static BOOL Net_IsNetworked() { return invoke<BOOL>(0xC3026B07); }
	static int Net_GetJoinWishPad() { return invoke<int>(0x196742B2); }
	static float Net_GetSyncedTime() { return invoke<float>(0x1C58AE3B); }
	static int Net_GetSyncedTimeInMs() { return invoke<int>(0x7C6C6FFF); }
	static BOOL Net_IsCruiseMode() { return invoke<BOOL>(0x0100F7A9); }
	static BOOL Net_IsRankedMode() { return invoke<BOOL>(0xB0AF24BA); }
	static BOOL Net_IsPlayerDisconnected(Player player) { return invoke<BOOL>(0xE167E622, player); }
	static BOOL Net_IsPlayerInvalid(Player player) { return invoke<BOOL>(0x60503225, player); }
	static BOOL Net_IsConnecting() { return invoke<BOOL>(0xBB2D589F); }
	static int Net_GetRaceLayout() { return invoke<int>(0x154D1065); }
	static void Net_ResetLocalPlayer() { invoke<Void>(0x14B9D78D); }
	static int Net_GetAchievementSetupStatus() { return invoke<int>(0xA32BA6B3); }
	static void Net_EnableSearchQos() { invoke<Void>(0xD5A73611); }
}

namespace AMBIENT_MGR
{
	static void AmbientMgr_DisableTraffic(BOOL p0) { invoke<Void>(0x0143A508, p0); }
	static BOOL AmbientMgr_GetTrafficEnable() { return invoke<BOOL>(0x6A66371D); }
	static void AmbientMgr_SetTrafficEnable(BOOL p0) { invoke<Void>(0xB3BD31FA, p0); }
	static BOOL AmbientMgr_GetPedsEnable() { return invoke<BOOL>(0xE175E3A4); }
	static void AmbientMgr_SetPedsEnable(BOOL p0) { invoke<Void>(0x7FE22E0B, p0); }
	static BOOL AmbientMgr_GetHangoutMode() { return invoke<BOOL>(0x29840371); }
	static void AmbientMgr_SetHangoutMode(BOOL p0) { invoke<Void>(0x96287338, p0); }
	static BOOL AmbientMgr_GetParkedCarsEnable() { return invoke<BOOL>(0x1239F67F); }
	static void AmbientMgr_SetParkedCarsEnable(BOOL p0) { invoke<Void>(0xF8629CEC, p0); }
	static int AmbientMgr_AddAmbientToLayout(int p0, Vector3* p1) { return invoke<int>(0x13D17C41, p0, p1); }
	static int AmbientMgr_AddRandomCarToLayout(int p0, Vector3* p1) { return invoke<int>(0x776DC4DB, p0, p1); }
	static int AmbientMgr_AddRandomPedToLayout(Vector3* p0) { return invoke<int>(0xFCC71C0B, p0); }
	static void AmbientMgr_RemoveAmbientFromLayout(int p0) { invoke<Void>(0xCAA4D55D, p0); }
	static void AmbientMgr_SetRoadDensity(Vector3* p0, int p1) { invoke<Void>(0xDBC08179, p0, p1); }
	static void AmbientMgr_Reset() { invoke<Void>(0x2705AD85); }
	static void AmbientMgr_FullReset() { invoke<Void>(0x1C2391D3); }
	static BOOL AmbientMgr_GetCutscene() { return invoke<BOOL>(0xA082458F); }
	static void AmbientMgr_SetCutscene(BOOL p0) { invoke<Void>(0x3C3F3F55, p0); }
	static BOOL AmbientMgr_GetFrontEnd() { return invoke<BOOL>(0x16EE6EBD); }
	static void AmbientMgr_SetFrontEnd(BOOL p0, float p1, float p2, float p3, float p4, int p5) { invoke<Void>(0x93560E67, p0, p1, p2, p3, p4, p5); }
}

namespace VHSM_STATE
{
	static void vhsmState_EmptyDynamicList(int p0) { invoke<Void>(0xE31DD038, p0); }
	static int vhsmState_EnableDynamicChild(int p0) { return invoke<int>(0x2D845F3B, p0); }
	static int vhsmState_GetChild(int p0, int p1) { return invoke<int>(0xF4FCDE28, p0, p1); }
	static void vhsmState_SetText(int p0, char* p1) { invoke<Void>(0xFFFBA7CB, p0, p1); }
	static void vhsmState_SetDataString(int p0, char* p1) { invoke<Void>(0x53B76E50, p0, p1); }
	static void vhsmState_SetDataInt(int p0, int p1) { invoke<Void>(0x9B0B7AA7, p0, p1); }
	static int vhsmState_GetDataInt(int p0) { return invoke<int>(0x4701AF01, p0); }
	static void vhsmState_Enable(int p0) { invoke<Void>(0x3156CD4E, p0); }
	static void vhsmState_Disable(int p0) { invoke<Void>(0x38098770, p0); }
	static void vhsmState_Activate(int p0) { invoke<Void>(0xDD0FA802, p0); }
	static BOOL vhsmState_IsListener(int p0) { return invoke<BOOL>(0x982D1E30, p0); }
	static BOOL vhsmState_IsActive(int p0) { return invoke<BOOL>(0x625DD7F0, p0); }
}

namespace TRIGGER_MANAGER
{
	static int TriggerManager_CreateTriggerArray(int p0) { return invoke<int>(0x60614755, p0); }
	static void TriggerManager_DestroyTriggerArray(int p0) { invoke<Void>(0x7B6BF854, p0); }
	static void TriggerManager_ResetTriggers() { invoke<Void>(0x696DF8EB); }
	static void TriggerManager_RacerLapChanged(int p0, int p1) { invoke<Void>(0xEB9D3E2C, p0, p1); }
}

namespace PICKUP_MANAGER
{
	static int PickUpManager_CreatePowerUpSourcesFromCheckPoints(int p0, BOOL p1) { return invoke<int>(0x50D89111, p0, p1); }
	static int PickUpManager_CreatePowerUpSources(int p0) { return invoke<int>(0x8A115016, p0); }
	static void PickUpManager_AddPowerUpSource(int p0, Vector3* p1, float p2, Vector3* p3) { invoke<Void>(0x5023685E, p0, p1, p2, p3); }
	static void PickUpManager_DeletePowerUpSources(int p0) { invoke<Void>(0x8D51A26C, p0); }
	static void PickUpManager_PowerUpSourcePostInit(int p0) { invoke<Void>(0xAABCF596, p0); }
	static void PickUpManager_OnRaceReset() { invoke<Void>(0x139EB525); }
}

namespace MC_CAR_ARRAY
{
	static void mcCarArrayData_EvaluateModValue(int p0, int p1, int p2) { invoke<Void>(0xECF601CD, p0, p1, p2); }
	static int mcCarArrayData_GetModValue(int p0) { return invoke<int>(0x5BB01691, p0); }
	static char* mcCarArrayData_GetName(int p0) { return invoke<char*>(0xEAA4B56C, p0); }
	static int mcCarArray_Create() { return invoke<int>(0xB511CC2F); }
	static void mcCarArray_Destroy(int p0) { invoke<Void>(0x6222E298, p0); }
	static int mcCarArray_GetCount(int p0) { return invoke<int>(0x4D915505, p0); }
	static int mcCarArray_Fill(int p0, int p1, int p2, int p3, int p4, int p5) { return invoke<int>(0x97912DB8, p0, p1, p2, p3, p4, p5); }
	static int mcCarArray_GetCarArrayData(int p0, int p1) { return invoke<int>(0x8B356C99, p0, p1); }
	static int mcCarArray_GetRandomCarArrayData(int p0) { return invoke<int>(0x84992148, p0); }
}

namespace MC_CONFIG
{
	static int mcCharacterConfigData_GetCarConfigData(int p0, int p1, int p2, short p3, BOOL p4) { return invoke<int>(0x4A2DB2C4, p0, p1, p2, p3, p4); }
	static int mcCharacterConfigData_GetCarConfigDataByVehicleName(int p0, int p1, int p2, int p3, int p4, BOOL p5) { return invoke<int>(0x4722A153, p0, p1, p2, p3, p4, p5); }
	static char* mcCharacterConfigData_GetName(int p0) { return invoke<char*>(0xB0CA5B76, p0); }
	static char* mcConfigData_GetName(int p0) { return invoke<char*>(0x646B1F45, p0); }
	static int mcCarConfigData_GetRandomConfigData(int p0) { return invoke<int>(0x192BC504, p0); }
	static int mcCarConfigData_GetModValue(int p0) { return invoke<int>(0xCE3F62AB, p0); }
	static int mcCarConfig_Create(int p0) { return invoke<int>(0x0D62BD74, p0); }
	static int mcCarConfig_Destroy(int p0) { return invoke<int>(0x024FCFDA, p0); }
	static BOOL mcCarConfig_Load(int p0, int p1) { return invoke<BOOL>(0x44C54C42, p0, p1); }
	static void mcCarConfig_Copy(int p0, int p1) { invoke<Void>(0xCE953D0E, p0, p1); }
	static char* mcCarConfig_GetVehicleTypeName(int p0) { return invoke<char*>(0x2B55BE3D, p0); }
	static char* mcCarConfig_GetVehicleProfileName(int p0) { return invoke<char*>(0x15907902, p0); }
}

namespace CTF
{
	static int Ctf_Create(int p0) { return invoke<int>(0x0C34001B, p0); }
	static void Ctf_Destroy(int p0) { invoke<Void>(0x3DFC12D5, p0); }
	static void Ctf_Reset(int p0) { invoke<Void>(0xF775DB8E, p0); }
	static int Ctf_GetCurrentCtf() { return invoke<int>(0xB58DB76D); }
	static void Ctf_SetCurrentCtf(int p0) { invoke<Void>(0xEADEF69E, p0); }
	static int Ctf_GetMap(int p0) { return invoke<int>(0xAC3800E7, p0); }
	static Race Ctf_GetRace(int p0) { return invoke<Race>(0xB28160B7, p0); }
	static int Ctf_ActivateDrop(int p0, int p1, int p2) { return invoke<int>(0x8FFEF12F, p0, p1, p2); }
	static void Ctf_ActivateDropInRange(int p0, int p1, int p2) { invoke<Void>(0xB1F0058D, p0, p1, p2); }
	static void Ctf_AttemptPickupFlag(int p0, int p1) { invoke<Void>(0x0A14D282, p0, p1); }
	static void Ctf_AttemptResetFlagToSpawnPosition(int p0, int p1) { invoke<Void>(0xC8D7A423, p0, p1); }
	static void Ctf_AttemptReturnFlags(int p0, int p1) { invoke<Void>(0xFDFE493B, p0, p1); }
	static void Ctf_DeactivateDrop(int p0, int p1) { invoke<Void>(0x1F792D5C, p0, p1); }
	static int Ctf_GetDropColor(int p0, int p1) { return invoke<int>(0xB8E75927, p0, p1); }
	static void Ctf_GetDropPosition(int p0, int p1, Vector3* p2) { invoke<Void>(0xDCEDC2A7, p0, p1, p2); }
	static int Ctf_GetFlagColor(int p0, int p1) { return invoke<int>(0x50DEC025, p0, p1); }
	static int Ctf_GetFlagDroppedElapsedTimeMs(int p0, int p1) { return invoke<int>(0xB723CD94, p0, p1); }
	static void Ctf_GetFlagPosition(int p0, int p1, Vector3* p2) { invoke<Void>(0xF45479B5, p0, p1, p2); }
	static int Ctf_GetFlagHolder(int p0, int p1) { return invoke<int>(0xADE96693, p0, p1); }
	static int Ctf_GetMaxActiveFlags() { return invoke<int>(0x8BAFE992); }
	static int Ctf_GetMaxActiveDrops() { return invoke<int>(0xF2441210); }
	static int Ctf_GetNearestActiveDropIndex(int p0, int p1, int p2) { return invoke<int>(0x24D5749E, p0, p1, p2); }
	static int Ctf_GetNearestActiveFlagIndex(int p0, int p1, int p2) { return invoke<int>(0x63C649AC, p0, p1, p2); }
	static int Ctf_GetRacerHeldFlagIndex(int p0, int p1, int p2) { return invoke<int>(0x124A0421, p0, p1, p2); }
	static BOOL Ctf_HasHitDrop(int p0, int p1, int p2) { return invoke<BOOL>(0x2929F7EA, p0, p1, p2); }
	static BOOL Ctf_HasHitFlag(int p0, int p1, int p2) { return invoke<BOOL>(0x6644DB31, p0, p1, p2); }
	static BOOL Ctf_IsDropActive(int p0, int p1) { return invoke<BOOL>(0x927FAE23, p0, p1); }
	static BOOL Ctf_IsFlagActive(int p0, int p1) { return invoke<BOOL>(0x0D57ACD8, p0, p1); }
	static BOOL Ctf_IsFlagAtHomePosition(int p0, int p1) { return invoke<BOOL>(0x390A7D54, p0, p1); }
	static int Ctf_GetFlagHomeBaseDropIndex(int p0, int p1, int p2) { return invoke<int>(0xA741C06C, p0, p1, p2); }
	static int Ctf_SpawnFlag(int p0, int p1, int p2, int p3, int p4) { return invoke<int>(0xD85F3B3A, p0, p1, p2, p3, p4); }
	static int Ctf_SpawnFlagInRange(int p0, int p1, Vector3* p2, float p3, float p4, int p5, int p6, int p7) { return invoke<int>(0x633A8EC4, p0, p1, p2, p3, p4, p5, p6, p7); }
	static int Ctf_GetTeamScore(int p0, int p1) { return invoke<int>(0x68F4B4E8, p0, p1); }
	static void Ctf_SetFlagHeldTime(int p0) { invoke<Void>(0x4907C9D5, p0); }
	static int Ctf_GetFlagHeldTime(int p0) { return invoke<int>(0x7ED4269F, p0); }
	static void Ctf_AddFlagHeldTime(int p0) { invoke<Void>(0x23219059, p0); }
	static void Ctf_SetFlagPickUpTime(int p0) { invoke<Void>(0x381E34A6, p0); }
	static int Ctf_GetFlagPickUpTime(int p0) { return invoke<int>(0xE9ACC0E2, p0); }
	static int Ctf_GetDropIcon(int p0, int p1) { return invoke<int>(0xF42D4654, p0, p1); }
	static int Ctf_GetFlagIcon(int p0, int p1) { return invoke<int>(0x887977DF, p0, p1); }
	static void Ctf_ClearEvents(int p0) { invoke<Void>(0xF36A5B79, p0); }
	static BOOL Ctf_PopEvent(int p0, int p1) { return invoke<BOOL>(0x38D5A2CB, p0, p1); }
}

namespace MOVIE_PLAYER
{
	static int MoviePlayer_StartMovie(int p0) { return invoke<int>(0x6333A245, p0); }
	static void MoviePlayer_StopMovie() { invoke<Void>(0x03C1ADB2); }
	static BOOL MoviePlayer_IsMoviePlaying() { return invoke<int>(0x787B4C41); }
	static void MoviePlayer_SetTintColor(FloatRGBA p0) { invoke<Void>(0xEE18D78C, p0); }
}

namespace RN_ROAD_AMBIENT
{
	static void RnRoadAmbient_SetGlobalRoadDensity(int p0) { invoke<Void>(0x54E5C23B, p0); }
	static int RnRoadAmbient_GetGlobalRoadDensity() { return invoke<int>(0xBE3BFD8A); }
}

namespace RN_INTERSECTION_AMBIENT
{
	static BOOL RnIntersectionAmbient_GetRedLightRace() { return invoke<BOOL>(0x9DF02389); }
	static void RnIntersectionAmbient_SetRedLightRace(BOOL p0) { invoke<Void>(0x1F66D168, p0); }
	static void RnIntersectionAmbient_SetIntersectionRed(Vector3* p0) { invoke<Void>(0x490FFA5D, p0); }
	static void RnIntersectionAmbient_SetIntersectionGreen(Vector3* p0, Vector3* p1) { invoke<Void>(0xE59CF4B9, p0, p1); }
}

namespace EVENT_OPTIONS
{
	static void EventOptions_DestroyOptions(int p0) { invoke<Void>(0x13DC6A4F, p0); }
	static BOOL EventOptions_IsNitro(int p0) { return invoke<BOOL>(0xBE6B6E40, p0); }
	static BOOL EventOptions_IsIce(int p0) { return invoke<BOOL>(0xB06C2C8E, p0); }
	static BOOL EventOptions_IsReverse(int p0) { return invoke<BOOL>(0x55B6B557, p0); }
	static BOOL EventOptions_IsStealth(int p0) { return invoke<BOOL>(0x0C023BC2, p0); }
	static BOOL EventOptions_IsDisrupter(int p0) { return invoke<BOOL>(0xE6465755, p0); }
	static BOOL EventOptions_IsShield(int p0) { return invoke<BOOL>(0x4355C8A0, p0); }
	static BOOL EventOptions_IsStop(int p0) { return invoke<BOOL>(0x20E2E4FC, p0); }
	static BOOL EventOptions_IsPulse(int p0) { return invoke<BOOL>(0xFEBD8291, p0); }
	static BOOL EventOptions_IsMirror(int p0) { return invoke<BOOL>(0xDAF58548, p0); }
	static BOOL EventOptions_IsAgro(int p0) { return invoke<BOOL>(0xBCF0C01C, p0); }
	static int EventOptions_GetFlagLimit(int p0) { return invoke<int>(0xA0995285, p0); }
	static int EventOptions_GetTimeLimit(int p0) { return invoke<int>(0x407E92D3, p0); }
	static BOOL EventOptions_IsHeavyFlag(int p0) { return invoke<BOOL>(0xC3D1AC69, p0); }
	static BOOL EventOptions_IsFlagTransfer(int p0) { return invoke<BOOL>(0xFE479026, p0); }
	static BOOL EventOptions_IsLastManOut(int p0) { return invoke<BOOL>(0x05E26F91, p0); }
	static BOOL EventOptions_IsPowerUps(int p0) { return invoke<BOOL>(0x0E237674, p0); }
	static int EventOptions_GetTrafficLevel(int p0) { return invoke<int>(0x2D70348D, p0); }
}

namespace MC_RACE_SCRIPT
{
	static void mcRaceScriptParam_Clear(int p0) { invoke<Void>(0x584BB29E, p0); }
	static int mcRaceScriptData_GetRandomOpponent(int p0) { return invoke<int>(0x99CB0904, p0); }
}

namespace STATS_MANAGER
{
	static int StatsManager_GetIntValue(const char* p0, int p1) { return invoke<int>(0x7D123878, p0, p1); }
	static float StatsManager_GetFloatValue(int p0, int p1) { return invoke<float>(0x765736A4, p0, p1); }
	static BOOL StatsManager_IsStatPresent(int p0, int p1) { return invoke<BOOL>(0x4368BE3E, p0, p1); }
	static void StatsManager_UpdateStatInt(const char* p0, int p1, int p2, int p3) { invoke<Void>(0xFCAF1F84, p0, p1, p2, p3); }
	static void StatsManager_UpdateStatFloat(int p0, int p1, int p2, float p3) { invoke<Void>(0x077C88DB, p0, p1, p2, p3); }
	static void StatsManager_SetUpdateFrequency(float p0, BOOL p1) { invoke<Void>(0x006CF1F3, p0, p1); }
}

namespace MC_CAREER_SPEECH
{
	static BOOL mcCareerSpeech_PlayScenario(int p0, char* p1, const char* p2) { return invoke<BOOL>(0x7FEAC093, p0, p1, p2); }
	static int mcCareerSpeech_PlayNamedScenario(int p0, int p1, int p2) { return invoke<int>(0xEB90868C, p0, p1, p2); }
	static int mcCareerSpeech_PlayRacerScenario(int p0, int p1, int p2) { return invoke<int>(0xB70A3886, p0, p1, p2); }
	static BOOL mcCareerSpeech_IsScenarioPlaying(int p0) { return invoke<BOOL>(0xD2FF9A5B, p0); }
	static void mcCareerSpeech_Stop() { invoke<Void>(0x8222F800); }
	static int mcCareerSpeech_PrepareScenario(int p0, int p1, int p2) { return invoke<int>(0x1B037C72, p0, p1, p2); }
	static int mcCareerSpeech_PrepareRacerScenario(int p0, int p1, int p2) { return invoke<int>(0x8F6B5585, p0, p1, p2); }
	static int mcCareerSpeech_EnqueueNamedScenario(int p0, int p1, int p2) { return invoke<int>(0xD3D03D3D, p0, p1, p2); }
	static BOOL mcCareerSpeech_IsScenarioPrepared(int p0) { return invoke<BOOL>(0xD61815A4, p0); }
	static void mcCareerSpeech_PlayPreparedScenario() { invoke<Void>(0x383636E1); }
	static int mcCareerSpeech_FindScenario(const char* p0) { return invoke<int>(0xE85AF6EE, p0); }
	static void mcCareerSpeech_SetEmitters(int p0, int p1) { invoke<Void>(0x2C8BA4A9, p0, p1); }
	static int mcCareerSpeech_PlayTauntInRace(int p0, int p1, int p2, int p3) { return invoke<int>(0x6B5C86EF, p0, p1, p2, p3); }
	static int mcCareerSpeech_PlayTauntpostRace(int p0, int p1, BOOL p2) { return invoke<int>(0xB0D14A76, p0, p1, p2); }
}

namespace MC_MUSIC_MANAGER
{
	static void mcMusicManager_Play(int p0) { invoke<Void>(0xC098F4F1, p0); }
	static void mcMusicManager_PlaySilently() { invoke<Void>(0x3BE21EC0); }
	static void mcMusicManager_Stop() { invoke<Void>(0x76922450); }
	static void mcMusicManager_Pause() { invoke<Void>(0x0B944108); }
	static void mcMusicManager_Next() { invoke<Void>(0x1C45FCF8); }
	static void mcMusicManager_Prev() { invoke<Void>(0xAEE526A9); }
	static void mcMusicManager_SetStartOffset(int p0) { invoke<Void>(0xCB5792FD, p0); }
	static void mcMusicManager_SuspendUserState(int p0) { invoke<Void>(0x8C2F692C, p0); }
	static void mcMusicManager_ResumeUserState() { invoke<Void>(0x258C9BFA); }
	static void mcMusicManager_GotoAllGenreSong(int p0) { invoke<Void>(0x2B3DA3B9, p0); }
	static void mcMusicManager_PlayCustomMusic(int p0) { invoke<Void>(0x51BFB501, p0); }
	static void mcMusicManager_StopCustomMusic() { invoke<Void>(0x6CB42B7C); }
	static void mcMusicManager_SetAllowBackgroundPlay(BOOL p0) { invoke<Void>(0x1E4FDC85, p0); }
	static void mcMusicManager_TriggerDynmixerSuspend(BOOL p0) { invoke<Void>(0x3C86E5F4, p0); }
}

namespace MC_CTRL
{
	static BOOL mcCtrl_IsVisible(int p0) { return invoke<BOOL>(0xBB83E894, p0); }
}

namespace SPEECH_SYSTEM
{
	static BOOL SpeechSystem_IsInUse() { return invoke<BOOL>(0xF897691A); }
	static BOOL SpeechSystem_IsPlaying() { return invoke<BOOL>(0x8BAFE429); }
	static void SpeechSystem_StopEverything() { invoke<Void>(0xFD90EC2B); }
}

namespace WEATHER
{
	static void Weather_SetCurrentWeather(Any p0, BOOL p1) { invoke<Void>(0x37F300B9, p0, p1); }
	static Any Weather_GetCurrentWeather() { return invoke<Any>(0x4402D949); }
	static BOOL Weather_GetAndSetAutoWeatherChange(BOOL set) { return invoke<BOOL>(0xC0394E05, set); }
}

namespace POST_PROCESSING
{
	static void PostProcessing_SetCutsceneDofNear(float p0) { invoke<Void>(0x34A9AA55, p0); }
	static void PostProcessing_SetCutsceneDofFar(float p0) { invoke<Void>(0xBD68602C, p0); }
	static void PostProcessing_SetCutsceneDof() { invoke<Void>(0xDBD3687C); }
	static void PostProcessing_SetGarageDof() { invoke<Void>(0x0F806EBC); }
	static void PostProcessing_SetGameDof() { invoke<Void>(0x3305B685); }
	static void PostProcessing_SetDofTransitionTime(float p0) { invoke<Void>(0xA0348336, p0); }
	static void PostProcessing_SetFogNearFar(float p0, float p1) { invoke<Void>(0xC5F9E22D, p0, p1); }
	static float PostProcessing_GetFogNear() { return invoke<float>(0xF5A9D349); }
	static float PostProcessing_GetFogFar() { return invoke<float>(0x92F3FDDD); }
}

namespace MC_PLAYER_AUDIO_ENTITY
{
	static void mcPlayerAudioEntity_PlayEndRaceSpeechWin() { invoke<Void>(0xA6C4EA2E); }
	static void mcPlayerAudioEntity_PlayEndRaceSpeechLose() { invoke<Void>(0x07B20714); }
	static void mcPlayerAudioEntity_PlayEndRaceSpeechClose() { invoke<Void>(0x22FEE0FE); }
}

namespace LIGHTING_MANAGER
{
	static void LightingManager_EnableCutsceneLighting(BOOL p0) { invoke<Void>(0x3A47A35A, p0); }
}

namespace DYNAMICMIXER
{
	static void DYNAMICMIXER_TriggerState(int p0) { invoke<Void>(0xECD8E116, p0); }
	static void DYNAMICMIXER_DeTriggerState(int p0) { invoke<Void>(0xF86010D1, p0); }
}
"""

# BUG: parsing will use comment hex value instead of invoke<> value. Search for 'Unused' in json and manually fix
# BUG: fix random '//' comments
# BUG: will parse const char* incorrectly
# BUG: this function is broken 0x6B8E4CDD
# BUG: this function is broken _0xD7BB1792
# BUG: search for "{" invalid native names

# Initialize a dictionary to store all function details
all_functions_dict = {}

# Split the code by namespaces
code_namespaces = code.strip().split("\n\n")

# Iterate through each namespace
for namespace_code in code_namespaces:
    # Split the namespace code by lines
    code_lines = namespace_code.strip().splitlines()

    # Initialize variables to store function details
    namespace_name = None
    functions = []

    # Iterate through each line of code
    for line in code_lines:
        if line.strip().startswith("namespace "):
            # Extract the namespace name
            namespace_name = line.strip().split()[1]
        elif line.strip().startswith("static "):
            # Extract function details using a simpler approach
            function_parts = line.strip().split()
            return_type = function_parts[1]
            function_signature = " ".join(function_parts[2:]).split("//")[0]  # Remove comments
            function_name = function_signature.split("(")[0]
            parameters = function_signature.split("(")[1].split(")")[0].split(",") if "(" in function_signature else []

            # Extract parameter types and names
            param_info = []
            for param in parameters:
                param_parts = param.strip().split()
                if len(param_parts) == 2:
                    param_type, param_name = param_parts
                    param_info.append({"Type": param_type, "Name": param_name})

            comment_hex_value = function_parts[-1]

            functions.append({
                "Namespace": namespace_name,
                "Return Type": return_type,
                "Function Name": function_name,
                "Parameters": param_info,
                "Comment Hexadecimal Value": comment_hex_value,
            })

    # Add functions from the current namespace to the dictionary
    all_functions_dict[namespace_name] = functions

# Write all the function details to a single text file
output_file_path = "natives.json"
with open(output_file_path, "w") as output_file:

    output_file.write('{')

    for namespace, functions in all_functions_dict.items():
        output_file.write(f'"{namespace}": {{')

        for i, func in enumerate(functions):
            output_file.write(f'"{func["Comment Hexadecimal Value"]}": {{')
            output_file.write(f'"name": "{func["Function Name"]}",')
            output_file.write(f'"comment": "",')
            output_file.write('"params": [')
                
            total_params = len(func['Parameters'])
            for j, param in enumerate(func['Parameters']):
                output_file.write('{')
                output_file.write(f'"type": "{param["Type"]}",')
                output_file.write(f'"name": "{param["Name"]}"')
                if j < total_params - 1:
                    output_file.write('},')
                else:
                    output_file.write('}')
                        
            output_file.write('],')
            output_file.write(f'"return_type": "{func["Return Type"]}"')
            if i < len(functions) - 1:
                output_file.write('},')
            else:
                output_file.write('}')
            
        output_file.write('},')

    output_file.write('}')

print(f"natives saved to {output_file_path}.")
