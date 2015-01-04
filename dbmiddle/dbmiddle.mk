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
Date                   :=01/04/15
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
	$(IntermediateDirectory)/ConfigLocal.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose.c$(ObjectSuffix) $(IntermediateDirectory)/mongoose_Controller.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_JsonController.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_JsonResponse.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_Mutex.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_Request.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_Response.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_Server.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_Session.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/mongoose_Sessions.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_StreamResponse.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_UploadFile.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_Utils.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_WebController.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_WebSocket.cpp$(ObjectSuffix) $(IntermediateDirectory)/mongoose_WebSockets.cpp$(ObjectSuffix) 



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

$(IntermediateDirectory)/mongoose_Controller.cpp$(ObjectSuffix): mongoose/Controller.cpp $(IntermediateDirectory)/mongoose_Controller.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/Controller.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_Controller.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_Controller.cpp$(DependSuffix): mongoose/Controller.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_Controller.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_Controller.cpp$(DependSuffix) -MM "mongoose/Controller.cpp"

$(IntermediateDirectory)/mongoose_Controller.cpp$(PreprocessSuffix): mongoose/Controller.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_Controller.cpp$(PreprocessSuffix) "mongoose/Controller.cpp"

$(IntermediateDirectory)/mongoose_JsonController.cpp$(ObjectSuffix): mongoose/JsonController.cpp $(IntermediateDirectory)/mongoose_JsonController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/JsonController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_JsonController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_JsonController.cpp$(DependSuffix): mongoose/JsonController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_JsonController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_JsonController.cpp$(DependSuffix) -MM "mongoose/JsonController.cpp"

$(IntermediateDirectory)/mongoose_JsonController.cpp$(PreprocessSuffix): mongoose/JsonController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_JsonController.cpp$(PreprocessSuffix) "mongoose/JsonController.cpp"

$(IntermediateDirectory)/mongoose_JsonResponse.cpp$(ObjectSuffix): mongoose/JsonResponse.cpp $(IntermediateDirectory)/mongoose_JsonResponse.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/JsonResponse.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_JsonResponse.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_JsonResponse.cpp$(DependSuffix): mongoose/JsonResponse.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_JsonResponse.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_JsonResponse.cpp$(DependSuffix) -MM "mongoose/JsonResponse.cpp"

$(IntermediateDirectory)/mongoose_JsonResponse.cpp$(PreprocessSuffix): mongoose/JsonResponse.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_JsonResponse.cpp$(PreprocessSuffix) "mongoose/JsonResponse.cpp"

$(IntermediateDirectory)/mongoose_Mutex.cpp$(ObjectSuffix): mongoose/Mutex.cpp $(IntermediateDirectory)/mongoose_Mutex.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/Mutex.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_Mutex.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_Mutex.cpp$(DependSuffix): mongoose/Mutex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_Mutex.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_Mutex.cpp$(DependSuffix) -MM "mongoose/Mutex.cpp"

$(IntermediateDirectory)/mongoose_Mutex.cpp$(PreprocessSuffix): mongoose/Mutex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_Mutex.cpp$(PreprocessSuffix) "mongoose/Mutex.cpp"

$(IntermediateDirectory)/mongoose_Request.cpp$(ObjectSuffix): mongoose/Request.cpp $(IntermediateDirectory)/mongoose_Request.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/Request.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_Request.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_Request.cpp$(DependSuffix): mongoose/Request.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_Request.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_Request.cpp$(DependSuffix) -MM "mongoose/Request.cpp"

$(IntermediateDirectory)/mongoose_Request.cpp$(PreprocessSuffix): mongoose/Request.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_Request.cpp$(PreprocessSuffix) "mongoose/Request.cpp"

$(IntermediateDirectory)/mongoose_Response.cpp$(ObjectSuffix): mongoose/Response.cpp $(IntermediateDirectory)/mongoose_Response.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/Response.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_Response.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_Response.cpp$(DependSuffix): mongoose/Response.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_Response.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_Response.cpp$(DependSuffix) -MM "mongoose/Response.cpp"

$(IntermediateDirectory)/mongoose_Response.cpp$(PreprocessSuffix): mongoose/Response.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_Response.cpp$(PreprocessSuffix) "mongoose/Response.cpp"

$(IntermediateDirectory)/mongoose_Server.cpp$(ObjectSuffix): mongoose/Server.cpp $(IntermediateDirectory)/mongoose_Server.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/Server.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_Server.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_Server.cpp$(DependSuffix): mongoose/Server.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_Server.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_Server.cpp$(DependSuffix) -MM "mongoose/Server.cpp"

$(IntermediateDirectory)/mongoose_Server.cpp$(PreprocessSuffix): mongoose/Server.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_Server.cpp$(PreprocessSuffix) "mongoose/Server.cpp"

