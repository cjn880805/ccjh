//tulong_dao.h 屠龙刀
//秦波 2002-5-11

EQUIP_BEGIN(CItulong_dao);

virtual void create(int nFlag = 0)		
{
	set_name( "屠龙刀");	

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(70000);		//set item weight

	set("unit", "把");
	set("long", "武林中传诵已久的神兵利器，与倚天剑并提，相传是一对夫妇为避免本国灭亡、力图日后中兴而做成，不过传说辛秘已不可考……但如今这把屠龙刀至少仍然锋利无匹。");
	set("material", "steel");
	set("weapon/strength", 10);
	set("wield_msg",  "$N亮出屠龙刀，长啸道：“$HIR武林至尊，宝刀屠龙，号令天下，莫敢不从。$COM”" );
	set("unwield_msg",  "只见$N拂拭着刀身：“这屠龙刀的秘密到底是什么呢？”呢喃之间将屠龙刀放了下来。" );

	set("apply/damage", 1000);					//set the modifiers of attribute
 
};

EQUIP_END;

//last, register the item into ../server/ItemSetup.cpp



