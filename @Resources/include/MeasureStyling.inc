[MeasureSetMediaPlayer]
Measure=String
String=#PlayerName#
IfMatch=Spotify
IfMatchAction=[!WriteKeyValue Variables MPMode Spotify "#@#variables.ini"][!DisableMeasure MeasureGenre]
IfMatch2=GPMDP
IfMatchAction2=[!WriteKeyValue Variables MPMode GPMDP "#@#variables.ini"][!DisableMeasure MeasureGenre]
IfNotMatchAction=[!WriteKeyValue Variables MPMode NowPlaying "#@#variables.ini"][!EnableMeasure MeasureGenre]
UpdateDivider=-1

[MeasureSetDynamicColors]
Measure=Calc
Formula=#EnableDynamicColors#
IfBelowValue=1
IfBelowAction=[!SetOptionGroup GroupBarColor MeterStyle "StyleStaticBar"][!SetOption MeterCoverBG MeterStyle "StyleStaticMeter"][!SetOptionGroup SongMeta MeterStyle "StyleStaticText"][!DisableMeasure MeasureGenre][!DisableMeasure MeasureGetCoverColor][!DisableMeasure MeasureCoverColor]
IfEqualValue=1
IfEqualAction=[!SetOptionGroup GroupBarColor MeterStyle "StyleGenreBar"][!SetOption MeterCoverBG MeterStyle "StyleGenreMeter"][!SetOptionGroup SongMeta MeterStyle "StyleGenreText"][!EnableMeasure MeasureGenre][!DisableMeasure MeasureGetCoverColor][!DisableMeasure MeasureCoverColor]
IfAboveValue=1
IfAboveAction=[!SetOptionGroup GroupBarColor MeterStyle "StyleCoverBar"][!SetOption MeterCoverBG MeterStyle "StyleCoverMeter"][!SetOptionGroup SongMeta MeterStyle "StyleCoverText"][!DisableMeasure MeasureGenre][!EnableMeasure MeasureGetCoverColor][!EnableMeasure MeasureCoverColor]
UpdateDivider=-1

[MeasureDisableDynamicFontColors]
Measure=Calc
Formula=#DisableDynamicFontColors#
IfEqualValue=1
IfEqualAction=[!SetOptionGroup SongMeta MeterStyle "StyleStaticText"]
UpdateDivider=-1

[MeasureFlipProgressbar]
Measure=Calc
Formula=#FlipVisualizer#
IfEqualValue=1
IfEqualAction=[!SetOption MeterProgressBar Y 0]
UpdateDivider=-1

[MeasureGetCoverColor]
Measure=Plugin
Plugin=Chameleon
Type=File
Path=[MeasureCover]

[MeasureCoverColor]
Measure=Plugin
Plugin=Chameleon
Parent=MeasureGetCoverColor
Format=Dec
Color=Background1
Substitute="":"#Color#","0,0,0,255":"#Color#","254,254,254":"#Color#"

[MeasureGenre]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=Genre
; You can add your own genres here.
; Use | as dividier and replace spaces with \s (otherwise it won't work)
; Electro
IfMatch=Electro
IfMatchAction=[!SetVariable GenreColor "#Electro#"]
; Electronic/EDM
IfMatch2=EDM|Electronic|Breaks|Chillout|Bounce|Chill
IfMatchAction2=[!SetVariable GenreColor "#EDM#"]
; House/Progressive House
IfMatch3=House|Electro\sHouse|Progressive\sHouse
IfMatchAction3=[!SetVariable GenreColor "#House#"]
; Drum & Bass
IfMatch4=Drum\s&\sBass|DnB
IfMatchAction4=[!SetVariable GenreColor "#DnB#"]
; Dubstep
IfMatch5=Dubstep
IfMatchAction5=[!SetVariable GenreColor "#Dubstep#"]
; Drumstep
IfMatch6=Drumstep
IfMatchAction6=[!SetVariable GenreColor "#Drumstep#"]
; Glitch Hop
IfMatch7=Glitch\sHop|GlitchHop
IfMatchAction7=[!SetVariable GenreColor "#GlitchHop#"]
; Trap
IfMatch8=Trap
IfMatchAction8=[!SetVariable GenreColor "#Trap#"]
; Trance
IfMatch9=Trance|Deep\sHouse
IfMatchAction9=[!SetVariable GenreColor "#Trance#"]
; Hard Dance
IfMatch10=Hard\sDance
IfMatchAction10=[!SetVariable GenreColor "#HardDance#"]
; Nu Disco/Indie Dance
IfMatch11=Nu\sDisco|NuDisco|Disco|Indie\sDance|Electro\sSwing
IfMatchAction11=[!SetVariable GenreColor "#NuDisco#"]
; Future Bass
IfMatch12=Future|Future\sBass
IfMatchAction12=[!SetVariable GenreColor "#FutureBass#"]
; Here is an example for an custom genre. Colors need to be rgb(a) values.
IfMatch13=Mashup|Mash\sUp
IfMatchAction13=[!SetVariable GenreColor "192,255,99"]
Substitute="":"#Color#"
Disabled=1

[StyleStaticBar]
BarColor=#Color#
[StyleStaticMeter]
SolidColor=#Color#
[StyleStaticText]
FontColor=#TextColor#
[StyleGenreMeter]
SolidColor=#GenreColor#
DynamicVariables=1
[StyleGenreBar]
BarColor=#GenreColor#
DynamicVariables=1
[StyleGenreText]
FontColor=#GenreColor#
DynamicVariables=1
[StyleCoverMeter]
SolidColor=[MeasureCoverColor]
DynamicVariables=1
[StyleCoverBar]
BarColor=[MeasureCoverColor]
DynamicVariables=1
[StyleCoverText]
FontColor=[MeasureCoverColor]
DynamicVariables=1