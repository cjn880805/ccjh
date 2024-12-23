EQUIP_BEGIN(CIqingsi);


virtual void create(int nFlag = 0)
{
	set_name( "情絲");	

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "whip");
	set_weight(1000);		

	set("unit", "把");
	set("value", 250000);
	set("material", "bamboo");
	set("long", "这是一束烏黑的長髮。");
	set("wield_msg", "$N自懷中掏出一個小紅布包，細心的打開，取出什麽握在手中。");
	set("unequip_msg", "$N仔細的將手中一縷烏絲收起。");
	set("apply/damage", 60);				

	set("skill/name","jieyu_bian");	
	set("skill/exp_required",  0l);	
	set("skill/jing_cost",   100);	
	set("skill/difficulty",  20);
	set("skill/max_skill", 120 );	
	set("skill/min_skill",  0l); 


};

EQUIP_END;
