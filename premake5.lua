workspace "openspy-client"
  configurations { "Release" }
  platforms { "Win32", "x64" }
  location "build"
  objdir ("build/obj")
  buildlog ("build/log/%{prj.name}.log")

  characterset ("ASCII")
  staticruntime "Off"
  exceptionhandling "Off"
  floatingpoint "Fast"
  floatingpointexceptions "Off"
  intrinsics "On"
  rtti "Off"
  flags { "NoBufferSecurityCheck", "NoIncrementalLink", "NoManifest", "NoPCH", "NoRuntimeChecks", "OmitDefaultLibrary" }
  buildoptions { "/kernel", "/Gs1000000" }
  linkoptions { "/kernel", "/SAFESEH:NO", "/GUARD:NO", "/EMITPOGOPHASEINFO", "/RELEASE", "/DEBUG:NONE", "/NOIMPLIB", "/NOEXP", "/IGNORE:4104" }

  filter "configurations:Release"
    runtime "Release"
    defines "NDEBUG"
    optimize "Speed"
    symbols "Off"

  filter "platforms:Win32"
    architecture "x86"

  filter "platforms:x64"
    architecture "x64"
    linkoptions { "/HIGHENTROPYVA:NO" }

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

if _ACTION and _ACTION >= "vs2010" then
  require "vstudio"
  premake.override(premake.vstudio.vc2010.elements, "clCompile", function(base, prj)
    local calls = base(prj)
    table.insert(calls, function() premake.vstudio.vc2010.element("SDLCheck", nil, "false") end)
    table.insert(calls, function() premake.vstudio.vc2010.element("ControlFlowGuard", nil, "false") end)
    return calls
  end)
  premake.override(premake.vstudio.vc2010.elements, "link", function(base, prj)
    local calls = base(prj)
    table.insert(calls, function() premake.vstudio.vc2010.element("SetChecksum", nil, "true") end)
    table.insert(calls, function() premake.vstudio.vc2010.element("CETCompat", nil, "false") end)
    table.insert(calls, function() premake.vstudio.vc2010.element("ImageHasSafeExceptionHandlers", nil, "false") end)
    table.insert(calls, function() premake.vstudio.vc2010.element("EnableUAC", nil, "false") end)
    return calls
  end)
end
