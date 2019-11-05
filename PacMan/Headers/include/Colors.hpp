#ifndef COLORS_HPP
#define COLORS_HPP

#include <vector>

namespace Colors
{
    std::vector<int> Red                    = {255,   0,   0};  //#FF0000
    std::vector<int> Red50                  = {255, 235, 235};  //#FFEBEE
    std::vector<int> Red100                 = {255, 205, 210};  //#FFCDC2
    std::vector<int> Red200                 = {239, 154, 154};  //#EF9A9A
    std::vector<int> Red300                 = {229, 115, 115};  //#E57373
    std::vector<int> Red400                 = {239,  83,  80};  //#EF5350
    std::vector<int> Red500                 = {244,  67,  54};  //#F44336
    std::vector<int> Red600                 = {229,  57,  53};  //#E53935
    std::vector<int> Red700                 = {211,  47,  47};  //#D32F2F
    std::vector<int> Red800                 = {198,  40,  40};  //#C62828
    std::vector<int> Red900                 = {183,  28,  28};  //#B71C1C
    std::vector<int> RedA100                = {255, 138, 128};  //#FF8A80
    std::vector<int> RedA200                = {255,  82,  82};  //#FF5252
    std::vector<int> RedA400                = {183,  23,  68};  //#FF1744
    std::vector<int> RedA700                = {213,   0,   0};  //#D50000

    std::vector<int> Blue                   = {  0,   0, 255};  //#0000FF
    std::vector<int> Blue50                 = {227, 242, 253};  //#E3F2FD
    std::vector<int> Blue100                = {187, 222, 251};  //#BBDEFB
    std::vector<int> Blue200                = {144, 202, 249};  //#90CAF9
    std::vector<int> Blue300                = {100, 181, 246};  //#64B5F6
    std::vector<int> Blue400                = { 66, 165, 245};  //#42A5F5
    std::vector<int> Blue500                = { 33, 150, 243};  //#2196F3
    std::vector<int> Blue600                = { 30, 136, 229};  //#0080FF
    std::vector<int> Blue700                = { 25, 118, 210};  //#1976D2
    std::vector<int> Blue800                = { 21, 101, 192};  //#1565C0
    std::vector<int> Blue900                = {13,  71,  161};  //#0D47A1
    std::vector<int> BlueA100               = {130, 177, 255};  //#82B1FF
    std::vector<int> BlueA200               = { 68, 138, 255};  //#448AFF
    std::vector<int> BlueA400               = { 41, 121, 255};  //#2979FF
    std::vector<int> BlueA700               = { 41,  98, 255};  //#2962FF

    std::vector<int> Green                  = {  0, 255,   0};  //#E8F5E9
    std::vector<int> Green50                = {232, 245, 233};  //#E8F5E9
    std::vector<int> Green100               = {200, 230, 201};  //#C8E6C9
    std::vector<int> Green200               = {165, 214, 167};  //#A5D6A7
    std::vector<int> Green300               = {129, 199, 132};  //#81C784
    std::vector<int> Green400               = {102, 187, 106};  //#66BB6A
    std::vector<int> Green500               = { 76, 175,  80};  //#4CAF50
    std::vector<int> Green600               = { 67, 160,  71};  //#430A47
    std::vector<int> Green700               = { 56, 142,  60};  //#388E3C
    std::vector<int> Green800               = { 46, 125,  50};  //#2E7D32
    std::vector<int> Green900               = { 27,  94,  32};  //#1B5E20
    std::vector<int> GreenA100              = {185, 246, 202};  //#B9F6CA
    std::vector<int> GreenA200              = {105, 240, 174};  //#69F0AE
    std::vector<int> GreenA400              = {  0, 230, 118};  //#00E676
    std::vector<int> GreenA700              = {  0, 200,  83};  //#00C853

    std::vector<int> Yellow                 = {255, 255,   0};  //#FFFF00

    std::vector<int> Magenta                = {255,   0, 255};  //#FF00FF

    std::vector<int> Cyan                   = {  0, 255, 255};  //#00FFFF

    std::vector<int> White                  = {255, 255, 255};  //#FFFFFF

    std::vector<int> Black                  = {  0,   0,   0};  //#000000

    std::vector<int> Brown                  = {101,  67,  33};  //#654321

