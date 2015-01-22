##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=dbmiddle
ConfigurationName      :=Debug
WorkspacePath          := "/home/anandrathi/sre/baccount"
ProjectPath            := "/home/anandrathi/sre/baccount/dbmiddle"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=anandrathi
Date                   :=01/22/15
CodeLitePath           :="/home/anandrathi/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="dbmiddle.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./soci/ $(IncludeSwitch)./soci/core/ $(IncludeSwitch)./jsoncpp/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)soci_core $(LibrarySwitch)soci_mysql $(LibrarySwitch)soci_postgresql $(LibrarySwitch)jsoncpp $(LibrarySwitch)boost_date_time 
ArLibs                 :=  "soci_core" "soci_mysql" "soci_postgresql" "libjsoncpp.a" "boost_date_time" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./soci/build/lib $(LibraryPathSwitch)./jsoncpp/build/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=./soci/build/lib;../soci/build/lib
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/pgdbcommon.cpp$(ObjectSuffix) $(IntermediateDirectory)/SCreateScheme.cpp$(ObjectSuffix) $(IntermediateDirectory)/SCreateBet.cpp$(ObjectSuffix) $(IntermediateDirectory)/SFinalizeScheme.cpp$(ObjectSuffix) $(IntermediateDirectory)/SUser.cpp$(ObjectSuffix) $(IntermediateDirectory)/error_codes.cpp$(ObjectSuffix) $(IntermediateDirectory)/UnitTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/LocalCaches.cpp$(ObjectSuffix) $(IntermediateDirectory)/SGetSchemeNOptions.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ConfigLocal.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose.c$(ObjectSuffix) $(IntermediateDirectory)/RestAPI.cpp$(ObjectSuffix) $(IntermediateDirectory)/rest_impl.cpp$(ObjectSuffix) $(IntermediateDirectory)/getgainPLSQL.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/pgdbcommon.cpp$(ObjectSuffix): pgdbcommon.cpp $(IntermediateDirectory)/pgdbcommon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/pgdbcommon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pgdbcommon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pgdbcommon.cpp$(DependSuffix): pgdbcommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pgdbcommon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pgdbcommon.cpp$(DependSuffix) -MM "pgdbcommon.cpp"

$(IntermediateDirectory)/pgdbcommon.cpp$(PreprocessSuffix): pgdbcommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pgdbcommon.cpp$(PreprocessSuffix) "pgdbcommon.cpp"

$(IntermediateDirectory)/SCreateScheme.cpp$(ObjectSuffix): SCreateScheme.cpp $(IntermediateDirectory)/SCreateScheme.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/SCreateScheme.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SCreateScheme.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SCreateScheme.cpp$(DependSuffix): SCreateScheme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SCreateScheme.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SCreateScheme.cpp$(DependSuffix) -MM "SCreateScheme.cpp"

$(IntermediateDirectory)/SCreateScheme.cpp$(PreprocessSuffix): SCreateScheme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SCreateScheme.cpp$(PreprocessSuffix) "SCreateScheme.cpp"

$(IntermediateDirectory)/SCreateBet.cpp$(ObjectSuffix): SCreateBet.cpp $(IntermediateDirectory)/SCreateBet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/SCreateBet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SCreateBet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SCreateBet.cpp$(DependSuffix): SCreateBet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SCreateBet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SCreateBet.cpp$(DependSuffix) -MM "SCreateBet.cpp"

$(IntermediateDirectory)/SCreateBet.cpp$(PreprocessSuffix): SCreateBet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SCreateBet.cpp$(PreprocessSuffix) "SCreateBet.cpp"

$(IntermediateDirectory)/SFinalizeScheme.cpp$(ObjectSuffix): SFinalizeScheme.cpp $(IntermediateDirectory)/SFinalizeScheme.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/SFinalizeScheme.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SFinalizeScheme.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SFinalizeScheme.cpp$(DependSuffix): SFinalizeScheme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SFinalizeScheme.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SFinalizeScheme.cpp$(DependSuffix) -MM "SFinalizeScheme.cpp"

$(IntermediateDirectory)/SFinalizeScheme.cpp$(PreprocessSuffix): SFinalizeScheme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SFinalizeScheme.cpp$(PreprocessSuffix) "SFinalizeScheme.cpp"

$(IntermediateDirectory)/SUser.cpp$(ObjectSuffix): SUser.cpp $(IntermediateDirectory)/SUser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/SUser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SUser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SUser.cpp$(DependSuffix): SUser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SUser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SUser.cpp$(DependSuffix) -MM "SUser.cpp"

$(IntermediateDirectory)/SUser.cpp$(PreprocessSuffix): SUser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SUser.cpp$(PreprocessSuffix) "SUser.cpp"

$(IntermediateDirectory)/error_codes.cpp$(ObjectSuffix): error_codes.cpp $(IntermediateDirectory)/error_codes.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/error_codes.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/error_codes.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/error_codes.cpp$(DependSuffix): error_codes.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/error_codes.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/error_codes.cpp$(DependSuffix) -MM "error_codes.cpp"

