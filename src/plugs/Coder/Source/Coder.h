#ifndef _CODER_H_
#define _CODER_H_


//// Common defines

#define STRID_PLUGIN                1
#define STRID_OK                    2
#define STRID_CANCEL                3
#define STRID_CLOSE                 4
#define STRID_ENABLE                5
#define STRID_GENERAL               11
#define STRID_CODER_NOTRUNNING      12
#define STRID_LOADFIRST             13
#define STRID_CACHE_ENABLE          51
#define STRID_DEFAULTALIAS_ENABLE   52
#define STRID_VARTHEME_NAME         53
#define STRID_VARTHEME_SAVE         54
#define STRID_VARTHEME_DELETE       55
#define STRID_VARTHEME_RETURN       56
#define STRID_VARTHEME_GLOBAL       57
#define STRID_VARTHEME_LINK         58
#define STRID_MENU_ADDITEM          59
#define STRID_MENU_MODITEM          60
#define STRID_MENU_MOVEUPITEM       61
#define STRID_MENU_MOVEDOWNITEM     62
#define STRID_MENU_DELITEM          63
#define STRID_MENU_CLEARITEM        64
#define STRID_VARIABLE              65
#define STRID_VALUE                 66
#define STRID_COLOR                 67
#define STRID_SYNTAXFILE            68
#define STRID_VARTHEMENAME          69
#define STRID_ADDVAR                70
#define STRID_EDITVAR               71
#define STRID_LOSTPROMPT            72
#define STRID_OVERWRITEPROMPT       73
#define STRID_DELETEPROMPT          74
#define STRID_VARMISSING            75
#define STRID_UNKNOWNSYNTAXFILE     76
#define STRID_UNKNOWNVARTHEME       77

#define DLLA_CODER_SETEXTENSION     1
#define DLLA_CODER_CLEARCACHE       2
#define DLLA_CODER_SETTINGS         3
#define DLLA_CODER_EXPORT           4
#define DLLA_CODER_SETVARTHEME      5
#define DLLA_CODER_SETALIAS         6
#define DLLA_CODER_CHECKALIAS       12
#define DLLA_CODER_CHECKVARTHEME    14
#define DLLA_CODER_GETSYNTAXFILE    16
#define DLLA_CODER_GETALIAS         18
#define DLLA_CODER_GETVARTHEME      20
#define DLLA_CODER_GETVARIABLE      22
#define DLLA_CODER_GETVARTHEMEDATA  24

#define OF_CLEAR                    0x001
#define OF_GENERAL_GLOBALTHEME      0x002
#define OF_GENERAL_ACTIVETHEME      0x004
#define OF_GENERAL_ALLTHEMES        0x008
#define OF_GENERAL_THEMELINK        0x010
#define OF_GENERAL_SETTINGS         0x020
#define OF_HIGHLIGHT_SETTINGS       0x040
#define OF_CODEFOLD_RECT            0x080
#define OF_CODEFOLD_SETTINGS        0x100
#define OF_AUTOCOMPLETE_RECT        0x200
#define OF_AUTOCOMPLETE_SETTINGS    0x400

#define OF_GENERAL      (OF_GENERAL_ALLTHEMES |\
                         OF_GENERAL_THEMELINK|\
                         OF_GENERAL_SETTINGS)
#define OF_HIGHLIGHT     OF_HIGHLIGHT_SETTINGS
#define OF_CODEFOLD     (OF_CODEFOLD_RECT |\
                         OF_CODEFOLD_SETTINGS)
#define OF_AUTOCOMPLETE (OF_AUTOCOMPLETE_RECT |\
                         OF_AUTOCOMPLETE_SETTINGS)

#define BUFFER_SIZE      1024

#define FIRST_NONLATIN   128

#ifndef IDI_ICON_MAIN
  #define IDI_ICON_MAIN 1001
#endif
#ifndef PROPSHEETHEADERA_V1_SIZE
  #define PROPSHEETHEADERA_V1_SIZE CCSIZEOF_STRUCT(PROPSHEETHEADERA, pfnCallback)
#endif
#ifndef PROPSHEETHEADERW_V1_SIZE
  #define PROPSHEETHEADERW_V1_SIZE CCSIZEOF_STRUCT(PROPSHEETHEADERW, pfnCallback)
#endif
#ifndef LVM_SETEXTENDEDLISTVIEWSTYLE
  #define LVM_SETEXTENDEDLISTVIEWSTYLE (LVM_FIRST + 54)
#endif
#ifndef LVS_EX_GRIDLINES
  #define LVS_EX_GRIDLINES 0x00000001
#endif
#ifndef LVS_EX_FULLROWSELECT
  #define LVS_EX_FULLROWSELECT 0x00000020
#endif

//Combobox edit ID
#define IDC_COMBOBOXEDIT       1001

#define PAGE_GENERAL       0
#define PAGE_HIGHLIGHT     1
#define PAGE_CODEFOLD1     2
#define PAGE_CODEFOLD2     3
#define PAGE_AUTOCOMPLETE  4

#define LVSI_LIST_VARIABLE  0
#define LVSI_LIST_VALUE     1
#define LVSI_LIST_COLOR     2

#define LVSI_LINK_SYNTAXFILE 0
#define LVSI_LINK_VARTHEME   1

//Save cache
#define SC_NONE        0x0
#define SC_SAVE        0x1
#define SC_CLEAR       0x2

#define CODER_HIGHLIGHT     0x01
#define CODER_CODEFOLD      0x02
#define CODER_AUTOCOMPLETE  0x04
#define CODER_ALL           (CODER_HIGHLIGHT   |\
                             CODER_CODEFOLD    |\
                             CODER_AUTOCOMPLETE)

//UpdateEdit flags
#define UE_ERASE        0x01
#define UE_ALLRECT      0x02
#define UE_DRAWRECT     0x04
#define UE_FIRSTPIXEL   0x08
#define UE_UPDATEWINDOW 0x10

//DLLA_CODER_EXPORT flags
#define HLEXP_FILE                 0x00000001  //Export to file.
#define HLEXP_COPY                 0x00000010  //Copy to clipboard.
#define HLEXP_COPYTEXT             0x00000020  //Fill plain-text format of clipboard with text. Must be combined with HLEXP_COPY.
#define HLEXP_COPYDATA             0x00000040  //Fill plain-text format of clipboard with formated data. Must be combined with HLEXP_COPY.
#define HLEXP_SELECTIONCOLOR       0x00000100  //Export text selection color.
#define HLEXP_ACTIVELINECOLOR      0x00000200  //Export active line colors.
#define HLEXP_ALTLINECOLOR         0x00000400  //Export alternating lines colors.
#define HLEXP_NOBASICTEXTCOLOR     0x00000800  //Don't export basic text color.
#define HLEXP_NOBASICBKCOLOR       0x00001000  //Don't export basic background color.
#define HLEXP_ONLYSELECTION        0x00010000  //Export only selected text. By default exported selection or all document if selection is empty.
#define HLEXP_ALLDOCUMENT          0x00020000  //Export all document. By default exported selection or all document if selection is empty.


//// Structures

typedef struct _RTFCOLORITEM {
  struct _RTFCOLORITEM *next;
  struct _RTFCOLORITEM *prev;
  DWORD dwColor;
  char szRGB[64];
  int nRGBLen;
} RTFCOLORITEM;

typedef struct {
  RTFCOLORITEM *first;
  RTFCOLORITEM *last;
  int nCount;
  int nTableLen;
} STACKRTFCOLOR;

typedef struct {
  char *szRtf;
  INT_PTR nRtfLen;
  STACKRTFCOLOR hColorStack;
  LOGFONTW lfFont;
  AECOLORS aec;
  int nPointSize;
  char szDefStyle[32];
  char szDefTextColor[32];
  char szDefBkColor[32];
  AECHARRANGE crRange;
  DWORD dwFlags;
} RTFDATA;

typedef struct _WILDCARDINFO {
  struct _WILDCARDINFO *next;
  struct _WILDCARDINFO *prev;
  wchar_t *wpWildcard;
  int nWildcardLen;
} WILDCARDINFO;

typedef struct {
  WILDCARDINFO *first;
  WILDCARDINFO *last;
} STACKWILDCARD;

typedef struct _DELIMITERINFO {
  struct _DELIMITERINFO *next;
  struct _DELIMITERINFO *prev;
  wchar_t *wpDelimiter;
  int nDelimiterLen;
  DWORD dwFlags;
  DWORD dwColor1;
  DWORD dwColor2;
  DWORD dwFontStyle;
} DELIMITERINFO;

typedef struct {
  DELIMITERINFO *first;
  DELIMITERINFO *last;
} STACKDELIM;

typedef struct _MANUALSET {
  struct _MANUALSET *next;
  struct _MANUALSET *prev;
  HWND hWndEdit;
  AEHDOC hDocEdit;
  wchar_t wszAlias[MAX_PATH];

  //User window
  DWORD dwDllFunction;
  HWND hWndParent;
  WNDPROC lpOldEditProc;
  WNDPROC lpOldParentProc;
  void *lpHighlightWindow; //Pointer to HIGHLIGHTWINDOW
  void *lpFoldWindow;      //Pointer to FOLDWINDOW
} MANUALSET;

