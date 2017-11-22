##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=therestofyourlife
ConfigurationName      :=Debug
WorkspacePath          :=C:/WorkSpace/therestofyourlife
ProjectPath            :=C:/WorkSpace/therestofyourlife
IntermediateDirectory  :=./Obj
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=aLFoNSo
Date                   :=22/11/2017
CodeLitePath           :="C:/Archivos de programa/CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=./bin/$(ConfigurationName)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="therestofyourlife.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Archivos de programa\CodeLite
WXWIN:=C:/wx302
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/hitables.cpp$(ObjectSuffix) $(IntermediateDirectory)/textures.cpp$(ObjectSuffix) $(IntermediateDirectory)/materials.cpp$(ObjectSuffix) $(IntermediateDirectory)/rangen.cpp$(ObjectSuffix) $(IntermediateDirectory)/vec3.cpp$(ObjectSuffix) $(IntermediateDirectory)/aabb.cpp$(ObjectSuffix) $(IntermediateDirectory)/perlin.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Obj"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Obj"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/WorkSpace/therestofyourlife/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/hitables.cpp$(ObjectSuffix): hitables.cpp $(IntermediateDirectory)/hitables.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/WorkSpace/therestofyourlife/hitables.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hitables.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hitables.cpp$(DependSuffix): hitables.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hitables.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hitables.cpp$(DependSuffix) -MM hitables.cpp

$(IntermediateDirectory)/hitables.cpp$(PreprocessSuffix): hitables.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hitables.cpp$(PreprocessSuffix) hitables.cpp

$(IntermediateDirectory)/textures.cpp$(ObjectSuffix): textures.cpp $(IntermediateDirectory)/textures.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/WorkSpace/therestofyourlife/textures.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/textures.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/textures.cpp$(DependSuffix): textures.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/textures.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/textures.cpp$(DependSuffix) -MM textures.cpp

$(IntermediateDirectory)/textures.cpp$(PreprocessSuffix): textures.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/textures.cpp$(PreprocessSuffix) textures.cpp

$(IntermediateDirectory)/materials.cpp$(ObjectSuffix): materials.cpp $(IntermediateDirectory)/materials.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/WorkSpace/therestofyourlife/materials.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/materials.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/materials.cpp$(DependSuffix): materials.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/materials.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/materials.cpp$(DependSuffix) -MM materials.cpp

$(IntermediateDirectory)/materials.cpp$(PreprocessSuffix): materials.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/materials.cpp$(PreprocessSuffix) materials.cpp

$(IntermediateDirectory)/rangen.cpp$(ObjectSuffix): rangen.cpp $(IntermediateDirectory)/rangen.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/WorkSpace/therestofyourlife/rangen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/rangen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/rangen.cpp$(DependSuffix): rangen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/rangen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/rangen.cpp$(DependSuffix) -MM rangen.cpp

$(IntermediateDirectory)/rangen.cpp$(PreprocessSuffix): rangen.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/rangen.cpp$(PreprocessSuffix) rangen.cpp

$(IntermediateDirectory)/vec3.cpp$(ObjectSuffix): vec3.cpp $(IntermediateDirectory)/vec3.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/WorkSpace/therestofyourlife/vec3.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vec3.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vec3.cpp$(DependSuffix): vec3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vec3.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vec3.cpp$(DependSuffix) -MM vec3.cpp

$(IntermediateDirectory)/vec3.cpp$(PreprocessSuffix): vec3.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vec3.cpp$(PreprocessSuffix) vec3.cpp

$(IntermediateDirectory)/aabb.cpp$(ObjectSuffix): aabb.cpp $(IntermediateDirectory)/aabb.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/WorkSpace/therestofyourlife/aabb.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/aabb.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/aabb.cpp$(DependSuffix): aabb.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/aabb.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/aabb.cpp$(DependSuffix) -MM aabb.cpp

$(IntermediateDirectory)/aabb.cpp$(PreprocessSuffix): aabb.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/aabb.cpp$(PreprocessSuffix) aabb.cpp

$(IntermediateDirectory)/perlin.cpp$(ObjectSuffix): perlin.cpp $(IntermediateDirectory)/perlin.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/WorkSpace/therestofyourlife/perlin.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/perlin.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/perlin.cpp$(DependSuffix): perlin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/perlin.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/perlin.cpp$(DependSuffix) -MM perlin.cpp

$(IntermediateDirectory)/perlin.cpp$(PreprocessSuffix): perlin.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/perlin.cpp$(PreprocessSuffix) perlin.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Obj/