$(IntermediateDirectory)/error_codes.cpp$(PreprocessSuffix): error_codes.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/error_codes.cpp$(PreprocessSuffix) "error_codes.cpp"

$(IntermediateDirectory)/UnitTest.cpp$(ObjectSuffix): UnitTest.cpp $(IntermediateDirectory)/UnitTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/UnitTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/UnitTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/UnitTest.cpp$(DependSuffix): UnitTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/UnitTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/UnitTest.cpp$(DependSuffix) -MM "UnitTest.cpp"

$(IntermediateDirectory)/UnitTest.cpp$(PreprocessSuffix): UnitTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/UnitTest.cpp$(PreprocessSuffix) "UnitTest.cpp"

$(IntermediateDirectory)/LocalCaches.cpp$(ObjectSuffix): LocalCaches.cpp $(IntermediateDirectory)/LocalCaches.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/LocalCaches.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LocalCaches.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LocalCaches.cpp$(DependSuffix): LocalCaches.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LocalCaches.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LocalCaches.cpp$(DependSuffix) -MM "LocalCaches.cpp"

$(IntermediateDirectory)/LocalCaches.cpp$(PreprocessSuffix): LocalCaches.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LocalCaches.cpp$(PreprocessSuffix) "LocalCaches.cpp"

$(IntermediateDirectory)/SGetSchemeNOptions.cpp$(ObjectSuffix): SGetSchemeNOptions.cpp $(IntermediateDirectory)/SGetSchemeNOptions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/SGetSchemeNOptions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SGetSchemeNOptions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SGetSchemeNOptions.cpp$(DependSuffix): SGetSchemeNOptions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SGetSchemeNOptions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SGetSchemeNOptions.cpp$(DependSuffix) -MM "SGetSchemeNOptions.cpp"

$(IntermediateDirectory)/SGetSchemeNOptions.cpp$(PreprocessSuffix): SGetSchemeNOptions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SGetSchemeNOptions.cpp$(PreprocessSuffix) "SGetSchemeNOptions.cpp"

$(IntermediateDirectory)/ConfigLocal.cpp$(ObjectSuffix): ConfigLocal.cpp $(IntermediateDirectory)/ConfigLocal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/ConfigLocal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConfigLocal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConfigLocal.cpp$(DependSuffix): ConfigLocal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConfigLocal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConfigLocal.cpp$(DependSuffix) -MM "ConfigLocal.cpp"

$(IntermediateDirectory)/ConfigLocal.cpp$(PreprocessSuffix): ConfigLocal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConfigLocal.cpp$(PreprocessSuffix) "ConfigLocal.cpp"

$(IntermediateDirectory)/mongoose.c$(ObjectSuffix): mongoose.c $(IntermediateDirectory)/mongoose.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose.c$(DependSuffix): mongoose.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose.c$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose.c$(DependSuffix) -MM "mongoose.c"

$(IntermediateDirectory)/mongoose.c$(PreprocessSuffix): mongoose.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose.c$(PreprocessSuffix) "mongoose.c"

$(IntermediateDirectory)/RestAPI.cpp$(ObjectSuffix): RestAPI.cpp $(IntermediateDirectory)/RestAPI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/RestAPI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RestAPI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RestAPI.cpp$(DependSuffix): RestAPI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RestAPI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RestAPI.cpp$(DependSuffix) -MM "RestAPI.cpp"

$(IntermediateDirectory)/RestAPI.cpp$(PreprocessSuffix): RestAPI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RestAPI.cpp$(PreprocessSuffix) "RestAPI.cpp"

$(IntermediateDirectory)/rest_impl.cpp$(ObjectSuffix): rest_impl.cpp $(IntermediateDirectory)/rest_impl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/rest_impl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/rest_impl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/rest_impl.cpp$(DependSuffix): rest_impl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/rest_impl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/rest_impl.cpp$(DependSuffix) -MM "rest_impl.cpp"

$(IntermediateDirectory)/rest_impl.cpp$(PreprocessSuffix): rest_impl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/rest_impl.cpp$(PreprocessSuffix) "rest_impl.cpp"

$(IntermediateDirectory)/getgainPLSQL.cpp$(ObjectSuffix): getgainPLSQL.cpp $(IntermediateDirectory)/getgainPLSQL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/getgainPLSQL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/getgainPLSQL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/getgainPLSQL.cpp$(DependSuffix): getgainPLSQL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/getgainPLSQL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/getgainPLSQL.cpp$(DependSuffix) -MM "getgainPLSQL.cpp"

$(IntermediateDirectory)/getgainPLSQL.cpp$(PreprocessSuffix): getgainPLSQL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/getgainPLSQL.cpp$(PreprocessSuffix) "getgainPLSQL.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/dbmiddle"


