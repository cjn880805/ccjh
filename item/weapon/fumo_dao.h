//fumo_dao.h

//Sample for ITEM: 伏魔刀
//coded by Fisho
//data: 2000-11-24

EQUIP_BEGIN(CIfumo_dao);

virtual void create(int nFlag = 0)	
{
	set_name( "伏魔刀");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(10000);		//set item weight
	
	set("unit", "把");
	set("long", "这是一把银光雪亮的伏魔刀，刀刃间隐隐有血光流动，锋利无匹，映面生寒。此刀数百年前由达摩老祖携入中原，一路用之除妖灭魔，乃是佛家无上降魔法宝。");
	set("value", 1000000);
	set("material", "steel");
	set("no_drop", "这样东西不能离开你。");
	set("no_get", "这样东西不能离开那儿。");
	set("wield_msg",  "只听「铮」的一声，伏魔刀脱鞘飞出，自行跃入$N掌中。瞬时天际间风云变色，电闪雷鸣，弥漫着一片无边杀意。" );
	set("unwield_msg",  "伏魔刀自$N掌中飞起，在半空中一转，「唰」地跃入刀鞘。" );
	set("apply/damage", 1000);					//set the modifiers of attribute
	
};

EQUIP_END;
