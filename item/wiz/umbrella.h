EQUIP_BEGIN(CIumbrella);


virtual void create(int nFlag = 0)
{
	set_name( "雨伞");	

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");
	set_weight(1000);		

	set("unit", "把");
	set("value", 250000);
	set("material", "bamboo");
	set("long", "这是一把奇怪的东西，据说名叫“雨伞”。");
	set("wield_msg", "$N看看天色，道：好象要下雨了……不过我不怕。\n$N掏出一把$n，撑在手中，笑道：这是最新发明。");
	set("unequip_msg", "$N道：既然不是下雨，$n就没什么用了，还是先收起来吧。");
	set("apply/damage", 15);				

	set("skill/name","fengyu_wuqingzhi");	
	set("skill/exp_required",  0l);	
	set("skill/jing_cost",   100);	
	set("skill/difficulty",  20);
	set("skill/max_skill", 140 );	
	set("skill/min_skill",  0l); 

	set("no_drop", 1);
};

EQUIP_END;