    std::vector<int> Gray                   = {153, 153, 153};  //#999999
#if 0
    std::vector<int> LightSalmon	        = {};   //#FFA07A
    std::vector<int> LightSeaGreen	        = {};   //#20B2AA
    std::vector<int> LightSkyBlue	        = {};   //#87CEFA
    std::vector<int> LightSlateGray	        = {};   //#778899
    std::vector<int> LightSteelBlue	        = {};   //#B0C4DE
    std::vector<int> LightYellow	        = {};   //#FFFFE0
    std::vector<int> Lime	                = {};   //#00FF00
    std::vector<int> LimeGreen	            = {};   //#32CD32
    std::vector<int> Linen	                = {};   //#FAF0E6
    std::vector<int> Magenta	            = {};   //#FF00FF
    std::vector<int> Maroon	                = {};   //#800000
    std::vector<int> MediumAquamarine	    = {};   //#66CDAA
    std::vector<int> MediumBlue	            = {};   //#0000CD
    std::vector<int> MediumOrchid	        = {};   //#BA55D3
    std::vector<int> MediumPurple	        = {};   //#9370DB
    std::vector<int> MediumSeaGreen	        = {};   //#3CB371
    std::vector<int> MediumSlateBlue	    = {};   //#7B68EE
    std::vector<int> MediumSpringGreen	    = {};   //#00FA9A
    std::vector<int> MediumTurquoise	    = {};   //#48D1CC
    std::vector<int> MediumVioletRed	    = {};   //#C71585
    std::vector<int> MidnightBlue	        = {};   //#191970
    std::vector<int> MintCream	            = {};   //#F5FFFA
    std::vector<int> MistyRose	            = {};   //#FFE4E1
    std::vector<int> Moccasin	            = {};   //#FFE4B5
    std::vector<int> NavajoWhite	        = {};   //#FFDEAD
    std::vector<int> Navy	                = {};   //#000080
    std::vector<int> OldLace	            = {};   //#FDF5E6
    std::vector<int> Olive	                = {};   //#808000
    std::vector<int> OliveDrab	            = {};   //#6B8E23
    std::vector<int> Orange	                = {};   //#FFA500
    std::vector<int> OrangeRed	            = {};   //#FF4500
    std::vector<int> Orchid	                = {};   //#DA70D6
    std::vector<int> PaleGoldenrod	        = {};   //#EEE8AA
    std::vector<int> PaleGreen	            = {};   //#98FB98
    std::vector<int> PaleTurquoise	        = {};   //#AFEEEE
    std::vector<int> PaleVioletRed	        = {};   //#DB7093
    std::vector<int> PapayaWhip	            = {};   //#FFEFD5
    std::vector<int> PeachPuff	            = {};   //#FFDAB9
    std::vector<int> Peru	                = {};   //#CD853F
    std::vector<int> Pink	                = {};   //#FFC0CB
    std::vector<int> Plum	                = {};   //#DDA0DD
    std::vector<int> PowderBlue	            = {};   //#B0E0E6
    std::vector<int> Purple	                = {};   //#800080
    std::vector<int> Red	                = {};   //#FF0000
    std::vector<int> RosyBrown	            = {};   //#BC8F8F
    std::vector<int> RoyalBlue	            = {};   //#4169E1
    std::vector<int> SaddleBrown	        = {};   //#8B4513
    std::vector<int> Salmon	                = {};   //#FA8072
    std::vector<int> SandyBrown	            = {};   //#F4A460
    std::vector<int> SeaGreen	            = {};   //#2E8B57
    std::vector<int> Seashell	            = {};   //#FFF5EE
    std::vector<int> Sienna	                = {};   //#A0522D
    std::vector<int> Silver	                = {};   //#C0C0C0
    std::vector<int> SkyBlue	            = {};   //#87CEEB
    std::vector<int> SlateBlue	            = {};   //#6A5ACD
    std::vector<int> SlateGray	            = {};   //#708090
    std::vector<int> Snow	                = {};   //#FFFAFA
    std::vector<int> SpringGreen	        = {};   //#00FF7F
    std::vector<int> SteelBlue	            = {};   //#4682B4
    std::vector<int> Tan	                = {};   //#D2B48C
    std::vector<int> Teal	                = {};   //#008080
    std::vector<int> Thistle	            = {};   //#D8BFD8
    std::vector<int> Tomato	                = {};   //#FF6347
    std::vector<int> Turquoise	            = {};   //#40E0D0
    std::vector<int> Violet	                = {};   //#EE82EE
    std::vector<int> Wheat	                = {};   //#F5DEB3
    std::vector<int> White	                = {};   //#FFFFFF
    std::vector<int> WhiteSmoke	            = {};   //#F5F5F5
    std::vector<int> Yellow	                = {};   //#FFFF00
    std::vector<int> YellowGreen	        = {};   //#9ACD32
    
#endif

} // namespace Colors

#endif  //COLORS_HPP