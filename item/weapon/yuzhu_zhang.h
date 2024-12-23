EQUIP_BEGIN(CIyuzhu_zhang)

virtual void create(int nFlag = 0)		
{
	set_name("玉竹杖", "yuzhu zhang");
	set_weight(5000);
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");		
	
	set("unit", "根");
	set("long", "一根泛着淡淡青光的竹杖。");
	set("value", 10000);
	set("material", "bamboo");
	set("wield_msg", "$N抽出一根青光闪闪的竹杖抓在手中。");
	set("unwield_msg", "$N把手中的玉竹杖插回腰中。");
	
	set("apply/damage", 50);
};

EQUIP_END;
