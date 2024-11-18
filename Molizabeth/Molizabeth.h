#ifndef MOLIZABETH_H
#define MOLIZABETH_H

#include "Kotekana.h"
#include "Kazuko.h"
#include "Senmu.h"
#include "Dainagon.h"
#include "Maruki.h"
#include "Miwa.h"
#include "Doc.h"
#include "Waka.h"
#include "Wasei.h"
#include "Tabokun.h"
#include "Jibu.h"
#include "Back.h"
#include "Number.h"

const unsigned char** grap_member_Array[11][2] =
{
	{ grap_Jibu_Array,grap_Jibu_mask_Array },
	{ grap_Tabokun_Array,grap_Tabokun_mask_Array },
	{ grap_Wasei_Array,grap_Wasei_mask_Array },
	{ grap_Waka_Array,grap_Waka_mask_Array },
	{ grap_Doc_Array,grap_Doc_mask_Array },
	{ grap_Miwa_Array,grap_Miwa_mask_Array },
	{ grap_Maruki_Array,grap_Maruki_mask_Array },
	{ grap_Dainagon_Array,grap_Dainagon_mask_Array },
	{ grap_Senmu_Array,grap_Senmu_mask_Array },
	{ grap_Kazuko_Array,grap_Kazuko_mask_Array },
	{ grap_Kotekana_Array,grap_Kotekana_mask_Array }
};

const int drawIndex[11][2] = {
	{13,0},		// Jibu
	{1,1},		// Tabokun
	{0,10},		// Wasei
	{0,19},		// Waka
	{25,0},		// Doc
	{28,6},		// Miwa
	{29,12},	// Maruki
	{28,22},	// Dainagon
	{3,27},		// Senmu
	{28,28},	// Kazuko
	{15,28}		// Kotekana
};

#endif