typedef struct {
  INT_PTR first;
  INT_PTR last;
  INT_PTR lpWordLens[MAX_PATH];
} STACKWORD;

typedef struct {
  INT_PTR first;
  INT_PTR last;
} STACKQUOTE;

typedef struct {
  INT_PTR first;
  INT_PTR last;
} STACKSKIP;

typedef struct {
  INT_PTR first;
  INT_PTR last;
  int nCommonFirstChar;
} STACKFOLD;

typedef struct _VARINFO {
  struct _VARINFO *next;
  struct _VARINFO *prev;
  wchar_t *wpVarName;
  int nVarNameLen;
  wchar_t *wpVarValue;
  int nVarValueLen;
} VARINFO;

typedef struct {
  VARINFO *first;
  VARINFO *last;
} STACKVAR;

typedef struct _VARTHEME {
  struct _VARTHEME *next;
  struct _VARTHEME *prev;
  STACKVAR hVarStack;
  wchar_t wszVarThemeName[MAX_PATH];
  int nVarThemeNameLen;
  const wchar_t *wpTextData;
} VARTHEME;

typedef struct {
  VARTHEME *first;
  VARTHEME *last;
} STACKVARTHEME;

typedef struct _TITLEINFO {
  struct _TITLEINFO *next;
  struct _TITLEINFO *prev;
  wchar_t *wpTitle;
  int nTitleLen;
  BOOL bExactTitle;
} TITLEINFO;

typedef struct {
  TITLEINFO *first;
  TITLEINFO *last;
} STACKTITLE;

typedef struct _STACKBLOCK {
  INT_PTR first;
  INT_PTR last;
  INT_PTR lpSorted[FIRST_NONLATIN + 1];
} STACKBLOCK;

typedef struct _SYNTAXFILE {
  struct _SYNTAXFILE *next;
  struct _SYNTAXFILE *prev;
  STACKWILDCARD hWildcardStack;
  STACKDELIM hDelimiterStack;
  STACKWORD hWordStack;
  STACKQUOTE hQuoteStack;
  STACKSKIP hSkipStack;
  HSTACK hSkipStartStack;
  STACKFOLD hFoldStack;
  HSTACK hFoldStartStack;
  STACKTITLE hTitleStack;
  STACKBLOCK hBlockStack;
  STACKBLOCK hExactBlockStack;
  wchar_t wszSyntaxFileName[MAX_PATH];
  VARTHEME *lpVarThemeLink;
  HANDLE hThemeHighLight;
  DWORD dwFontFlags;
  LOGFONTW lfFont;
  AECOLORS aecColors;
  wchar_t wszBkImageFile[MAX_PATH];
  int nBkImageAlpha;
  DWORD dwAutoMarkFlags;
  DWORD dwAutoMarkFontStyle;
  DWORD dwAutoMarkTextColor;
  DWORD dwAutoMarkBkColor;
  DWORD dwPanelFirstBkColor;
  DWORD dwPanelSecondBkColor;
  DWORD dwPanelNormalFoldColor;
  DWORD dwPanelActiveFoldColor;
  DWORD dwPanelNormalNodeOpenBkColor;
  DWORD dwPanelNormalNodeCloseBkColor;
  DWORD dwPanelActiveNodeOpenBkColor;
  DWORD dwPanelActiveNodeCloseBkColor;
  DWORD dwPanelNormalNodeOpenSignColor;
  DWORD dwPanelNormalNodeCloseSignColor;
  DWORD dwPanelActiveNodeOpenSignColor;
  DWORD dwPanelActiveNodeCloseSignColor;
  DWORD dwListTextColor;
  DWORD dwListBkColor;
  DWORD dwTagMarkFlags;
  DWORD dwTagMarkFontStyle;
  DWORD dwTagMarkTextColor;
  DWORD dwTagMarkBkColor;
  BOOL bCache;
} SYNTAXFILE;


//// Functions prototypes

void ExportToRtf(HWND hWndEdit, DWORD dwFlags, wchar_t *wszRtfFile);
HANDLE GetRTF(HWND hWndEdit, AECHARRANGE *crRange, DWORD dwFlags, INT_PTR *lpnRtfLen);
DWORD CALLBACK GetHighLightCallback(UINT_PTR dwCookie, AECHARRANGE *crAkelRange, CHARRANGE64 *crRichRange, AEHLPAINT *hlp);
int StackInsertRTFColor(STACKRTFCOLOR *hStack, DWORD dwColor);
int StackGetRTFColor(STACKRTFCOLOR *hStack, DWORD dwColor);
void StackFreeRTFColors(STACKRTFCOLOR *hStack);
void SettingsSheet(int nStartPage);
LRESULT CALLBACK CBTProc(int iCode, WPARAM wParam, LPARAM lParam);
int CALLBACK PropSheetProc(HWND hDlg, UINT uMsg, LPARAM lParam);
BOOL CALLBACK GeneralSetupDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK GeneralVarEditDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK GeneralLinkDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK NewMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK NewFrameProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK NewUserParentProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ParentMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT *lResult);
LRESULT CALLBACK NewEditProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK NewUserEditProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK EditMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT *lResult);
SYNTAXFILE* StackLoadSyntaxFile(HSTACK *hStack, SYNTAXFILE *lpSyntaxFile);
void StackRequestSyntaxFile(SYNTAXFILE *lpSyntaxFile);
SYNTAXFILE* StackAddSyntaxFile(HSTACK *hStack, const wchar_t *wpFile);
SYNTAXFILE* StackPushSortSyntaxFile(HSTACK *hStack, const wchar_t *wpFile, int nUpDown);
SYNTAXFILE* StackGetSyntaxFileByFile(HSTACK *hStack, const wchar_t *wpFile);
SYNTAXFILE* StackGetSyntaxFileByName(HSTACK *hStack, const wchar_t *wpSyntaxFileName);
SYNTAXFILE* StackGetSyntaxFileByTheme(HSTACK *hStack, HANDLE hTheme);
SYNTAXFILE* StackGetSyntaxFileByIndex(HSTACK *hStack, int nIndex);
SYNTAXFILE* StackGetSyntaxFileByWindow(HSTACK *hStack, HWND hWnd, AEHDOC hDoc, const wchar_t **wppAlias);
void StackFreeSyntaxFiles(HSTACK *hStack);
WILDCARDINFO* StackInsertWildcard(STACKWILDCARD *hStack, int nWildcardLen);
WILDCARDINFO* StackGetWildcard(STACKWILDCARD *hStack, const wchar_t *wpFile);
void StackFreeWildcard(STACKWILDCARD *hStack);
DELIMITERINFO* StackInsertDelimiter(STACKDELIM *hStack, int nDelimiterLen);
DELIMITERINFO* StackGetDelimiter(STACKDELIM *hStack, wchar_t wchDelimiter);
void StackFreeDelimiter(STACKDELIM *hStack);
BOOL IsInDelimiterList(const wchar_t *s, wchar_t c);
BOOL IsDelimiter(STACKDELIM *hDelimiterStack, HWND hWnd, int nChar);
BOOL IsDelimiterFromLeft(STACKDELIM *hDelimiterStack, HWND hWnd, const AECHARINDEX *ciChar);
BOOL IsDelimiterFromRight(STACKDELIM *hDelimiterStack, HWND hWnd, const AECHARINDEX *ciChar);
MANUALSET* StackInsertManual(HSTACK *hStack);
MANUALSET* StackGetManual(HSTACK *hStack, HWND hWndMaster, AEHDOC hDocMaster);
MANUALSET* StackGetManualByUserParent(HSTACK *hStack, HWND hWndParent);
void StackDeleteManual(HSTACK *hStack, MANUALSET *lpManual, DWORD dwDllFunction);

VARTHEME* StackInsertVarTheme(STACKVARTHEME *hStack, int nIndex);
VARTHEME* StackGetVarThemeByName(STACKVARTHEME *hStack, const wchar_t *wpVarThemeName);
VARTHEME* StackGetVarThemeByIndex(STACKVARTHEME *hStack, int nIndex);
int StackGetVarThemeIndex(STACKVARTHEME *hStack, VARTHEME *lpVarTheme);
void StackMoveVarTheme(STACKVARTHEME *hStack, VARTHEME *lpVarTheme, int nIndex);
void StackDeleteVarTheme(STACKVARTHEME *hStack, VARTHEME *lpVarTheme);
void StackFreeVarThemes(STACKVARTHEME *hStack);
void AddInternalVarThemes(STACKVARTHEME *hStack);
VARTHEME* RequestVarTheme(STACKVARTHEME *hStack, const wchar_t *wpVarThemeName);
void GetVarThemeGlobals(VARTHEME *lpVarTheme);
int FillVarThemeList(HWND hWnd, VARTHEME *lpVarTheme);
int RetriveVarThemeList(HWND hWnd, VARTHEME *lpVarTheme);
VARINFO* StackInsertVar(STACKVAR *hStack);
VARINFO* StackGetVarByName(STACKVAR *hStack, const wchar_t *wpVarName, int nVarNameLen);
VARINFO* StackGetVarByIndex(STACKVAR *hStack, int nIndex);
void StackFreeVars(STACKVAR *hStack);
int ParseStringToVars(STACKVAR *lpVarStack, const wchar_t *wpText);
DWORD ParseVarsToString(STACKVAR *lpVarStack, wchar_t **wpText);

