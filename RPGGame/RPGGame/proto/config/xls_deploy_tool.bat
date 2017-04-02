@echo off

set XLS_NAME=%1
set SHEET_NAME=%2

echo.
echo =========Compilation of %XLS_NAME%=========

::----------------------------------------
::��������Դת��
::-----------------------------------------

@echo off
::---------------------------------------------------
::��һ������xls����xls_deploy_toolת��data��proto
::---------------------------------------------------
set STEP1_SERVER_XLS=../xls
set STEP2_SERVER_PYTHON=../python
set STEP2_SERVER_PROTO=../proto
set STEP2_SERVER_DATA=../data
set STEP2_SERVER_JSON=../json
set STEP2_SERVER_SRC=../src
@echo on

@echo off
echo TRY TO DELETE TEMP FILES:
del %STEP2_SERVER_PYTHON%\*_pb2.py
del %STEP2_SERVER_PYTHON%\*_pb2.pyc
del %STEP2_SERVER_PROTO%\*.proto
del %STEP2_SERVER_DATA%\*.data
del %STEP2_SERVER_JSON%\*.data
del %STEP2_SERVER_SRC%\proto\*.pb.cc
del %STEP2_SERVER_SRC%\proto\*.pb.h
::del *.log
::del *.txt
@echo on

call python xls_deploy_tool.py %SHEET_NAME% %STEP1_SERVER_XLS%\%XLS_NAME% s

@echo off
if  %errorlevel% LSS 0 ( echo  "Failed" & pause & exit ) else ( echo  "OK" )
@echo on

::---------------------------------------------------
::�ڶ�������data ����STEP2_SERVER_DATA��
::---------------------------------------------------
::---------------------------------------------------
::        ��proto����STEP2_SERVER_PROTO��
::---------------------------------------------------
::---------------------------------------------------
::        ��py   ����STEP2_SERVER_PYTHON��
::---------------------------------------------------
::---------------------------------------------------
::        ��txt  ����STEP2_SERVER_JSON��
::---------------------------------------------------
@echo off

IF NOT EXIST "%STEP2_SERVER_DATA%" MD "%STEP2_SERVER_DATA%"
IF NOT EXIST "%STEP2_SERVER_PROTO%" MD "%STEP2_SERVER_PROTO%"
IF NOT EXIST "%STEP2_SERVER_PYTHON%" MD "%STEP2_SERVER_PYTHON%"
IF NOT EXIST "%STEP2_SERVER_JSON%" MD "%STEP2_SERVER_JSON%"

move *.data    %STEP2_SERVER_DATA%\
move *.proto   %STEP2_SERVER_PROTO%\
move *_pb2.py  %STEP2_SERVER_PYTHON%\
move *_pb2.pyc %STEP2_SERVER_PYTHON%\
move *.txt     %STEP2_SERVER_JSON%\
@echo on

::---------------------------------------------------
::��������������c++Դ����
::---------------------------------------------------

echo =========Compilation of Proto=========
call protoc.exe --cpp_out=.  %STEP2_SERVER_PROTO%\*.proto --proto_path=%STEP2_SERVER_PROTO%
@echo off
if  %errorlevel% LSS 0 ( echo  "Failed" & pause & exit ) else ( echo  "OK" )
@echo on
@echo off
IF NOT EXIST "%STEP2_SERVER_SRC%\proto" MD "%STEP2_SERVER_SRC%\proto"
move *.pb.cc %STEP2_SERVER_SRC%\proto\
move *.pb.h %STEP2_SERVER_SRC%\proto\
@echo on