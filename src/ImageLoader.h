#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include "ImageMan.h"

void LoadImages()
{
	// spritecow.com

	// Images
	/*ImageMan::addImage(ImageName::Stitch, TextName::Stitch, Rect(0, 0, 300, 410));
	ImageMan::addImage(ImageName::Alien_Green, TextName::Invaders, Rect(136, 64, 85, 63));
	ImageMan::addImage(ImageName::Alien_Blue, TextName::Invaders, Rect(370, 64, 62, 63));
	ImageMan::addImage(ImageName::Alien_Red, TextName::Invaders, Rect(559, 64, 93, 63));*/

	ImageMan::addImage(ImageName::Bird_Red_0, TextName::BirdPigsEffects, Rect(903, 798, 46, 45));
	ImageMan::addImage(ImageName::Bird_Red_1, TextName::BirdPigsEffects, Rect(951, 798, 46, 45));
	ImageMan::addImage(ImageName::Bird_Red_2, TextName::BirdPigsEffects, Rect(956, 845, 51, 42));
	ImageMan::addImage(ImageName::Bird_Red_3, TextName::BirdPigsEffects, Rect(903, 891, 51, 42));
	ImageMan::addImage(ImageName::Bird_Red_4, TextName::BirdPigsEffects, Rect(853, 592, 47, 45));

	ImageMan::addImage(ImageName::Bird_Red_Normal, TextName::BirdPigsEffects, Rect(903, 798, 46, 45));
	ImageMan::addImage(ImageName::Bird_Red_Blink, TextName::BirdPigsEffects, Rect(956, 845, 51, 42));
	ImageMan::addImage(ImageName::Bird_Red_Flying, TextName::BirdPigsEffects, Rect(951, 798, 46, 45));
	ImageMan::addImage(ImageName::Bird_Red_Damaged, TextName::BirdPigsEffects, Rect(853, 892, 47, 45));

	ImageMan::addImage(ImageName::Bird_Yellow_0, TextName::BirdPigsEffects, Rect(668, 879, 58, 54));
	ImageMan::addImage(ImageName::Bird_Yellow_1, TextName::BirdPigsEffects, Rect(588, 915, 68, 52));
	ImageMan::addImage(ImageName::Bird_Yellow_2, TextName::BirdPigsEffects, Rect(732, 800, 58, 54));
	ImageMan::addImage(ImageName::Bird_Yellow_3, TextName::BirdPigsEffects, Rect(732, 744, 58, 54));
	ImageMan::addImage(ImageName::Bird_Yellow_4, TextName::BirdPigsEffects, Rect(792, 744, 59, 53));
	ImageMan::addImage(ImageName::Bird_Yellow_5, TextName::BirdPigsEffects, Rect(853, 744, 81, 52));

	ImageMan::addImage(ImageName::Bird_Yellow_Normal, TextName::BirdPigsEffects, Rect(668, 879, 58, 54));
	ImageMan::addImage(ImageName::Bird_Yellow_Blink, TextName::BirdPigsEffects, Rect(732, 744, 58, 54));
	ImageMan::addImage(ImageName::Bird_Yellow_Flying, TextName::BirdPigsEffects, Rect(732, 800, 58, 54));
	ImageMan::addImage(ImageName::Bird_Yellow_Damaged, TextName::BirdPigsEffects, Rect(792, 744, 59, 53));
	ImageMan::addImage(ImageName::Bird_Yellow_Zoom, TextName::BirdPigsEffects, Rect(853, 744, 81, 52));

	ImageMan::addImage(ImageName::Bird_Black_0, TextName::BirdPigsEffects, Rect(409, 725, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_1, TextName::BirdPigsEffects, Rect(777, 446, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_2, TextName::BirdPigsEffects, Rect(668, 679, 62, 71));
	ImageMan::addImage(ImageName::Bird_Black_3, TextName::BirdPigsEffects, Rect(714, 446, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_4, TextName::BirdPigsEffects, Rect(409, 808, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_5, TextName::BirdPigsEffects, Rect(588, 446, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_6, TextName::BirdPigsEffects, Rect(651, 446, 61, 81));

	ImageMan::addImage(ImageName::Bird_Black_Normal, TextName::BirdPigsEffects, Rect(409, 725, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_Blink, TextName::BirdPigsEffects, Rect(714, 446, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_Flying, TextName::BirdPigsEffects, Rect(777, 446, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_Damaged, TextName::BirdPigsEffects, Rect(668, 679, 62, 71)); // ??
	ImageMan::addImage(ImageName::Bird_Black_Bomb_0, TextName::BirdPigsEffects, Rect(409, 808, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_Bomb_1, TextName::BirdPigsEffects, Rect(588, 446, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_Bomb_2, TextName::BirdPigsEffects, Rect(651, 446, 61, 81));

	ImageMan::addImage(ImageName::Bird_White_0, TextName::BirdPigsEffects, Rect(409, 353, 81, 93));
	ImageMan::addImage(ImageName::Bird_White_1, TextName::BirdPigsEffects, Rect(409, 543, 81, 93));
	ImageMan::addImage(ImageName::Bird_White_2, TextName::BirdPigsEffects, Rect(409, 448, 82, 93));
	ImageMan::addImage(ImageName::Bird_White_3, TextName::BirdPigsEffects, Rect(493, 353, 85, 91));
	ImageMan::addImage(ImageName::Bird_White_4, TextName::BirdPigsEffects, Rect(409, 638, 79, 85));
	ImageMan::addImage(ImageName::Bird_White_5, TextName::BirdPigsEffects, Rect(668, 752, 50, 65));

	ImageMan::addImage(ImageName::Bird_White_Normal, TextName::BirdPigsEffects, Rect(409, 353, 81, 93));
	ImageMan::addImage(ImageName::Bird_White_Blink, TextName::BirdPigsEffects, Rect(409, 448, 82, 93));
	ImageMan::addImage(ImageName::Bird_White_Flying, TextName::BirdPigsEffects, Rect(409, 543, 81, 93));
	ImageMan::addImage(ImageName::Bird_White_Damaged, TextName::BirdPigsEffects, Rect(409, 638, 79, 85));
	ImageMan::addImage(ImageName::Bird_White_Laying, TextName::BirdPigsEffects, Rect(493, 353, 79, 85));
	ImageMan::addImage(ImageName::Bird_White_Ghost, TextName::BirdPigsEffects, Rect(668, 752, 50, 65));
	ImageMan::addImage(ImageName::Bird_White_Egg, TextName::BirdPigsEffects, Rect(668, 819, 45, 58));

	ImageMan::addImage(ImageName::Bird_Green_0, TextName::BirdPigsEffects, Rect(932, 529, 99, 72));
	ImageMan::addImage(ImageName::Bird_Green_1, TextName::BirdPigsEffects, Rect(830, 529, 100, 72));
	ImageMan::addImage(ImageName::Bird_Green_2, TextName::BirdPigsEffects, Rect(668, 605, 99, 72));
	ImageMan::addImage(ImageName::Bird_Green_3, TextName::BirdPigsEffects, Rect(952, 605, 95, 71));
	ImageMan::addImage(ImageName::Bird_Green_4, TextName::BirdPigsEffects, Rect(956, 156, 84, 94));

	ImageMan::addImage(ImageName::Bird_Green_Normal, TextName::BirdPigsEffects, Rect(932, 529, 99, 72));
	ImageMan::addImage(ImageName::Bird_Green_Blink, TextName::BirdPigsEffects, Rect(668, 605, 99, 72));
	ImageMan::addImage(ImageName::Bird_Green_Flying, TextName::BirdPigsEffects, Rect(830, 529, 100, 72));
	ImageMan::addImage(ImageName::Bird_Green_Damaged, TextName::BirdPigsEffects, Rect(952, 605, 95, 71));
	ImageMan::addImage(ImageName::Bird_Green_Boomerang, TextName::BirdPigsEffects, Rect(956, 156, 84, 94));

	ImageMan::addImage(ImageName::Bird_Blue_0, TextName::BirdPigsEffects, Rect(1, 379, 31, 30));
	ImageMan::addImage(ImageName::Bird_Blue_1, TextName::BirdPigsEffects, Rect(1, 538, 30, 29));
	ImageMan::addImage(ImageName::Bird_Blue_2, TextName::BirdPigsEffects, Rect(1, 508, 30, 28));
	ImageMan::addImage(ImageName::Bird_Blue_3, TextName::BirdPigsEffects, Rect(1, 411, 31, 30));

	ImageMan::addImage(ImageName::Bird_Blue_Normal, TextName::BirdPigsEffects, Rect(1, 379, 31, 30));
	ImageMan::addImage(ImageName::Bird_Blue_Blink, TextName::BirdPigsEffects, Rect(1, 508, 30, 28));
	ImageMan::addImage(ImageName::Bird_Blue_Flying, TextName::BirdPigsEffects, Rect(1, 538, 30, 29));
	ImageMan::addImage(ImageName::Bird_Blue_Damaged, TextName::BirdPigsEffects, Rect(1, 411, 31, 30));

	ImageMan::addImage(ImageName::Bird_Big_0, TextName::BirdPigsEffects, Rect(298, 752, 98, 95));
	ImageMan::addImage(ImageName::Bird_Big_1, TextName::BirdPigsEffects, Rect(634, 156, 98, 98));
	ImageMan::addImage(ImageName::Bird_Big_2, TextName::BirdPigsEffects, Rect(813, 258, 98, 93));
	ImageMan::addImage(ImageName::Bird_Big_3, TextName::BirdPigsEffects, Rect(813, 258, 98, 93));

	ImageMan::addImage(ImageName::Bird_Big_Normal, TextName::BirdPigsEffects, Rect(298, 752, 98, 95));
	ImageMan::addImage(ImageName::Bird_Big_Blink, TextName::BirdPigsEffects, Rect(813, 258, 98, 93));
	ImageMan::addImage(ImageName::Bird_Big_Flying, TextName::BirdPigsEffects, Rect(634, 156, 98, 98));
	ImageMan::addImage(ImageName::Bird_Big_Damaged, TextName::BirdPigsEffects, Rect(298, 752, 98, 95));

	// Pigs

	ImageMan::addImage(ImageName::Pig_Big_0, TextName::BirdPigsEffects, Rect(298, 357, 98, 97));
	ImageMan::addImage(ImageName::Pig_Big_1, TextName::BirdPigsEffects, Rect(298, 849, 99, 93));

	ImageMan::addImage(ImageName::Pig_Medium_0, TextName::BirdPigsEffects, Rect(929, 446, 78, 77));
	ImageMan::addImage(ImageName::Pig_Medium_1, TextName::BirdPigsEffects, Rect(409, 891, 79, 74));

	ImageMan::addImage(ImageName::Pig_Small_0, TextName::BirdPigsEffects, Rect(732, 856, 48, 46));
	ImageMan::addImage(ImageName::Pig_Small_1, TextName::BirdPigsEffects, Rect(986, 744, 48, 45));

	ImageMan::addImage(ImageName::Pig_King_0, TextName::BirdPigsEffects, Rect(41, 1, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_1, TextName::BirdPigsEffects, Rect(169, 1, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_2, TextName::BirdPigsEffects, Rect(297, 1, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_3, TextName::BirdPigsEffects, Rect(425, 1, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_4, TextName::BirdPigsEffects, Rect(41, 156, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_5, TextName::BirdPigsEffects, Rect(41, 311, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_6, TextName::BirdPigsEffects, Rect(41, 466, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_7, TextName::BirdPigsEffects, Rect(41, 621, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_8, TextName::BirdPigsEffects, Rect(41, 776, 126, 153));

	ImageMan::addImage(ImageName::Pig_Mustache_0, TextName::BirdPigsEffects, Rect(169, 626, 110, 100));
	ImageMan::addImage(ImageName::Pig_Mustache_1, TextName::BirdPigsEffects, Rect(169, 728, 110, 100));
	ImageMan::addImage(ImageName::Pig_Mustache_2, TextName::BirdPigsEffects, Rect(168, 832, 109, 99));
	ImageMan::addImage(ImageName::Pig_Mustache_3, TextName::BirdPigsEffects, Rect(298, 156, 110, 100));
	ImageMan::addImage(ImageName::Pig_Mustache_4, TextName::BirdPigsEffects, Rect(410, 156, 110, 99));
	ImageMan::addImage(ImageName::Pig_Mustache_5, TextName::BirdPigsEffects, Rect(522, 156, 110, 99));
	ImageMan::addImage(ImageName::Pig_Mustache_6, TextName::BirdPigsEffects, Rect(734, 156, 109, 97));
	ImageMan::addImage(ImageName::Pig_Mustache_7, TextName::BirdPigsEffects, Rect(845, 156, 109, 97));
	ImageMan::addImage(ImageName::Pig_Mustache_8, TextName::BirdPigsEffects, Rect(298, 258, 109, 97));

	ImageMan::addImage(ImageName::Wood_Platform, TextName::WoodPlatform, Rect(0, 0, 156, 44));

	// Wood Blocks

	ImageMan::addImage(ImageName::Wood_Plat_Long_0, TextName::WoodBlocks, Rect(288, 168, 205, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Long_1, TextName::WoodBlocks, Rect(288, 189, 205, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Long_2, TextName::WoodBlocks, Rect(288, 210, 205, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Long_3, TextName::WoodBlocks, Rect(288, 231, 205, 21));

	ImageMan::addImage(ImageName::Wood_Plat_Medium_0, TextName::WoodBlocks, Rect(288, 256, 168, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Medium_1, TextName::WoodBlocks, Rect(288, 277, 168, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Medium_2, TextName::WoodBlocks, Rect(288, 298, 168, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Medium_3, TextName::WoodBlocks, Rect(288, 319, 168, 21));

	ImageMan::addImage(ImageName::Wood_Plat_Short_0, TextName::WoodBlocks, Rect(288, 344, 82, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Short_1, TextName::WoodBlocks, Rect(288, 365, 82, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Short_2, TextName::WoodBlocks, Rect(372, 344, 82, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Short_3, TextName::WoodBlocks, Rect(372, 365, 82, 21));

	ImageMan::addImage(ImageName::Wood_Plat_Tiny_0, TextName::WoodBlocks, Rect(458, 255, 41, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Tiny_1, TextName::WoodBlocks, Rect(458, 276, 41, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Tiny_2, TextName::WoodBlocks, Rect(458, 297, 41, 21));
	ImageMan::addImage(ImageName::Wood_Plat_Tiny_3, TextName::WoodBlocks, Rect(458, 318, 41, 21));

	ImageMan::addImage(ImageName::Wood_Rect_0, TextName::WoodBlocks, Rect(245, 81, 84, 46));
	ImageMan::addImage(ImageName::Wood_Rect_1, TextName::WoodBlocks, Rect(329, 81, 84, 46));
	ImageMan::addImage(ImageName::Wood_Rect_2, TextName::WoodBlocks, Rect(413, 81, 84, 46));
	ImageMan::addImage(ImageName::Wood_Rect_3, TextName::WoodBlocks, Rect(245, 125, 84, 46));

	ImageMan::addImage(ImageName::Wood_Square_0, TextName::WoodBlocks, Rect(0, 335, 44, 44));
	ImageMan::addImage(ImageName::Wood_Square_1, TextName::WoodBlocks, Rect(84, 335, 44, 44));
	ImageMan::addImage(ImageName::Wood_Square_2, TextName::WoodBlocks, Rect(330, 125, 44, 44));
	ImageMan::addImage(ImageName::Wood_Square_3, TextName::WoodBlocks, Rect(374, 125, 44, 44));

	ImageMan::addImage(ImageName::Wood_Circle_Big_0, TextName::WoodBlocks, Rect(167, 82, 77, 77));

	// Glass Blocks

	ImageMan::addImage(ImageName::Glass_Plat_Long_0, TextName::GlassBlocks, Rect(288, 215, 205, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Long_1, TextName::GlassBlocks, Rect(288, 194, 205, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Long_2, TextName::GlassBlocks, Rect(288, 236, 205, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Long_3, TextName::GlassBlocks, Rect(288, 173, 205, 21));

	ImageMan::addImage(ImageName::Glass_Plat_Medium_0, TextName::GlassBlocks, Rect(288, 260, 168, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Medium_1, TextName::GlassBlocks, Rect(288, 281, 168, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Medium_2, TextName::GlassBlocks, Rect(288, 302, 168, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Medium_3, TextName::GlassBlocks, Rect(288, 323, 168, 21));

	ImageMan::addImage(ImageName::Glass_Plat_Short_0, TextName::GlassBlocks, Rect(288, 347, 82, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Short_1, TextName::GlassBlocks, Rect(288, 368, 82, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Short_2, TextName::GlassBlocks, Rect(372, 347, 82, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Short_3, TextName::GlassBlocks, Rect(372, 368, 82, 21));

	ImageMan::addImage(ImageName::Glass_Plat_Tiny_0, TextName::GlassBlocks, Rect(245, 255, 41, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Tiny_1, TextName::GlassBlocks, Rect(245, 276, 41, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Tiny_2, TextName::GlassBlocks, Rect(245, 297, 41, 21));
	ImageMan::addImage(ImageName::Glass_Plat_Tiny_3, TextName::GlassBlocks, Rect(245, 318, 41, 21));

	ImageMan::addImage(ImageName::Glass_Rect_0, TextName::GlassBlocks, Rect(332, 81, 84, 46));
	ImageMan::addImage(ImageName::Glass_Rect_1, TextName::GlassBlocks, Rect(418, 81, 84, 46));
	ImageMan::addImage(ImageName::Glass_Rect_2, TextName::GlassBlocks, Rect(244, 127, 84, 46));
	ImageMan::addImage(ImageName::Glass_Rect_3, TextName::GlassBlocks, Rect(328, 127, 84, 46));

	ImageMan::addImage(ImageName::Glass_Square_0, TextName::GlassBlocks, Rect(414, 127, 44, 44));
	ImageMan::addImage(ImageName::Glass_Square_1, TextName::GlassBlocks, Rect(458, 127, 44, 44));
	ImageMan::addImage(ImageName::Glass_Square_2, TextName::GlassBlocks, Rect(244, 169, 44, 44));
	ImageMan::addImage(ImageName::Glass_Square_3, TextName::GlassBlocks, Rect(244, 213, 44, 44));

	ImageMan::addImage(ImageName::Glass_Circle_0, TextName::GlassBlocks, Rect(168, 235, 75, 75));
	ImageMan::addImage(ImageName::Glass_Circle_1, TextName::GlassBlocks, Rect(168, 311, 75, 75));
	ImageMan::addImage(ImageName::Glass_Circle_2, TextName::GlassBlocks, Rect(168, 158, 75, 75));
	ImageMan::addImage(ImageName::Glass_Circle_3, TextName::GlassBlocks, Rect(168, 83, 75, 75));

	// Stone Blocks

	ImageMan::addImage(ImageName::Stone_Plat_Long_0, TextName::StoneBlocks, Rect(246, 168, 205, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Long_1, TextName::StoneBlocks, Rect(246, 189, 205, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Long_2, TextName::StoneBlocks, Rect(246, 212, 205, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Long_3, TextName::StoneBlocks, Rect(246, 235, 205, 21));

	ImageMan::addImage(ImageName::Stone_Plat_Medium_0, TextName::StoneBlocks, Rect(246, 257, 168, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Medium_1, TextName::StoneBlocks, Rect(246, 279, 168, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Medium_2, TextName::StoneBlocks, Rect(246, 301, 168, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Medium_3, TextName::StoneBlocks, Rect(246, 323, 168, 21));

	ImageMan::addImage(ImageName::Stone_Plat_Short_0, TextName::StoneBlocks, Rect(416, 257, 82, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Short_1, TextName::StoneBlocks, Rect(416, 279, 82, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Short_2, TextName::StoneBlocks, Rect(246, 345, 82, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Short_3, TextName::StoneBlocks, Rect(330, 456, 82, 21));

	ImageMan::addImage(ImageName::Stone_Plat_Tiny_0, TextName::StoneBlocks, Rect(452, 168, 41, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Tiny_1, TextName::StoneBlocks, Rect(452, 189, 41, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Tiny_2, TextName::StoneBlocks, Rect(452, 212, 41, 21));
	ImageMan::addImage(ImageName::Stone_Plat_Tiny_3, TextName::StoneBlocks, Rect(452, 235, 41, 21));

	ImageMan::addImage(ImageName::Stone_Rect_0, TextName::StoneBlocks, Rect(246, 82, 84, 44));
	ImageMan::addImage(ImageName::Stone_Rect_1, TextName::StoneBlocks, Rect(331, 82, 84, 44));
	ImageMan::addImage(ImageName::Stone_Rect_2, TextName::StoneBlocks, Rect(412, 82, 84, 44));
	ImageMan::addImage(ImageName::Stone_Rect_3, TextName::StoneBlocks, Rect(246, 130, 84, 44));

	ImageMan::addImage(ImageName::Stone_Square_0, TextName::StoneBlocks, Rect(0, 337, 44, 44));
	ImageMan::addImage(ImageName::Stone_Square_1, TextName::StoneBlocks, Rect(84, 337, 44, 44));
	ImageMan::addImage(ImageName::Stone_Square_2, TextName::StoneBlocks, Rect(331, 125, 44, 44));
	ImageMan::addImage(ImageName::Stone_Square_3, TextName::StoneBlocks, Rect(375, 125, 44, 44));

	ImageMan::addImage(ImageName::Stone_Circle_0, TextName::StoneBlocks, Rect(169, 83, 76, 76));
	ImageMan::addImage(ImageName::Stone_Circle_1, TextName::StoneBlocks, Rect(169, 158, 76, 76));
	ImageMan::addImage(ImageName::Stone_Circle_2, TextName::StoneBlocks, Rect(169, 233, 76, 76));
	ImageMan::addImage(ImageName::Stone_Circle_3, TextName::StoneBlocks, Rect(169, 308, 76, 76));

	// Effects
	ImageMan::addImage(ImageName::Puff, TextName::BirdPigsEffects, Rect(0, 344, 40, 35));
	ImageMan::addImage(ImageName::Bang, TextName::BirdPigsEffects, Rect(674, 354, 87, 89));
	ImageMan::addImage(ImageName::Null, TextName::BirdPigsEffects, Rect(0, 0, 0, 0));

	ImageMan::addImage(ImageName::Sling, TextName::BirdPigsEffects, Rect(839, 25, 18, 23));
	ImageMan::addImage(ImageName::Sling_Branch, TextName::BirdPigsEffects, Rect(830, 0, 47, 127));
	ImageMan::addImage(ImageName::Sling_Tree, TextName::BirdPigsEffects, Rect(0, 0, 40, 200));

	ImageMan::addImage(ImageName::BG_0, TextName::AngryBackground, Rect(0, 0, 1280, 1336));
}

#endif