int GetWord(wchar_t *wpText, wchar_t *wszWord, int nWordLenMax, wchar_t **wpNextWord, BOOL *bQuote, STACKVAR *lpVarStack);
INT_PTR ExpandVars(const wchar_t *wpString, INT_PTR nStringLen, wchar_t *wszBuffer, INT_PTR nBufferSize, STACKVAR *lpVarStack);
BOOL NextLine(wchar_t **wpText);
BOOL SkipComment(wchar_t **wpText);
BOOL FileMaskCmp(const wchar_t *wpMaskStr, const wchar_t *wpFileStr);
const wchar_t* GetFileName(const wchar_t *wpFile, int nFileLen);
int GetBaseName(const wchar_t *wpFile, wchar_t *wszBaseName, int nBaseNameMaxLen);
HWND GetCurEdit();
HWND GetFocusEdit();
void UpdateEdit(HWND hWnd, DWORD dwFlags);
void UpdateEditAndClones(HWND hWnd, DWORD dwFlags);
void UpdateEditAll(DWORD dwFlags);
BOOL SelectColorDialog(HWND hWndOwner, COLORREF *crColor);
void GetPosFromChar(HWND hWnd, INT_PTR nCharIndex, POINT *pt);

void ReadSyntaxFiles();
void SaveCache(DWORD dwFlags);
void ClearCache(BOOL bForceNewCache);
void UpdateAllOptions();
INT_PTR WideOption(HANDLE hOptions, const wchar_t *pOptionName, DWORD dwType, BYTE *lpData, DWORD dwData);
void ReadOptions(DWORD dwFlags);
void SaveOptions(DWORD dwFlags);
const char* GetLangStringA(LANGID wLangID, int nStringID);
const wchar_t* GetLangStringW(LANGID wLangID, int nStringID);
BOOL IsExtCallParamValid(LPARAM lParam, int nIndex);
INT_PTR GetExtCallParam(LPARAM lParam, int nIndex);
void InitCommon(PLUGINDATA *pd);
void InitMain();
void UninitMain();


//// Global variables

extern char szBuffer[BUFFER_SIZE];
extern wchar_t wszBuffer[BUFFER_SIZE];
extern wchar_t wszPluginName[MAX_PATH];
extern HINSTANCE hInstanceDLL;
extern HWND hMainWnd;
extern HWND hWndEdit;
extern HWND hMdiClient;
extern HICON hMainIcon;
extern BOOL bOldWindows;
extern BOOL bOldRichEdit;
extern BOOL bAkelEdit;
extern int nMDI;
extern LANGID wLangModule;
extern BOOL bInitCommon;
extern int nInitMain;
extern DWORD dwSaveFlags;
extern BOOL bInitHighLight;
extern int nInitCodeFold;
extern BOOL bInitAutoComplete;
extern BOOL bUseCache;
extern BOOL bSaveCache;
extern HSTACK hSyntaxFilesStack;
extern HSTACK hManualStack;
extern STACKVARTHEME hVarThemesStack;
extern VARTHEME *lpVarThemeActive;
extern WNDPROCDATA *NewMainProcData;
extern WNDPROCDATA *NewFrameProcData;
extern WNDPROCDATA *NewEditProcData;
extern HWND hWndPropSheet;
extern int nPropMaxVisitPage;
extern BOOL bSaveOptions;


//// Themes

//Default variable theme
#define TXT_DEFAULT_VARTHEME_BASIC \
L"STR #808080\r\
COMM #008000\r\
VAR #800000\r\
DEL1 #CC3333\r\
DEL2 0\r\
TYPE #3333CC\r\
OP #3333CC\r\
TAG #3333CC\r\
ATTR #339933\r\
IF #339933\r\
AREA #FF8000\r\
NUM #FF8000\r"

#define TXT_DEFAULT_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor 0\r\
HighLight_BasicBkColor 0\r\
HighLight_SelTextColor 0\r\
HighLight_SelBkColor 0\r\
HighLight_LineTextColor 0\r\
HighLight_LineBkColor 0\r\
HighLight_LineBorderColor 0\r\
HighLight_AltTextColor 0\r\
HighLight_AltBkColor 0\r\
HighLight_AltBorderColor 0\r\
HighLight_ColumnColor 0\r\
HighLight_MarkerColor 0\r\
HighLight_CaretColor 0\r\
HighLight_UrlColor 0\r\
HighLight_ActiveUrlColor 0\r\
HighLight_VisitUrlColor 0\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #000000\r\
HighLight_AutoMarkBkColor #75D975\r"

#define TXT_DEFAULT_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #FFFFFF\r\
CodeFold_PanelSecondBkColor #E9E9E9\r\
CodeFold_PanelNormalFoldColor #808080\r\
CodeFold_PanelActiveFoldColor #0000FF\r\
CodeFold_PanelNormalNodeOpenBkColor 0\r\
CodeFold_PanelNormalNodeCloseBkColor 0\r\
CodeFold_PanelActiveNodeOpenBkColor 0\r\
CodeFold_PanelActiveNodeCloseBkColor 0\r\
CodeFold_PanelNormalNodeOpenSignColor 0\r\
CodeFold_PanelNormalNodeCloseSignColor 0\r\
CodeFold_PanelActiveNodeOpenSignColor 0\r\
CodeFold_PanelActiveNodeCloseSignColor 0\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 2\r\
CodeFold_TagMarkTextColor 0\r\
CodeFold_TagMarkBkColor #E3CCFF\r"

#define TXT_DEFAULT_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_DEFAULT_VARTHEME_LINEBOARD \
L"LineBoard_TextColor 0\r\
LineBoard_BkColor 0\r\
LineBoard_BorderColor 0\r\
LineBoard_BookmarkTextColor 0\r\
LineBoard_BookmarkBkColor 0\r\
LineBoard_BookmarkBorderColor 0\r\
LineBoard_LineUnsavedColor 0\r\
LineBoard_LineSavedColor 0\r"

#define TXT_DEFAULT_VARTHEME (TXT_DEFAULT_VARTHEME_BASIC TXT_DEFAULT_VARTHEME_HIGHLIGHT TXT_DEFAULT_VARTHEME_CODEFOLD TXT_DEFAULT_VARTHEME_AUTOCOMPLETE TXT_DEFAULT_VARTHEME_LINEBOARD)

//Active4D variable theme
#define TXT_ACTIVE4D_VARTHEME_BASIC \
L"STR #666666\r\
COMM #D33435\r\
VAR #0053FF\r\
DEL1 #7A7A7A\r\
DEL2 #000000\r\
TYPE #B7734C\r\
OP #45AE34\r\
TAG #016CFF\r\
ATTR #963DFF\r\
IF #006699\r\
AREA #317B24\r\
NUM #A8017E\r"

#define TXT_ACTIVE4D_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #000000\r\
HighLight_BasicBkColor #FFFFFF\r\
HighLight_SelTextColor #000000\r\
HighLight_SelBkColor #A5B0A2\r\
HighLight_LineTextColor #000000\r\
HighLight_LineBkColor #EBEBEB\r\
HighLight_LineBorderColor #E1E1E1\r\
HighLight_AltTextColor #000000\r\
HighLight_AltBkColor #F7F7F7\r\
HighLight_AltBorderColor #F2F2F2\r\
HighLight_ColumnColor #7A7A7A\r\
HighLight_MarkerColor #7A7A7A\r\
HighLight_CaretColor #000000\r\
HighLight_UrlColor #0079FF\r\
HighLight_ActiveUrlColor #0083AE\r\
HighLight_VisitUrlColor #0083AE\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #000000\r\
HighLight_AutoMarkBkColor #8DFF51\r"

#define TXT_ACTIVE4D_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #FFFFFF\r\
CodeFold_PanelSecondBkColor #FFFFFF\r\
CodeFold_PanelNormalFoldColor #7A7A7A\r\
CodeFold_PanelActiveFoldColor #000000\r\
CodeFold_PanelNormalNodeOpenBkColor #FFFFFF\r\
CodeFold_PanelNormalNodeCloseBkColor #7A7A7A\r\
CodeFold_PanelActiveNodeOpenBkColor #FFFFFF\r\
CodeFold_PanelActiveNodeCloseBkColor #000000\r\
CodeFold_PanelNormalNodeOpenSignColor #7A7A7A\r\
CodeFold_PanelNormalNodeCloseSignColor #FFFFFF\r\
CodeFold_PanelActiveNodeOpenSignColor #000000\r\
CodeFold_PanelActiveNodeCloseSignColor #FFFFFF\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #FFFFFF\r\
CodeFold_TagMarkBkColor #2FB1FF\r"

#define TXT_ACTIVE4D_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_ACTIVE4D_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #000000\r\
LineBoard_BkColor #EBEBEB\r\
LineBoard_BorderColor #FFFFFF\r\
LineBoard_BookmarkTextColor #FFFFFF\r\
LineBoard_BookmarkBkColor #666666\r\
LineBoard_BookmarkBorderColor #EBEBEB\r\
LineBoard_LineUnsavedColor #DBCD28\r\
LineBoard_LineSavedColor #50CF30\r"

