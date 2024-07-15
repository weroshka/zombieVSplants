;  
#define   Name       "ZombieVsPlants"
;  
#define   Version    "1.0.0"
; -
#define   Publisher  "Veronika Kurtmullaeva"
;   
#define   URL        "http://www.vk.com/verosh_ka"
;   
#define   ExeName    "ZombieVsPlants.exe"

;------------------------------------------------------------------------------
;    
;------------------------------------------------------------------------------
[Setup]

;   , 
;  Tools -> Generate GUID
AppId={{EE311CC8-7EAC-45E2-8FB1-7C867046A470}

;  ,   
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

;   -
DefaultDirName={pf}\{#Name}
;     ""
DefaultGroupName={#Name}

; ,     setup    
OutputDir=C:\Git\Exam\installer\output
OutputBaseFileName=ZombieVsPlants

;  
SetupIconFile=C:\Git\Exam\img\icon32_1.ico

;  
Compression=lzma
SolidCompression=yes

;------------------------------------------------------------------------------
;       
;------------------------------------------------------------------------------
[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "License_ENG.txt"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

;------------------------------------------------------------------------------
;    -  ,     
;------------------------------------------------------------------------------
[Tasks]
;     
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

;------------------------------------------------------------------------------
;   ,      
;------------------------------------------------------------------------------
[Files]

;  
Source: "C:\Build\Exams\Release\ZombieVsPlants.exe"; DestDir: "{app}"; Flags: ignoreversion

;  
Source: "C:\Git\Exam\img\*"; DestDir: "{app}\img\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Git\Exam\fonts\*"; DestDir: "{app}\fonts\"; Flags: ignoreversion recursesubdirs createallsubdirs

; VS Redistributable package
Source: "C:\Git\Exam\installer\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
;------------------------------------------------------------------------------
;    ,     
;------------------------------------------------------------------------------ 
[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; Tasks: desktopicon

[Run]
;------------------------------------------------------------------------------
;      VS
;------------------------------------------------------------------------------
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait...
