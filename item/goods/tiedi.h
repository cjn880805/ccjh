//tiedi.h	

ITEM_BEGIN(CItiedi)

virtual void create(int nFlag = 0)		
{
	    
	set_name("铁笛", "tie di");
	set_weight(500);

	set("unit", "支");
	set("long", "一支黑铁做成的长笛，看上去坚忍异常。");
	set("value", 10000);
	set("material", "bamboo");
	set("wield_msg", "$N大袖一挥，手中已多了一支乌黑油光的铁笛。");
	set("unwield_msg", "$N手中铁笛一转，眨眼间铁笛已然不见影踪。");
	
	set("apply/damage", 50);	
};

ITEM_END;