#define TXT_ACTIVE4D_VARTHEME (TXT_ACTIVE4D_VARTHEME_BASIC TXT_ACTIVE4D_VARTHEME_HIGHLIGHT TXT_ACTIVE4D_VARTHEME_CODEFOLD TXT_ACTIVE4D_VARTHEME_AUTOCOMPLETE TXT_ACTIVE4D_VARTHEME_LINEBOARD)

//Bespin variable theme
#define TXT_BESPIN_VARTHEME_BASIC \
L"STR #80FF80\r\
COMM #707070\r\
VAR #FFFFFF\r\
DEL1 #A6DEFF\r\
DEL2 #FFAA00\r\
TYPE #FFAA00\r\
OP #37A8ED\r\
TAG #37A8ED\r\
ATTR #E5C138\r\
IF #F6F080\r\
AREA #55E439\r\
NUM #FF3A83\r"

#define TXT_BESPIN_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #E8E2DD\r\
HighLight_BasicBkColor #2B211C\r\
HighLight_SelTextColor #FFFFFF\r\
HighLight_SelBkColor #846759\r\
HighLight_LineTextColor #FFFFFF\r\
HighLight_LineBkColor #4B3D34\r\
HighLight_LineBorderColor #54443A\r\
HighLight_AltTextColor #E8E2DD\r\
HighLight_AltBkColor #281F1A\r\
HighLight_AltBorderColor #251D18\r\
HighLight_ColumnColor #656565\r\
HighLight_MarkerColor #656565\r\
HighLight_CaretColor #91EAB9\r\
HighLight_UrlColor #66C6FF\r\
HighLight_ActiveUrlColor #82EFFF\r\
HighLight_VisitUrlColor #82EFFF\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #FFFFFF\r\
HighLight_AutoMarkBkColor #FF0080\r"

#define TXT_BESPIN_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #2B211C\r\
CodeFold_PanelSecondBkColor #2B211C\r\
CodeFold_PanelNormalFoldColor #494949\r\
CodeFold_PanelActiveFoldColor #808080\r\
CodeFold_PanelNormalNodeOpenBkColor #494949\r\
CodeFold_PanelNormalNodeCloseBkColor #494949\r\
CodeFold_PanelActiveNodeOpenBkColor #808080\r\
CodeFold_PanelActiveNodeCloseBkColor #808080\r\
CodeFold_PanelNormalNodeOpenSignColor #808080\r\
CodeFold_PanelNormalNodeCloseSignColor #C0C0C0\r\
CodeFold_PanelActiveNodeOpenSignColor #000000\r\
CodeFold_PanelActiveNodeCloseSignColor #FFFFFF\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #FFFFFF\r\
CodeFold_TagMarkBkColor #605620\r"

#define TXT_BESPIN_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_BESPIN_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #E8E2DD\r\
LineBoard_BkColor #4B3D34\r\
LineBoard_BorderColor #2B211C\r\
LineBoard_BookmarkTextColor #2B211C\r\
LineBoard_BookmarkBkColor #E8E2DD\r\
LineBoard_BookmarkBorderColor #4B3D34\r\
LineBoard_LineUnsavedColor #F6F080\r\
LineBoard_LineSavedColor #80FF80\r"

#define TXT_BESPIN_VARTHEME (TXT_BESPIN_VARTHEME_BASIC TXT_BESPIN_VARTHEME_HIGHLIGHT TXT_BESPIN_VARTHEME_CODEFOLD TXT_BESPIN_VARTHEME_AUTOCOMPLETE TXT_BESPIN_VARTHEME_LINEBOARD)

//Cobalt variable theme
#define TXT_COBALT_VARTHEME_BASIC \
L"STR #3AD900\r\
COMM #0088FF\r\
VAR #E1EFFF\r\
DEL1 #E1EFFF\r\
DEL2 #FF9D00\r\
TYPE #FFAA00\r\
OP #FFEE80\r\
TAG #9EFFFF\r\
ATTR #9EFFFF\r\
IF #FF9D00\r\
AREA #9DF39F\r\
NUM #FF628C\r"

#define TXT_COBALT_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #FFFFFF\r\
HighLight_BasicBkColor #002240\r\
HighLight_SelTextColor #FFFFFF\r\
HighLight_SelBkColor #86543A\r\
HighLight_LineTextColor #FFFFFF\r\
HighLight_LineBkColor #001629\r\
HighLight_LineBorderColor #001122\r\
HighLight_AltTextColor #FFFFFF\r\
HighLight_AltBkColor #001F3C\r\
HighLight_AltBorderColor #001D37\r\
HighLight_ColumnColor #656565\r\
HighLight_MarkerColor #656565\r\
HighLight_CaretColor #91EAB9\r\
HighLight_UrlColor #66C6FF\r\
HighLight_ActiveUrlColor #B9E4FF\r\
HighLight_VisitUrlColor #B9E4FF\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #FFFFFF\r\
HighLight_AutoMarkBkColor #4000FF\r"

#define TXT_COBALT_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #002240\r\
CodeFold_PanelSecondBkColor #002240\r\
CodeFold_PanelNormalFoldColor #47545F\r\
CodeFold_PanelActiveFoldColor #7F909F\r\
CodeFold_PanelNormalNodeOpenBkColor #47545F\r\
CodeFold_PanelNormalNodeCloseBkColor #47545F\r\
CodeFold_PanelActiveNodeOpenBkColor #7F909F\r\
CodeFold_PanelActiveNodeCloseBkColor #7F909F\r\
CodeFold_PanelNormalNodeOpenSignColor #7F909F\r\
CodeFold_PanelNormalNodeCloseSignColor #C2CAD1\r\
CodeFold_PanelActiveNodeOpenSignColor #030405\r\
CodeFold_PanelActiveNodeCloseSignColor #FFFFFF\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #FFFFFF\r\
CodeFold_TagMarkBkColor #433B3D\r"

#define TXT_COBALT_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_COBALT_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #FFFFFF\r\
LineBoard_BkColor #001629\r\
LineBoard_BorderColor #002240\r\
LineBoard_BookmarkTextColor #002240\r\
LineBoard_BookmarkBkColor #E1EFFF\r\
LineBoard_BookmarkBorderColor #001629\r\
LineBoard_LineUnsavedColor #FF9D00\r\
LineBoard_LineSavedColor #3AD900\r"

#define TXT_COBALT_VARTHEME (TXT_COBALT_VARTHEME_BASIC TXT_COBALT_VARTHEME_HIGHLIGHT TXT_COBALT_VARTHEME_CODEFOLD TXT_COBALT_VARTHEME_AUTOCOMPLETE TXT_COBALT_VARTHEME_LINEBOARD)

//Dawn variable theme
#define TXT_DAWN_VARTHEME_BASIC \
L"STR #0B6125\r\
COMM #5A525F\r\
VAR #080808\r\
DEL1 #080808\r\
DEL2 #794938\r\
TYPE #691C97\r\
OP #BF4F24\r\
TAG #BF4F24\r\
ATTR #A71D5D\r\
IF #794938\r\
AREA #5A525F\r\
NUM #811F24\r"

#define TXT_DAWN_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #080808\r\
HighLight_BasicBkColor #F9F9F9\r\
HighLight_SelTextColor #080808\r\
HighLight_SelBkColor #B9CAFA\r\
HighLight_LineTextColor #080808\r\
HighLight_LineBkColor #DFE6F0\r\
HighLight_LineBorderColor #D7DFEC\r\
HighLight_AltTextColor #080808\r\
HighLight_AltBkColor #F4F4F4\r\
HighLight_AltBorderColor #EFEFEF\r\
HighLight_ColumnColor #7C7C7C\r\
HighLight_MarkerColor #7C7C7C\r\
HighLight_CaretColor #080808\r\
HighLight_UrlColor #0FA5FF\r\
HighLight_ActiveUrlColor #6B40FF\r\
HighLight_VisitUrlColor #6B40FF\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #080808\r\
HighLight_AutoMarkBkColor #DAFFB5\r"

#define TXT_DAWN_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #F9F9F9\r\
CodeFold_PanelSecondBkColor #F9F9F9\r\
CodeFold_PanelNormalFoldColor #808080\r\
CodeFold_PanelActiveFoldColor #080808\r\
CodeFold_PanelNormalNodeOpenBkColor #F9F9F9\r\
CodeFold_PanelNormalNodeCloseBkColor #808080\r\
CodeFold_PanelActiveNodeOpenBkColor #F9F9F9\r\
CodeFold_PanelActiveNodeCloseBkColor #080808\r\
CodeFold_PanelNormalNodeOpenSignColor #808080\r\
CodeFold_PanelNormalNodeCloseSignColor #F9F9F9\r\
CodeFold_PanelActiveNodeOpenSignColor #080808\r\
CodeFold_PanelActiveNodeCloseSignColor #F9F9F9\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #080808\r\
CodeFold_TagMarkBkColor #BAE2FA\r"

