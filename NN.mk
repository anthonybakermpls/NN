##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=NN
ConfigurationName      :=Debug
WorkspacePath          := "/home/anthony/Data/Code/NN"
ProjectPath            := "/home/anthony/Data/Code/NN"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=anthony
Date                   :=05/21/14
CodeLitePath           :="/home/anthony/.codelite"
LinkerName             :=clang++
SharedObjectLinkerName :=clang++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="NN.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -s
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)src $(IncludeSwitch)lib/glm/glm 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := clang++
CC       := clang
CXXFLAGS :=  -g -Wall -std=c++11 -O0 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := llvm-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/src_parameters$(ObjectSuffix) $(IntermediateDirectory)/src_gen_alg$(ObjectSuffix) $(IntermediateDirectory)/src_lifeform$(ObjectSuffix) $(IntermediateDirectory)/src_neural_net$(ObjectSuffix) $(IntermediateDirectory)/src_system$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anthony/Data/Code/NN/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/src_parameters$(ObjectSuffix): src/parameters.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anthony/Data/Code/NN/src/parameters.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_parameters$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_parameters$(PreprocessSuffix): src/parameters.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_parameters$(PreprocessSuffix) "src/parameters.cpp"

$(IntermediateDirectory)/src_gen_alg$(ObjectSuffix): src/gen_alg.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anthony/Data/Code/NN/src/gen_alg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gen_alg$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gen_alg$(PreprocessSuffix): src/gen_alg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gen_alg$(PreprocessSuffix) "src/gen_alg.cpp"

$(IntermediateDirectory)/src_lifeform$(ObjectSuffix): src/lifeform.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anthony/Data/Code/NN/src/lifeform.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lifeform$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lifeform$(PreprocessSuffix): src/lifeform.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lifeform$(PreprocessSuffix) "src/lifeform.cpp"

$(IntermediateDirectory)/src_neural_net$(ObjectSuffix): src/neural_net.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anthony/Data/Code/NN/src/neural_net.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_neural_net$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_neural_net$(PreprocessSuffix): src/neural_net.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_neural_net$(PreprocessSuffix) "src/neural_net.cpp"

$(IntermediateDirectory)/src_system$(ObjectSuffix): src/system.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anthony/Data/Code/NN/src/system.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_system$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_system$(PreprocessSuffix): src/system.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_system$(PreprocessSuffix) "src/system.cpp"

##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_parameters$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_parameters$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_parameters$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_gen_alg$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_gen_alg$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_gen_alg$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_lifeform$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_lifeform$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_lifeform$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_neural_net$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_neural_net$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_neural_net$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_system$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_system$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_system$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/NN"


