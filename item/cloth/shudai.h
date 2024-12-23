//shudai.h 束发金带

EQUIP_BEGIN(CIshudai);

virtual void create(int nFlag = 0)	
{
	set_name( "束发金带", "jindai");
    set_weight(50);

	set("wield_position", WIELD_HEAD);	

	set("unit", "条");
    set("long","这是一条用金丝织成的束发带子");
    set("value", 1500);
    set("material", "silk");
	set("apply/per", 1);
    set("apply/armor", 1);
	set("female_only", 1);
    set("wear_msg", "$N将$n拿出束在头发上。");
};

EQUIP_END;