#define TXT_DAWN_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_DAWN_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #080808\r\
LineBoard_BkColor #E7E7E7\r\
LineBoard_BorderColor #F9F9F9\r\
LineBoard_BookmarkTextColor #F9F9F9\r\
LineBoard_BookmarkBkColor #7A7A7A\r\
LineBoard_BookmarkBorderColor #DFE6F0\r\
LineBoard_LineUnsavedColor #D35727\r\
LineBoard_LineSavedColor #108B35\r"

#define TXT_DAWN_VARTHEME (TXT_DAWN_VARTHEME_BASIC TXT_DAWN_VARTHEME_HIGHLIGHT TXT_DAWN_VARTHEME_CODEFOLD TXT_DAWN_VARTHEME_AUTOCOMPLETE TXT_DAWN_VARTHEME_LINEBOARD)

//Earth variable theme
#define TXT_EARTH_VARTHEME_BASIC \
L"STR #CC7800\r\
COMM #748AB0\r\
VAR #6D3206\r\
DEL1 #000000\r\
DEL2 #000000\r\
TYPE #3B5BB5\r\
OP #07377E\r\
TAG #0A267C\r\
ATTR #000000\r\
IF #0A327C\r\
AREA #748AB0\r\
NUM #3B5BB5\r"

#define TXT_EARTH_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #000000\r\
HighLight_BasicBkColor #FFFFFF\r\
HighLight_SelTextColor #000000\r\
HighLight_SelBkColor #B5CCE3\r\
HighLight_LineTextColor #000000\r\
HighLight_LineBkColor #F1F1DA\r\
HighLight_LineBorderColor #EDEDCD\r\
HighLight_AltTextColor #000000\r\
HighLight_AltBkColor #FAFAFA\r\
HighLight_AltBorderColor #F4F4F4\r\
HighLight_ColumnColor #7C7C7C\r\
HighLight_MarkerColor #7C7C7C\r\
HighLight_CaretColor #000000\r\
HighLight_UrlColor #0A0A7C\r\
HighLight_ActiveUrlColor #4A4AF0\r\
HighLight_VisitUrlColor #4A4AF0\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #000000\r\
HighLight_AutoMarkBkColor #C0FF97\r"

#define TXT_EARTH_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #FFFFFF\r\
CodeFold_PanelSecondBkColor #FFFFFF\r\
CodeFold_PanelNormalFoldColor #7F7F7F\r\
CodeFold_PanelActiveFoldColor #000000\r\
CodeFold_PanelNormalNodeOpenBkColor #FFFFFF\r\
CodeFold_PanelNormalNodeCloseBkColor #7F7F7F\r\
CodeFold_PanelActiveNodeOpenBkColor #FFFFFF\r\
CodeFold_PanelActiveNodeCloseBkColor #000000\r\
CodeFold_PanelNormalNodeOpenSignColor #7F7F7F\r\
CodeFold_PanelNormalNodeCloseSignColor #FFFFFF\r\
CodeFold_PanelActiveNodeOpenSignColor #000000\r\
CodeFold_PanelActiveNodeCloseSignColor #FFFFFF\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #000000\r\
CodeFold_TagMarkBkColor #B0EAFF\r"

#define TXT_EARTH_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_EARTH_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #000000\r\
LineBoard_BkColor #E5E5E5\r\
LineBoard_BorderColor #FFFFFF\r\
LineBoard_BookmarkTextColor #FFFFFF\r\
LineBoard_BookmarkBkColor #747474\r\
LineBoard_BookmarkBorderColor #F1F1DA\r\
LineBoard_LineUnsavedColor #CC7800\r\
LineBoard_LineSavedColor #2FB900\r"

#define TXT_EARTH_VARTHEME (TXT_EARTH_VARTHEME_BASIC TXT_EARTH_VARTHEME_HIGHLIGHT TXT_EARTH_VARTHEME_CODEFOLD TXT_EARTH_VARTHEME_AUTOCOMPLETE TXT_EARTH_VARTHEME_LINEBOARD)

//iPlastic variable theme
#define TXT_IPLASTIC_VARTHEME_BASIC \
L"STR #009933\r\
COMM #0066FF\r\
VAR #000000\r\
DEL1 #0033CC\r\
DEL2 #0000FF\r\
TYPE #9700CC\r\
OP #1A00FF\r\
TAG #0033CC\r\
ATTR #3366CC\r\
IF #0000FF\r\
AREA #748AB0\r\
NUM #0066FF\r"

#define TXT_IPLASTIC_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #000000\r\
HighLight_BasicBkColor #EEEEEE\r\
HighLight_SelTextColor #000000\r\
HighLight_SelBkColor #BAD6FD\r\
HighLight_LineTextColor #000000\r\
HighLight_LineBkColor #DFDFDF\r\
HighLight_LineBorderColor #DADADA\r\
HighLight_AltTextColor #000000\r\
HighLight_AltBkColor #F2F2F2\r\
HighLight_AltBorderColor #E9E9E9\r\
HighLight_ColumnColor #777777\r\
HighLight_MarkerColor #777777\r\
HighLight_CaretColor #000000\r\
HighLight_UrlColor #004DCC\r\
HighLight_ActiveUrlColor #0D68FF\r\
HighLight_VisitUrlColor #0D68FF\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #EEEEEE\r\
HighLight_AutoMarkBkColor #FF0080\r"

#define TXT_IPLASTIC_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #EEEEEE\r\
CodeFold_PanelSecondBkColor #EEEEEE\r\
CodeFold_PanelNormalFoldColor #777777\r\
CodeFold_PanelActiveFoldColor #000000\r\
CodeFold_PanelNormalNodeOpenBkColor #EEEEEE\r\
CodeFold_PanelNormalNodeCloseBkColor #777777\r\
CodeFold_PanelActiveNodeOpenBkColor #EEEEEE\r\
CodeFold_PanelActiveNodeCloseBkColor #000000\r\
CodeFold_PanelNormalNodeOpenSignColor #777777\r\
CodeFold_PanelNormalNodeCloseSignColor #EEEEEE\r\
CodeFold_PanelActiveNodeOpenSignColor #000000\r\
CodeFold_PanelActiveNodeCloseSignColor #EEEEEE\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #000000\r\
CodeFold_TagMarkBkColor #D4E2F5\r"

#define TXT_IPLASTIC_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_IPLASTIC_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #000000\r\
LineBoard_BkColor #DFDFDF\r\
LineBoard_BorderColor #EEEEEE\r\
LineBoard_BookmarkTextColor #EEEEEE\r\
LineBoard_BookmarkBkColor #777777\r\
LineBoard_BookmarkBorderColor #DFDFDF\r\
LineBoard_LineUnsavedColor #EC9900\r\
LineBoard_LineSavedColor #009933\r"

#define TXT_IPLASTIC_VARTHEME (TXT_IPLASTIC_VARTHEME_BASIC TXT_IPLASTIC_VARTHEME_HIGHLIGHT TXT_IPLASTIC_VARTHEME_CODEFOLD TXT_IPLASTIC_VARTHEME_AUTOCOMPLETE TXT_IPLASTIC_VARTHEME_LINEBOARD)

//Lazy variable theme
#define TXT_LAZY_VARTHEME_BASIC \
L"STR #409B1C\r\
COMM #8C868F\r\
VAR #000000\r\
DEL1 #3A4A64\r\
DEL2 #FF7800\r\
TYPE #3B5BB5\r\
OP #3A4A64\r\
TAG #416476\r\
ATTR #384965\r\
IF #FF7800\r\
AREA #8C868F\r\
NUM #3B5BB5\r"

#define TXT_LAZY_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #000000\r\
HighLight_BasicBkColor #FFFFFF\r\
HighLight_SelTextColor #000000\r\
HighLight_SelBkColor #E3FC8D\r\
HighLight_LineTextColor #000000\r\
HighLight_LineBkColor #F6FDCD\r\
HighLight_LineBorderColor #F1FEB6\r\
HighLight_AltTextColor #000000\r\
HighLight_AltBkColor #F7F7F7\r\
HighLight_AltBorderColor #F3F3F3\r\
HighLight_ColumnColor #7C7C7C\r\
HighLight_MarkerColor #7C7C7C\r\
HighLight_CaretColor #000000\r\
HighLight_UrlColor #0080FF\r\
HighLight_ActiveUrlColor #005AE1\r\
HighLight_VisitUrlColor #005AE1\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #000000\r\
HighLight_AutoMarkBkColor #FCF98D\r"

#define TXT_LAZY_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #FFFFFF\r\
CodeFold_PanelSecondBkColor #FFFFFF\r\
CodeFold_PanelNormalFoldColor #7F7F7F\r\
CodeFold_PanelActiveFoldColor #000000\r\
CodeFold_PanelNormalNodeOpenBkColor #FFFFFF\r\
CodeFold_PanelNormalNodeCloseBkColor #7F7F7F\r\
CodeFold_PanelActiveNodeOpenBkColor #FFFFFF\r\
CodeFold_PanelActiveNodeCloseBkColor #000000\r\
CodeFold_PanelNormalNodeOpenSignColor #7F7F7F\r\
CodeFold_PanelNormalNodeCloseSignColor #FFFFFF\r\
CodeFold_PanelActiveNodeOpenSignColor #000000\r\
CodeFold_PanelActiveNodeCloseSignColor #FFFFFF\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #000000\r\
CodeFold_TagMarkBkColor #FAD872\r"

