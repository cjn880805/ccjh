//mingwang_jian.h 明王剑
//秦波 2002-5-11

EQUIP_BEGIN(CImingwang_jian);


virtual void create(int nFlag = 0)		
{
	set_name( "明王剑");	

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(20000);		//set item weight

	set("unit", "把");
	set("long", "这是一柄密教神器，全称为不动明王剑。剑锷上浮雕着八叶莲花，莲花中间有咒文——“撼”，剑身自血槽以外通为赤色，显得分外妖艳诡异，但却是消除魔障的圣器。");
	set("material", "steel");
	set("weapon/strength", 10);
	set("wield_msg",  "只见$N口念不动明王金刚不共大法咒语，猝然右手中变化出一柄幻火环绕的明王剑。" );
	set("unwield_msg",  "$N突然心头一惊，暗知是心魔入侵，忙收起明王剑定心消除业障。" );

	set("apply/damage", random(100)+230);					//set the modifiers of attribute
 
};

EQUIP_END;

//last, register the item into ../server/ItemSetup.cpp



