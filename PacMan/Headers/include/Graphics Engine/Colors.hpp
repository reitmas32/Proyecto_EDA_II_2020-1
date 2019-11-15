#ifndef COLORS_HPP
#define COLORS_HPP

/**
 * Se utilizara la estructura vector para almacenar los valores de los colores
 **/
#include <vector>

/**
 * Namespace que almacena los colores del Motor Grafico
 **/
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
    std::vector<int> LightSalmon	        = {255, 160, 122};  //#FFA07A      
    std::vector<int> LightSeaGreen	        = { 32, 178, 170};  //#20B2AA   
    std::vector<int> LightSkyBlue	        = {135, 206, 250};  //#87CEFA   
    std::vector<int> LightSlateGray	        = {119, 136, 153};  //#778899   
    std::vector<int> LightSteelBlue	        = {176, 196, 222};  //#B0C4DE   
    std::vector<int> LightYellow	        = {255, 255, 224};  //#FFFFE0   
    std::vector<int> Lime	                = {  0, 255,   0};  //#00FF00   
    std::vector<int> LimeGreen	            = { 50, 205,  50};  //#32CD32   
    std::vector<int> Linen	                = {250, 240, 230};  //#FAF0E6   
    std::vector<int> Maroon	                = {128,   0,   0};  //#800000   
    std::vector<int> MediumAquamarine	    = {102, 205, 170};  //#66CDAA   
    std::vector<int> MediumBlue	            = {  0,   0, 205};  //#0000CD   
    std::vector<int> MediumOrchid	        = {186,  85, 211};  //#BA55D3   
    std::vector<int> MediumPurple	        = {147, 112, 219};  //#9370DB   
    std::vector<int> MediumSeaGreen	        = { 60, 179, 113};  //#3CB371   
    std::vector<int> MediumSlateBlue	    = {123, 104, 238};  //#7B68EE   
    std::vector<int> MediumSpringGreen	    = {  0, 250, 154};  //#00FA9A   
    std::vector<int> MediumTurquoise	    = { 72, 209, 204};  //#48D1CC   
    std::vector<int> MediumVioletRed	    = {199,  21, 133};  //#C71585   
    std::vector<int> MidnightBlue	        = { 25,  25, 112};  //#191970   
    std::vector<int> MintCream	            = {245, 255, 250};  //#F5FFFA   
    std::vector<int> MistyRose	            = {255, 228, 225};  //#FFE4E1   
    std::vector<int> Moccasin	            = {255, 228, 181};  //#FFE4B5   
    std::vector<int> NavajoWhite	        = {255, 222, 173};  //#FFDEAD   
    std::vector<int> Navy	                = {  0,   0, 128};  //#000080   
    std::vector<int> OldLace	            = {253, 245, 230};  //#FDF5E6   
    std::vector<int> Olive	                = {128, 128,   0};  //#808000   
    std::vector<int> OliveDrab	            = {107, 142,  35};  //#6B8E23   
    std::vector<int> Orange	                = {255, 165,   0};  //#FFA500   
    std::vector<int> OrangeRed	            = {255,  69,   0};  //#FF4500   
    std::vector<int> Orchid	                = {218, 112, 214};  //#DA70D6   
    std::vector<int> PaleGoldenrod	        = {238, 232, 170};  //#EEE8AA   
    std::vector<int> PaleGreen	            = {152, 251, 152};  //#98FB98   
    std::vector<int> PaleTurquoise	        = {175, 238, 238};  //#AFEEEE   
    std::vector<int> PaleVioletRed	        = {219, 112, 147};  //#DB7093   
    std::vector<int> PapayaWhip	            = {255, 239, 213};  //#FFEFD5   
    std::vector<int> PeachPuff	            = {255, 218, 185};  //#FFDAB9   
    std::vector<int> Peru	                = {205, 133,  63};  //#CD853F   
    std::vector<int> Pink	                = {255, 192, 203};  //#FFC0CB   
    std::vector<int> Plum	                = {221, 160, 221};  //#DDA0DD   
    std::vector<int> PowderBlue	            = {176, 224, 230};  //#B0E0E6   
    std::vector<int> Purple	                = {128,   0, 128};  //#800080    
    std::vector<int> RosyBrown	            = {188, 143, 143};  //#BC8F8F   
    std::vector<int> RoyalBlue	            = { 65, 105, 225};  //#4169E1   
    std::vector<int> SaddleBrown	        = {139,  69,  19};  //#8B4513   
    std::vector<int> Salmon	                = {250, 128, 114};  //#FA8072   
    std::vector<int> SandyBrown	            = {244, 164,  96};  //#F4A460   
    std::vector<int> SeaGreen	            = { 46, 139,  87};  //#2E8B57   
    std::vector<int> Seashell	            = {255, 245, 238};  //#FFF5EE   
    std::vector<int> Sienna	                = {160,  82,  45};  //#A0522D   
    std::vector<int> Silver	                = {192, 192, 192};  //#C0C0C0   
    std::vector<int> SkyBlue	            = {135, 206, 235};  //#87CEEB   
    std::vector<int> SlateBlue	            = {106,  90, 205};  //#6A5ACD   
    std::vector<int> SlateGray	            = {112, 128, 144};  //#708090   
    std::vector<int> Snow	                = {255, 250, 250};  //#FFFAFA   
    std::vector<int> SpringGreen	        = {  0, 255, 127};  //#00FF7F   
    std::vector<int> SteelBlue	            = { 70, 130, 180};  //#4682B4   
    std::vector<int> Tan	                = {210, 180, 140};  //#D2B48C   
    std::vector<int> Teal	                = {  0, 128, 128};  //#008080   
    std::vector<int> Thistle	            = {216, 191, 216};  //#D8BFD8   
    std::vector<int> Tomato	                = {255,  99,  71};  //#FF6347   
    std::vector<int> Turquoise	            = { 64, 224, 208};  //#40E0D0   
    std::vector<int> Violet	                = {238, 130, 238};  //#EE82EE   
    std::vector<int> Wheat	                = {245, 222, 179};  //#F5DEB3    
    std::vector<int> WhiteSmoke	            = {245, 245, 245};  //#F5F5F5   
    std::vector<int> YellowGreen	        = {154, 205,  50};  //#9ACD32   
} // namespace Colors

#endif  //COLORS_HPP