#define TXT_LAZY_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_LAZY_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #000000\r\
LineBoard_BkColor #E5E5E5\r\
LineBoard_BorderColor #FFFFFF\r\
LineBoard_BookmarkTextColor #FFFFFF\r\
LineBoard_BookmarkBkColor #A0A0A0\r\
LineBoard_BookmarkBorderColor #E5E5E5\r\
LineBoard_LineUnsavedColor #FF7800\r\
LineBoard_LineSavedColor #409B1C\r"

#define TXT_LAZY_VARTHEME (TXT_LAZY_VARTHEME_BASIC TXT_LAZY_VARTHEME_HIGHLIGHT TXT_LAZY_VARTHEME_CODEFOLD TXT_LAZY_VARTHEME_AUTOCOMPLETE TXT_LAZY_VARTHEME_LINEBOARD)

//Mac Classic variable theme
#define TXT_MACCLASSIC_VARTHEME_BASIC \
L"STR #036A07\r\
COMM #0066FF\r\
VAR #000000\r\
DEL1 #1C02FF\r\
DEL2 #687687\r\
TYPE #585CF6\r\
OP #1A00FF\r\
TAG #0A267C\r\
ATTR #1C02FF\r\
IF #0000FF\r\
AREA #748AB0\r\
NUM #0000CD\r"

#define TXT_MACCLASSIC_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #000000\r\
HighLight_BasicBkColor #FFFFFF\r\
HighLight_SelTextColor #000000\r\
HighLight_SelBkColor #C4DCFF\r\
HighLight_LineTextColor #000000\r\
HighLight_LineBkColor #ECECEC\r\
HighLight_LineBorderColor #E7E7E7\r\
HighLight_AltTextColor #000000\r\
HighLight_AltBkColor #F8F8F8\r\
HighLight_AltBorderColor #F4F4F4\r\
HighLight_ColumnColor #7C7C7C\r\
HighLight_MarkerColor #7C7C7C\r\
HighLight_CaretColor #000000\r\
HighLight_UrlColor #0A0A7C\r\
HighLight_ActiveUrlColor #1212DE\r\
HighLight_VisitUrlColor #1212DE\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #000000\r\
HighLight_AutoMarkBkColor #95DAFF\r"

#define TXT_MACCLASSIC_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #FFFFFF\r\
CodeFold_PanelSecondBkColor #FFFFFF\r\
CodeFold_PanelNormalFoldColor #7F7F7F\r\
CodeFold_PanelActiveFoldColor #000000\r\
CodeFold_PanelNormalNodeOpenBkColor #FFFFFF\r\
CodeFold_PanelNormalNodeCloseBkColor #7F7F7F\r\
CodeFold_PanelActiveNodeOpenBkColor #FFFFFF\r\
CodeFold_PanelActiveNodeCloseBkColor #000000\r\
CodeFold_PanelNormalNodeOpenSignColor #7F7F7F\r\
CodeFold_PanelNormalNodeCloseSignColor #FFFFFF\r\
CodeFold_PanelActiveNodeOpenSignColor #000000\r\
CodeFold_PanelActiveNodeCloseSignColor #FFFFFF\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #000000\r\
CodeFold_TagMarkBkColor #D8FF95\r"

#define TXT_MACCLASSIC_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_MACCLASSIC_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #000000\r\
LineBoard_BkColor #ECECEC\r\
LineBoard_BorderColor #FFFFFF\r\
LineBoard_BookmarkTextColor #FFFFFF\r\
LineBoard_BookmarkBkColor #7C7C7C\r\
LineBoard_BookmarkBorderColor #ECECEC\r\
LineBoard_LineUnsavedColor #FDA91E\r\
LineBoard_LineSavedColor #04D20F\r"

#define TXT_MACCLASSIC_VARTHEME (TXT_MACCLASSIC_VARTHEME_BASIC TXT_MACCLASSIC_VARTHEME_HIGHLIGHT TXT_MACCLASSIC_VARTHEME_CODEFOLD TXT_MACCLASSIC_VARTHEME_AUTOCOMPLETE TXT_MACCLASSIC_VARTHEME_LINEBOARD)

//Monokai variable theme
#define TXT_MONOKAI_VARTHEME_BASIC \
L"STR #E6DB74\r\
COMM #75715E\r\
VAR #A6E22E\r\
DEL1 #F8F8F2\r\
DEL2 #F8F8F2\r\
TYPE #FD971F\r\
OP #66D9EF\r\
TAG #F92672\r\
ATTR #A6E22E\r\
IF #F92672\r\
AREA #75715E\r\
NUM #AE81FF\r"

#define TXT_MONOKAI_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #F8F8F2\r\
HighLight_BasicBkColor #272822\r\
HighLight_SelTextColor #F8F8F2\r\
HighLight_SelBkColor #49483E\r\
HighLight_LineTextColor #F8F8F2\r\
HighLight_LineBkColor #3E3D32\r\
HighLight_LineBorderColor #434238\r\
HighLight_AltTextColor #F8F8F2\r\
HighLight_AltBkColor #252620\r\
HighLight_AltBorderColor #22231F\r\
HighLight_ColumnColor #8F908A\r\
HighLight_MarkerColor #8F908A\r\
HighLight_CaretColor #FFFFFF\r\
HighLight_UrlColor #65B8EF\r\
HighLight_ActiveUrlColor #9BDEF4\r\
HighLight_VisitUrlColor #9BDEF4\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #F8F8F2\r\
HighLight_AutoMarkBkColor #F92672\r"

#define TXT_MONOKAI_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #272822\r\
CodeFold_PanelSecondBkColor #272822\r\
CodeFold_PanelNormalFoldColor #8F908A\r\
CodeFold_PanelActiveFoldColor #F8F8F2\r\
CodeFold_PanelNormalNodeOpenBkColor #272822\r\
CodeFold_PanelNormalNodeCloseBkColor #8F908A\r\
CodeFold_PanelActiveNodeOpenBkColor #272822\r\
CodeFold_PanelActiveNodeCloseBkColor #F8F8F2\r\
CodeFold_PanelNormalNodeOpenSignColor #8F908A\r\
CodeFold_PanelNormalNodeCloseSignColor #272822\r\
CodeFold_PanelActiveNodeOpenSignColor #F8F8F2\r\
CodeFold_PanelActiveNodeCloseSignColor #272822\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #F8F8F2\r\
CodeFold_TagMarkBkColor #75715E\r"

#define TXT_MONOKAI_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_MONOKAI_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #F8F8F2\r\
LineBoard_BkColor #3E3D32\r\
LineBoard_BorderColor #272822\r\
LineBoard_BookmarkTextColor #272822\r\
LineBoard_BookmarkBkColor #F8F8F2\r\
LineBoard_BookmarkBorderColor #3E3D32\r\
LineBoard_LineUnsavedColor #FD971F\r\
LineBoard_LineSavedColor #A6E22E\r"

#define TXT_MONOKAI_VARTHEME (TXT_MONOKAI_VARTHEME_BASIC TXT_MONOKAI_VARTHEME_HIGHLIGHT TXT_MONOKAI_VARTHEME_CODEFOLD TXT_MONOKAI_VARTHEME_AUTOCOMPLETE TXT_MONOKAI_VARTHEME_LINEBOARD)

//Solarized Light variable theme
#define TXT_SOLARIZEDLIGHT_VARTHEME_BASIC \
L"STR #2AA198\r\
COMM #839496\r\
VAR #849900\r\
DEL1 #839496\r\
DEL2 #6C71C4\r\
TYPE #CB4B16\r\
OP #B58900\r\
TAG #268BD2\r\
ATTR #7D9394\r\
IF #849900\r\
AREA #2AA198\r\
NUM #D33682\r"

#define TXT_SOLARIZEDLIGHT_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #586E75\r\
HighLight_BasicBkColor #FDF6E3\r\
HighLight_SelTextColor #586E75\r\
HighLight_SelBkColor #FFFFFF\r\
HighLight_LineTextColor #586E75\r\
HighLight_LineBkColor #EEE8D5\r\
HighLight_LineBorderColor #EEEAD5\r\
HighLight_AltTextColor #586E75\r\
HighLight_AltBkColor #FEF9E9\r\
HighLight_AltBorderColor #FDF2DB\r\
HighLight_ColumnColor #839496\r\
HighLight_MarkerColor #839496\r\
HighLight_CaretColor #000000\r\
HighLight_UrlColor #06A2FF\r\
HighLight_ActiveUrlColor #0087EA\r\
HighLight_VisitUrlColor #0087EA\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #FFFFFF\r\
HighLight_AutoMarkBkColor #268BD2\r"

#define TXT_SOLARIZEDLIGHT_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #EEE8D5\r\
CodeFold_PanelSecondBkColor #EEE8D5\r\
CodeFold_PanelNormalFoldColor #657B83\r\
CodeFold_PanelActiveFoldColor #93A1A1\r\
CodeFold_PanelNormalNodeOpenBkColor #EEE8D5\r\
CodeFold_PanelNormalNodeCloseBkColor #657B83\r\
CodeFold_PanelActiveNodeOpenBkColor #EEE8D5\r\
CodeFold_PanelActiveNodeCloseBkColor #93A1A1\r\
CodeFold_PanelNormalNodeOpenSignColor #657B83\r\
CodeFold_PanelNormalNodeCloseSignColor #EEE8D5\r\
CodeFold_PanelActiveNodeOpenSignColor #93A1A1\r\
CodeFold_PanelActiveNodeCloseSignColor #EEE8D5\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #FFFFFF\r\
CodeFold_TagMarkBkColor #ABC9D4\r"