$(IntermediateDirectory)/mongoose_Session.cpp$(ObjectSuffix): mongoose/Session.cpp $(IntermediateDirectory)/mongoose_Session.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/Session.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_Session.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_Session.cpp$(DependSuffix): mongoose/Session.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_Session.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_Session.cpp$(DependSuffix) -MM "mongoose/Session.cpp"

$(IntermediateDirectory)/mongoose_Session.cpp$(PreprocessSuffix): mongoose/Session.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_Session.cpp$(PreprocessSuffix) "mongoose/Session.cpp"

$(IntermediateDirectory)/mongoose_Sessions.cpp$(ObjectSuffix): mongoose/Sessions.cpp $(IntermediateDirectory)/mongoose_Sessions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/Sessions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_Sessions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_Sessions.cpp$(DependSuffix): mongoose/Sessions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_Sessions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_Sessions.cpp$(DependSuffix) -MM "mongoose/Sessions.cpp"

$(IntermediateDirectory)/mongoose_Sessions.cpp$(PreprocessSuffix): mongoose/Sessions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_Sessions.cpp$(PreprocessSuffix) "mongoose/Sessions.cpp"

$(IntermediateDirectory)/mongoose_StreamResponse.cpp$(ObjectSuffix): mongoose/StreamResponse.cpp $(IntermediateDirectory)/mongoose_StreamResponse.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/StreamResponse.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_StreamResponse.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_StreamResponse.cpp$(DependSuffix): mongoose/StreamResponse.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_StreamResponse.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_StreamResponse.cpp$(DependSuffix) -MM "mongoose/StreamResponse.cpp"

$(IntermediateDirectory)/mongoose_StreamResponse.cpp$(PreprocessSuffix): mongoose/StreamResponse.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_StreamResponse.cpp$(PreprocessSuffix) "mongoose/StreamResponse.cpp"

$(IntermediateDirectory)/mongoose_UploadFile.cpp$(ObjectSuffix): mongoose/UploadFile.cpp $(IntermediateDirectory)/mongoose_UploadFile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/UploadFile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_UploadFile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_UploadFile.cpp$(DependSuffix): mongoose/UploadFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_UploadFile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_UploadFile.cpp$(DependSuffix) -MM "mongoose/UploadFile.cpp"

$(IntermediateDirectory)/mongoose_UploadFile.cpp$(PreprocessSuffix): mongoose/UploadFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_UploadFile.cpp$(PreprocessSuffix) "mongoose/UploadFile.cpp"

$(IntermediateDirectory)/mongoose_Utils.cpp$(ObjectSuffix): mongoose/Utils.cpp $(IntermediateDirectory)/mongoose_Utils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/Utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_Utils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_Utils.cpp$(DependSuffix): mongoose/Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_Utils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_Utils.cpp$(DependSuffix) -MM "mongoose/Utils.cpp"

$(IntermediateDirectory)/mongoose_Utils.cpp$(PreprocessSuffix): mongoose/Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_Utils.cpp$(PreprocessSuffix) "mongoose/Utils.cpp"

$(IntermediateDirectory)/mongoose_WebController.cpp$(ObjectSuffix): mongoose/WebController.cpp $(IntermediateDirectory)/mongoose_WebController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/WebController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_WebController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_WebController.cpp$(DependSuffix): mongoose/WebController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_WebController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_WebController.cpp$(DependSuffix) -MM "mongoose/WebController.cpp"

$(IntermediateDirectory)/mongoose_WebController.cpp$(PreprocessSuffix): mongoose/WebController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_WebController.cpp$(PreprocessSuffix) "mongoose/WebController.cpp"

$(IntermediateDirectory)/mongoose_WebSocket.cpp$(ObjectSuffix): mongoose/WebSocket.cpp $(IntermediateDirectory)/mongoose_WebSocket.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/WebSocket.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_WebSocket.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_WebSocket.cpp$(DependSuffix): mongoose/WebSocket.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_WebSocket.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_WebSocket.cpp$(DependSuffix) -MM "mongoose/WebSocket.cpp"

$(IntermediateDirectory)/mongoose_WebSocket.cpp$(PreprocessSuffix): mongoose/WebSocket.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_WebSocket.cpp$(PreprocessSuffix) "mongoose/WebSocket.cpp"

$(IntermediateDirectory)/mongoose_WebSockets.cpp$(ObjectSuffix): mongoose/WebSockets.cpp $(IntermediateDirectory)/mongoose_WebSockets.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/anandrathi/sre/baccount/dbmiddle/mongoose/WebSockets.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mongoose_WebSockets.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mongoose_WebSockets.cpp$(DependSuffix): mongoose/WebSockets.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mongoose_WebSockets.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mongoose_WebSockets.cpp$(DependSuffix) -MM "mongoose/WebSockets.cpp"

$(IntermediateDirectory)/mongoose_WebSockets.cpp$(PreprocessSuffix): mongoose/WebSockets.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mongoose_WebSockets.cpp$(PreprocessSuffix) "mongoose/WebSockets.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/dbmiddle"


