workspace "openspy-client"
   configurations { "Release" }
   platforms { "Win32", "x64" }
   location "build"
   objdir ("build/obj")
   buildlog ("build/log/%{prj.name}.log")

   characterset ("MBCS")
   staticruntime "Off"
   exceptionhandling "Off"
   floatingpoint "Fast"
   intrinsics "On"
   rtti "Off"
   flags { "NoBufferSecurityCheck", "NoIncrementalLink", "NoManifest", "NoPCH", "NoRuntimeChecks", "OmitDefaultLibrary" }
   buildoptions { "/kernel /Gs1000000" }
   linkoptions { "/SAFESEH:NO", "/EMITPOGOPHASEINFO", "/RELEASE", "/DEBUG:NONE" }

   filter "configurations:Release"
      runtime "Release"
      defines "NDEBUG"
      optimize "Speed"
      symbols "Off"

   filter "platforms:Win32"
      architecture "x86"

   filter "platforms:x64"
      architecture "x64"

project "openspy-client"
   kind "SharedLib"
   language "C"
   targetextension ".dll"
   targetdir "bin"
   files { "dllmain.c", "include/*.h", "iathook/iathook.h" }
   entrypoint "DllMain"
   filter "platforms:Win32"
      targetname "openspy.x86"
   filter "platforms:x64"
      targetname "openspy.x64"