#define TXT_SOLARIZEDLIGHT_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_SOLARIZEDLIGHT_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #586E75\r\
LineBoard_BkColor #EEE8D5\r\
LineBoard_BorderColor #FDF6E3\r\
LineBoard_BookmarkTextColor #FDF6E3\r\
LineBoard_BookmarkBkColor #586E75\r\
LineBoard_BookmarkBorderColor #EEE8D5\r\
LineBoard_LineUnsavedColor #E3A420\r\
LineBoard_LineSavedColor #99BF00\r"

#define TXT_SOLARIZEDLIGHT_VARTHEME (TXT_SOLARIZEDLIGHT_VARTHEME_BASIC TXT_SOLARIZEDLIGHT_VARTHEME_HIGHLIGHT TXT_SOLARIZEDLIGHT_VARTHEME_CODEFOLD TXT_SOLARIZEDLIGHT_VARTHEME_AUTOCOMPLETE TXT_SOLARIZEDLIGHT_VARTHEME_LINEBOARD)

//Solarized Dark variable theme
#define TXT_SOLARIZEDDARK_VARTHEME_BASIC \
L"STR #2AA198\r\
COMM #586E75\r\
VAR #849900\r\
DEL1 #839496\r\
DEL2 #839496\r\
TYPE #CB4B16\r\
OP #B58900\r\
TAG #268BD2\r\
ATTR #7D9394\r\
IF #849900\r\
AREA #2AA198\r\
NUM #D33682\r"

#define TXT_SOLARIZEDDARK_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #839496\r\
HighLight_BasicBkColor #002B36\r\
HighLight_SelTextColor #FFFFFF\r\
HighLight_SelBkColor #586E75\r\
HighLight_LineTextColor #93A1A1\r\
HighLight_LineBkColor #07404B\r\
HighLight_LineBorderColor #074552\r\
HighLight_AltTextColor #839496\r\
HighLight_AltBkColor #002833\r\
HighLight_AltBorderColor #002631\r\
HighLight_ColumnColor #839496\r\
HighLight_MarkerColor #839496\r\
HighLight_CaretColor #91EAB9\r\
HighLight_UrlColor #06A2FF\r\
HighLight_ActiveUrlColor #75C1FF\r\
HighLight_VisitUrlColor #75C1FF\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #FFFFFF\r\
HighLight_AutoMarkBkColor #DC322F\r"

#define TXT_SOLARIZEDDARK_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #053542\r\
CodeFold_PanelSecondBkColor #053542\r\
CodeFold_PanelNormalFoldColor #657B83\r\
CodeFold_PanelActiveFoldColor #93A1A1\r\
CodeFold_PanelNormalNodeOpenBkColor #053542\r\
CodeFold_PanelNormalNodeCloseBkColor #657B83\r\
CodeFold_PanelActiveNodeOpenBkColor #053542\r\
CodeFold_PanelActiveNodeCloseBkColor #93A1A1\r\
CodeFold_PanelNormalNodeOpenSignColor #657B83\r\
CodeFold_PanelNormalNodeCloseSignColor #053542\r\
CodeFold_PanelActiveNodeOpenSignColor #93A1A1\r\
CodeFold_PanelActiveNodeCloseSignColor #053542\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #FFFFFF\r\
CodeFold_TagMarkBkColor #105A5D\r"

#define TXT_SOLARIZEDDARK_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_SOLARIZEDDARK_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #839496\r\
LineBoard_BkColor #07404B\r\
LineBoard_BorderColor #002B36\r\
LineBoard_BookmarkTextColor #002B36\r\
LineBoard_BookmarkBkColor #839496\r\
LineBoard_BookmarkBorderColor #07404B\r\
LineBoard_LineUnsavedColor #AC4113\r\
LineBoard_LineSavedColor #849900\r"

#define TXT_SOLARIZEDDARK_VARTHEME (TXT_SOLARIZEDDARK_VARTHEME_BASIC TXT_SOLARIZEDDARK_VARTHEME_HIGHLIGHT TXT_SOLARIZEDDARK_VARTHEME_CODEFOLD TXT_SOLARIZEDDARK_VARTHEME_AUTOCOMPLETE TXT_SOLARIZEDDARK_VARTHEME_LINEBOARD)

//SpaceCadet variable theme
#define TXT_SPACECADET_VARTHEME_BASIC \
L"STR #805978\r\
COMM #564954\r\
VAR #7587A6\r\
DEL1 #DDE6CF\r\
DEL2 #E8EEDF\r\
TYPE #A86D59\r\
OP #CDA869\r\
TAG #6078BF\r\
ATTR #6084BF\r\
IF #728059\r\
AREA #596380\r\
NUM #A8885A\r"

#define TXT_SPACECADET_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #DDE6CF\r\
HighLight_BasicBkColor #0D0D0D\r\
HighLight_SelTextColor #DDE6CF\r\
HighLight_SelBkColor #40002F\r\
HighLight_LineTextColor #FFFFFF\r\
HighLight_LineBkColor #191919\r\
HighLight_LineBorderColor #1E1E1E\r\
HighLight_AltTextColor #DDE6CF\r\
HighLight_AltBkColor #0F0F0F\r\
HighLight_AltBorderColor #0A0A0A\r\
HighLight_ColumnColor #75796E\r\
HighLight_MarkerColor #75796E\r\
HighLight_CaretColor #FFFFFF\r\
HighLight_UrlColor #769FBE\r\
HighLight_ActiveUrlColor #95BFDB\r\
HighLight_VisitUrlColor #95BFDB\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #DDE6CF\r\
HighLight_AutoMarkBkColor #72349E\r"

#define TXT_SPACECADET_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #0D0D0D\r\
CodeFold_PanelSecondBkColor #0D0D0D\r\
CodeFold_PanelNormalFoldColor #75796E\r\
CodeFold_PanelActiveFoldColor #DDE6CF\r\
CodeFold_PanelNormalNodeOpenBkColor #0D0D0D\r\
CodeFold_PanelNormalNodeCloseBkColor #75796E\r\
CodeFold_PanelActiveNodeOpenBkColor #0D0D0D\r\
CodeFold_PanelActiveNodeCloseBkColor #DDE6CF\r\
CodeFold_PanelNormalNodeOpenSignColor #75796E\r\
CodeFold_PanelNormalNodeCloseSignColor #0D0D0D\r\
CodeFold_PanelActiveNodeOpenSignColor #DDE6CF\r\
CodeFold_PanelActiveNodeCloseSignColor #0D0D0D\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #FFFFFF\r\
CodeFold_TagMarkBkColor #003040\r"

#define TXT_SPACECADET_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_SPACECADET_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #DDE6CF\r\
LineBoard_BkColor #191919\r\
LineBoard_BorderColor #0D0D0D\r\
LineBoard_BookmarkTextColor #0D0D0D\r\
LineBoard_BookmarkBkColor #DDE6CF\r\
LineBoard_BookmarkBorderColor #191919\r\
LineBoard_LineUnsavedColor #DE9B58\r\
LineBoard_LineSavedColor #A2D95E\r"

#define TXT_SPACECADET_VARTHEME (TXT_SPACECADET_VARTHEME_BASIC TXT_SPACECADET_VARTHEME_HIGHLIGHT TXT_SPACECADET_VARTHEME_CODEFOLD TXT_SPACECADET_VARTHEME_AUTOCOMPLETE TXT_SPACECADET_VARTHEME_LINEBOARD)

//Sunburst variable theme
#define TXT_SUNBURST_VARTHEME_BASIC \
L"STR #99CF50\r\
COMM #AEAEAE\r\
VAR #69A3E9\r\
DEL1 #AC885B\r\
DEL2 #E28964\r\
TYPE #9B859D\r\
OP #CE8964\r\
TAG #89BDFF\r\
ATTR #E0C589\r\
IF #65B042\r\
AREA #8FAFDF\r\
NUM #0080FF\r"

#define TXT_SUNBURST_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #F8F8F8\r\
HighLight_BasicBkColor #060606\r\
HighLight_SelTextColor #F8F8F8\r\
HighLight_SelBkColor #2C3033\r\
HighLight_LineTextColor #F8F8F8\r\
HighLight_LineBkColor #16181B\r\
HighLight_LineBorderColor #1A1E20\r\
HighLight_AltTextColor #F8F8F8\r\
HighLight_AltBkColor #090909\r\
HighLight_AltBorderColor #040404\r\
HighLight_ColumnColor #7C7C7C\r\
HighLight_MarkerColor #7C7C7C\r\
HighLight_CaretColor #FFFFFF\r\
HighLight_UrlColor #35AEFF\r\
HighLight_ActiveUrlColor #84F0FF\r\
HighLight_VisitUrlColor #84F0FF\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #F8F8F8\r\
HighLight_AutoMarkBkColor #CF6A4C\r"

#define TXT_SUNBURST_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #060606\r\
CodeFold_PanelSecondBkColor #060606\r\
CodeFold_PanelNormalFoldColor #7C7C7C\r\
CodeFold_PanelActiveFoldColor #F8F8F8\r\
CodeFold_PanelNormalNodeOpenBkColor #060606\r\
CodeFold_PanelNormalNodeCloseBkColor #7C7C7C\r\
CodeFold_PanelActiveNodeOpenBkColor #060606\r\
CodeFold_PanelActiveNodeCloseBkColor #F8F8F8\r\
CodeFold_PanelNormalNodeOpenSignColor #7C7C7C\r\
CodeFold_PanelNormalNodeCloseSignColor #060606\r\
CodeFold_PanelActiveNodeOpenSignColor #F8F8F8\r\
CodeFold_PanelActiveNodeCloseSignColor #060606\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #F8F8F8\r\
CodeFold_TagMarkBkColor #3D4B63\r"

#define TXT_SUNBURST_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_SUNBURST_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #F8F8F8\r\
LineBoard_BkColor #16181B\r\
LineBoard_BorderColor #060606\r\
LineBoard_BookmarkTextColor #060606\r\
LineBoard_BookmarkBkColor #F8F8F8\r\
LineBoard_BookmarkBorderColor #16181B\r\
LineBoard_LineUnsavedColor #F7B02D\r\
LineBoard_LineSavedColor #A4E13E\r"

#define TXT_SUNBURST_VARTHEME (TXT_SUNBURST_VARTHEME_BASIC TXT_SUNBURST_VARTHEME_HIGHLIGHT TXT_SUNBURST_VARTHEME_CODEFOLD TXT_SUNBURST_VARTHEME_AUTOCOMPLETE TXT_SUNBURST_VARTHEME_LINEBOARD)

//Twilight variable theme
#define TXT_TWILIGHT_VARTHEME_BASIC \
L"STR #8F9D6A\r\
COMM #5F5A60\r\
VAR #7587A6\r\
DEL1 #AC885B\r\
DEL2 #E0C589\r\
TYPE #CF6A4C\r\
OP #CDA869\r\
TAG #E0C589\r\
ATTR #AC885B\r\
IF #CDA869\r\
AREA #A3B5CB\r\
NUM #CA7840\r"

#define TXT_TWILIGHT_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #F8F8F8\r\
HighLight_BasicBkColor #141414\r\
HighLight_SelTextColor #F8F8F8\r\
HighLight_SelBkColor #3C4043\r\
HighLight_LineTextColor #F8F8F8\r\
HighLight_LineBkColor #252327\r\
HighLight_LineBorderColor #2D2428\r\
HighLight_AltTextColor #F8F8F8\r\
HighLight_AltBkColor #121212\r\
HighLight_AltBorderColor #0F0F0F\r\
HighLight_ColumnColor #868686\r\
HighLight_MarkerColor #868686\r\
HighLight_CaretColor #FFFFFF\r\
HighLight_UrlColor #769FBE\r\
HighLight_ActiveUrlColor #A9C2D6\r\
HighLight_VisitUrlColor #A9C2D6\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #F8F8F8\r\
HighLight_AutoMarkBkColor #CF6A4C\r"

#define TXT_TWILIGHT_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #141414\r\
CodeFold_PanelSecondBkColor #141414\r\
CodeFold_PanelNormalFoldColor #868686\r\
CodeFold_PanelActiveFoldColor #F8F8F8\r\
CodeFold_PanelNormalNodeOpenBkColor #141414\r\
CodeFold_PanelNormalNodeCloseBkColor #868686\r\
CodeFold_PanelActiveNodeOpenBkColor #141414\r\
CodeFold_PanelActiveNodeCloseBkColor #F8F8F8\r\
CodeFold_PanelNormalNodeOpenSignColor #868686\r\
CodeFold_PanelNormalNodeCloseSignColor #141414\r\
CodeFold_PanelActiveNodeOpenSignColor #F8F8F8\r\
CodeFold_PanelActiveNodeCloseSignColor #141414\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #F8F8F8\r\
CodeFold_TagMarkBkColor #27303F\r"

#define TXT_TWILIGHT_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_TWILIGHT_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #F8F8F8\r\
LineBoard_BkColor #252327\r\
LineBoard_BorderColor #141414\r\
LineBoard_BookmarkTextColor #141414\r\
LineBoard_BookmarkBkColor #F8F8F8\r\
LineBoard_BookmarkBorderColor #252327\r\
LineBoard_LineUnsavedColor #F8DA72\r\
LineBoard_LineSavedColor #95DA2E\r"

#define TXT_TWILIGHT_VARTHEME (TXT_TWILIGHT_VARTHEME_BASIC TXT_TWILIGHT_VARTHEME_HIGHLIGHT TXT_TWILIGHT_VARTHEME_CODEFOLD TXT_TWILIGHT_VARTHEME_AUTOCOMPLETE TXT_TWILIGHT_VARTHEME_LINEBOARD)

//Zenburn variable theme
#define TXT_ZENBURN_VARTHEME_BASIC \
L"STR #DCA5A5\r\
COMM #C0C0C0\r\
VAR #E4E49A\r\
DEL1 #ACACED\r\
DEL2 #95B6D4\r\
TYPE #FFAA00\r\
OP #FFC66D\r\
TAG #E4E49A\r\
ATTR #FFCC6C\r\
IF #C0E380\r\
AREA #7D9EC0\r\
NUM #8ACCCF\r"

#define TXT_ZENBURN_VARTHEME_HIGHLIGHT \
L"HighLight_FontStyle 0\r\
HighLight_FontSize 0\r\
HighLight_FaceName \"\"\r\
HighLight_BasicTextColor #FFFFFF\r\
HighLight_BasicBkColor #3F3F3F\r\
HighLight_SelTextColor #DFDFBF\r\
HighLight_SelBkColor #585858\r\
HighLight_LineTextColor #DFDFBF\r\
HighLight_LineBkColor #5D666E\r\
HighLight_LineBorderColor #616972\r\
HighLight_AltTextColor #FFFFFF\r\
HighLight_AltBkColor #3B3B3B\r\
HighLight_AltBorderColor #393939\r\
HighLight_ColumnColor #5D666E\r\
HighLight_MarkerColor #5D666E\r\
HighLight_CaretColor #91EAB9\r\
HighLight_UrlColor #66C6FF\r\
HighLight_ActiveUrlColor #A8DEFF\r\
HighLight_VisitUrlColor #A8DEFF\r\
HighLight_BkImageFile \"\"\r\
HighLight_BkImageAlpha 128\r\
HighLight_AutoMarkFlags 1\r\
HighLight_AutoMarkFontStyle 0\r\
HighLight_AutoMarkTextColor #FFFFFF\r\
HighLight_AutoMarkBkColor #82A8A8\r"

#define TXT_ZENBURN_VARTHEME_CODEFOLD \
L"CodeFold_PanelFirstBkColor #3F3F3F\r\
CodeFold_PanelSecondBkColor #3F3F3F\r\
CodeFold_PanelNormalFoldColor #808080\r\
CodeFold_PanelActiveFoldColor #B9B9B9\r\
CodeFold_PanelNormalNodeOpenBkColor #3F3F3F\r\
CodeFold_PanelNormalNodeCloseBkColor #808080\r\
CodeFold_PanelActiveNodeOpenBkColor #3F3F3F\r\
CodeFold_PanelActiveNodeCloseBkColor #B9B9B9\r\
CodeFold_PanelNormalNodeOpenSignColor #808080\r\
CodeFold_PanelNormalNodeCloseSignColor #3F3F3F\r\
CodeFold_PanelActiveNodeOpenSignColor #B9B9B9\r\
CodeFold_PanelActiveNodeCloseSignColor #3F3F3F\r\
CodeFold_ListTextColor 0\r\
CodeFold_ListBkColor 0\r\
CodeFold_TagMarkFlags 0\r\
CodeFold_TagMarkFontStyle 1\r\
CodeFold_TagMarkTextColor #FFFFFF\r\
CodeFold_TagMarkBkColor #3F706B\r"

#define TXT_ZENBURN_VARTHEME_AUTOCOMPLETE \
L"AutoComplete_Indent \"  \"\r"

#define TXT_ZENBURN_VARTHEME_LINEBOARD \
L"LineBoard_TextColor #FFFFFF\r\
LineBoard_BkColor #5D666E\r\
LineBoard_BorderColor #3F3F3F\r\
LineBoard_BookmarkTextColor #3F3F3F\r\
LineBoard_BookmarkBkColor #FFFFFF\r\
LineBoard_BookmarkBorderColor #5D666E\r\
LineBoard_LineUnsavedColor #FFB13E\r\
LineBoard_LineSavedColor #AEDB5B\r"

#define TXT_ZENBURN_VARTHEME (TXT_ZENBURN_VARTHEME_BASIC TXT_ZENBURN_VARTHEME_HIGHLIGHT TXT_ZENBURN_VARTHEME_CODEFOLD TXT_ZENBURN_VARTHEME_AUTOCOMPLETE TXT_ZENBURN_VARTHEME_LINEBOARD)


#endif